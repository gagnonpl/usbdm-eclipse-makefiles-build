/**
 * @file     USBHS.h (180.ARM_Peripherals/Project_Headers/USBHS.h)
 * @brief    USB High Speed OTG Controller
 *
 * @version  V4.12.1.80
 * @date     13 April 2019
 */
#ifndef HEADER_USBHS_H
#define HEADER_USBHS_H
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
 * @addtogroup USBHS_Group USBHS, USB High Speed OTG Controller
 * @brief C++ Class allowing access to USBHS interface
 * @{
 */

/**
 * Type definition for interrupt call back
 */
typedef void (*UsbhsCallbackFunction)();

/**
 * Virtual Base class for USBHS interface
 */
class Usbhs {

protected:
   /** Callback to catch unhandled interrupt */
   static void unhandledCallback() {
      // Not considered an error as may be using polling
   }

   volatile USBHS_Type  *usbhs;                 //!< USBHS hardware instance
   
   /**
    * Construct USBHS interface
    *
    * @param[in]  usbhs     Base address of USBHS hardware
    */
   Usbhs(volatile USBHS_Type *usbhs) : usbhs(usbhs) {
   }

   /**
    * Destructor
    */
   ~Usbhs() {}

public:
};

/**
 * @brief Template class representing an USBHS interface
 *
 * <b>Example</b>
 *
 * @code
 *  @endcode
 *
 * @tparam Info            Class describing USBHS hardware
 */
template<class Info> class UsbhsBase_T : public Usbhs {

public:
   // Handle on USBHS hardware
   static constexpr volatile USBHS_Type *USBHS_ = Info::usbhs;

   // USBHS SCL (clock) Pin
   using sclGpio = GpioTable_T<Info, 0, USBDM::ActiveLow>; // Inactive is high

   // USBHS SDA (data) Pin
   using sdaGpio = GpioTable_T<Info, 1, USBDM::ActiveHigh>;

   /** Used by ISR to obtain handle of object */
   static USBHS_Type *thisPtr;

   /** Callback function for ISR */
   static UsbhsCallbackFunction sCallback;

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
    * Construct USBHS interface
    *
    * @param[in]  bps        Tx/Rx rate
    * @param[in]  usbhsMode    Mode of operation
    * @param[in]  myAddress  Address of this device on bus (not currently used)
    */
   UsbhsBase_T(unsigned bps=400000, uint8_t myAddress=0) : Usbhs(&Info::usbhs()) {

#ifdef DEBUG_BUILD
      // Check pin assignments
      static_assert(Info::info[0].gpioBit != UNMAPPED_PCR, "USBHSx_SCL has not been assigned to a pin - Modify Configure.usbdm");
      static_assert(Info::info[1].gpioBit != UNMAPPED_PCR, "USBHSx_SDA has not been assigned to a pin - Modify Configure.usbdm");
#endif

   }

   /**
    * Destructor
    */
   virtual ~UsbhsBase_T() {}

   /**
    * Set channel Callback function\n
    * This callback is executed when the USBHS state machine returns to the IDLE state
    * at the end of a transaction.
    *
    * @param[in] callback Callback function to execute on interrupt.\n
    *                     Use nullptr to remove callback.
    */
   static __attribute__((always_inline)) void setCallback(UsbhsCallbackFunction callback) {
      static_assert(Info::irqHandlerInstalled, "USBHS not configured for interrupts");
      if (callback == nullptr) {
         callback = Usbhs::unhandledCallback;
      }
      sCallback = callback;
   }

   static void irqHandler() {
   }
};

template<class Info> UsbhsCallbackFunction UsbhsBase_T<Info>::sCallback = Usbhs::unhandledCallback;

/** Used by ISR to obtain handle of object */
template<class Info> USBHS_Type *UsbhsBase_T<Info>::thisPtr = 0;

#if defined(USBDM_USBHS0_IS_DEFINED)
/**
 * @brief Class representing the USBHS0 interface
 *
 * <b>Example</b>\n
 * Refer @ref UsbhsBase_T
 */
using Usbhs0 = UsbhsBase_T<Usbhs0Info>;
#endif

/**
 * End USBHS_Group
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_USBHS_H */
