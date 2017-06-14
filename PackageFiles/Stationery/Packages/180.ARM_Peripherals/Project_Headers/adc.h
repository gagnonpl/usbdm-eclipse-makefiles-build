/**
 * @file     adc.h
 * @brief    ADC routines
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_ADC_H
#define HEADER_ADC_H
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include <stddef.h>
#include <assert.h>
#include "derivative.h"

/*
 * Default port information
 */
#ifndef FIXED_PORT_CLOCK_REG
#define FIXED_PORT_CLOCK_REG SCGC5
#endif

#ifndef ADC0_CLOCK_MASK
#ifdef SIM_SCGC6_ADC0_MASK
#define ADC0_CLOCK_MASK SIM_SCGC6_ADC0_MASK
#define ADC0_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC3_ADC1_MASK
#define ADC1_CLOCK_MASK SIM_SCGC3_ADC1_MASK
#define ADC1_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC6_ADC1_MASK
#define ADC1_CLOCK_MASK SIM_SCGC6_ADC1_MASK
#define ADC1_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_ADC2_MASK
#define ADC2_CLOCK_MASK SIM_SCGC6_ADC2_MASK
#define ADC2_CLOCK_REG  SCGC6
#endif
#endif

namespace USBDM {

/**
 * @addtogroup AnalogueIO_Group Analogue Input
 * @{
 */

/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 */
static constexpr PcrValue ADC_DEFAULT_PCR = pcrValue(PinPullNone, PinDriveLow, PinPushPull, PinIrqNone, PinMuxAnalogue);

/**
 * ADC Resolutions for use with AnalogueIO::setMode()
 */
enum Adc_Resolution {
   resolution_8bit_se    = ADC_CFG1_MODE(0),  //!<  8-bit unsigned for use with single-ended mode
   resolution_10bit_se   = ADC_CFG1_MODE(2),  //!< 10-bit unsigned for use with single-ended mode
   resolution_12bit_se   = ADC_CFG1_MODE(1),  //!< 12-bit unsigned for use with single-ended mode
   resolution_16bit_se   = ADC_CFG1_MODE(3),  //!< 16-bit unsigned for use with single-ended mode
   resolution_9bit_diff  = ADC_CFG1_MODE(0),  //!<  9-bit signed for use with differential mode
   resolution_11bit_diff = ADC_CFG1_MODE(2),  //!< 11-bit signed for use with differential mode
   resolution_12bit_diff = ADC_CFG1_MODE(1),  //!< 12-bit signed for use with differential mode
   resolution_16bit_diff = ADC_CFG1_MODE(3),  //!< 16-bit signed for use with differential mode
};

/**
 * ADC Resolutions for use with AnalogueIO::setMode()
 */
enum Adc_Averaging {
	   averaging_off = 0,                                 //!< No averaging - single conversion
	   averaging_4   = ADC_SC3_AVGE_MASK|ADC_SC3_AVGS(0), //!< Average across 4 conversions
	   averaging_8   = ADC_SC3_AVGE_MASK|ADC_SC3_AVGS(1), //!< Average across 8 conversions
	   averaging_16  = ADC_SC3_AVGE_MASK|ADC_SC3_AVGS(2), //!< Average across 16 conversions
	   averaging_32  = ADC_SC3_AVGE_MASK|ADC_SC3_AVGS(3), //!< Average across 32 conversions
};

/**
 * Type definition for ADC interrupt call back
 *
 * @param value Conversion value from channel
 */
typedef void (*ADCCallbackFunction)(uint32_t value);

/**
 * Template class representing an ADC
 *
 * Example
 * @code
 *  // Instantiate ADC channel adc0_se8
 *  const AdcBase_T<adc0Info> Adc0;
 *
 *  // Initialise ADC
 *  Adc0.setMode(resolution_16bit_se);
 *  @endcode
 *
 * @tparam info Table of information describing ADC
 */
template<class Info>
class AdcBase_T {

protected:
   static constexpr volatile ADC_Type *adc      = Info::adc;
   static constexpr volatile uint32_t *clockReg = Info::clockReg;

public:
   /**
    * Initialise ADC to default settings\n
    * Configures all ADC pins
    */
   static void enable() {
      // Configure pins
      Info::initPCRs();
      Info::InfoDP::initPCRs();
      Info::InfoDM::initPCRs();

      // Enable clock to ADC
      *clockReg  |= Info::clockMask;
      __DMB();

      // Set mode to default
      adc->CFG1 = Info::cfg1;
      adc->CFG2 = Info::cfg2;
      adc->SC2  = Info::sc2;

      enableNvicInterrupts();
   }

   /**
    * Enable/disable interrupts in NVIC
    *
    * @param enable true to enable, false to disable
    */
   static void enableNvicInterrupts(bool enable=true) {

      if (enable) {
         // Enable interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }

   /**
    * Disables the ADC\n
    * Does not change ADC pin mapping
    */
   static void disable() {
      adc->CFG1 = 0;
      adc->CFG2 = 0;
      adc->SC2  = 0;
   }

   /**
    * Set conversion mode
    *
    * @param resolution Resolution for converter e.g. resolution_16bit_se
    *
    * @note This affects all channels on the ADC
    */
   static void setResolution(uint32_t resolution = resolution_16bit_se) {
      adc->CFG1 = (Info::cfg1&~ADC_CFG1_MODE_MASK)|(resolution&ADC_CFG1_MODE_MASK);
   }

   /**
    * Set averaging mode
    *
    * @param mode Mode for averaging e.g. averaging_4 etc
    *
    * @note This affects all channels on the ADC
    */
   static void setAveraging(uint32_t mode = averaging_4) {
      adc->SC3 = (ADC_SC3_AVGE_MASK|ADC_SC3_AVGS_MASK)&mode;
   }

   /**
    * Configure ADC
    *
    * @param cfg1 CFG1 register value
    * @param cfg2 CFG1 register value
    * @param sc2  SC2 register value
    *
    */
   static void configure(uint32_t cfg1=Info::cfg1, uint32_t cfg2=Info::cfg2, uint32_t sc2=Info::sc2) {
      // Set mode
      adc->CFG1 = cfg1;
      adc->CFG2 = cfg2;
      adc->SC2  = sc2;
   }

   /**
    * Initiates a conversion but does not wait for it to complete\n
    * Intended for use with interrupts
    *
    * @param sc1Value SC1 register value including the ADC channel to use
    *
    * @return E_NO_ERROR on success
    */
   static ErrorCode startConversion(const int sc1Value) {
      if (!Info::irqHandlerInstalled) {
         return setErrorCode(E_NO_HANDLER);
      }
      // Trigger conversion with interrupts enabled
      adc->SC1[0] = ADC_SC1_AIEN_MASK|(sc1Value&(ADC_SC1_ADCH_MASK|ADC_SC1_AIEN_MASK|ADC_SC1_DIFF_MASK));

      return E_NO_ERROR;
   };

   /**
    * Initiates a conversion and waits for it to complete
    *
    * @param sc1Value SC1 register value including the ADC channel to use
    *
    * @return - the result of the conversion
    */
   static int readAnalogue(const int sc1Value) {

      // Trigger conversion
      adc->SC1[0] = (sc1Value&(ADC_SC1_ADCH_MASK|ADC_SC1_AIEN_MASK|ADC_SC1_DIFF_MASK));

      while ((adc->SC1[0]&ADC_SC1_COCO_MASK) == 0) {
         __asm__("nop");
      }
      return (int)adc->R[0];
   };
};

/**
 * Template class to provide ADC callback
 */
template<class Info>
class AdcIrq_T : public AdcBase_T<Info> {

protected:
   /** Callback function for ISR */
   static ADCCallbackFunction callback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler() {
      if (callback != 0) {
         callback(AdcBase_T<Info>::adc->R[0]);
      }
      else {
         setAndCheckErrorCode(E_NO_HANDLER);
      }
   }

   /**
    * Set Callback function
    *
    * @param theCallback Callback function to execute on interrupt
    */
   static void setCallback(ADCCallbackFunction theCallback) {
      callback = theCallback;
   }
};

template<class Info> ADCCallbackFunction AdcIrq_T<Info>::callback = 0;

#ifdef USBDM_ADC0_IS_DEFINED
/**
 *
 * Template class representing a ADC0 channel
 *
 * Example
 * @code
 * // Instantiate the ADC channel (for ADC0 channel 6)
 * using Adc0_ch6 = USBDM::Adc0Channel<6>;
 *
 * // Set ADC resolution
 * Adc0_ch6.setMode(resolution_16bit_se);
 *
 * // Read ADC value
 * uint32_t value = Adc0_ch6.readAnalogue();
 * @endcode
 *
 * @tparam channel ADC channel
 */
template<int channel>
class Adc0Channel : public AdcBase_T<Adc0Info>, CheckSignal<Adc0Info, channel> {

public:
   /**
    * Initiates a conversion but does not wait for it to complete\n
    * Intended for use with interrupts
    */
   static void startConversion() {
      AdcBase_T::startConversion(ADC_SC1_ADCH(channel)&~ADC_SC1_DIFF_MASK);
   };
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   static uint32_t readAnalogue() {
      return AdcBase_T::readAnalogue(ADC_SC1_ADCH(channel)&~ADC_SC1_DIFF_MASK);
   };
};

/**
 *
 * Template class representing a ADC0 differential channel
 *
 * Example
 * @code
 * // Instantiate the differential ADC channels (for ADC_DM0, ADC_DP0)
 * using Adc0_diff0 = USBDM::Adc0DiffChannel<0>;
 *
 * // Set ADC resolution
 * Adc0_diff0.setMode(resolution_11bit_diff );
 *
 * // Read ADC value
 * uint32_t value = Adc0_diff0.readAnalogue();
 * @endcode
 *
 * @tparam channel ADC channel
 */
template<int channel>
class Adc0DiffChannel : public AdcBase_T<Adc0Info>, CheckSignal<Adc0Info::InfoDP, channel>, CheckSignal<Adc0Info::InfoDM, channel> {

public:
   /**
    * Initiates a conversion but does not wait for it to complete\n
    * Intended for use with interrupts
    */
   static void startConversion() {
      AdcBase_T::startConversion(ADC_SC1_ADCH(channel)|ADC_SC1_DIFF_MASK);
   };
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   static int32_t readAnalogue() {
      return AdcBase_T::readAnalogue(ADC_SC1_ADCH(channel)|ADC_SC1_DIFF_MASK);
   };
};
/**
 * Class representing ADC0
 */
using Adc0 = AdcIrq_T<Adc0Info>;
#endif

#ifdef USBDM_ADC1_IS_DEFINED
/**
 *
 * Template class representing a ADC0 channel
 *
 * Refer @ref Adc0Channel
 *
 * @tparam channel ADC channel
 */
template<int channel>
class Adc1Channel : public AdcBase_T<Adc1Info>, CheckSignal<Adc1Info, channel> {

public:
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   static int readAnalogue() {
      return AdcBase_T::readAnalogue(channel);
   };
};
/**
 *
 * Template class representing a ADC0 differential channel
 *
 * Example
 * @code
 * // Instantiate the differential ADC channels (for ADC_DM0, ADC_DP0)
 * using Adc1_diff0 = USBDM::Adc0DiffChannel<0>;
 *
 * // Set ADC resolution
 * Adc1_diff0.setMode(resolution_16bit_se);
 *
 * // Read ADC value
 * uint32_t value = Adc1_diff0.readAnalogue();
 * @endcode
 *
 * @tparam channel ADC channel
 */
template<int channel>
class Adc1DiffChannel : public AdcBase_T<Adc1Info>, CheckSignal<Adc1Info::InfoDP, channel>, CheckSignal<Adc1Info::InfoDM, channel> {

public:
   /**
    * Initiates a conversion but does not wait for it to complete\n
    * Intended for use with interrupts
    */
   static void startConversion() {
      AdcBase_T::startConversion(ADC_SC1_ADCH(channel)|ADC_SC1_DIFF_MASK);
   };
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   static int readAnalogue() {
      return AdcBase_T::readAnalogue(ADC_SC1_ADCH(channel)|ADC_SC1_DIFF_MASK);
   };
};
/**
 * Class representing ADC1
 */
using Adc1 = AdcIrq_T<Adc1Info>;
#endif

/**
 * @}
 */
 
} // End namespace USBDM

#endif /* HEADER_ADC_H */

