/** \file max30102.cpp ******************************************************
 *
 * Project: MAXREFDES117#
 * Filename: max30102.cpp
 * Description: This module is an embedded controller driver for the MAX30102
 *
 * ------------------------------------------------------------------------- */
/*******************************************************************************
 * Copyright (C) 2016 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 * Modified: podonoghue
 *******************************************************************************
 */
#include "MAX30102.h"
#include "i2c.h"
#include "delay.h"

using Strobe = USBDM::GpioE<1>;

/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
using namespace USBDM;

// Device register addresses
#define REG_INTR_STATUS_1    (0x00)
#define REG_INTR_STATUS_2    (0x01)
#define REG_INTR_ENABLE_1    (0x02)
#define REG_INTR_ENABLE_2    (0x03)
#define REG_FIFO_WR_PTR      (0x04)
#define REG_OVF_COUNTER      (0x05)
#define REG_FIFO_RD_PTR      (0x06)
#define REG_FIFO_DATA        (0x07)
#define REG_FIFO_CONFIG      (0x08)
#define REG_MODE_CONFIG      (0x09)
#define REG_SPO2_CONFIG      (0x0A)
#define REG_LED1_PA          (0x0C)
#define REG_LED2_PA          (0x0D)
#define REG_PILOT_PA         (0x10)
#define REG_MULTI_LED_CTRL1  (0x11)
#define REG_MULTI_LED_CTRL2  (0x12)
#define REG_TEMP_INTR        (0x1F)
#define REG_TEMP_FRAC        (0x20)
#define REG_TEMP_CONFIG      (0x21)
#define REG_PROX_INT_THRESH  (0x30)
#define REG_REV_ID           (0xFE)
#define REG_PART_ID          (0xFF)

constexpr uint8_t INTR_STATUS_1_A_FULL   = (1<<7);
constexpr uint8_t INTR_STATUS_1_PPG_RDY  = (1<<6);
constexpr uint8_t INTR_STATUS_1_ALC_OVF  = (1<<5);
constexpr uint8_t INTR_STATUS_1_PROX_INT = (1<<4);
constexpr uint8_t INTR_STATUS_1_PWR_RDY  = (1<<0);

constexpr uint8_t INTR_STATUS_2_DIE_TEMP_RDY  = (1<<1);

constexpr unsigned TEMP_UPDATE_PERIOD    = 1000; // How often to do temperature update in measurement 'ticks'

/**
 * @param[in] aFull       FIFO Almost Full Flag
 * @param[in] ppgRdy      New FIFO Data Ready
 * @param[in] alc         Ambient Light Cancellation Overflow
 * @param[in] proximity   Proximity Threshold Triggered
 * @param[in] pwrRdy      Power Ready Flag
 */
static constexpr uint8_t interruptEnable1Value(bool aFull, bool ppgRdy, bool alc, bool proximity, bool pwrRdy) {
   return (aFull<<7)|(ppgRdy<<6)|(alc<<5)|(proximity<<4)|(pwrRdy<<0);
}
/**
 * @param[in] dieTemp     Internal Temperature Ready Flag
 */
static constexpr uint8_t interruptEnable2Value(bool dieTemp) {
   return (dieTemp<<1);
}

enum AverageNum {
   Averages_None = 0,
   Averages_2    = 1,
   Averages_4    = 2,
   Averages_8    = 3,
   Averages_16   = 4,
   Averages_32   = 5,
};

/**
 * @param[in]   smpAve           Sample Averaging
 * @param[in]   fifoRollOver     FIFO Rolls on Full
 * @param[in]   fifoAlmostFull   FIFO Almost Full Value (number of slots left of 32)
 */
static constexpr uint8_t fifoConfigValue(AverageNum smpAve, bool fifoRollOver, uint8_t fifoAlmostFull) {
   return (smpAve<<5)|(fifoRollOver<<4)|(fifoAlmostFull<<0);
}

enum Mode {
   ModeHeartRate = 2,  //<! Red LED only
   ModeSpO2      = 3,  //<! Red + IR LEDs
   ModeMultiLED  = 7,  //<! Red + IR LEDs
};
/**
 * @param[in]   shdn      Shutdown Control
 * @param[in]   reset     Reset Control
 * @param[in]   mode      Mode Control
 */
static constexpr uint8_t fifoModeValue(bool shdn, bool reset, Mode mode) {
   return (shdn<<7)|(reset<<6)|(mode<<0);
}

enum AdcRange {
   AdcRange_2048,  //!< 7.81 pA
   AdcRange_4096,  //!< 15.63 pA
   AdcRange_8192,  //!< 31.25 pA
   AdcRange_16384, //!< 62.5 pA
};

enum SpO2SampleRate {
   SpO2SampleRate_50 ,     //!< 50 Hz
   SpO2SampleRate_100,     //!< 100 Hz
   SpO2SampleRate_200,     //!< 200 Hz
   SpO2SampleRate_400,     //!< 400 Hz
   SpO2SampleRate_800,     //!< 800 Hz
   SpO2SampleRate_1000,    //!< 1 kHz
   SpO2SampleRate_1600,    //!< 1.6 kHz
   SpO2SampleRate_3200,    //!< 3.2 kHz
};

enum LedPulseWidth {
   LedPulseWidth_69uS,  //!< ADC integration time, ADC 15-bits
   LedPulseWidth_118uS, //!< ADC integration time, ADC 16-bits
   LedPulseWidth_215uS, //!< ADC integration time, ADC 17-bits
   LedPulseWidth_411uS, //!< ADC integration time, ADC 18-bits
};

/**
 * @param[in]   shdn      Shutdown Control
 * @param[in]   reset     Reset Control
 * @param[in]   mode      Mode Control
 */
static constexpr uint8_t spO2Value(AdcRange adcRange, SpO2SampleRate spO2SampleRate, LedPulseWidth ledPulseWidth) {
   return (adcRange<<5)|(spO2SampleRate<<2)|(ledPulseWidth<<0);
}

/**
 * @brief        Write a value to a MAX30102 register
 *
 * @param[in]    addr   Register address
 * @param[in]    data   Register data
 *
 * @return       true on success
 */
bool MAX30102::writeReg(uint8_t addr, uint8_t data) {

   uint8_t i2cData[2] = {addr, data};
   return i2c.transmit(DEVICE_ADDRESS, sizeof(i2cData), i2cData) == E_NO_ERROR;
}

/**
 * @brief        Read a MAX30102 register
 *
 * @param[in]    addr   Register address
 * @param[out]   data   Register data
 *
 * @return       true on success
 */
bool MAX30102::readReg(uint8_t addr, uint8_t &data) {

   uint8_t i2cData[] = {addr};
   if (i2c.txRx(DEVICE_ADDRESS, 1, i2cData, sizeof(i2cData), i2cData) == E_NO_ERROR) {
      data = i2cData[0];
      return true;
   }
   return false;
}

/**
 * @brief        Initialize the MAX30102
 *
 * @return       true on success
 */
bool MAX30102::init() {
   static const uint8_t initData[] = {
         REG_INTR_ENABLE_1,                                                            // Start write at REG_INTR_ENABLE_1 == 0x02
         /* 0x02 */ interruptEnable1Value(false, true, false, false, false),           // Interrupts from ppgRdy
         /* 0x03 */ interruptEnable2Value(true),                                       // Temperature interrupts
         /* 0x04 */ 0,                                                                 // Clear FIFO write pointer
         /* 0x05 */ 0,                                                                 // Clear FIFO overflow counter
         /* 0x06 */ 0,                                                                 // Clear FIFO read pointer
         /* 0x07 */ 0,  // dummy
         /* 0x08 */ fifoConfigValue(Averages_None,true,15),                            // No averaging, no FIFO roll-over, FIFO threshold @ 15 slots left (17 samples
         /* 0x09 */ fifoModeValue(false, false, ModeSpO2),                             // SpO2 mode
         /* 0x0A */ spO2Value(AdcRange_4096, SpO2SampleRate_100, LedPulseWidth_411uS), // SPO2 ADC range = 4096nA, SPO2 rate 100 Hz, LED pulseWidth 411uS
         /* 0x0B */ 0,  // dummy
         /* 0x0C */ 36,                                                                // ~7mA for Red LED
         /* 0x0D */ 36,                                                                // ~7mA for IR LED
         /* 0x0E */ 0,  // dummy
         /* 0x0F */ 0,  // dummy
         /* 0x10 */ 127,                                                               // ~25mA for Pilot LED
   };
   return i2c.transmit(DEVICE_ADDRESS, sizeof(initData), initData);

   //   return
   //         writeReg(REG_INTR_ENABLE_1,interruptEnable1Value(false, true, false, false, false))           && // Interrupts for ppgRdy
   //         writeReg(REG_INTR_ENABLE_2,interruptEnable2Value(false))                                      && // No temperature interrupts
   //         writeReg(REG_FIFO_WR_PTR,  0)                                                                 && // Clear FIFO write pointer
   //         writeReg(REG_OVF_COUNTER,  0)                                                                 && // Clear FIFO overflow counter
   //         writeReg(REG_FIFO_RD_PTR,  0)                                                                 && // Clear FIFO read pointer
   //         writeReg(REG_FIFO_CONFIG,  fifoConfigValue(Averages_None,false,15))                           && // No averaging, no FIFO roll-over, FIFO threshold @ 15 slots left (17 samples)
   //         writeReg(REG_MODE_CONFIG,  fifoModeValue(false, false, ModeSpO2))                             && // SpO2 mode
   //         writeReg(REG_SPO2_CONFIG,  spO2Value(AdcRange_4096, SpO2SampleRate_100, LedPulseWidth_411uS)) && // SPO2 ADC range = 4096nA, SPO2 rate 100 Hz, LED pulseWidth 411uS
   //         writeReg(REG_LED1_PA,      36)                                                                && // Choose value for ~ 7mA for Red LED
   //         writeReg(REG_LED2_PA,      36)                                                                && // Choose value for ~ 7mA for IR LED
   //         writeReg(REG_PILOT_PA,     127);                                                                 // Choose value for ~ 25mA for Pilot LED
}

/**
 * @brief        Read a set of samples from the MAX30102 FIFO register
 * @par          Details
 *               This function reads a set of samples from the MAX30102 FIFO register
 *               Assumes the samples are available - no checks!
 *
 * @param[out]   redLed  Red LED data read
 * @param[out]   irLed   IR LED data read
 *
 * @return       true on success
 */
bool MAX30102::readLeds(uint32_t &redLed, uint32_t &irLed) {
   // Read and clear interrupt status registers
   // Read 2 bytes [Interrupt Status 1 & 2]
   uint8_t intStatus[2];
   intStatus[0]=REG_INTR_STATUS_1;
   if (i2c.txRx(DEVICE_ADDRESS, 1, intStatus, sizeof(intStatus), intStatus)!=0) {
      return false;
   }
   // Check for temperature measurement
   if (intStatus[1]&INTR_STATUS_2_DIE_TEMP_RDY) {
      uint8_t temp[2];
      temp[0]=REG_TEMP_INTR;
      if (i2c.txRx(DEVICE_ADDRESS, 1, temp, sizeof(temp), temp)!=0) {
         return false;
      }
      temperature = ((int8_t)temp[0])+(temp[1]*0.0625);
   }
   // Check for channel measurement
   if ((intStatus[0]&INTR_STATUS_1_PPG_RDY) == 0) {
      // No data
      return false;
   }
   // Read 3 bytes [readPtr, overflowCnt, writePtr]
   uint8_t i2cData1[3];
   i2cData1[0]=REG_FIFO_WR_PTR;
   if (i2c.txRx(DEVICE_ADDRESS, 1, i2cData1, sizeof(i2cData1), i2cData1)!=0) {
      return false;
   }
   uint8_t writePointer    = i2cData1[0];
   uint8_t readPointer     = i2cData1[2];

   int numSamples = (writePointer-readPointer)&0x1F;

   Strobe::set();

   uint8_t i2cData[6];

   if (numSamples>1) {
      __asm__("nop");
   }
   // Discard all but last measurement
   while(numSamples-->0) {
      // Read 1 sample = 6 bytes from FIFO [REDx3, IRx3]
      i2cData[0]=REG_FIFO_DATA;
      if (i2c.txRx(DEVICE_ADDRESS, 1, i2cData, sizeof(i2cData), i2cData)!=0) {
         return false;
      }
   }
   int index = 0;

   // Assemble RED LED value
   redLed  = i2cData[index++]<<16;
   redLed += i2cData[index++]<<8;
   redLed += i2cData[index++];
   redLed &= 0x03FFFF;  // Keep [17..0]

   // Assemble IR LED value
   irLed  = i2cData[index++]<<16;
   irLed += i2cData[index++]<<8;
   irLed += i2cData[index++];
   irLed &= 0x03FFFF;  // Keep [17..0]

   Strobe::clear();

   static unsigned sampleCount = TEMP_UPDATE_PERIOD;
   if (sampleCount++ == TEMP_UPDATE_PERIOD) {
      // Start temperature measurement every TEMP_UPDATE_PERIOD samples e.g. 1000 = ~10 seconds @100 Hz
      startTempMeasurement();
      sampleCount = 0;
   }
   return true;
}

/**
 * @brief        Initiates a temperature measurement
 *
 * @return       true on success
 */
bool MAX30102::startTempMeasurement() {
   static const uint8_t command[] = {REG_TEMP_CONFIG, 0x01};
   return i2c.transmit(DEVICE_ADDRESS, sizeof(command), command) == E_NO_ERROR;
}

/**
 * @brief        Reset the MAX30102
 *
 * @return       true on success
 */
bool MAX30102::reset() {
   return writeReg(REG_MODE_CONFIG, 0x40);
}
