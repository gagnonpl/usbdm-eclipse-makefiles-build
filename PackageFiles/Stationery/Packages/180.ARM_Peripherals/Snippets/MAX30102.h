/** @file max30102.h ******************************************************
 *
 * Project: MAXREFDES117#
 * Filename: max30102.h
 * @brief: This module is an embedded controller driver header file for MAX30102
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
#ifndef MAX30102_H_
#define MAX30102_H_

#include <stdint.h>

/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include <stdint.h>
#include "i2c.h"

namespace USBDM {

/**
 * @addtogroup MAX30102_Group MAX30102 SpO2 sensor
 * @brief C++ Class providing interface to MAX30102
 * @{
 */

/**
 * @brief Class representing an interface for a MAX30102 SpO2 sensor over I2C
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interfaces
 *
 *  // I2C interface
 *  I2c0     i2c0;
 *  // Accelerometer via I2C
 *  MAX30102  spo2sensor(i2c0);
 *
 * @endcode
 */
class MAX30102 {
private:
   I2c &i2c;
   static const uint8_t DEVICE_ADDRESS = 0xAE;

   float temperature = 0;

public:
   /**
    * Constructor
    *
    * @param[in] i2c I2C interface to use
    */
   MAX30102(I2c &i2c) : i2c(i2c){
      init();
   }
   /**
    * @brief        Initialize the MAX30102
    *
    * @return       true on success
    */
   bool init();
   /**
    * @brief        Read a set of samples from the MAX30102 FIFO register
    * @par          Details
    *               This function reads a set of samples from the MAX30102 FIFO register
    *               Assumes the samples are present - no checks!
    *
    * @param[out]   redLed  Red LED data read
    * @param[out]   irLed   IR LED data read
    *
    * @return       true on success
    */
   bool readLeds(uint32_t &redLed, uint32_t &irLed);
   /**
    * @brief        Write a value to a MAX30102 register
    *
    * @param[in]    addr  Register address
    * @param[in]    data  Register data
    *
    * @return       true on success
    */
   bool writeReg(uint8_t addr, uint8_t data);
   /**
    * @brief        Read a MAX30102 register
    *
    * @param[in]    addr  Register address
    * @param[out]   data  Register data
    *
    * @return       true on success
    */
   bool readReg(uint8_t addr, uint8_t &data);
   /**
    * @brief        Reset the MAX30102
    *
    * @return       true on success
    */
   bool reset();
   /**
    * @brief        Initiates a temperature measurement
    *
    * @return       true on success
    */
   bool startTempMeasurement();
   /**
    * @brief        Gets last temperature measurement
    *
    * @return       Temeprature as float
    */
   float getTempMeasurement() {
      return temperature;
   }
};

/**
 * @}
 */

} // End namespace USBDM

#endif /* MAX30102_H_ */
