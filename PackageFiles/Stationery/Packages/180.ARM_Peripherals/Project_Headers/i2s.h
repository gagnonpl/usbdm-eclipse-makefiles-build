/**
 * @file     I2S.h (180.ARM_Peripherals/Project_Headers/I2S.h)
 * @brief    I2S interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2019
 */
#ifndef HEADER_I2S_H
#define HEADER_I2S_H
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include <stdint.h>
#include "derivative.h"
#include "hardware.h"
#ifdef __CMSIS_RTOS
#include "cmsis.h"
#endif

namespace USBDM {

/**
 * @addtogroup I2S_Group I2S, Inter-Integrated-Circuit Interface
 * @brief C++ Class allowing access to I2S interface
 * @{
 */

/**
 * Type definition for interrupt call back
 */
typedef void (*I2sCallbackFunction)();

/**
 * Virtual Base class for I2S interface
 */
class I2s {

protected:
   /** Callback to catch unhandled interrupt */
   static void unhandledCallback() {
      // Not considered an error as may be using polling
   }

   volatile I2S_Type  *i2s;                 //!< I2S hardware instance
   
   /**
    * Construct I2S interface
    *
    * @param[in]  i2s     Base address of I2S hardware
    */
   I2s(volatile I2S_Type *i2s) : i2s(i2s) {
   }

   /**
    * Destructor
    */
   ~I2s() {}

public:
};

/**
 * @brief Template class representing an I2S interface
 *
 * <b>Example</b>
 *
 * @code
 *  @endcode
 *
 * @tparam Info            Class describing I2S hardware
 */
template<class Info> class I2sBase_T : public I2s {

public:
   // Handle on I2S hardware
   static constexpr volatile I2S_Type *I2S = Info::i2s;

   // I2S SCL (clock) Pin
   using sclGpio = GpioTable_T<Info, 0, USBDM::ActiveLow>; // Inactive is high

   // I2S SDA (data) Pin
   using sdaGpio = GpioTable_T<Info, 1, USBDM::ActiveHigh>;

   /** Used by ISR to obtain handle of object */
   static I2S_Type *thisPtr;

   /** Callback function for ISR */
   static I2sCallbackFunction sCallback;

   /**
    * Enable interrupts in NVIC
    */
   static void enableNvicInterrupts() {
      NVIC_EnableIRQ(Info::irqNums[0]);
   }

   /**
    * Enable and set priority of interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(uint32_t nvicPriority) {
      enableNvicInterrupt(Info::irqNums[0], nvicPriority);
   }

   /**
    * Disable interrupts in NVIC
    */
   static void disableNvicInterrupts() {
      NVIC_DisableIRQ(Info::irqNums[0]);
   }

public:
   /**
    * Configures all mapped pins associated with this peripheral
    */
   static void __attribute__((always_inline)) configureAllPins() {
      // Configure pins
      Info::initPCRs();
   }

   /**
    * Construct I2S interface
    *
    * @param[in]  bps        Tx/Rx rate
    * @param[in]  i2sMode    Mode of operation
    * @param[in]  myAddress  Address of this device on bus (not currently used)
    */
   I2sBase_T(unsigned bps=400000, uint8_t myAddress=0) : I2s(&Info::i2s()) {

#ifdef DEBUG_BUILD
      // Check pin assignments
      static_assert(Info::info[0].gpioBit != UNMAPPED_PCR, "I2Sx_SCL has not been assigned to a pin - Modify Configure.usbdm");
      static_assert(Info::info[1].gpioBit != UNMAPPED_PCR, "I2Sx_SDA has not been assigned to a pin - Modify Configure.usbdm");
#endif

   }

   /**
    * Destructor
    */
   virtual ~I2sBase_T() {}

   /**
    * Set channel Callback function\n
    * This callback is executed when the I2S state machine returns to the IDLE state
    * at the end of a transaction.
    *
    * @param[in] callback Callback function to execute on interrupt.\n
    *                     Use nullptr to remove callback.
    */
   static __attribute__((always_inline)) void setCallback(I2sCallbackFunction callback) {
      static_assert(Info::irqHandlerInstalled, "I2S not configured for interrupts");
      if (callback == nullptr) {
         callback = I2s::unhandledCallback;
      }
      sCallback = callback;
   }

   static void irqHandler() {
   }
};

template<class Info> I2sCallbackFunction I2sBase_T<Info>::sCallback = I2s::unhandledCallback;

/** Used by ISR to obtain handle of object */
template<class Info> I2S_Type *I2sBase_T<Info>::thisPtr = 0;

#if defined(USBDM_I2S0_IS_DEFINED)
/**
 * @brief Class representing the I2S0 interface
 *
 * <b>Example</b>\n
 * Refer @ref I2sBase_T
 */
using I2s0 = I2sBase_T<I2s0Info>;
#endif

#if defined(USBDM_I2S1_IS_DEFINED)
/**
 * @brief Class representing the I2S1 interface
 *
 * <b>Example</b>
 * Refer @ref I2sBase_T
 */
using I2s1 = I2sBase_T<I2s1Info>;
#endif

#if defined(USBDM_I2S2_IS_DEFINED)
/**
 * @brief Class representing the I2S2 interface
 *
 * <b>Example</b>
 * Refer @ref I2SBase_T
 */
using I2s2 = I2sBase_T<I2s2Info>;
#endif

/**
 * End I2S_Group
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_I2S_H */
