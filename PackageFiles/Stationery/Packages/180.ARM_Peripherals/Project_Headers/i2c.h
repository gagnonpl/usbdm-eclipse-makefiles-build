/**
 * @file     i2c.h (180.ARM_Peripherals/Project_Headers/i2c.h)
 * @brief    I2C interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_I2C_H
#define HEADER_I2C_H
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
 * @addtogroup I2C_Group I2C, Inter-Integrated-Circuit Interface
 * @brief C++ Class allowing access to I2C interface
 * @{
 */

/**
 * Type definition for interrupt call back
 * @param status Interrupt status value from SPI->SR
 */
typedef void (*I2cCallbackFunction)();

/**
 * I2C Operating mode
 */
enum I2cMode {
   I2cMode_Polled    = I2C_C1_IICIE(0),   //!< Operate in Polled mode
   I2cMode_Interrupt = I2C_C1_IICIE(1),   //!< Operate in Interrupt mode
};

/**
 * Virtual Base class for I2C interface
 */
class I2c {

public:
   /** States for the I2C state machine */
   enum I2C_State { i2c_idle, i2c_txData, i2c_rxData, i2c_rxAddress };

   I2C_State           state;               //!< State of current transaction

protected:
   /** Callback to catch unhandled interrupt */
   static void unhandledCallback() {
      // Not considered an error as may be using polling
   }

   volatile I2C_Type  *i2c;                 //!< I2C hardware instance
   const I2cMode       i2cMode;             //!< Mode of operation (I2cMode_Interrupt/I2cMode_Polled)
   uint16_t            rxBytesRemaining;    //!< Number of receive bytes remaining in current transaction
   uint16_t            txBytesRemaining;    //!< Number of transmit bytes remaining in current transaction
   uint8_t            *rxDataPtr;           //!< Pointer to receive data for current transaction
   const uint8_t      *txDataPtr;           //!< Pointer to transmit data for current transaction
   uint8_t             addressedDevice;     //!< Address of device being communicated with
   ErrorCode           errorCode;           //!< Error code from last transaction

   /** I2C baud rate divisor table */
   static const uint16_t I2C_DIVISORS[4*16];

   /**
    * Construct I2C interface
    *
    * @param[in]  i2c     Base address of I2C hardware
    * @param[in]  i2cMode Mode of operation (I2cMode_Interrupt or I2cMode_Polled)
    */
   I2c(volatile I2C_Type *i2c, I2cMode i2cMode) :
      state(i2c_idle), i2c(i2c), i2cMode(i2cMode), rxBytesRemaining(0),
      txBytesRemaining(0), rxDataPtr(0), txDataPtr(0), addressedDevice(0),
      errorCode(E_NO_ERROR) {
   }

   /**
    * Destructor
    */
   ~I2c() {}

   /**
    * Calculate value for baud rate register of I2C
    *
    * This is calculated from processor bus frequency and given bps
    *
    * @param[in]  bps            Interface speed in bits-per-second
    * @param[in]  clockFrequency Frequency of I2C input clock
    *
    * @return I2C_F value representing speed
    */
   static uint8_t getBPSValue(uint32_t bps, uint32_t clockFrequency);

   /**
    * Start Rx/Tx sequence by sending address byte
    *
    * @param[in]  address - address of slave to access
    */
   void sendAddress(uint8_t address);

   /**
    * Set baud factor value for interface
    *
    * This is calculated from processor frequency and given bits-per-second
    *
    * @param[in]  bps            - Interface speed in bits-per-second
    * @param[in]  clockFrequency - Frequency of I2C input clock
    */
   void setBPS(uint32_t bps, uint32_t clockFrequency) {
      i2c->F = getBPSValue(bps, clockFrequency);
   }

public:

#ifdef __CMSIS_RTOS
   /**
    * Obtain I2C MUTEX
    *
    * @param[in]  milliseconds How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus startTransaction(int milliseconds=osWaitForever) = 0;

   /**
    * Release I2C MUTEX
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus endTransaction() = 0;
#else
   /**
    * Obtain I2C MUTEX - dummy
    */
   virtual ErrorCode startTransaction(int =0) {return E_NO_ERROR;};
   /**
    * Release I2C MUTEX - dummy
    */
   virtual ErrorCode endTransaction() {return E_NO_ERROR;};
#endif

   /**
    * Clear bus hang
    *
    * Generates I2C_SCL clock until I2C_SDA goes high.
    *
    * This is useful if a slave is part-way through a transaction when the master goes away!
    */
   virtual void busHangReset() = 0;

   /**
    * Wait for current sequence to complete
    */
   void waitWhileBusy(void) {
      while (state != i2c_idle) {
         if ((i2c->C1&I2C_C1_IICIE_MASK) == 0) {
            poll();
         }
         else {
            __asm__("wfi");
         }
      }
   }

   /**
    * I2C state-machine poll function.
    * May be called by polling loop or interrupt handler.
    */
   virtual void poll(void);

   /**
    * Transmit message
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  size     Size of transmission data
    * @param[in]  data     Data to transmit, 0th byte is often register address
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode transmit(uint8_t address, uint16_t size, const uint8_t data[]);

   /**
    * Receive message
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  size     Size of reception data
    * @param[out] data     Data buffer for reception
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode receive(uint8_t address, uint16_t size,  uint8_t data[]);

   /**
    * Transmit message followed by receive message.
    *
    * Uses repeated-start.
    *
    * @param[in]  address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]  txSize   Size of transmission data
    * @param[in]  txData   Data for transmission
    * @param[in]  rxSize   Size of reception data
    * @param[out] rxData   Date buffer for reception
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode txRx(uint8_t address, uint16_t txSize, const uint8_t txData[], uint16_t rxSize, uint8_t rxData[] );

   /**
    * Transmit message followed by receive message.
    * Uses repeated-start.\n
    * Uses shared transmit and receive buffer
    *
    * @param[in]    address  Address of slave to communicate with (should include LSB = R/W bit = 0)
    * @param[in]    txSize   Size of transmission data
    * @param[in]    rxSize   Size of reception data
    * @param[inout] data     Data for transmission and reception
    *
    * @return E_NO_ERROR on success
    */
   ErrorCode txRx(uint8_t address, uint16_t txSize, uint16_t rxSize, uint8_t data[] );

};

/**
 * @brief Template class representing an I2C interface
 *
 * <b>Example</b>
 *
 * @code
 *  // Instantiate interface
 *  I2c *i2c0 = new USBDM::I2cBase_T<I2cInfo>();
 *
 *  // Transmit data
 *  const uint8_t txDataBuffer[] = {0x11, 0x22, 0x33, 0x44};
 *
 *  // Receive buffer
 *  uint8_t rxDataBuffer[5];
 *
 *  for(;;) {
 *     // Transmit block
 *     i2c->transmit(0x1D<<1, sizeof(txDataBuffer), txDataBuffer);
 *
 *     // Receive block
 *     i2c->receive((0x1D<<1)|1, sizeof(rxDataBuffer), rxDataBuffer);
 *
 *     // Transmit block followed by read block (using repeated-start)
 *     // Note rxDataBuffer may be the same as txDataBuffer
 *     i2c->txRx(0x1D<<1, sizeof(txDataBuffer), txDataBuffer, sizeof(rxDataBuffer), rxDataBuffer);
 *  }
 *  @endcode
 *
 * @tparam Info            Class describing I2C hardware
 */
template<class Info> class I2cBase_T : public I2c {

public:
   // Handle on I2C hardware
   static constexpr volatile I2C_Type *I2C = Info::i2c;

   // I2C SCL (clock) Pin
   using sclGpio = GpioTable_T<Info, 0, USBDM::ActiveLow>; // Inactive is high

   // I2C SDA (data) Pin
   using sdaGpio = GpioTable_T<Info, 1, USBDM::ActiveHigh>;

   /** Used by ISR to obtain handle of object */
   static I2c *thisPtr;

   /** Callback function for ISR */
   static I2cCallbackFunction sCallback;

#ifdef __CMSIS_RTOS
protected:
   /**
    * Mutex to protect access\n
    * Using a static accessor function avoids issues with static object initialisation order
    *
    * @return mutex
    */
   static CMSIS::Mutex &mutex() {
      static CMSIS::Mutex mutex;
      return mutex;
   }

public:
   /**
    * Obtain I2C mutex
    *
    * @param[in]  milliseconds How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus startTransaction(int milliseconds=osWaitForever) override {
      return mutex().wait(milliseconds);
   }

   /**
    * Release I2C mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus endTransaction() override {
      return mutex().release();
   }
#endif

public:
   /**
    * Configures all mapped pins associated with this peripheral
    */
   static void __attribute__((always_inline)) configureAllPins() {
      // Configure pins
      Info::initPCRs();
   }

   /**
    * Construct I2C interface
    *
    * @param[in]  bps        Tx/Rx rate
    * @param[in]  i2cMode    Mode of operation
    * @param[in]  myAddress  Address of this device on bus (not currently used)
    */
   I2cBase_T(unsigned bps=400000, I2cMode i2cMode=I2cMode_Polled, uint8_t myAddress=0) : I2c(&Info::i2c(), i2cMode) {

#ifdef DEBUG_BUILD
      // Check pin assignments
      static_assert(Info::info[0].gpioBit != UNMAPPED_PCR, "I2Cx_SCL has not been assigned to a pin - Modify Configure.usbdm");
      static_assert(Info::info[1].gpioBit != UNMAPPED_PCR, "I2Cx_SDA has not been assigned to a pin - Modify Configure.usbdm");
#endif

      busHangReset();

      init(myAddress);
      setBPS(bps);

      if (Info::mapPinsOnEnable) {
         configureAllPins();
      }
   }

   /**
    * Destructor
    */
   virtual ~I2cBase_T() {}

   /**
    * Set channel Callback function\n
    * This callback is executed when the I2C state machine returns to the IDLE state
    * at the end of a transaction.
    *
    * @param[in] callback Callback function to execute on interrupt.\n
    *                     Use nullptr to remove callback.
    */
   static __attribute__((always_inline)) void setCallback(I2cCallbackFunction callback) {
      usbdm_assert(Info::irqHandlerInstalled, "I2C not configured for interrupts");
      if (callback == nullptr) {
         callback = I2c::unhandledCallback;
      }
      sCallback = callback;
   }

   /**
    * Set baud factor value for interface
    *
    * This is calculated from processor frequency and given bits-per-second
    *
    * @param[in]  bps Interface speed in bits-per-second
    */
   void setBPS(uint32_t bps) {
      I2c::setBPS(bps, Info::getInputClockFrequency());
   }

   /**
    * Initialise interface
    *
    * @param[in]  myAddress Address of self (not used)
    */
   void init(const uint8_t myAddress) {

      // Enable clock to I2C interface
      Info::clockReg() |= Info::clockMask;

      thisPtr = this;

      if (i2cMode&I2C_C1_IICIE_MASK) {
         NVIC_EnableIRQ(Info::irqNums[0]);
      }
      // Enable I2C peripheral
      i2c->C1 = I2C_C1_IICEN_MASK|i2cMode;

      // Default options
      i2c->C2  = I2C_C2_AD(myAddress>>8);
      i2c->A1  = myAddress&~1;
      i2c->FLT = I2C_FLT_FLT(2);
   }

   /**
    * Clear bus hang
    *
    * Generates I2C_SCL clock until I2C_SDA goes high\n
    * This is useful if a slave is part-way through a transaction when the master goes away!
    */
   virtual void busHangReset() {

      sclGpio::setOutput(Info::defaultPcrValue);
      sdaGpio::setInput(Info::defaultPcrValue);
      /*
       * Set SCL initially high before enabling to minimise disturbance to bus
       */
      for (int i=0; i<9; i++) {
         // Set clock high (ideally 3-state)
         sclGpio::high();
         for(int j=0; j<20; j++) {
            __asm__("nop");
         }
         // If data is high bus is OK
         if (sdaGpio::read()) {
            break;
         }
         // Set clock low
         sclGpio::low();
         for(int j=0; j<20; j++) {
            __asm__("nop");
         }
      }
   }

   static void irqHandler() {
      thisPtr->poll();
      if (thisPtr->state == I2C_State::i2c_idle) {
         sCallback();
      }
   }
};

template<class Info> I2cCallbackFunction I2cBase_T<Info>::sCallback = I2c::unhandledCallback;

/** Used by ISR to obtain handle of object */
template<class Info> I2c *I2cBase_T<Info>::thisPtr = 0;

#if defined(USBDM_I2C0_IS_DEFINED)
/**
 * @brief Class representing the I2C0 interface
 *
 * <b>Example</b>\n
 * Refer @ref I2cBase_T
 */
class I2c0 : public I2cBase_T<I2c0Info> {};
#endif

#if defined(USBDM_I2C1_IS_DEFINED)
/**
 * @brief Class representing the I2C1 interface
 *
 * <b>Example</b>
 * Refer @ref I2cBase_T
 */
class I2c1 : public I2cBase_T<I2c1Info> {};
#endif

#if defined(USBDM_I2C2_IS_DEFINED)
/**
 * @brief Class representing the I2C2 interface
 *
 * <b>Example</b>
 * Refer @ref I2cBase_T
 */
class I2c2 : public I2cBase_T<I2c2Info> {};
#endif

/**
 * End I2C_Group
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_I2C_H */
