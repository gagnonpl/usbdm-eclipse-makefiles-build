/**
 * @file     rtc.h (180.ARM_Peripherals/Project_Headers/rtc.h)
 * @brief    Real Time Clock
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef HEADER_RTC_H
#define HEADER_RTC_H
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup RTC_Group RTC, Real Time Clock
 * @brief Abstraction for Real Time Clock
 * @{
 */

/**
 * Type definition for RTC interrupt callback.
 * This is used for seconds and alarm callbacks.
 *
 *  @param[in]  timeSinceEpoch - Time since the epoch in seconds
 */
typedef void (*RTCCallbackFunction)(uint32_t timeSinceEpoch);

/**
 * Template class providing interface to Real Time Clock
 *
 * @tparam info      Information class for RTC
 *
 * @code
 * using rtc = RtcBase_T<RtcInfo>;
 *
 *  rtc::enableAlarmInterrupts();
 *
 * @endcode
 */
template <class Info>
class RtcBase_T {

public:
   /** Handler for unexpected interrupts */
   static void unhandledCallback(uint32_t) {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

protected:
   /** Callback function for alarm ISR */
   static RTCCallbackFunction sAlarmCallback;

   /** Callback function for seconds ISR */
   static RTCCallbackFunction sSecondsCallback;

public:
   /**
    * Alarm IRQ handler
    */
   static void irqAlarmHandler(void) {
      // Clear alarm
      RtcBase_T<Info>::rtc().TAR   = 0;
      // Call handler
      sAlarmCallback(RtcBase_T<Info>::rtc().TSR);
   }

   /**
    * Alarm IRQ handler
    */
   static void irqSecondsHandler(void) {
      // Call handler
      sSecondsCallback(RtcBase_T<Info>::rtc().TSR);
   }

   /**
    * Enable/disable RTC Alarm interrupts
    *
    * @param[in]  enable True=>enable, False=>disable
    */
   static void enableAlarmInterrupts(bool enable=true) {
      if (enable) {
         rtc().IER   |= RTC_IER_TAIE_MASK;
      }
      else {
         rtc().IER   &= ~RTC_IER_TAIE_MASK;
      }
   }
   /**
    * Enable/disable RTC Seconds interrupts
    *
    * @param[in]  enable True=>enable, False=>disable
    */
   static void enableSecondsInterrupts(bool enable=true) {
      if (enable) {
         rtc().IER   |= RTC_IER_TSIE_MASK;
      }
      else {
         rtc().IER   &= ~RTC_IER_TSIE_MASK;
      }
   }
   /**
    * Set Alarm callback function
    *
    *  @param[in]  callback  Callback function to be executed on alarm interrupt.\n
    *                        Use nullptr to remove callback.
    */
   static void setAlarmCallback(RTCCallbackFunction callback) {
      usbdm_assert(Info::irqHandlerInstalled, "RTC not configure for interrupts");
      if (callback == nullptr) {
         callback = unhandledCallback;
      }
      sAlarmCallback = callback;
   }

   /**
    * Set Seconds callback function
    *
    *  @param[in]  callback  Callback function to be executed on seconds interrupt.\n
    *                        Use nullptr to remove callback.
    */
   static void setSecondsCallback(RTCCallbackFunction callback) {
      usbdm_assert(Info::irqHandlerInstalled, "RTC not configure for interrupts");
      if (callback == nullptr) {
         callback = unhandledCallback;
      }
      sSecondsCallback = callback;
   }


protected:
   /** Hardware instance */
   static volatile RTC_Type &rtc()      { return Info::rtc(); }
   
public:
   /**
    * Configures all mapped pins associated with this peripheral
    */
   static void __attribute__((always_inline)) configureAllPins() {
      // Configure pins
      Info::initPCRs();
   }

   /**
    * Initialise RTC to default settings.
    * Configures all RTC pins
    */
   static void defaultConfigure() {

      // Enable clock to RTC interface
      // (RTC used its own clock internally)
      Info::enableClock();

      if ((Info::cr&RTC_CR_OSCE_MASK) == 0) {
         // RTC disabled
         return;
      }

      configureAllPins();

      // Enable to debug RTX startup
#if defined(DEBUG_BUILD) && 0
      // Software reset RTC - trigger cold start
      rtc().CR  = RTC_CR_SWR_MASK;
      rtc().CR  = 0;

      // Disable interrupts
      rtc().IER  = 0;
#endif

      if ((rtc().SR&RTC_SR_TIF_MASK) != 0) {
         // RTC not running yet or invalid - re-initialise

         // Software reset RTC
         rtc().CR  = RTC_CR_SWR_MASK;
         rtc().CR  = 0;

         // Configure oscillator
         // Note - on KL25 this will disable the standard oscillator
         rtc().CR  = Info::cr;

         // Wait startup time
         for (int i=0; i<100000; i++) {
            __asm__("nop");
         }

         // Set current time
         rtc().TSR = Info::coldStartTime;
         rtc().SR  = RTC_SR_TCE_MASK;

         // Time compensation values
         rtc().TCR = RtcInfo::tcr;

         // Lock registers
         rtc().LR  = RtcInfo::lr;

#ifdef RTC_WAR_IERW_MASK
         // Write access
         rtc().WAR = RtcInfo::war;
#endif
#ifdef RTC_RAR_IERR_MASK
         // Read access
         rtc().RAR = RtcInfo::rar;
#endif
      }

      // Update settings
      rtc().CR   = Info::cr;
   }

   /**
    * Set up the RTC out of reset.
    */
   static void initialise() {
      defaultConfigure();
   }

   /**
    * Enable interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    */
   static void enableNvicInterrupts() {
      enableNvicInterrupt(Info::irqNums[0]);
      if (Info::irqCount>1) {
         enableNvicInterrupt(Info::irqNums[1]);
      }
   }

   /**
    * Enable and set priority of interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(uint32_t nvicPriority) {
      enableNvicInterrupt(Info::irqNums[0], nvicPriority);
      if (Info::irqCount>1) {
         enableNvicInterrupt(Info::irqNums[1], nvicPriority);
      }
   }

   /**
    * Disable interrupts in NVIC
    */
   static void disableNvicInterrupts() {
      NVIC_DisableIRQ(Info::irqNums[0]);
      if (Info::irqCount>1) {
         NVIC_DisableIRQ(Info::irqNums[1]);
      }
   }

   /**
    * Sets the system RTC time
    *
    *  @param[in]  timeSinceEpoch - time since the epoch in seconds
    */
   static void setTime(uint32_t timeSinceEpoch) {
      rtc().SR  = 0;
      rtc().TSR = timeSinceEpoch;
      rtc().SR  = RTC_SR_TCE_MASK;
   }

   /**
    *  Get current alarm time
    *
    *  @return alarm time as 32-bit number
    */
   static uint32_t getTime(void) {
      return rtc().TSR;
   }

   /**
    *  Get current alarm time
    *
    *  @return Alarm time in seconds relative to the epoch
    */
   static uint32_t getAlarmTime(void) {
      return rtc().TAR;
   }

   /**
    *  Set alarm time
    *
    *  @param[in]  timeSinceEpoch - Alarm time in seconds relative to the epoch
    */
   static void setAlarmTime(uint32_t timeSinceEpoch) {
      rtc().TAR = timeSinceEpoch;
   }

};

template<class Info> RTCCallbackFunction RtcBase_T<Info>::sAlarmCallback   = unhandledCallback;
template<class Info> RTCCallbackFunction RtcBase_T<Info>::sSecondsCallback = unhandledCallback;

#ifdef USBDM_RTC_IS_DEFINED
/**
 * Class representing RTC
 */
class Rtc : public RtcBase_T<RtcInfo>{};

#endif

/**
 * End RTC_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_RTC_H */
