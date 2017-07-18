/**
 * @file     tpm.h (180.ARM_Peripherals/Project_Headers/tpm.h)
 * @brief    Flexitimer Timer Module
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_TPM_H
#define HEADER_TPM_H
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
#include <cmath>

/*
 * Default port information
 */

#ifndef TPM0_CLOCK_MASK
#ifdef SIM_SCGC6_TPM0_MASK
#define TPM0_CLOCK_MASK SIM_SCGC6_TPM0_MASK
#define TPM0_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_TPM1_MASK
#define TPM1_CLOCK_MASK SIM_SCGC6_TPM1_MASK
#define TPM1_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_TPM2_MASK
#define TPM2_CLOCK_MASK SIM_SCGC6_TPM2_MASK
#define TPM2_CLOCK_REG  SCGC6
#elif defined SIM_SCGC3_TPM2_MASK
#define TPM2_CLOCK_MASK SIM_SCGC3_TPM2_MASK
#define TPM2_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC6_TPM3_MASK
#define TPM3_CLOCK_MASK SIM_SCGC6_TPM3_MASK
#define TPM3_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC3_TPM3_MASK
#define TPM3_CLOCK_MASK SIM_SCGC3_TPM3_MASK
#define TPM3_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC3_TPM3_MASKC
#define TPM3_CLOCK_MASK SIM_SCGC3_TPM3_MASKC
#define TPM3_CLOCK_REG  SCGC3
#endif
#endif

namespace USBDM {

/**
 * @addtogroup TPM_Group TPM, PWM, Input capture and Output compare
 * @brief Pins used for PWM, Input capture and Output compare
 * @{
 */
 
/**
 * Control mode of operation of shared TPM counter
 */
enum TpmMode {
   //! Up counter: Used for left-aligned PWM, input capture and output compare modes
   TpmMode_LeftAlign   = 0,
   //! Up-down counter: Used for centre-aligned PWM 
   TpmMode_CentreAlign = TPM_SC_CPWMS_MASK,
};

/**
 * Controls basic operation TPM channel
 */
enum TpmChMode {
   //! Capture rising edge
   TpmChMode_InputCaptureRisingEdge  = TPM_CnSC_MS(0)|TPM_CnSC_ELS(1),
   //! Capture falling edge
   TpmChMode_InputCaptureFallingEdge = TPM_CnSC_MS(0)|TPM_CnSC_ELS(2),
   //! Capture both rising and falling edges
   TpmChMode_InputCaptureEitherEdge  = TPM_CnSC_MS(0)|TPM_CnSC_ELS(3),
   //! Output compare operation
   TpmChMode_OutputCompare           = TPM_CnSC_MS(1),
   //! Toggle pin on output compare
   TpmChMode_OutputCompareToggle     = TPM_CnSC_MS(1)|TPM_CnSC_ELS(1),
   //! Clear pin on output compare
   TpmChMode_OutputCompareClear      = TPM_CnSC_MS(1)|TPM_CnSC_ELS(2),
   //! Set pin on output compare
   TpmChMode_OutputCompareSet        = TPM_CnSC_MS(1)|TPM_CnSC_ELS(3),
   //! PWM with high-true pulses
   TpmChMode_PwmHighTruePulses       = TPM_CnSC_MS(2)|TPM_CnSC_ELS(2),
   //! PWM with low-true pulses
   TpmChMode_PwmLowTruePulses        = TPM_CnSC_MS(2)|TPM_CnSC_ELS(1),
};

/**
 * Type definition for TPM timer overflow interrupt call back
 */
typedef void (*TPMCallbackFunction)(volatile TPM_Type *tmr);
/**
 * Type definition for TPM channel interrupt call back
 *
 * @param tmr    Timer hardware instance e.g. FTM or TPM
 * @param status Flags indicating interrupt source channel(s)
 */
typedef void (*TPMChannelCallbackFunction)(volatile TPM_Type *tmr, int status);

/**
 * Base class representing an TPM
 *
 * Example
 * @code
 * // Instantiate the tmr (for TPM0)
 * const USBDM::TpmBase_T<TPM0_Info)> Tpm0;
 *
 * // Initialise PWM with initial period and alignment
 * Tpm0::initialise(200, USBDM::TpmMode_LeftAlign);
 *
 * // Change timer period
 * Tpm0::setPeriod(500);
 * @endcode
 *
 * @tparam Info  Class describing TPM hardware instance
 */
template<class Info>
class TpmBase_T {

protected:
   static constexpr volatile TPM_Type* tmr      = Info::tpm;
   static constexpr volatile uint32_t *clockReg = Info::clockReg;

public:
   /**
    * Enable with default settings\n
    * Includes configuring all pins
    */
   static void enable() {
      // Configure pins
      Info::initPCRs();

      // Enable clock to timer
      *clockReg |= Info::clockMask;
      __DMB();

      // Disable so immediate effect
      tmr->SC      = 0;

      // Common registers
      tmr->CNT     = 0;
      tmr->MOD     = Info::period;
      tmr->SC      = Info::sc;

      enableNvicInterrupts();
   }

   /**
    * Check if FTM is enabled\n
    * Just check for clock enable and clock sourtce selection
    *
    * @return True => enabled
    */
   static __attribute__((always_inline)) bool isEnabled() {
      return ((*clockReg & Info::clockMask) != 0) && ((tmr->SC & TPM_SC_CMOD_MASK) != 0);
   }

   /**
    * Configure Timer operation\n
    * Used to change configuration after enabling interface
    *
    * @param period  Period in ticks
    * @param tpmMode Mode of operation see USBDM::TpmMode
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static void configure(uint32_t period /* ticks */, TpmMode tpmMode=TpmMode_LeftAlign) {

      // Disable so immediate effect
      tmr->SC      = 0;

      tmr->SC      = tpmMode;
      if (tpmMode == TpmMode_CentreAlign) {
         // Centre aligned PWM with CPWMS not selected
         tmr->SC   = Info::sc|TPM_SC_CPWMS_MASK;
      }
      else {
         // Left aligned PWM without CPWMS selected
         tmr->SC   = Info::sc;
      }
      setPeriodInTicks(period);

      enableNvicInterrupts();
   }

   /**
    * Enable/disable Timer interrupts in NVIC
    *
    * @param enable true to enable, false to disable
    */
   static __attribute__((always_inline)) void enableNvicInterrupts(bool enable=true) {

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
    * Enable/disable Timer Overflow interrupts
    *
    * @param[in] enable true to enable, false to disable
    */
   static __attribute__((always_inline)) void enableTimerOverflowInterrupts(bool enable=true) {
      if (enable) {
         tmr->SC |= TPM_SC_TOIE_MASK;
      }
      else {
         tmr->SC &= ~TPM_SC_TOIE_MASK;
      }
   }

   /**
    * Set period
    *
    * @param[in] period Period in seconds as a float
    *
    * @note Adjusts Timer pre-scaler to appropriate value.
    *       This will affect all channels of the timer.
    *
    * @return E_NO_ERROR  => success
    * @return E_TOO_SMALL => failed to find suitable values
    * @return E_TOO_LARGE => failed to find suitable values
    */
   static ErrorCode setPeriod(float period) {
      float inputClock = Info::getInputClockFrequency();
      int prescaleFactor=1;
      int prescalerValue=0;
      while (prescalerValue<=7) {
         float    clock = inputClock/prescaleFactor;
         uint32_t mod   = round(period*clock);
         if (mod < Info::minimumResolution) {
            // Too short a period for 1% resolution
            return setErrorCode(E_TOO_SMALL);
         }
         if (mod <= 65535) {
            // Clear SC so immediate effect on prescale change
            uint32_t sc = tmr->SC&~TPM_SC_PS_MASK;
            tmr->SC     = 0;
            __DSB();
            tmr->MOD    = mod;
            tmr->SC     = sc|TPM_SC_PS(prescalerValue);
            return E_NO_ERROR;
         }
         prescalerValue++;
         prescaleFactor <<= 1;
      }
      // Too long a period
      return setErrorCode(E_TOO_LARGE);
   }

   /**
    * Set measurement period.
    * Input Capture and Output Compare will be able to operate over
    *  at least this period without overflow.
    *
    * @param[in] period Period in seconds as a float
    *
    * @note Adjusts Timer pre-scaler to appropriate value.
    *       Timer period is set to maximum.
    *       This will affect all channels of the timer.
    *
    * @return E_NO_ERROR  => success
    * @return E_TOO_SMALL => failed to find suitable values
    * @return E_TOO_LARGE => failed to find suitable values
    */
   static __attribute__((always_inline)) ErrorCode setMeasurementPeriod(float period) {
      // Try to set capture period
      ErrorCode rc = setPeriod(period);
      // Set actual period to maximum ticks in any case
      // This is the usual value for IC or OC set-up
      setPeriodInTicks(0);
      return rc;
   }
   /**
    * Get frequency of timer tick
    *
    * @return Timer frequency in Hz
    */
   static __attribute__((always_inline)) float getTickFrequency() {

      // Calculate timer prescale factor
      int prescaleFactor = 1<<((tmr->SC&TPM_SC_PS_MASK)>>TPM_SC_PS_SHIFT);

      return (float)Info::getInputClockFrequency() / prescaleFactor;
   }

   /**
    * Set approximate frequency of timer tick
    *
    * @param[in] frequency Frequency as a float
    * @param[in] tolerance Tolerance in percent
    *
    * @note Adjusts Timer pre-scaler to appropriate value.
    *       This will affect all channels
    *
    * @return E_NO_ERROR       Success
    * @return E_ILLEGAL_PARAM  Failed to find suitable pre-scaler values
    */
   static ErrorCode setTickFrequency(float frequency, float tolerance) {
      float inputClockFrequency = Info::getInputClockFrequency();

      int prescaleFactor=1;
      int prescalerValue=0;
      while (prescalerValue<=7) {
         float tickFrequency = inputClockFrequency/prescaleFactor;

         if ((100*std::abs((tickFrequency/frequency)-1)) < tolerance) {
            // Clear SC so immediate effect on prescale change
            uint32_t sc = tmr->SC&~TPM_SC_PS_MASK;
            tmr->SC     = 0;
            __DSB();
            tmr->SC     = sc|TPM_SC_PS(prescalerValue);
            return E_NO_ERROR;
         }
         prescalerValue++;
         prescaleFactor <<= 1;
      }
      // Too long a period
      return setErrorCode(E_ILLEGAL_PARAM);
   }

   /**
    * Set period
    *
    * @param[in] period Period in ticks
    *
    * @return E_NO_ERROR       Success
    * @return E_TOO_LARGE      Failed to find suitable pre-scaler values
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static ErrorCode setPeriodInTicks(uint32_t period) {

      // Check if CPWMS is set (affects period)
      bool centreAlign = (tmr->SC&TPM_SC_CPWMS_MASK) != 0;

      // Disable timer so register changes are immediate
      uint8_t sc = tmr->SC;
      tmr->SC = TPM_SC_CMOD(0);

      if (centreAlign) {
#ifdef DEBUG_BUILD
         if (period > 2*0xFFFFUL) {
            // Attempt to set too long a period
            return setErrorCode(E_TOO_LARGE);
         }
#endif
         tmr->MOD = (uint32_t)(period/2);
         // Centre aligned PWM with CPWMS not selected
         tmr->SC  = sc;
      }
      else {
#ifdef DEBUG_BUILD
         if (period > 0x10000UL) {
            // Attempt to set too long a period
            return setErrorCode(E_TOO_LARGE);
         }
#endif
         tmr->MOD = (uint32_t)(period-1);
         // Left aligned PWM without CPWMS selected
         tmr->SC  = sc;
      }
      // OK period
      return setErrorCode(E_NO_ERROR);
   }

   /**
    * Converts a time in microseconds to number of ticks
    *
    * @param[in] time Time in microseconds
    *
    * @return Time in ticks
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertMicrosecondsToTicks(int time) {

      // Calculate period
      uint32_t tickRate = Info::getClockFrequency();
      uint64_t rv       = ((uint64_t)time*tickRate)/1000000;
#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         setErrorCode(E_TOO_LARGE);
      }
      if (rv == 0) {
         // Attempt to set too short a period
         setErrorCode(E_TOO_SMALL);
      }
#endif
      return rv;
   }

   /**
    * Converts a time in microseconds to number of ticks
    *
    * @param[in] time Time in microseconds
    *
    * @return Time in ticks
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertSecondsToTicks(float time) {

      // Calculate period
      float    tickRate = Info::getClockFrequencyF();
      uint64_t rv       = time*tickRate;
#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         setErrorCode(E_TOO_LARGE);
      }
      if (rv == 0) {
         // Attempt to set too short a period
         setErrorCode(E_TOO_SMALL);
      }
#endif
      return rv;
   }

   /**
    * Converts ticks to time in microseconds
    *
    * @param[in] tickInterval Time in ticks
    *
    * @return Time in microseconds
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertTicksToMicroseconds(int time) {

      // Calculate period
      uint32_t tickRate = Info::getClockFrequency()/(1<<(tmr->SC&TPM_SC_PS_MASK));
      uint64_t rv       = ((uint64_t)time*1000000)/tickRate;
#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         setErrorCode(E_TOO_LARGE);
      }
      if (rv == 0) {
         // Attempt to set too short a period
         setErrorCode(E_TOO_SMALL);
      }
#endif
      return rv;
   }

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    * @param channel    Timer channel
    */
   static void setDutyCycle(int dutyCycle, int channel) {
      if (tmr->SC&TPM_SC_CPWMS_MASK) {
         tmr->CONTROLS[channel].CnV  = (dutyCycle*tmr->MOD)/100;
      }
      else {
         tmr->CONTROLS[channel].CnV  = (dutyCycle*(tmr->MOD+1))/100;
      }
   }

   /**
    * Set Timer event time
    *
    * @param eventTime  Absolute event time
    * @param channel    Timer channel
    */
   static __attribute__((always_inline)) void setEventTime(uint16_t eventTime, int channel) {
      tmr->CONTROLS[channel].CnV = eventTime;
   }

   /**
    * Set Timer event time
    *
    * @param eventTime  Event time relative to current event time (i.e. Timer channel CnV value)
    * @param channel    Timer channel
    */
   static __attribute__((always_inline)) void setDeltaEventTime(uint16_t eventTime, int channel) {
      tmr->CONTROLS[channel].CnV += eventTime;
   }

   /**
    * Set Timer event time
    *
    * @param eventTime  Event time relative to current time (i.e. Timer CNT value)
    * @param channel    Timer channel
    */
   static __attribute__((always_inline)) void setRelativeEventTime(uint16_t eventTime, int channel) {
      tmr->CONTROLS[channel].CnV = tmr->CNT + eventTime;
   }

   /**
    * Set PWM duty cycle\n
    * Higher precision float version
    *
    * @param dutyCycle  Duty-cycle as percentage (float)
    * @param channel    Timer channel
    */
   static void setDutyCycle(float dutyCycle, int channel) {
      if (tmr->SC&TPM_SC_CPWMS_MASK) {
         tmr->CONTROLS[channel].CnV  = round((dutyCycle*tmr->MOD)/100.0f);
      }
      else {
         tmr->CONTROLS[channel].CnV  = round((dutyCycle*(tmr->MOD+1))/100.0f);
      }
   }

   /**
    * Set PWM high time in ticks
    * Assumes value is less than period
    *
    * @param highTime   PWM high time in ticks
    * @param channel    Timer channel
    *
    * @return E_NO_ERROR on success
    */
   static ErrorCode setHighTime(uint32_t highTime, int channel) {
#ifdef DEBUG_BUILD
      if (highTime > tmr->MOD) {
         return setErrorCode(E_TOO_LARGE);
      }
#endif
      tmr->CONTROLS[channel].CnV  = highTime;
      return E_NO_ERROR;
   }

   /**
    * Set PWM high time in seconds
    *
    * @param highTime   PWM high time in seconds
    * @param channel    Timer channel
    *
    * @return E_NO_ERROR on success
    */
   static __attribute__((always_inline)) ErrorCode setHighTime(float highTime, int channel) {
      return setHighTime(convertSecondsToTicks(highTime), channel);
   }

};

/**
 * Template class to provide Timer callback
 */
template<class Info>
class TpmIrq_T : public TpmBase_T<Info> {

protected:
   /** Callback function for TOI ISR */
   static TPMCallbackFunction toiCallback;
   /** Callback function for Channel ISR */
   static TPMChannelCallbackFunction callback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler() {
      if ((TpmBase_T<Info>::tmr->SC&(TPM_SC_TOF_MASK|TPM_SC_TOIE_MASK)) == (TPM_SC_TOF_MASK|TPM_SC_TOIE_MASK)) {
         // Clear TOI flag
         TpmBase_T<Info>::tmr->SC &= ~TPM_SC_TOF_MASK;
         if (toiCallback != 0) {
            toiCallback(TpmBase_T<Info>::tmr);
         }
         else {
            setAndCheckErrorCode(E_NO_HANDLER);
         }
      }
      uint8_t status = TpmBase_T<Info>::tmr->STATUS;
      if (status) {
         // Clear flags for channel events being handled (w1c register if read)
         TpmBase_T<Info>::tmr->STATUS = status;
         if (callback != 0) {
            callback(TpmBase_T<Info>::tmr, status);
         }
      }
   }

   /**
    * Set TOI Callback function\n
    * Note that one callback is shared by all channels of the FTM
    *
    * @param theCallback Callback function to execute on overflow interrupt
    */
   static __attribute__((always_inline)) void setTimerOverflowCallback(TPMCallbackFunction theCallback) {
      toiCallback = theCallback;
   }
   /**
    * Set channel Callback function\n
    * Note that one callback is shared by all channels of the FTM
    *
    * @param theCallback Callback function to execute on channel interrupt
    */
   static __attribute__((always_inline)) void setChannelCallback(TPMChannelCallbackFunction theCallback) {
      callback = theCallback;
   }
};

template<class Info> TPMCallbackFunction         TpmIrq_T<Info>::toiCallback = 0;
template<class Info> TPMChannelCallbackFunction  TpmIrq_T<Info>::callback = 0;

/**
 * Template class representing a timer channel
 *
 * Example
 * @code
 * // Instantiate the timer channel (for TPM0 channel 6)
 * using Tmr0_ch6 = USBDM::TpmChannel<TPM0Info, 6>;
 *
 * // Initialise PWM with initial period and alignment
 * Tmr0_ch6.setMode(200, USBDM::TpmMode_LeftAlign);
 *
 * // Change period (in ticks)
 * Tmr0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * Tmr0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel TPM timer channel
 */
template <class Info, int channel>
class TpmChannel_T : protected TpmIrq_T<Info>, protected PcrTable_T<Info, channel>, CheckSignal<Info, channel> {

protected:
   // Allow more convenient access to template super-classes
   using PcrBase = PcrBase_T<Info::info[channel].pcrAddress>;

public:
   // Allow more convenient access to template super-classes
   using Pcr = PcrTable_T<Info, channel>;
   using Tpm = TpmIrq_T<Info>;

   // Make these PCR functions available
   using Pcr::setDriveMode;
   using Pcr::setDriveStrength;
   using Pcr::setFilter;
   using Pcr::setPullDevice;
   using Pcr::setSlewRate;

   // Make these shared FTM functions available
   using Tpm::setChannelCallback;
   using Tpm::setPeriod;
   using Tpm::setMeasurementPeriod;
   using Tpm::setPeriodInTicks;
   using Tpm::convertMicrosecondsToTicks;
   using Tpm::convertSecondsToTicks;
   using Tpm::convertTicksToMicroseconds;
   using Tpm::getTickFrequency;
   using Tpm::setTickFrequency;

   /**
    * Set callback for Pin IRQ
    *
    * @note There is a single callback function for all pins on the related port.
    *
    * @param[in] callback The function to call on Pin interrupt
    */
   static __attribute__((always_inline)) void setPinCallback(PinCallbackFunction callback) {
      PcrBase::setCallback(callback);
   }

   /** Timer channel number */
   static constexpr uint32_t CHANNEL      = channel;

   /** Mask for Timer channel */
   static constexpr uint32_t CHANNEL_MASK = 1<<channel;

   /**
    * Enable channel (and set mode)\n
    * Enables owning FTM if not already enabled\n
    * Also see enableChannel()
    *
    * @param mode Mode of operation for FTM e.g.TpmChMode_PwmHighTruePulses
    *
    * @note Enables FTM as well
    */
   static void enable(TpmChMode tpmChMode = TpmChMode_PwmHighTruePulses) {
      if (!Tpm::isEnabled()) {
         // Enable parent FTM if needed
         Tpm::enable();
      }
      Tpm::tmr->CONTROLS[channel].CnSC = tpmChMode;
   }

   /**
    * Enable channel (and set mode)\n
    * Doesn't affect shared settings of owning Timer
    *
    * @param mode Mode of operation for FTM e.g.TpmChMode_PwmHighTruePulses
    */
   static __attribute__((always_inline)) void enableChannel(TpmChMode tpmChMode = TpmChMode_PwmHighTruePulses) {
      Tpm::tmr->CONTROLS[channel].CnSC = tpmChMode;
   }

   /**
    * Enable or disable interrupt from this channel\n
    * Note: It is necessary to enableNvicInterrupts() as well
    *
    * @param enable  True => enable, False => disable
    */
   static __attribute__((always_inline)) void enableChannelInterrupts(bool enable=true) {
      if (enable) {
         Tpm::tmr->CONTROLS[channel].CnSC |= TPM_CnSC_CHIE_MASK;
      }
      else {
         Tpm::tmr->CONTROLS[channel].CnSC &= ~TPM_CnSC_CHIE_MASK;
      }
   }

   /**
    * Enable/disable FTM interrupts in NVIC
    *
    * @param enable true to enable, false to disable
    */
   static __attribute__((always_inline)) void enableNvicInterrupts(bool enable=true) {
      TpmIrq_T<Info>::enableNvicInterrupts(enable);
   }

   /**
    * Enable/disable Pin interrupts in NVIC
    *
    * @param[in] enable true => enable, false => disable
    */
   static __attribute__((always_inline)) void enablePinNvicInterrupts(bool enable=true) {
      Pcr::enableNvicInterrupts(enable);
   }

   /**
    * Set Pin Control Register Value (apart from pin multiplexor value)
    *
    * @param pcrValue PCR value to set
    */
   static __attribute__((always_inline)) void setPCR(PcrValue pcrValue) {
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(Info::info[channel].pcrValue&PORT_PCR_MUX_MASK));
   }

   /**
    * Set Pin Control Register (PCR) value
    *
    * @param[in] pinPull          One of PinPull_None, PinPull_Up, PinPull_Down (defaults to PinPull_None)
    * @param[in] pinDriveStrength One of PinDriveStrength_Low, PinDriveStrength_High (defaults to PinDriveLow)
    * @param[in] pinDriveMode     One of PinDriveMode_PushPull, PinDriveMode_OpenDrain (defaults to PinPushPull)
    * @param[in] pinIrq           One of PinIrq_None, etc (defaults to PinIrq_None)
    * @param[in] pinFilter        One of PinFilter_None, PinFilter_Passive (defaults to PinFilter_None)
    * @param[in] pinSlewRate      One of PinSlewRate_Slow, PinSlewRate_Fast (defaults to PinSlewRate_Fast)
    * @param[in] pinMux           One of PinMux_Analogue, PinMux_Gpio etc (defaults to FTM selection value)
    */
   static __attribute__((always_inline)) void setPCR(
         PinPull           pinPull,
         PinDriveStrength  pinDriveStrength  = PinDriveStrength_Low,
         PinDriveMode      pinDriveMode      = PinDriveMode_PushPull,
         PinIrq            pinIrq            = PinIrq_None,
         PinFilter         pinFilter         = PinFilter_None,
         PinSlewRate       pinSlewRate       = PinSlewRate_Fast,
         PinMux            pinMux            = (PinMux)(Info::info[channel].pcrValue&PORT_PCR_MUX_MASK)
         ) {
      Pcr::setPCR(pinPull,pinDriveStrength,pinDriveMode,pinIrq,pinFilter,pinSlewRate,pinMux);
   }
   /**
    * Set PWM high time in ticks\n
    * Assumes value is less than period
    *
    * @param highTime   PWM high time in ticks
    *
    * @return E_NO_ERROR on success
    */
   static __attribute__((always_inline)) ErrorCode setHighTime(uint32_t highTime) {
      return Tpm::setHighTime(highTime, channel);
   }

   /**
    * Set PWM high time in seconds\n
    * Higher precision float version
    *
    * @param highTime   PWM high time in seconds
    *
    * @return E_NO_ERROR on success
    */
   static __attribute__((always_inline)) ErrorCode setHighTime(float highTime) {
      return Tpm::setHighTime(highTime, channel);
   }
   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    */
   static __attribute__((always_inline)) void setDutyCycle(int dutyCycle) {
      Tpm::setDutyCycle(dutyCycle, channel);
   }

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    */
   static __attribute__((always_inline)) void setDutyCycle(float dutyCycle) {
      Tpm::setDutyCycle(dutyCycle, channel);
   }

   /**
    * Set Timer event time
    *
    * @param eventTime  Absolute event time
    */
   static __attribute__((always_inline)) void setEventTime(uint16_t eventTime) {
      Tpm::setEventTime(eventTime, channel);
   }

   /**
    * Set Timer event time
    *
    * @param eventTime  Event time relative to current event time (i.e. Timer channel CnV value)
    */
   static __attribute__((always_inline)) void setDeltaEventTime(uint16_t eventTime) {
      Tpm::setDeltaEventTime(eventTime, channel);
   }

   /**
    * Set Timer event time
    *
    * @param eventTime  Event time relative to current time (i.e. Timer CNT value)
    */
   static __attribute__((always_inline)) void setRelativeEventTime(uint16_t eventTime) {
      Tpm::setRelativeEventTime(eventTime, channel);
   }

   /**
    * Get channel number
    *
    * @return Channel number (0-7)
    */
   static __attribute__((always_inline)) constexpr int getChannelNumber(void) {
      return channel;
   }

   /**
    * Clear interrupt flag on channel
    */
   static __attribute__((always_inline)) void clearInterruptFlag(void) {
      Tpm::tmr->CONTROLS[channel].CnSC &= ~TPM_CnSC_CHF_MASK;
   }
};

#ifdef USBDM_TPM0_IS_DEFINED
/**
 * Template class representing a Timer channel
 *
 * Example
 * @code
 * // Instantiate the timer channel (for TPM0 channel 6)
 * using Tmr0_ch6 = USBDM::Tpm0Channel<6>;
 *
 * // Initialise PWM with initial period and alignment
 * Tmr0_ch6.setMode(200, USBDM::TpmMode_LeftAlign);
 *
 * // Change period (in ticks)
 * Tmr0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * Tmr0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel Timer channel
 */
template <int channel>
class Tpm0Channel : public TpmChannel_T<Tpm0Info, channel> {};

/**
 * Class representing TPM0
 */
using Tpm0 = TpmIrq_T<Tpm0Info>;
#endif

#ifdef USBDM_TPM1_IS_DEFINED
/**
 * Template class representing a TPM1 timer channel
 *
 * Refer @ref Tpm0Channel
 *
 * @tparam channel Timer channel
 */
template <int channel>
class Tpm1Channel : public TpmChannel_T<Tpm1Info, channel> {};

/**
 * Class representing TPM1
 */
using Tpm1 = TpmIrq_T<Tpm1Info>;
#endif

#ifdef USBDM_TPM2_IS_DEFINED
/**
 * Template class representing a TPM2 timer channel
 *
 * Refer @ref Tpm0Channel
 *
 * @tparam channel Timer channel
 */
template <int channel>
class Tpm2Channel : public TpmChannel_T<Tpm2Info, channel> {};

/**
 * Class representing TPM2
 */
using Tpm2 = TpmIrq_T<Tpm2Info>;
#endif

#ifdef USBDM_TPM3_IS_DEFINED
/**
 * Template class representing a TPM3 timer channel
 *
 * Refer @ref Tpm0Channel
 *
 * @tparam channel Timer channel
 */
template <int channel>
class Tpm3Channel : public TpmBase_T<Tpm3Info>, CheckSignal<Tpm2Info, channel> {

/**
 * Class representing TPM3
 */
   using Tpm3 = TpmIrq_T<Tpm3Info>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_TPM_H */

