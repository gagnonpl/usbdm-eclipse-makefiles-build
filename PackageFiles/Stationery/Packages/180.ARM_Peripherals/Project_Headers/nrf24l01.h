/*
 * @file nrf24l01.h
 * @brief Interface for nRF24L01 wireless module
 *
 * @version  V4.12.1.50
 * @date     18 June 2015
 */

#ifndef INCLUDE_NRF24L01_H
#define INCLUDE_NRF24L01_H

#include <string.h>
#include "spi.h"

namespace USBDM {

/**
 * @addtogroup NRF24L01_Group nrf24l01 Wireless Interface
 * @brief C++ Class providing interface to nrf24l01 wireless modules
 * @{
 */

/**
 * Base class for nRF24L01 Wireless module
 */
class NRF24L01 {
public:
   enum RegisterAddresses {
      CONFIG_REG        = 0x00,  // See masks below
      EN_AA_REG         = 0x01,  // Enable auto acknowledgement data pipe n
      EN_RXADDR_REG     = 0x02,  // Enabled RX Addresses, Enable data pipe n
      SETUP_AW_REG      = 0x03,  // Setup of Address Widths (common for all data pipes)
      SETUP_RETR_REG    = 0x04,  // Setup of Automatic Retransmission
      RF_CH_REG         = 0x05,  // RF Channel
      RF_SETUP_REG      = 0x06,  // RF Setup Register
      STATUS_REG        = 0x07,  // Status Register. In parallel to the SPI command word applied on the MOSI pin,
      //                            the STATUS register is shifted serially out on the MISO pin.
      OBSERVE_TX_REG    = 0x08,  // Transmit observe register
      RPD_REG           = 0x09,  // Receive power detector
      RX_ADDR_P0_REG    = 0x0A,  // Receive address for data pipes 0-1. 5 Bytes maximum length.
      RX_ADDR_P1_REG    = 0x0B,  // LSByte is written first. Write the number of bytes defined by SETUP_AW
      RX_ADDR_P2_REG    = 0x0C,  // Receive address for data pipes 2-5. 1 Byte only.
      RX_ADDR_P3_REG    = 0x0D,  // LSByte only, MSBytes common with RX_ADDR_P1
      RX_ADDR_P4_REG    = 0x0E,  //  " "
      RX_ADDR_P5_REG    = 0x0F,  //  " "
      TX_ADDR_REG       = 0x10,  //  Transmit address. Used for a PTX device only. (LSByte is written first)
      //                             Set RX_ADDR_P0 equal to this address to handle automatic acknowledge if this is
      //                             a PTX device with Enhanced ShockBurst(TM) enabled.
      RX_PW_P0_REG      = 0x11,  //  Number of bytes in RX pay-load in data pipes 0-5 (1 to 32 bytes).
      RX_PW_P1_REG      = 0x12,  //  0: Pipe not used, 1-32: 1-32 bytes
      RX_PW_P2_REG      = 0x13,  //  " "
      RX_PW_P3_REG      = 0x14,  //  " "
      RX_PW_P4_REG      = 0x15,  //  " "
      RX_PW_P5_REG      = 0x16,  //  " "
      FIFO_STATUS_REG   = 0x17,  //  FIFO Status Register
      DYNPD_REG         = 0x1C,  //  Enable dynamic pay-load length
      FEATURE_REG       = 0x1D,  //
   };

   // CONFIG register masks
   static constexpr uint8_t CONFIG_MASK_RX_DR  =  (1<<6);  // Mask interrupt caused by RX_DR
   //                                                         1: Interrupt not reflected on the IRQ pin
   //                                                         0: Reflect RX_DR as active low interrupt on the IRQ pin
   static constexpr uint8_t CONFIG_MASK_TX_DS  =  (1<<5);  // Mask interrupt caused by TX_DS
   //                                                         1: Interrupt not reflected on the IRQ pin
   //                                                         0: Reflect TX_DS as active low interrupt on the IRQ pin
   static constexpr uint8_t CONFIG_MASK_MAX_RT =  (1<<4);  // Mask interrupt caused by MAX_RT
   //                                                         1: Interrupt not reflected on the IRQ pin
   //                                                         0: Reflect MAX_RT as active low interrupt on the IRQ pin
   static constexpr uint8_t CONFIG_EN_CRC      =  (1<<3);  // Enable CRC. Forced high if one of the bits in the EN_AA is high
   static constexpr uint8_t CONFIG_CRCO        =  (1<<2);  // CRC encoding scheme 0: 1 byte, 1: 2 bytes
   static constexpr uint8_t CONFIG_PWR_UP      =  (1<<1);  // Power control 1: POWER UP, 0:POWER DOWN
   static constexpr uint8_t CONFIG_PRIM_RX     =  (1<<0);  // RX/TX control 1: PRX, 0: PTX

   // EN_AA register masks
   static constexpr uint8_t EN_AA_P0           =  (1<<0);  // Enable auto acknowledgement data pipe n
   static constexpr uint8_t EN_AA_P1           =  (1<<1);  // " "
   static constexpr uint8_t EN_AA_P2           =  (1<<2);  // " "
   static constexpr uint8_t EN_AA_P3           =  (1<<3);  // " "
   static constexpr uint8_t EN_AA_P4           =  (1<<4);  // " "
   static constexpr uint8_t EN_AA_P5           =  (1<<5);  // " "

   // EN_AA register masks
   static constexpr uint8_t EN_RXADDR_P0       =  (1<<0);  // Enable data pipe n
   static constexpr uint8_t EN_RXADDR_P1       =  (1<<1);  // " "
   static constexpr uint8_t EN_RXADDR_P2       =  (1<<2);  // " "
   static constexpr uint8_t EN_RXADDR_P3       =  (1<<3);  // " "
   static constexpr uint8_t EN_RXADDR_P4       =  (1<<4);  // " "
   static constexpr uint8_t EN_RXADDR_P5       =  (1<<5);  // " "

   // SETUP_AW register masks
   static constexpr uint8_t SETUP_AW_3_BYTES   = (1);
   static constexpr uint8_t SETUP_AW_4_BYTES   = (2);
   static constexpr uint8_t SETUP_AW_5_BYTES   = (3);

   /**
    * SETUP_RETR register masks
    */
   constexpr static uint8_t SETUP_RETR(uint8_t ard, uint8_t arc) {
      return (uint8_t)(((ard)&0xF)<<4)|(((arc)&0xF)<<0);
   }
   /**
    *  Auto Retransmit delay in 250us steps (250-4000us)
    */
   constexpr static uint8_t SETUP_RETR_ARD(uint8_t x) {
      return (((x)&0xF)<<4);
   }
   /**
    * Auto Retransmit Count 0-15 retransmits (0 disables)
    */
   constexpr static uint8_t SETUP_RETR_ARC(uint8_t x) {
      return (((x)&0xF)<<0);
   }
   /** RF_CH register masks */
   /**
    * Sets the frequency channel nRF24L01+ operates on
    */
   constexpr static uint8_t RF_CH_CH(uint8_t x) {
      return (((x)&0x7F)<<0);
   }

   // RF_SETUP register masks
   static constexpr uint8_t RF_SETUP_CONT_WAVE      =  (1<<7);   // Enables continuous carrier transmit when high
   static constexpr uint8_t RF_SETUP_RF_DR_LOW      =  (1<<5);   // Set RF Data Rate to 250kbps. See RF_DR_HIGH for encoding.
   static constexpr uint8_t RF_SETUP_PLL_LOCK       =  (1<<4);   // Force PLL lock signal. Only used in test
   static constexpr uint8_t RF_SETUP_RF_DR_HIGH     =  (1<<3);   // Select between the high speed data rates. This bit is don't care if RF_DR_LOW is set.
   static constexpr uint8_t RF_SETUP_RF_DR_1Mbps    =  (0);                     // 1 Mbps
   static constexpr uint8_t RF_SETUP_RF_DR_2Mbps    =  (RF_SETUP_RF_DR_HIGH);   // 2 Mbps
   static constexpr uint8_t RF_SETUP_RF_DR_250kbps  =  (RF_SETUP_RF_DR_LOW);    // 250 kbps
   static constexpr uint8_t RF_SETUP_PWR_minus18dBm =  (0<<1);    // -18dBm
   static constexpr uint8_t RF_SETUP_PWR_minus12dBm =  (1<<1);    // -11dBm
   static constexpr uint8_t RF_SETUP_PWR_minus6dBm  =  (2<<1);    //  -6dBm
   static constexpr uint8_t RF_SETUP_PWR_0dBm       =  (3<<1);    //   0dBm

   // STATUS register masks
   static constexpr uint8_t STATUS_RX_DR      =  (1<<6); // Data Ready RX FIFO interrupt. Asserted when new data arrives RX FIFOc. Write 1 to clear bit.
   static constexpr uint8_t STATUS_TX_DS      =  (1<<5); // Data Sent TX FIFO interrupt. Asserted when packet transmitted on TX.
   //                                                   If AUTO_ACK is activated, this bit is set high only when ACK is received. Write 1 to clear bit.
   static constexpr uint8_t STATUS_MAX_RT     =  (1<<4); // Maximum number of TX retransmits interrupt. Write 1 to clear bit.
   //                                                   If MAX_RT is asserted it must be cleared to enable further communication.
   /*
    *  Data pipe number for the payload available for reading from RX_FIFO.
    */
   static constexpr uint8_t STATUS_RX_P_NO(uint8_t x) {
      return (((x)>>1)&0x7);
   }
   //                                           000-101: Data Pipe Number
   //                                           110: Not Used
   //                                           111: RX FIFO Empty
   static constexpr uint8_t STATUS_TX_FULL    =  (1<<0); // TX FIFO full flag. 1: TX FIFO full. 0: Available locations in TX FIFO.

   // OBSERVE_TX register masks
   /**
    *  Count lost packets. The counter sticks at 15. The counter is reset by writing to RF_CH.
    */
   static constexpr uint8_t OBSERVE_TX_PLOS_CNT(uint8_t x) {
      return (((x)>>4)&0x0F);
   }

   /**
    * Count retransmitted packets. The counter is reset when transmission of a new packet starts.
    */
   static constexpr uint8_t OBSERVE_TX_ARC_CNT(uint8_t x) {
      return (((x)>>0)&0x0F);
   }

   // RPD register masks
   static constexpr uint8_t RPD_RPD  =  (1<<0); // Received Power Detector. This register is called CD (Carrier Detect) in the nRF24L01.

   // FIFO_STATUS register masks
   static constexpr uint8_t FIFO_STATUS_TX_REUSE  =  (1<<6); // Used for a PTX device. Pulse the rfce high for at least 10us to reuse last transmitted pay-load.
   //                                                           TX pay-load reuse is active until W_TX_PAYLOAD or FLUSH TX is executed.
   //                                                           TX_REUSE is set by the SPI command REUSE_TX_PL, and is reset by the SPI commands W_TX_PAYLOAD or FLUSH TX
   static constexpr uint8_t FIFO_STATUS_TX_FULL   =  (1<<5); // TX FIFO full flag. 1: TX FIFO full. 0: Available locations in TX FIFO.
   static constexpr uint8_t FIFO_STATUS_TX_EMPTY  =  (1<<4); // TX FIFO empty flag. 1: TX FIFO empty. 0: Data in TX FIFO.
   static constexpr uint8_t FIFO_STATUS_RX_FULL   =  (1<<1); // RX FIFO full flag. 1: RX FIFO full. 0: Available locations in RX FIFO.
   static constexpr uint8_t FIFO_STATUS_RX_EMPTY  =  (1<<0); // RX FIFO empty flag. 1: RX FIFO empty. 0: Data in RX FIFO.

   // DYNPD register masks
   static constexpr uint8_t DYNPD_P0 =  (1<<0); // Enable dynamic pay-load length data pipe n. (Requires EN_DPL and ENAA_P5)
   static constexpr uint8_t DYNPD_P1 =  (1<<1); // " "
   static constexpr uint8_t DYNPD_P2 =  (1<<2); // " "
   static constexpr uint8_t DYNPD_P3 =  (1<<3); // " "
   static constexpr uint8_t DYNPD_P4 =  (1<<4); // " "
   static constexpr uint8_t DYNPD_P5 =  (1<<5); // " "

   // FEATURE register masks
   static constexpr uint8_t FEATURE_EN_DPL     =  (1<<2);  // Enables Dynamic Payload Length
   static constexpr uint8_t FEATURE_EN_ACK_PAY =  (1<<1);  // Enables Payload with ACK
   static constexpr uint8_t FEATURE_EN_DYN_ACK =  (1<<0);  // Enables the W_TX_PAYLOAD_NOACK command

public:
   /**
    * Data for NRF configuration
    */
   struct NRFData {
      uint8_t config;
      uint8_t en_aa;
      uint8_t en_rxaddr;
      uint8_t setup_aw;
      uint8_t setup_retr;
      uint8_t rf_ch;
      uint8_t rf_setup;
      uint8_t rx_addr_p0[5];
      uint8_t rx_addr_p1[5];
      uint8_t rx_addr_p2;
      uint8_t rx_addr_p3;
      uint8_t rx_addr_p4;
      uint8_t rx_addr_p5;
      uint8_t tx_addr[5];
      uint8_t rx_pw_p0;
      uint8_t rx_pw_p1;
      uint8_t rx_pw_p2;
      uint8_t rx_pw_p3;
      uint8_t rx_pw_p4;
      uint8_t rx_pw_p5;
      uint8_t dynpd;
      uint8_t feature;
   };
   /**
    * Data for NRF default configuration
    */
   static const NRFData DEFAULT_CONFIGURATION;

protected:
   Spi           *spi;        //! SPI interface to use
   const NRFData *configData; //! Configuration

   /**
    * Create NRF24L01 interface
    *
    * @param spi        SPI interface to use - Note: It is assumes that PCS signal has been assigned
    * @param configData Configuration to use.
    */
   NRF24L01(Spi *spi, const NRFData *configData) : spi(spi), configData(configData) {
   }
   /**
    * Initialise NRF24L01 based on configData data
    */
   void init();
   /**
    * Set CE signal high/low
    *
    * @param value true=>enable, false=>disable
    */
   virtual void setCE(bool value) = 0;
   /**
    * Get IRQ signal state
    *
    * @return true => IRQ asserted
    */
   virtual bool getIRQn(void) = 0;

public:
   /**
    * Read status register
    *
    * @return status register value
    */
   uint8_t getStatus(void);
   /**
    * Write command
    *
    * @param command  - Command number e.g. R_REGISTER etc
    * @param dataSize - Size of data in bytes
    * @param data     - Data to write
    *
    * @return status register value
    */
   uint8_t writeCommand(uint8_t command, unsigned dataSize, const uint8_t data[]);
   /**
    * Read command
    *
    * @param command  - Command number e.g. W_REGISTER etc
    * @param dataSize - Size of data in bytes
    * @param data     - Pointer to buffer for data read (may be NULL)
    *
    * @return status register value
    */
   uint8_t readCommand(uint8_t command, unsigned dataSize, uint8_t data[]);
   /**
    * Write data to register
    *
    * @param regNum   - Register number e.g. CONFIG_REG
    * @param dataSize - Size of data in bytes
    * @param data     - Data to write
    *
    * @return status register value
    */
   uint8_t writeRegister(uint8_t regNum, unsigned dataSize, const uint8_t data[]);
   /**
    * Read data from register
    *
    * @param regNum   - Register number e.g. CONFIG_REG
    * @param dataSize - Size of data in bytes
    * @param data     - Pointer to buffer for data read (may be NULL)
    *
    * @return status register value
    */
   uint8_t readRegister(uint8_t regNum, unsigned dataSize, uint8_t data[]);
   /**
    * Write value to CONFIG register
    *
    * @param value - Value to write
    *
    * @return status register value
    */
   uint8_t writeConfig(uint8_t value);
   /**
    * Read value from CONFIG register
    *
    * @return Value from register
    */
   uint8_t readConfig(void);
   /**
    * Power down device
    *
    * This clears the PWR_UP bit in the CONFIG register (if necessary)
    */
   void powerDown(void);
   /**
    * Change configuration and power up device
    *
    * @param configValue value for NRF24L01 config register (see CONFIG_EN_CRC etc)
    *
    * This sets the PWR_UP bit in the CONFIG register if necessary
    * The CE is set active if RX mode is indicated by CONFIG_PRIM_RX bit
    */
   void powerUp(uint8_t configValue);
   /**
    * Power up device with the current configuration
    *
    * This sets the PWR_UP bit in the CONFIG register if necessary
    * The CE is set active if RX mode is indicated by CONFIG_PRIM_RX bit
    */
   void powerUp();
   /**
    * Flush Tx Buffer
    *
    * @return status register value
    */
   uint8_t flushTx(void);
   /**
    * Flush Rx Buffer
    *
    * @return status register value
    */
   uint8_t flushRx(void);
   /**
    * Transmit packet
    *
    * @param dataSize - Size of packet in bytes (should match what Rx pipe is expecting)
    * @param data     - Data to Tx
    *
    * @return status register value
    */
   uint8_t transmitData(unsigned dataSize, uint8_t data[]);
   /**
    * Receive packet
    *
    * @param dataSize - Size of packet in bytes (should match what Rx pipe is expecting)
    * @param data     - Data received
    *
    *
    * @return status register value
    */
   uint8_t receiveData(unsigned dataSize, uint8_t data[]);
};

/**
 * Template class for nRF24L01 Wireless module
 *
 * @code
 *    USBDM::Spi *spi = new USBDM::Spi0_T<USBDM::spi0_PCS1>();
 *    USBDM::NRF24L01 *nrf24l01 = new USBDM::NRF24L01_T<USBDM::GpioC<11>, USBDM::GpioD<0>>(spi);
 *
 *    for (;;) {
 *       uint8_t txData[] = {1,2,3,4};
 *       uint8_t rxData[100];
 *       nrf24l01->transmitData(sizeof(txData), txData);
 *       uint8_t status = nrf24l01->getStatus();
 *       if ((status & USBDM::NRF24L01::FIFO_STATUS_RX_FULL) != 0) {
 *          nrf24l01->receiveData(sizeof(rxData), rxData);
 *       }
 *    }
 * @endcode
 *
 * @tparam CeReg_n Chip Enable Gpio for nRF24L01
 * @tparam IrqReg  Irq Gpio input for nRF24L01
 */
template<typename CeReg_n, typename IrqReg>
class NRF24L01_T : public NRF24L01 {

public:
   /**
    * Create NRF24L01 interface
    *
    * @param spi        SPI interface to use - Note: It is assumes that PCS signal has been assigned
    * @param configData Configuration to use.
    */
   NRF24L01_T(Spi *spi, const NRFData *configData=&DEFAULT_CONFIGURATION) : NRF24L01(spi, configData) {

      // CE pin
      CeReg_n::setOutput();
      CeReg_n::clear();

      // IRQn pin
      IrqReg::setInput();

      init();
   }

private:
   /**
    * Set CE signal high/low
    *
    * @param value true=>enable, false=>disable
    */
   void setCE(bool value) {
      CeReg_n::write(value);
   }

   /**
    * Get IRQ signal state
    *
    * @return true => IRQ asserted
    */
   bool getIRQn(void) {
      return IrqReg::read();
   }
};

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_NRF24L01_H */
