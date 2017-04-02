/**
 * @file     spi.h
 * @brief    Serial Peripheral Interface (derived from spi-MK.h)
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef INCLUDE_USBDM_SPI_H_
#define INCLUDE_USBDM_SPI_H_
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

static constexpr uint32_t SPI_CPHA = SPI_CTAR_CPHA_MASK;     // Clock phase    - First edge on SPSCK occurs at the start of the first cycle of a data transfer
static constexpr uint32_t SPI_CPOL = SPI_CTAR_CPOL_MASK;     // Clock polarity - Active-low SPI clock (idles high)
static constexpr uint32_t SPI_LSBF = SPI_CTAR_LSBFE_MASK;    // LSB transmitted  first

static constexpr uint32_t SPI_MODE0 (0       |0);
static constexpr uint32_t SPI_MODE1 (0       |SPI_CPHA);
static constexpr uint32_t SPI_MODE2 (SPI_CPOL|0);
static constexpr uint32_t SPI_MODE3 (SPI_CPOL|SPI_CPHA);

/**
 * @addtogroup SPI_Group SPI, Serial Peripheral Interface
 * @brief C++ Class allowing access to SPI interface
 * @{
 */

/**
 * @brief Base class for representing an SPI interface
 */
class Spi {
protected:
   ~Spi() {}

protected:
   volatile  SPI_Type * const spi; //!< SPI hardware
   uint32_t  pushrMask;            //!< Value to combine with data

protected:
   /**
    * Constructor
    *
    * @param baseAddress    Base address of SPI
    */
   Spi(volatile SPI_Type *baseAddress) :
      spi(baseAddress), pushrMask(SPI_PUSHR_PCS_MASK) {
   }

public:
   /**
    * Calculate communication speed factors for SPI
    *
    * @param clockFrequency => Clock frequency of SPI in Hz
    * @param frequency      => Communication frequency in Hz
    *
    * @return CTAR register value including SPI_CTAR_BR, SPI_CTAR_PBR fields
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    */
   static uint32_t calculateDividers(uint32_t clockFrequency, uint32_t frequency);

   /**
    * Calculate communication speed from SPI clock frequency and speed factors
    *
    * @param clockFrequency => Clock frequency of SPI in Hz
    * @param clockFactors   => CTAR register value providing SPI_CTAR_BR, SPI_CTAR_PBR fields
    *
    * @return Clock frequency of SPI in Hz for these factors
    */
   static uint32_t calculateSpeed(uint32_t clockFrequency, uint32_t clockFactors);

protected:
   /**
    * Calculate Delay factors
    * Used for ASC, DT and CSSCK
    *
    * @param delay          => Desired delay in seconds
    * @param clockFrequency => Clock frequency of SPI in Hz
    * @param bestPrescale   => Best prescaler value (0=>/1, 1=>/3, 2=/5, 3=>/7)
    * @param bestDivider    => Best divider value (N=>/(2**(N+1)))
    *
    * @return true
    *
    * Note: Determines bestPrescaler and bestDivider for the smallest delay that is not less than delay.
    */
   static void calculateDelay(float clockFrequency, float delay, int &bestPrescale, int &bestDivider);

   /**
    * Calculate Delay factors for CSSCK (PCS assertion to SCK Delay Scaler)
    *
    * @param delay          => Desired delay in seconds
    * @param clockFrequency => Clock frequency of SPI in Hz
    *
    * @return Masks for CTAR register
    *
    * Note: Determines value for the smallest delay that is not less than delay.
    */
   static uint32_t calculateCSSCK(float clockFrequency, float delay) {
      int bestPrescale, bestDivider;
      calculateDelay(clockFrequency, delay, bestPrescale, bestDivider);
      return SPI_CTAR_PCSSCK(bestPrescale)|SPI_CTAR_CSSCK(bestDivider);
   }

   /**
    * Calculate Delay factors for ASC (SCK to PCS negation delay)
    *
    * @param delay          => Desired delay in seconds
    * @param clockFrequency => Clock frequency of SPI in Hz
    *
    * @return Masks for CTAR register
    *
    * Note: Determines value for the smallest delay that is not less than delay.
    */
   static uint32_t calculateASC(float clockFrequency, float delay) {
      int bestPrescale, bestDivider;
      calculateDelay(clockFrequency, delay, bestPrescale, bestDivider);
      return SPI_CTAR_PASC(bestPrescale)|SPI_CTAR_ASC(bestDivider);
   }

   /**
    * Calculate Delay factors for DT (PCS negation to PCS assertion delay between transfers)
    *
    * @param delay          => Desired delay in seconds
    * @param clockFrequency => Clock frequency of SPI in Hz
    *
    * @return Masks for CTAR register
    *
    * Note: Determines value for the smallest delay that is not less than delay.
    */
   static uint32_t calculateDT(float clockFrequency, float delay) {
      int bestPrescale, bestDivider;
      calculateDelay(clockFrequency, delay, bestPrescale, bestDivider);
      return SPI_CTAR_PDT(bestPrescale)|SPI_CTAR_DT(bestDivider);
   }

   /**
    * Calculates the CTAR value for a given set of communication delays for SPI
    *
    * @param clockFrequency => Clock frequency of SPI in Hz
    * @param cssck          => PCS assertion to SCK Delay Scaler
    * @param asc            => SCK to PCS negation delay
    * @param dt             => PCS negation to PCS assertion delay between transfers
    *
    * @return Masks for CTAR register
    *
    * Note: Determines values for the smallest delay that is not less than specified delays.
    */
   static uint32_t calculateDelays(uint32_t clockFrequency, float cssck=1*USBDM::us, float asc=1*USBDM::us, float dt=1*USBDM::us) {
      uint32_t ctarValue;
      ctarValue  = calculateASC(clockFrequency, asc);
      ctarValue |= calculateDT(clockFrequency, dt);
      ctarValue |= calculateCSSCK(clockFrequency, cssck);
      return ctarValue;
   }

   /**
    * Sets Communication speed for SPI
    *
    * @param frequency      => Communication frequency in Hz
    * @param clockFrequency => Clock frequency of SPI in Hz
    * @param ctarNum        => Index of CTAR register to modify
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    */
   void setSpeed(uint32_t clockFrequency, uint32_t frequency, int ctarNum) {
      spi->CTAR[ctarNum] = (spi->CTAR[ctarNum] & ~(SPI_CTAR_BR_MASK|SPI_CTAR_PBR_MASK)) |
            (calculateDividers(clockFrequency, frequency) & (SPI_CTAR_BR_MASK|SPI_CTAR_PBR_MASK));
   }

   /**
    * Sets the CTAR value for a given set of communication delays
    *
    * @param clockFrequency => Clock frequency of SPI in Hz
    * @param cssck          => PCS assertion to SCK Delay Scaler
    * @param asc            => SCK to PCS negation delay
    * @param dt             => PCS negation to PCS assertion delay between transfers
    * @param ctarNum        => Index of CTAR register to modify
    *
    * Note: Determines values for the smallest delay that is not less than specified delays.
    */
   void setDelays(uint32_t clockFrequency, float cssck, float asc, float dt, int ctarNum) {

      uint32_t ctarValue = spi->CTAR[ctarNum] &
            ~(SPI_CTAR_ASC_MASK|SPI_CTAR_PASC_MASK|SPI_CTAR_DT_MASK|SPI_CTAR_PDT_MASK|SPI_CTAR_CSSCK_MASK|SPI_CTAR_PCSSCK_MASK);
      spi->CTAR[ctarNum] = ctarValue|calculateDelays(clockFrequency, cssck, asc, dt);
   }

public:

#ifdef __CMSIS_RTOS
   /**
    * Obtain SPI mutex
    *
    * @param milliseconds How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus lock(int milliseconds=osWaitForever) = 0;

   /**
    * Release SPI mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus unlock() = 0;
#else
   int lock(int milliseconds=0) {};
   int unlock() {};
#endif

   /**
    * Enable pins used by SPI
    */
   virtual void enablePins() = 0;

   /**
    * Disable (restore to usual default) pins used by SPI
    */
   virtual void disablePins() = 0;

   /**
    * Sets the CTAR value for a given set of communication delays
    *
    * @param cssck          => PCS assertion to SCK Delay Scaler
    * @param asc            => SCK to PCS negation delay
    * @param dt             => PCS negation to PCS assertion delay between transfers
    * @param ctarNum        => Index of CTAR register to modify
    *
    * Note: Determines values for the smallest delay that is not less than specified delays.
    */
   virtual void setDelays(float cssck=1*USBDM::ms, float asc=1*USBDM::ms, float dt=1*USBDM::ms, int ctarNum=0) = 0;

   /**
    * Sets the CTAR value for a given communication speed
    *
    * @param frequency => Frequency in Hz (0 => use default value)
    * @param ctarNum   => Index of CTAR register to modify
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    * Note: This will only have effect the next time a CTAR is changed
    */
   virtual void setSpeed(uint32_t frequency, int ctarNum=0) = 0;

   /**
    * Sets Communication mode for SPI
    *
    * @param mode    => Mode to set. Combination of SPI_CPHA, SPI_CPOL and SPI_LSBFE
    * @param ctarNum => Index of CTAR register to modify
    */
   void setMode(uint32_t mode, int ctarNum=0) {
      // Sets the default CTAR value with 8 bits
      spi->CTAR[ctarNum] = (spi->CTAR[ctarNum]&~(SPI_CPHA|SPI_CPOL|SPI_LSBF)) |
            (mode & (SPI_CPHA|SPI_CPOL|SPI_LSBF));
   }

   /**
    * Sets Communication mode for SPI
    *
    * @param numBits => Number of bits in each transfer
    * @param ctarNum => Index of CTAR register to modify
    */
   void setFrameSize(int numBits=8, int ctarNum=0) {
      // Sets the frame size in CTAR
      spi->CTAR[ctarNum] = (spi->CTAR[ctarNum]&~(SPI_CTAR_FMSZ_MASK)) |
            SPI_CTAR_FMSZ(numBits-1);
   }
   /**
    * Set value that is combined with data for PUSHR register
    * For example this may be used to control which CTAR is used or which SPI_PCSx signal is asserted
    *
    * @param pushrMask Value to combine with Tx data before writing to PUSHR register
    *                  For example, SPI_PUSHR_CTAS(1)|SPI_PUSHR_PCS(1<<2)
    */
   void setPushrValue(uint32_t pushrMask) {
      this->pushrMask = pushrMask;
   }
   /**
    *  Transmit and receive a series of bytes
    *
    *  @param dataSize  Number of bytes to transfer
    *  @param dataOut   Transmit bytes (may be NULL for Rx only)
    *  @param dataIn    Receive byte buffer (may be NULL for Tx only)
    *
    *  Note: dataIn may use same buffer as dataOut
    */
   void txRxBytes(uint32_t dataSize, const uint8_t *dataOut, uint8_t *dataIn=0);

   /**
    *  Transmit and receive a series of 16-bit values
    *
    *  @param dataSize  Number of values to transfer
    *  @param dataOut   Transmit values (may be NULL for Rx only)
    *  @param dataIn    Receive buffer (may be NULL for Tx only)
    */
   void txRxWords(uint32_t dataSize, const uint16_t *dataOut, uint16_t *dataIn=0);

   /**
    * Transmit and receive a value over SPI
    *
    * @param data - Data to send (8-16 bits) <br>
    *               May include other control bits
    *
    * @return Data received
    */
   uint32_t txRx(uint32_t data);

   /** Set SPI.CTAR0 value
    *
    * @param ctar 32-bit CTAR value
    */
   void setCTAR0Value(uint32_t ctar) {
      spi->CTAR[0] = ctar;
   }

   /** Set SPI.CTAR1 value
    *
    * @param ctar 32-bit CTAR value
    */
   void setCTAR1Value(uint32_t ctar) {
      spi->CTAR[1] = ctar;
   }

   /** Get SPI.CTAR0 value
    *
    * @return ctar 32-bit CTAR value
    */
   uint32_t getCTAR0Value() {
      return spi->CTAR[0];
   }

   /** Get SPI.CTAR1 value
    *
    * @return ctar 32-bit CTAR value
    */
   uint32_t getCTAR1Value() {
      return spi->CTAR[1];
   }

   /**
    * Set polarity of hardware PCS signals
    *
    * @param signal     Signal number
    * @param activeHigh Bit-mask for polarity of PCSn true=>active high, false=>active low
    */
   void setPcsPolarity(int signal, bool activeHigh=true) {
      if (activeHigh) {
         spi->MCR &= ~SPI_MCR_PCSIS(1<<signal);
      }
      else {
         spi->MCR |= SPI_MCR_PCSIS(1<<signal);
      }
   }
};

/**
 * @brief Template class representing a SPI interface
 *
 * @tparam  Info           Class describing Spi hardware
 */
template<class Info>
class Spi_T : public Spi {

#ifdef __CMSIS_RTOS
protected:
   /** Mutex to protect access - static so per SPI */
   static CMSIS::Mutex mutex;

public:
   /**
    * Obtain SPI mutex
    *
    * @param milliseconds How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus lock(int milliseconds=osWaitForever) {
      return mutex.wait(milliseconds);
   }

   /**
    * Release SPI mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus unlock() {
      return mutex.release();
   }
#endif

public:
   virtual ~Spi_T() {}

   virtual void enablePins() {
      // Configure SPI pins
      Info::initPCRs(PORT_PCR_DSE(1)|PORT_PCR_SRE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(1));
   }

   virtual void disablePins() {
      // Configure SPI pins to mux=0
      Info::clearPCRs();
   }

   /**
    * Sets Communication speed for SPI
    *
    * @param frequency      => Frequency in Hz (0 => use default value)
    * @param ctarNum        => Index of CTAR register to modify
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    */
   virtual void setSpeed(uint32_t frequency, int ctarNum=0) {
      Spi::setSpeed(Info::getClockFrequency(), frequency, ctarNum);
   }

   /**
    * Sets the CTAR value for a given set of communication delays
    *
    * @param cssck          => PCS assertion to SCK Delay Scaler
    * @param asc            => SCK to PCS negation delay
    * @param dt             => PCS negation to PCS assertion delay between transfers
    * @param ctarNum        => Index of CTAR register to modify
    *
    * Note: Determines values for the smallest delay that is not less than specified delays.
    */
   void setDelays(float cssck=10*USBDM::us, float asc=10*USBDM::us, float dt=10*USBDM::us, int ctarNum=0) {
      Spi::setDelays(Info::getClockFrequency(), cssck, asc, dt, ctarNum);
   }

   /**
    * Constructor
    */
   Spi_T() : Spi(reinterpret_cast<volatile SPI_Type*>(Info::spi)) {

#ifdef DEBUG_BUILD
      // Check pin assignments
      static_assert(Info::info[0].gpioBit != UNMAPPED_PCR, "SPIx_SCK has not been assigned to a pin");
      static_assert(Info::info[1].gpioBit != UNMAPPED_PCR, "SPIx_SIN has not been assigned to a pin");
      static_assert(Info::info[2].gpioBit != UNMAPPED_PCR, "SPIx_SOUT has not been assigned to a pin");
#endif

      // Enable SPI module clock
      *Info::clockReg |= Info::clockMask;
      __DMB();

      spi->MCR = SPI_MCR_HALT_MASK|SPI_MCR_CLR_RXF_MASK|SPI_MCR_ROOE_MASK|SPI_MCR_CLR_TXF_MASK|
            SPI_MCR_MSTR_MASK|SPI_MCR_DCONF(0)|SPI_MCR_SMPL_PT(0)|SPI_MCR_PCSIS_MASK;

      setCTAR0Value(0); // Clear
      setCTAR1Value(0); // Clear
      setFrameSize(8);          // Default 8-bit transfers
      setSpeed(Info::speed);    // Use default speed
      setMode(Info::modeValue); // Use default mode
      setDelays();      // Defaults

      // Configure SPI pins
      enablePins();
   }

};

#ifdef __CMSIS_RTOS
/** Mutex to protect access - static so per SPI */
template<class Info>
CMSIS::Mutex Spi_T<Info>::mutex;
#endif

#if defined(USBDM_SPI0_IS_DEFINED)
/**
 * @brief Template class representing a SPI0 interface
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi0();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 */
using Spi0 = Spi_T<Spi0Info>;
#endif

#if defined(USBDM_SPI1_IS_DEFINED)
/**
 * @brief Template class representing a SPI1 interface
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi1();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 */
using  Spi1 = Spi_T<Spi1Info>;
#endif
/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_SPI_H_ */
