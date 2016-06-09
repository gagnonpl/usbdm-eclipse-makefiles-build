/**
 * @file     lptmr.h
 * @brief    Low power timer interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef INCLUDE_USBDM_LPTMR_H_
#define INCLUDE_USBDM_LPTMR_H_
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "derivative.h"
#include "system.h"
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup LPTMR_Group LPTMR, Low Power Timer
 * @brief Abstraction for Low Power Timer
 * @{
 */

/**
 * Type definition for LPTMR interrupt call back
 */
typedef void (*LPTMRCallbackFunction)(void);

/**
 * @brief Template class representing a Low Power Timer
 */
template<class Info>
class Lptmr_T {

private:
   /** Minimum resolution required when setting interval */
   static constexpr int MINIMUM_RESOLUTION = 100;

protected:
   /** Callback function for ISR */
   static LPTMRCallbackFunction callback;

public:
   /**
    * Set callback for ISR
    *
    * @param theCallback The function to call from stub ISR
    */
   static void setCallback(LPTMRCallbackFunction theCallback) {
#ifdef DEBUG_BUILD
      assert(Info::irqHandlerInstalled);
#endif
      callback = theCallback;

      // Enable interrupts in LPTMR
      lptmr->CSR |= LPTMR_CSR_TIE_MASK|LPTMR_CSR_TCF_MASK;

      // Set priority level
      NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);

      // Enable interrupts in NVIC
      NVIC_EnableIRQ(Info::irqNums[0]);
   }

   /**
    * PIT interrupt handler. \n
    * Calls PIT0 callback
    */
   static void irqHandler() {
      // Clear interrupt flag
      lptmr->CSR |= LPTMR_CSR_TCF_MASK;

      if (callback != 0) {
         callback();
      }
   }

protected:
   /** Pointer to hardware */
   static constexpr volatile LPTMR_Type *lptmr     = reinterpret_cast<volatile LPTMR_Type *>(Info::basePtr);

   /* Pointer to clock register */
   static constexpr volatile uint32_t   *clockReg  = reinterpret_cast<volatile uint32_t *>(Info::clockReg);

public:
   /**
    * Enable LPTMR\n
    * Includes initialising clock and any pins used
    */
   static void enable() {
      // Configure pins
      Info::initPCRs();

      // Enable clock
      *clockReg |= Info::clockMask;
      __DMB();

      configure();
   }

   /**
    *  Configure the LPTMR
    *
    *  @param period    Period for the timer in timer ticks
    *  @param csr       Control Status Register
    *  @param psr       Prescale Register
    */
   static void configure(uint16_t period=Info::cmr, uint32_t csr=Info::csr, uint32_t psr=Info::psr) {
      // Disable timer
      lptmr->CSR  = csr;
      // PCS 0,1,2,3 => MCGIRCLK, LPO, ERCLK32K, OSCERCLK
      lptmr->PSR  = psr;
      // Period/Compare value
      lptmr->CMR  = period;
      // Enable timer
      lptmr->CSR |= LPTMR_CSR_TEN_MASK;

      if (csr & LPTMR_CSR_TIE_MASK) {
         // Enable timer interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
   }
   /**
    *   Disable the LPTMR
    */
   static void finalise(void) {
      // Disable timer
      lptmr->CSR = 0;
      NVIC_DisableIRQ(Info::irqNums[0]);
      *clockReg &= ~Info::clockMask;
   }

   /**
    * Converts a time in microseconds to number of ticks
    *
    * @param time Time in microseconds
    * @return Time in ticks
    *
    * @note Assumes prescale has been chosen appropriately.
    * @note Rudimentary range checking only.
    */
   static uint32_t convertMicrosecondsToTicks(int time) {

      // Calculate period
      uint32_t tickRate = Info::getClockFrequency();
      uint64_t rv       = ((uint64_t)time*tickRate)/1000000;

#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
      if (rv == 0) {
         // Attempt to set too short a period
         __BKPT();
      }
#endif
      return rv;
   }
   /**
    * Converts a time in milliseconds to number of ticks
    *
    * @param time Time in milliseconds
    * @return Time in ticks
    *
    * @note Assumes prescale has been chosen appropriately.
    * @note Rudimentary range checking only.
    */
   static uint32_t convertMillisecondsToTicks(int time) {

      // Calculate period
      uint32_t tickRate = Info::getClockFrequency();
      uint64_t rv       = ((uint64_t)time*tickRate)/1000;

#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
      if (rv == 0) {
         // Attempt to set too short a period
         __BKPT();
      }
#endif
      return rv;
   }

   /**
    * Converts a time in seconds to number of ticks
    *
    * @param time Time in seconds (float!)
    * @return Time in ticks
    *
    * @note Uses floating point
    */
   static uint32_t convertSecondsToTicks(float time) {

      // Calculate period
      float    tickRate = Info::getClockFrequencyF();
      uint64_t rv       = (time*tickRate);

#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
      if (rv == 0) {
         // Attempt to set too long a period
         __BKPT();
      }
#endif
      return rv;
   }

   /**
    * Set period of timer
    *
    * @param period Period in seconds as a float
    *
    * @note May enable and adjust the pre-scaler to appropriate value.
    *
    * @return true => success, false => failed to find suitable values for PBYP & PRESCALE
    */
   static ErrorCode setPeriod(float period) {
      float inputClock = Info::getInputClockFrequency();
      int      prescaleFactor=1;
      uint32_t prescalerValue=0;
      while (prescalerValue<=16) {
         float    clock = inputClock/prescaleFactor;
         uint32_t mod   = round(period*clock);
         if (mod < MINIMUM_RESOLUTION) {
            // Too short a period for 1% resolution
            return setErrrCode(E_TOO_SMALL);
         }
         if (mod <= 65535) {
            // Disable LPTMR before prescale change
            lptmr->CSR &= ~LPTMR_CSR_TEN_MASK;
            __DSB();
            lptmr->CMR  = mod;
            lptmr->PSR  = (lptmr->PSR & ~(LPTMR_PSR_PRESCALE_MASK|LPTMR_PSR_PBYP_MASK))|LPTMR_PSR_PRESCALE(prescalerValue-1)|LPTMR_PSR_PBYP(prescalerValue==0);
            lptmr->CSR |= LPTMR_CSR_TEN_MASK;
            return E_NO_ERROR;
         }
         prescalerValue++;
         prescaleFactor <<= 1;
      }
      // Too long a period
      return setErrrCode(E_TOO_LARGE);
   }


};

template<class Info> LPTMRCallbackFunction Lptmr_T<Info>::callback = 0;

#ifdef LPTMR0
/**
 * @brief Class representing LPTMR0
 *
 * <b>Example</b>
 * @code
 *
 * // LPTMR callback
 * void flash(void) {
 *    RED_LED::toggle();
 * }
 *
 * ...
 *
 * // Configure LPTMR
 * Lptmr0::configure(1000);
 *
 * // This handler is set programmatically
 * Lptmr0::setCallback(flash);
 *
 * @endcode
 */
using Lptmr0 = Lptmr_T<Lptmr0Info>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_LPTMR_H_ */
