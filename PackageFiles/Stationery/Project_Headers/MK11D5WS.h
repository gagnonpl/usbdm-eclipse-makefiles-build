/****************************************************************************************************//**
 * @file     MK11D5WS.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MK11D5WS.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2017/05
 *
 *******************************************************************************************************/

#ifndef MCU_MK11D5WS
#define MCU_MK11D5WS

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
* @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers
* @brief Vector numbers required for NVIC functions
* @{
*/
/* -------------------------  Interrupt Number Definition  ------------------------ */

/**
 * Interrupt vector numbers
 */
typedef enum {
/* ------------------------  Processor Exceptions Numbers  ------------------------- */
  Reset_IRQn                    = -15,   /**<   1 Reset Vector, invoked on Power up and warm reset                                 */
  NonMaskableInt_IRQn           = -14,   /**<   2 Non maskable Interrupt, cannot be stopped or preempted                           */
  HardFault_IRQn                = -13,   /**<   3 Hard Fault, all classes of Fault                                                 */
  MemoryManagement_IRQn         = -12,   /**<   4 Memory Management, MPU mismatch, including Access Violation and No Match         */
  BusFault_IRQn                 = -11,   /**<   5 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
  UsageFault_IRQn               = -10,   /**<   6 Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
  SVCall_IRQn                   =  -5,   /**<  11 System Service Call via SVC instruction                                          */
  DebugMonitor_IRQn             =  -4,   /**<  12 Debug Monitor                                                                    */
  PendSV_IRQn                   =  -2,   /**<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /**<  15 System Tick Timer                                                                */
/* ----------------------   MK11D5WS VectorTable                     ---------------------- */
  DMA0_IRQn                     =   0,   /**<  16 Direct memory access controller                                                  */
  DMA1_IRQn                     =   1,   /**<  17 Direct memory access controller                                                  */
  DMA2_IRQn                     =   2,   /**<  18 Direct memory access controller                                                  */
  DMA3_IRQn                     =   3,   /**<  19 Direct memory access controller                                                  */
  DMA4_IRQn                     =   4,   /**<  20 Direct memory access controller                                                  */
  DMA5_IRQn                     =   5,   /**<  21 Direct memory access controller                                                  */
  DMA6_IRQn                     =   6,   /**<  22 Direct memory access controller                                                  */
  DMA7_IRQn                     =   7,   /**<  23 Direct memory access controller                                                  */
  DMA8_IRQn                     =   8,   /**<  24 Direct memory access controller                                                  */
  DMA9_IRQn                     =   9,   /**<  25 Direct memory access controller                                                  */
  DMA10_IRQn                    =  10,   /**<  26 Direct memory access controller                                                  */
  DMA11_IRQn                    =  11,   /**<  27 Direct memory access controller                                                  */
  DMA12_IRQn                    =  12,   /**<  28 Direct memory access controller                                                  */
  DMA13_IRQn                    =  13,   /**<  29 Direct memory access controller                                                  */
  DMA14_IRQn                    =  14,   /**<  30 Direct memory access controller                                                  */
  DMA15_IRQn                    =  15,   /**<  31 Direct memory access controller                                                  */
  DMA_Error_IRQn                =  16,   /**<  32 DMA error interrupt all channels                                                 */
  MCM_IRQn                      =  17,   /**<  33 Miscellaneous Control Module                                                     */
  FTF_Command_IRQn              =  18,   /**<  34 Flash Memory Interface                                                           */
  FTF_ReadCollision_IRQn        =  19,   /**<  35 Flash Memory Interface                                                           */
  PMC_IRQn                      =  20,   /**<  36 Power Management Controller                                                      */
  LLWU_IRQn                     =  21,   /**<  37 Low Leakage Wakeup                                                               */
  WDOG_IRQn                     =  22,   /**<  38 External Watchdog Monitor                                                        */
  RNG_IRQn                      =  23,   /**<  39 Random Number Generator                                                          */
  I2C0_IRQn                     =  24,   /**<  40 Inter-Integrated Circuit                                                         */
  I2C1_IRQn                     =  25,   /**<  41 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  26,   /**<  42 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =  27,   /**<  43 Serial Peripheral Interface                                                      */
  I2S0_Tx_IRQn                  =  28,   /**<  44 Synchronous Serial Interface                                                     */
  I2S0_Rx_IRQn                  =  29,   /**<  45 Synchronous Serial Interface                                                     */
  UART0_LON_IRQn                =  30,   /**<  46 Serial Communication Interface                                                   */
  UART0_RX_TX_IRQn              =  31,   /**<  47 Serial Communication Interface                                                   */
  UART0_ERR_IRQn                =  32,   /**<  48 Serial Communication Interface                                                   */
  UART1_RX_TX_IRQn              =  33,   /**<  49 Serial Communication Interface                                                   */
  UART1_ERR_IRQn                =  34,   /**<  50 Serial Communication Interface                                                   */
  UART2_RX_TX_IRQn              =  35,   /**<  51 Serial Communication Interface                                                   */
  UART2_ERR_IRQn                =  36,   /**<  52 Serial Communication Interface                                                   */
  UART3_RX_TX_IRQn              =  37,   /**<  53 Serial Communication Interface                                                   */
  UART3_ERR_IRQn                =  38,   /**<  54 Serial Communication Interface                                                   */
  ADC0_IRQn                     =  39,   /**<  55 Analogue to Digital Converter                                                    */
  CMP0_IRQn                     =  40,   /**<  56 High-Speed Comparator                                                            */
  CMP1_IRQn                     =  41,   /**<  57 High-Speed Comparator                                                            */
  FTM0_IRQn                     =  42,   /**<  58 FlexTimer Module                                                                 */
  FTM1_IRQn                     =  43,   /**<  59 FlexTimer Module                                                                 */
  FTM2_IRQn                     =  44,   /**<  60 FlexTimer Module                                                                 */
  CMT_IRQn                      =  45,   /**<  61 Carrier Modulator Transmitter                                                    */
  RTC_Alarm_IRQn                =  46,   /**<  62 Real Time Clock                                                                  */
  RTC_Seconds_IRQn              =  47,   /**<  63 Real Time Clock                                                                  */
  PIT0_IRQn                     =  48,   /**<  64 Periodic Interrupt Timer                                                         */
  PIT1_IRQn                     =  49,   /**<  65 Periodic Interrupt Timer                                                         */
  PIT2_IRQn                     =  50,   /**<  66 Periodic Interrupt Timer                                                         */
  PIT3_IRQn                     =  51,   /**<  67 Periodic Interrupt Timer                                                         */
  PDB0_IRQn                     =  52,   /**<  68 Programmable Delay Block                                                         */
  Tamper_IRQn                   =  55,   /**<  71 Tamper Detect and Secure Key Storage                                             */
  DAC0_IRQn                     =  56,   /**<  72 Digital to Analogue Converter                                                    */
  MCG_IRQn                      =  57,   /**<  73 Multipurpose Clock Generator                                                     */
  LPTMR0_IRQn                   =  58,   /**<  74 Low Power Timer                                                                  */
  PORTA_IRQn                    =  59,   /**<  75 General Purpose Input/Output                                                     */
  PORTB_IRQn                    =  60,   /**<  76 General Purpose Input/Output                                                     */
  PORTC_IRQn                    =  61,   /**<  77 General Purpose Input/Output                                                     */
  PORTD_IRQn                    =  62,   /**<  78 General Purpose Input/Output                                                     */
  PORTE_IRQn                    =  63,   /**<  79 General Purpose Input/Output                                                     */
  SWI_IRQn                      =  64,   /**<  80 Software interrupt                                                               */
} IRQn_Type;

/**
 * @} */ /* End group Interrupt_vector_numbers_GROUP 
 */
/**
* @addtogroup Interrupt_handler_prototypes_GROUP Interrupt handler prototypes
* @brief Prototypes for interrupt handlers
* @{
*/
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                 /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);           /**< Hard Fault, all classes of Fault                                                 */
extern void MemManage_Handler(void);           /**< Memory Management, MPU mismatch, including Access Violation and No Match         */
extern void BusFault_Handler(void);            /**< Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
extern void UsageFault_Handler(void);          /**< Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
extern void SVC_Handler(void);                 /**< System Service Call via SVC instruction                                          */
extern void DebugMon_Handler(void);            /**< Debug Monitor                                                                    */
extern void PendSV_Handler(void);              /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);             /**< System Tick Timer                                                                */
extern void DMA0_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA1_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA2_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA3_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA4_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA5_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA6_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA7_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA8_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA9_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA10_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA11_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA12_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA13_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA14_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA15_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA_Error_IRQHandler(void);        /**< DMA error interrupt all channels                                                 */
extern void MCM_IRQHandler(void);              /**< Miscellaneous Control Module                                                     */
extern void FTF_Command_IRQHandler(void);      /**< Flash Memory Interface                                                           */
extern void FTF_ReadCollision_IRQHandler(void);   /**< Flash Memory Interface                                                           */
extern void PMC_IRQHandler(void);              /**< Power Management Controller                                                      */
extern void LLWU_IRQHandler(void);             /**< Low Leakage Wakeup                                                               */
extern void WDOG_IRQHandler(void);             /**< External Watchdog Monitor                                                        */
extern void RNG_IRQHandler(void);              /**< Random Number Generator                                                          */
extern void I2C0_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void I2C1_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void I2S0_Tx_IRQHandler(void);          /**< Synchronous Serial Interface                                                     */
extern void I2S0_Rx_IRQHandler(void);          /**< Synchronous Serial Interface                                                     */
extern void UART0_LON_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART0_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART0_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART1_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART1_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART2_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART2_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART3_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART3_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void ADC0_IRQHandler(void);             /**< Analogue to Digital Converter                                                    */
extern void CMP0_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void CMP1_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void FTM0_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void FTM1_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void FTM2_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void CMT_IRQHandler(void);              /**< Carrier Modulator Transmitter                                                    */
extern void RTC_Alarm_IRQHandler(void);        /**< Real Time Clock                                                                  */
extern void RTC_Seconds_IRQHandler(void);      /**< Real Time Clock                                                                  */
extern void PIT0_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT1_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT2_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT3_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PDB0_IRQHandler(void);             /**< Programmable Delay Block                                                         */
extern void Tamper_IRQHandler(void);           /**< Tamper Detect and Secure Key Storage                                             */
extern void DAC0_IRQHandler(void);             /**< Digital to Analogue Converter                                                    */
extern void MCG_IRQHandler(void);              /**< Multipurpose Clock Generator                                                     */
extern void LPTMR0_IRQHandler(void);           /**< Low Power Timer                                                                  */
extern void PORTA_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTB_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTC_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTD_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTE_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void SWI_IRQHandler(void);              /**< Software interrupt                                                               */

/**
 * @} */ /* End group Interrupt_handler_prototypes_GROUP 
 */
/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/**
* @addtogroup Cortex_Core_Configuration_GROUP Cortex Core Configuration
* @brief Configuration of the cm4 Processor and Core Peripherals
* @{
*/
#define __CM3_REV                 0x0100     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          0          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cm3.h"           /* Processor and core peripherals     */
#include "system.h"             /* Device specific configuration file */

#ifndef __IO
#define __IO volatile 
#endif

#ifndef __I
#define __I volatile const
#endif

#ifndef __O
#define __O volatile
#endif


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */



/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif
/**
* @addtogroup Peripheral_access_layer_GROUP Device Peripheral Access Layer
* @brief C structs allowing access to peripheral registers
* @{
*/
/**
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC0 (file:ADC0_DIFF_A)              ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC0 Structure                                               */
   __IO uint32_t  SC1[2];                       /**< 0000: Status and Control Register 1                                */
   __IO uint32_t  CFG1;                         /**< 0008: Configuration Register 1                                     */
   __IO uint32_t  CFG2;                         /**< 000C: Configuration Register 2                                     */
   __I  uint32_t  R[2];                         /**< 0010: Data Result Register                                         */
   __IO uint32_t  CV1;                          /**< 0018: Compare Value                                                */
   __IO uint32_t  CV2;                          /**< 001C: Compare Value                                                */
   __IO uint32_t  SC2;                          /**< 0020: Status and Control Register 2                                */
   __IO uint32_t  SC3;                          /**< 0024: Status and Control Register 3                                */
   __IO uint32_t  OFS;                          /**< 0028: Offset Correction Register                                   */
   __IO uint32_t  PG;                           /**< 002C: Plus-Side Gain Register                                      */
   __IO uint32_t  MG;                           /**< 0030: Minus-Side Gain Register                                     */
   __IO uint32_t  CLPD;                         /**< 0034: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLPS;                         /**< 0038: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP4;                         /**< 003C: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP3;                         /**< 0040: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP2;                         /**< 0044: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP1;                         /**< 0048: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP0;                         /**< 004C: Plus-Side General Calibration Value                          */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  CLMD;                         /**< 0054: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLMS;                         /**< 0058: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM4;                         /**< 005C: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM3;                         /**< 0060: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM2;                         /**< 0064: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM1;                         /**< 0068: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM0;                         /**< 006C: Minus-Side General Calibration Value                         */
} ADC_Type;

/**
 * @} */ /* End group ADC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ADC_Register_Masks_GROUP ADC Register Masks
* @brief Register Masks for ADC
* @{
*/
/* ------- SC1 Bit Fields                           ------ */
#define ADC_SC1_ADCH_MASK                        (0x1FU)                                             /*!< ADC0_SC1: ADCH Mask                     */
#define ADC_SC1_ADCH_SHIFT                       (0U)                                                /*!< ADC0_SC1: ADCH Position                 */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_DIFF_MASK                        (0x20U)                                             /*!< ADC0_SC1: DIFF Mask                     */
#define ADC_SC1_DIFF_SHIFT                       (5U)                                                /*!< ADC0_SC1: DIFF Position                 */
#define ADC_SC1_DIFF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_DIFF_SHIFT))&ADC_SC1_DIFF_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_AIEN_MASK                        (0x40U)                                             /*!< ADC0_SC1: AIEN Mask                     */
#define ADC_SC1_AIEN_SHIFT                       (6U)                                                /*!< ADC0_SC1: AIEN Position                 */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_AIEN_SHIFT))&ADC_SC1_AIEN_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_COCO_MASK                        (0x80U)                                             /*!< ADC0_SC1: COCO Mask                     */
#define ADC_SC1_COCO_SHIFT                       (7U)                                                /*!< ADC0_SC1: COCO Position                 */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_COCO_SHIFT))&ADC_SC1_COCO_MASK) /*!< ADC0_SC1                                */
/* ------- CFG1 Bit Fields                          ------ */
#define ADC_CFG1_ADICLK_MASK                     (0x3U)                                              /*!< ADC0_CFG1: ADICLK Mask                  */
#define ADC_CFG1_ADICLK_SHIFT                    (0U)                                                /*!< ADC0_CFG1: ADICLK Position              */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_MODE_MASK                       (0xCU)                                              /*!< ADC0_CFG1: MODE Mask                    */
#define ADC_CFG1_MODE_SHIFT                      (2U)                                                /*!< ADC0_CFG1: MODE Position                */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLSMP_MASK                     (0x10U)                                             /*!< ADC0_CFG1: ADLSMP Mask                  */
#define ADC_CFG1_ADLSMP_SHIFT                    (4U)                                                /*!< ADC0_CFG1: ADLSMP Position              */
#define ADC_CFG1_ADLSMP(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLSMP_SHIFT))&ADC_CFG1_ADLSMP_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADIV_MASK                       (0x60U)                                             /*!< ADC0_CFG1: ADIV Mask                    */
#define ADC_CFG1_ADIV_SHIFT                      (5U)                                                /*!< ADC0_CFG1: ADIV Position                */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLPC_MASK                      (0x80U)                                             /*!< ADC0_CFG1: ADLPC Mask                   */
#define ADC_CFG1_ADLPC_SHIFT                     (7U)                                                /*!< ADC0_CFG1: ADLPC Position               */
#define ADC_CFG1_ADLPC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLPC_SHIFT))&ADC_CFG1_ADLPC_MASK) /*!< ADC0_CFG1                               */
/* ------- CFG2 Bit Fields                          ------ */
#define ADC_CFG2_ADLSTS_MASK                     (0x3U)                                              /*!< ADC0_CFG2: ADLSTS Mask                  */
#define ADC_CFG2_ADLSTS_SHIFT                    (0U)                                                /*!< ADC0_CFG2: ADLSTS Position              */
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADHSC_MASK                      (0x4U)                                              /*!< ADC0_CFG2: ADHSC Mask                   */
#define ADC_CFG2_ADHSC_SHIFT                     (2U)                                                /*!< ADC0_CFG2: ADHSC Position               */
#define ADC_CFG2_ADHSC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADHSC_SHIFT))&ADC_CFG2_ADHSC_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADACKEN_MASK                    (0x8U)                                              /*!< ADC0_CFG2: ADACKEN Mask                 */
#define ADC_CFG2_ADACKEN_SHIFT                   (3U)                                                /*!< ADC0_CFG2: ADACKEN Position             */
#define ADC_CFG2_ADACKEN(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADACKEN_SHIFT))&ADC_CFG2_ADACKEN_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_MUXSEL_MASK                     (0x10U)                                             /*!< ADC0_CFG2: MUXSEL Mask                  */
#define ADC_CFG2_MUXSEL_SHIFT                    (4U)                                                /*!< ADC0_CFG2: MUXSEL Position              */
#define ADC_CFG2_MUXSEL(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_MUXSEL_SHIFT))&ADC_CFG2_MUXSEL_MASK) /*!< ADC0_CFG2                               */
/* ------- R Bit Fields                             ------ */
#define ADC_R_D_MASK                             (0xFFFFU)                                           /*!< ADC0_R: D Mask                          */
#define ADC_R_D_SHIFT                            (0U)                                                /*!< ADC0_R: D Position                      */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK) /*!< ADC0_R                                  */
/* ------- CV Bit Fields                            ------ */
#define ADC_CV_CV_MASK                           (0xFFFFU)                                           /*!< ADC0_CV: CV Mask                        */
#define ADC_CV_CV_SHIFT                          (0U)                                                /*!< ADC0_CV: CV Position                    */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /*!< ADC0_CV                                 */
/* ------- SC2 Bit Fields                           ------ */
#define ADC_SC2_REFSEL_MASK                      (0x3U)                                              /*!< ADC0_SC2: REFSEL Mask                   */
#define ADC_SC2_REFSEL_SHIFT                     (0U)                                                /*!< ADC0_SC2: REFSEL Position               */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_DMAEN_MASK                       (0x4U)                                              /*!< ADC0_SC2: DMAEN Mask                    */
#define ADC_SC2_DMAEN_SHIFT                      (2U)                                                /*!< ADC0_SC2: DMAEN Position                */
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_DMAEN_SHIFT))&ADC_SC2_DMAEN_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACREN_MASK                       (0x8U)                                              /*!< ADC0_SC2: ACREN Mask                    */
#define ADC_SC2_ACREN_SHIFT                      (3U)                                                /*!< ADC0_SC2: ACREN Position                */
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACREN_SHIFT))&ADC_SC2_ACREN_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACFGT_MASK                       (0x10U)                                             /*!< ADC0_SC2: ACFGT Mask                    */
#define ADC_SC2_ACFGT_SHIFT                      (4U)                                                /*!< ADC0_SC2: ACFGT Position                */
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFGT_SHIFT))&ADC_SC2_ACFGT_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACFE_MASK                        (0x20U)                                             /*!< ADC0_SC2: ACFE Mask                     */
#define ADC_SC2_ACFE_SHIFT                       (5U)                                                /*!< ADC0_SC2: ACFE Position                 */
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFE_SHIFT))&ADC_SC2_ACFE_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADTRG_MASK                       (0x40U)                                             /*!< ADC0_SC2: ADTRG Mask                    */
#define ADC_SC2_ADTRG_SHIFT                      (6U)                                                /*!< ADC0_SC2: ADTRG Position                */
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADTRG_SHIFT))&ADC_SC2_ADTRG_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADACT_MASK                       (0x80U)                                             /*!< ADC0_SC2: ADACT Mask                    */
#define ADC_SC2_ADACT_SHIFT                      (7U)                                                /*!< ADC0_SC2: ADACT Position                */
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADACT_SHIFT))&ADC_SC2_ADACT_MASK) /*!< ADC0_SC2                                */
/* ------- SC3 Bit Fields                           ------ */
#define ADC_SC3_AVGS_MASK                        (0x3U)                                              /*!< ADC0_SC3: AVGS Mask                     */
#define ADC_SC3_AVGS_SHIFT                       (0U)                                                /*!< ADC0_SC3: AVGS Position                 */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_AVGE_MASK                        (0x4U)                                              /*!< ADC0_SC3: AVGE Mask                     */
#define ADC_SC3_AVGE_SHIFT                       (2U)                                                /*!< ADC0_SC3: AVGE Position                 */
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGE_SHIFT))&ADC_SC3_AVGE_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_ADCO_MASK                        (0x8U)                                              /*!< ADC0_SC3: ADCO Mask                     */
#define ADC_SC3_ADCO_SHIFT                       (3U)                                                /*!< ADC0_SC3: ADCO Position                 */
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADCO_SHIFT))&ADC_SC3_ADCO_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_CALF_MASK                        (0x40U)                                             /*!< ADC0_SC3: CALF Mask                     */
#define ADC_SC3_CALF_SHIFT                       (6U)                                                /*!< ADC0_SC3: CALF Position                 */
#define ADC_SC3_CALF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CALF_SHIFT))&ADC_SC3_CALF_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_CAL_MASK                         (0x80U)                                             /*!< ADC0_SC3: CAL Mask                      */
#define ADC_SC3_CAL_SHIFT                        (7U)                                                /*!< ADC0_SC3: CAL Position                  */
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CAL_SHIFT))&ADC_SC3_CAL_MASK) /*!< ADC0_SC3                                */
/* ------- OFS Bit Fields                           ------ */
#define ADC_OFS_OFS_MASK                         (0xFFFFU)                                           /*!< ADC0_OFS: OFS Mask                      */
#define ADC_OFS_OFS_SHIFT                        (0U)                                                /*!< ADC0_OFS: OFS Position                  */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK) /*!< ADC0_OFS                                */
/* ------- PG Bit Fields                            ------ */
#define ADC_PG_PG_MASK                           (0xFFFFU)                                           /*!< ADC0_PG: PG Mask                        */
#define ADC_PG_PG_SHIFT                          (0U)                                                /*!< ADC0_PG: PG Position                    */
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK) /*!< ADC0_PG                                 */
/* ------- MG Bit Fields                            ------ */
#define ADC_MG_MG_MASK                           (0xFFFFU)                                           /*!< ADC0_MG: MG Mask                        */
#define ADC_MG_MG_SHIFT                          (0U)                                                /*!< ADC0_MG: MG Position                    */
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_MG_MG_SHIFT))&ADC_MG_MG_MASK) /*!< ADC0_MG                                 */
/* ------- CLPD Bit Fields                          ------ */
#define ADC_CLPD_CLPD_MASK                       (0x3FU)                                             /*!< ADC0_CLPD: CLPD Mask                    */
#define ADC_CLPD_CLPD_SHIFT                      (0U)                                                /*!< ADC0_CLPD: CLPD Position                */
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK) /*!< ADC0_CLPD                               */
/* ------- CLPS Bit Fields                          ------ */
#define ADC_CLPS_CLPS_MASK                       (0x3FU)                                             /*!< ADC0_CLPS: CLPS Mask                    */
#define ADC_CLPS_CLPS_SHIFT                      (0U)                                                /*!< ADC0_CLPS: CLPS Position                */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK) /*!< ADC0_CLPS                               */
/* ------- CLP4 Bit Fields                          ------ */
#define ADC_CLP4_CLP4_MASK                       (0x3FFU)                                            /*!< ADC0_CLP4: CLP4 Mask                    */
#define ADC_CLP4_CLP4_SHIFT                      (0U)                                                /*!< ADC0_CLP4: CLP4 Position                */
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK) /*!< ADC0_CLP4                               */
/* ------- CLP3 Bit Fields                          ------ */
#define ADC_CLP3_CLP3_MASK                       (0x1FFU)                                            /*!< ADC0_CLP3: CLP3 Mask                    */
#define ADC_CLP3_CLP3_SHIFT                      (0U)                                                /*!< ADC0_CLP3: CLP3 Position                */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK) /*!< ADC0_CLP3                               */
/* ------- CLP2 Bit Fields                          ------ */
#define ADC_CLP2_CLP2_MASK                       (0xFFU)                                             /*!< ADC0_CLP2: CLP2 Mask                    */
#define ADC_CLP2_CLP2_SHIFT                      (0U)                                                /*!< ADC0_CLP2: CLP2 Position                */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK) /*!< ADC0_CLP2                               */
/* ------- CLP1 Bit Fields                          ------ */
#define ADC_CLP1_CLP1_MASK                       (0x7FU)                                             /*!< ADC0_CLP1: CLP1 Mask                    */
#define ADC_CLP1_CLP1_SHIFT                      (0U)                                                /*!< ADC0_CLP1: CLP1 Position                */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK) /*!< ADC0_CLP1                               */
/* ------- CLP0 Bit Fields                          ------ */
#define ADC_CLP0_CLP0_MASK                       (0x3FU)                                             /*!< ADC0_CLP0: CLP0 Mask                    */
#define ADC_CLP0_CLP0_SHIFT                      (0U)                                                /*!< ADC0_CLP0: CLP0 Position                */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK) /*!< ADC0_CLP0                               */
/* ------- CLMD Bit Fields                          ------ */
#define ADC_CLMD_CLMD_MASK                       (0x3FU)                                             /*!< ADC0_CLMD: CLMD Mask                    */
#define ADC_CLMD_CLMD_SHIFT                      (0U)                                                /*!< ADC0_CLMD: CLMD Position                */
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMD_CLMD_SHIFT))&ADC_CLMD_CLMD_MASK) /*!< ADC0_CLMD                               */
/* ------- CLMS Bit Fields                          ------ */
#define ADC_CLMS_CLMS_MASK                       (0x3FU)                                             /*!< ADC0_CLMS: CLMS Mask                    */
#define ADC_CLMS_CLMS_SHIFT                      (0U)                                                /*!< ADC0_CLMS: CLMS Position                */
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMS_CLMS_SHIFT))&ADC_CLMS_CLMS_MASK) /*!< ADC0_CLMS                               */
/* ------- CLM4 Bit Fields                          ------ */
#define ADC_CLM4_CLM4_MASK                       (0x3FFU)                                            /*!< ADC0_CLM4: CLM4 Mask                    */
#define ADC_CLM4_CLM4_SHIFT                      (0U)                                                /*!< ADC0_CLM4: CLM4 Position                */
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM4_CLM4_SHIFT))&ADC_CLM4_CLM4_MASK) /*!< ADC0_CLM4                               */
/* ------- CLM3 Bit Fields                          ------ */
#define ADC_CLM3_CLM3_MASK                       (0x1FFU)                                            /*!< ADC0_CLM3: CLM3 Mask                    */
#define ADC_CLM3_CLM3_SHIFT                      (0U)                                                /*!< ADC0_CLM3: CLM3 Position                */
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM3_CLM3_SHIFT))&ADC_CLM3_CLM3_MASK) /*!< ADC0_CLM3                               */
/* ------- CLM2 Bit Fields                          ------ */
#define ADC_CLM2_CLM2_MASK                       (0xFFU)                                             /*!< ADC0_CLM2: CLM2 Mask                    */
#define ADC_CLM2_CLM2_SHIFT                      (0U)                                                /*!< ADC0_CLM2: CLM2 Position                */
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM2_CLM2_SHIFT))&ADC_CLM2_CLM2_MASK) /*!< ADC0_CLM2                               */
/* ------- CLM1 Bit Fields                          ------ */
#define ADC_CLM1_CLM1_MASK                       (0x7FU)                                             /*!< ADC0_CLM1: CLM1 Mask                    */
#define ADC_CLM1_CLM1_SHIFT                      (0U)                                                /*!< ADC0_CLM1: CLM1 Position                */
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM1_CLM1_SHIFT))&ADC_CLM1_CLM1_MASK) /*!< ADC0_CLM1                               */
/* ------- CLM0 Bit Fields                          ------ */
#define ADC_CLM0_CLM0_MASK                       (0x3FU)                                             /*!< ADC0_CLM0: CLM0 Mask                    */
#define ADC_CLM0_CLM0_SHIFT                      (0U)                                                /*!< ADC0_CLM0: CLM0 Position                */
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM0_CLM0_SHIFT))&ADC_CLM0_CLM0_MASK) /*!< ADC0_CLM0                               */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0x4003B000UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CAU_Peripheral_access_layer_GROUP CAU Peripheral Access Layer
* @brief C Struct for CAU
* @{
*/

/* ================================================================================ */
/* ================           CAU (file:CAU_0)                     ================ */
/* ================================================================================ */

/**
 * @brief Memory Mapped Cryptographic Acceleration Unit
 */
/**
* @addtogroup CAU_structs_GROUP CAU struct
* @brief Struct for CAU
* @{
*/
typedef struct {                                /*       CAU Structure                                                */
   __O  uint32_t  DIRECT[16];                   /**< 0000: Direct access register                                       */
        uint8_t   RESERVED_0[2048];            
   __O  uint32_t  LDR_CASR;                     /**< 0840: Status register - Load Register command                      */
   __O  uint32_t  LDR_CAA;                      /**< 0844: Accumulator register - Load Register command                 */
   __O  uint32_t  LDR_CA[9];                    /**< 0848: General Purpose Register  - Load Register command            */
        uint8_t   RESERVED_1[20];              
   __I  uint32_t  STR_CASR;                     /**< 0880: Status register  - Store Register command                    */
   __I  uint32_t  STR_CAA;                      /**< 0884: Accumulator register - Store Register command                */
   __I  uint32_t  STR_CA[9];                    /**< 0888: General Purpose Register  - Store Register command           */
        uint8_t   RESERVED_2[20];              
   __O  uint32_t  ADR_CASR;                     /**< 08C0: Status register  - Add Register command                      */
   __O  uint32_t  ADR_CAA;                      /**< 08C4: Accumulator register - Add to register command               */
   __O  uint32_t  ADR_CA[9];                    /**< 08C8: General Purpose Register  - Add to register command          */
        uint8_t   RESERVED_3[20];              
   __O  uint32_t  RADR_CASR;                    /**< 0900: Status register  - Reverse and Add to Register command       */
   __O  uint32_t  RADR_CAA;                     /**< 0904: Accumulator register - Reverse and Add to Register command   */
   __O  uint32_t  RADR_CA[9];                   /**< 0908: General Purpose Register  - Reverse and Add to Register command */
        uint8_t   RESERVED_4[84];              
   __O  uint32_t  XOR_CASR;                     /**< 0980: Status register  - Exclusive Or command                      */
   __O  uint32_t  XOR_CAA;                      /**< 0984: Accumulator register - Exclusive Or command                  */
   __O  uint32_t  XOR_CA[9];                    /**< 0988: General Purpose Register  - Exclusive Or command             */
        uint8_t   RESERVED_5[20];              
   __O  uint32_t  ROTL_CASR;                    /**< 09C0: Status register  - Rotate Left command                       */
   __O  uint32_t  ROTL_CAA;                     /**< 09C4: Accumulator register - Rotate Left command                   */
   __O  uint32_t  ROTL_CA[9];                   /**< 09C8: General Purpose Register  - Rotate Left command              */
        uint8_t   RESERVED_6[276];             
   __O  uint32_t  AESC_CASR;                    /**< 0B00: Status register  - AES Column Operation command              */
   __O  uint32_t  AESC_CAA;                     /**< 0B04: Accumulator register - AES Column Operation command          */
   __O  uint32_t  AESC_CA[9];                   /**< 0B08: General Purpose Register  - AES Column Operation command     */
        uint8_t   RESERVED_7[20];              
   __O  uint32_t  AESIC_CASR;                   /**< 0B40: Status register  - AES Inverse Column Operation command      */
   __O  uint32_t  AESIC_CAA;                    /**< 0B44: Accumulator register - AES Inverse Column Operation command  */
   __O  uint32_t  AESIC_CA[9];                  /**< 0B48: General Purpose Register  - AES Inverse Column Operation command */
} CAU_Type;

/**
 * @} */ /* End group CAU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CAU' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CAU_Register_Masks_GROUP CAU Register Masks
* @brief Register Masks for CAU
* @{
*/
/* ------- DIRECT Bit Fields                        ------ */
/* ------- LDR_CASR Bit Fields                      ------ */
#define CAU_LDR_CASR_IC_MASK                     (0x1U)                                              /*!< CAU_LDR_CASR: IC Mask                   */
#define CAU_LDR_CASR_IC_SHIFT                    (0U)                                                /*!< CAU_LDR_CASR: IC Position               */
#define CAU_LDR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CASR_IC_SHIFT))&CAU_LDR_CASR_IC_MASK) /*!< CAU_LDR_CASR                            */
#define CAU_LDR_CASR_DPE_MASK                    (0x2U)                                              /*!< CAU_LDR_CASR: DPE Mask                  */
#define CAU_LDR_CASR_DPE_SHIFT                   (1U)                                                /*!< CAU_LDR_CASR: DPE Position              */
#define CAU_LDR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CASR_DPE_SHIFT))&CAU_LDR_CASR_DPE_MASK) /*!< CAU_LDR_CASR                            */
#define CAU_LDR_CASR_VER_MASK                    (0xF0000000U)                                       /*!< CAU_LDR_CASR: VER Mask                  */
#define CAU_LDR_CASR_VER_SHIFT                   (28U)                                               /*!< CAU_LDR_CASR: VER Position              */
#define CAU_LDR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_LDR_CASR_VER_SHIFT))&CAU_LDR_CASR_VER_MASK) /*!< CAU_LDR_CASR                            */
/* ------- LDR_CAA Bit Fields                       ------ */
/* ------- LDR_CA Bit Fields                        ------ */
/* ------- STR_CASR Bit Fields                      ------ */
#define CAU_STR_CASR_IC_MASK                     (0x1U)                                              /*!< CAU_STR_CASR: IC Mask                   */
#define CAU_STR_CASR_IC_SHIFT                    (0U)                                                /*!< CAU_STR_CASR: IC Position               */
#define CAU_STR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_STR_CASR_IC_SHIFT))&CAU_STR_CASR_IC_MASK) /*!< CAU_STR_CASR                            */
#define CAU_STR_CASR_DPE_MASK                    (0x2U)                                              /*!< CAU_STR_CASR: DPE Mask                  */
#define CAU_STR_CASR_DPE_SHIFT                   (1U)                                                /*!< CAU_STR_CASR: DPE Position              */
#define CAU_STR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_STR_CASR_DPE_SHIFT))&CAU_STR_CASR_DPE_MASK) /*!< CAU_STR_CASR                            */
#define CAU_STR_CASR_VER_MASK                    (0xF0000000U)                                       /*!< CAU_STR_CASR: VER Mask                  */
#define CAU_STR_CASR_VER_SHIFT                   (28U)                                               /*!< CAU_STR_CASR: VER Position              */
#define CAU_STR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_STR_CASR_VER_SHIFT))&CAU_STR_CASR_VER_MASK) /*!< CAU_STR_CASR                            */
/* ------- STR_CAA Bit Fields                       ------ */
/* ------- STR_CA Bit Fields                        ------ */
/* ------- ADR_CASR Bit Fields                      ------ */
#define CAU_ADR_CASR_IC_MASK                     (0x1U)                                              /*!< CAU_ADR_CASR: IC Mask                   */
#define CAU_ADR_CASR_IC_SHIFT                    (0U)                                                /*!< CAU_ADR_CASR: IC Position               */
#define CAU_ADR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CASR_IC_SHIFT))&CAU_ADR_CASR_IC_MASK) /*!< CAU_ADR_CASR                            */
#define CAU_ADR_CASR_DPE_MASK                    (0x2U)                                              /*!< CAU_ADR_CASR: DPE Mask                  */
#define CAU_ADR_CASR_DPE_SHIFT                   (1U)                                                /*!< CAU_ADR_CASR: DPE Position              */
#define CAU_ADR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CASR_DPE_SHIFT))&CAU_ADR_CASR_DPE_MASK) /*!< CAU_ADR_CASR                            */
#define CAU_ADR_CASR_VER_MASK                    (0xF0000000U)                                       /*!< CAU_ADR_CASR: VER Mask                  */
#define CAU_ADR_CASR_VER_SHIFT                   (28U)                                               /*!< CAU_ADR_CASR: VER Position              */
#define CAU_ADR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_ADR_CASR_VER_SHIFT))&CAU_ADR_CASR_VER_MASK) /*!< CAU_ADR_CASR                            */
/* ------- ADR_CAA Bit Fields                       ------ */
/* ------- ADR_CA Bit Fields                        ------ */
/* ------- RADR_CASR Bit Fields                     ------ */
#define CAU_RADR_CASR_IC_MASK                    (0x1U)                                              /*!< CAU_RADR_CASR: IC Mask                  */
#define CAU_RADR_CASR_IC_SHIFT                   (0U)                                                /*!< CAU_RADR_CASR: IC Position              */
#define CAU_RADR_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CASR_IC_SHIFT))&CAU_RADR_CASR_IC_MASK) /*!< CAU_RADR_CASR                           */
#define CAU_RADR_CASR_DPE_MASK                   (0x2U)                                              /*!< CAU_RADR_CASR: DPE Mask                 */
#define CAU_RADR_CASR_DPE_SHIFT                  (1U)                                                /*!< CAU_RADR_CASR: DPE Position             */
#define CAU_RADR_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CASR_DPE_SHIFT))&CAU_RADR_CASR_DPE_MASK) /*!< CAU_RADR_CASR                           */
#define CAU_RADR_CASR_VER_MASK                   (0xF0000000U)                                       /*!< CAU_RADR_CASR: VER Mask                 */
#define CAU_RADR_CASR_VER_SHIFT                  (28U)                                               /*!< CAU_RADR_CASR: VER Position             */
#define CAU_RADR_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_RADR_CASR_VER_SHIFT))&CAU_RADR_CASR_VER_MASK) /*!< CAU_RADR_CASR                           */
/* ------- RADR_CAA Bit Fields                      ------ */
/* ------- RADR_CA Bit Fields                       ------ */
/* ------- XOR_CASR Bit Fields                      ------ */
#define CAU_XOR_CASR_IC_MASK                     (0x1U)                                              /*!< CAU_XOR_CASR: IC Mask                   */
#define CAU_XOR_CASR_IC_SHIFT                    (0U)                                                /*!< CAU_XOR_CASR: IC Position               */
#define CAU_XOR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CASR_IC_SHIFT))&CAU_XOR_CASR_IC_MASK) /*!< CAU_XOR_CASR                            */
#define CAU_XOR_CASR_DPE_MASK                    (0x2U)                                              /*!< CAU_XOR_CASR: DPE Mask                  */
#define CAU_XOR_CASR_DPE_SHIFT                   (1U)                                                /*!< CAU_XOR_CASR: DPE Position              */
#define CAU_XOR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CASR_DPE_SHIFT))&CAU_XOR_CASR_DPE_MASK) /*!< CAU_XOR_CASR                            */
#define CAU_XOR_CASR_VER_MASK                    (0xF0000000U)                                       /*!< CAU_XOR_CASR: VER Mask                  */
#define CAU_XOR_CASR_VER_SHIFT                   (28U)                                               /*!< CAU_XOR_CASR: VER Position              */
#define CAU_XOR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_XOR_CASR_VER_SHIFT))&CAU_XOR_CASR_VER_MASK) /*!< CAU_XOR_CASR                            */
/* ------- XOR_CAA Bit Fields                       ------ */
/* ------- XOR_CA Bit Fields                        ------ */
/* ------- ROTL_CASR Bit Fields                     ------ */
#define CAU_ROTL_CASR_IC_MASK                    (0x1U)                                              /*!< CAU_ROTL_CASR: IC Mask                  */
#define CAU_ROTL_CASR_IC_SHIFT                   (0U)                                                /*!< CAU_ROTL_CASR: IC Position              */
#define CAU_ROTL_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CASR_IC_SHIFT))&CAU_ROTL_CASR_IC_MASK) /*!< CAU_ROTL_CASR                           */
#define CAU_ROTL_CASR_DPE_MASK                   (0x2U)                                              /*!< CAU_ROTL_CASR: DPE Mask                 */
#define CAU_ROTL_CASR_DPE_SHIFT                  (1U)                                                /*!< CAU_ROTL_CASR: DPE Position             */
#define CAU_ROTL_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CASR_DPE_SHIFT))&CAU_ROTL_CASR_DPE_MASK) /*!< CAU_ROTL_CASR                           */
#define CAU_ROTL_CASR_VER_MASK                   (0xF0000000U)                                       /*!< CAU_ROTL_CASR: VER Mask                 */
#define CAU_ROTL_CASR_VER_SHIFT                  (28U)                                               /*!< CAU_ROTL_CASR: VER Position             */
#define CAU_ROTL_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_ROTL_CASR_VER_SHIFT))&CAU_ROTL_CASR_VER_MASK) /*!< CAU_ROTL_CASR                           */
/* ------- ROTL_CAA Bit Fields                      ------ */
/* ------- ROTL_CA Bit Fields                       ------ */
/* ------- AESC_CASR Bit Fields                     ------ */
#define CAU_AESC_CASR_IC_MASK                    (0x1U)                                              /*!< CAU_AESC_CASR: IC Mask                  */
#define CAU_AESC_CASR_IC_SHIFT                   (0U)                                                /*!< CAU_AESC_CASR: IC Position              */
#define CAU_AESC_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CASR_IC_SHIFT))&CAU_AESC_CASR_IC_MASK) /*!< CAU_AESC_CASR                           */
#define CAU_AESC_CASR_DPE_MASK                   (0x2U)                                              /*!< CAU_AESC_CASR: DPE Mask                 */
#define CAU_AESC_CASR_DPE_SHIFT                  (1U)                                                /*!< CAU_AESC_CASR: DPE Position             */
#define CAU_AESC_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CASR_DPE_SHIFT))&CAU_AESC_CASR_DPE_MASK) /*!< CAU_AESC_CASR                           */
#define CAU_AESC_CASR_VER_MASK                   (0xF0000000U)                                       /*!< CAU_AESC_CASR: VER Mask                 */
#define CAU_AESC_CASR_VER_SHIFT                  (28U)                                               /*!< CAU_AESC_CASR: VER Position             */
#define CAU_AESC_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_AESC_CASR_VER_SHIFT))&CAU_AESC_CASR_VER_MASK) /*!< CAU_AESC_CASR                           */
/* ------- AESC_CAA Bit Fields                      ------ */
/* ------- AESC_CA Bit Fields                       ------ */
/* ------- AESIC_CASR Bit Fields                    ------ */
#define CAU_AESIC_CASR_IC_MASK                   (0x1U)                                              /*!< CAU_AESIC_CASR: IC Mask                 */
#define CAU_AESIC_CASR_IC_SHIFT                  (0U)                                                /*!< CAU_AESIC_CASR: IC Position             */
#define CAU_AESIC_CASR_IC(x)                     (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CASR_IC_SHIFT))&CAU_AESIC_CASR_IC_MASK) /*!< CAU_AESIC_CASR                          */
#define CAU_AESIC_CASR_DPE_MASK                  (0x2U)                                              /*!< CAU_AESIC_CASR: DPE Mask                */
#define CAU_AESIC_CASR_DPE_SHIFT                 (1U)                                                /*!< CAU_AESIC_CASR: DPE Position            */
#define CAU_AESIC_CASR_DPE(x)                    (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CASR_DPE_SHIFT))&CAU_AESIC_CASR_DPE_MASK) /*!< CAU_AESIC_CASR                          */
#define CAU_AESIC_CASR_VER_MASK                  (0xF0000000U)                                       /*!< CAU_AESIC_CASR: VER Mask                */
#define CAU_AESIC_CASR_VER_SHIFT                 (28U)                                               /*!< CAU_AESIC_CASR: VER Position            */
#define CAU_AESIC_CASR_VER(x)                    (((uint32_t)(((uint32_t)(x))<<CAU_AESIC_CASR_VER_SHIFT))&CAU_AESIC_CASR_VER_MASK) /*!< CAU_AESIC_CASR                          */
/* ------- AESIC_CAA Bit Fields                     ------ */
/* ------- AESIC_CA Bit Fields                      ------ */
/**
 * @} */ /* End group CAU_Register_Masks_GROUP 
 */

/* CAU - Peripheral instance base addresses */
#define CAU_BasePtr                    0xE0081000UL //!< Peripheral base address
#define CAU                            ((CAU_Type *) CAU_BasePtr) //!< Freescale base pointer
#define CAU_BASE_PTR                   (CAU) //!< Freescale style base pointer
/**
 * @} */ /* End group CAU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_PSTM7)               ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */
/**
* @addtogroup CMP_structs_GROUP CMP struct
* @brief Struct for CMP
* @{
*/
typedef struct {                                /*       CMP0 Structure                                               */
   __IO uint8_t   CR0;                          /**< 0000: CMP Control Register 0                                       */
   __IO uint8_t   CR1;                          /**< 0001: CMP Control Register 1                                       */
   __IO uint8_t   FPR;                          /**< 0002: CMP Filter Period Register                                   */
   __IO uint8_t   SCR;                          /**< 0003: CMP Status and Control Register                              */
   __IO uint8_t   DACCR;                        /**< 0004: DAC Control Register                                         */
   __IO uint8_t   MUXCR;                        /**< 0005: MUX Control Register                                         */
} CMP_Type;

/**
 * @} */ /* End group CMP_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMP0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMP_Register_Masks_GROUP CMP Register Masks
* @brief Register Masks for CMP
* @{
*/
/* ------- CR0 Bit Fields                           ------ */
#define CMP_CR0_HYSTCTR_MASK                     (0x3U)                                              /*!< CMP0_CR0: HYSTCTR Mask                  */
#define CMP_CR0_HYSTCTR_SHIFT                    (0U)                                                /*!< CMP0_CR0: HYSTCTR Position              */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK) /*!< CMP0_CR0                                */
#define CMP_CR0_FILTER_CNT_MASK                  (0x70U)                                             /*!< CMP0_CR0: FILTER_CNT Mask               */
#define CMP_CR0_FILTER_CNT_SHIFT                 (4U)                                                /*!< CMP0_CR0: FILTER_CNT Position           */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK) /*!< CMP0_CR0                                */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x1U)                                              /*!< CMP0_CR1: EN Mask                       */
#define CMP_CR1_EN_SHIFT                         (0U)                                                /*!< CMP0_CR1: EN Position                   */
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_EN_SHIFT))&CMP_CR1_EN_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_OPE_MASK                         (0x2U)                                              /*!< CMP0_CR1: OPE Mask                      */
#define CMP_CR1_OPE_SHIFT                        (1U)                                                /*!< CMP0_CR1: OPE Position                  */
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_OPE_SHIFT))&CMP_CR1_OPE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_COS_MASK                         (0x4U)                                              /*!< CMP0_CR1: COS Mask                      */
#define CMP_CR1_COS_SHIFT                        (2U)                                                /*!< CMP0_CR1: COS Position                  */
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_COS_SHIFT))&CMP_CR1_COS_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_INV_MASK                         (0x8U)                                              /*!< CMP0_CR1: INV Mask                      */
#define CMP_CR1_INV_SHIFT                        (3U)                                                /*!< CMP0_CR1: INV Position                  */
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_INV_SHIFT))&CMP_CR1_INV_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_PMODE_MASK                       (0x10U)                                             /*!< CMP0_CR1: PMODE Mask                    */
#define CMP_CR1_PMODE_SHIFT                      (4U)                                                /*!< CMP0_CR1: PMODE Position                */
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_PMODE_SHIFT))&CMP_CR1_PMODE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_WE_MASK                          (0x40U)                                             /*!< CMP0_CR1: WE Mask                       */
#define CMP_CR1_WE_SHIFT                         (6U)                                                /*!< CMP0_CR1: WE Position                   */
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_WE_SHIFT))&CMP_CR1_WE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_SE_MASK                          (0x80U)                                             /*!< CMP0_CR1: SE Mask                       */
#define CMP_CR1_SE_SHIFT                         (7U)                                                /*!< CMP0_CR1: SE Position                   */
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_SE_SHIFT))&CMP_CR1_SE_MASK) /*!< CMP0_CR1                                */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFU)                                             /*!< CMP0_FPR: FILT_PER Mask                 */
#define CMP_FPR_FILT_PER_SHIFT                   (0U)                                                /*!< CMP0_FPR: FILT_PER Position             */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK) /*!< CMP0_FPR                                */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x1U)                                              /*!< CMP0_SCR: COUT Mask                     */
#define CMP_SCR_COUT_SHIFT                       (0U)                                                /*!< CMP0_SCR: COUT Position                 */
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<CMP_SCR_COUT_SHIFT))&CMP_SCR_COUT_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFF_MASK                         (0x2U)                                              /*!< CMP0_SCR: CFF Mask                      */
#define CMP_SCR_CFF_SHIFT                        (1U)                                                /*!< CMP0_SCR: CFF Position                  */
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFF_SHIFT))&CMP_SCR_CFF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFR_MASK                         (0x4U)                                              /*!< CMP0_SCR: CFR Mask                      */
#define CMP_SCR_CFR_SHIFT                        (2U)                                                /*!< CMP0_SCR: CFR Position                  */
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFR_SHIFT))&CMP_SCR_CFR_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IEF_MASK                         (0x8U)                                              /*!< CMP0_SCR: IEF Mask                      */
#define CMP_SCR_IEF_SHIFT                        (3U)                                                /*!< CMP0_SCR: IEF Position                  */
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IEF_SHIFT))&CMP_SCR_IEF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IER_MASK                         (0x10U)                                             /*!< CMP0_SCR: IER Mask                      */
#define CMP_SCR_IER_SHIFT                        (4U)                                                /*!< CMP0_SCR: IER Position                  */
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IER_SHIFT))&CMP_SCR_IER_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_DMAEN_MASK                       (0x40U)                                             /*!< CMP0_SCR: DMAEN Mask                    */
#define CMP_SCR_DMAEN_SHIFT                      (6U)                                                /*!< CMP0_SCR: DMAEN Position                */
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_SCR_DMAEN_SHIFT))&CMP_SCR_DMAEN_MASK) /*!< CMP0_SCR                                */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FU)                                             /*!< CMP0_DACCR: VOSEL Mask                  */
#define CMP_DACCR_VOSEL_SHIFT                    (0U)                                                /*!< CMP0_DACCR: VOSEL Position              */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_VRSEL_MASK                     (0x40U)                                             /*!< CMP0_DACCR: VRSEL Mask                  */
#define CMP_DACCR_VRSEL_SHIFT                    (6U)                                                /*!< CMP0_DACCR: VRSEL Position              */
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VRSEL_SHIFT))&CMP_DACCR_VRSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_DACEN_MASK                     (0x80U)                                             /*!< CMP0_DACCR: DACEN Mask                  */
#define CMP_DACCR_DACEN_SHIFT                    (7U)                                                /*!< CMP0_DACCR: DACEN Position              */
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_DACEN_SHIFT))&CMP_DACCR_DACEN_MASK) /*!< CMP0_DACCR                              */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x7U)                                              /*!< CMP0_MUXCR: MSEL Mask                   */
#define CMP_MUXCR_MSEL_SHIFT                     (0U)                                                /*!< CMP0_MUXCR: MSEL Position               */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSEL_MASK                      (0x38U)                                             /*!< CMP0_MUXCR: PSEL Mask                   */
#define CMP_MUXCR_PSEL_SHIFT                     (3U)                                                /*!< CMP0_MUXCR: PSEL Position               */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSTM_MASK                      (0x80U)                                             /*!< CMP0_MUXCR: PSTM Mask                   */
#define CMP_MUXCR_PSTM_SHIFT                     (7U)                                                /*!< CMP0_MUXCR: PSTM Position               */
#define CMP_MUXCR_PSTM(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSTM_SHIFT))&CMP_MUXCR_PSTM_MASK) /*!< CMP0_MUXCR                              */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40073000UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP1 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP1 - Peripheral instance base addresses */
#define CMP1_BasePtr                   0x40073008UL //!< Peripheral base address
#define CMP1                           ((CMP_Type *) CMP1_BasePtr) //!< Freescale base pointer
#define CMP1_BASE_PTR                  (CMP1) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMT_Peripheral_access_layer_GROUP CMT Peripheral Access Layer
* @brief C Struct for CMT
* @{
*/

/* ================================================================================ */
/* ================           CMT (file:CMT_0)                     ================ */
/* ================================================================================ */

/**
 * @brief Carrier Modulator Transmitter
 */
/**
* @addtogroup CMT_structs_GROUP CMT struct
* @brief Struct for CMT
* @{
*/
typedef struct {                                /*       CMT Structure                                                */
   __IO uint8_t   CGH1;                         /**< 0000: Carrier Generator High Data Register 1                       */
   __IO uint8_t   CGL1;                         /**< 0001: Carrier Generator Low Data Register 1                        */
   __IO uint8_t   CGH2;                         /**< 0002: Carrier Generator High Data Register 2                       */
   __IO uint8_t   CGL2;                         /**< 0003: Carrier Generator Low Data Register 2                        */
   __IO uint8_t   OC;                           /**< 0004: Output Control Register                                      */
   __IO uint8_t   MSC;                          /**< 0005: Modulator Status and Control Register                        */
   __IO uint8_t   CMD1;                         /**< 0006: Modulator Data Register Mark High                            */
   __IO uint8_t   CMD2;                         /**< 0007: Modulator Data Register Mark Low                             */
   __IO uint8_t   CMD3;                         /**< 0008: Modulator Data Register Space High                           */
   __IO uint8_t   CMD4;                         /**< 0009: Modulator Data Register Space Low                            */
   __IO uint8_t   PPS;                          /**< 000A: Primary Prescaler Register                                   */
   __IO uint8_t   DMA;                          /**< 000B: Direct Memory Access                                         */
} CMT_Type;

/**
 * @} */ /* End group CMT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMT_Register_Masks_GROUP CMT Register Masks
* @brief Register Masks for CMT
* @{
*/
/* ------- CGH1 Bit Fields                          ------ */
#define CMT_CGH1_PH_MASK                         (0xFFU)                                             /*!< CMT_CGH1: PH Mask                       */
#define CMT_CGH1_PH_SHIFT                        (0U)                                                /*!< CMT_CGH1: PH Position                   */
#define CMT_CGH1_PH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH1_PH_SHIFT))&CMT_CGH1_PH_MASK) /*!< CMT_CGH1                                */
/* ------- CGL1 Bit Fields                          ------ */
#define CMT_CGL1_PL_MASK                         (0xFFU)                                             /*!< CMT_CGL1: PL Mask                       */
#define CMT_CGL1_PL_SHIFT                        (0U)                                                /*!< CMT_CGL1: PL Position                   */
#define CMT_CGL1_PL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL1_PL_SHIFT))&CMT_CGL1_PL_MASK) /*!< CMT_CGL1                                */
/* ------- CGH2 Bit Fields                          ------ */
#define CMT_CGH2_SH_MASK                         (0xFFU)                                             /*!< CMT_CGH2: SH Mask                       */
#define CMT_CGH2_SH_SHIFT                        (0U)                                                /*!< CMT_CGH2: SH Position                   */
#define CMT_CGH2_SH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH2_SH_SHIFT))&CMT_CGH2_SH_MASK) /*!< CMT_CGH2                                */
/* ------- CGL2 Bit Fields                          ------ */
#define CMT_CGL2_SL_MASK                         (0xFFU)                                             /*!< CMT_CGL2: SL Mask                       */
#define CMT_CGL2_SL_SHIFT                        (0U)                                                /*!< CMT_CGL2: SL Position                   */
#define CMT_CGL2_SL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL2_SL_SHIFT))&CMT_CGL2_SL_MASK) /*!< CMT_CGL2                                */
/* ------- OC Bit Fields                            ------ */
#define CMT_OC_IROPEN_MASK                       (0x20U)                                             /*!< CMT_OC: IROPEN Mask                     */
#define CMT_OC_IROPEN_SHIFT                      (5U)                                                /*!< CMT_OC: IROPEN Position                 */
#define CMT_OC_IROPEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_OC_IROPEN_SHIFT))&CMT_OC_IROPEN_MASK) /*!< CMT_OC                                  */
#define CMT_OC_CMTPOL_MASK                       (0x40U)                                             /*!< CMT_OC: CMTPOL Mask                     */
#define CMT_OC_CMTPOL_SHIFT                      (6U)                                                /*!< CMT_OC: CMTPOL Position                 */
#define CMT_OC_CMTPOL(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_OC_CMTPOL_SHIFT))&CMT_OC_CMTPOL_MASK) /*!< CMT_OC                                  */
#define CMT_OC_IROL_MASK                         (0x80U)                                             /*!< CMT_OC: IROL Mask                       */
#define CMT_OC_IROL_SHIFT                        (7U)                                                /*!< CMT_OC: IROL Position                   */
#define CMT_OC_IROL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_OC_IROL_SHIFT))&CMT_OC_IROL_MASK) /*!< CMT_OC                                  */
/* ------- MSC Bit Fields                           ------ */
#define CMT_MSC_MCGEN_MASK                       (0x1U)                                              /*!< CMT_MSC: MCGEN Mask                     */
#define CMT_MSC_MCGEN_SHIFT                      (0U)                                                /*!< CMT_MSC: MCGEN Position                 */
#define CMT_MSC_MCGEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_MCGEN_SHIFT))&CMT_MSC_MCGEN_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EOCIE_MASK                       (0x2U)                                              /*!< CMT_MSC: EOCIE Mask                     */
#define CMT_MSC_EOCIE_SHIFT                      (1U)                                                /*!< CMT_MSC: EOCIE Position                 */
#define CMT_MSC_EOCIE(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EOCIE_SHIFT))&CMT_MSC_EOCIE_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_FSK_MASK                         (0x4U)                                              /*!< CMT_MSC: FSK Mask                       */
#define CMT_MSC_FSK_SHIFT                        (2U)                                                /*!< CMT_MSC: FSK Position                   */
#define CMT_MSC_FSK(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_MSC_FSK_SHIFT))&CMT_MSC_FSK_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_BASE_MASK                        (0x8U)                                              /*!< CMT_MSC: BASE Mask                      */
#define CMT_MSC_BASE_SHIFT                       (3U)                                                /*!< CMT_MSC: BASE Position                  */
#define CMT_MSC_BASE(x)                          (((uint8_t)(((uint8_t)(x))<<CMT_MSC_BASE_SHIFT))&CMT_MSC_BASE_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EXSPC_MASK                       (0x10U)                                             /*!< CMT_MSC: EXSPC Mask                     */
#define CMT_MSC_EXSPC_SHIFT                      (4U)                                                /*!< CMT_MSC: EXSPC Position                 */
#define CMT_MSC_EXSPC(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EXSPC_SHIFT))&CMT_MSC_EXSPC_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_CMTDIV_MASK                      (0x60U)                                             /*!< CMT_MSC: CMTDIV Mask                    */
#define CMT_MSC_CMTDIV_SHIFT                     (5U)                                                /*!< CMT_MSC: CMTDIV Position                */
#define CMT_MSC_CMTDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_MSC_CMTDIV_SHIFT))&CMT_MSC_CMTDIV_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EOCF_MASK                        (0x80U)                                             /*!< CMT_MSC: EOCF Mask                      */
#define CMT_MSC_EOCF_SHIFT                       (7U)                                                /*!< CMT_MSC: EOCF Position                  */
#define CMT_MSC_EOCF(x)                          (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EOCF_SHIFT))&CMT_MSC_EOCF_MASK) /*!< CMT_MSC                                 */
/* ------- CMD1 Bit Fields                          ------ */
#define CMT_CMD1_MB_MASK                         (0xFFU)                                             /*!< CMT_CMD1: MB Mask                       */
#define CMT_CMD1_MB_SHIFT                        (0U)                                                /*!< CMT_CMD1: MB Position                   */
#define CMT_CMD1_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD1_MB_SHIFT))&CMT_CMD1_MB_MASK) /*!< CMT_CMD1                                */
/* ------- CMD2 Bit Fields                          ------ */
#define CMT_CMD2_MB_MASK                         (0xFFU)                                             /*!< CMT_CMD2: MB Mask                       */
#define CMT_CMD2_MB_SHIFT                        (0U)                                                /*!< CMT_CMD2: MB Position                   */
#define CMT_CMD2_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD2_MB_SHIFT))&CMT_CMD2_MB_MASK) /*!< CMT_CMD2                                */
/* ------- CMD3 Bit Fields                          ------ */
#define CMT_CMD3_SB_MASK                         (0xFFU)                                             /*!< CMT_CMD3: SB Mask                       */
#define CMT_CMD3_SB_SHIFT                        (0U)                                                /*!< CMT_CMD3: SB Position                   */
#define CMT_CMD3_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD3_SB_SHIFT))&CMT_CMD3_SB_MASK) /*!< CMT_CMD3                                */
/* ------- CMD4 Bit Fields                          ------ */
#define CMT_CMD4_SB_MASK                         (0xFFU)                                             /*!< CMT_CMD4: SB Mask                       */
#define CMT_CMD4_SB_SHIFT                        (0U)                                                /*!< CMT_CMD4: SB Position                   */
#define CMT_CMD4_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD4_SB_SHIFT))&CMT_CMD4_SB_MASK) /*!< CMT_CMD4                                */
/* ------- PPS Bit Fields                           ------ */
#define CMT_PPS_PPSDIV_MASK                      (0xFU)                                              /*!< CMT_PPS: PPSDIV Mask                    */
#define CMT_PPS_PPSDIV_SHIFT                     (0U)                                                /*!< CMT_PPS: PPSDIV Position                */
#define CMT_PPS_PPSDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_PPS_PPSDIV_SHIFT))&CMT_PPS_PPSDIV_MASK) /*!< CMT_PPS                                 */
/* ------- DMA Bit Fields                           ------ */
#define CMT_DMA_DMA_MASK                         (0x1U)                                              /*!< CMT_DMA: DMA Mask                       */
#define CMT_DMA_DMA_SHIFT                        (0U)                                                /*!< CMT_DMA: DMA Position                   */
#define CMT_DMA_DMA(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_DMA_DMA_SHIFT))&CMT_DMA_DMA_MASK) /*!< CMT_DMA                                 */
/**
 * @} */ /* End group CMT_Register_Masks_GROUP 
 */

/* CMT - Peripheral instance base addresses */
#define CMT_BasePtr                    0x40062000UL //!< Peripheral base address
#define CMT                            ((CMT_Type *) CMT_BasePtr) //!< Freescale base pointer
#define CMT_BASE_PTR                   (CMT) //!< Freescale style base pointer
/**
 * @} */ /* End group CMT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           CRC (file:CRC_0x40032000)            ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
/**
* @addtogroup CRC_structs_GROUP CRC struct
* @brief Struct for CRC
* @{
*/
typedef struct {                                /*       CRC Structure                                                */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DATA;                      /**< 0000: Data register                                                */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAL;               /**< 0000: DATAL register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATALL;           /**< 0000: DATALL register                                              */
               __IO uint8_t   DATALU;           /**< 0001: DATALU register                                              */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAH;               /**< 0002: DATAH register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATAHL;           /**< 0002: DATAHL register                                              */
               __IO uint8_t   DATAHU;           /**< 0003: DATAHU register                                              */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /**< 0004: Polynomial register                                          */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYL;              /**< 0004: GPOLYL register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYLL;          /**< 0004: GPOLYLL register                                             */
               __IO uint8_t   GPOLYLU;          /**< 0005: GPOLYLU register                                             */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYH;              /**< 0006: GPOLYH register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYHL;          /**< 0006: GPOLYHL register                                             */
               __IO uint8_t   GPOLYHU;          /**< 0007: GPOLYHU register                                             */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CTRL;                      /**< 0008: Control register                                             */
      struct {                                  /**< 0000: (size=0004)                                                  */
              uint8_t   RESERVED_6[3];         
         __IO uint8_t   CTRLHU;                 /**< 000B: Control register (byte access)                               */
      };
   };
} CRC_Type;

/**
 * @} */ /* End group CRC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CRC_Register_Masks_GROUP CRC Register Masks
* @brief Register Masks for CRC
* @{
*/
/* ------- DATA Bit Fields                          ------ */
#define CRC_DATA_LL_MASK                         (0xFFU)                                             /*!< CRC_DATA: LL Mask                       */
#define CRC_DATA_LL_SHIFT                        (0U)                                                /*!< CRC_DATA: LL Position                   */
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_LU_MASK                         (0xFF00U)                                           /*!< CRC_DATA: LU Mask                       */
#define CRC_DATA_LU_SHIFT                        (8U)                                                /*!< CRC_DATA: LU Position                   */
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_HL_MASK                         (0xFF0000U)                                         /*!< CRC_DATA: HL Mask                       */
#define CRC_DATA_HL_SHIFT                        (16U)                                               /*!< CRC_DATA: HL Position                   */
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK) /*!< CRC_DATA                                */
#define CRC_DATA_HU_MASK                         (0xFF000000U)                                       /*!< CRC_DATA: HU Mask                       */
#define CRC_DATA_HU_SHIFT                        (24U)                                               /*!< CRC_DATA: HU Position                   */
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK) /*!< CRC_DATA                                */
/* ------- DATAL Bit Fields                         ------ */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFU)                                           /*!< CRC_DATAL: DATAL Mask                   */
#define CRC_DATAL_DATAL_SHIFT                    (0U)                                                /*!< CRC_DATAL: DATAL Position               */
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK) /*!< CRC_DATAL                               */
/* ------- DATALL Bit Fields                        ------ */
#define CRC_DATALL_DATALL_MASK                   (0xFFU)                                             /*!< CRC_DATALL: DATALL Mask                 */
#define CRC_DATALL_DATALL_SHIFT                  (0U)                                                /*!< CRC_DATALL: DATALL Position             */
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK) /*!< CRC_DATALL                              */
/* ------- DATALU Bit Fields                        ------ */
#define CRC_DATALU_DATALU_MASK                   (0xFFU)                                             /*!< CRC_DATALU: DATALU Mask                 */
#define CRC_DATALU_DATALU_SHIFT                  (0U)                                                /*!< CRC_DATALU: DATALU Position             */
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK) /*!< CRC_DATALU                              */
/* ------- DATAH Bit Fields                         ------ */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFU)                                           /*!< CRC_DATAH: DATAH Mask                   */
#define CRC_DATAH_DATAH_SHIFT                    (0U)                                                /*!< CRC_DATAH: DATAH Position               */
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK) /*!< CRC_DATAH                               */
/* ------- DATAHL Bit Fields                        ------ */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFU)                                             /*!< CRC_DATAHL: DATAHL Mask                 */
#define CRC_DATAHL_DATAHL_SHIFT                  (0U)                                                /*!< CRC_DATAHL: DATAHL Position             */
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK) /*!< CRC_DATAHL                              */
/* ------- DATAHU Bit Fields                        ------ */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFU)                                             /*!< CRC_DATAHU: DATAHU Mask                 */
#define CRC_DATAHU_DATAHU_SHIFT                  (0U)                                                /*!< CRC_DATAHU: DATAHU Position             */
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK) /*!< CRC_DATAHU                              */
/* ------- GPOLY Bit Fields                         ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFU)                                           /*!< CRC_GPOLY: LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      (0U)                                                /*!< CRC_GPOLY: LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK) /*!< CRC_GPOLY                               */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000U)                                       /*!< CRC_GPOLY: HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     (16U)                                               /*!< CRC_GPOLY: HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK) /*!< CRC_GPOLY                               */
/* ------- GPOLYL Bit Fields                        ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFU)                                           /*!< CRC_GPOLYL: GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  (0U)                                                /*!< CRC_GPOLYL: GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK) /*!< CRC_GPOLYL                              */
/* ------- GPOLYLL Bit Fields                       ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFU)                                             /*!< CRC_GPOLYLL: GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                (0U)                                                /*!< CRC_GPOLYLL: GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK) /*!< CRC_GPOLYLL                             */
/* ------- GPOLYLU Bit Fields                       ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFU)                                             /*!< CRC_GPOLYLU: GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                (0U)                                                /*!< CRC_GPOLYLU: GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK) /*!< CRC_GPOLYLU                             */
/* ------- GPOLYH Bit Fields                        ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFU)                                           /*!< CRC_GPOLYH: GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  (0U)                                                /*!< CRC_GPOLYH: GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK) /*!< CRC_GPOLYH                              */
/* ------- GPOLYHL Bit Fields                       ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFU)                                             /*!< CRC_GPOLYHL: GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                (0U)                                                /*!< CRC_GPOLYHL: GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK) /*!< CRC_GPOLYHL                             */
/* ------- GPOLYHU Bit Fields                       ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFU)                                             /*!< CRC_GPOLYHU: GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                (0U)                                                /*!< CRC_GPOLYHU: GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK) /*!< CRC_GPOLYHU                             */
/* ------- CTRL Bit Fields                          ------ */
#define CRC_CTRL_TCRC_MASK                       (0x1000000U)                                        /*!< CRC_CTRL: TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      (24U)                                               /*!< CRC_CTRL: TCRC Position                 */
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TCRC_SHIFT))&CRC_CTRL_TCRC_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_WAS_MASK                        (0x2000000U)                                        /*!< CRC_CTRL: WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       (25U)                                               /*!< CRC_CTRL: WAS Position                  */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_WAS_SHIFT))&CRC_CTRL_WAS_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_FXOR_MASK                       (0x4000000U)                                        /*!< CRC_CTRL: FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      (26U)                                               /*!< CRC_CTRL: FXOR Position                 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_FXOR_SHIFT))&CRC_CTRL_FXOR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOTR_MASK                       (0x30000000U)                                       /*!< CRC_CTRL: TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      (28U)                                               /*!< CRC_CTRL: TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOT_MASK                        (0xC0000000U)                                       /*!< CRC_CTRL: TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       (30U)                                               /*!< CRC_CTRL: TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK) /*!< CRC_CTRL                                */
/* ------- CTRLHU Bit Fields                        ------ */
#define CRC_CTRLHU_TCRC_MASK                     (0x1U)                                              /*!< CRC_CTRLHU: TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    (0U)                                                /*!< CRC_CTRLHU: TCRC Position               */
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TCRC_SHIFT))&CRC_CTRLHU_TCRC_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_WAS_MASK                      (0x2U)                                              /*!< CRC_CTRLHU: WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     (1U)                                                /*!< CRC_CTRLHU: WAS Position                */
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_WAS_SHIFT))&CRC_CTRLHU_WAS_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_FXOR_MASK                     (0x4U)                                              /*!< CRC_CTRLHU: FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    (2U)                                                /*!< CRC_CTRLHU: FXOR Position               */
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_FXOR_SHIFT))&CRC_CTRLHU_FXOR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOTR_MASK                     (0x30U)                                             /*!< CRC_CTRLHU: TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    (4U)                                                /*!< CRC_CTRLHU: TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOT_MASK                      (0xC0U)                                             /*!< CRC_CTRLHU: TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     (6U)                                                /*!< CRC_CTRLHU: TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK) /*!< CRC_CTRLHU                              */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* CRC - Peripheral instance base addresses */
#define CRC_BasePtr                    0x40032000UL //!< Peripheral base address
#define CRC                            ((CRC_Type *) CRC_BasePtr) //!< Freescale base pointer
#define CRC_BASE_PTR                   (CRC) //!< Freescale style base pointer
/**
 * @} */ /* End group CRC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DAC_Peripheral_access_layer_GROUP DAC Peripheral Access Layer
* @brief C Struct for DAC
* @{
*/

/* ================================================================================ */
/* ================           DAC0 (file:DAC0_16CH_FIFO16)         ================ */
/* ================================================================================ */

/**
 * @brief 12-Bit Digital-to-Analog Converter
 */
/**
* @addtogroup DAC_structs_GROUP DAC struct
* @brief Struct for DAC
* @{
*/
typedef struct {                                /*       DAC0 Structure                                               */
   union {                                      /**< 0000: (size=0020)                                                  */
      struct {
         __IO uint8_t   DATL;                   /**< 0000: Data Low Register                                            */
         __IO uint8_t   DATH;                   /**< 0001: Data High Register                                           */
      } DAT[16];                                /**< 0000: (cluster: size=0x0020, 32)                                   */
      __IO uint16_t  DATA[16];                  /**< 0000: Data Register                                                */
   };
   __IO uint8_t   SR;                           /**< 0020: Status Register                                              */
   __IO uint8_t   C0;                           /**< 0021: Control Register 0                                           */
   __IO uint8_t   C1;                           /**< 0022: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0023: Control Register 2                                           */
} DAC_Type;

/**
 * @} */ /* End group DAC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DAC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DAC_Register_Masks_GROUP DAC Register Masks
* @brief Register Masks for DAC
* @{
*/
/* ------- DATL Bit Fields                          ------ */
#define DAC_DATL_DATA_MASK                       (0xFFU)                                             /*!< DAC0_DATL: DATA Mask                    */
#define DAC_DATL_DATA_SHIFT                      (0U)                                                /*!< DAC0_DATL: DATA Position                */
#define DAC_DATL_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA_SHIFT))&DAC_DATL_DATA_MASK) /*!< DAC0_DATL                               */
/* ------- DATH Bit Fields                          ------ */
#define DAC_DATH_DATA_MASK                       (0xFU)                                              /*!< DAC0_DATH: DATA Mask                    */
#define DAC_DATH_DATA_SHIFT                      (0U)                                                /*!< DAC0_DATH: DATA Position                */
#define DAC_DATH_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA_SHIFT))&DAC_DATH_DATA_MASK) /*!< DAC0_DATH                               */
/* ------- DATA Bit Fields                          ------ */
#define DAC_DATA_DATA_MASK                       (0xFFFU)                                            /*!< DAC0_DATA: DATA Mask                    */
#define DAC_DATA_DATA_SHIFT                      (0U)                                                /*!< DAC0_DATA: DATA Position                */
#define DAC_DATA_DATA(x)                         (((uint16_t)(((uint16_t)(x))<<DAC_DATA_DATA_SHIFT))&DAC_DATA_DATA_MASK) /*!< DAC0_DATA                               */
/* ------- SR Bit Fields                            ------ */
#define DAC_SR_DACBFRPBF_MASK                    (0x1U)                                              /*!< DAC0_SR: DACBFRPBF Mask                 */
#define DAC_SR_DACBFRPBF_SHIFT                   (0U)                                                /*!< DAC0_SR: DACBFRPBF Position             */
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPBF_SHIFT))&DAC_SR_DACBFRPBF_MASK) /*!< DAC0_SR                                 */
#define DAC_SR_DACBFRPTF_MASK                    (0x2U)                                              /*!< DAC0_SR: DACBFRPTF Mask                 */
#define DAC_SR_DACBFRPTF_SHIFT                   (1U)                                                /*!< DAC0_SR: DACBFRPTF Position             */
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPTF_SHIFT))&DAC_SR_DACBFRPTF_MASK) /*!< DAC0_SR                                 */
#define DAC_SR_DACBFWMF_MASK                     (0x4U)                                              /*!< DAC0_SR: DACBFWMF Mask                  */
#define DAC_SR_DACBFWMF_SHIFT                    (2U)                                                /*!< DAC0_SR: DACBFWMF Position              */
#define DAC_SR_DACBFWMF(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFWMF_SHIFT))&DAC_SR_DACBFWMF_MASK) /*!< DAC0_SR                                 */
/* ------- C0 Bit Fields                            ------ */
#define DAC_C0_DACBBIEN_MASK                     (0x1U)                                              /*!< DAC0_C0: DACBBIEN Mask                  */
#define DAC_C0_DACBBIEN_SHIFT                    (0U)                                                /*!< DAC0_C0: DACBBIEN Position              */
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBBIEN_SHIFT))&DAC_C0_DACBBIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACBTIEN_MASK                     (0x2U)                                              /*!< DAC0_C0: DACBTIEN Mask                  */
#define DAC_C0_DACBTIEN_SHIFT                    (1U)                                                /*!< DAC0_C0: DACBTIEN Position              */
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBTIEN_SHIFT))&DAC_C0_DACBTIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACBWIEN_MASK                     (0x4U)                                              /*!< DAC0_C0: DACBWIEN Mask                  */
#define DAC_C0_DACBWIEN_SHIFT                    (2U)                                                /*!< DAC0_C0: DACBWIEN Position              */
#define DAC_C0_DACBWIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBWIEN_SHIFT))&DAC_C0_DACBWIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_LPEN_MASK                         (0x8U)                                              /*!< DAC0_C0: LPEN Mask                      */
#define DAC_C0_LPEN_SHIFT                        (3U)                                                /*!< DAC0_C0: LPEN Position                  */
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x))<<DAC_C0_LPEN_SHIFT))&DAC_C0_LPEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACSWTRG_MASK                     (0x10U)                                             /*!< DAC0_C0: DACSWTRG Mask                  */
#define DAC_C0_DACSWTRG_SHIFT                    (4U)                                                /*!< DAC0_C0: DACSWTRG Position              */
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACSWTRG_SHIFT))&DAC_C0_DACSWTRG_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACTRGSEL_MASK                    (0x20U)                                             /*!< DAC0_C0: DACTRGSEL Mask                 */
#define DAC_C0_DACTRGSEL_SHIFT                   (5U)                                                /*!< DAC0_C0: DACTRGSEL Position             */
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACTRGSEL_SHIFT))&DAC_C0_DACTRGSEL_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACRFS_MASK                       (0x40U)                                             /*!< DAC0_C0: DACRFS Mask                    */
#define DAC_C0_DACRFS_SHIFT                      (6U)                                                /*!< DAC0_C0: DACRFS Position                */
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACRFS_SHIFT))&DAC_C0_DACRFS_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACEN_MASK                        (0x80U)                                             /*!< DAC0_C0: DACEN Mask                     */
#define DAC_C0_DACEN_SHIFT                       (7U)                                                /*!< DAC0_C0: DACEN Position                 */
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACEN_SHIFT))&DAC_C0_DACEN_MASK) /*!< DAC0_C0                                 */
/* ------- C1 Bit Fields                            ------ */
#define DAC_C1_DACBFEN_MASK                      (0x1U)                                              /*!< DAC0_C1: DACBFEN Mask                   */
#define DAC_C1_DACBFEN_SHIFT                     (0U)                                                /*!< DAC0_C1: DACBFEN Position               */
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFEN_SHIFT))&DAC_C1_DACBFEN_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DACBFMD_MASK                      (0x6U)                                              /*!< DAC0_C1: DACBFMD Mask                   */
#define DAC_C1_DACBFMD_SHIFT                     (1U)                                                /*!< DAC0_C1: DACBFMD Position               */
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DACBFWM_MASK                      (0x18U)                                             /*!< DAC0_C1: DACBFWM Mask                   */
#define DAC_C1_DACBFWM_SHIFT                     (3U)                                                /*!< DAC0_C1: DACBFWM Position               */
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DMAEN_MASK                        (0x80U)                                             /*!< DAC0_C1: DMAEN Mask                     */
#define DAC_C1_DMAEN_SHIFT                       (7U)                                                /*!< DAC0_C1: DMAEN Position                 */
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C1_DMAEN_SHIFT))&DAC_C1_DMAEN_MASK) /*!< DAC0_C1                                 */
/* ------- C2 Bit Fields                            ------ */
#define DAC_C2_DACBFUP_MASK                      (0xFU)                                              /*!< DAC0_C2: DACBFUP Mask                   */
#define DAC_C2_DACBFUP_SHIFT                     (0U)                                                /*!< DAC0_C2: DACBFUP Position               */
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK) /*!< DAC0_C2                                 */
#define DAC_C2_DACBFRP_MASK                      (0xF0U)                                             /*!< DAC0_C2: DACBFRP Mask                   */
#define DAC_C2_DACBFRP_SHIFT                     (4U)                                                /*!< DAC0_C2: DACBFRP Position               */
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK) /*!< DAC0_C2                                 */
/**
 * @} */ /* End group DAC_Register_Masks_GROUP 
 */

/* DAC0 - Peripheral instance base addresses */
#define DAC0_BasePtr                   0x4003F000UL //!< Peripheral base address
#define DAC0                           ((DAC_Type *) DAC0_BasePtr) //!< Freescale base pointer
#define DAC0_BASE_PTR                  (DAC0) //!< Freescale style base pointer
/**
 * @} */ /* End group DAC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA0_Peripheral_access_layer_GROUP DMA0 Peripheral Access Layer
* @brief C Struct for DMA0
* @{
*/

/* ================================================================================ */
/* ================           DMA0 (file:DMA0_16CH)                ================ */
/* ================================================================================ */

/**
 * @brief Enhanced direct memory access controller
 */
/**
* @addtogroup DMA0_structs_GROUP DMA0 struct
* @brief Struct for DMA0
* @{
*/
typedef struct {                                /*       DMA0 Structure                                               */
   __IO uint32_t  CR;                           /**< 0000: Control Register                                             */
   __I  uint32_t  ES;                           /**< 0004: Error Status Register                                        */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  ERQ;                          /**< 000C: Enable Request Register                                      */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  EEI;                          /**< 0014: Enable Error Interrupt Register                              */
   __O  uint8_t   CEEI;                         /**< 0018: Clear Enable Error Interrupt Register                        */
   __O  uint8_t   SEEI;                         /**< 0019: Set Enable Error Interrupt Register                          */
   __O  uint8_t   CERQ;                         /**< 001A: Clear Enable Request Register                                */
   __O  uint8_t   SERQ;                         /**< 001B: Set Enable Request Register                                  */
   __O  uint8_t   CDNE;                         /**< 001C: Clear DONE Status Bit Register                               */
   __O  uint8_t   SSRT;                         /**< 001D: Set START Bit Register                                       */
   __O  uint8_t   CERR;                         /**< 001E: Clear Error Register                                         */
   __O  uint8_t   CINT;                         /**< 001F: Clear Interrupt Request Register                             */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  INT;                          /**< 0024: Interrupt Request Register                                   */
        uint8_t   RESERVED_3[4];               
   __IO uint32_t  ERR;                          /**< 002C: Error Register                                               */
        uint8_t   RESERVED_4[4];               
   __I  uint32_t  HRS;                          /**< 0034: Hardware Request Status Register                             */
        uint8_t   RESERVED_5[200];             
   __IO uint8_t   DCHPRI3;                      /**< 0100: Channel 3 Priority Register                                  */
   __IO uint8_t   DCHPRI2;                      /**< 0101: Channel 2 Priority Register                                  */
   __IO uint8_t   DCHPRI1;                      /**< 0102: Channel 1 Priority Register                                  */
   __IO uint8_t   DCHPRI0;                      /**< 0103: Channel 0 Priority Register                                  */
   __IO uint8_t   DCHPRI7;                      /**< 0104: Channel 7 Priority Register                                  */
   __IO uint8_t   DCHPRI6;                      /**< 0105: Channel 6 Priority Register                                  */
   __IO uint8_t   DCHPRI5;                      /**< 0106: Channel 5 Priority Register                                  */
   __IO uint8_t   DCHPRI4;                      /**< 0107: Channel 4 Priority Register                                  */
   __IO uint8_t   DCHPRI11;                     /**< 0108: Channel 11 Priority Register                                 */
   __IO uint8_t   DCHPRI10;                     /**< 0109: Channel 10 Priority Register                                 */
   __IO uint8_t   DCHPRI9;                      /**< 010A: Channel 9 Priority Register                                  */
   __IO uint8_t   DCHPRI8;                      /**< 010B: Channel 8 Priority Register                                  */
   __IO uint8_t   DCHPRI15;                     /**< 010C: Channel 15 Priority Register                                 */
   __IO uint8_t   DCHPRI14;                     /**< 010D: Channel 14 Priority Register                                 */
   __IO uint8_t   DCHPRI13;                     /**< 010E: Channel 13 Priority Register                                 */
   __IO uint8_t   DCHPRI12;                     /**< 010F: Channel 12 Priority Register                                 */
        uint8_t   RESERVED_6[3824];            
   struct {
      __IO uint32_t  SADDR;                     /**< 1000: Source Address                                               */
      __IO uint16_t  SOFF;                      /**< 1004: Signed Source Address Offset                                 */
      __IO uint16_t  ATTR;                      /**< 1006: Transfer Attributes                                          */
      union {                                   /**< 1000: (size=0004)                                                  */
         __IO uint32_t  NBYTES_MLNO;            /**< 1008: Minor Byte Count (Minor Loop Disabled)                       */
         __IO uint32_t  NBYTES_MLOFFNO;         /**< 1008: Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled) */
         __IO uint32_t  NBYTES_MLOFFYES;        /**< 1008: Signed Minor Loop Offset (Minor Loop and Offset Enabled)     */
      };
      __IO uint32_t  SLAST;                     /**< 100C: Last Source Address Adjustment                               */
      __IO uint32_t  DADDR;                     /**< 1010: Destination Address                                          */
      __IO uint16_t  DOFF;                      /**< 1014: Signed Destination Address Offset                            */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  CITER_ELINKNO;          /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  CITER_ELINKYES;         /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
      __IO uint32_t  DLASTSGA;                  /**< 1018: Last Destination Address Adjustment/Scatter Gather Address   */
      __IO uint16_t  CSR;                       /**< 101C: Control and Status                                           */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  BITER_ELINKNO;          /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  BITER_ELINKYES;         /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
   } TCD[16];                                   /**< 1000: (cluster: size=0x0200, 512)                                  */
} DMA_Type;

/**
 * @} */ /* End group DMA0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA0_Register_Masks_GROUP DMA0 Register Masks
* @brief Register Masks for DMA0
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define DMA_CR_EDBG_MASK                         (0x2U)                                              /*!< DMA0_CR: EDBG Mask                      */
#define DMA_CR_EDBG_SHIFT                        (1U)                                                /*!< DMA0_CR: EDBG Position                  */
#define DMA_CR_EDBG(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EDBG_SHIFT))&DMA_CR_EDBG_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_ERCA_MASK                         (0x4U)                                              /*!< DMA0_CR: ERCA Mask                      */
#define DMA_CR_ERCA_SHIFT                        (2U)                                                /*!< DMA0_CR: ERCA Position                  */
#define DMA_CR_ERCA(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_ERCA_SHIFT))&DMA_CR_ERCA_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_HOE_MASK                          (0x10U)                                             /*!< DMA0_CR: HOE Mask                       */
#define DMA_CR_HOE_SHIFT                         (4U)                                                /*!< DMA0_CR: HOE Position                   */
#define DMA_CR_HOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_HOE_SHIFT))&DMA_CR_HOE_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_HALT_MASK                         (0x20U)                                             /*!< DMA0_CR: HALT Mask                      */
#define DMA_CR_HALT_SHIFT                        (5U)                                                /*!< DMA0_CR: HALT Position                  */
#define DMA_CR_HALT(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_HALT_SHIFT))&DMA_CR_HALT_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_CLM_MASK                          (0x40U)                                             /*!< DMA0_CR: CLM Mask                       */
#define DMA_CR_CLM_SHIFT                         (6U)                                                /*!< DMA0_CR: CLM Position                   */
#define DMA_CR_CLM(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_CLM_SHIFT))&DMA_CR_CLM_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_EMLM_MASK                         (0x80U)                                             /*!< DMA0_CR: EMLM Mask                      */
#define DMA_CR_EMLM_SHIFT                        (7U)                                                /*!< DMA0_CR: EMLM Position                  */
#define DMA_CR_EMLM(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EMLM_SHIFT))&DMA_CR_EMLM_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_ECX_MASK                          (0x10000U)                                          /*!< DMA0_CR: ECX Mask                       */
#define DMA_CR_ECX_SHIFT                         (16U)                                               /*!< DMA0_CR: ECX Position                   */
#define DMA_CR_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_ECX_SHIFT))&DMA_CR_ECX_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_CX_MASK                           (0x20000U)                                          /*!< DMA0_CR: CX Mask                        */
#define DMA_CR_CX_SHIFT                          (17U)                                               /*!< DMA0_CR: CX Position                    */
#define DMA_CR_CX(x)                             (((uint32_t)(((uint32_t)(x))<<DMA_CR_CX_SHIFT))&DMA_CR_CX_MASK) /*!< DMA0_CR                                 */
/* ------- ES Bit Fields                            ------ */
#define DMA_ES_DBE_MASK                          (0x1U)                                              /*!< DMA0_ES: DBE Mask                       */
#define DMA_ES_DBE_SHIFT                         (0U)                                                /*!< DMA0_ES: DBE Position                   */
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DBE_SHIFT))&DMA_ES_DBE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SBE_MASK                          (0x2U)                                              /*!< DMA0_ES: SBE Mask                       */
#define DMA_ES_SBE_SHIFT                         (1U)                                                /*!< DMA0_ES: SBE Position                   */
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SBE_SHIFT))&DMA_ES_SBE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SGE_MASK                          (0x4U)                                              /*!< DMA0_ES: SGE Mask                       */
#define DMA_ES_SGE_SHIFT                         (2U)                                                /*!< DMA0_ES: SGE Position                   */
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SGE_SHIFT))&DMA_ES_SGE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_NCE_MASK                          (0x8U)                                              /*!< DMA0_ES: NCE Mask                       */
#define DMA_ES_NCE_SHIFT                         (3U)                                                /*!< DMA0_ES: NCE Position                   */
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_NCE_SHIFT))&DMA_ES_NCE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_DOE_MASK                          (0x10U)                                             /*!< DMA0_ES: DOE Mask                       */
#define DMA_ES_DOE_SHIFT                         (4U)                                                /*!< DMA0_ES: DOE Position                   */
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DOE_SHIFT))&DMA_ES_DOE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_DAE_MASK                          (0x20U)                                             /*!< DMA0_ES: DAE Mask                       */
#define DMA_ES_DAE_SHIFT                         (5U)                                                /*!< DMA0_ES: DAE Position                   */
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DAE_SHIFT))&DMA_ES_DAE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SOE_MASK                          (0x40U)                                             /*!< DMA0_ES: SOE Mask                       */
#define DMA_ES_SOE_SHIFT                         (6U)                                                /*!< DMA0_ES: SOE Position                   */
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SOE_SHIFT))&DMA_ES_SOE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SAE_MASK                          (0x80U)                                             /*!< DMA0_ES: SAE Mask                       */
#define DMA_ES_SAE_SHIFT                         (7U)                                                /*!< DMA0_ES: SAE Position                   */
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SAE_SHIFT))&DMA_ES_SAE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_ERRCHN_MASK                       (0xF00U)                                            /*!< DMA0_ES: ERRCHN Mask                    */
#define DMA_ES_ERRCHN_SHIFT                      (8U)                                                /*!< DMA0_ES: ERRCHN Position                */
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_CPE_MASK                          (0x4000U)                                           /*!< DMA0_ES: CPE Mask                       */
#define DMA_ES_CPE_SHIFT                         (14U)                                               /*!< DMA0_ES: CPE Position                   */
#define DMA_ES_CPE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_CPE_SHIFT))&DMA_ES_CPE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_ECX_MASK                          (0x10000U)                                          /*!< DMA0_ES: ECX Mask                       */
#define DMA_ES_ECX_SHIFT                         (16U)                                               /*!< DMA0_ES: ECX Position                   */
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_ECX_SHIFT))&DMA_ES_ECX_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_VLD_MASK                          (0x80000000U)                                       /*!< DMA0_ES: VLD Mask                       */
#define DMA_ES_VLD_SHIFT                         (31U)                                               /*!< DMA0_ES: VLD Position                   */
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_VLD_SHIFT))&DMA_ES_VLD_MASK) /*!< DMA0_ES                                 */
/* ------- ERQ Bit Fields                           ------ */
#define DMA_ERQ_ERQ0_MASK                        (0x1U)                                              /*!< DMA0_ERQ: ERQ0 Mask                     */
#define DMA_ERQ_ERQ0_SHIFT                       (0U)                                                /*!< DMA0_ERQ: ERQ0 Position                 */
#define DMA_ERQ_ERQ0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ0_SHIFT))&DMA_ERQ_ERQ0_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ1_MASK                        (0x2U)                                              /*!< DMA0_ERQ: ERQ1 Mask                     */
#define DMA_ERQ_ERQ1_SHIFT                       (1U)                                                /*!< DMA0_ERQ: ERQ1 Position                 */
#define DMA_ERQ_ERQ1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ1_SHIFT))&DMA_ERQ_ERQ1_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ2_MASK                        (0x4U)                                              /*!< DMA0_ERQ: ERQ2 Mask                     */
#define DMA_ERQ_ERQ2_SHIFT                       (2U)                                                /*!< DMA0_ERQ: ERQ2 Position                 */
#define DMA_ERQ_ERQ2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ2_SHIFT))&DMA_ERQ_ERQ2_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ3_MASK                        (0x8U)                                              /*!< DMA0_ERQ: ERQ3 Mask                     */
#define DMA_ERQ_ERQ3_SHIFT                       (3U)                                                /*!< DMA0_ERQ: ERQ3 Position                 */
#define DMA_ERQ_ERQ3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ3_SHIFT))&DMA_ERQ_ERQ3_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ4_MASK                        (0x10U)                                             /*!< DMA0_ERQ: ERQ4 Mask                     */
#define DMA_ERQ_ERQ4_SHIFT                       (4U)                                                /*!< DMA0_ERQ: ERQ4 Position                 */
#define DMA_ERQ_ERQ4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ4_SHIFT))&DMA_ERQ_ERQ4_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ5_MASK                        (0x20U)                                             /*!< DMA0_ERQ: ERQ5 Mask                     */
#define DMA_ERQ_ERQ5_SHIFT                       (5U)                                                /*!< DMA0_ERQ: ERQ5 Position                 */
#define DMA_ERQ_ERQ5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ5_SHIFT))&DMA_ERQ_ERQ5_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ6_MASK                        (0x40U)                                             /*!< DMA0_ERQ: ERQ6 Mask                     */
#define DMA_ERQ_ERQ6_SHIFT                       (6U)                                                /*!< DMA0_ERQ: ERQ6 Position                 */
#define DMA_ERQ_ERQ6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ6_SHIFT))&DMA_ERQ_ERQ6_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ7_MASK                        (0x80U)                                             /*!< DMA0_ERQ: ERQ7 Mask                     */
#define DMA_ERQ_ERQ7_SHIFT                       (7U)                                                /*!< DMA0_ERQ: ERQ7 Position                 */
#define DMA_ERQ_ERQ7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ7_SHIFT))&DMA_ERQ_ERQ7_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ8_MASK                        (0x100U)                                            /*!< DMA0_ERQ: ERQ8 Mask                     */
#define DMA_ERQ_ERQ8_SHIFT                       (8U)                                                /*!< DMA0_ERQ: ERQ8 Position                 */
#define DMA_ERQ_ERQ8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ8_SHIFT))&DMA_ERQ_ERQ8_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ9_MASK                        (0x200U)                                            /*!< DMA0_ERQ: ERQ9 Mask                     */
#define DMA_ERQ_ERQ9_SHIFT                       (9U)                                                /*!< DMA0_ERQ: ERQ9 Position                 */
#define DMA_ERQ_ERQ9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ9_SHIFT))&DMA_ERQ_ERQ9_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ10_MASK                       (0x400U)                                            /*!< DMA0_ERQ: ERQ10 Mask                    */
#define DMA_ERQ_ERQ10_SHIFT                      (10U)                                               /*!< DMA0_ERQ: ERQ10 Position                */
#define DMA_ERQ_ERQ10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ10_SHIFT))&DMA_ERQ_ERQ10_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ11_MASK                       (0x800U)                                            /*!< DMA0_ERQ: ERQ11 Mask                    */
#define DMA_ERQ_ERQ11_SHIFT                      (11U)                                               /*!< DMA0_ERQ: ERQ11 Position                */
#define DMA_ERQ_ERQ11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ11_SHIFT))&DMA_ERQ_ERQ11_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ12_MASK                       (0x1000U)                                           /*!< DMA0_ERQ: ERQ12 Mask                    */
#define DMA_ERQ_ERQ12_SHIFT                      (12U)                                               /*!< DMA0_ERQ: ERQ12 Position                */
#define DMA_ERQ_ERQ12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ12_SHIFT))&DMA_ERQ_ERQ12_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ13_MASK                       (0x2000U)                                           /*!< DMA0_ERQ: ERQ13 Mask                    */
#define DMA_ERQ_ERQ13_SHIFT                      (13U)                                               /*!< DMA0_ERQ: ERQ13 Position                */
#define DMA_ERQ_ERQ13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ13_SHIFT))&DMA_ERQ_ERQ13_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ14_MASK                       (0x4000U)                                           /*!< DMA0_ERQ: ERQ14 Mask                    */
#define DMA_ERQ_ERQ14_SHIFT                      (14U)                                               /*!< DMA0_ERQ: ERQ14 Position                */
#define DMA_ERQ_ERQ14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ14_SHIFT))&DMA_ERQ_ERQ14_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ15_MASK                       (0x8000U)                                           /*!< DMA0_ERQ: ERQ15 Mask                    */
#define DMA_ERQ_ERQ15_SHIFT                      (15U)                                               /*!< DMA0_ERQ: ERQ15 Position                */
#define DMA_ERQ_ERQ15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ15_SHIFT))&DMA_ERQ_ERQ15_MASK) /*!< DMA0_ERQ                                */
/* ------- EEI Bit Fields                           ------ */
#define DMA_EEI_EEI0_MASK                        (0x1U)                                              /*!< DMA0_EEI: EEI0 Mask                     */
#define DMA_EEI_EEI0_SHIFT                       (0U)                                                /*!< DMA0_EEI: EEI0 Position                 */
#define DMA_EEI_EEI0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI0_SHIFT))&DMA_EEI_EEI0_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI1_MASK                        (0x2U)                                              /*!< DMA0_EEI: EEI1 Mask                     */
#define DMA_EEI_EEI1_SHIFT                       (1U)                                                /*!< DMA0_EEI: EEI1 Position                 */
#define DMA_EEI_EEI1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI1_SHIFT))&DMA_EEI_EEI1_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI2_MASK                        (0x4U)                                              /*!< DMA0_EEI: EEI2 Mask                     */
#define DMA_EEI_EEI2_SHIFT                       (2U)                                                /*!< DMA0_EEI: EEI2 Position                 */
#define DMA_EEI_EEI2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI2_SHIFT))&DMA_EEI_EEI2_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI3_MASK                        (0x8U)                                              /*!< DMA0_EEI: EEI3 Mask                     */
#define DMA_EEI_EEI3_SHIFT                       (3U)                                                /*!< DMA0_EEI: EEI3 Position                 */
#define DMA_EEI_EEI3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI3_SHIFT))&DMA_EEI_EEI3_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI4_MASK                        (0x10U)                                             /*!< DMA0_EEI: EEI4 Mask                     */
#define DMA_EEI_EEI4_SHIFT                       (4U)                                                /*!< DMA0_EEI: EEI4 Position                 */
#define DMA_EEI_EEI4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI4_SHIFT))&DMA_EEI_EEI4_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI5_MASK                        (0x20U)                                             /*!< DMA0_EEI: EEI5 Mask                     */
#define DMA_EEI_EEI5_SHIFT                       (5U)                                                /*!< DMA0_EEI: EEI5 Position                 */
#define DMA_EEI_EEI5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI5_SHIFT))&DMA_EEI_EEI5_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI6_MASK                        (0x40U)                                             /*!< DMA0_EEI: EEI6 Mask                     */
#define DMA_EEI_EEI6_SHIFT                       (6U)                                                /*!< DMA0_EEI: EEI6 Position                 */
#define DMA_EEI_EEI6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI6_SHIFT))&DMA_EEI_EEI6_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI7_MASK                        (0x80U)                                             /*!< DMA0_EEI: EEI7 Mask                     */
#define DMA_EEI_EEI7_SHIFT                       (7U)                                                /*!< DMA0_EEI: EEI7 Position                 */
#define DMA_EEI_EEI7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI7_SHIFT))&DMA_EEI_EEI7_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI8_MASK                        (0x100U)                                            /*!< DMA0_EEI: EEI8 Mask                     */
#define DMA_EEI_EEI8_SHIFT                       (8U)                                                /*!< DMA0_EEI: EEI8 Position                 */
#define DMA_EEI_EEI8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI8_SHIFT))&DMA_EEI_EEI8_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI9_MASK                        (0x200U)                                            /*!< DMA0_EEI: EEI9 Mask                     */
#define DMA_EEI_EEI9_SHIFT                       (9U)                                                /*!< DMA0_EEI: EEI9 Position                 */
#define DMA_EEI_EEI9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI9_SHIFT))&DMA_EEI_EEI9_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI10_MASK                       (0x400U)                                            /*!< DMA0_EEI: EEI10 Mask                    */
#define DMA_EEI_EEI10_SHIFT                      (10U)                                               /*!< DMA0_EEI: EEI10 Position                */
#define DMA_EEI_EEI10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI10_SHIFT))&DMA_EEI_EEI10_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI11_MASK                       (0x800U)                                            /*!< DMA0_EEI: EEI11 Mask                    */
#define DMA_EEI_EEI11_SHIFT                      (11U)                                               /*!< DMA0_EEI: EEI11 Position                */
#define DMA_EEI_EEI11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI11_SHIFT))&DMA_EEI_EEI11_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI12_MASK                       (0x1000U)                                           /*!< DMA0_EEI: EEI12 Mask                    */
#define DMA_EEI_EEI12_SHIFT                      (12U)                                               /*!< DMA0_EEI: EEI12 Position                */
#define DMA_EEI_EEI12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI12_SHIFT))&DMA_EEI_EEI12_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI13_MASK                       (0x2000U)                                           /*!< DMA0_EEI: EEI13 Mask                    */
#define DMA_EEI_EEI13_SHIFT                      (13U)                                               /*!< DMA0_EEI: EEI13 Position                */
#define DMA_EEI_EEI13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI13_SHIFT))&DMA_EEI_EEI13_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI14_MASK                       (0x4000U)                                           /*!< DMA0_EEI: EEI14 Mask                    */
#define DMA_EEI_EEI14_SHIFT                      (14U)                                               /*!< DMA0_EEI: EEI14 Position                */
#define DMA_EEI_EEI14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI14_SHIFT))&DMA_EEI_EEI14_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI15_MASK                       (0x8000U)                                           /*!< DMA0_EEI: EEI15 Mask                    */
#define DMA_EEI_EEI15_SHIFT                      (15U)                                               /*!< DMA0_EEI: EEI15 Position                */
#define DMA_EEI_EEI15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI15_SHIFT))&DMA_EEI_EEI15_MASK) /*!< DMA0_EEI                                */
/* ------- CEEI Bit Fields                          ------ */
#define DMA_CEEI_CEEI_MASK                       (0xFU)                                              /*!< DMA0_CEEI: CEEI Mask                    */
#define DMA_CEEI_CEEI_SHIFT                      (0U)                                                /*!< DMA0_CEEI: CEEI Position                */
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK) /*!< DMA0_CEEI                               */
#define DMA_CEEI_CAEE_MASK                       (0x40U)                                             /*!< DMA0_CEEI: CAEE Mask                    */
#define DMA_CEEI_CAEE_SHIFT                      (6U)                                                /*!< DMA0_CEEI: CAEE Position                */
#define DMA_CEEI_CAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CAEE_SHIFT))&DMA_CEEI_CAEE_MASK) /*!< DMA0_CEEI                               */
#define DMA_CEEI_NOP_MASK                        (0x80U)                                             /*!< DMA0_CEEI: NOP Mask                     */
#define DMA_CEEI_NOP_SHIFT                       (7U)                                                /*!< DMA0_CEEI: NOP Position                 */
#define DMA_CEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_NOP_SHIFT))&DMA_CEEI_NOP_MASK) /*!< DMA0_CEEI                               */
/* ------- SEEI Bit Fields                          ------ */
#define DMA_SEEI_SEEI_MASK                       (0xFU)                                              /*!< DMA0_SEEI: SEEI Mask                    */
#define DMA_SEEI_SEEI_SHIFT                      (0U)                                                /*!< DMA0_SEEI: SEEI Position                */
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK) /*!< DMA0_SEEI                               */
#define DMA_SEEI_SAEE_MASK                       (0x40U)                                             /*!< DMA0_SEEI: SAEE Mask                    */
#define DMA_SEEI_SAEE_SHIFT                      (6U)                                                /*!< DMA0_SEEI: SAEE Position                */
#define DMA_SEEI_SAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SAEE_SHIFT))&DMA_SEEI_SAEE_MASK) /*!< DMA0_SEEI                               */
#define DMA_SEEI_NOP_MASK                        (0x80U)                                             /*!< DMA0_SEEI: NOP Mask                     */
#define DMA_SEEI_NOP_SHIFT                       (7U)                                                /*!< DMA0_SEEI: NOP Position                 */
#define DMA_SEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_NOP_SHIFT))&DMA_SEEI_NOP_MASK) /*!< DMA0_SEEI                               */
/* ------- CERQ Bit Fields                          ------ */
#define DMA_CERQ_CERQ_MASK                       (0xFU)                                              /*!< DMA0_CERQ: CERQ Mask                    */
#define DMA_CERQ_CERQ_SHIFT                      (0U)                                                /*!< DMA0_CERQ: CERQ Position                */
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK) /*!< DMA0_CERQ                               */
#define DMA_CERQ_CAER_MASK                       (0x40U)                                             /*!< DMA0_CERQ: CAER Mask                    */
#define DMA_CERQ_CAER_SHIFT                      (6U)                                                /*!< DMA0_CERQ: CAER Position                */
#define DMA_CERQ_CAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CAER_SHIFT))&DMA_CERQ_CAER_MASK) /*!< DMA0_CERQ                               */
#define DMA_CERQ_NOP_MASK                        (0x80U)                                             /*!< DMA0_CERQ: NOP Mask                     */
#define DMA_CERQ_NOP_SHIFT                       (7U)                                                /*!< DMA0_CERQ: NOP Position                 */
#define DMA_CERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_NOP_SHIFT))&DMA_CERQ_NOP_MASK) /*!< DMA0_CERQ                               */
/* ------- SERQ Bit Fields                          ------ */
#define DMA_SERQ_SERQ_MASK                       (0xFU)                                              /*!< DMA0_SERQ: SERQ Mask                    */
#define DMA_SERQ_SERQ_SHIFT                      (0U)                                                /*!< DMA0_SERQ: SERQ Position                */
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK) /*!< DMA0_SERQ                               */
#define DMA_SERQ_SAER_MASK                       (0x40U)                                             /*!< DMA0_SERQ: SAER Mask                    */
#define DMA_SERQ_SAER_SHIFT                      (6U)                                                /*!< DMA0_SERQ: SAER Position                */
#define DMA_SERQ_SAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SAER_SHIFT))&DMA_SERQ_SAER_MASK) /*!< DMA0_SERQ                               */
#define DMA_SERQ_NOP_MASK                        (0x80U)                                             /*!< DMA0_SERQ: NOP Mask                     */
#define DMA_SERQ_NOP_SHIFT                       (7U)                                                /*!< DMA0_SERQ: NOP Position                 */
#define DMA_SERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_NOP_SHIFT))&DMA_SERQ_NOP_MASK) /*!< DMA0_SERQ                               */
/* ------- CDNE Bit Fields                          ------ */
#define DMA_CDNE_CDNE_MASK                       (0xFU)                                              /*!< DMA0_CDNE: CDNE Mask                    */
#define DMA_CDNE_CDNE_SHIFT                      (0U)                                                /*!< DMA0_CDNE: CDNE Position                */
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK) /*!< DMA0_CDNE                               */
#define DMA_CDNE_CADN_MASK                       (0x40U)                                             /*!< DMA0_CDNE: CADN Mask                    */
#define DMA_CDNE_CADN_SHIFT                      (6U)                                                /*!< DMA0_CDNE: CADN Position                */
#define DMA_CDNE_CADN(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CADN_SHIFT))&DMA_CDNE_CADN_MASK) /*!< DMA0_CDNE                               */
#define DMA_CDNE_NOP_MASK                        (0x80U)                                             /*!< DMA0_CDNE: NOP Mask                     */
#define DMA_CDNE_NOP_SHIFT                       (7U)                                                /*!< DMA0_CDNE: NOP Position                 */
#define DMA_CDNE_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_NOP_SHIFT))&DMA_CDNE_NOP_MASK) /*!< DMA0_CDNE                               */
/* ------- SSRT Bit Fields                          ------ */
#define DMA_SSRT_SSRT_MASK                       (0xFU)                                              /*!< DMA0_SSRT: SSRT Mask                    */
#define DMA_SSRT_SSRT_SHIFT                      (0U)                                                /*!< DMA0_SSRT: SSRT Position                */
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK) /*!< DMA0_SSRT                               */
#define DMA_SSRT_SAST_MASK                       (0x40U)                                             /*!< DMA0_SSRT: SAST Mask                    */
#define DMA_SSRT_SAST_SHIFT                      (6U)                                                /*!< DMA0_SSRT: SAST Position                */
#define DMA_SSRT_SAST(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SAST_SHIFT))&DMA_SSRT_SAST_MASK) /*!< DMA0_SSRT                               */
#define DMA_SSRT_NOP_MASK                        (0x80U)                                             /*!< DMA0_SSRT: NOP Mask                     */
#define DMA_SSRT_NOP_SHIFT                       (7U)                                                /*!< DMA0_SSRT: NOP Position                 */
#define DMA_SSRT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_NOP_SHIFT))&DMA_SSRT_NOP_MASK) /*!< DMA0_SSRT                               */
/* ------- CERR Bit Fields                          ------ */
#define DMA_CERR_CERR_MASK                       (0xFU)                                              /*!< DMA0_CERR: CERR Mask                    */
#define DMA_CERR_CERR_SHIFT                      (0U)                                                /*!< DMA0_CERR: CERR Position                */
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK) /*!< DMA0_CERR                               */
#define DMA_CERR_CAEI_MASK                       (0x40U)                                             /*!< DMA0_CERR: CAEI Mask                    */
#define DMA_CERR_CAEI_SHIFT                      (6U)                                                /*!< DMA0_CERR: CAEI Position                */
#define DMA_CERR_CAEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CAEI_SHIFT))&DMA_CERR_CAEI_MASK) /*!< DMA0_CERR                               */
#define DMA_CERR_NOP_MASK                        (0x80U)                                             /*!< DMA0_CERR: NOP Mask                     */
#define DMA_CERR_NOP_SHIFT                       (7U)                                                /*!< DMA0_CERR: NOP Position                 */
#define DMA_CERR_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERR_NOP_SHIFT))&DMA_CERR_NOP_MASK) /*!< DMA0_CERR                               */
/* ------- CINT Bit Fields                          ------ */
#define DMA_CINT_CINT_MASK                       (0xFU)                                              /*!< DMA0_CINT: CINT Mask                    */
#define DMA_CINT_CINT_SHIFT                      (0U)                                                /*!< DMA0_CINT: CINT Position                */
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK) /*!< DMA0_CINT                               */
#define DMA_CINT_CAIR_MASK                       (0x40U)                                             /*!< DMA0_CINT: CAIR Mask                    */
#define DMA_CINT_CAIR_SHIFT                      (6U)                                                /*!< DMA0_CINT: CAIR Position                */
#define DMA_CINT_CAIR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CAIR_SHIFT))&DMA_CINT_CAIR_MASK) /*!< DMA0_CINT                               */
#define DMA_CINT_NOP_MASK                        (0x80U)                                             /*!< DMA0_CINT: NOP Mask                     */
#define DMA_CINT_NOP_SHIFT                       (7U)                                                /*!< DMA0_CINT: NOP Position                 */
#define DMA_CINT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CINT_NOP_SHIFT))&DMA_CINT_NOP_MASK) /*!< DMA0_CINT                               */
/* ------- INT Bit Fields                           ------ */
#define DMA_INT_INT0_MASK                        (0x1U)                                              /*!< DMA0_INT: INT0 Mask                     */
#define DMA_INT_INT0_SHIFT                       (0U)                                                /*!< DMA0_INT: INT0 Position                 */
#define DMA_INT_INT0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT0_SHIFT))&DMA_INT_INT0_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT1_MASK                        (0x2U)                                              /*!< DMA0_INT: INT1 Mask                     */
#define DMA_INT_INT1_SHIFT                       (1U)                                                /*!< DMA0_INT: INT1 Position                 */
#define DMA_INT_INT1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT1_SHIFT))&DMA_INT_INT1_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT2_MASK                        (0x4U)                                              /*!< DMA0_INT: INT2 Mask                     */
#define DMA_INT_INT2_SHIFT                       (2U)                                                /*!< DMA0_INT: INT2 Position                 */
#define DMA_INT_INT2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT2_SHIFT))&DMA_INT_INT2_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT3_MASK                        (0x8U)                                              /*!< DMA0_INT: INT3 Mask                     */
#define DMA_INT_INT3_SHIFT                       (3U)                                                /*!< DMA0_INT: INT3 Position                 */
#define DMA_INT_INT3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT3_SHIFT))&DMA_INT_INT3_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT4_MASK                        (0x10U)                                             /*!< DMA0_INT: INT4 Mask                     */
#define DMA_INT_INT4_SHIFT                       (4U)                                                /*!< DMA0_INT: INT4 Position                 */
#define DMA_INT_INT4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT4_SHIFT))&DMA_INT_INT4_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT5_MASK                        (0x20U)                                             /*!< DMA0_INT: INT5 Mask                     */
#define DMA_INT_INT5_SHIFT                       (5U)                                                /*!< DMA0_INT: INT5 Position                 */
#define DMA_INT_INT5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT5_SHIFT))&DMA_INT_INT5_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT6_MASK                        (0x40U)                                             /*!< DMA0_INT: INT6 Mask                     */
#define DMA_INT_INT6_SHIFT                       (6U)                                                /*!< DMA0_INT: INT6 Position                 */
#define DMA_INT_INT6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT6_SHIFT))&DMA_INT_INT6_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT7_MASK                        (0x80U)                                             /*!< DMA0_INT: INT7 Mask                     */
#define DMA_INT_INT7_SHIFT                       (7U)                                                /*!< DMA0_INT: INT7 Position                 */
#define DMA_INT_INT7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT7_SHIFT))&DMA_INT_INT7_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT8_MASK                        (0x100U)                                            /*!< DMA0_INT: INT8 Mask                     */
#define DMA_INT_INT8_SHIFT                       (8U)                                                /*!< DMA0_INT: INT8 Position                 */
#define DMA_INT_INT8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT8_SHIFT))&DMA_INT_INT8_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT9_MASK                        (0x200U)                                            /*!< DMA0_INT: INT9 Mask                     */
#define DMA_INT_INT9_SHIFT                       (9U)                                                /*!< DMA0_INT: INT9 Position                 */
#define DMA_INT_INT9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT9_SHIFT))&DMA_INT_INT9_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT10_MASK                       (0x400U)                                            /*!< DMA0_INT: INT10 Mask                    */
#define DMA_INT_INT10_SHIFT                      (10U)                                               /*!< DMA0_INT: INT10 Position                */
#define DMA_INT_INT10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT10_SHIFT))&DMA_INT_INT10_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT11_MASK                       (0x800U)                                            /*!< DMA0_INT: INT11 Mask                    */
#define DMA_INT_INT11_SHIFT                      (11U)                                               /*!< DMA0_INT: INT11 Position                */
#define DMA_INT_INT11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT11_SHIFT))&DMA_INT_INT11_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT12_MASK                       (0x1000U)                                           /*!< DMA0_INT: INT12 Mask                    */
#define DMA_INT_INT12_SHIFT                      (12U)                                               /*!< DMA0_INT: INT12 Position                */
#define DMA_INT_INT12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT12_SHIFT))&DMA_INT_INT12_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT13_MASK                       (0x2000U)                                           /*!< DMA0_INT: INT13 Mask                    */
#define DMA_INT_INT13_SHIFT                      (13U)                                               /*!< DMA0_INT: INT13 Position                */
#define DMA_INT_INT13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT13_SHIFT))&DMA_INT_INT13_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT14_MASK                       (0x4000U)                                           /*!< DMA0_INT: INT14 Mask                    */
#define DMA_INT_INT14_SHIFT                      (14U)                                               /*!< DMA0_INT: INT14 Position                */
#define DMA_INT_INT14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT14_SHIFT))&DMA_INT_INT14_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT15_MASK                       (0x8000U)                                           /*!< DMA0_INT: INT15 Mask                    */
#define DMA_INT_INT15_SHIFT                      (15U)                                               /*!< DMA0_INT: INT15 Position                */
#define DMA_INT_INT15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT15_SHIFT))&DMA_INT_INT15_MASK) /*!< DMA0_INT                                */
/* ------- ERR Bit Fields                           ------ */
#define DMA_ERR_ERR0_MASK                        (0x1U)                                              /*!< DMA0_ERR: ERR0 Mask                     */
#define DMA_ERR_ERR0_SHIFT                       (0U)                                                /*!< DMA0_ERR: ERR0 Position                 */
#define DMA_ERR_ERR0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR0_SHIFT))&DMA_ERR_ERR0_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR1_MASK                        (0x2U)                                              /*!< DMA0_ERR: ERR1 Mask                     */
#define DMA_ERR_ERR1_SHIFT                       (1U)                                                /*!< DMA0_ERR: ERR1 Position                 */
#define DMA_ERR_ERR1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR1_SHIFT))&DMA_ERR_ERR1_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR2_MASK                        (0x4U)                                              /*!< DMA0_ERR: ERR2 Mask                     */
#define DMA_ERR_ERR2_SHIFT                       (2U)                                                /*!< DMA0_ERR: ERR2 Position                 */
#define DMA_ERR_ERR2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR2_SHIFT))&DMA_ERR_ERR2_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR3_MASK                        (0x8U)                                              /*!< DMA0_ERR: ERR3 Mask                     */
#define DMA_ERR_ERR3_SHIFT                       (3U)                                                /*!< DMA0_ERR: ERR3 Position                 */
#define DMA_ERR_ERR3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR3_SHIFT))&DMA_ERR_ERR3_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR4_MASK                        (0x10U)                                             /*!< DMA0_ERR: ERR4 Mask                     */
#define DMA_ERR_ERR4_SHIFT                       (4U)                                                /*!< DMA0_ERR: ERR4 Position                 */
#define DMA_ERR_ERR4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR4_SHIFT))&DMA_ERR_ERR4_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR5_MASK                        (0x20U)                                             /*!< DMA0_ERR: ERR5 Mask                     */
#define DMA_ERR_ERR5_SHIFT                       (5U)                                                /*!< DMA0_ERR: ERR5 Position                 */
#define DMA_ERR_ERR5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR5_SHIFT))&DMA_ERR_ERR5_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR6_MASK                        (0x40U)                                             /*!< DMA0_ERR: ERR6 Mask                     */
#define DMA_ERR_ERR6_SHIFT                       (6U)                                                /*!< DMA0_ERR: ERR6 Position                 */
#define DMA_ERR_ERR6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR6_SHIFT))&DMA_ERR_ERR6_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR7_MASK                        (0x80U)                                             /*!< DMA0_ERR: ERR7 Mask                     */
#define DMA_ERR_ERR7_SHIFT                       (7U)                                                /*!< DMA0_ERR: ERR7 Position                 */
#define DMA_ERR_ERR7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR7_SHIFT))&DMA_ERR_ERR7_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR8_MASK                        (0x100U)                                            /*!< DMA0_ERR: ERR8 Mask                     */
#define DMA_ERR_ERR8_SHIFT                       (8U)                                                /*!< DMA0_ERR: ERR8 Position                 */
#define DMA_ERR_ERR8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR8_SHIFT))&DMA_ERR_ERR8_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR9_MASK                        (0x200U)                                            /*!< DMA0_ERR: ERR9 Mask                     */
#define DMA_ERR_ERR9_SHIFT                       (9U)                                                /*!< DMA0_ERR: ERR9 Position                 */
#define DMA_ERR_ERR9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR9_SHIFT))&DMA_ERR_ERR9_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR10_MASK                       (0x400U)                                            /*!< DMA0_ERR: ERR10 Mask                    */
#define DMA_ERR_ERR10_SHIFT                      (10U)                                               /*!< DMA0_ERR: ERR10 Position                */
#define DMA_ERR_ERR10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR10_SHIFT))&DMA_ERR_ERR10_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR11_MASK                       (0x800U)                                            /*!< DMA0_ERR: ERR11 Mask                    */
#define DMA_ERR_ERR11_SHIFT                      (11U)                                               /*!< DMA0_ERR: ERR11 Position                */
#define DMA_ERR_ERR11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR11_SHIFT))&DMA_ERR_ERR11_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR12_MASK                       (0x1000U)                                           /*!< DMA0_ERR: ERR12 Mask                    */
#define DMA_ERR_ERR12_SHIFT                      (12U)                                               /*!< DMA0_ERR: ERR12 Position                */
#define DMA_ERR_ERR12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR12_SHIFT))&DMA_ERR_ERR12_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR13_MASK                       (0x2000U)                                           /*!< DMA0_ERR: ERR13 Mask                    */
#define DMA_ERR_ERR13_SHIFT                      (13U)                                               /*!< DMA0_ERR: ERR13 Position                */
#define DMA_ERR_ERR13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR13_SHIFT))&DMA_ERR_ERR13_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR14_MASK                       (0x4000U)                                           /*!< DMA0_ERR: ERR14 Mask                    */
#define DMA_ERR_ERR14_SHIFT                      (14U)                                               /*!< DMA0_ERR: ERR14 Position                */
#define DMA_ERR_ERR14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR14_SHIFT))&DMA_ERR_ERR14_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR15_MASK                       (0x8000U)                                           /*!< DMA0_ERR: ERR15 Mask                    */
#define DMA_ERR_ERR15_SHIFT                      (15U)                                               /*!< DMA0_ERR: ERR15 Position                */
#define DMA_ERR_ERR15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR15_SHIFT))&DMA_ERR_ERR15_MASK) /*!< DMA0_ERR                                */
/* ------- HRS Bit Fields                           ------ */
#define DMA_HRS_HRS0_MASK                        (0x1U)                                              /*!< DMA0_HRS: HRS0 Mask                     */
#define DMA_HRS_HRS0_SHIFT                       (0U)                                                /*!< DMA0_HRS: HRS0 Position                 */
#define DMA_HRS_HRS0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS0_SHIFT))&DMA_HRS_HRS0_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS1_MASK                        (0x2U)                                              /*!< DMA0_HRS: HRS1 Mask                     */
#define DMA_HRS_HRS1_SHIFT                       (1U)                                                /*!< DMA0_HRS: HRS1 Position                 */
#define DMA_HRS_HRS1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS1_SHIFT))&DMA_HRS_HRS1_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS2_MASK                        (0x4U)                                              /*!< DMA0_HRS: HRS2 Mask                     */
#define DMA_HRS_HRS2_SHIFT                       (2U)                                                /*!< DMA0_HRS: HRS2 Position                 */
#define DMA_HRS_HRS2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS2_SHIFT))&DMA_HRS_HRS2_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS3_MASK                        (0x8U)                                              /*!< DMA0_HRS: HRS3 Mask                     */
#define DMA_HRS_HRS3_SHIFT                       (3U)                                                /*!< DMA0_HRS: HRS3 Position                 */
#define DMA_HRS_HRS3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS3_SHIFT))&DMA_HRS_HRS3_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS4_MASK                        (0x10U)                                             /*!< DMA0_HRS: HRS4 Mask                     */
#define DMA_HRS_HRS4_SHIFT                       (4U)                                                /*!< DMA0_HRS: HRS4 Position                 */
#define DMA_HRS_HRS4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS4_SHIFT))&DMA_HRS_HRS4_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS5_MASK                        (0x20U)                                             /*!< DMA0_HRS: HRS5 Mask                     */
#define DMA_HRS_HRS5_SHIFT                       (5U)                                                /*!< DMA0_HRS: HRS5 Position                 */
#define DMA_HRS_HRS5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS5_SHIFT))&DMA_HRS_HRS5_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS6_MASK                        (0x40U)                                             /*!< DMA0_HRS: HRS6 Mask                     */
#define DMA_HRS_HRS6_SHIFT                       (6U)                                                /*!< DMA0_HRS: HRS6 Position                 */
#define DMA_HRS_HRS6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS6_SHIFT))&DMA_HRS_HRS6_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS7_MASK                        (0x80U)                                             /*!< DMA0_HRS: HRS7 Mask                     */
#define DMA_HRS_HRS7_SHIFT                       (7U)                                                /*!< DMA0_HRS: HRS7 Position                 */
#define DMA_HRS_HRS7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS7_SHIFT))&DMA_HRS_HRS7_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS8_MASK                        (0x100U)                                            /*!< DMA0_HRS: HRS8 Mask                     */
#define DMA_HRS_HRS8_SHIFT                       (8U)                                                /*!< DMA0_HRS: HRS8 Position                 */
#define DMA_HRS_HRS8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS8_SHIFT))&DMA_HRS_HRS8_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS9_MASK                        (0x200U)                                            /*!< DMA0_HRS: HRS9 Mask                     */
#define DMA_HRS_HRS9_SHIFT                       (9U)                                                /*!< DMA0_HRS: HRS9 Position                 */
#define DMA_HRS_HRS9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS9_SHIFT))&DMA_HRS_HRS9_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS10_MASK                       (0x400U)                                            /*!< DMA0_HRS: HRS10 Mask                    */
#define DMA_HRS_HRS10_SHIFT                      (10U)                                               /*!< DMA0_HRS: HRS10 Position                */
#define DMA_HRS_HRS10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS10_SHIFT))&DMA_HRS_HRS10_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS11_MASK                       (0x800U)                                            /*!< DMA0_HRS: HRS11 Mask                    */
#define DMA_HRS_HRS11_SHIFT                      (11U)                                               /*!< DMA0_HRS: HRS11 Position                */
#define DMA_HRS_HRS11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS11_SHIFT))&DMA_HRS_HRS11_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS12_MASK                       (0x1000U)                                           /*!< DMA0_HRS: HRS12 Mask                    */
#define DMA_HRS_HRS12_SHIFT                      (12U)                                               /*!< DMA0_HRS: HRS12 Position                */
#define DMA_HRS_HRS12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS12_SHIFT))&DMA_HRS_HRS12_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS13_MASK                       (0x2000U)                                           /*!< DMA0_HRS: HRS13 Mask                    */
#define DMA_HRS_HRS13_SHIFT                      (13U)                                               /*!< DMA0_HRS: HRS13 Position                */
#define DMA_HRS_HRS13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS13_SHIFT))&DMA_HRS_HRS13_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS14_MASK                       (0x4000U)                                           /*!< DMA0_HRS: HRS14 Mask                    */
#define DMA_HRS_HRS14_SHIFT                      (14U)                                               /*!< DMA0_HRS: HRS14 Position                */
#define DMA_HRS_HRS14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS14_SHIFT))&DMA_HRS_HRS14_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS15_MASK                       (0x8000U)                                           /*!< DMA0_HRS: HRS15 Mask                    */
#define DMA_HRS_HRS15_SHIFT                      (15U)                                               /*!< DMA0_HRS: HRS15 Position                */
#define DMA_HRS_HRS15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS15_SHIFT))&DMA_HRS_HRS15_MASK) /*!< DMA0_HRS                                */
/* ------- DCHPRI Bit Fields                        ------ */
#define DMA_DCHPRI_CHPRI_MASK                    (0xFU)                                              /*!< DMA0_DCHPRI: CHPRI Mask                 */
#define DMA_DCHPRI_CHPRI_SHIFT                   (0U)                                                /*!< DMA0_DCHPRI: CHPRI Position             */
#define DMA_DCHPRI_CHPRI(x)                      (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_CHPRI_SHIFT))&DMA_DCHPRI_CHPRI_MASK) /*!< DMA0_DCHPRI                             */
#define DMA_DCHPRI_DPA_MASK                      (0x40U)                                             /*!< DMA0_DCHPRI: DPA Mask                   */
#define DMA_DCHPRI_DPA_SHIFT                     (6U)                                                /*!< DMA0_DCHPRI: DPA Position               */
#define DMA_DCHPRI_DPA(x)                        (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_DPA_SHIFT))&DMA_DCHPRI_DPA_MASK) /*!< DMA0_DCHPRI                             */
#define DMA_DCHPRI_ECP_MASK                      (0x80U)                                             /*!< DMA0_DCHPRI: ECP Mask                   */
#define DMA_DCHPRI_ECP_SHIFT                     (7U)                                                /*!< DMA0_DCHPRI: ECP Position               */
#define DMA_DCHPRI_ECP(x)                        (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_ECP_SHIFT))&DMA_DCHPRI_ECP_MASK) /*!< DMA0_DCHPRI                             */
/* ------- SADDR Bit Fields                         ------ */
#define DMA_SADDR_SADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_SADDR: SADDR Mask                  */
#define DMA_SADDR_SADDR_SHIFT                    (0U)                                                /*!< DMA0_SADDR: SADDR Position              */
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SADDR_SADDR_SHIFT))&DMA_SADDR_SADDR_MASK) /*!< DMA0_SADDR                              */
/* ------- SOFF Bit Fields                          ------ */
#define DMA_SOFF_SOFF_MASK                       (0xFFFFU)                                           /*!< DMA0_SOFF: SOFF Mask                    */
#define DMA_SOFF_SOFF_SHIFT                      (0U)                                                /*!< DMA0_SOFF: SOFF Position                */
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_SOFF_SOFF_SHIFT))&DMA_SOFF_SOFF_MASK) /*!< DMA0_SOFF                               */
/* ------- ATTR Bit Fields                          ------ */
#define DMA_ATTR_DSIZE_MASK                      (0x7U)                                              /*!< DMA0_ATTR: DSIZE Mask                   */
#define DMA_ATTR_DSIZE_SHIFT                     (0U)                                                /*!< DMA0_ATTR: DSIZE Position               */
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DSIZE_SHIFT))&DMA_ATTR_DSIZE_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_DMOD_MASK                       (0xF8U)                                             /*!< DMA0_ATTR: DMOD Mask                    */
#define DMA_ATTR_DMOD_SHIFT                      (3U)                                                /*!< DMA0_ATTR: DMOD Position                */
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DMOD_SHIFT))&DMA_ATTR_DMOD_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_SSIZE_MASK                      (0x700U)                                            /*!< DMA0_ATTR: SSIZE Mask                   */
#define DMA_ATTR_SSIZE_SHIFT                     (8U)                                                /*!< DMA0_ATTR: SSIZE Position               */
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SSIZE_SHIFT))&DMA_ATTR_SSIZE_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_SMOD_MASK                       (0xF800U)                                           /*!< DMA0_ATTR: SMOD Mask                    */
#define DMA_ATTR_SMOD_SHIFT                      (11U)                                               /*!< DMA0_ATTR: SMOD Position                */
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SMOD_SHIFT))&DMA_ATTR_SMOD_MASK) /*!< DMA0_ATTR                               */
/* ------- NBYTES_MLNO Bit Fields                   ------ */
#define DMA_NBYTES_MLNO_NBYTES_MASK              (0xFFFFFFFFU)                                       /*!< DMA0_NBYTES_MLNO: NBYTES Mask           */
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             (0U)                                                /*!< DMA0_NBYTES_MLNO: NBYTES Position       */
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLNO_NBYTES_SHIFT))&DMA_NBYTES_MLNO_NBYTES_MASK) /*!< DMA0_NBYTES_MLNO                        */
/* ------- NBYTES_MLOFFNO Bit Fields                ------ */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           (0x3FFFFFFFU)                                       /*!< DMA0_NBYTES_MLOFFNO: NBYTES Mask        */
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          (0U)                                                /*!< DMA0_NBYTES_MLOFFNO: NBYTES Position    */
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_NBYTES_SHIFT))&DMA_NBYTES_MLOFFNO_NBYTES_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            (0x40000000U)                                       /*!< DMA0_NBYTES_MLOFFNO: DMLOE Mask         */
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           (30U)                                               /*!< DMA0_NBYTES_MLOFFNO: DMLOE Position     */
#define DMA_NBYTES_MLOFFNO_DMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_DMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_DMLOE_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            (0x80000000U)                                       /*!< DMA0_NBYTES_MLOFFNO: SMLOE Mask         */
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           (31U)                                               /*!< DMA0_NBYTES_MLOFFNO: SMLOE Position     */
#define DMA_NBYTES_MLOFFNO_SMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_SMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_SMLOE_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
/* ------- NBYTES_MLOFFYES Bit Fields               ------ */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          (0x3FFU)                                            /*!< DMA0_NBYTES_MLOFFYES: NBYTES Mask       */
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         (0U)                                                /*!< DMA0_NBYTES_MLOFFYES: NBYTES Position   */
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_NBYTES_SHIFT))&DMA_NBYTES_MLOFFYES_NBYTES_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           (0x3FFFFC00U)                                       /*!< DMA0_NBYTES_MLOFFYES: MLOFF Mask        */
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          (10U)                                               /*!< DMA0_NBYTES_MLOFFYES: MLOFF Position    */
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT))&DMA_NBYTES_MLOFFYES_MLOFF_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           (0x40000000U)                                       /*!< DMA0_NBYTES_MLOFFYES: DMLOE Mask        */
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          (30U)                                               /*!< DMA0_NBYTES_MLOFFYES: DMLOE Position    */
#define DMA_NBYTES_MLOFFYES_DMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_DMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_DMLOE_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           (0x80000000U)                                       /*!< DMA0_NBYTES_MLOFFYES: SMLOE Mask        */
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          (31U)                                               /*!< DMA0_NBYTES_MLOFFYES: SMLOE Position    */
#define DMA_NBYTES_MLOFFYES_SMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_SMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_SMLOE_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
/* ------- SLAST Bit Fields                         ------ */
#define DMA_SLAST_SLAST_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_SLAST: SLAST Mask                  */
#define DMA_SLAST_SLAST_SHIFT                    (0U)                                                /*!< DMA0_SLAST: SLAST Position              */
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SLAST_SLAST_SHIFT))&DMA_SLAST_SLAST_MASK) /*!< DMA0_SLAST                              */
/* ------- DADDR Bit Fields                         ------ */
#define DMA_DADDR_DADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_DADDR: DADDR Mask                  */
#define DMA_DADDR_DADDR_SHIFT                    (0U)                                                /*!< DMA0_DADDR: DADDR Position              */
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DADDR_DADDR_SHIFT))&DMA_DADDR_DADDR_MASK) /*!< DMA0_DADDR                              */
/* ------- DOFF Bit Fields                          ------ */
#define DMA_DOFF_DOFF_MASK                       (0xFFFFU)                                           /*!< DMA0_DOFF: DOFF Mask                    */
#define DMA_DOFF_DOFF_SHIFT                      (0U)                                                /*!< DMA0_DOFF: DOFF Position                */
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_DOFF_DOFF_SHIFT))&DMA_DOFF_DOFF_MASK) /*!< DMA0_DOFF                               */
/* ------- CITER_ELINKNO Bit Fields                 ------ */
#define DMA_CITER_ELINKNO_CITER_MASK             (0x7FFFU)                                           /*!< DMA0_CITER_ELINKNO: CITER Mask          */
#define DMA_CITER_ELINKNO_CITER_SHIFT            (0U)                                                /*!< DMA0_CITER_ELINKNO: CITER Position      */
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_CITER_SHIFT))&DMA_CITER_ELINKNO_CITER_MASK) /*!< DMA0_CITER_ELINKNO                      */
#define DMA_CITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA0_CITER_ELINKNO: ELINK Mask          */
#define DMA_CITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA0_CITER_ELINKNO: ELINK Position      */
#define DMA_CITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_ELINK_SHIFT))&DMA_CITER_ELINKNO_ELINK_MASK) /*!< DMA0_CITER_ELINKNO                      */
/* ------- CITER_ELINKYES Bit Fields                ------ */
#define DMA_CITER_ELINKYES_CITER_MASK            (0x1FFU)                                            /*!< DMA0_CITER_ELINKYES: CITER Mask         */
#define DMA_CITER_ELINKYES_CITER_SHIFT           (0U)                                                /*!< DMA0_CITER_ELINKYES: CITER Position     */
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_CITER_SHIFT))&DMA_CITER_ELINKYES_CITER_MASK) /*!< DMA0_CITER_ELINKYES                     */
#define DMA_CITER_ELINKYES_LINKCH_MASK           (0x1E00U)                                           /*!< DMA0_CITER_ELINKYES: LINKCH Mask        */
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA0_CITER_ELINKYES: LINKCH Position    */
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_LINKCH_SHIFT))&DMA_CITER_ELINKYES_LINKCH_MASK) /*!< DMA0_CITER_ELINKYES                     */
#define DMA_CITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA0_CITER_ELINKYES: ELINK Mask         */
#define DMA_CITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA0_CITER_ELINKYES: ELINK Position     */
#define DMA_CITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_ELINK_SHIFT))&DMA_CITER_ELINKYES_ELINK_MASK) /*!< DMA0_CITER_ELINKYES                     */
/* ------- DLASTSGA Bit Fields                      ------ */
#define DMA_DLASTSGA_DLASTSGA_MASK               (0xFFFFFFFFU)                                       /*!< DMA0_DLASTSGA: DLASTSGA Mask            */
#define DMA_DLASTSGA_DLASTSGA_SHIFT              (0U)                                                /*!< DMA0_DLASTSGA: DLASTSGA Position        */
#define DMA_DLASTSGA_DLASTSGA(x)                 (((uint32_t)(((uint32_t)(x))<<DMA_DLASTSGA_DLASTSGA_SHIFT))&DMA_DLASTSGA_DLASTSGA_MASK) /*!< DMA0_DLASTSGA                           */
/* ------- CSR Bit Fields                           ------ */
#define DMA_CSR_START_MASK                       (0x1U)                                              /*!< DMA0_CSR: START Mask                    */
#define DMA_CSR_START_SHIFT                      (0U)                                                /*!< DMA0_CSR: START Position                */
#define DMA_CSR_START(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_CSR_START_SHIFT))&DMA_CSR_START_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_INTMAJOR_MASK                    (0x2U)                                              /*!< DMA0_CSR: INTMAJOR Mask                 */
#define DMA_CSR_INTMAJOR_SHIFT                   (1U)                                                /*!< DMA0_CSR: INTMAJOR Position             */
#define DMA_CSR_INTMAJOR(x)                      (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTMAJOR_SHIFT))&DMA_CSR_INTMAJOR_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_INTHALF_MASK                     (0x4U)                                              /*!< DMA0_CSR: INTHALF Mask                  */
#define DMA_CSR_INTHALF_SHIFT                    (2U)                                                /*!< DMA0_CSR: INTHALF Position              */
#define DMA_CSR_INTHALF(x)                       (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTHALF_SHIFT))&DMA_CSR_INTHALF_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_DREQ_MASK                        (0x8U)                                              /*!< DMA0_CSR: DREQ Mask                     */
#define DMA_CSR_DREQ_SHIFT                       (3U)                                                /*!< DMA0_CSR: DREQ Position                 */
#define DMA_CSR_DREQ(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DREQ_SHIFT))&DMA_CSR_DREQ_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_ESG_MASK                         (0x10U)                                             /*!< DMA0_CSR: ESG Mask                      */
#define DMA_CSR_ESG_SHIFT                        (4U)                                                /*!< DMA0_CSR: ESG Position                  */
#define DMA_CSR_ESG(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ESG_SHIFT))&DMA_CSR_ESG_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_MAJORELINK_MASK                  (0x20U)                                             /*!< DMA0_CSR: MAJORELINK Mask               */
#define DMA_CSR_MAJORELINK_SHIFT                 (5U)                                                /*!< DMA0_CSR: MAJORELINK Position           */
#define DMA_CSR_MAJORELINK(x)                    (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORELINK_SHIFT))&DMA_CSR_MAJORELINK_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_ACTIVE_MASK                      (0x40U)                                             /*!< DMA0_CSR: ACTIVE Mask                   */
#define DMA_CSR_ACTIVE_SHIFT                     (6U)                                                /*!< DMA0_CSR: ACTIVE Position               */
#define DMA_CSR_ACTIVE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ACTIVE_SHIFT))&DMA_CSR_ACTIVE_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_DONE_MASK                        (0x80U)                                             /*!< DMA0_CSR: DONE Mask                     */
#define DMA_CSR_DONE_SHIFT                       (7U)                                                /*!< DMA0_CSR: DONE Position                 */
#define DMA_CSR_DONE(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DONE_SHIFT))&DMA_CSR_DONE_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_MAJORLINKCH_MASK                 (0xF00U)                                            /*!< DMA0_CSR: MAJORLINKCH Mask              */
#define DMA_CSR_MAJORLINKCH_SHIFT                (8U)                                                /*!< DMA0_CSR: MAJORLINKCH Position          */
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORLINKCH_SHIFT))&DMA_CSR_MAJORLINKCH_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_BWC_MASK                         (0xC000U)                                           /*!< DMA0_CSR: BWC Mask                      */
#define DMA_CSR_BWC_SHIFT                        (14U)                                               /*!< DMA0_CSR: BWC Position                  */
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_BWC_SHIFT))&DMA_CSR_BWC_MASK) /*!< DMA0_CSR                                */
/* ------- BITER_ELINKNO Bit Fields                 ------ */
#define DMA_BITER_ELINKNO_BITER_MASK             (0x7FFFU)                                           /*!< DMA0_BITER_ELINKNO: BITER Mask          */
#define DMA_BITER_ELINKNO_BITER_SHIFT            (0U)                                                /*!< DMA0_BITER_ELINKNO: BITER Position      */
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK) /*!< DMA0_BITER_ELINKNO                      */
#define DMA_BITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA0_BITER_ELINKNO: ELINK Mask          */
#define DMA_BITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA0_BITER_ELINKNO: ELINK Position      */
#define DMA_BITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_ELINK_SHIFT))&DMA_BITER_ELINKNO_ELINK_MASK) /*!< DMA0_BITER_ELINKNO                      */
/* ------- BITER_ELINKYES Bit Fields                ------ */
#define DMA_BITER_ELINKYES_BITER_MASK            (0x1FFU)                                            /*!< DMA0_BITER_ELINKYES: BITER Mask         */
#define DMA_BITER_ELINKYES_BITER_SHIFT           (0U)                                                /*!< DMA0_BITER_ELINKYES: BITER Position     */
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_BITER_SHIFT))&DMA_BITER_ELINKYES_BITER_MASK) /*!< DMA0_BITER_ELINKYES                     */
#define DMA_BITER_ELINKYES_LINKCH_MASK           (0x1E00U)                                           /*!< DMA0_BITER_ELINKYES: LINKCH Mask        */
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA0_BITER_ELINKYES: LINKCH Position    */
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_LINKCH_SHIFT))&DMA_BITER_ELINKYES_LINKCH_MASK) /*!< DMA0_BITER_ELINKYES                     */
#define DMA_BITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA0_BITER_ELINKYES: ELINK Mask         */
#define DMA_BITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA0_BITER_ELINKYES: ELINK Position     */
#define DMA_BITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_ELINK_SHIFT))&DMA_BITER_ELINKYES_ELINK_MASK) /*!< DMA0_BITER_ELINKYES                     */
/**
 * @} */ /* End group DMA0_Register_Masks_GROUP 
 */

/* DMA0 - Peripheral instance base addresses */
#define DMA0_BasePtr                   0x40008000UL //!< Peripheral base address
#define DMA0                           ((DMA_Type *) DMA0_BasePtr) //!< Freescale base pointer
#define DMA0_BASE_PTR                  (DMA0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX0 (file:DMAMUX0_16CH_TRIG)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */
/**
* @addtogroup DMAMUX_structs_GROUP DMAMUX struct
* @brief Struct for DMAMUX
* @{
*/
typedef struct {                                /*       DMAMUX0 Structure                                            */
   __IO uint8_t   CHCFG[16];                    /**< 0000: Channel Configuration Register                               */
} DMAMUX_Type;

/**
 * @} */ /* End group DMAMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMAMUX0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMAMUX_Register_Masks_GROUP DMAMUX Register Masks
* @brief Register Masks for DMAMUX
* @{
*/
/* ------- CHCFG Bit Fields                         ------ */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)                                             /*!< DMAMUX0_CHCFG: SOURCE Mask              */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)                                                /*!< DMAMUX0_CHCFG: SOURCE Position          */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)                                             /*!< DMAMUX0_CHCFG: TRIG Mask                */
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)                                                /*!< DMAMUX0_CHCFG: TRIG Position            */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_TRIG_SHIFT))&DMAMUX_CHCFG_TRIG_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)                                             /*!< DMAMUX0_CHCFG: ENBL Mask                */
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)                                                /*!< DMAMUX0_CHCFG: ENBL Position            */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_ENBL_SHIFT))&DMAMUX_CHCFG_ENBL_MASK) /*!< DMAMUX0_CHCFG                           */
/**
 * @} */ /* End group DMAMUX_Register_Masks_GROUP 
 */

/* DMAMUX0 - Peripheral instance base addresses */
#define DMAMUX0_BasePtr                0x40021000UL //!< Peripheral base address
#define DMAMUX0                        ((DMAMUX_Type *) DMAMUX0_BasePtr) //!< Freescale base pointer
#define DMAMUX0_BASE_PTR               (DMAMUX0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DRY_Peripheral_access_layer_GROUP DRY Peripheral Access Layer
* @brief C Struct for DRY
* @{
*/

/* ================================================================================ */
/* ================           DRY (file:DRY_3IN)                   ================ */
/* ================================================================================ */

/**
 * @brief Tamper Detect and Secure Key Storage
 */
/**
* @addtogroup DRY_structs_GROUP DRY struct
* @brief Struct for DRY
* @{
*/
typedef struct {                                /*       DRY Structure                                                */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  SKVR;                         /**< 0004: DryIce Secure Key Valid Register                             */
   __IO uint32_t  SKWLR;                        /**< 0008: DryIce Secure Key Write Lock Register                        */
   __IO uint32_t  SKRLR;                        /**< 000C: DryIce Secure Key Read Lock Register                         */
   __IO uint32_t  CR;                           /**< 0010: DryIce Control Register                                      */
   __IO uint32_t  SR;                           /**< 0014: DryIce Status Register                                       */
   __IO uint32_t  LR;                           /**< 0018: DryIce Lock Register                                         */
   __IO uint32_t  IER;                          /**< 001C: DryIce Interrupt Enable Register                             */
   __IO uint32_t  TSR;                          /**< 0020: DryIce Tamper Seconds Register                               */
   __IO uint32_t  TER;                          /**< 0024: DryIce Tamper Enable Register                                */
   __IO uint32_t  PDR;                          /**< 0028: DryIce Pin Direction Register                                */
   __IO uint32_t  PPR;                          /**< 002C: DryIce Pin Polarity Register                                 */
   __IO uint32_t  ATR[2];                       /**< 0030: DryIce Active Tamper Register                                */
        uint8_t   RESERVED_1[8];               
   __IO uint32_t  PGFR[3];                      /**< 0040: DryIce Pin Glitch Filter Register                            */
        uint8_t   RESERVED_2[1972];            
   __IO uint32_t  WAC;                          /**< 0800: DryIce Write Access Control Register                         */
   __IO uint32_t  RAC;                          /**< 0804: DryIce Read Access Control Register                          */
        uint8_t   RESERVED_3[2040];            
   __IO uint32_t  SKR[8];                       /**< 1000: Secure Key Register                                          */
        uint8_t   RESERVED_4[2016];            
   __IO uint32_t  SWAC;                         /**< 1800: Secure Write Access Control                                  */
   __IO uint32_t  SRAC;                         /**< 1804: Secure Read Access Control                                   */
} DRY_Type;

/**
 * @} */ /* End group DRY_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DRY' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DRY_Register_Masks_GROUP DRY Register Masks
* @brief Register Masks for DRY
* @{
*/
/* ------- SKVR Bit Fields                          ------ */
#define DRY_SKVR_SKV_MASK                        (0xFFU)                                             /*!< DRY_SKVR: SKV Mask                      */
#define DRY_SKVR_SKV_SHIFT                       (0U)                                                /*!< DRY_SKVR: SKV Position                  */
#define DRY_SKVR_SKV(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_SKVR_SKV_SHIFT))&DRY_SKVR_SKV_MASK) /*!< DRY_SKVR                                */
/* ------- SKWLR Bit Fields                         ------ */
#define DRY_SKWLR_SKWL_MASK                      (0xFFU)                                             /*!< DRY_SKWLR: SKWL Mask                    */
#define DRY_SKWLR_SKWL_SHIFT                     (0U)                                                /*!< DRY_SKWLR: SKWL Position                */
#define DRY_SKWLR_SKWL(x)                        (((uint32_t)(((uint32_t)(x))<<DRY_SKWLR_SKWL_SHIFT))&DRY_SKWLR_SKWL_MASK) /*!< DRY_SKWLR                               */
/* ------- SKRLR Bit Fields                         ------ */
#define DRY_SKRLR_SKRL_MASK                      (0xFFU)                                             /*!< DRY_SKRLR: SKRL Mask                    */
#define DRY_SKRLR_SKRL_SHIFT                     (0U)                                                /*!< DRY_SKRLR: SKRL Position                */
#define DRY_SKRLR_SKRL(x)                        (((uint32_t)(((uint32_t)(x))<<DRY_SKRLR_SKRL_SHIFT))&DRY_SKRLR_SKRL_MASK) /*!< DRY_SKRLR                               */
/* ------- CR Bit Fields                            ------ */
#define DRY_CR_SWR_MASK                          (0x1U)                                              /*!< DRY_CR: SWR Mask                        */
#define DRY_CR_SWR_SHIFT                         (0U)                                                /*!< DRY_CR: SWR Position                    */
#define DRY_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_CR_SWR_SHIFT))&DRY_CR_SWR_MASK) /*!< DRY_CR                                  */
#define DRY_CR_DEN_MASK                          (0x2U)                                              /*!< DRY_CR: DEN Mask                        */
#define DRY_CR_DEN_SHIFT                         (1U)                                                /*!< DRY_CR: DEN Position                    */
#define DRY_CR_DEN(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_CR_DEN_SHIFT))&DRY_CR_DEN_MASK) /*!< DRY_CR                                  */
#define DRY_CR_TFSR_MASK                         (0x4U)                                              /*!< DRY_CR: TFSR Mask                       */
#define DRY_CR_TFSR_SHIFT                        (2U)                                                /*!< DRY_CR: TFSR Position                   */
#define DRY_CR_TFSR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_CR_TFSR_SHIFT))&DRY_CR_TFSR_MASK) /*!< DRY_CR                                  */
#define DRY_CR_UM_MASK                           (0x8U)                                              /*!< DRY_CR: UM Mask                         */
#define DRY_CR_UM_SHIFT                          (3U)                                                /*!< DRY_CR: UM Position                     */
#define DRY_CR_UM(x)                             (((uint32_t)(((uint32_t)(x))<<DRY_CR_UM_SHIFT))&DRY_CR_UM_MASK) /*!< DRY_CR                                  */
#define DRY_CR_THYS_MASK                         (0x100U)                                            /*!< DRY_CR: THYS Mask                       */
#define DRY_CR_THYS_SHIFT                        (8U)                                                /*!< DRY_CR: THYS Position                   */
#define DRY_CR_THYS(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_CR_THYS_SHIFT))&DRY_CR_THYS_MASK) /*!< DRY_CR                                  */
#define DRY_CR_TPFE_MASK                         (0x200U)                                            /*!< DRY_CR: TPFE Mask                       */
#define DRY_CR_TPFE_SHIFT                        (9U)                                                /*!< DRY_CR: TPFE Position                   */
#define DRY_CR_TPFE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_CR_TPFE_SHIFT))&DRY_CR_TPFE_MASK) /*!< DRY_CR                                  */
#define DRY_CR_TDSE_MASK                         (0x400U)                                            /*!< DRY_CR: TDSE Mask                       */
#define DRY_CR_TDSE_SHIFT                        (10U)                                               /*!< DRY_CR: TDSE Position                   */
#define DRY_CR_TDSE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_CR_TDSE_SHIFT))&DRY_CR_TDSE_MASK) /*!< DRY_CR                                  */
#define DRY_CR_TSRE_MASK                         (0x800U)                                            /*!< DRY_CR: TSRE Mask                       */
#define DRY_CR_TSRE_SHIFT                        (11U)                                               /*!< DRY_CR: TSRE Position                   */
#define DRY_CR_TSRE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_CR_TSRE_SHIFT))&DRY_CR_TSRE_MASK) /*!< DRY_CR                                  */
#define DRY_CR_DPR_MASK                          (0xFFFE0000U)                                       /*!< DRY_CR: DPR Mask                        */
#define DRY_CR_DPR_SHIFT                         (17U)                                               /*!< DRY_CR: DPR Position                    */
#define DRY_CR_DPR(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_CR_DPR_SHIFT))&DRY_CR_DPR_MASK) /*!< DRY_CR                                  */
/* ------- SR Bit Fields                            ------ */
#define DRY_SR_DTF_MASK                          (0x1U)                                              /*!< DRY_SR: DTF Mask                        */
#define DRY_SR_DTF_SHIFT                         (0U)                                                /*!< DRY_SR: DTF Position                    */
#define DRY_SR_DTF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_DTF_SHIFT))&DRY_SR_DTF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_TAF_MASK                          (0x2U)                                              /*!< DRY_SR: TAF Mask                        */
#define DRY_SR_TAF_SHIFT                         (1U)                                                /*!< DRY_SR: TAF Position                    */
#define DRY_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_TAF_SHIFT))&DRY_SR_TAF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_TOF_MASK                          (0x4U)                                              /*!< DRY_SR: TOF Mask                        */
#define DRY_SR_TOF_SHIFT                         (2U)                                                /*!< DRY_SR: TOF Position                    */
#define DRY_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_TOF_SHIFT))&DRY_SR_TOF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_MOF_MASK                          (0x8U)                                              /*!< DRY_SR: MOF Mask                        */
#define DRY_SR_MOF_SHIFT                         (3U)                                                /*!< DRY_SR: MOF Position                    */
#define DRY_SR_MOF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_MOF_SHIFT))&DRY_SR_MOF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_VTF_MASK                          (0x10U)                                             /*!< DRY_SR: VTF Mask                        */
#define DRY_SR_VTF_SHIFT                         (4U)                                                /*!< DRY_SR: VTF Position                    */
#define DRY_SR_VTF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_VTF_SHIFT))&DRY_SR_VTF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_CTF_MASK                          (0x20U)                                             /*!< DRY_SR: CTF Mask                        */
#define DRY_SR_CTF_SHIFT                         (5U)                                                /*!< DRY_SR: CTF Position                    */
#define DRY_SR_CTF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_CTF_SHIFT))&DRY_SR_CTF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_TTF_MASK                          (0x40U)                                             /*!< DRY_SR: TTF Mask                        */
#define DRY_SR_TTF_SHIFT                         (6U)                                                /*!< DRY_SR: TTF Position                    */
#define DRY_SR_TTF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_TTF_SHIFT))&DRY_SR_TTF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_STF_MASK                          (0x80U)                                             /*!< DRY_SR: STF Mask                        */
#define DRY_SR_STF_SHIFT                         (7U)                                                /*!< DRY_SR: STF Position                    */
#define DRY_SR_STF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_STF_SHIFT))&DRY_SR_STF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_FSF_MASK                          (0x100U)                                            /*!< DRY_SR: FSF Mask                        */
#define DRY_SR_FSF_SHIFT                         (8U)                                                /*!< DRY_SR: FSF Position                    */
#define DRY_SR_FSF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_FSF_SHIFT))&DRY_SR_FSF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_TMF_MASK                          (0x200U)                                            /*!< DRY_SR: TMF Mask                        */
#define DRY_SR_TMF_SHIFT                         (9U)                                                /*!< DRY_SR: TMF Position                    */
#define DRY_SR_TMF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_TMF_SHIFT))&DRY_SR_TMF_MASK) /*!< DRY_SR                                  */
#define DRY_SR_TPF_MASK                          (0xFF0000U)                                         /*!< DRY_SR: TPF Mask                        */
#define DRY_SR_TPF_SHIFT                         (16U)                                               /*!< DRY_SR: TPF Position                    */
#define DRY_SR_TPF(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SR_TPF_SHIFT))&DRY_SR_TPF_MASK) /*!< DRY_SR                                  */
/* ------- LR Bit Fields                            ------ */
#define DRY_LR_KVL_MASK                          (0x2U)                                              /*!< DRY_LR: KVL Mask                        */
#define DRY_LR_KVL_SHIFT                         (1U)                                                /*!< DRY_LR: KVL Position                    */
#define DRY_LR_KVL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_KVL_SHIFT))&DRY_LR_KVL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_KWL_MASK                          (0x4U)                                              /*!< DRY_LR: KWL Mask                        */
#define DRY_LR_KWL_SHIFT                         (2U)                                                /*!< DRY_LR: KWL Position                    */
#define DRY_LR_KWL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_KWL_SHIFT))&DRY_LR_KWL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_KRL_MASK                          (0x8U)                                              /*!< DRY_LR: KRL Mask                        */
#define DRY_LR_KRL_SHIFT                         (3U)                                                /*!< DRY_LR: KRL Position                    */
#define DRY_LR_KRL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_KRL_SHIFT))&DRY_LR_KRL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_CRL_MASK                          (0x10U)                                             /*!< DRY_LR: CRL Mask                        */
#define DRY_LR_CRL_SHIFT                         (4U)                                                /*!< DRY_LR: CRL Position                    */
#define DRY_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_CRL_SHIFT))&DRY_LR_CRL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_SRL_MASK                          (0x20U)                                             /*!< DRY_LR: SRL Mask                        */
#define DRY_LR_SRL_SHIFT                         (5U)                                                /*!< DRY_LR: SRL Position                    */
#define DRY_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_SRL_SHIFT))&DRY_LR_SRL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_LRL_MASK                          (0x40U)                                             /*!< DRY_LR: LRL Mask                        */
#define DRY_LR_LRL_SHIFT                         (6U)                                                /*!< DRY_LR: LRL Position                    */
#define DRY_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_LRL_SHIFT))&DRY_LR_LRL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_IEL_MASK                          (0x80U)                                             /*!< DRY_LR: IEL Mask                        */
#define DRY_LR_IEL_SHIFT                         (7U)                                                /*!< DRY_LR: IEL Position                    */
#define DRY_LR_IEL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_IEL_SHIFT))&DRY_LR_IEL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_TSL_MASK                          (0x100U)                                            /*!< DRY_LR: TSL Mask                        */
#define DRY_LR_TSL_SHIFT                         (8U)                                                /*!< DRY_LR: TSL Position                    */
#define DRY_LR_TSL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_TSL_SHIFT))&DRY_LR_TSL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_TEL_MASK                          (0x200U)                                            /*!< DRY_LR: TEL Mask                        */
#define DRY_LR_TEL_SHIFT                         (9U)                                                /*!< DRY_LR: TEL Position                    */
#define DRY_LR_TEL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_TEL_SHIFT))&DRY_LR_TEL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_PDL_MASK                          (0x400U)                                            /*!< DRY_LR: PDL Mask                        */
#define DRY_LR_PDL_SHIFT                         (10U)                                               /*!< DRY_LR: PDL Position                    */
#define DRY_LR_PDL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_PDL_SHIFT))&DRY_LR_PDL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_PPL_MASK                          (0x800U)                                            /*!< DRY_LR: PPL Mask                        */
#define DRY_LR_PPL_SHIFT                         (11U)                                               /*!< DRY_LR: PPL Position                    */
#define DRY_LR_PPL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_PPL_SHIFT))&DRY_LR_PPL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_ATL_MASK                          (0x3000U)                                           /*!< DRY_LR: ATL Mask                        */
#define DRY_LR_ATL_SHIFT                         (12U)                                               /*!< DRY_LR: ATL Position                    */
#define DRY_LR_ATL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_ATL_SHIFT))&DRY_LR_ATL_MASK) /*!< DRY_LR                                  */
#define DRY_LR_GFL_MASK                          (0xFF0000U)                                         /*!< DRY_LR: GFL Mask                        */
#define DRY_LR_GFL_SHIFT                         (16U)                                               /*!< DRY_LR: GFL Position                    */
#define DRY_LR_GFL(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_LR_GFL_SHIFT))&DRY_LR_GFL_MASK) /*!< DRY_LR                                  */
/* ------- IER Bit Fields                           ------ */
#define DRY_IER_DTIE_MASK                        (0x1U)                                              /*!< DRY_IER: DTIE Mask                      */
#define DRY_IER_DTIE_SHIFT                       (0U)                                                /*!< DRY_IER: DTIE Position                  */
#define DRY_IER_DTIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_DTIE_SHIFT))&DRY_IER_DTIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_TOIE_MASK                        (0x4U)                                              /*!< DRY_IER: TOIE Mask                      */
#define DRY_IER_TOIE_SHIFT                       (2U)                                                /*!< DRY_IER: TOIE Position                  */
#define DRY_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_TOIE_SHIFT))&DRY_IER_TOIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_MOIE_MASK                        (0x8U)                                              /*!< DRY_IER: MOIE Mask                      */
#define DRY_IER_MOIE_SHIFT                       (3U)                                                /*!< DRY_IER: MOIE Position                  */
#define DRY_IER_MOIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_MOIE_SHIFT))&DRY_IER_MOIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_VTIE_MASK                        (0x10U)                                             /*!< DRY_IER: VTIE Mask                      */
#define DRY_IER_VTIE_SHIFT                       (4U)                                                /*!< DRY_IER: VTIE Position                  */
#define DRY_IER_VTIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_VTIE_SHIFT))&DRY_IER_VTIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_CTIE_MASK                        (0x20U)                                             /*!< DRY_IER: CTIE Mask                      */
#define DRY_IER_CTIE_SHIFT                       (5U)                                                /*!< DRY_IER: CTIE Position                  */
#define DRY_IER_CTIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_CTIE_SHIFT))&DRY_IER_CTIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_TTIE_MASK                        (0x40U)                                             /*!< DRY_IER: TTIE Mask                      */
#define DRY_IER_TTIE_SHIFT                       (6U)                                                /*!< DRY_IER: TTIE Position                  */
#define DRY_IER_TTIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_TTIE_SHIFT))&DRY_IER_TTIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_STIE_MASK                        (0x80U)                                             /*!< DRY_IER: STIE Mask                      */
#define DRY_IER_STIE_SHIFT                       (7U)                                                /*!< DRY_IER: STIE Position                  */
#define DRY_IER_STIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_STIE_SHIFT))&DRY_IER_STIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_FSIE_MASK                        (0x100U)                                            /*!< DRY_IER: FSIE Mask                      */
#define DRY_IER_FSIE_SHIFT                       (8U)                                                /*!< DRY_IER: FSIE Position                  */
#define DRY_IER_FSIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_FSIE_SHIFT))&DRY_IER_FSIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_TMIE_MASK                        (0x200U)                                            /*!< DRY_IER: TMIE Mask                      */
#define DRY_IER_TMIE_SHIFT                       (9U)                                                /*!< DRY_IER: TMIE Position                  */
#define DRY_IER_TMIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_TMIE_SHIFT))&DRY_IER_TMIE_MASK) /*!< DRY_IER                                 */
#define DRY_IER_TPIE_MASK                        (0xFF0000U)                                         /*!< DRY_IER: TPIE Mask                      */
#define DRY_IER_TPIE_SHIFT                       (16U)                                               /*!< DRY_IER: TPIE Position                  */
#define DRY_IER_TPIE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_IER_TPIE_SHIFT))&DRY_IER_TPIE_MASK) /*!< DRY_IER                                 */
/* ------- TSR Bit Fields                           ------ */
#define DRY_TSR_TTS_MASK                         (0xFFFFFFFFU)                                       /*!< DRY_TSR: TTS Mask                       */
#define DRY_TSR_TTS_SHIFT                        (0U)                                                /*!< DRY_TSR: TTS Position                   */
#define DRY_TSR_TTS(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TSR_TTS_SHIFT))&DRY_TSR_TTS_MASK) /*!< DRY_TSR                                 */
/* ------- TER Bit Fields                           ------ */
#define DRY_TER_TOE_MASK                         (0x4U)                                              /*!< DRY_TER: TOE Mask                       */
#define DRY_TER_TOE_SHIFT                        (2U)                                                /*!< DRY_TER: TOE Position                   */
#define DRY_TER_TOE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_TOE_SHIFT))&DRY_TER_TOE_MASK) /*!< DRY_TER                                 */
#define DRY_TER_MOE_MASK                         (0x8U)                                              /*!< DRY_TER: MOE Mask                       */
#define DRY_TER_MOE_SHIFT                        (3U)                                                /*!< DRY_TER: MOE Position                   */
#define DRY_TER_MOE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_MOE_SHIFT))&DRY_TER_MOE_MASK) /*!< DRY_TER                                 */
#define DRY_TER_VTE_MASK                         (0x10U)                                             /*!< DRY_TER: VTE Mask                       */
#define DRY_TER_VTE_SHIFT                        (4U)                                                /*!< DRY_TER: VTE Position                   */
#define DRY_TER_VTE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_VTE_SHIFT))&DRY_TER_VTE_MASK) /*!< DRY_TER                                 */
#define DRY_TER_CTE_MASK                         (0x20U)                                             /*!< DRY_TER: CTE Mask                       */
#define DRY_TER_CTE_SHIFT                        (5U)                                                /*!< DRY_TER: CTE Position                   */
#define DRY_TER_CTE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_CTE_SHIFT))&DRY_TER_CTE_MASK) /*!< DRY_TER                                 */
#define DRY_TER_TTE_MASK                         (0x40U)                                             /*!< DRY_TER: TTE Mask                       */
#define DRY_TER_TTE_SHIFT                        (6U)                                                /*!< DRY_TER: TTE Position                   */
#define DRY_TER_TTE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_TTE_SHIFT))&DRY_TER_TTE_MASK) /*!< DRY_TER                                 */
#define DRY_TER_STE_MASK                         (0x80U)                                             /*!< DRY_TER: STE Mask                       */
#define DRY_TER_STE_SHIFT                        (7U)                                                /*!< DRY_TER: STE Position                   */
#define DRY_TER_STE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_STE_SHIFT))&DRY_TER_STE_MASK) /*!< DRY_TER                                 */
#define DRY_TER_FSE_MASK                         (0x100U)                                            /*!< DRY_TER: FSE Mask                       */
#define DRY_TER_FSE_SHIFT                        (8U)                                                /*!< DRY_TER: FSE Position                   */
#define DRY_TER_FSE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_FSE_SHIFT))&DRY_TER_FSE_MASK) /*!< DRY_TER                                 */
#define DRY_TER_TME_MASK                         (0x200U)                                            /*!< DRY_TER: TME Mask                       */
#define DRY_TER_TME_SHIFT                        (9U)                                                /*!< DRY_TER: TME Position                   */
#define DRY_TER_TME(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_TME_SHIFT))&DRY_TER_TME_MASK) /*!< DRY_TER                                 */
#define DRY_TER_TPE_MASK                         (0xFF0000U)                                         /*!< DRY_TER: TPE Mask                       */
#define DRY_TER_TPE_SHIFT                        (16U)                                               /*!< DRY_TER: TPE Position                   */
#define DRY_TER_TPE(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_TER_TPE_SHIFT))&DRY_TER_TPE_MASK) /*!< DRY_TER                                 */
/* ------- PDR Bit Fields                           ------ */
#define DRY_PDR_TPD_MASK                         (0xFFU)                                             /*!< DRY_PDR: TPD Mask                       */
#define DRY_PDR_TPD_SHIFT                        (0U)                                                /*!< DRY_PDR: TPD Position                   */
#define DRY_PDR_TPD(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_PDR_TPD_SHIFT))&DRY_PDR_TPD_MASK) /*!< DRY_PDR                                 */
#define DRY_PDR_TPOD_MASK                        (0xFF0000U)                                         /*!< DRY_PDR: TPOD Mask                      */
#define DRY_PDR_TPOD_SHIFT                       (16U)                                               /*!< DRY_PDR: TPOD Position                  */
#define DRY_PDR_TPOD(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_PDR_TPOD_SHIFT))&DRY_PDR_TPOD_MASK) /*!< DRY_PDR                                 */
/* ------- PPR Bit Fields                           ------ */
#define DRY_PPR_TPP_MASK                         (0xFFU)                                             /*!< DRY_PPR: TPP Mask                       */
#define DRY_PPR_TPP_SHIFT                        (0U)                                                /*!< DRY_PPR: TPP Position                   */
#define DRY_PPR_TPP(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_PPR_TPP_SHIFT))&DRY_PPR_TPP_MASK) /*!< DRY_PPR                                 */
#define DRY_PPR_TPID_MASK                        (0xFF0000U)                                         /*!< DRY_PPR: TPID Mask                      */
#define DRY_PPR_TPID_SHIFT                       (16U)                                               /*!< DRY_PPR: TPID Position                  */
#define DRY_PPR_TPID(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_PPR_TPID_SHIFT))&DRY_PPR_TPID_MASK) /*!< DRY_PPR                                 */
/* ------- ATR Bit Fields                           ------ */
#define DRY_ATR_ATSR_MASK                        (0xFFFFU)                                           /*!< DRY_ATR: ATSR Mask                      */
#define DRY_ATR_ATSR_SHIFT                       (0U)                                                /*!< DRY_ATR: ATSR Position                  */
#define DRY_ATR_ATSR(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_ATR_ATSR_SHIFT))&DRY_ATR_ATSR_MASK) /*!< DRY_ATR                                 */
#define DRY_ATR_ATP_MASK                         (0xFFFF0000U)                                       /*!< DRY_ATR: ATP Mask                       */
#define DRY_ATR_ATP_SHIFT                        (16U)                                               /*!< DRY_ATR: ATP Position                   */
#define DRY_ATR_ATP(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_ATR_ATP_SHIFT))&DRY_ATR_ATP_MASK) /*!< DRY_ATR                                 */
/* ------- PGFR Bit Fields                          ------ */
#define DRY_PGFR_GFW_MASK                        (0x3FU)                                             /*!< DRY_PGFR: GFW Mask                      */
#define DRY_PGFR_GFW_SHIFT                       (0U)                                                /*!< DRY_PGFR: GFW Position                  */
#define DRY_PGFR_GFW(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_PGFR_GFW_SHIFT))&DRY_PGFR_GFW_MASK) /*!< DRY_PGFR                                */
#define DRY_PGFR_GFP_MASK                        (0x40U)                                             /*!< DRY_PGFR: GFP Mask                      */
#define DRY_PGFR_GFP_SHIFT                       (6U)                                                /*!< DRY_PGFR: GFP Position                  */
#define DRY_PGFR_GFP(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_PGFR_GFP_SHIFT))&DRY_PGFR_GFP_MASK) /*!< DRY_PGFR                                */
#define DRY_PGFR_GFE_MASK                        (0x80U)                                             /*!< DRY_PGFR: GFE Mask                      */
#define DRY_PGFR_GFE_SHIFT                       (7U)                                                /*!< DRY_PGFR: GFE Position                  */
#define DRY_PGFR_GFE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_PGFR_GFE_SHIFT))&DRY_PGFR_GFE_MASK) /*!< DRY_PGFR                                */
#define DRY_PGFR_TPEX_MASK                       (0x30000U)                                          /*!< DRY_PGFR: TPEX Mask                     */
#define DRY_PGFR_TPEX_SHIFT                      (16U)                                               /*!< DRY_PGFR: TPEX Position                 */
#define DRY_PGFR_TPEX(x)                         (((uint32_t)(((uint32_t)(x))<<DRY_PGFR_TPEX_SHIFT))&DRY_PGFR_TPEX_MASK) /*!< DRY_PGFR                                */
#define DRY_PGFR_TPE_MASK                        (0x1000000U)                                        /*!< DRY_PGFR: TPE Mask                      */
#define DRY_PGFR_TPE_SHIFT                       (24U)                                               /*!< DRY_PGFR: TPE Position                  */
#define DRY_PGFR_TPE(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_PGFR_TPE_SHIFT))&DRY_PGFR_TPE_MASK) /*!< DRY_PGFR                                */
/* ------- WAC Bit Fields                           ------ */
#define DRY_WAC_SKVW_MASK                        (0x2U)                                              /*!< DRY_WAC: SKVW Mask                      */
#define DRY_WAC_SKVW_SHIFT                       (1U)                                                /*!< DRY_WAC: SKVW Position                  */
#define DRY_WAC_SKVW(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_WAC_SKVW_SHIFT))&DRY_WAC_SKVW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_SKWRW_MASK                       (0x4U)                                              /*!< DRY_WAC: SKWRW Mask                     */
#define DRY_WAC_SKWRW_SHIFT                      (2U)                                                /*!< DRY_WAC: SKWRW Position                 */
#define DRY_WAC_SKWRW(x)                         (((uint32_t)(((uint32_t)(x))<<DRY_WAC_SKWRW_SHIFT))&DRY_WAC_SKWRW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_SKRRW_MASK                       (0x8U)                                              /*!< DRY_WAC: SKRRW Mask                     */
#define DRY_WAC_SKRRW_SHIFT                      (3U)                                                /*!< DRY_WAC: SKRRW Position                 */
#define DRY_WAC_SKRRW(x)                         (((uint32_t)(((uint32_t)(x))<<DRY_WAC_SKRRW_SHIFT))&DRY_WAC_SKRRW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_CRW_MASK                         (0x10U)                                             /*!< DRY_WAC: CRW Mask                       */
#define DRY_WAC_CRW_SHIFT                        (4U)                                                /*!< DRY_WAC: CRW Position                   */
#define DRY_WAC_CRW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_CRW_SHIFT))&DRY_WAC_CRW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_SRW_MASK                         (0x20U)                                             /*!< DRY_WAC: SRW Mask                       */
#define DRY_WAC_SRW_SHIFT                        (5U)                                                /*!< DRY_WAC: SRW Position                   */
#define DRY_WAC_SRW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_SRW_SHIFT))&DRY_WAC_SRW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_LRW_MASK                         (0x40U)                                             /*!< DRY_WAC: LRW Mask                       */
#define DRY_WAC_LRW_SHIFT                        (6U)                                                /*!< DRY_WAC: LRW Position                   */
#define DRY_WAC_LRW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_LRW_SHIFT))&DRY_WAC_LRW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_IEW_MASK                         (0x80U)                                             /*!< DRY_WAC: IEW Mask                       */
#define DRY_WAC_IEW_SHIFT                        (7U)                                                /*!< DRY_WAC: IEW Position                   */
#define DRY_WAC_IEW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_IEW_SHIFT))&DRY_WAC_IEW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_TSRW_MASK                        (0x100U)                                            /*!< DRY_WAC: TSRW Mask                      */
#define DRY_WAC_TSRW_SHIFT                       (8U)                                                /*!< DRY_WAC: TSRW Position                  */
#define DRY_WAC_TSRW(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_WAC_TSRW_SHIFT))&DRY_WAC_TSRW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_TEW_MASK                         (0x200U)                                            /*!< DRY_WAC: TEW Mask                       */
#define DRY_WAC_TEW_SHIFT                        (9U)                                                /*!< DRY_WAC: TEW Position                   */
#define DRY_WAC_TEW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_TEW_SHIFT))&DRY_WAC_TEW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_PDW_MASK                         (0x400U)                                            /*!< DRY_WAC: PDW Mask                       */
#define DRY_WAC_PDW_SHIFT                        (10U)                                               /*!< DRY_WAC: PDW Position                   */
#define DRY_WAC_PDW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_PDW_SHIFT))&DRY_WAC_PDW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_PPW_MASK                         (0x800U)                                            /*!< DRY_WAC: PPW Mask                       */
#define DRY_WAC_PPW_SHIFT                        (11U)                                               /*!< DRY_WAC: PPW Position                   */
#define DRY_WAC_PPW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_PPW_SHIFT))&DRY_WAC_PPW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_ATW_MASK                         (0x3000U)                                           /*!< DRY_WAC: ATW Mask                       */
#define DRY_WAC_ATW_SHIFT                        (12U)                                               /*!< DRY_WAC: ATW Position                   */
#define DRY_WAC_ATW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_ATW_SHIFT))&DRY_WAC_ATW_MASK) /*!< DRY_WAC                                 */
#define DRY_WAC_GFW_MASK                         (0xFF0000U)                                         /*!< DRY_WAC: GFW Mask                       */
#define DRY_WAC_GFW_SHIFT                        (16U)                                               /*!< DRY_WAC: GFW Position                   */
#define DRY_WAC_GFW(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_WAC_GFW_SHIFT))&DRY_WAC_GFW_MASK) /*!< DRY_WAC                                 */
/* ------- RAC Bit Fields                           ------ */
#define DRY_RAC_SKVR_MASK                        (0x2U)                                              /*!< DRY_RAC: SKVR Mask                      */
#define DRY_RAC_SKVR_SHIFT                       (1U)                                                /*!< DRY_RAC: SKVR Position                  */
#define DRY_RAC_SKVR(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_RAC_SKVR_SHIFT))&DRY_RAC_SKVR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_SKWRR_MASK                       (0x4U)                                              /*!< DRY_RAC: SKWRR Mask                     */
#define DRY_RAC_SKWRR_SHIFT                      (2U)                                                /*!< DRY_RAC: SKWRR Position                 */
#define DRY_RAC_SKWRR(x)                         (((uint32_t)(((uint32_t)(x))<<DRY_RAC_SKWRR_SHIFT))&DRY_RAC_SKWRR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_SKRRR_MASK                       (0x8U)                                              /*!< DRY_RAC: SKRRR Mask                     */
#define DRY_RAC_SKRRR_SHIFT                      (3U)                                                /*!< DRY_RAC: SKRRR Position                 */
#define DRY_RAC_SKRRR(x)                         (((uint32_t)(((uint32_t)(x))<<DRY_RAC_SKRRR_SHIFT))&DRY_RAC_SKRRR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_CRR_MASK                         (0x10U)                                             /*!< DRY_RAC: CRR Mask                       */
#define DRY_RAC_CRR_SHIFT                        (4U)                                                /*!< DRY_RAC: CRR Position                   */
#define DRY_RAC_CRR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_CRR_SHIFT))&DRY_RAC_CRR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_SRR_MASK                         (0x20U)                                             /*!< DRY_RAC: SRR Mask                       */
#define DRY_RAC_SRR_SHIFT                        (5U)                                                /*!< DRY_RAC: SRR Position                   */
#define DRY_RAC_SRR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_SRR_SHIFT))&DRY_RAC_SRR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_LRR_MASK                         (0x40U)                                             /*!< DRY_RAC: LRR Mask                       */
#define DRY_RAC_LRR_SHIFT                        (6U)                                                /*!< DRY_RAC: LRR Position                   */
#define DRY_RAC_LRR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_LRR_SHIFT))&DRY_RAC_LRR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_IER_MASK                         (0x80U)                                             /*!< DRY_RAC: IER Mask                       */
#define DRY_RAC_IER_SHIFT                        (7U)                                                /*!< DRY_RAC: IER Position                   */
#define DRY_RAC_IER(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_IER_SHIFT))&DRY_RAC_IER_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_TSRR_MASK                        (0x100U)                                            /*!< DRY_RAC: TSRR Mask                      */
#define DRY_RAC_TSRR_SHIFT                       (8U)                                                /*!< DRY_RAC: TSRR Position                  */
#define DRY_RAC_TSRR(x)                          (((uint32_t)(((uint32_t)(x))<<DRY_RAC_TSRR_SHIFT))&DRY_RAC_TSRR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_TER_MASK                         (0x200U)                                            /*!< DRY_RAC: TER Mask                       */
#define DRY_RAC_TER_SHIFT                        (9U)                                                /*!< DRY_RAC: TER Position                   */
#define DRY_RAC_TER(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_TER_SHIFT))&DRY_RAC_TER_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_PDR_MASK                         (0x400U)                                            /*!< DRY_RAC: PDR Mask                       */
#define DRY_RAC_PDR_SHIFT                        (10U)                                               /*!< DRY_RAC: PDR Position                   */
#define DRY_RAC_PDR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_PDR_SHIFT))&DRY_RAC_PDR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_PPR_MASK                         (0x800U)                                            /*!< DRY_RAC: PPR Mask                       */
#define DRY_RAC_PPR_SHIFT                        (11U)                                               /*!< DRY_RAC: PPR Position                   */
#define DRY_RAC_PPR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_PPR_SHIFT))&DRY_RAC_PPR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_ATR_MASK                         (0x3000U)                                           /*!< DRY_RAC: ATR Mask                       */
#define DRY_RAC_ATR_SHIFT                        (12U)                                               /*!< DRY_RAC: ATR Position                   */
#define DRY_RAC_ATR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_ATR_SHIFT))&DRY_RAC_ATR_MASK) /*!< DRY_RAC                                 */
#define DRY_RAC_GFR_MASK                         (0xFF0000U)                                         /*!< DRY_RAC: GFR Mask                       */
#define DRY_RAC_GFR_SHIFT                        (16U)                                               /*!< DRY_RAC: GFR Position                   */
#define DRY_RAC_GFR(x)                           (((uint32_t)(((uint32_t)(x))<<DRY_RAC_GFR_SHIFT))&DRY_RAC_GFR_MASK) /*!< DRY_RAC                                 */
/* ------- SKR Bit Fields                           ------ */
#define DRY_SKR_SK_MASK                          (0xFFFFFFFFU)                                       /*!< DRY_SKR: SK Mask                        */
#define DRY_SKR_SK_SHIFT                         (0U)                                                /*!< DRY_SKR: SK Position                    */
#define DRY_SKR_SK(x)                            (((uint32_t)(((uint32_t)(x))<<DRY_SKR_SK_SHIFT))&DRY_SKR_SK_MASK) /*!< DRY_SKR                                 */
/* ------- SWAC Bit Fields                          ------ */
#define DRY_SWAC_SKRW_MASK                       (0xFFU)                                             /*!< DRY_SWAC: SKRW Mask                     */
#define DRY_SWAC_SKRW_SHIFT                      (0U)                                                /*!< DRY_SWAC: SKRW Position                 */
#define DRY_SWAC_SKRW(x)                         (((uint32_t)(((uint32_t)(x))<<DRY_SWAC_SKRW_SHIFT))&DRY_SWAC_SKRW_MASK) /*!< DRY_SWAC                                */
/* ------- SRAC Bit Fields                          ------ */
#define DRY_SRAC_SKRR_MASK                       (0xFFU)                                             /*!< DRY_SRAC: SKRR Mask                     */
#define DRY_SRAC_SKRR_SHIFT                      (0U)                                                /*!< DRY_SRAC: SKRR Position                 */
#define DRY_SRAC_SKRR(x)                         (((uint32_t)(((uint32_t)(x))<<DRY_SRAC_SKRR_SHIFT))&DRY_SRAC_SKRR_MASK) /*!< DRY_SRAC                                */
/**
 * @} */ /* End group DRY_Register_Masks_GROUP 
 */

/* DRY - Peripheral instance base addresses */
#define DRY_BasePtr                    0x40042000UL //!< Peripheral base address
#define DRY                            ((DRY_Type *) DRY_BasePtr) //!< Freescale base pointer
#define DRY_BASE_PTR                   (DRY) //!< Freescale style base pointer
/**
 * @} */ /* End group DRY_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EWM_Peripheral_access_layer_GROUP EWM Peripheral Access Layer
* @brief C Struct for EWM
* @{
*/

/* ================================================================================ */
/* ================           EWM (file:EWM_2)                     ================ */
/* ================================================================================ */

/**
 * @brief External Watchdog Monitor
 */
/**
* @addtogroup EWM_structs_GROUP EWM struct
* @brief Struct for EWM
* @{
*/
typedef struct {                                /*       EWM Structure                                                */
   __IO uint8_t   CTRL;                         /**< 0000: Control Register                                             */
   __O  uint8_t   SERV;                         /**< 0001: Service Register                                             */
   __IO uint8_t   CMPL;                         /**< 0002: Compare Low Register                                         */
   __IO uint8_t   CMPH;                         /**< 0003: Compare High Register                                        */
} EWM_Type;

/**
 * @} */ /* End group EWM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EWM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EWM_Register_Masks_GROUP EWM Register Masks
* @brief Register Masks for EWM
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define EWM_CTRL_EWMEN_MASK                      (0x1U)                                              /*!< EWM_CTRL: EWMEN Mask                    */
#define EWM_CTRL_EWMEN_SHIFT                     (0U)                                                /*!< EWM_CTRL: EWMEN Position                */
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_EWMEN_SHIFT))&EWM_CTRL_EWMEN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_ASSIN_MASK                      (0x2U)                                              /*!< EWM_CTRL: ASSIN Mask                    */
#define EWM_CTRL_ASSIN_SHIFT                     (1U)                                                /*!< EWM_CTRL: ASSIN Position                */
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_ASSIN_SHIFT))&EWM_CTRL_ASSIN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_INEN_MASK                       (0x4U)                                              /*!< EWM_CTRL: INEN Mask                     */
#define EWM_CTRL_INEN_SHIFT                      (2U)                                                /*!< EWM_CTRL: INEN Position                 */
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_INEN_SHIFT))&EWM_CTRL_INEN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_INTEN_MASK                      (0x8U)                                              /*!< EWM_CTRL: INTEN Mask                    */
#define EWM_CTRL_INTEN_SHIFT                     (3U)                                                /*!< EWM_CTRL: INTEN Position                */
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_INTEN_SHIFT))&EWM_CTRL_INTEN_MASK) /*!< EWM_CTRL                                */
/* ------- SERV Bit Fields                          ------ */
#define EWM_SERV_SERVICE_MASK                    (0xFFU)                                             /*!< EWM_SERV: SERVICE Mask                  */
#define EWM_SERV_SERVICE_SHIFT                   (0U)                                                /*!< EWM_SERV: SERVICE Position              */
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<EWM_SERV_SERVICE_SHIFT))&EWM_SERV_SERVICE_MASK) /*!< EWM_SERV                                */
/* ------- CMPL Bit Fields                          ------ */
#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)                                             /*!< EWM_CMPL: COMPAREL Mask                 */
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)                                                /*!< EWM_CMPL: COMPAREL Position             */
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK) /*!< EWM_CMPL                                */
/* ------- CMPH Bit Fields                          ------ */
#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)                                             /*!< EWM_CMPH: COMPAREH Mask                 */
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)                                                /*!< EWM_CMPH: COMPAREH Position             */
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPH_COMPAREH_SHIFT))&EWM_CMPH_COMPAREH_MASK) /*!< EWM_CMPH                                */
/**
 * @} */ /* End group EWM_Register_Masks_GROUP 
 */

/* EWM - Peripheral instance base addresses */
#define EWM_BasePtr                    0x40061000UL //!< Peripheral base address
#define EWM                            ((EWM_Type *) EWM_BasePtr) //!< Freescale base pointer
#define EWM_BASE_PTR                   (EWM) //!< Freescale style base pointer
/**
 * @} */ /* End group EWM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FMC_Peripheral_access_layer_GROUP FMC Peripheral Access Layer
* @brief C Struct for FMC
* @{
*/

/* ================================================================================ */
/* ================           FMC (file:FMC_MK11D5)                ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Controller
 */
/**
* @addtogroup FMC_structs_GROUP FMC struct
* @brief Struct for FMC
* @{
*/
typedef struct {                                /*       FMC Structure                                                */
   __IO uint32_t  PFAPR;                        /**< 0000: Flash Access Protection Register                             */
   __IO uint32_t  PFB0CR;                       /**< 0004: Flash Bank 0 Control Register                                */
   __IO uint32_t  PFB1CR;                       /**< 0008: Flash Bank 1 Control Register                                */
        uint8_t   RESERVED_0[244];             
   struct {
      __IO uint32_t  S0;                        /**< 0100: Cache Tag Storage                                            */
      __IO uint32_t  S1;                        /**< 0104: Cache Tag Storage                                            */
   } TAGVDW[4];                                 /**< 0100: (cluster: size=0x0020, 32)                                   */
        uint8_t   RESERVED_2[224];             
   struct {
      __IO uint32_t  S0U;                       /**< 0200: Cache Data Storage (upper word)                              */
      __IO uint32_t  S0L;                       /**< 0204: Cache Data Storage (lower word)                              */
      __IO uint32_t  S1U;                       /**< 0208: Cache Data Storage (upper word)                              */
      __IO uint32_t  S1L;                       /**< 020C: Cache Data Storage (lower word)                              */
   } DATAW[4];                                  /**< 0200: (cluster: size=0x0040, 64)                                   */
} FMC_Type;

/**
 * @} */ /* End group FMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FMC_Register_Masks_GROUP FMC Register Masks
* @brief Register Masks for FMC
* @{
*/
/* ------- PFAPR Bit Fields                         ------ */
#define FMC_PFAPR_M0AP_MASK                      (0x3U)                                              /*!< FMC_PFAPR: M0AP Mask                    */
#define FMC_PFAPR_M0AP_SHIFT                     (0U)                                                /*!< FMC_PFAPR: M0AP Position                */
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0AP_SHIFT))&FMC_PFAPR_M0AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M1AP_MASK                      (0xCU)                                              /*!< FMC_PFAPR: M1AP Mask                    */
#define FMC_PFAPR_M1AP_SHIFT                     (2U)                                                /*!< FMC_PFAPR: M1AP Position                */
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1AP_SHIFT))&FMC_PFAPR_M1AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M2AP_MASK                      (0x30U)                                             /*!< FMC_PFAPR: M2AP Mask                    */
#define FMC_PFAPR_M2AP_SHIFT                     (4U)                                                /*!< FMC_PFAPR: M2AP Position                */
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2AP_SHIFT))&FMC_PFAPR_M2AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M3AP_MASK                      (0xC0U)                                             /*!< FMC_PFAPR: M3AP Mask                    */
#define FMC_PFAPR_M3AP_SHIFT                     (6U)                                                /*!< FMC_PFAPR: M3AP Position                */
#define FMC_PFAPR_M3AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M3AP_SHIFT))&FMC_PFAPR_M3AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M4AP_MASK                      (0x300U)                                            /*!< FMC_PFAPR: M4AP Mask                    */
#define FMC_PFAPR_M4AP_SHIFT                     (8U)                                                /*!< FMC_PFAPR: M4AP Position                */
#define FMC_PFAPR_M4AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M4AP_SHIFT))&FMC_PFAPR_M4AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M5AP_MASK                      (0xC00U)                                            /*!< FMC_PFAPR: M5AP Mask                    */
#define FMC_PFAPR_M5AP_SHIFT                     (10U)                                               /*!< FMC_PFAPR: M5AP Position                */
#define FMC_PFAPR_M5AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M5AP_SHIFT))&FMC_PFAPR_M5AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M6AP_MASK                      (0x3000U)                                           /*!< FMC_PFAPR: M6AP Mask                    */
#define FMC_PFAPR_M6AP_SHIFT                     (12U)                                               /*!< FMC_PFAPR: M6AP Position                */
#define FMC_PFAPR_M6AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M6AP_SHIFT))&FMC_PFAPR_M6AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M7AP_MASK                      (0xC000U)                                           /*!< FMC_PFAPR: M7AP Mask                    */
#define FMC_PFAPR_M7AP_SHIFT                     (14U)                                               /*!< FMC_PFAPR: M7AP Position                */
#define FMC_PFAPR_M7AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M7AP_SHIFT))&FMC_PFAPR_M7AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M0PFD_MASK                     (0x10000U)                                          /*!< FMC_PFAPR: M0PFD Mask                   */
#define FMC_PFAPR_M0PFD_SHIFT                    (16U)                                               /*!< FMC_PFAPR: M0PFD Position               */
#define FMC_PFAPR_M0PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0PFD_SHIFT))&FMC_PFAPR_M0PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M1PFD_MASK                     (0x20000U)                                          /*!< FMC_PFAPR: M1PFD Mask                   */
#define FMC_PFAPR_M1PFD_SHIFT                    (17U)                                               /*!< FMC_PFAPR: M1PFD Position               */
#define FMC_PFAPR_M1PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1PFD_SHIFT))&FMC_PFAPR_M1PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M2PFD_MASK                     (0x40000U)                                          /*!< FMC_PFAPR: M2PFD Mask                   */
#define FMC_PFAPR_M2PFD_SHIFT                    (18U)                                               /*!< FMC_PFAPR: M2PFD Position               */
#define FMC_PFAPR_M2PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2PFD_SHIFT))&FMC_PFAPR_M2PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M3PFD_MASK                     (0x80000U)                                          /*!< FMC_PFAPR: M3PFD Mask                   */
#define FMC_PFAPR_M3PFD_SHIFT                    (19U)                                               /*!< FMC_PFAPR: M3PFD Position               */
#define FMC_PFAPR_M3PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M3PFD_SHIFT))&FMC_PFAPR_M3PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M4PFD_MASK                     (0x100000U)                                         /*!< FMC_PFAPR: M4PFD Mask                   */
#define FMC_PFAPR_M4PFD_SHIFT                    (20U)                                               /*!< FMC_PFAPR: M4PFD Position               */
#define FMC_PFAPR_M4PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M4PFD_SHIFT))&FMC_PFAPR_M4PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M5PFD_MASK                     (0x200000U)                                         /*!< FMC_PFAPR: M5PFD Mask                   */
#define FMC_PFAPR_M5PFD_SHIFT                    (21U)                                               /*!< FMC_PFAPR: M5PFD Position               */
#define FMC_PFAPR_M5PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M5PFD_SHIFT))&FMC_PFAPR_M5PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M6PFD_MASK                     (0x400000U)                                         /*!< FMC_PFAPR: M6PFD Mask                   */
#define FMC_PFAPR_M6PFD_SHIFT                    (22U)                                               /*!< FMC_PFAPR: M6PFD Position               */
#define FMC_PFAPR_M6PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M6PFD_SHIFT))&FMC_PFAPR_M6PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M7PFD_MASK                     (0x800000U)                                         /*!< FMC_PFAPR: M7PFD Mask                   */
#define FMC_PFAPR_M7PFD_SHIFT                    (23U)                                               /*!< FMC_PFAPR: M7PFD Position               */
#define FMC_PFAPR_M7PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M7PFD_SHIFT))&FMC_PFAPR_M7PFD_MASK) /*!< FMC_PFAPR                               */
/* ------- PFB0CR Bit Fields                        ------ */
#define FMC_PFB0CR_B0SEBE_MASK                   (0x1U)                                              /*!< FMC_PFB0CR: B0SEBE Mask                 */
#define FMC_PFB0CR_B0SEBE_SHIFT                  (0U)                                                /*!< FMC_PFB0CR: B0SEBE Position             */
#define FMC_PFB0CR_B0SEBE(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0SEBE_SHIFT))&FMC_PFB0CR_B0SEBE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0IPE_MASK                    (0x2U)                                              /*!< FMC_PFB0CR: B0IPE Mask                  */
#define FMC_PFB0CR_B0IPE_SHIFT                   (1U)                                                /*!< FMC_PFB0CR: B0IPE Position              */
#define FMC_PFB0CR_B0IPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0IPE_SHIFT))&FMC_PFB0CR_B0IPE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0DPE_MASK                    (0x4U)                                              /*!< FMC_PFB0CR: B0DPE Mask                  */
#define FMC_PFB0CR_B0DPE_SHIFT                   (2U)                                                /*!< FMC_PFB0CR: B0DPE Position              */
#define FMC_PFB0CR_B0DPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0DPE_SHIFT))&FMC_PFB0CR_B0DPE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0ICE_MASK                    (0x8U)                                              /*!< FMC_PFB0CR: B0ICE Mask                  */
#define FMC_PFB0CR_B0ICE_SHIFT                   (3U)                                                /*!< FMC_PFB0CR: B0ICE Position              */
#define FMC_PFB0CR_B0ICE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0ICE_SHIFT))&FMC_PFB0CR_B0ICE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0DCE_MASK                    (0x10U)                                             /*!< FMC_PFB0CR: B0DCE Mask                  */
#define FMC_PFB0CR_B0DCE_SHIFT                   (4U)                                                /*!< FMC_PFB0CR: B0DCE Position              */
#define FMC_PFB0CR_B0DCE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0DCE_SHIFT))&FMC_PFB0CR_B0DCE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CRC_MASK                      (0xE0U)                                             /*!< FMC_PFB0CR: CRC Mask                    */
#define FMC_PFB0CR_CRC_SHIFT                     (5U)                                                /*!< FMC_PFB0CR: CRC Position                */
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CRC_SHIFT))&FMC_PFB0CR_CRC_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0MW_MASK                     (0x60000U)                                          /*!< FMC_PFB0CR: B0MW Mask                   */
#define FMC_PFB0CR_B0MW_SHIFT                    (17U)                                               /*!< FMC_PFB0CR: B0MW Position               */
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0MW_SHIFT))&FMC_PFB0CR_B0MW_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_S_B_INV_MASK                  (0x80000U)                                          /*!< FMC_PFB0CR: S_B_INV Mask                */
#define FMC_PFB0CR_S_B_INV_SHIFT                 (19U)                                               /*!< FMC_PFB0CR: S_B_INV Position            */
#define FMC_PFB0CR_S_B_INV(x)                    (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_S_B_INV_SHIFT))&FMC_PFB0CR_S_B_INV_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CINV_WAY_MASK                 (0xF00000U)                                         /*!< FMC_PFB0CR: CINV_WAY Mask               */
#define FMC_PFB0CR_CINV_WAY_SHIFT                (20U)                                               /*!< FMC_PFB0CR: CINV_WAY Position           */
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CINV_WAY_SHIFT))&FMC_PFB0CR_CINV_WAY_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CLCK_WAY_MASK                 (0xF000000U)                                        /*!< FMC_PFB0CR: CLCK_WAY Mask               */
#define FMC_PFB0CR_CLCK_WAY_SHIFT                (24U)                                               /*!< FMC_PFB0CR: CLCK_WAY Position           */
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CLCK_WAY_SHIFT))&FMC_PFB0CR_CLCK_WAY_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0RWSC_MASK                   (0xF0000000U)                                       /*!< FMC_PFB0CR: B0RWSC Mask                 */
#define FMC_PFB0CR_B0RWSC_SHIFT                  (28U)                                               /*!< FMC_PFB0CR: B0RWSC Position             */
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0RWSC_SHIFT))&FMC_PFB0CR_B0RWSC_MASK) /*!< FMC_PFB0CR                              */
/* ------- PFB1CR Bit Fields                        ------ */
#define FMC_PFB1CR_B1SEBE_MASK                   (0x1U)                                              /*!< FMC_PFB1CR: B1SEBE Mask                 */
#define FMC_PFB1CR_B1SEBE_SHIFT                  (0U)                                                /*!< FMC_PFB1CR: B1SEBE Position             */
#define FMC_PFB1CR_B1SEBE(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1SEBE_SHIFT))&FMC_PFB1CR_B1SEBE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1IPE_MASK                    (0x2U)                                              /*!< FMC_PFB1CR: B1IPE Mask                  */
#define FMC_PFB1CR_B1IPE_SHIFT                   (1U)                                                /*!< FMC_PFB1CR: B1IPE Position              */
#define FMC_PFB1CR_B1IPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1IPE_SHIFT))&FMC_PFB1CR_B1IPE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1DPE_MASK                    (0x4U)                                              /*!< FMC_PFB1CR: B1DPE Mask                  */
#define FMC_PFB1CR_B1DPE_SHIFT                   (2U)                                                /*!< FMC_PFB1CR: B1DPE Position              */
#define FMC_PFB1CR_B1DPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1DPE_SHIFT))&FMC_PFB1CR_B1DPE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1ICE_MASK                    (0x8U)                                              /*!< FMC_PFB1CR: B1ICE Mask                  */
#define FMC_PFB1CR_B1ICE_SHIFT                   (3U)                                                /*!< FMC_PFB1CR: B1ICE Position              */
#define FMC_PFB1CR_B1ICE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1ICE_SHIFT))&FMC_PFB1CR_B1ICE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1DCE_MASK                    (0x10U)                                             /*!< FMC_PFB1CR: B1DCE Mask                  */
#define FMC_PFB1CR_B1DCE_SHIFT                   (4U)                                                /*!< FMC_PFB1CR: B1DCE Position              */
#define FMC_PFB1CR_B1DCE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1DCE_SHIFT))&FMC_PFB1CR_B1DCE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1MW_MASK                     (0x60000U)                                          /*!< FMC_PFB1CR: B1MW Mask                   */
#define FMC_PFB1CR_B1MW_SHIFT                    (17U)                                               /*!< FMC_PFB1CR: B1MW Position               */
#define FMC_PFB1CR_B1MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1MW_SHIFT))&FMC_PFB1CR_B1MW_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1RWSC_MASK                   (0xF0000000U)                                       /*!< FMC_PFB1CR: B1RWSC Mask                 */
#define FMC_PFB1CR_B1RWSC_SHIFT                  (28U)                                               /*!< FMC_PFB1CR: B1RWSC Position             */
#define FMC_PFB1CR_B1RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1RWSC_SHIFT))&FMC_PFB1CR_B1RWSC_MASK) /*!< FMC_PFB1CR                              */
/* ------- S0 Bit Fields                            ------ */
#define FMC_TAGVD0_valid_MASK                    (0x1U)                                              /*!< FMC_TAGVD0: valid Mask                  */
#define FMC_TAGVD0_valid_SHIFT                   (0U)                                                /*!< FMC_TAGVD0: valid Position              */
#define FMC_TAGVD0_valid(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_TAGVD0_valid_SHIFT))&FMC_TAGVD0_valid_MASK) /*!< FMC_TAGVD0                              */
#define FMC_TAGVD0_tag_MASK                      (0x7FFF0U)                                          /*!< FMC_TAGVD0: tag Mask                    */
#define FMC_TAGVD0_tag_SHIFT                     (4U)                                                /*!< FMC_TAGVD0: tag Position                */
#define FMC_TAGVD0_tag(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_TAGVD0_tag_SHIFT))&FMC_TAGVD0_tag_MASK) /*!< FMC_TAGVD0                              */
/* ------- S0U Bit Fields                           ------ */
#define FMC_DATAW0U_data_MASK                    (0xFFFFFFFFU)                                       /*!< FMC_DATAW0U: data Mask                  */
#define FMC_DATAW0U_data_SHIFT                   (0U)                                                /*!< FMC_DATAW0U: data Position              */
#define FMC_DATAW0U_data(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_DATAW0U_data_SHIFT))&FMC_DATAW0U_data_MASK) /*!< FMC_DATAW0U                             */
/* ------- S0L Bit Fields                           ------ */
#define FMC_DATAW0L_data_MASK                    (0xFFFFFFFFU)                                       /*!< FMC_DATAW0L: data Mask                  */
#define FMC_DATAW0L_data_SHIFT                   (0U)                                                /*!< FMC_DATAW0L: data Position              */
#define FMC_DATAW0L_data(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_DATAW0L_data_SHIFT))&FMC_DATAW0L_data_MASK) /*!< FMC_DATAW0L                             */
/**
 * @} */ /* End group FMC_Register_Masks_GROUP 
 */

/* FMC - Peripheral instance base addresses */
#define FMC_BasePtr                    0x4001F000UL //!< Peripheral base address
#define FMC                            ((FMC_Type *) FMC_BasePtr) //!< Freescale base pointer
#define FMC_BASE_PTR                   (FMC) //!< Freescale style base pointer
/**
 * @} */ /* End group FMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTFL_Peripheral_access_layer_GROUP FTFL Peripheral Access Layer
* @brief C Struct for FTFL
* @{
*/

/* ================================================================================ */
/* ================           FTFL (file:FTFL)                     ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
* @addtogroup FTFL_structs_GROUP FTFL struct
* @brief Struct for FTFL
* @{
*/
typedef struct {                                /*       FTFL Structure                                               */
   __IO uint8_t   FSTAT;                        /**< 0000: Flash Status Register                                        */
   __IO uint8_t   FCNFG;                        /**< 0001: Flash Configuration Register                                 */
   __I  uint8_t   FSEC;                         /**< 0002: Flash Security Register                                      */
   __I  uint8_t   FOPT;                         /**< 0003: Flash Option Register                                        */
   __IO uint8_t   FCCOB3;                       /**< 0004: FCCOB 3 - Usually Flash address [7..0]                       */
   __IO uint8_t   FCCOB2;                       /**< 0005: FCCOB 2 - Usually Flash address [15..8]                      */
   __IO uint8_t   FCCOB1;                       /**< 0006: FCCOB 1 - Usually Flash address [23..16]                     */
   __IO uint8_t   FCCOB0;                       /**< 0007: FCCOB 0 - Usually FCMD (Flash command)                       */
   __IO uint8_t   FCCOB7;                       /**< 0008: FCCOB 7 - Usually Data Byte 3                                */
   __IO uint8_t   FCCOB6;                       /**< 0009: FCCOB 6 - Usually Data Byte 2                                */
   __IO uint8_t   FCCOB5;                       /**< 000A: FCCOB 5 - Usually Data Byte 1                                */
   __IO uint8_t   FCCOB4;                       /**< 000B: FCCOB 4 - Usually Data Byte 0                                */
   __IO uint8_t   FCCOBB;                       /**< 000C: FCCOB B - Usually Data Byte 7                                */
   __IO uint8_t   FCCOBA;                       /**< 000D: FCCOB A - Usually Data Byte 6                                */
   __IO uint8_t   FCCOB9;                       /**< 000E: FCCOB 9 - Usually Data Byte 5                                */
   __IO uint8_t   FCCOB8;                       /**< 000F: FCCOB 8 - Usually Data Byte 4                                */
   __IO uint8_t   FPROT3;                       /**< 0010: Program Flash Protection                                     */
   __IO uint8_t   FPROT2;                       /**< 0011: Program Flash Protection                                     */
   __IO uint8_t   FPROT1;                       /**< 0012: Program Flash Protection                                     */
   __IO uint8_t   FPROT0;                       /**< 0013: Program Flash Protection                                     */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   FEPROT;                       /**< 0016: EEPROM Protection Register                                   */
   __IO uint8_t   FDPROT;                       /**< 0017: Data Flash Protection Register                               */
} FTFL_Type;

/**
 * @} */ /* End group FTFL_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFL' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTFL_Register_Masks_GROUP FTFL Register Masks
* @brief Register Masks for FTFL
* @{
*/
/* ------- FSTAT Bit Fields                         ------ */
#define FTFL_FSTAT_MGSTAT0_MASK                  (0x1U)                                              /*!< FTFL_FSTAT: MGSTAT0 Mask                */
#define FTFL_FSTAT_MGSTAT0_SHIFT                 (0U)                                                /*!< FTFL_FSTAT: MGSTAT0 Position            */
#define FTFL_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_MGSTAT0_SHIFT))&FTFL_FSTAT_MGSTAT0_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_FPVIOL_MASK                   (0x10U)                                             /*!< FTFL_FSTAT: FPVIOL Mask                 */
#define FTFL_FSTAT_FPVIOL_SHIFT                  (4U)                                                /*!< FTFL_FSTAT: FPVIOL Position             */
#define FTFL_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_FPVIOL_SHIFT))&FTFL_FSTAT_FPVIOL_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_ACCERR_MASK                   (0x20U)                                             /*!< FTFL_FSTAT: ACCERR Mask                 */
#define FTFL_FSTAT_ACCERR_SHIFT                  (5U)                                                /*!< FTFL_FSTAT: ACCERR Position             */
#define FTFL_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_ACCERR_SHIFT))&FTFL_FSTAT_ACCERR_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_RDCOLERR_MASK                 (0x40U)                                             /*!< FTFL_FSTAT: RDCOLERR Mask               */
#define FTFL_FSTAT_RDCOLERR_SHIFT                (6U)                                                /*!< FTFL_FSTAT: RDCOLERR Position           */
#define FTFL_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_RDCOLERR_SHIFT))&FTFL_FSTAT_RDCOLERR_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_CCIF_MASK                     (0x80U)                                             /*!< FTFL_FSTAT: CCIF Mask                   */
#define FTFL_FSTAT_CCIF_SHIFT                    (7U)                                                /*!< FTFL_FSTAT: CCIF Position               */
#define FTFL_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_CCIF_SHIFT))&FTFL_FSTAT_CCIF_MASK) /*!< FTFL_FSTAT                              */
/* ------- FCNFG Bit Fields                         ------ */
#define FTFL_FCNFG_EEERDY_MASK                   (0x1U)                                              /*!< FTFL_FCNFG: EEERDY Mask                 */
#define FTFL_FCNFG_EEERDY_SHIFT                  (0U)                                                /*!< FTFL_FCNFG: EEERDY Position             */
#define FTFL_FCNFG_EEERDY(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_EEERDY_SHIFT))&FTFL_FCNFG_EEERDY_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_RAMRDY_MASK                   (0x2U)                                              /*!< FTFL_FCNFG: RAMRDY Mask                 */
#define FTFL_FCNFG_RAMRDY_SHIFT                  (1U)                                                /*!< FTFL_FCNFG: RAMRDY Position             */
#define FTFL_FCNFG_RAMRDY(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_RAMRDY_SHIFT))&FTFL_FCNFG_RAMRDY_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_PFLSH_MASK                    (0x4U)                                              /*!< FTFL_FCNFG: PFLSH Mask                  */
#define FTFL_FCNFG_PFLSH_SHIFT                   (2U)                                                /*!< FTFL_FCNFG: PFLSH Position              */
#define FTFL_FCNFG_PFLSH(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_PFLSH_SHIFT))&FTFL_FCNFG_PFLSH_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_SWAP_MASK                     (0x8U)                                              /*!< FTFL_FCNFG: SWAP Mask                   */
#define FTFL_FCNFG_SWAP_SHIFT                    (3U)                                                /*!< FTFL_FCNFG: SWAP Position               */
#define FTFL_FCNFG_SWAP(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_SWAP_SHIFT))&FTFL_FCNFG_SWAP_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_ERSSUSP_MASK                  (0x10U)                                             /*!< FTFL_FCNFG: ERSSUSP Mask                */
#define FTFL_FCNFG_ERSSUSP_SHIFT                 (4U)                                                /*!< FTFL_FCNFG: ERSSUSP Position            */
#define FTFL_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_ERSSUSP_SHIFT))&FTFL_FCNFG_ERSSUSP_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_ERSAREQ_MASK                  (0x20U)                                             /*!< FTFL_FCNFG: ERSAREQ Mask                */
#define FTFL_FCNFG_ERSAREQ_SHIFT                 (5U)                                                /*!< FTFL_FCNFG: ERSAREQ Position            */
#define FTFL_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_ERSAREQ_SHIFT))&FTFL_FCNFG_ERSAREQ_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_RDCOLLIE_MASK                 (0x40U)                                             /*!< FTFL_FCNFG: RDCOLLIE Mask               */
#define FTFL_FCNFG_RDCOLLIE_SHIFT                (6U)                                                /*!< FTFL_FCNFG: RDCOLLIE Position           */
#define FTFL_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_RDCOLLIE_SHIFT))&FTFL_FCNFG_RDCOLLIE_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_CCIE_MASK                     (0x80U)                                             /*!< FTFL_FCNFG: CCIE Mask                   */
#define FTFL_FCNFG_CCIE_SHIFT                    (7U)                                                /*!< FTFL_FCNFG: CCIE Position               */
#define FTFL_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_CCIE_SHIFT))&FTFL_FCNFG_CCIE_MASK) /*!< FTFL_FCNFG                              */
/* ------- FSEC Bit Fields                          ------ */
#define FTFL_FSEC_SEC_MASK                       (0x3U)                                              /*!< FTFL_FSEC: SEC Mask                     */
#define FTFL_FSEC_SEC_SHIFT                      (0U)                                                /*!< FTFL_FSEC: SEC Position                 */
#define FTFL_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_SEC_SHIFT))&FTFL_FSEC_SEC_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_FSLACC_MASK                    (0xCU)                                              /*!< FTFL_FSEC: FSLACC Mask                  */
#define FTFL_FSEC_FSLACC_SHIFT                   (2U)                                                /*!< FTFL_FSEC: FSLACC Position              */
#define FTFL_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_FSLACC_SHIFT))&FTFL_FSEC_FSLACC_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_MEEN_MASK                      (0x30U)                                             /*!< FTFL_FSEC: MEEN Mask                    */
#define FTFL_FSEC_MEEN_SHIFT                     (4U)                                                /*!< FTFL_FSEC: MEEN Position                */
#define FTFL_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_MEEN_SHIFT))&FTFL_FSEC_MEEN_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_KEYEN_MASK                     (0xC0U)                                             /*!< FTFL_FSEC: KEYEN Mask                   */
#define FTFL_FSEC_KEYEN_SHIFT                    (6U)                                                /*!< FTFL_FSEC: KEYEN Position               */
#define FTFL_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_KEYEN_SHIFT))&FTFL_FSEC_KEYEN_MASK) /*!< FTFL_FSEC                               */
/* ------- FOPT Bit Fields                          ------ */
#define FTFL_FOPT_OPT_MASK                       (0xFFU)                                             /*!< FTFL_FOPT: OPT Mask                     */
#define FTFL_FOPT_OPT_SHIFT                      (0U)                                                /*!< FTFL_FOPT: OPT Position                 */
#define FTFL_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FOPT_OPT_SHIFT))&FTFL_FOPT_OPT_MASK) /*!< FTFL_FOPT                               */
/* ------- FCCOB Bit Fields                         ------ */
#define FTFL_FCCOB_CCOBn_MASK                    (0xFFU)                                             /*!< FTFL_FCCOB: CCOBn Mask                  */
#define FTFL_FCCOB_CCOBn_SHIFT                   (0U)                                                /*!< FTFL_FCCOB: CCOBn Position              */
#define FTFL_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB_CCOBn_SHIFT))&FTFL_FCCOB_CCOBn_MASK) /*!< FTFL_FCCOB                              */
/* ------- FPROT Bit Fields                         ------ */
#define FTFL_FPROT_PROT_MASK                     (0xFFU)                                             /*!< FTFL_FPROT: PROT Mask                   */
#define FTFL_FPROT_PROT_SHIFT                    (0U)                                                /*!< FTFL_FPROT: PROT Position               */
#define FTFL_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT_PROT_SHIFT))&FTFL_FPROT_PROT_MASK) /*!< FTFL_FPROT                              */
/* ------- FEPROT Bit Fields                        ------ */
#define FTFL_FEPROT_EPROT_MASK                   (0xFFU)                                             /*!< FTFL_FEPROT: EPROT Mask                 */
#define FTFL_FEPROT_EPROT_SHIFT                  (0U)                                                /*!< FTFL_FEPROT: EPROT Position             */
#define FTFL_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FEPROT_EPROT_SHIFT))&FTFL_FEPROT_EPROT_MASK) /*!< FTFL_FEPROT                             */
/* ------- FDPROT Bit Fields                        ------ */
#define FTFL_FDPROT_DPROT_MASK                   (0xFFU)                                             /*!< FTFL_FDPROT: DPROT Mask                 */
#define FTFL_FDPROT_DPROT_SHIFT                  (0U)                                                /*!< FTFL_FDPROT: DPROT Position             */
#define FTFL_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FDPROT_DPROT_SHIFT))&FTFL_FDPROT_DPROT_MASK) /*!< FTFL_FDPROT                             */
/**
 * @} */ /* End group FTFL_Register_Masks_GROUP 
 */

/* FTFL - Peripheral instance base addresses */
#define FTFL_BasePtr                   0x40020000UL //!< Peripheral base address
#define FTFL                           ((FTFL_Type *) FTFL_BasePtr) //!< Freescale base pointer
#define FTFL_BASE_PTR                  (FTFL) //!< Freescale style base pointer
/**
 * @} */ /* End group FTFL_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM0 (file:FTM0_8CH)                 ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (8 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[8];                               /**< 000C: (cluster: size=0x0040, 64)                                   */
   __IO uint32_t  CNTIN;                        /**< 004C: Counter Initial Value                                        */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
   __IO uint32_t  MODE;                         /**< 0054: Features Mode Selection                                      */
   __IO uint32_t  SYNC;                         /**< 0058: Synchronization                                              */
   __IO uint32_t  OUTINIT;                      /**< 005C: Initial State for Channels Output                            */
   __IO uint32_t  OUTMASK;                      /**< 0060: Output Mask                                                  */
   __IO uint32_t  COMBINE;                      /**< 0064: Function for Linked Channels                                 */
   __IO uint32_t  DEADTIME;                     /**< 0068: Deadtime Insertion Control                                   */
   __IO uint32_t  EXTTRIG;                      /**< 006C: FTM External Trigger                                         */
   __IO uint32_t  POL;                          /**< 0070: Channels Polarity                                            */
   __IO uint32_t  FMS;                          /**< 0074: Fault Mode Status                                            */
   __IO uint32_t  FILTER;                       /**< 0078: Input Capture Filter Control                                 */
   __IO uint32_t  FLTCTRL;                      /**< 007C: Fault Control                                                */
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define FTM_SC_PS_MASK                           (0x7U)                                              /*!< FTM0_SC: PS Mask                        */
#define FTM_SC_PS_SHIFT                          (0U)                                                /*!< FTM0_SC: PS Position                    */
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CLKS_MASK                         (0x18U)                                             /*!< FTM0_SC: CLKS Mask                      */
#define FTM_SC_CLKS_SHIFT                        (3U)                                                /*!< FTM0_SC: CLKS Position                  */
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CPWMS_MASK                        (0x20U)                                             /*!< FTM0_SC: CPWMS Mask                     */
#define FTM_SC_CPWMS_SHIFT                       (5U)                                                /*!< FTM0_SC: CPWMS Position                 */
#define FTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_SC_CPWMS_SHIFT))&FTM_SC_CPWMS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_TOIE_MASK                         (0x40U)                                             /*!< FTM0_SC: TOIE Mask                      */
#define FTM_SC_TOIE_SHIFT                        (6U)                                                /*!< FTM0_SC: TOIE Position                  */
#define FTM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOIE_SHIFT))&FTM_SC_TOIE_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_TOF_MASK                          (0x80U)                                             /*!< FTM0_SC: TOF Mask                       */
#define FTM_SC_TOF_SHIFT                         (7U)                                                /*!< FTM0_SC: TOF Position                   */
#define FTM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOF_SHIFT))&FTM_SC_TOF_MASK) /*!< FTM0_SC                                 */
/* ------- CNT Bit Fields                           ------ */
#define FTM_CNT_COUNT_MASK                       (0xFFFFU)                                           /*!< FTM0_CNT: COUNT Mask                    */
#define FTM_CNT_COUNT_SHIFT                      (0U)                                                /*!< FTM0_CNT: COUNT Position                */
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK) /*!< FTM0_CNT                                */
/* ------- MOD Bit Fields                           ------ */
#define FTM_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< FTM0_MOD: MOD Mask                      */
#define FTM_MOD_MOD_SHIFT                        (0U)                                                /*!< FTM0_MOD: MOD Position                  */
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK) /*!< FTM0_MOD                                */
/* ------- CnSC Bit Fields                          ------ */
#define FTM_CnSC_DMA_MASK                        (0x1U)                                              /*!< FTM0_CnSC: DMA Mask                     */
#define FTM_CnSC_DMA_SHIFT                       (0U)                                                /*!< FTM0_CnSC: DMA Position                 */
#define FTM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_DMA_SHIFT))&FTM_CnSC_DMA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELS_MASK                        (0xCU)                                              /*!< FTM0_CnSC: ELS Mask                     */
#define FTM_CnSC_ELS_SHIFT                       (2U)                                                /*!< FTM0_CnSC: ELS Position                 */
#define FTM_CnSC_ELS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELS_SHIFT))&FTM_CnSC_ELS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELSA_MASK                       (0x4U)                                              /*!< FTM0_CnSC: ELSA Mask                    */
#define FTM_CnSC_ELSA_SHIFT                      (2U)                                                /*!< FTM0_CnSC: ELSA Position                */
#define FTM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSA_SHIFT))&FTM_CnSC_ELSA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELSB_MASK                       (0x8U)                                              /*!< FTM0_CnSC: ELSB Mask                    */
#define FTM_CnSC_ELSB_SHIFT                      (3U)                                                /*!< FTM0_CnSC: ELSB Position                */
#define FTM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSB_SHIFT))&FTM_CnSC_ELSB_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MS_MASK                         (0x30U)                                             /*!< FTM0_CnSC: MS Mask                      */
#define FTM_CnSC_MS_SHIFT                        (4U)                                                /*!< FTM0_CnSC: MS Position                  */
#define FTM_CnSC_MS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MS_SHIFT))&FTM_CnSC_MS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MSA_MASK                        (0x10U)                                             /*!< FTM0_CnSC: MSA Mask                     */
#define FTM_CnSC_MSA_SHIFT                       (4U)                                                /*!< FTM0_CnSC: MSA Position                 */
#define FTM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSA_SHIFT))&FTM_CnSC_MSA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MSB_MASK                        (0x20U)                                             /*!< FTM0_CnSC: MSB Mask                     */
#define FTM_CnSC_MSB_SHIFT                       (5U)                                                /*!< FTM0_CnSC: MSB Position                 */
#define FTM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSB_SHIFT))&FTM_CnSC_MSB_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_CHIE_MASK                       (0x40U)                                             /*!< FTM0_CnSC: CHIE Mask                    */
#define FTM_CnSC_CHIE_SHIFT                      (6U)                                                /*!< FTM0_CnSC: CHIE Position                */
#define FTM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHIE_SHIFT))&FTM_CnSC_CHIE_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_CHF_MASK                        (0x80U)                                             /*!< FTM0_CnSC: CHF Mask                     */
#define FTM_CnSC_CHF_SHIFT                       (7U)                                                /*!< FTM0_CnSC: CHF Position                 */
#define FTM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHF_SHIFT))&FTM_CnSC_CHF_MASK) /*!< FTM0_CnSC                               */
/* ------- CnV Bit Fields                           ------ */
#define FTM_CnV_VAL_MASK                         (0xFFFFU)                                           /*!< FTM0_CnV: VAL Mask                      */
#define FTM_CnV_VAL_SHIFT                        (0U)                                                /*!< FTM0_CnV: VAL Position                  */
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK) /*!< FTM0_CnV                                */
/* ------- CNTIN Bit Fields                         ------ */
#define FTM_CNTIN_INIT_MASK                      (0xFFFFU)                                           /*!< FTM0_CNTIN: INIT Mask                   */
#define FTM_CNTIN_INIT_SHIFT                     (0U)                                                /*!< FTM0_CNTIN: INIT Position               */
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK) /*!< FTM0_CNTIN                              */
/* ------- STATUS Bit Fields                        ------ */
#define FTM_STATUS_CH0F_MASK                     (0x1U)                                              /*!< FTM0_STATUS: CH0F Mask                  */
#define FTM_STATUS_CH0F_SHIFT                    (0U)                                                /*!< FTM0_STATUS: CH0F Position              */
#define FTM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH0F_SHIFT))&FTM_STATUS_CH0F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH1F_MASK                     (0x2U)                                              /*!< FTM0_STATUS: CH1F Mask                  */
#define FTM_STATUS_CH1F_SHIFT                    (1U)                                                /*!< FTM0_STATUS: CH1F Position              */
#define FTM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH1F_SHIFT))&FTM_STATUS_CH1F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH2F_MASK                     (0x4U)                                              /*!< FTM0_STATUS: CH2F Mask                  */
#define FTM_STATUS_CH2F_SHIFT                    (2U)                                                /*!< FTM0_STATUS: CH2F Position              */
#define FTM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH2F_SHIFT))&FTM_STATUS_CH2F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH3F_MASK                     (0x8U)                                              /*!< FTM0_STATUS: CH3F Mask                  */
#define FTM_STATUS_CH3F_SHIFT                    (3U)                                                /*!< FTM0_STATUS: CH3F Position              */
#define FTM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH3F_SHIFT))&FTM_STATUS_CH3F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH4F_MASK                     (0x10U)                                             /*!< FTM0_STATUS: CH4F Mask                  */
#define FTM_STATUS_CH4F_SHIFT                    (4U)                                                /*!< FTM0_STATUS: CH4F Position              */
#define FTM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH4F_SHIFT))&FTM_STATUS_CH4F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH5F_MASK                     (0x20U)                                             /*!< FTM0_STATUS: CH5F Mask                  */
#define FTM_STATUS_CH5F_SHIFT                    (5U)                                                /*!< FTM0_STATUS: CH5F Position              */
#define FTM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH5F_SHIFT))&FTM_STATUS_CH5F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH6F_MASK                     (0x40U)                                             /*!< FTM0_STATUS: CH6F Mask                  */
#define FTM_STATUS_CH6F_SHIFT                    (6U)                                                /*!< FTM0_STATUS: CH6F Position              */
#define FTM_STATUS_CH6F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH6F_SHIFT))&FTM_STATUS_CH6F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH7F_MASK                     (0x80U)                                             /*!< FTM0_STATUS: CH7F Mask                  */
#define FTM_STATUS_CH7F_SHIFT                    (7U)                                                /*!< FTM0_STATUS: CH7F Position              */
#define FTM_STATUS_CH7F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH7F_SHIFT))&FTM_STATUS_CH7F_MASK) /*!< FTM0_STATUS                             */
/* ------- MODE Bit Fields                          ------ */
#define FTM_MODE_FTMEN_MASK                      (0x1U)                                              /*!< FTM0_MODE: FTMEN Mask                   */
#define FTM_MODE_FTMEN_SHIFT                     (0U)                                                /*!< FTM0_MODE: FTMEN Position               */
#define FTM_MODE_FTMEN(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FTMEN_SHIFT))&FTM_MODE_FTMEN_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_INIT_MASK                       (0x2U)                                              /*!< FTM0_MODE: INIT Mask                    */
#define FTM_MODE_INIT_SHIFT                      (1U)                                                /*!< FTM0_MODE: INIT Position                */
#define FTM_MODE_INIT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_MODE_INIT_SHIFT))&FTM_MODE_INIT_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_WPDIS_MASK                      (0x4U)                                              /*!< FTM0_MODE: WPDIS Mask                   */
#define FTM_MODE_WPDIS_SHIFT                     (2U)                                                /*!< FTM0_MODE: WPDIS Position               */
#define FTM_MODE_WPDIS(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_WPDIS_SHIFT))&FTM_MODE_WPDIS_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_PWMSYNC_MASK                    (0x8U)                                              /*!< FTM0_MODE: PWMSYNC Mask                 */
#define FTM_MODE_PWMSYNC_SHIFT                   (3U)                                                /*!< FTM0_MODE: PWMSYNC Position             */
#define FTM_MODE_PWMSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_PWMSYNC_SHIFT))&FTM_MODE_PWMSYNC_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_CAPTEST_MASK                    (0x10U)                                             /*!< FTM0_MODE: CAPTEST Mask                 */
#define FTM_MODE_CAPTEST_SHIFT                   (4U)                                                /*!< FTM0_MODE: CAPTEST Position             */
#define FTM_MODE_CAPTEST(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_CAPTEST_SHIFT))&FTM_MODE_CAPTEST_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_FAULTM_MASK                     (0x60U)                                             /*!< FTM0_MODE: FAULTM Mask                  */
#define FTM_MODE_FAULTM_SHIFT                    (5U)                                                /*!< FTM0_MODE: FAULTM Position              */
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_FAULTIE_MASK                    (0x80U)                                             /*!< FTM0_MODE: FAULTIE Mask                 */
#define FTM_MODE_FAULTIE_SHIFT                   (7U)                                                /*!< FTM0_MODE: FAULTIE Position             */
#define FTM_MODE_FAULTIE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTIE_SHIFT))&FTM_MODE_FAULTIE_MASK) /*!< FTM0_MODE                               */
/* ------- SYNC Bit Fields                          ------ */
#define FTM_SYNC_CNTMIN_MASK                     (0x1U)                                              /*!< FTM0_SYNC: CNTMIN Mask                  */
#define FTM_SYNC_CNTMIN_SHIFT                    (0U)                                                /*!< FTM0_SYNC: CNTMIN Position              */
#define FTM_SYNC_CNTMIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMIN_SHIFT))&FTM_SYNC_CNTMIN_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_CNTMAX_MASK                     (0x2U)                                              /*!< FTM0_SYNC: CNTMAX Mask                  */
#define FTM_SYNC_CNTMAX_SHIFT                    (1U)                                                /*!< FTM0_SYNC: CNTMAX Position              */
#define FTM_SYNC_CNTMAX(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMAX_SHIFT))&FTM_SYNC_CNTMAX_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_REINIT_MASK                     (0x4U)                                              /*!< FTM0_SYNC: REINIT Mask                  */
#define FTM_SYNC_REINIT_SHIFT                    (2U)                                                /*!< FTM0_SYNC: REINIT Position              */
#define FTM_SYNC_REINIT(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_REINIT_SHIFT))&FTM_SYNC_REINIT_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_SYNCHOM_MASK                    (0x8U)                                              /*!< FTM0_SYNC: SYNCHOM Mask                 */
#define FTM_SYNC_SYNCHOM_SHIFT                   (3U)                                                /*!< FTM0_SYNC: SYNCHOM Position             */
#define FTM_SYNC_SYNCHOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SYNCHOM_SHIFT))&FTM_SYNC_SYNCHOM_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG0_MASK                      (0x10U)                                             /*!< FTM0_SYNC: TRIG0 Mask                   */
#define FTM_SYNC_TRIG0_SHIFT                     (4U)                                                /*!< FTM0_SYNC: TRIG0 Position               */
#define FTM_SYNC_TRIG0(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG0_SHIFT))&FTM_SYNC_TRIG0_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG1_MASK                      (0x20U)                                             /*!< FTM0_SYNC: TRIG1 Mask                   */
#define FTM_SYNC_TRIG1_SHIFT                     (5U)                                                /*!< FTM0_SYNC: TRIG1 Position               */
#define FTM_SYNC_TRIG1(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG1_SHIFT))&FTM_SYNC_TRIG1_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG2_MASK                      (0x40U)                                             /*!< FTM0_SYNC: TRIG2 Mask                   */
#define FTM_SYNC_TRIG2_SHIFT                     (6U)                                                /*!< FTM0_SYNC: TRIG2 Position               */
#define FTM_SYNC_TRIG2(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG2_SHIFT))&FTM_SYNC_TRIG2_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_SWSYNC_MASK                     (0x80U)                                             /*!< FTM0_SYNC: SWSYNC Mask                  */
#define FTM_SYNC_SWSYNC_SHIFT                    (7U)                                                /*!< FTM0_SYNC: SWSYNC Position              */
#define FTM_SYNC_SWSYNC(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SWSYNC_SHIFT))&FTM_SYNC_SWSYNC_MASK) /*!< FTM0_SYNC                               */
/* ------- OUTINIT Bit Fields                       ------ */
#define FTM_OUTINIT_CH0OI_MASK                   (0x1U)                                              /*!< FTM0_OUTINIT: CH0OI Mask                */
#define FTM_OUTINIT_CH0OI_SHIFT                  (0U)                                                /*!< FTM0_OUTINIT: CH0OI Position            */
#define FTM_OUTINIT_CH0OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH0OI_SHIFT))&FTM_OUTINIT_CH0OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH1OI_MASK                   (0x2U)                                              /*!< FTM0_OUTINIT: CH1OI Mask                */
#define FTM_OUTINIT_CH1OI_SHIFT                  (1U)                                                /*!< FTM0_OUTINIT: CH1OI Position            */
#define FTM_OUTINIT_CH1OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH1OI_SHIFT))&FTM_OUTINIT_CH1OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH2OI_MASK                   (0x4U)                                              /*!< FTM0_OUTINIT: CH2OI Mask                */
#define FTM_OUTINIT_CH2OI_SHIFT                  (2U)                                                /*!< FTM0_OUTINIT: CH2OI Position            */
#define FTM_OUTINIT_CH2OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH2OI_SHIFT))&FTM_OUTINIT_CH2OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH3OI_MASK                   (0x8U)                                              /*!< FTM0_OUTINIT: CH3OI Mask                */
#define FTM_OUTINIT_CH3OI_SHIFT                  (3U)                                                /*!< FTM0_OUTINIT: CH3OI Position            */
#define FTM_OUTINIT_CH3OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH3OI_SHIFT))&FTM_OUTINIT_CH3OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH4OI_MASK                   (0x10U)                                             /*!< FTM0_OUTINIT: CH4OI Mask                */
#define FTM_OUTINIT_CH4OI_SHIFT                  (4U)                                                /*!< FTM0_OUTINIT: CH4OI Position            */
#define FTM_OUTINIT_CH4OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH4OI_SHIFT))&FTM_OUTINIT_CH4OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH5OI_MASK                   (0x20U)                                             /*!< FTM0_OUTINIT: CH5OI Mask                */
#define FTM_OUTINIT_CH5OI_SHIFT                  (5U)                                                /*!< FTM0_OUTINIT: CH5OI Position            */
#define FTM_OUTINIT_CH5OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH5OI_SHIFT))&FTM_OUTINIT_CH5OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH6OI_MASK                   (0x40U)                                             /*!< FTM0_OUTINIT: CH6OI Mask                */
#define FTM_OUTINIT_CH6OI_SHIFT                  (6U)                                                /*!< FTM0_OUTINIT: CH6OI Position            */
#define FTM_OUTINIT_CH6OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH6OI_SHIFT))&FTM_OUTINIT_CH6OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH7OI_MASK                   (0x80U)                                             /*!< FTM0_OUTINIT: CH7OI Mask                */
#define FTM_OUTINIT_CH7OI_SHIFT                  (7U)                                                /*!< FTM0_OUTINIT: CH7OI Position            */
#define FTM_OUTINIT_CH7OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH7OI_SHIFT))&FTM_OUTINIT_CH7OI_MASK) /*!< FTM0_OUTINIT                            */
/* ------- OUTMASK Bit Fields                       ------ */
#define FTM_OUTMASK_CH0OM_MASK                   (0x1U)                                              /*!< FTM0_OUTMASK: CH0OM Mask                */
#define FTM_OUTMASK_CH0OM_SHIFT                  (0U)                                                /*!< FTM0_OUTMASK: CH0OM Position            */
#define FTM_OUTMASK_CH0OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH0OM_SHIFT))&FTM_OUTMASK_CH0OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH1OM_MASK                   (0x2U)                                              /*!< FTM0_OUTMASK: CH1OM Mask                */
#define FTM_OUTMASK_CH1OM_SHIFT                  (1U)                                                /*!< FTM0_OUTMASK: CH1OM Position            */
#define FTM_OUTMASK_CH1OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH1OM_SHIFT))&FTM_OUTMASK_CH1OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH2OM_MASK                   (0x4U)                                              /*!< FTM0_OUTMASK: CH2OM Mask                */
#define FTM_OUTMASK_CH2OM_SHIFT                  (2U)                                                /*!< FTM0_OUTMASK: CH2OM Position            */
#define FTM_OUTMASK_CH2OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH2OM_SHIFT))&FTM_OUTMASK_CH2OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH3OM_MASK                   (0x8U)                                              /*!< FTM0_OUTMASK: CH3OM Mask                */
#define FTM_OUTMASK_CH3OM_SHIFT                  (3U)                                                /*!< FTM0_OUTMASK: CH3OM Position            */
#define FTM_OUTMASK_CH3OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH3OM_SHIFT))&FTM_OUTMASK_CH3OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH4OM_MASK                   (0x10U)                                             /*!< FTM0_OUTMASK: CH4OM Mask                */
#define FTM_OUTMASK_CH4OM_SHIFT                  (4U)                                                /*!< FTM0_OUTMASK: CH4OM Position            */
#define FTM_OUTMASK_CH4OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH4OM_SHIFT))&FTM_OUTMASK_CH4OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH5OM_MASK                   (0x20U)                                             /*!< FTM0_OUTMASK: CH5OM Mask                */
#define FTM_OUTMASK_CH5OM_SHIFT                  (5U)                                                /*!< FTM0_OUTMASK: CH5OM Position            */
#define FTM_OUTMASK_CH5OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH5OM_SHIFT))&FTM_OUTMASK_CH5OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH6OM_MASK                   (0x40U)                                             /*!< FTM0_OUTMASK: CH6OM Mask                */
#define FTM_OUTMASK_CH6OM_SHIFT                  (6U)                                                /*!< FTM0_OUTMASK: CH6OM Position            */
#define FTM_OUTMASK_CH6OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH6OM_SHIFT))&FTM_OUTMASK_CH6OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH7OM_MASK                   (0x80U)                                             /*!< FTM0_OUTMASK: CH7OM Mask                */
#define FTM_OUTMASK_CH7OM_SHIFT                  (7U)                                                /*!< FTM0_OUTMASK: CH7OM Position            */
#define FTM_OUTMASK_CH7OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH7OM_SHIFT))&FTM_OUTMASK_CH7OM_MASK) /*!< FTM0_OUTMASK                            */
/* ------- COMBINE Bit Fields                       ------ */
#define FTM_COMBINE_COMBINE0_MASK                (0x1U)                                              /*!< FTM0_COMBINE: COMBINE0 Mask             */
#define FTM_COMBINE_COMBINE0_SHIFT               (0U)                                                /*!< FTM0_COMBINE: COMBINE0 Position         */
#define FTM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE0_SHIFT))&FTM_COMBINE_COMBINE0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP0_MASK                   (0x2U)                                              /*!< FTM0_COMBINE: COMP0 Mask                */
#define FTM_COMBINE_COMP0_SHIFT                  (1U)                                                /*!< FTM0_COMBINE: COMP0 Position            */
#define FTM_COMBINE_COMP0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP0_SHIFT))&FTM_COMBINE_COMP0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN0_MASK                (0x4U)                                              /*!< FTM0_COMBINE: DECAPEN0 Mask             */
#define FTM_COMBINE_DECAPEN0_SHIFT               (2U)                                                /*!< FTM0_COMBINE: DECAPEN0 Position         */
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN0_SHIFT))&FTM_COMBINE_DECAPEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP0_MASK                  (0x8U)                                              /*!< FTM0_COMBINE: DECAP0 Mask               */
#define FTM_COMBINE_DECAP0_SHIFT                 (3U)                                                /*!< FTM0_COMBINE: DECAP0 Position           */
#define FTM_COMBINE_DECAP0(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP0_SHIFT))&FTM_COMBINE_DECAP0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN0_MASK                   (0x10U)                                             /*!< FTM0_COMBINE: DTEN0 Mask                */
#define FTM_COMBINE_DTEN0_SHIFT                  (4U)                                                /*!< FTM0_COMBINE: DTEN0 Position            */
#define FTM_COMBINE_DTEN0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN0_SHIFT))&FTM_COMBINE_DTEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN0_MASK                 (0x20U)                                             /*!< FTM0_COMBINE: SYNCEN0 Mask              */
#define FTM_COMBINE_SYNCEN0_SHIFT                (5U)                                                /*!< FTM0_COMBINE: SYNCEN0 Position          */
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN0_SHIFT))&FTM_COMBINE_SYNCEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN0_MASK                (0x40U)                                             /*!< FTM0_COMBINE: FAULTEN0 Mask             */
#define FTM_COMBINE_FAULTEN0_SHIFT               (6U)                                                /*!< FTM0_COMBINE: FAULTEN0 Position         */
#define FTM_COMBINE_FAULTEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN0_SHIFT))&FTM_COMBINE_FAULTEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE1_MASK                (0x100U)                                            /*!< FTM0_COMBINE: COMBINE1 Mask             */
#define FTM_COMBINE_COMBINE1_SHIFT               (8U)                                                /*!< FTM0_COMBINE: COMBINE1 Position         */
#define FTM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE1_SHIFT))&FTM_COMBINE_COMBINE1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP1_MASK                   (0x200U)                                            /*!< FTM0_COMBINE: COMP1 Mask                */
#define FTM_COMBINE_COMP1_SHIFT                  (9U)                                                /*!< FTM0_COMBINE: COMP1 Position            */
#define FTM_COMBINE_COMP1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP1_SHIFT))&FTM_COMBINE_COMP1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN1_MASK                (0x400U)                                            /*!< FTM0_COMBINE: DECAPEN1 Mask             */
#define FTM_COMBINE_DECAPEN1_SHIFT               (10U)                                               /*!< FTM0_COMBINE: DECAPEN1 Position         */
#define FTM_COMBINE_DECAPEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN1_SHIFT))&FTM_COMBINE_DECAPEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP1_MASK                  (0x800U)                                            /*!< FTM0_COMBINE: DECAP1 Mask               */
#define FTM_COMBINE_DECAP1_SHIFT                 (11U)                                               /*!< FTM0_COMBINE: DECAP1 Position           */
#define FTM_COMBINE_DECAP1(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP1_SHIFT))&FTM_COMBINE_DECAP1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN1_MASK                   (0x1000U)                                           /*!< FTM0_COMBINE: DTEN1 Mask                */
#define FTM_COMBINE_DTEN1_SHIFT                  (12U)                                               /*!< FTM0_COMBINE: DTEN1 Position            */
#define FTM_COMBINE_DTEN1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN1_SHIFT))&FTM_COMBINE_DTEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN1_MASK                 (0x2000U)                                           /*!< FTM0_COMBINE: SYNCEN1 Mask              */
#define FTM_COMBINE_SYNCEN1_SHIFT                (13U)                                               /*!< FTM0_COMBINE: SYNCEN1 Position          */
#define FTM_COMBINE_SYNCEN1(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN1_SHIFT))&FTM_COMBINE_SYNCEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN1_MASK                (0x4000U)                                           /*!< FTM0_COMBINE: FAULTEN1 Mask             */
#define FTM_COMBINE_FAULTEN1_SHIFT               (14U)                                               /*!< FTM0_COMBINE: FAULTEN1 Position         */
#define FTM_COMBINE_FAULTEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN1_SHIFT))&FTM_COMBINE_FAULTEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE2_MASK                (0x10000U)                                          /*!< FTM0_COMBINE: COMBINE2 Mask             */
#define FTM_COMBINE_COMBINE2_SHIFT               (16U)                                               /*!< FTM0_COMBINE: COMBINE2 Position         */
#define FTM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE2_SHIFT))&FTM_COMBINE_COMBINE2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP2_MASK                   (0x20000U)                                          /*!< FTM0_COMBINE: COMP2 Mask                */
#define FTM_COMBINE_COMP2_SHIFT                  (17U)                                               /*!< FTM0_COMBINE: COMP2 Position            */
#define FTM_COMBINE_COMP2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP2_SHIFT))&FTM_COMBINE_COMP2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN2_MASK                (0x40000U)                                          /*!< FTM0_COMBINE: DECAPEN2 Mask             */
#define FTM_COMBINE_DECAPEN2_SHIFT               (18U)                                               /*!< FTM0_COMBINE: DECAPEN2 Position         */
#define FTM_COMBINE_DECAPEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN2_SHIFT))&FTM_COMBINE_DECAPEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP2_MASK                  (0x80000U)                                          /*!< FTM0_COMBINE: DECAP2 Mask               */
#define FTM_COMBINE_DECAP2_SHIFT                 (19U)                                               /*!< FTM0_COMBINE: DECAP2 Position           */
#define FTM_COMBINE_DECAP2(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP2_SHIFT))&FTM_COMBINE_DECAP2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN2_MASK                   (0x100000U)                                         /*!< FTM0_COMBINE: DTEN2 Mask                */
#define FTM_COMBINE_DTEN2_SHIFT                  (20U)                                               /*!< FTM0_COMBINE: DTEN2 Position            */
#define FTM_COMBINE_DTEN2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN2_SHIFT))&FTM_COMBINE_DTEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN2_MASK                 (0x200000U)                                         /*!< FTM0_COMBINE: SYNCEN2 Mask              */
#define FTM_COMBINE_SYNCEN2_SHIFT                (21U)                                               /*!< FTM0_COMBINE: SYNCEN2 Position          */
#define FTM_COMBINE_SYNCEN2(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN2_SHIFT))&FTM_COMBINE_SYNCEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN2_MASK                (0x400000U)                                         /*!< FTM0_COMBINE: FAULTEN2 Mask             */
#define FTM_COMBINE_FAULTEN2_SHIFT               (22U)                                               /*!< FTM0_COMBINE: FAULTEN2 Position         */
#define FTM_COMBINE_FAULTEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN2_SHIFT))&FTM_COMBINE_FAULTEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE3_MASK                (0x1000000U)                                        /*!< FTM0_COMBINE: COMBINE3 Mask             */
#define FTM_COMBINE_COMBINE3_SHIFT               (24U)                                               /*!< FTM0_COMBINE: COMBINE3 Position         */
#define FTM_COMBINE_COMBINE3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE3_SHIFT))&FTM_COMBINE_COMBINE3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP3_MASK                   (0x2000000U)                                        /*!< FTM0_COMBINE: COMP3 Mask                */
#define FTM_COMBINE_COMP3_SHIFT                  (25U)                                               /*!< FTM0_COMBINE: COMP3 Position            */
#define FTM_COMBINE_COMP3(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP3_SHIFT))&FTM_COMBINE_COMP3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN3_MASK                (0x4000000U)                                        /*!< FTM0_COMBINE: DECAPEN3 Mask             */
#define FTM_COMBINE_DECAPEN3_SHIFT               (26U)                                               /*!< FTM0_COMBINE: DECAPEN3 Position         */
#define FTM_COMBINE_DECAPEN3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN3_SHIFT))&FTM_COMBINE_DECAPEN3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP3_MASK                  (0x8000000U)                                        /*!< FTM0_COMBINE: DECAP3 Mask               */
#define FTM_COMBINE_DECAP3_SHIFT                 (27U)                                               /*!< FTM0_COMBINE: DECAP3 Position           */
#define FTM_COMBINE_DECAP3(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP3_SHIFT))&FTM_COMBINE_DECAP3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN3_MASK                   (0x10000000U)                                       /*!< FTM0_COMBINE: DTEN3 Mask                */
#define FTM_COMBINE_DTEN3_SHIFT                  (28U)                                               /*!< FTM0_COMBINE: DTEN3 Position            */
#define FTM_COMBINE_DTEN3(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN3_SHIFT))&FTM_COMBINE_DTEN3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN3_MASK                 (0x20000000U)                                       /*!< FTM0_COMBINE: SYNCEN3 Mask              */
#define FTM_COMBINE_SYNCEN3_SHIFT                (29U)                                               /*!< FTM0_COMBINE: SYNCEN3 Position          */
#define FTM_COMBINE_SYNCEN3(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN3_SHIFT))&FTM_COMBINE_SYNCEN3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN3_MASK                (0x40000000U)                                       /*!< FTM0_COMBINE: FAULTEN3 Mask             */
#define FTM_COMBINE_FAULTEN3_SHIFT               (30U)                                               /*!< FTM0_COMBINE: FAULTEN3 Position         */
#define FTM_COMBINE_FAULTEN3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN3_SHIFT))&FTM_COMBINE_FAULTEN3_MASK) /*!< FTM0_COMBINE                            */
/* ------- DEADTIME Bit Fields                      ------ */
#define FTM_DEADTIME_DTVAL_MASK                  (0x3FU)                                             /*!< FTM0_DEADTIME: DTVAL Mask               */
#define FTM_DEADTIME_DTVAL_SHIFT                 (0U)                                                /*!< FTM0_DEADTIME: DTVAL Position           */
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK) /*!< FTM0_DEADTIME                           */
#define FTM_DEADTIME_DTPS_MASK                   (0xC0U)                                             /*!< FTM0_DEADTIME: DTPS Mask                */
#define FTM_DEADTIME_DTPS_SHIFT                  (6U)                                                /*!< FTM0_DEADTIME: DTPS Position            */
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK) /*!< FTM0_DEADTIME                           */
/* ------- EXTTRIG Bit Fields                       ------ */
#define FTM_EXTTRIG_CH2TRIG_MASK                 (0x1U)                                              /*!< FTM0_EXTTRIG: CH2TRIG Mask              */
#define FTM_EXTTRIG_CH2TRIG_SHIFT                (0U)                                                /*!< FTM0_EXTTRIG: CH2TRIG Position          */
#define FTM_EXTTRIG_CH2TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH2TRIG_SHIFT))&FTM_EXTTRIG_CH2TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH3TRIG_MASK                 (0x2U)                                              /*!< FTM0_EXTTRIG: CH3TRIG Mask              */
#define FTM_EXTTRIG_CH3TRIG_SHIFT                (1U)                                                /*!< FTM0_EXTTRIG: CH3TRIG Position          */
#define FTM_EXTTRIG_CH3TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH3TRIG_SHIFT))&FTM_EXTTRIG_CH3TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH4TRIG_MASK                 (0x4U)                                              /*!< FTM0_EXTTRIG: CH4TRIG Mask              */
#define FTM_EXTTRIG_CH4TRIG_SHIFT                (2U)                                                /*!< FTM0_EXTTRIG: CH4TRIG Position          */
#define FTM_EXTTRIG_CH4TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH4TRIG_SHIFT))&FTM_EXTTRIG_CH4TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH5TRIG_MASK                 (0x8U)                                              /*!< FTM0_EXTTRIG: CH5TRIG Mask              */
#define FTM_EXTTRIG_CH5TRIG_SHIFT                (3U)                                                /*!< FTM0_EXTTRIG: CH5TRIG Position          */
#define FTM_EXTTRIG_CH5TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH5TRIG_SHIFT))&FTM_EXTTRIG_CH5TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH0TRIG_MASK                 (0x10U)                                             /*!< FTM0_EXTTRIG: CH0TRIG Mask              */
#define FTM_EXTTRIG_CH0TRIG_SHIFT                (4U)                                                /*!< FTM0_EXTTRIG: CH0TRIG Position          */
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH0TRIG_SHIFT))&FTM_EXTTRIG_CH0TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH1TRIG_MASK                 (0x20U)                                             /*!< FTM0_EXTTRIG: CH1TRIG Mask              */
#define FTM_EXTTRIG_CH1TRIG_SHIFT                (5U)                                                /*!< FTM0_EXTTRIG: CH1TRIG Position          */
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH1TRIG_SHIFT))&FTM_EXTTRIG_CH1TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_INITTRIGEN_MASK              (0x40U)                                             /*!< FTM0_EXTTRIG: INITTRIGEN Mask           */
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             (6U)                                                /*!< FTM0_EXTTRIG: INITTRIGEN Position       */
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_INITTRIGEN_SHIFT))&FTM_EXTTRIG_INITTRIGEN_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_TRIGF_MASK                   (0x80U)                                             /*!< FTM0_EXTTRIG: TRIGF Mask                */
#define FTM_EXTTRIG_TRIGF_SHIFT                  (7U)                                                /*!< FTM0_EXTTRIG: TRIGF Position            */
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_TRIGF_SHIFT))&FTM_EXTTRIG_TRIGF_MASK) /*!< FTM0_EXTTRIG                            */
/* ------- POL Bit Fields                           ------ */
#define FTM_POL_POL0_MASK                        (0x1U)                                              /*!< FTM0_POL: POL0 Mask                     */
#define FTM_POL_POL0_SHIFT                       (0U)                                                /*!< FTM0_POL: POL0 Position                 */
#define FTM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL0_SHIFT))&FTM_POL_POL0_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL1_MASK                        (0x2U)                                              /*!< FTM0_POL: POL1 Mask                     */
#define FTM_POL_POL1_SHIFT                       (1U)                                                /*!< FTM0_POL: POL1 Position                 */
#define FTM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL1_SHIFT))&FTM_POL_POL1_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL2_MASK                        (0x4U)                                              /*!< FTM0_POL: POL2 Mask                     */
#define FTM_POL_POL2_SHIFT                       (2U)                                                /*!< FTM0_POL: POL2 Position                 */
#define FTM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL2_SHIFT))&FTM_POL_POL2_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL3_MASK                        (0x8U)                                              /*!< FTM0_POL: POL3 Mask                     */
#define FTM_POL_POL3_SHIFT                       (3U)                                                /*!< FTM0_POL: POL3 Position                 */
#define FTM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL3_SHIFT))&FTM_POL_POL3_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL4_MASK                        (0x10U)                                             /*!< FTM0_POL: POL4 Mask                     */
#define FTM_POL_POL4_SHIFT                       (4U)                                                /*!< FTM0_POL: POL4 Position                 */
#define FTM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL4_SHIFT))&FTM_POL_POL4_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL5_MASK                        (0x20U)                                             /*!< FTM0_POL: POL5 Mask                     */
#define FTM_POL_POL5_SHIFT                       (5U)                                                /*!< FTM0_POL: POL5 Position                 */
#define FTM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL5_SHIFT))&FTM_POL_POL5_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL6_MASK                        (0x40U)                                             /*!< FTM0_POL: POL6 Mask                     */
#define FTM_POL_POL6_SHIFT                       (6U)                                                /*!< FTM0_POL: POL6 Position                 */
#define FTM_POL_POL6(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL6_SHIFT))&FTM_POL_POL6_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL7_MASK                        (0x80U)                                             /*!< FTM0_POL: POL7 Mask                     */
#define FTM_POL_POL7_SHIFT                       (7U)                                                /*!< FTM0_POL: POL7 Position                 */
#define FTM_POL_POL7(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL7_SHIFT))&FTM_POL_POL7_MASK) /*!< FTM0_POL                                */
/* ------- FMS Bit Fields                           ------ */
#define FTM_FMS_FAULTF0_MASK                     (0x1U)                                              /*!< FTM0_FMS: FAULTF0 Mask                  */
#define FTM_FMS_FAULTF0_SHIFT                    (0U)                                                /*!< FTM0_FMS: FAULTF0 Position              */
#define FTM_FMS_FAULTF0(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF0_SHIFT))&FTM_FMS_FAULTF0_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF1_MASK                     (0x2U)                                              /*!< FTM0_FMS: FAULTF1 Mask                  */
#define FTM_FMS_FAULTF1_SHIFT                    (1U)                                                /*!< FTM0_FMS: FAULTF1 Position              */
#define FTM_FMS_FAULTF1(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF1_SHIFT))&FTM_FMS_FAULTF1_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF2_MASK                     (0x4U)                                              /*!< FTM0_FMS: FAULTF2 Mask                  */
#define FTM_FMS_FAULTF2_SHIFT                    (2U)                                                /*!< FTM0_FMS: FAULTF2 Position              */
#define FTM_FMS_FAULTF2(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF2_SHIFT))&FTM_FMS_FAULTF2_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF3_MASK                     (0x8U)                                              /*!< FTM0_FMS: FAULTF3 Mask                  */
#define FTM_FMS_FAULTF3_SHIFT                    (3U)                                                /*!< FTM0_FMS: FAULTF3 Position              */
#define FTM_FMS_FAULTF3(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF3_SHIFT))&FTM_FMS_FAULTF3_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTIN_MASK                     (0x20U)                                             /*!< FTM0_FMS: FAULTIN Mask                  */
#define FTM_FMS_FAULTIN_SHIFT                    (5U)                                                /*!< FTM0_FMS: FAULTIN Position              */
#define FTM_FMS_FAULTIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTIN_SHIFT))&FTM_FMS_FAULTIN_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_WPEN_MASK                        (0x40U)                                             /*!< FTM0_FMS: WPEN Mask                     */
#define FTM_FMS_WPEN_SHIFT                       (6U)                                                /*!< FTM0_FMS: WPEN Position                 */
#define FTM_FMS_WPEN(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_FMS_WPEN_SHIFT))&FTM_FMS_WPEN_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF_MASK                      (0x80U)                                             /*!< FTM0_FMS: FAULTF Mask                   */
#define FTM_FMS_FAULTF_SHIFT                     (7U)                                                /*!< FTM0_FMS: FAULTF Position               */
#define FTM_FMS_FAULTF(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF_SHIFT))&FTM_FMS_FAULTF_MASK) /*!< FTM0_FMS                                */
/* ------- FILTER Bit Fields                        ------ */
#define FTM_FILTER_CH0FVAL_MASK                  (0xFU)                                              /*!< FTM0_FILTER: CH0FVAL Mask               */
#define FTM_FILTER_CH0FVAL_SHIFT                 (0U)                                                /*!< FTM0_FILTER: CH0FVAL Position           */
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH1FVAL_MASK                  (0xF0U)                                             /*!< FTM0_FILTER: CH1FVAL Mask               */
#define FTM_FILTER_CH1FVAL_SHIFT                 (4U)                                                /*!< FTM0_FILTER: CH1FVAL Position           */
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH2FVAL_MASK                  (0xF00U)                                            /*!< FTM0_FILTER: CH2FVAL Mask               */
#define FTM_FILTER_CH2FVAL_SHIFT                 (8U)                                                /*!< FTM0_FILTER: CH2FVAL Position           */
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH3FVAL_MASK                  (0xF000U)                                           /*!< FTM0_FILTER: CH3FVAL Mask               */
#define FTM_FILTER_CH3FVAL_SHIFT                 (12U)                                               /*!< FTM0_FILTER: CH3FVAL Position           */
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK) /*!< FTM0_FILTER                             */
/* ------- FLTCTRL Bit Fields                       ------ */
#define FTM_FLTCTRL_FAULT0EN_MASK                (0x1U)                                              /*!< FTM0_FLTCTRL: FAULT0EN Mask             */
#define FTM_FLTCTRL_FAULT0EN_SHIFT               (0U)                                                /*!< FTM0_FLTCTRL: FAULT0EN Position         */
#define FTM_FLTCTRL_FAULT0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT0EN_SHIFT))&FTM_FLTCTRL_FAULT0EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT1EN_MASK                (0x2U)                                              /*!< FTM0_FLTCTRL: FAULT1EN Mask             */
#define FTM_FLTCTRL_FAULT1EN_SHIFT               (1U)                                                /*!< FTM0_FLTCTRL: FAULT1EN Position         */
#define FTM_FLTCTRL_FAULT1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT1EN_SHIFT))&FTM_FLTCTRL_FAULT1EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT2EN_MASK                (0x4U)                                              /*!< FTM0_FLTCTRL: FAULT2EN Mask             */
#define FTM_FLTCTRL_FAULT2EN_SHIFT               (2U)                                                /*!< FTM0_FLTCTRL: FAULT2EN Position         */
#define FTM_FLTCTRL_FAULT2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT2EN_SHIFT))&FTM_FLTCTRL_FAULT2EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT3EN_MASK                (0x8U)                                              /*!< FTM0_FLTCTRL: FAULT3EN Mask             */
#define FTM_FLTCTRL_FAULT3EN_SHIFT               (3U)                                                /*!< FTM0_FLTCTRL: FAULT3EN Position         */
#define FTM_FLTCTRL_FAULT3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT3EN_SHIFT))&FTM_FLTCTRL_FAULT3EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR0EN_MASK                (0x10U)                                             /*!< FTM0_FLTCTRL: FFLTR0EN Mask             */
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               (4U)                                                /*!< FTM0_FLTCTRL: FFLTR0EN Position         */
#define FTM_FLTCTRL_FFLTR0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR0EN_SHIFT))&FTM_FLTCTRL_FFLTR0EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR1EN_MASK                (0x20U)                                             /*!< FTM0_FLTCTRL: FFLTR1EN Mask             */
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               (5U)                                                /*!< FTM0_FLTCTRL: FFLTR1EN Position         */
#define FTM_FLTCTRL_FFLTR1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR1EN_SHIFT))&FTM_FLTCTRL_FFLTR1EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR2EN_MASK                (0x40U)                                             /*!< FTM0_FLTCTRL: FFLTR2EN Mask             */
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               (6U)                                                /*!< FTM0_FLTCTRL: FFLTR2EN Position         */
#define FTM_FLTCTRL_FFLTR2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR2EN_SHIFT))&FTM_FLTCTRL_FFLTR2EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR3EN_MASK                (0x80U)                                             /*!< FTM0_FLTCTRL: FFLTR3EN Mask             */
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               (7U)                                                /*!< FTM0_FLTCTRL: FFLTR3EN Position         */
#define FTM_FLTCTRL_FFLTR3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR3EN_SHIFT))&FTM_FLTCTRL_FFLTR3EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFVAL_MASK                   (0xF00U)                                            /*!< FTM0_FLTCTRL: FFVAL Mask                */
#define FTM_FLTCTRL_FFVAL_SHIFT                  (8U)                                                /*!< FTM0_FLTCTRL: FFVAL Position            */
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK) /*!< FTM0_FLTCTRL                            */
/* ------- QDCTRL Bit Fields                        ------ */
#define FTM_QDCTRL_QUADEN_MASK                   (0x1U)                                              /*!< FTM0_QDCTRL: QUADEN Mask                */
#define FTM_QDCTRL_QUADEN_SHIFT                  (0U)                                                /*!< FTM0_QDCTRL: QUADEN Position            */
#define FTM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADEN_SHIFT))&FTM_QDCTRL_QUADEN_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_TOFDIR_MASK                   (0x2U)                                              /*!< FTM0_QDCTRL: TOFDIR Mask                */
#define FTM_QDCTRL_TOFDIR_SHIFT                  (1U)                                                /*!< FTM0_QDCTRL: TOFDIR Position            */
#define FTM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_TOFDIR_SHIFT))&FTM_QDCTRL_TOFDIR_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_QUADIR_MASK                   (0x4U)                                              /*!< FTM0_QDCTRL: QUADIR Mask                */
#define FTM_QDCTRL_QUADIR_SHIFT                  (2U)                                                /*!< FTM0_QDCTRL: QUADIR Position            */
#define FTM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADIR_SHIFT))&FTM_QDCTRL_QUADIR_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_QUADMODE_MASK                 (0x8U)                                              /*!< FTM0_QDCTRL: QUADMODE Mask              */
#define FTM_QDCTRL_QUADMODE_SHIFT                (3U)                                                /*!< FTM0_QDCTRL: QUADMODE Position          */
#define FTM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADMODE_SHIFT))&FTM_QDCTRL_QUADMODE_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHBPOL_MASK                   (0x10U)                                             /*!< FTM0_QDCTRL: PHBPOL Mask                */
#define FTM_QDCTRL_PHBPOL_SHIFT                  (4U)                                                /*!< FTM0_QDCTRL: PHBPOL Position            */
#define FTM_QDCTRL_PHBPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBPOL_SHIFT))&FTM_QDCTRL_PHBPOL_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHAPOL_MASK                   (0x20U)                                             /*!< FTM0_QDCTRL: PHAPOL Mask                */
#define FTM_QDCTRL_PHAPOL_SHIFT                  (5U)                                                /*!< FTM0_QDCTRL: PHAPOL Position            */
#define FTM_QDCTRL_PHAPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAPOL_SHIFT))&FTM_QDCTRL_PHAPOL_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHBFLTREN_MASK                (0x40U)                                             /*!< FTM0_QDCTRL: PHBFLTREN Mask             */
#define FTM_QDCTRL_PHBFLTREN_SHIFT               (6U)                                                /*!< FTM0_QDCTRL: PHBFLTREN Position         */
#define FTM_QDCTRL_PHBFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBFLTREN_SHIFT))&FTM_QDCTRL_PHBFLTREN_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHAFLTREN_MASK                (0x80U)                                             /*!< FTM0_QDCTRL: PHAFLTREN Mask             */
#define FTM_QDCTRL_PHAFLTREN_SHIFT               (7U)                                                /*!< FTM0_QDCTRL: PHAFLTREN Position         */
#define FTM_QDCTRL_PHAFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAFLTREN_SHIFT))&FTM_QDCTRL_PHAFLTREN_MASK) /*!< FTM0_QDCTRL                             */
/* ------- CONF Bit Fields                          ------ */
#define FTM_CONF_NUMTOF_MASK                     (0x1FU)                                             /*!< FTM0_CONF: NUMTOF Mask                  */
#define FTM_CONF_NUMTOF_SHIFT                    (0U)                                                /*!< FTM0_CONF: NUMTOF Position              */
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_NUMTOF_SHIFT))&FTM_CONF_NUMTOF_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_BDMMODE_MASK                    (0xC0U)                                             /*!< FTM0_CONF: BDMMODE Mask                 */
#define FTM_CONF_BDMMODE_SHIFT                   (6U)                                                /*!< FTM0_CONF: BDMMODE Position             */
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_GTBEEN_MASK                     (0x200U)                                            /*!< FTM0_CONF: GTBEEN Mask                  */
#define FTM_CONF_GTBEEN_SHIFT                    (9U)                                                /*!< FTM0_CONF: GTBEEN Position              */
#define FTM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEEN_SHIFT))&FTM_CONF_GTBEEN_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_GTBEOUT_MASK                    (0x400U)                                            /*!< FTM0_CONF: GTBEOUT Mask                 */
#define FTM_CONF_GTBEOUT_SHIFT                   (10U)                                               /*!< FTM0_CONF: GTBEOUT Position             */
#define FTM_CONF_GTBEOUT(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEOUT_SHIFT))&FTM_CONF_GTBEOUT_MASK) /*!< FTM0_CONF                               */
/* ------- FLTPOL Bit Fields                        ------ */
#define FTM_FLTPOL_FLT0POL_MASK                  (0x1U)                                              /*!< FTM0_FLTPOL: FLT0POL Mask               */
#define FTM_FLTPOL_FLT0POL_SHIFT                 (0U)                                                /*!< FTM0_FLTPOL: FLT0POL Position           */
#define FTM_FLTPOL_FLT0POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT0POL_SHIFT))&FTM_FLTPOL_FLT0POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT1POL_MASK                  (0x2U)                                              /*!< FTM0_FLTPOL: FLT1POL Mask               */
#define FTM_FLTPOL_FLT1POL_SHIFT                 (1U)                                                /*!< FTM0_FLTPOL: FLT1POL Position           */
#define FTM_FLTPOL_FLT1POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT1POL_SHIFT))&FTM_FLTPOL_FLT1POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT2POL_MASK                  (0x4U)                                              /*!< FTM0_FLTPOL: FLT2POL Mask               */
#define FTM_FLTPOL_FLT2POL_SHIFT                 (2U)                                                /*!< FTM0_FLTPOL: FLT2POL Position           */
#define FTM_FLTPOL_FLT2POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT2POL_SHIFT))&FTM_FLTPOL_FLT2POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT3POL_MASK                  (0x8U)                                              /*!< FTM0_FLTPOL: FLT3POL Mask               */
#define FTM_FLTPOL_FLT3POL_SHIFT                 (3U)                                                /*!< FTM0_FLTPOL: FLT3POL Position           */
#define FTM_FLTPOL_FLT3POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT3POL_SHIFT))&FTM_FLTPOL_FLT3POL_MASK) /*!< FTM0_FLTPOL                             */
/* ------- SYNCONF Bit Fields                       ------ */
#define FTM_SYNCONF_HWTRIGMODE_MASK              (0x1U)                                              /*!< FTM0_SYNCONF: HWTRIGMODE Mask           */
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             (0U)                                                /*!< FTM0_SYNCONF: HWTRIGMODE Position       */
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWTRIGMODE_SHIFT))&FTM_SYNCONF_HWTRIGMODE_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_CNTINC_MASK                  (0x4U)                                              /*!< FTM0_SYNCONF: CNTINC Mask               */
#define FTM_SYNCONF_CNTINC_SHIFT                 (2U)                                                /*!< FTM0_SYNCONF: CNTINC Position           */
#define FTM_SYNCONF_CNTINC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_CNTINC_SHIFT))&FTM_SYNCONF_CNTINC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_INVC_MASK                    (0x10U)                                             /*!< FTM0_SYNCONF: INVC Mask                 */
#define FTM_SYNCONF_INVC_SHIFT                   (4U)                                                /*!< FTM0_SYNCONF: INVC Position             */
#define FTM_SYNCONF_INVC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_INVC_SHIFT))&FTM_SYNCONF_INVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWOC_MASK                    (0x20U)                                             /*!< FTM0_SYNCONF: SWOC Mask                 */
#define FTM_SYNCONF_SWOC_SHIFT                   (5U)                                                /*!< FTM0_SYNCONF: SWOC Position             */
#define FTM_SYNCONF_SWOC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOC_SHIFT))&FTM_SYNCONF_SWOC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SYNCMODE_MASK                (0x80U)                                             /*!< FTM0_SYNCONF: SYNCMODE Mask             */
#define FTM_SYNCONF_SYNCMODE_SHIFT               (7U)                                                /*!< FTM0_SYNCONF: SYNCMODE Position         */
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SYNCMODE_SHIFT))&FTM_SYNCONF_SYNCMODE_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWRSTCNT_MASK                (0x100U)                                            /*!< FTM0_SYNCONF: SWRSTCNT Mask             */
#define FTM_SYNCONF_SWRSTCNT_SHIFT               (8U)                                                /*!< FTM0_SYNCONF: SWRSTCNT Position         */
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWRSTCNT_SHIFT))&FTM_SYNCONF_SWRSTCNT_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWWRBUF_MASK                 (0x200U)                                            /*!< FTM0_SYNCONF: SWWRBUF Mask              */
#define FTM_SYNCONF_SWWRBUF_SHIFT                (9U)                                                /*!< FTM0_SYNCONF: SWWRBUF Position          */
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWWRBUF_SHIFT))&FTM_SYNCONF_SWWRBUF_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWOM_MASK                    (0x400U)                                            /*!< FTM0_SYNCONF: SWOM Mask                 */
#define FTM_SYNCONF_SWOM_SHIFT                   (10U)                                               /*!< FTM0_SYNCONF: SWOM Position             */
#define FTM_SYNCONF_SWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOM_SHIFT))&FTM_SYNCONF_SWOM_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWINVC_MASK                  (0x800U)                                            /*!< FTM0_SYNCONF: SWINVC Mask               */
#define FTM_SYNCONF_SWINVC_SHIFT                 (11U)                                               /*!< FTM0_SYNCONF: SWINVC Position           */
#define FTM_SYNCONF_SWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWINVC_SHIFT))&FTM_SYNCONF_SWINVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWSOC_MASK                   (0x1000U)                                           /*!< FTM0_SYNCONF: SWSOC Mask                */
#define FTM_SYNCONF_SWSOC_SHIFT                  (12U)                                               /*!< FTM0_SYNCONF: SWSOC Position            */
#define FTM_SYNCONF_SWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWSOC_SHIFT))&FTM_SYNCONF_SWSOC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWRSTCNT_MASK                (0x10000U)                                          /*!< FTM0_SYNCONF: HWRSTCNT Mask             */
#define FTM_SYNCONF_HWRSTCNT_SHIFT               (16U)                                               /*!< FTM0_SYNCONF: HWRSTCNT Position         */
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWRSTCNT_SHIFT))&FTM_SYNCONF_HWRSTCNT_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWWRBUF_MASK                 (0x20000U)                                          /*!< FTM0_SYNCONF: HWWRBUF Mask              */
#define FTM_SYNCONF_HWWRBUF_SHIFT                (17U)                                               /*!< FTM0_SYNCONF: HWWRBUF Position          */
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWWRBUF_SHIFT))&FTM_SYNCONF_HWWRBUF_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWOM_MASK                    (0x40000U)                                          /*!< FTM0_SYNCONF: HWOM Mask                 */
#define FTM_SYNCONF_HWOM_SHIFT                   (18U)                                               /*!< FTM0_SYNCONF: HWOM Position             */
#define FTM_SYNCONF_HWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWOM_SHIFT))&FTM_SYNCONF_HWOM_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWINVC_MASK                  (0x80000U)                                          /*!< FTM0_SYNCONF: HWINVC Mask               */
#define FTM_SYNCONF_HWINVC_SHIFT                 (19U)                                               /*!< FTM0_SYNCONF: HWINVC Position           */
#define FTM_SYNCONF_HWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWINVC_SHIFT))&FTM_SYNCONF_HWINVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWSOC_MASK                   (0x100000U)                                         /*!< FTM0_SYNCONF: HWSOC Mask                */
#define FTM_SYNCONF_HWSOC_SHIFT                  (20U)                                               /*!< FTM0_SYNCONF: HWSOC Position            */
#define FTM_SYNCONF_HWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWSOC_SHIFT))&FTM_SYNCONF_HWSOC_MASK) /*!< FTM0_SYNCONF                            */
/* ------- INVCTRL Bit Fields                       ------ */
#define FTM_INVCTRL_INV0EN_MASK                  (0x1U)                                              /*!< FTM0_INVCTRL: INV0EN Mask               */
#define FTM_INVCTRL_INV0EN_SHIFT                 (0U)                                                /*!< FTM0_INVCTRL: INV0EN Position           */
#define FTM_INVCTRL_INV0EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV0EN_SHIFT))&FTM_INVCTRL_INV0EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV1EN_MASK                  (0x2U)                                              /*!< FTM0_INVCTRL: INV1EN Mask               */
#define FTM_INVCTRL_INV1EN_SHIFT                 (1U)                                                /*!< FTM0_INVCTRL: INV1EN Position           */
#define FTM_INVCTRL_INV1EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV1EN_SHIFT))&FTM_INVCTRL_INV1EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV2EN_MASK                  (0x4U)                                              /*!< FTM0_INVCTRL: INV2EN Mask               */
#define FTM_INVCTRL_INV2EN_SHIFT                 (2U)                                                /*!< FTM0_INVCTRL: INV2EN Position           */
#define FTM_INVCTRL_INV2EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV2EN_SHIFT))&FTM_INVCTRL_INV2EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV3EN_MASK                  (0x8U)                                              /*!< FTM0_INVCTRL: INV3EN Mask               */
#define FTM_INVCTRL_INV3EN_SHIFT                 (3U)                                                /*!< FTM0_INVCTRL: INV3EN Position           */
#define FTM_INVCTRL_INV3EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV3EN_SHIFT))&FTM_INVCTRL_INV3EN_MASK) /*!< FTM0_INVCTRL                            */
/* ------- SWOCTRL Bit Fields                       ------ */
#define FTM_SWOCTRL_CH0OC_MASK                   (0x1U)                                              /*!< FTM0_SWOCTRL: CH0OC Mask                */
#define FTM_SWOCTRL_CH0OC_SHIFT                  (0U)                                                /*!< FTM0_SWOCTRL: CH0OC Position            */
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OC_SHIFT))&FTM_SWOCTRL_CH0OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH1OC_MASK                   (0x2U)                                              /*!< FTM0_SWOCTRL: CH1OC Mask                */
#define FTM_SWOCTRL_CH1OC_SHIFT                  (1U)                                                /*!< FTM0_SWOCTRL: CH1OC Position            */
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OC_SHIFT))&FTM_SWOCTRL_CH1OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH2OC_MASK                   (0x4U)                                              /*!< FTM0_SWOCTRL: CH2OC Mask                */
#define FTM_SWOCTRL_CH2OC_SHIFT                  (2U)                                                /*!< FTM0_SWOCTRL: CH2OC Position            */
#define FTM_SWOCTRL_CH2OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OC_SHIFT))&FTM_SWOCTRL_CH2OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH3OC_MASK                   (0x8U)                                              /*!< FTM0_SWOCTRL: CH3OC Mask                */
#define FTM_SWOCTRL_CH3OC_SHIFT                  (3U)                                                /*!< FTM0_SWOCTRL: CH3OC Position            */
#define FTM_SWOCTRL_CH3OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OC_SHIFT))&FTM_SWOCTRL_CH3OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH4OC_MASK                   (0x10U)                                             /*!< FTM0_SWOCTRL: CH4OC Mask                */
#define FTM_SWOCTRL_CH4OC_SHIFT                  (4U)                                                /*!< FTM0_SWOCTRL: CH4OC Position            */
#define FTM_SWOCTRL_CH4OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OC_SHIFT))&FTM_SWOCTRL_CH4OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH5OC_MASK                   (0x20U)                                             /*!< FTM0_SWOCTRL: CH5OC Mask                */
#define FTM_SWOCTRL_CH5OC_SHIFT                  (5U)                                                /*!< FTM0_SWOCTRL: CH5OC Position            */
#define FTM_SWOCTRL_CH5OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OC_SHIFT))&FTM_SWOCTRL_CH5OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH6OC_MASK                   (0x40U)                                             /*!< FTM0_SWOCTRL: CH6OC Mask                */
#define FTM_SWOCTRL_CH6OC_SHIFT                  (6U)                                                /*!< FTM0_SWOCTRL: CH6OC Position            */
#define FTM_SWOCTRL_CH6OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OC_SHIFT))&FTM_SWOCTRL_CH6OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH7OC_MASK                   (0x80U)                                             /*!< FTM0_SWOCTRL: CH7OC Mask                */
#define FTM_SWOCTRL_CH7OC_SHIFT                  (7U)                                                /*!< FTM0_SWOCTRL: CH7OC Position            */
#define FTM_SWOCTRL_CH7OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OC_SHIFT))&FTM_SWOCTRL_CH7OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH0OCV_MASK                  (0x100U)                                            /*!< FTM0_SWOCTRL: CH0OCV Mask               */
#define FTM_SWOCTRL_CH0OCV_SHIFT                 (8U)                                                /*!< FTM0_SWOCTRL: CH0OCV Position           */
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OCV_SHIFT))&FTM_SWOCTRL_CH0OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH1OCV_MASK                  (0x200U)                                            /*!< FTM0_SWOCTRL: CH1OCV Mask               */
#define FTM_SWOCTRL_CH1OCV_SHIFT                 (9U)                                                /*!< FTM0_SWOCTRL: CH1OCV Position           */
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OCV_SHIFT))&FTM_SWOCTRL_CH1OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH2OCV_MASK                  (0x400U)                                            /*!< FTM0_SWOCTRL: CH2OCV Mask               */
#define FTM_SWOCTRL_CH2OCV_SHIFT                 (10U)                                               /*!< FTM0_SWOCTRL: CH2OCV Position           */
#define FTM_SWOCTRL_CH2OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OCV_SHIFT))&FTM_SWOCTRL_CH2OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH3OCV_MASK                  (0x800U)                                            /*!< FTM0_SWOCTRL: CH3OCV Mask               */
#define FTM_SWOCTRL_CH3OCV_SHIFT                 (11U)                                               /*!< FTM0_SWOCTRL: CH3OCV Position           */
#define FTM_SWOCTRL_CH3OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OCV_SHIFT))&FTM_SWOCTRL_CH3OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH4OCV_MASK                  (0x1000U)                                           /*!< FTM0_SWOCTRL: CH4OCV Mask               */
#define FTM_SWOCTRL_CH4OCV_SHIFT                 (12U)                                               /*!< FTM0_SWOCTRL: CH4OCV Position           */
#define FTM_SWOCTRL_CH4OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OCV_SHIFT))&FTM_SWOCTRL_CH4OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH5OCV_MASK                  (0x2000U)                                           /*!< FTM0_SWOCTRL: CH5OCV Mask               */
#define FTM_SWOCTRL_CH5OCV_SHIFT                 (13U)                                               /*!< FTM0_SWOCTRL: CH5OCV Position           */
#define FTM_SWOCTRL_CH5OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OCV_SHIFT))&FTM_SWOCTRL_CH5OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH6OCV_MASK                  (0x4000U)                                           /*!< FTM0_SWOCTRL: CH6OCV Mask               */
#define FTM_SWOCTRL_CH6OCV_SHIFT                 (14U)                                               /*!< FTM0_SWOCTRL: CH6OCV Position           */
#define FTM_SWOCTRL_CH6OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OCV_SHIFT))&FTM_SWOCTRL_CH6OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH7OCV_MASK                  (0x8000U)                                           /*!< FTM0_SWOCTRL: CH7OCV Mask               */
#define FTM_SWOCTRL_CH7OCV_SHIFT                 (15U)                                               /*!< FTM0_SWOCTRL: CH7OCV Position           */
#define FTM_SWOCTRL_CH7OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OCV_SHIFT))&FTM_SWOCTRL_CH7OCV_MASK) /*!< FTM0_SWOCTRL                            */
/* ------- PWMLOAD Bit Fields                       ------ */
#define FTM_PWMLOAD_CH0SEL_MASK                  (0x1U)                                              /*!< FTM0_PWMLOAD: CH0SEL Mask               */
#define FTM_PWMLOAD_CH0SEL_SHIFT                 (0U)                                                /*!< FTM0_PWMLOAD: CH0SEL Position           */
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH0SEL_SHIFT))&FTM_PWMLOAD_CH0SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH1SEL_MASK                  (0x2U)                                              /*!< FTM0_PWMLOAD: CH1SEL Mask               */
#define FTM_PWMLOAD_CH1SEL_SHIFT                 (1U)                                                /*!< FTM0_PWMLOAD: CH1SEL Position           */
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH1SEL_SHIFT))&FTM_PWMLOAD_CH1SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH2SEL_MASK                  (0x4U)                                              /*!< FTM0_PWMLOAD: CH2SEL Mask               */
#define FTM_PWMLOAD_CH2SEL_SHIFT                 (2U)                                                /*!< FTM0_PWMLOAD: CH2SEL Position           */
#define FTM_PWMLOAD_CH2SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH2SEL_SHIFT))&FTM_PWMLOAD_CH2SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH3SEL_MASK                  (0x8U)                                              /*!< FTM0_PWMLOAD: CH3SEL Mask               */
#define FTM_PWMLOAD_CH3SEL_SHIFT                 (3U)                                                /*!< FTM0_PWMLOAD: CH3SEL Position           */
#define FTM_PWMLOAD_CH3SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH3SEL_SHIFT))&FTM_PWMLOAD_CH3SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH4SEL_MASK                  (0x10U)                                             /*!< FTM0_PWMLOAD: CH4SEL Mask               */
#define FTM_PWMLOAD_CH4SEL_SHIFT                 (4U)                                                /*!< FTM0_PWMLOAD: CH4SEL Position           */
#define FTM_PWMLOAD_CH4SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH4SEL_SHIFT))&FTM_PWMLOAD_CH4SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH5SEL_MASK                  (0x20U)                                             /*!< FTM0_PWMLOAD: CH5SEL Mask               */
#define FTM_PWMLOAD_CH5SEL_SHIFT                 (5U)                                                /*!< FTM0_PWMLOAD: CH5SEL Position           */
#define FTM_PWMLOAD_CH5SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH5SEL_SHIFT))&FTM_PWMLOAD_CH5SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH6SEL_MASK                  (0x40U)                                             /*!< FTM0_PWMLOAD: CH6SEL Mask               */
#define FTM_PWMLOAD_CH6SEL_SHIFT                 (6U)                                                /*!< FTM0_PWMLOAD: CH6SEL Position           */
#define FTM_PWMLOAD_CH6SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH6SEL_SHIFT))&FTM_PWMLOAD_CH6SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH7SEL_MASK                  (0x80U)                                             /*!< FTM0_PWMLOAD: CH7SEL Mask               */
#define FTM_PWMLOAD_CH7SEL_SHIFT                 (7U)                                                /*!< FTM0_PWMLOAD: CH7SEL Position           */
#define FTM_PWMLOAD_CH7SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH7SEL_SHIFT))&FTM_PWMLOAD_CH7SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_LDOK_MASK                    (0x200U)                                            /*!< FTM0_PWMLOAD: LDOK Mask                 */
#define FTM_PWMLOAD_LDOK_SHIFT                   (9U)                                                /*!< FTM0_PWMLOAD: LDOK Position             */
#define FTM_PWMLOAD_LDOK(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_LDOK_SHIFT))&FTM_PWMLOAD_LDOK_MASK) /*!< FTM0_PWMLOAD                            */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM0 - Peripheral instance base addresses */
#define FTM0_BasePtr                   0x40038000UL //!< Peripheral base address
#define FTM0                           ((FTM_Type *) FTM0_BasePtr) //!< Freescale base pointer
#define FTM0_BASE_PTR                  (FTM0) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM1 (file:FTM1_2CH)                 ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM1 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[2];                               /**< 000C: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CNTIN;                        /**< 004C: Counter Initial Value                                        */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
   __IO uint32_t  MODE;                         /**< 0054: Features Mode Selection                                      */
   __IO uint32_t  SYNC;                         /**< 0058: Synchronization                                              */
   __IO uint32_t  OUTINIT;                      /**< 005C: Initial State for Channels Output                            */
   __IO uint32_t  OUTMASK;                      /**< 0060: Output Mask                                                  */
   __IO uint32_t  COMBINE;                      /**< 0064: Function for Linked Channels                                 */
   __IO uint32_t  DEADTIME;                     /**< 0068: Deadtime Insertion Control                                   */
   __IO uint32_t  EXTTRIG;                      /**< 006C: FTM External Trigger                                         */
   __IO uint32_t  POL;                          /**< 0070: Channels Polarity                                            */
   __IO uint32_t  FMS;                          /**< 0074: Fault Mode Status                                            */
   __IO uint32_t  FILTER;                       /**< 0078: Input Capture Filter Control                                 */
   __IO uint32_t  FLTCTRL;                      /**< 007C: Fault Control                                                */
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM1_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
/* ------- CNT Bit Fields                           ------ */
/* ------- MOD Bit Fields                           ------ */
/* ------- CnSC Bit Fields                          ------ */
/* ------- CnV Bit Fields                           ------ */
/* ------- CNTIN Bit Fields                         ------ */
/* ------- STATUS Bit Fields                        ------ */
/* ------- MODE Bit Fields                          ------ */
/* ------- SYNC Bit Fields                          ------ */
/* ------- OUTINIT Bit Fields                       ------ */
/* ------- OUTMASK Bit Fields                       ------ */
/* ------- COMBINE Bit Fields                       ------ */
/* ------- DEADTIME Bit Fields                      ------ */
/* ------- EXTTRIG Bit Fields                       ------ */
/* ------- POL Bit Fields                           ------ */
/* ------- FMS Bit Fields                           ------ */
/* ------- FILTER Bit Fields                        ------ */
/* ------- FLTCTRL Bit Fields                       ------ */
/* ------- QDCTRL Bit Fields                        ------ */
/* ------- CONF Bit Fields                          ------ */
/* ------- FLTPOL Bit Fields                        ------ */
/* ------- SYNCONF Bit Fields                       ------ */
/* ------- INVCTRL Bit Fields                       ------ */
/* ------- SWOCTRL Bit Fields                       ------ */
/* ------- PWMLOAD Bit Fields                       ------ */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM1 - Peripheral instance base addresses */
#define FTM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define FTM1                           ((FTM1_Type *) FTM1_BasePtr) //!< Freescale base pointer
#define FTM1_BASE_PTR                  (FTM1) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM2 (derived from FTM1)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */

/* FTM2 - Peripheral instance base addresses */
#define FTM2_BasePtr                   0x4003A000UL //!< Peripheral base address
#define FTM2                           ((FTM1_Type *) FTM2_BasePtr) //!< Freescale base pointer
#define FTM2_BASE_PTR                  (FTM2) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_0x400FF000)        ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
* @addtogroup GPIOA_structs_GROUP GPIOA struct
* @brief Struct for GPIOA
* @{
*/
typedef struct {                                /*       GPIOA Structure                                              */
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
} GPIO_Type;

/**
 * @} */ /* End group GPIOA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIOA_Register_Masks_GROUP GPIOA Register Masks
* @brief Register Masks for GPIOA
* @{
*/
/* ------- PDOR Bit Fields                          ------ */
/* ------- PSOR Bit Fields                          ------ */
/* ------- PCOR Bit Fields                          ------ */
/* ------- PTOR Bit Fields                          ------ */
/* ------- PDIR Bit Fields                          ------ */
/* ------- PDDR Bit Fields                          ------ */
/**
 * @} */ /* End group GPIOA_Register_Masks_GROUP 
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x400FF000UL //!< Peripheral base address
#define GPIOA                          ((GPIO_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOB (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOB                          ((GPIO_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOC (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOC                          ((GPIO_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOD (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x400FF0C0UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOE (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0x400FF100UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MK10D5)              ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
*/
typedef struct {                                /*       I2C0 Structure                                               */
   __IO uint8_t   A1;                           /**< 0000: Address Register 1                                           */
   __IO uint8_t   F;                            /**< 0001: Frequency Divider register                                   */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   S;                            /**< 0003: Status Register                                              */
   __IO uint8_t   D;                            /**< 0004: Data I/O register                                            */
   __IO uint8_t   C2;                           /**< 0005: Control Register 2                                           */
   __IO uint8_t   FLT;                          /**< 0006: Programmable Input Glitch Filter register                    */
   __IO uint8_t   RA;                           /**< 0007: Range Address register                                       */
   __IO uint8_t   SMB;                          /**< 0008: SMBus Control and Status register                            */
   __IO uint8_t   A2;                           /**< 0009: Address Register 2                                           */
   __IO uint8_t   SLTH;                         /**< 000A: SCL Low Timeout Register High                                */
   __IO uint8_t   SLTL;                         /**< 000B: SCL Low Timeout Register Low                                 */
} I2C_Type;

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- A1 Bit Fields                            ------ */
#define I2C_A1_AD_MASK                           (0xFEU)                                             /*!< I2C0_A1: AD Mask                        */
#define I2C_A1_AD_SHIFT                          (1U)                                                /*!< I2C0_A1: AD Position                    */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK) /*!< I2C0_A1                                 */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FU)                                             /*!< I2C0_F: ICR Mask                        */
#define I2C_F_ICR_SHIFT                          (0U)                                                /*!< I2C0_F: ICR Position                    */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK) /*!< I2C0_F                                  */
#define I2C_F_MULT_MASK                          (0xC0U)                                             /*!< I2C0_F: MULT Mask                       */
#define I2C_F_MULT_SHIFT                         (6U)                                                /*!< I2C0_F: MULT Position                   */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK) /*!< I2C0_F                                  */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x1U)                                              /*!< I2C0_C1: DMAEN Mask                     */
#define I2C_C1_DMAEN_SHIFT                       (0U)                                                /*!< I2C0_C1: DMAEN Position                 */
#define I2C_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_DMAEN_SHIFT))&I2C_C1_DMAEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_WUEN_MASK                         (0x2U)                                              /*!< I2C0_C1: WUEN Mask                      */
#define I2C_C1_WUEN_SHIFT                        (1U)                                                /*!< I2C0_C1: WUEN Position                  */
#define I2C_C1_WUEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_WUEN_SHIFT))&I2C_C1_WUEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_RSTA_MASK                         (0x4U)                                              /*!< I2C0_C1: RSTA Mask                      */
#define I2C_C1_RSTA_SHIFT                        (2U)                                                /*!< I2C0_C1: RSTA Position                  */
#define I2C_C1_RSTA(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_RSTA_SHIFT))&I2C_C1_RSTA_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TXAK_MASK                         (0x8U)                                              /*!< I2C0_C1: TXAK Mask                      */
#define I2C_C1_TXAK_SHIFT                        (3U)                                                /*!< I2C0_C1: TXAK Position                  */
#define I2C_C1_TXAK(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_TXAK_SHIFT))&I2C_C1_TXAK_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TX_MASK                           (0x10U)                                             /*!< I2C0_C1: TX Mask                        */
#define I2C_C1_TX_SHIFT                          (4U)                                                /*!< I2C0_C1: TX Position                    */
#define I2C_C1_TX(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C1_TX_SHIFT))&I2C_C1_TX_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_MST_MASK                          (0x20U)                                             /*!< I2C0_C1: MST Mask                       */
#define I2C_C1_MST_SHIFT                         (5U)                                                /*!< I2C0_C1: MST Position                   */
#define I2C_C1_MST(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_C1_MST_SHIFT))&I2C_C1_MST_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICIE_MASK                        (0x40U)                                             /*!< I2C0_C1: IICIE Mask                     */
#define I2C_C1_IICIE_SHIFT                       (6U)                                                /*!< I2C0_C1: IICIE Position                 */
#define I2C_C1_IICIE(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICIE_SHIFT))&I2C_C1_IICIE_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICEN_MASK                        (0x80U)                                             /*!< I2C0_C1: IICEN Mask                     */
#define I2C_C1_IICEN_SHIFT                       (7U)                                                /*!< I2C0_C1: IICEN Position                 */
#define I2C_C1_IICEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICEN_SHIFT))&I2C_C1_IICEN_MASK) /*!< I2C0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x1U)                                              /*!< I2C0_S: RXAK Mask                       */
#define I2C_S_RXAK_SHIFT                         (0U)                                                /*!< I2C0_S: RXAK Position                   */
#define I2C_S_RXAK(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_RXAK_SHIFT))&I2C_S_RXAK_MASK) /*!< I2C0_S                                  */
#define I2C_S_IICIF_MASK                         (0x2U)                                              /*!< I2C0_S: IICIF Mask                      */
#define I2C_S_IICIF_SHIFT                        (1U)                                                /*!< I2C0_S: IICIF Position                  */
#define I2C_S_IICIF(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_S_IICIF_SHIFT))&I2C_S_IICIF_MASK) /*!< I2C0_S                                  */
#define I2C_S_SRW_MASK                           (0x4U)                                              /*!< I2C0_S: SRW Mask                        */
#define I2C_S_SRW_SHIFT                          (2U)                                                /*!< I2C0_S: SRW Position                    */
#define I2C_S_SRW(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_SRW_SHIFT))&I2C_S_SRW_MASK) /*!< I2C0_S                                  */
#define I2C_S_RAM_MASK                           (0x8U)                                              /*!< I2C0_S: RAM Mask                        */
#define I2C_S_RAM_SHIFT                          (3U)                                                /*!< I2C0_S: RAM Position                    */
#define I2C_S_RAM(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_RAM_SHIFT))&I2C_S_RAM_MASK) /*!< I2C0_S                                  */
#define I2C_S_ARBL_MASK                          (0x10U)                                             /*!< I2C0_S: ARBL Mask                       */
#define I2C_S_ARBL_SHIFT                         (4U)                                                /*!< I2C0_S: ARBL Position                   */
#define I2C_S_ARBL(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_ARBL_SHIFT))&I2C_S_ARBL_MASK) /*!< I2C0_S                                  */
#define I2C_S_BUSY_MASK                          (0x20U)                                             /*!< I2C0_S: BUSY Mask                       */
#define I2C_S_BUSY_SHIFT                         (5U)                                                /*!< I2C0_S: BUSY Position                   */
#define I2C_S_BUSY(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_BUSY_SHIFT))&I2C_S_BUSY_MASK) /*!< I2C0_S                                  */
#define I2C_S_IAAS_MASK                          (0x40U)                                             /*!< I2C0_S: IAAS Mask                       */
#define I2C_S_IAAS_SHIFT                         (6U)                                                /*!< I2C0_S: IAAS Position                   */
#define I2C_S_IAAS(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_IAAS_SHIFT))&I2C_S_IAAS_MASK) /*!< I2C0_S                                  */
#define I2C_S_TCF_MASK                           (0x80U)                                             /*!< I2C0_S: TCF Mask                        */
#define I2C_S_TCF_SHIFT                          (7U)                                                /*!< I2C0_S: TCF Position                    */
#define I2C_S_TCF(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_TCF_SHIFT))&I2C_S_TCF_MASK) /*!< I2C0_S                                  */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFU)                                             /*!< I2C0_D: DATA Mask                       */
#define I2C_D_DATA_SHIFT                         (0U)                                                /*!< I2C0_D: DATA Position                   */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK) /*!< I2C0_D                                  */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x7U)                                              /*!< I2C0_C2: AD Mask                        */
#define I2C_C2_AD_SHIFT                          (0U)                                                /*!< I2C0_C2: AD Position                    */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_RMEN_MASK                         (0x8U)                                              /*!< I2C0_C2: RMEN Mask                      */
#define I2C_C2_RMEN_SHIFT                        (3U)                                                /*!< I2C0_C2: RMEN Position                  */
#define I2C_C2_RMEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_RMEN_SHIFT))&I2C_C2_RMEN_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_SBRC_MASK                         (0x10U)                                             /*!< I2C0_C2: SBRC Mask                      */
#define I2C_C2_SBRC_SHIFT                        (4U)                                                /*!< I2C0_C2: SBRC Position                  */
#define I2C_C2_SBRC(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_SBRC_SHIFT))&I2C_C2_SBRC_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_HDRS_MASK                         (0x20U)                                             /*!< I2C0_C2: HDRS Mask                      */
#define I2C_C2_HDRS_SHIFT                        (5U)                                                /*!< I2C0_C2: HDRS Position                  */
#define I2C_C2_HDRS(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_HDRS_SHIFT))&I2C_C2_HDRS_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_ADEXT_MASK                        (0x40U)                                             /*!< I2C0_C2: ADEXT Mask                     */
#define I2C_C2_ADEXT_SHIFT                       (6U)                                                /*!< I2C0_C2: ADEXT Position                 */
#define I2C_C2_ADEXT(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_ADEXT_SHIFT))&I2C_C2_ADEXT_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_GCAEN_MASK                        (0x80U)                                             /*!< I2C0_C2: GCAEN Mask                     */
#define I2C_C2_GCAEN_SHIFT                       (7U)                                                /*!< I2C0_C2: GCAEN Position                 */
#define I2C_C2_GCAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_GCAEN_SHIFT))&I2C_C2_GCAEN_MASK) /*!< I2C0_C2                                 */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0x1FU)                                             /*!< I2C0_FLT: FLT Mask                      */
#define I2C_FLT_FLT_SHIFT                        (0U)                                                /*!< I2C0_FLT: FLT Position                  */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /*!< I2C0_FLT                                */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0xFEU)                                             /*!< I2C0_RA: RAD Mask                       */
#define I2C_RA_RAD_SHIFT                         (1U)                                                /*!< I2C0_RA: RAD Position                   */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK) /*!< I2C0_RA                                 */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x1U)                                              /*!< I2C0_SMB: SHTF2IE Mask                  */
#define I2C_SMB_SHTF2IE_SHIFT                    (0U)                                                /*!< I2C0_SMB: SHTF2IE Position              */
#define I2C_SMB_SHTF2IE(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2IE_SHIFT))&I2C_SMB_SHTF2IE_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF2_MASK                       (0x2U)                                              /*!< I2C0_SMB: SHTF2 Mask                    */
#define I2C_SMB_SHTF2_SHIFT                      (1U)                                                /*!< I2C0_SMB: SHTF2 Position                */
#define I2C_SMB_SHTF2(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2_SHIFT))&I2C_SMB_SHTF2_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF1_MASK                       (0x4U)                                              /*!< I2C0_SMB: SHTF1 Mask                    */
#define I2C_SMB_SHTF1_SHIFT                      (2U)                                                /*!< I2C0_SMB: SHTF1 Position                */
#define I2C_SMB_SHTF1(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF1_SHIFT))&I2C_SMB_SHTF1_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SLTF_MASK                        (0x8U)                                              /*!< I2C0_SMB: SLTF Mask                     */
#define I2C_SMB_SLTF_SHIFT                       (3U)                                                /*!< I2C0_SMB: SLTF Position                 */
#define I2C_SMB_SLTF(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SLTF_SHIFT))&I2C_SMB_SLTF_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_TCKSEL_MASK                      (0x10U)                                             /*!< I2C0_SMB: TCKSEL Mask                   */
#define I2C_SMB_TCKSEL_SHIFT                     (4U)                                                /*!< I2C0_SMB: TCKSEL Position               */
#define I2C_SMB_TCKSEL(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_SMB_TCKSEL_SHIFT))&I2C_SMB_TCKSEL_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SIICAEN_MASK                     (0x20U)                                             /*!< I2C0_SMB: SIICAEN Mask                  */
#define I2C_SMB_SIICAEN_SHIFT                    (5U)                                                /*!< I2C0_SMB: SIICAEN Position              */
#define I2C_SMB_SIICAEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SIICAEN_SHIFT))&I2C_SMB_SIICAEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_ALERTEN_MASK                     (0x40U)                                             /*!< I2C0_SMB: ALERTEN Mask                  */
#define I2C_SMB_ALERTEN_SHIFT                    (6U)                                                /*!< I2C0_SMB: ALERTEN Position              */
#define I2C_SMB_ALERTEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_ALERTEN_SHIFT))&I2C_SMB_ALERTEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_FACK_MASK                        (0x80U)                                             /*!< I2C0_SMB: FACK Mask                     */
#define I2C_SMB_FACK_SHIFT                       (7U)                                                /*!< I2C0_SMB: FACK Position                 */
#define I2C_SMB_FACK(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_FACK_SHIFT))&I2C_SMB_FACK_MASK) /*!< I2C0_SMB                                */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0xFEU)                                             /*!< I2C0_A2: SAD Mask                       */
#define I2C_A2_SAD_SHIFT                         (1U)                                                /*!< I2C0_A2: SAD Position                   */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK) /*!< I2C0_A2                                 */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTH: SSLT Mask                    */
#define I2C_SLTH_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTH: SSLT Position                */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK) /*!< I2C0_SLTH                               */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTL: SSLT Mask                    */
#define I2C_SLTL_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTL: SSLT Position                */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK) /*!< I2C0_SLTL                               */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40066000UL //!< Peripheral base address
#define I2C0                           ((I2C_Type *) I2C0_BasePtr) //!< Freescale base pointer
#define I2C0_BASE_PTR                  (I2C0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C1 (derived from I2C0)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */

/* I2C1 - Peripheral instance base addresses */
#define I2C1_BasePtr                   0x40067000UL //!< Peripheral base address
#define I2C1                           ((I2C_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2S_Peripheral_access_layer_GROUP I2S Peripheral Access Layer
* @brief C Struct for I2S
* @{
*/

/* ================================================================================ */
/* ================           I2S0 (file:I2S0_1CH)                 ================ */
/* ================================================================================ */

/**
 * @brief Inter-IC Sound / Synchronous Audio Interface
 */
/**
* @addtogroup I2S_structs_GROUP I2S struct
* @brief Struct for I2S
* @{
*/
typedef struct {                                /*       I2S0 Structure                                               */
   __IO uint32_t  TCSR;                         /**< 0000: SAI Transmit Control Register                                */
   __IO uint32_t  TCR1;                         /**< 0004: SAI Transmit Configuration 1 Register                        */
   __IO uint32_t  TCR2;                         /**< 0008: SAI Transmit Configuration 2 Register                        */
   __IO uint32_t  TCR3;                         /**< 000C: SAI Transmit Configuration 3 Register                        */
   __IO uint32_t  TCR4;                         /**< 0010: SAI Transmit Configuration 4 Register                        */
   __IO uint32_t  TCR5;                         /**< 0014: SAI Transmit Configuration 5 Register                        */
        uint8_t   RESERVED_0[8];               
   __O  uint32_t  TDR[1];                       /**< 0020: Transmit Data Register                                       */
        uint8_t   RESERVED_1[28];              
   __I  uint32_t  TFR[1];                       /**< 0040: SAI Transmit FIFO Register                                   */
        uint8_t   RESERVED_2[28];              
   __IO uint32_t  TMR;                          /**< 0060: SAI Transmit Mask Register                                   */
        uint8_t   RESERVED_3[28];              
   __IO uint32_t  RCSR;                         /**< 0080: SAI Receive Control Register                                 */
   __IO uint32_t  RCR1;                         /**< 0084: SAI Receive Configuration 1 Register                         */
   __IO uint32_t  RCR2;                         /**< 0088: SAI Receive Configuration 2 Register                         */
   __IO uint32_t  RCR3;                         /**< 008C: SAI Receive Configuration 3 Register                         */
   __IO uint32_t  RCR4;                         /**< 0090: SAI Receive Configuration 4 Register                         */
   __IO uint32_t  RCR5;                         /**< 0094: SAI Receive Configuration 5 Register                         */
        uint8_t   RESERVED_4[8];               
   __I  uint32_t  RDR[1];                       /**< 00A0: SAI Receive Data Register                                    */
        uint8_t   RESERVED_5[28];              
   __I  uint32_t  RFR[1];                       /**< 00C0: SAI Receive FIFO Register                                    */
        uint8_t   RESERVED_6[28];              
   __IO uint32_t  RMR;                          /**< 00E0: SAI Receive Mask Register                                    */
        uint8_t   RESERVED_7[28];              
   __IO uint32_t  MCR;                          /**< 0100: SAI MCLK Control Register                                    */
   __IO uint32_t  MDR;                          /**< 0104: SAI MCLK Divide Register                                     */
} I2S_Type;

/**
 * @} */ /* End group I2S_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2S0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2S_Register_Masks_GROUP I2S Register Masks
* @brief Register Masks for I2S
* @{
*/
/* ------- TCSR Bit Fields                          ------ */
#define I2S_TCSR_FRDE_MASK                       (0x1U)                                              /*!< I2S0_TCSR: FRDE Mask                    */
#define I2S_TCSR_FRDE_SHIFT                      (0U)                                                /*!< I2S0_TCSR: FRDE Position                */
#define I2S_TCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRDE_SHIFT))&I2S_TCSR_FRDE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWDE_MASK                       (0x2U)                                              /*!< I2S0_TCSR: FWDE Mask                    */
#define I2S_TCSR_FWDE_SHIFT                      (1U)                                                /*!< I2S0_TCSR: FWDE Position                */
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWDE_SHIFT))&I2S_TCSR_FWDE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FRIE_MASK                       (0x100U)                                            /*!< I2S0_TCSR: FRIE Mask                    */
#define I2S_TCSR_FRIE_SHIFT                      (8U)                                                /*!< I2S0_TCSR: FRIE Position                */
#define I2S_TCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRIE_SHIFT))&I2S_TCSR_FRIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWIE_MASK                       (0x200U)                                            /*!< I2S0_TCSR: FWIE Mask                    */
#define I2S_TCSR_FWIE_SHIFT                      (9U)                                                /*!< I2S0_TCSR: FWIE Position                */
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWIE_SHIFT))&I2S_TCSR_FWIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FEIE_MASK                       (0x400U)                                            /*!< I2S0_TCSR: FEIE Mask                    */
#define I2S_TCSR_FEIE_SHIFT                      (10U)                                               /*!< I2S0_TCSR: FEIE Position                */
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEIE_SHIFT))&I2S_TCSR_FEIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SEIE_MASK                       (0x800U)                                            /*!< I2S0_TCSR: SEIE Mask                    */
#define I2S_TCSR_SEIE_SHIFT                      (11U)                                               /*!< I2S0_TCSR: SEIE Position                */
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEIE_SHIFT))&I2S_TCSR_SEIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_WSIE_MASK                       (0x1000U)                                           /*!< I2S0_TCSR: WSIE Mask                    */
#define I2S_TCSR_WSIE_SHIFT                      (12U)                                               /*!< I2S0_TCSR: WSIE Position                */
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSIE_SHIFT))&I2S_TCSR_WSIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FRF_MASK                        (0x10000U)                                          /*!< I2S0_TCSR: FRF Mask                     */
#define I2S_TCSR_FRF_SHIFT                       (16U)                                               /*!< I2S0_TCSR: FRF Position                 */
#define I2S_TCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRF_SHIFT))&I2S_TCSR_FRF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWF_MASK                        (0x20000U)                                          /*!< I2S0_TCSR: FWF Mask                     */
#define I2S_TCSR_FWF_SHIFT                       (17U)                                               /*!< I2S0_TCSR: FWF Position                 */
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWF_SHIFT))&I2S_TCSR_FWF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FEF_MASK                        (0x40000U)                                          /*!< I2S0_TCSR: FEF Mask                     */
#define I2S_TCSR_FEF_SHIFT                       (18U)                                               /*!< I2S0_TCSR: FEF Position                 */
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEF_SHIFT))&I2S_TCSR_FEF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SEF_MASK                        (0x80000U)                                          /*!< I2S0_TCSR: SEF Mask                     */
#define I2S_TCSR_SEF_SHIFT                       (19U)                                               /*!< I2S0_TCSR: SEF Position                 */
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEF_SHIFT))&I2S_TCSR_SEF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_WSF_MASK                        (0x100000U)                                         /*!< I2S0_TCSR: WSF Mask                     */
#define I2S_TCSR_WSF_SHIFT                       (20U)                                               /*!< I2S0_TCSR: WSF Position                 */
#define I2S_TCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSF_SHIFT))&I2S_TCSR_WSF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SR_MASK                         (0x1000000U)                                        /*!< I2S0_TCSR: SR Mask                      */
#define I2S_TCSR_SR_SHIFT                        (24U)                                               /*!< I2S0_TCSR: SR Position                  */
#define I2S_TCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SR_SHIFT))&I2S_TCSR_SR_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FR_MASK                         (0x2000000U)                                        /*!< I2S0_TCSR: FR Mask                      */
#define I2S_TCSR_FR_SHIFT                        (25U)                                               /*!< I2S0_TCSR: FR Position                  */
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FR_SHIFT))&I2S_TCSR_FR_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_BCE_MASK                        (0x10000000U)                                       /*!< I2S0_TCSR: BCE Mask                     */
#define I2S_TCSR_BCE_SHIFT                       (28U)                                               /*!< I2S0_TCSR: BCE Position                 */
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_BCE_SHIFT))&I2S_TCSR_BCE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_DBGE_MASK                       (0x20000000U)                                       /*!< I2S0_TCSR: DBGE Mask                    */
#define I2S_TCSR_DBGE_SHIFT                      (29U)                                               /*!< I2S0_TCSR: DBGE Position                */
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_DBGE_SHIFT))&I2S_TCSR_DBGE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_STOPE_MASK                      (0x40000000U)                                       /*!< I2S0_TCSR: STOPE Mask                   */
#define I2S_TCSR_STOPE_SHIFT                     (30U)                                               /*!< I2S0_TCSR: STOPE Position               */
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_STOPE_SHIFT))&I2S_TCSR_STOPE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_TE_MASK                         (0x80000000U)                                       /*!< I2S0_TCSR: TE Mask                      */
#define I2S_TCSR_TE_SHIFT                        (31U)                                               /*!< I2S0_TCSR: TE Position                  */
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_TE_SHIFT))&I2S_TCSR_TE_MASK) /*!< I2S0_TCSR                               */
/* ------- TCR1 Bit Fields                          ------ */
#define I2S_TCR1_TFW_MASK                        (0x7U)                                              /*!< I2S0_TCR1: TFW Mask                     */
#define I2S_TCR1_TFW_SHIFT                       (0U)                                                /*!< I2S0_TCR1: TFW Position                 */
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR1_TFW_SHIFT))&I2S_TCR1_TFW_MASK) /*!< I2S0_TCR1                               */
/* ------- TCR2 Bit Fields                          ------ */
#define I2S_TCR2_DIV_MASK                        (0xFFU)                                             /*!< I2S0_TCR2: DIV Mask                     */
#define I2S_TCR2_DIV_SHIFT                       (0U)                                                /*!< I2S0_TCR2: DIV Position                 */
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_DIV_SHIFT))&I2S_TCR2_DIV_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCD_MASK                        (0x1000000U)                                        /*!< I2S0_TCR2: BCD Mask                     */
#define I2S_TCR2_BCD_SHIFT                       (24U)                                               /*!< I2S0_TCR2: BCD Position                 */
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCD_SHIFT))&I2S_TCR2_BCD_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCP_MASK                        (0x2000000U)                                        /*!< I2S0_TCR2: BCP Mask                     */
#define I2S_TCR2_BCP_SHIFT                       (25U)                                               /*!< I2S0_TCR2: BCP Position                 */
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCP_SHIFT))&I2S_TCR2_BCP_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_MSEL_MASK                       (0xC000000U)                                        /*!< I2S0_TCR2: MSEL Mask                    */
#define I2S_TCR2_MSEL_SHIFT                      (26U)                                               /*!< I2S0_TCR2: MSEL Position                */
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_MSEL_SHIFT))&I2S_TCR2_MSEL_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCI_MASK                        (0x10000000U)                                       /*!< I2S0_TCR2: BCI Mask                     */
#define I2S_TCR2_BCI_SHIFT                       (28U)                                               /*!< I2S0_TCR2: BCI Position                 */
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCI_SHIFT))&I2S_TCR2_BCI_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCS_MASK                        (0x20000000U)                                       /*!< I2S0_TCR2: BCS Mask                     */
#define I2S_TCR2_BCS_SHIFT                       (29U)                                               /*!< I2S0_TCR2: BCS Position                 */
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCS_SHIFT))&I2S_TCR2_BCS_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_SYNC_MASK                       (0xC0000000U)                                       /*!< I2S0_TCR2: SYNC Mask                    */
#define I2S_TCR2_SYNC_SHIFT                      (30U)                                               /*!< I2S0_TCR2: SYNC Position                */
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_SYNC_SHIFT))&I2S_TCR2_SYNC_MASK) /*!< I2S0_TCR2                               */
/* ------- TCR3 Bit Fields                          ------ */
#define I2S_TCR3_WDFL_MASK                       (0xFU)                                              /*!< I2S0_TCR3: WDFL Mask                    */
#define I2S_TCR3_WDFL_SHIFT                      (0U)                                                /*!< I2S0_TCR3: WDFL Position                */
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_WDFL_SHIFT))&I2S_TCR3_WDFL_MASK) /*!< I2S0_TCR3                               */
#define I2S_TCR3_TCE_MASK                        (0x10000U)                                          /*!< I2S0_TCR3: TCE Mask                     */
#define I2S_TCR3_TCE_SHIFT                       (16U)                                               /*!< I2S0_TCR3: TCE Position                 */
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_TCE_SHIFT))&I2S_TCR3_TCE_MASK) /*!< I2S0_TCR3                               */
/* ------- TCR4 Bit Fields                          ------ */
#define I2S_TCR4_FSD_MASK                        (0x1U)                                              /*!< I2S0_TCR4: FSD Mask                     */
#define I2S_TCR4_FSD_SHIFT                       (0U)                                                /*!< I2S0_TCR4: FSD Position                 */
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSD_SHIFT))&I2S_TCR4_FSD_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FSP_MASK                        (0x2U)                                              /*!< I2S0_TCR4: FSP Mask                     */
#define I2S_TCR4_FSP_SHIFT                       (1U)                                                /*!< I2S0_TCR4: FSP Position                 */
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSP_SHIFT))&I2S_TCR4_FSP_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FSE_MASK                        (0x8U)                                              /*!< I2S0_TCR4: FSE Mask                     */
#define I2S_TCR4_FSE_SHIFT                       (3U)                                                /*!< I2S0_TCR4: FSE Position                 */
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSE_SHIFT))&I2S_TCR4_FSE_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_MF_MASK                         (0x10U)                                             /*!< I2S0_TCR4: MF Mask                      */
#define I2S_TCR4_MF_SHIFT                        (4U)                                                /*!< I2S0_TCR4: MF Position                  */
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_MF_SHIFT))&I2S_TCR4_MF_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_SYWD_MASK                       (0x1F00U)                                           /*!< I2S0_TCR4: SYWD Mask                    */
#define I2S_TCR4_SYWD_SHIFT                      (8U)                                                /*!< I2S0_TCR4: SYWD Position                */
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_SYWD_SHIFT))&I2S_TCR4_SYWD_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FRSZ_MASK                       (0xF0000U)                                          /*!< I2S0_TCR4: FRSZ Mask                    */
#define I2S_TCR4_FRSZ_SHIFT                      (16U)                                               /*!< I2S0_TCR4: FRSZ Position                */
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FRSZ_SHIFT))&I2S_TCR4_FRSZ_MASK) /*!< I2S0_TCR4                               */
/* ------- TCR5 Bit Fields                          ------ */
#define I2S_TCR5_FBT_MASK                        (0x1F00U)                                           /*!< I2S0_TCR5: FBT Mask                     */
#define I2S_TCR5_FBT_SHIFT                       (8U)                                                /*!< I2S0_TCR5: FBT Position                 */
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_FBT_SHIFT))&I2S_TCR5_FBT_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_W0W_MASK                        (0x1F0000U)                                         /*!< I2S0_TCR5: W0W Mask                     */
#define I2S_TCR5_W0W_SHIFT                       (16U)                                               /*!< I2S0_TCR5: W0W Position                 */
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_W0W_SHIFT))&I2S_TCR5_W0W_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_WNW_MASK                        (0x1F000000U)                                       /*!< I2S0_TCR5: WNW Mask                     */
#define I2S_TCR5_WNW_SHIFT                       (24U)                                               /*!< I2S0_TCR5: WNW Position                 */
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_WNW_SHIFT))&I2S_TCR5_WNW_MASK) /*!< I2S0_TCR5                               */
/* ------- TDR Bit Fields                           ------ */
#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFU)                                       /*!< I2S0_TDR: TDR Mask                      */
#define I2S_TDR_TDR_SHIFT                        (0U)                                                /*!< I2S0_TDR: TDR Position                  */
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&I2S_TDR_TDR_MASK) /*!< I2S0_TDR                                */
/* ------- TFR Bit Fields                           ------ */
#define I2S_TFR_RFP_MASK                         (0xFU)                                              /*!< I2S0_TFR: RFP Mask                      */
#define I2S_TFR_RFP_SHIFT                        (0U)                                                /*!< I2S0_TFR: RFP Position                  */
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_RFP_SHIFT))&I2S_TFR_RFP_MASK) /*!< I2S0_TFR                                */
#define I2S_TFR_WFP_MASK                         (0xF0000U)                                          /*!< I2S0_TFR: WFP Mask                      */
#define I2S_TFR_WFP_SHIFT                        (16U)                                               /*!< I2S0_TFR: WFP Position                  */
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_WFP_SHIFT))&I2S_TFR_WFP_MASK) /*!< I2S0_TFR                                */
/* ------- TMR Bit Fields                           ------ */
#define I2S_TMR_TWM_MASK                         (0xFFFFU)                                           /*!< I2S0_TMR: TWM Mask                      */
#define I2S_TMR_TWM_SHIFT                        (0U)                                                /*!< I2S0_TMR: TWM Position                  */
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TMR_TWM_SHIFT))&I2S_TMR_TWM_MASK) /*!< I2S0_TMR                                */
/* ------- RCSR Bit Fields                          ------ */
#define I2S_RCSR_FRDE_MASK                       (0x1U)                                              /*!< I2S0_RCSR: FRDE Mask                    */
#define I2S_RCSR_FRDE_SHIFT                      (0U)                                                /*!< I2S0_RCSR: FRDE Position                */
#define I2S_RCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRDE_SHIFT))&I2S_RCSR_FRDE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWDE_MASK                       (0x2U)                                              /*!< I2S0_RCSR: FWDE Mask                    */
#define I2S_RCSR_FWDE_SHIFT                      (1U)                                                /*!< I2S0_RCSR: FWDE Position                */
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWDE_SHIFT))&I2S_RCSR_FWDE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FRIE_MASK                       (0x100U)                                            /*!< I2S0_RCSR: FRIE Mask                    */
#define I2S_RCSR_FRIE_SHIFT                      (8U)                                                /*!< I2S0_RCSR: FRIE Position                */
#define I2S_RCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRIE_SHIFT))&I2S_RCSR_FRIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWIE_MASK                       (0x200U)                                            /*!< I2S0_RCSR: FWIE Mask                    */
#define I2S_RCSR_FWIE_SHIFT                      (9U)                                                /*!< I2S0_RCSR: FWIE Position                */
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWIE_SHIFT))&I2S_RCSR_FWIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FEIE_MASK                       (0x400U)                                            /*!< I2S0_RCSR: FEIE Mask                    */
#define I2S_RCSR_FEIE_SHIFT                      (10U)                                               /*!< I2S0_RCSR: FEIE Position                */
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEIE_SHIFT))&I2S_RCSR_FEIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SEIE_MASK                       (0x800U)                                            /*!< I2S0_RCSR: SEIE Mask                    */
#define I2S_RCSR_SEIE_SHIFT                      (11U)                                               /*!< I2S0_RCSR: SEIE Position                */
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEIE_SHIFT))&I2S_RCSR_SEIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_WSIE_MASK                       (0x1000U)                                           /*!< I2S0_RCSR: WSIE Mask                    */
#define I2S_RCSR_WSIE_SHIFT                      (12U)                                               /*!< I2S0_RCSR: WSIE Position                */
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSIE_SHIFT))&I2S_RCSR_WSIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FRF_MASK                        (0x10000U)                                          /*!< I2S0_RCSR: FRF Mask                     */
#define I2S_RCSR_FRF_SHIFT                       (16U)                                               /*!< I2S0_RCSR: FRF Position                 */
#define I2S_RCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRF_SHIFT))&I2S_RCSR_FRF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWF_MASK                        (0x20000U)                                          /*!< I2S0_RCSR: FWF Mask                     */
#define I2S_RCSR_FWF_SHIFT                       (17U)                                               /*!< I2S0_RCSR: FWF Position                 */
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWF_SHIFT))&I2S_RCSR_FWF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FEF_MASK                        (0x40000U)                                          /*!< I2S0_RCSR: FEF Mask                     */
#define I2S_RCSR_FEF_SHIFT                       (18U)                                               /*!< I2S0_RCSR: FEF Position                 */
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEF_SHIFT))&I2S_RCSR_FEF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SEF_MASK                        (0x80000U)                                          /*!< I2S0_RCSR: SEF Mask                     */
#define I2S_RCSR_SEF_SHIFT                       (19U)                                               /*!< I2S0_RCSR: SEF Position                 */
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEF_SHIFT))&I2S_RCSR_SEF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_WSF_MASK                        (0x100000U)                                         /*!< I2S0_RCSR: WSF Mask                     */
#define I2S_RCSR_WSF_SHIFT                       (20U)                                               /*!< I2S0_RCSR: WSF Position                 */
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSF_SHIFT))&I2S_RCSR_WSF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SR_MASK                         (0x1000000U)                                        /*!< I2S0_RCSR: SR Mask                      */
#define I2S_RCSR_SR_SHIFT                        (24U)                                               /*!< I2S0_RCSR: SR Position                  */
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SR_SHIFT))&I2S_RCSR_SR_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FR_MASK                         (0x2000000U)                                        /*!< I2S0_RCSR: FR Mask                      */
#define I2S_RCSR_FR_SHIFT                        (25U)                                               /*!< I2S0_RCSR: FR Position                  */
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FR_SHIFT))&I2S_RCSR_FR_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_BCE_MASK                        (0x10000000U)                                       /*!< I2S0_RCSR: BCE Mask                     */
#define I2S_RCSR_BCE_SHIFT                       (28U)                                               /*!< I2S0_RCSR: BCE Position                 */
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_BCE_SHIFT))&I2S_RCSR_BCE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_DBGE_MASK                       (0x20000000U)                                       /*!< I2S0_RCSR: DBGE Mask                    */
#define I2S_RCSR_DBGE_SHIFT                      (29U)                                               /*!< I2S0_RCSR: DBGE Position                */
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_DBGE_SHIFT))&I2S_RCSR_DBGE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_STOPE_MASK                      (0x40000000U)                                       /*!< I2S0_RCSR: STOPE Mask                   */
#define I2S_RCSR_STOPE_SHIFT                     (30U)                                               /*!< I2S0_RCSR: STOPE Position               */
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_STOPE_SHIFT))&I2S_RCSR_STOPE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_RE_MASK                         (0x80000000U)                                       /*!< I2S0_RCSR: RE Mask                      */
#define I2S_RCSR_RE_SHIFT                        (31U)                                               /*!< I2S0_RCSR: RE Position                  */
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_RE_SHIFT))&I2S_RCSR_RE_MASK) /*!< I2S0_RCSR                               */
/* ------- RCR1 Bit Fields                          ------ */
#define I2S_RCR1_RFW_MASK                        (0x7U)                                              /*!< I2S0_RCR1: RFW Mask                     */
#define I2S_RCR1_RFW_SHIFT                       (0U)                                                /*!< I2S0_RCR1: RFW Position                 */
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR1_RFW_SHIFT))&I2S_RCR1_RFW_MASK) /*!< I2S0_RCR1                               */
/* ------- RCR2 Bit Fields                          ------ */
#define I2S_RCR2_DIV_MASK                        (0xFFU)                                             /*!< I2S0_RCR2: DIV Mask                     */
#define I2S_RCR2_DIV_SHIFT                       (0U)                                                /*!< I2S0_RCR2: DIV Position                 */
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_DIV_SHIFT))&I2S_RCR2_DIV_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCD_MASK                        (0x1000000U)                                        /*!< I2S0_RCR2: BCD Mask                     */
#define I2S_RCR2_BCD_SHIFT                       (24U)                                               /*!< I2S0_RCR2: BCD Position                 */
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCD_SHIFT))&I2S_RCR2_BCD_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCP_MASK                        (0x2000000U)                                        /*!< I2S0_RCR2: BCP Mask                     */
#define I2S_RCR2_BCP_SHIFT                       (25U)                                               /*!< I2S0_RCR2: BCP Position                 */
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCP_SHIFT))&I2S_RCR2_BCP_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_MSEL_MASK                       (0xC000000U)                                        /*!< I2S0_RCR2: MSEL Mask                    */
#define I2S_RCR2_MSEL_SHIFT                      (26U)                                               /*!< I2S0_RCR2: MSEL Position                */
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_MSEL_SHIFT))&I2S_RCR2_MSEL_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCI_MASK                        (0x10000000U)                                       /*!< I2S0_RCR2: BCI Mask                     */
#define I2S_RCR2_BCI_SHIFT                       (28U)                                               /*!< I2S0_RCR2: BCI Position                 */
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCI_SHIFT))&I2S_RCR2_BCI_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCS_MASK                        (0x20000000U)                                       /*!< I2S0_RCR2: BCS Mask                     */
#define I2S_RCR2_BCS_SHIFT                       (29U)                                               /*!< I2S0_RCR2: BCS Position                 */
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCS_SHIFT))&I2S_RCR2_BCS_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_SYNC_MASK                       (0xC0000000U)                                       /*!< I2S0_RCR2: SYNC Mask                    */
#define I2S_RCR2_SYNC_SHIFT                      (30U)                                               /*!< I2S0_RCR2: SYNC Position                */
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_SYNC_SHIFT))&I2S_RCR2_SYNC_MASK) /*!< I2S0_RCR2                               */
/* ------- RCR3 Bit Fields                          ------ */
#define I2S_RCR3_WDFL_MASK                       (0xFU)                                              /*!< I2S0_RCR3: WDFL Mask                    */
#define I2S_RCR3_WDFL_SHIFT                      (0U)                                                /*!< I2S0_RCR3: WDFL Position                */
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_WDFL_SHIFT))&I2S_RCR3_WDFL_MASK) /*!< I2S0_RCR3                               */
#define I2S_RCR3_RCE_MASK                        (0x10000U)                                          /*!< I2S0_RCR3: RCE Mask                     */
#define I2S_RCR3_RCE_SHIFT                       (16U)                                               /*!< I2S0_RCR3: RCE Position                 */
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_RCE_SHIFT))&I2S_RCR3_RCE_MASK) /*!< I2S0_RCR3                               */
/* ------- RCR4 Bit Fields                          ------ */
#define I2S_RCR4_FSD_MASK                        (0x1U)                                              /*!< I2S0_RCR4: FSD Mask                     */
#define I2S_RCR4_FSD_SHIFT                       (0U)                                                /*!< I2S0_RCR4: FSD Position                 */
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSD_SHIFT))&I2S_RCR4_FSD_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FSP_MASK                        (0x2U)                                              /*!< I2S0_RCR4: FSP Mask                     */
#define I2S_RCR4_FSP_SHIFT                       (1U)                                                /*!< I2S0_RCR4: FSP Position                 */
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSP_SHIFT))&I2S_RCR4_FSP_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FSE_MASK                        (0x8U)                                              /*!< I2S0_RCR4: FSE Mask                     */
#define I2S_RCR4_FSE_SHIFT                       (3U)                                                /*!< I2S0_RCR4: FSE Position                 */
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSE_SHIFT))&I2S_RCR4_FSE_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_MF_MASK                         (0x10U)                                             /*!< I2S0_RCR4: MF Mask                      */
#define I2S_RCR4_MF_SHIFT                        (4U)                                                /*!< I2S0_RCR4: MF Position                  */
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_MF_SHIFT))&I2S_RCR4_MF_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_SYWD_MASK                       (0x1F00U)                                           /*!< I2S0_RCR4: SYWD Mask                    */
#define I2S_RCR4_SYWD_SHIFT                      (8U)                                                /*!< I2S0_RCR4: SYWD Position                */
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_SYWD_SHIFT))&I2S_RCR4_SYWD_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FRSZ_MASK                       (0xF0000U)                                          /*!< I2S0_RCR4: FRSZ Mask                    */
#define I2S_RCR4_FRSZ_SHIFT                      (16U)                                               /*!< I2S0_RCR4: FRSZ Position                */
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FRSZ_SHIFT))&I2S_RCR4_FRSZ_MASK) /*!< I2S0_RCR4                               */
/* ------- RCR5 Bit Fields                          ------ */
#define I2S_RCR5_FBT_MASK                        (0x1F00U)                                           /*!< I2S0_RCR5: FBT Mask                     */
#define I2S_RCR5_FBT_SHIFT                       (8U)                                                /*!< I2S0_RCR5: FBT Position                 */
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_FBT_SHIFT))&I2S_RCR5_FBT_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_W0W_MASK                        (0x1F0000U)                                         /*!< I2S0_RCR5: W0W Mask                     */
#define I2S_RCR5_W0W_SHIFT                       (16U)                                               /*!< I2S0_RCR5: W0W Position                 */
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_W0W_SHIFT))&I2S_RCR5_W0W_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_WNW_MASK                        (0x1F000000U)                                       /*!< I2S0_RCR5: WNW Mask                     */
#define I2S_RCR5_WNW_SHIFT                       (24U)                                               /*!< I2S0_RCR5: WNW Position                 */
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_WNW_SHIFT))&I2S_RCR5_WNW_MASK) /*!< I2S0_RCR5                               */
/* ------- RDR Bit Fields                           ------ */
#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFU)                                       /*!< I2S0_RDR: RDR Mask                      */
#define I2S_RDR_RDR_SHIFT                        (0U)                                                /*!< I2S0_RDR: RDR Position                  */
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RDR_RDR_SHIFT))&I2S_RDR_RDR_MASK) /*!< I2S0_RDR                                */
/* ------- RFR Bit Fields                           ------ */
#define I2S_RFR_RFP_MASK                         (0xFU)                                              /*!< I2S0_RFR: RFP Mask                      */
#define I2S_RFR_RFP_SHIFT                        (0U)                                                /*!< I2S0_RFR: RFP Position                  */
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_RFP_SHIFT))&I2S_RFR_RFP_MASK) /*!< I2S0_RFR                                */
#define I2S_RFR_WFP_MASK                         (0xF0000U)                                          /*!< I2S0_RFR: WFP Mask                      */
#define I2S_RFR_WFP_SHIFT                        (16U)                                               /*!< I2S0_RFR: WFP Position                  */
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_WFP_SHIFT))&I2S_RFR_WFP_MASK) /*!< I2S0_RFR                                */
/* ------- RMR Bit Fields                           ------ */
#define I2S_RMR_RWM_MASK                         (0xFFFFU)                                           /*!< I2S0_RMR: RWM Mask                      */
#define I2S_RMR_RWM_SHIFT                        (0U)                                                /*!< I2S0_RMR: RWM Position                  */
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RMR_RWM_SHIFT))&I2S_RMR_RWM_MASK) /*!< I2S0_RMR                                */
/* ------- MCR Bit Fields                           ------ */
#define I2S_MCR_MICS_MASK                        (0x3000000U)                                        /*!< I2S0_MCR: MICS Mask                     */
#define I2S_MCR_MICS_SHIFT                       (24U)                                               /*!< I2S0_MCR: MICS Position                 */
#define I2S_MCR_MICS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MICS_SHIFT))&I2S_MCR_MICS_MASK) /*!< I2S0_MCR                                */
#define I2S_MCR_MOE_MASK                         (0x40000000U)                                       /*!< I2S0_MCR: MOE Mask                      */
#define I2S_MCR_MOE_SHIFT                        (30U)                                               /*!< I2S0_MCR: MOE Position                  */
#define I2S_MCR_MOE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MOE_SHIFT))&I2S_MCR_MOE_MASK) /*!< I2S0_MCR                                */
#define I2S_MCR_DUF_MASK                         (0x80000000U)                                       /*!< I2S0_MCR: DUF Mask                      */
#define I2S_MCR_DUF_SHIFT                        (31U)                                               /*!< I2S0_MCR: DUF Position                  */
#define I2S_MCR_DUF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_MCR_DUF_SHIFT))&I2S_MCR_DUF_MASK) /*!< I2S0_MCR                                */
/* ------- MDR Bit Fields                           ------ */
#define I2S_MDR_DIVIDE_MASK                      (0xFFFU)                                            /*!< I2S0_MDR: DIVIDE Mask                   */
#define I2S_MDR_DIVIDE_SHIFT                     (0U)                                                /*!< I2S0_MDR: DIVIDE Position               */
#define I2S_MDR_DIVIDE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_MDR_DIVIDE_SHIFT))&I2S_MDR_DIVIDE_MASK) /*!< I2S0_MDR                                */
#define I2S_MDR_FRACT_MASK                       (0xFF000U)                                          /*!< I2S0_MDR: FRACT Mask                    */
#define I2S_MDR_FRACT_SHIFT                      (12U)                                               /*!< I2S0_MDR: FRACT Position                */
#define I2S_MDR_FRACT(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_MDR_FRACT_SHIFT))&I2S_MDR_FRACT_MASK) /*!< I2S0_MDR                                */
/**
 * @} */ /* End group I2S_Register_Masks_GROUP 
 */

/* I2S0 - Peripheral instance base addresses */
#define I2S0_BasePtr                   0x4002F000UL //!< Peripheral base address
#define I2S0                           ((I2S_Type *) I2S0_BasePtr) //!< Freescale base pointer
#define I2S0_BASE_PTR                  (I2S0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2S_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer
* @brief C Struct for LLWU
* @{
*/

/* ================================================================================ */
/* ================           LLWU (file:LLWU_PE3_FILT2_RST)       ================ */
/* ================================================================================ */

/**
 * @brief Low leakage wakeup unit
 */
/**
* @addtogroup LLWU_structs_GROUP LLWU struct
* @brief Struct for LLWU
* @{
*/
typedef struct {                                /*       LLWU Structure                                               */
   __IO uint8_t   PE1;                          /**< 0000: Pin Enable 1 Register                                        */
   __IO uint8_t   PE2;                          /**< 0001: Pin Enable 2 Register                                        */
   __IO uint8_t   PE3;                          /**< 0002: Pin Enable 3 Register                                        */
   __IO uint8_t   PE4;                          /**< 0003: Pin Enable 4 Register                                        */
   __IO uint8_t   ME;                           /**< 0004: Module Enable Register                                       */
   __IO uint8_t   F1;                           /**< 0005: Flag 1 Register                                              */
   __IO uint8_t   F2;                           /**< 0006: Flag 2 Register                                              */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   F3;                        /**< 0007: Flag 3 Register                                              */
      __I  uint8_t   MF0;                       /**< 0007: Module Flag 0 Register                                       */
   };
   __IO uint8_t   FILT1;                        /**< 0008: Pin Filter 1 register                                        */
   __IO uint8_t   FILT2;                        /**< 0009: Pin Filter 2 register                                        */
   __IO uint8_t   RST;                          /**< 000A: Reset Enable Register                                        */
} LLWU_Type;

/**
 * @} */ /* End group LLWU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LLWU_Register_Masks_GROUP LLWU Register Masks
* @brief Register Masks for LLWU
* @{
*/
/* ------- PE1 Bit Fields                           ------ */
#define LLWU_PE1_WUPE0_MASK                      (0x3U)                                              /*!< LLWU_PE1: WUPE0 Mask                    */
#define LLWU_PE1_WUPE0_SHIFT                     (0U)                                                /*!< LLWU_PE1: WUPE0 Position                */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE1_MASK                      (0xCU)                                              /*!< LLWU_PE1: WUPE1 Mask                    */
#define LLWU_PE1_WUPE1_SHIFT                     (2U)                                                /*!< LLWU_PE1: WUPE1 Position                */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE2_MASK                      (0x30U)                                             /*!< LLWU_PE1: WUPE2 Mask                    */
#define LLWU_PE1_WUPE2_SHIFT                     (4U)                                                /*!< LLWU_PE1: WUPE2 Position                */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE3_MASK                      (0xC0U)                                             /*!< LLWU_PE1: WUPE3 Mask                    */
#define LLWU_PE1_WUPE3_SHIFT                     (6U)                                                /*!< LLWU_PE1: WUPE3 Position                */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK) /*!< LLWU_PE1                                */
/* ------- PE2 Bit Fields                           ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x3U)                                              /*!< LLWU_PE2: WUPE4 Mask                    */
#define LLWU_PE2_WUPE4_SHIFT                     (0U)                                                /*!< LLWU_PE2: WUPE4 Position                */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE5_MASK                      (0xCU)                                              /*!< LLWU_PE2: WUPE5 Mask                    */
#define LLWU_PE2_WUPE5_SHIFT                     (2U)                                                /*!< LLWU_PE2: WUPE5 Position                */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE6_MASK                      (0x30U)                                             /*!< LLWU_PE2: WUPE6 Mask                    */
#define LLWU_PE2_WUPE6_SHIFT                     (4U)                                                /*!< LLWU_PE2: WUPE6 Position                */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE7_MASK                      (0xC0U)                                             /*!< LLWU_PE2: WUPE7 Mask                    */
#define LLWU_PE2_WUPE7_SHIFT                     (6U)                                                /*!< LLWU_PE2: WUPE7 Position                */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK) /*!< LLWU_PE2                                */
/* ------- PE3 Bit Fields                           ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x3U)                                              /*!< LLWU_PE3: WUPE8 Mask                    */
#define LLWU_PE3_WUPE8_SHIFT                     (0U)                                                /*!< LLWU_PE3: WUPE8 Position                */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE9_MASK                      (0xCU)                                              /*!< LLWU_PE3: WUPE9 Mask                    */
#define LLWU_PE3_WUPE9_SHIFT                     (2U)                                                /*!< LLWU_PE3: WUPE9 Position                */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE10_MASK                     (0x30U)                                             /*!< LLWU_PE3: WUPE10 Mask                   */
#define LLWU_PE3_WUPE10_SHIFT                    (4U)                                                /*!< LLWU_PE3: WUPE10 Position               */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE11_MASK                     (0xC0U)                                             /*!< LLWU_PE3: WUPE11 Mask                   */
#define LLWU_PE3_WUPE11_SHIFT                    (6U)                                                /*!< LLWU_PE3: WUPE11 Position               */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK) /*!< LLWU_PE3                                */
/* ------- PE4 Bit Fields                           ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x3U)                                              /*!< LLWU_PE4: WUPE12 Mask                   */
#define LLWU_PE4_WUPE12_SHIFT                    (0U)                                                /*!< LLWU_PE4: WUPE12 Position               */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE13_MASK                     (0xCU)                                              /*!< LLWU_PE4: WUPE13 Mask                   */
#define LLWU_PE4_WUPE13_SHIFT                    (2U)                                                /*!< LLWU_PE4: WUPE13 Position               */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE14_MASK                     (0x30U)                                             /*!< LLWU_PE4: WUPE14 Mask                   */
#define LLWU_PE4_WUPE14_SHIFT                    (4U)                                                /*!< LLWU_PE4: WUPE14 Position               */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE15_MASK                     (0xC0U)                                             /*!< LLWU_PE4: WUPE15 Mask                   */
#define LLWU_PE4_WUPE15_SHIFT                    (6U)                                                /*!< LLWU_PE4: WUPE15 Position               */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK) /*!< LLWU_PE4                                */
/* ------- ME Bit Fields                            ------ */
#define LLWU_ME_WUME0_MASK                       (0x1U)                                              /*!< LLWU_ME: WUME0 Mask                     */
#define LLWU_ME_WUME0_SHIFT                      (0U)                                                /*!< LLWU_ME: WUME0 Position                 */
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME0_SHIFT))&LLWU_ME_WUME0_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME1_MASK                       (0x2U)                                              /*!< LLWU_ME: WUME1 Mask                     */
#define LLWU_ME_WUME1_SHIFT                      (1U)                                                /*!< LLWU_ME: WUME1 Position                 */
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME1_SHIFT))&LLWU_ME_WUME1_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME2_MASK                       (0x4U)                                              /*!< LLWU_ME: WUME2 Mask                     */
#define LLWU_ME_WUME2_SHIFT                      (2U)                                                /*!< LLWU_ME: WUME2 Position                 */
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME2_SHIFT))&LLWU_ME_WUME2_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME3_MASK                       (0x8U)                                              /*!< LLWU_ME: WUME3 Mask                     */
#define LLWU_ME_WUME3_SHIFT                      (3U)                                                /*!< LLWU_ME: WUME3 Position                 */
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME3_SHIFT))&LLWU_ME_WUME3_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME4_MASK                       (0x10U)                                             /*!< LLWU_ME: WUME4 Mask                     */
#define LLWU_ME_WUME4_SHIFT                      (4U)                                                /*!< LLWU_ME: WUME4 Position                 */
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME4_SHIFT))&LLWU_ME_WUME4_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME5_MASK                       (0x20U)                                             /*!< LLWU_ME: WUME5 Mask                     */
#define LLWU_ME_WUME5_SHIFT                      (5U)                                                /*!< LLWU_ME: WUME5 Position                 */
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME5_SHIFT))&LLWU_ME_WUME5_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME6_MASK                       (0x40U)                                             /*!< LLWU_ME: WUME6 Mask                     */
#define LLWU_ME_WUME6_SHIFT                      (6U)                                                /*!< LLWU_ME: WUME6 Position                 */
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME6_SHIFT))&LLWU_ME_WUME6_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME7_MASK                       (0x80U)                                             /*!< LLWU_ME: WUME7 Mask                     */
#define LLWU_ME_WUME7_SHIFT                      (7U)                                                /*!< LLWU_ME: WUME7 Position                 */
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME7_SHIFT))&LLWU_ME_WUME7_MASK) /*!< LLWU_ME                                 */
/* ------- F1 Bit Fields                            ------ */
#define LLWU_F1_WUF0_MASK                        (0x1U)                                              /*!< LLWU_F1: WUF0 Mask                      */
#define LLWU_F1_WUF0_SHIFT                       (0U)                                                /*!< LLWU_F1: WUF0 Position                  */
#define LLWU_F1_WUF0(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF0_SHIFT))&LLWU_F1_WUF0_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF1_MASK                        (0x2U)                                              /*!< LLWU_F1: WUF1 Mask                      */
#define LLWU_F1_WUF1_SHIFT                       (1U)                                                /*!< LLWU_F1: WUF1 Position                  */
#define LLWU_F1_WUF1(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF1_SHIFT))&LLWU_F1_WUF1_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF2_MASK                        (0x4U)                                              /*!< LLWU_F1: WUF2 Mask                      */
#define LLWU_F1_WUF2_SHIFT                       (2U)                                                /*!< LLWU_F1: WUF2 Position                  */
#define LLWU_F1_WUF2(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF2_SHIFT))&LLWU_F1_WUF2_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF3_MASK                        (0x8U)                                              /*!< LLWU_F1: WUF3 Mask                      */
#define LLWU_F1_WUF3_SHIFT                       (3U)                                                /*!< LLWU_F1: WUF3 Position                  */
#define LLWU_F1_WUF3(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF3_SHIFT))&LLWU_F1_WUF3_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF4_MASK                        (0x10U)                                             /*!< LLWU_F1: WUF4 Mask                      */
#define LLWU_F1_WUF4_SHIFT                       (4U)                                                /*!< LLWU_F1: WUF4 Position                  */
#define LLWU_F1_WUF4(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF4_SHIFT))&LLWU_F1_WUF4_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF5_MASK                        (0x20U)                                             /*!< LLWU_F1: WUF5 Mask                      */
#define LLWU_F1_WUF5_SHIFT                       (5U)                                                /*!< LLWU_F1: WUF5 Position                  */
#define LLWU_F1_WUF5(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF5_SHIFT))&LLWU_F1_WUF5_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF6_MASK                        (0x40U)                                             /*!< LLWU_F1: WUF6 Mask                      */
#define LLWU_F1_WUF6_SHIFT                       (6U)                                                /*!< LLWU_F1: WUF6 Position                  */
#define LLWU_F1_WUF6(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF6_SHIFT))&LLWU_F1_WUF6_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF7_MASK                        (0x80U)                                             /*!< LLWU_F1: WUF7 Mask                      */
#define LLWU_F1_WUF7_SHIFT                       (7U)                                                /*!< LLWU_F1: WUF7 Position                  */
#define LLWU_F1_WUF7(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF7_SHIFT))&LLWU_F1_WUF7_MASK) /*!< LLWU_F1                                 */
/* ------- F2 Bit Fields                            ------ */
#define LLWU_F2_WUF8_MASK                        (0x1U)                                              /*!< LLWU_F2: WUF8 Mask                      */
#define LLWU_F2_WUF8_SHIFT                       (0U)                                                /*!< LLWU_F2: WUF8 Position                  */
#define LLWU_F2_WUF8(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF8_SHIFT))&LLWU_F2_WUF8_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF9_MASK                        (0x2U)                                              /*!< LLWU_F2: WUF9 Mask                      */
#define LLWU_F2_WUF9_SHIFT                       (1U)                                                /*!< LLWU_F2: WUF9 Position                  */
#define LLWU_F2_WUF9(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF9_SHIFT))&LLWU_F2_WUF9_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF10_MASK                       (0x4U)                                              /*!< LLWU_F2: WUF10 Mask                     */
#define LLWU_F2_WUF10_SHIFT                      (2U)                                                /*!< LLWU_F2: WUF10 Position                 */
#define LLWU_F2_WUF10(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF10_SHIFT))&LLWU_F2_WUF10_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF11_MASK                       (0x8U)                                              /*!< LLWU_F2: WUF11 Mask                     */
#define LLWU_F2_WUF11_SHIFT                      (3U)                                                /*!< LLWU_F2: WUF11 Position                 */
#define LLWU_F2_WUF11(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF11_SHIFT))&LLWU_F2_WUF11_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF12_MASK                       (0x10U)                                             /*!< LLWU_F2: WUF12 Mask                     */
#define LLWU_F2_WUF12_SHIFT                      (4U)                                                /*!< LLWU_F2: WUF12 Position                 */
#define LLWU_F2_WUF12(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF12_SHIFT))&LLWU_F2_WUF12_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF13_MASK                       (0x20U)                                             /*!< LLWU_F2: WUF13 Mask                     */
#define LLWU_F2_WUF13_SHIFT                      (5U)                                                /*!< LLWU_F2: WUF13 Position                 */
#define LLWU_F2_WUF13(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF13_SHIFT))&LLWU_F2_WUF13_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF14_MASK                       (0x40U)                                             /*!< LLWU_F2: WUF14 Mask                     */
#define LLWU_F2_WUF14_SHIFT                      (6U)                                                /*!< LLWU_F2: WUF14 Position                 */
#define LLWU_F2_WUF14(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF14_SHIFT))&LLWU_F2_WUF14_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF15_MASK                       (0x80U)                                             /*!< LLWU_F2: WUF15 Mask                     */
#define LLWU_F2_WUF15_SHIFT                      (7U)                                                /*!< LLWU_F2: WUF15 Position                 */
#define LLWU_F2_WUF15(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF15_SHIFT))&LLWU_F2_WUF15_MASK) /*!< LLWU_F2                                 */
/* ------- F3 Bit Fields                            ------ */
#define LLWU_F3_MWUF0_MASK                       (0x1U)                                              /*!< LLWU_F3: MWUF0 Mask                     */
#define LLWU_F3_MWUF0_SHIFT                      (0U)                                                /*!< LLWU_F3: MWUF0 Position                 */
#define LLWU_F3_MWUF0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF0_SHIFT))&LLWU_F3_MWUF0_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF1_MASK                       (0x2U)                                              /*!< LLWU_F3: MWUF1 Mask                     */
#define LLWU_F3_MWUF1_SHIFT                      (1U)                                                /*!< LLWU_F3: MWUF1 Position                 */
#define LLWU_F3_MWUF1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF1_SHIFT))&LLWU_F3_MWUF1_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF2_MASK                       (0x4U)                                              /*!< LLWU_F3: MWUF2 Mask                     */
#define LLWU_F3_MWUF2_SHIFT                      (2U)                                                /*!< LLWU_F3: MWUF2 Position                 */
#define LLWU_F3_MWUF2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF2_SHIFT))&LLWU_F3_MWUF2_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF3_MASK                       (0x8U)                                              /*!< LLWU_F3: MWUF3 Mask                     */
#define LLWU_F3_MWUF3_SHIFT                      (3U)                                                /*!< LLWU_F3: MWUF3 Position                 */
#define LLWU_F3_MWUF3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF3_SHIFT))&LLWU_F3_MWUF3_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF4_MASK                       (0x10U)                                             /*!< LLWU_F3: MWUF4 Mask                     */
#define LLWU_F3_MWUF4_SHIFT                      (4U)                                                /*!< LLWU_F3: MWUF4 Position                 */
#define LLWU_F3_MWUF4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF4_SHIFT))&LLWU_F3_MWUF4_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF5_MASK                       (0x20U)                                             /*!< LLWU_F3: MWUF5 Mask                     */
#define LLWU_F3_MWUF5_SHIFT                      (5U)                                                /*!< LLWU_F3: MWUF5 Position                 */
#define LLWU_F3_MWUF5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF5_SHIFT))&LLWU_F3_MWUF5_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF6_MASK                       (0x40U)                                             /*!< LLWU_F3: MWUF6 Mask                     */
#define LLWU_F3_MWUF6_SHIFT                      (6U)                                                /*!< LLWU_F3: MWUF6 Position                 */
#define LLWU_F3_MWUF6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF6_SHIFT))&LLWU_F3_MWUF6_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF7_MASK                       (0x80U)                                             /*!< LLWU_F3: MWUF7 Mask                     */
#define LLWU_F3_MWUF7_SHIFT                      (7U)                                                /*!< LLWU_F3: MWUF7 Position                 */
#define LLWU_F3_MWUF7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF7_SHIFT))&LLWU_F3_MWUF7_MASK) /*!< LLWU_F3                                 */
/* ------- MF0 Bit Fields                           ------ */
/* ------- FILT Bit Fields                          ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0xFU)                                              /*!< LLWU_FILT: FILTSEL Mask                 */
#define LLWU_FILT_FILTSEL_SHIFT                  (0U)                                                /*!< LLWU_FILT: FILTSEL Position             */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTSEL_SHIFT))&LLWU_FILT_FILTSEL_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTE_MASK                     (0x60U)                                             /*!< LLWU_FILT: FILTE Mask                   */
#define LLWU_FILT_FILTE_SHIFT                    (5U)                                                /*!< LLWU_FILT: FILTE Position               */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTE_SHIFT))&LLWU_FILT_FILTE_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTF_MASK                     (0x80U)                                             /*!< LLWU_FILT: FILTF Mask                   */
#define LLWU_FILT_FILTF_SHIFT                    (7U)                                                /*!< LLWU_FILT: FILTF Position               */
#define LLWU_FILT_FILTF(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTF_SHIFT))&LLWU_FILT_FILTF_MASK) /*!< LLWU_FILT                               */
/* ------- RST Bit Fields                           ------ */
#define LLWU_RST_RSTFILT_MASK                    (0x1U)                                              /*!< LLWU_RST: RSTFILT Mask                  */
#define LLWU_RST_RSTFILT_SHIFT                   (0U)                                                /*!< LLWU_RST: RSTFILT Position              */
#define LLWU_RST_RSTFILT(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_RST_RSTFILT_SHIFT))&LLWU_RST_RSTFILT_MASK) /*!< LLWU_RST                                */
#define LLWU_RST_LLRSTE_MASK                     (0x2U)                                              /*!< LLWU_RST: LLRSTE Mask                   */
#define LLWU_RST_LLRSTE_SHIFT                    (1U)                                                /*!< LLWU_RST: LLRSTE Position               */
#define LLWU_RST_LLRSTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_RST_LLRSTE_SHIFT))&LLWU_RST_LLRSTE_MASK) /*!< LLWU_RST                                */
/**
 * @} */ /* End group LLWU_Register_Masks_GROUP 
 */

/* LLWU - Peripheral instance base addresses */
#define LLWU_BasePtr                   0x4007C000UL //!< Peripheral base address
#define LLWU                           ((LLWU_Type *) LLWU_BasePtr) //!< Freescale base pointer
#define LLWU_BASE_PTR                  (LLWU) //!< Freescale style base pointer
/**
 * @} */ /* End group LLWU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer
* @brief C Struct for LPTMR
* @{
*/

/* ================================================================================ */
/* ================           LPTMR0 (file:LPTMR0_0)               ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */
/**
* @addtogroup LPTMR_structs_GROUP LPTMR struct
* @brief Struct for LPTMR
* @{
*/
typedef struct {                                /*       LPTMR0 Structure                                             */
   __IO uint32_t  CSR;                          /**< 0000: Control Status Register                                      */
   __IO uint32_t  PSR;                          /**< 0004: Prescale Register                                            */
   __IO uint32_t  CMR;                          /**< 0008: Compare Register                                             */
   __IO uint32_t  CNR;                          /**< 000C: Counter Register                                             */
} LPTMR_Type;

/**
 * @} */ /* End group LPTMR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LPTMR_Register_Masks_GROUP LPTMR Register Masks
* @brief Register Masks for LPTMR
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define LPTMR_CSR_TEN_MASK                       (0x1U)                                              /*!< LPTMR0_CSR: TEN Mask                    */
#define LPTMR_CSR_TEN_SHIFT                      (0U)                                                /*!< LPTMR0_CSR: TEN Position                */
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TEN_SHIFT))&LPTMR_CSR_TEN_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TMS_MASK                       (0x2U)                                              /*!< LPTMR0_CSR: TMS Mask                    */
#define LPTMR_CSR_TMS_SHIFT                      (1U)                                                /*!< LPTMR0_CSR: TMS Position                */
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TMS_SHIFT))&LPTMR_CSR_TMS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TFC_MASK                       (0x4U)                                              /*!< LPTMR0_CSR: TFC Mask                    */
#define LPTMR_CSR_TFC_SHIFT                      (2U)                                                /*!< LPTMR0_CSR: TFC Position                */
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TFC_SHIFT))&LPTMR_CSR_TFC_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TPP_MASK                       (0x8U)                                              /*!< LPTMR0_CSR: TPP Mask                    */
#define LPTMR_CSR_TPP_SHIFT                      (3U)                                                /*!< LPTMR0_CSR: TPP Position                */
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPP_SHIFT))&LPTMR_CSR_TPP_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TPS_MASK                       (0x30U)                                             /*!< LPTMR0_CSR: TPS Mask                    */
#define LPTMR_CSR_TPS_SHIFT                      (4U)                                                /*!< LPTMR0_CSR: TPS Position                */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TIE_MASK                       (0x40U)                                             /*!< LPTMR0_CSR: TIE Mask                    */
#define LPTMR_CSR_TIE_SHIFT                      (6U)                                                /*!< LPTMR0_CSR: TIE Position                */
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TIE_SHIFT))&LPTMR_CSR_TIE_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TCF_MASK                       (0x80U)                                             /*!< LPTMR0_CSR: TCF Mask                    */
#define LPTMR_CSR_TCF_SHIFT                      (7U)                                                /*!< LPTMR0_CSR: TCF Position                */
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TCF_SHIFT))&LPTMR_CSR_TCF_MASK) /*!< LPTMR0_CSR                              */
/* ------- PSR Bit Fields                           ------ */
#define LPTMR_PSR_PCS_MASK                       (0x3U)                                              /*!< LPTMR0_PSR: PCS Mask                    */
#define LPTMR_PSR_PCS_SHIFT                      (0U)                                                /*!< LPTMR0_PSR: PCS Position                */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PBYP_MASK                      (0x4U)                                              /*!< LPTMR0_PSR: PBYP Mask                   */
#define LPTMR_PSR_PBYP_SHIFT                     (2U)                                                /*!< LPTMR0_PSR: PBYP Position               */
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PBYP_SHIFT))&LPTMR_PSR_PBYP_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PRESCALE_MASK                  (0x78U)                                             /*!< LPTMR0_PSR: PRESCALE Mask               */
#define LPTMR_PSR_PRESCALE_SHIFT                 (3U)                                                /*!< LPTMR0_PSR: PRESCALE Position           */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK) /*!< LPTMR0_PSR                              */
/* ------- CMR Bit Fields                           ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CMR: COMPARE Mask                */
#define LPTMR_CMR_COMPARE_SHIFT                  (0U)                                                /*!< LPTMR0_CMR: COMPARE Position            */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK) /*!< LPTMR0_CMR                              */
/* ------- CNR Bit Fields                           ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CNR: COUNTER Mask                */
#define LPTMR_CNR_COUNTER_SHIFT                  (0U)                                                /*!< LPTMR0_CNR: COUNTER Position            */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK) /*!< LPTMR0_CNR                              */
/**
 * @} */ /* End group LPTMR_Register_Masks_GROUP 
 */

/* LPTMR0 - Peripheral instance base addresses */
#define LPTMR0_BasePtr                 0x40040000UL //!< Peripheral base address
#define LPTMR0                         ((LPTMR_Type *) LPTMR0_BasePtr) //!< Freescale base pointer
#define LPTMR0_BASE_PTR                (LPTMR0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer
* @brief C Struct for MCG
* @{
*/

/* ================================================================================ */
/* ================           MCG (file:MCG_MK)                    ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator module
 */
/**
* @addtogroup MCG_structs_GROUP MCG struct
* @brief Struct for MCG
* @{
*/
typedef struct {                                /*       MCG Structure                                                */
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __IO uint8_t   C5;                           /**< 0004: Control 5 Register                                           */
   __IO uint8_t   C6;                           /**< 0005: Control 6 Register                                           */
   __IO uint8_t   S;                            /**< 0006: Status Register                                              */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   ATCVH;                        /**< 000A: ATM Compare Value High                                       */
   __IO uint8_t   ATCVL;                        /**< 000B: ATM Compare Value Low                                        */
   __IO uint8_t   C7;                           /**< 000C: Control 7 Register                                           */
   __IO uint8_t   C8;                           /**< 000D: Control 8 Register                                           */
} MCG_Type;

/**
 * @} */ /* End group MCG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCG_Register_Masks_GROUP MCG Register Masks
* @brief Register Masks for MCG
* @{
*/
/* ------- C1 Bit Fields                            ------ */
#define MCG_C1_IREFSTEN_MASK                     (0x1U)                                              /*!< MCG_C1: IREFSTEN Mask                   */
#define MCG_C1_IREFSTEN_SHIFT                    (0U)                                                /*!< MCG_C1: IREFSTEN Position               */
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFSTEN_SHIFT))&MCG_C1_IREFSTEN_MASK) /*!< MCG_C1                                  */
#define MCG_C1_IRCLKEN_MASK                      (0x2U)                                              /*!< MCG_C1: IRCLKEN Mask                    */
#define MCG_C1_IRCLKEN_SHIFT                     (1U)                                                /*!< MCG_C1: IRCLKEN Position                */
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C1_IRCLKEN_SHIFT))&MCG_C1_IRCLKEN_MASK) /*!< MCG_C1                                  */
#define MCG_C1_IREFS_MASK                        (0x4U)                                              /*!< MCG_C1: IREFS Mask                      */
#define MCG_C1_IREFS_SHIFT                       (2U)                                                /*!< MCG_C1: IREFS Position                  */
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFS_SHIFT))&MCG_C1_IREFS_MASK) /*!< MCG_C1                                  */
#define MCG_C1_FRDIV_MASK                        (0x38U)                                             /*!< MCG_C1: FRDIV Mask                      */
#define MCG_C1_FRDIV_SHIFT                       (3U)                                                /*!< MCG_C1: FRDIV Position                  */
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK) /*!< MCG_C1                                  */
#define MCG_C1_CLKS_MASK                         (0xC0U)                                             /*!< MCG_C1: CLKS Mask                       */
#define MCG_C1_CLKS_SHIFT                        (6U)                                                /*!< MCG_C1: CLKS Position                   */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK) /*!< MCG_C1                                  */
/* ------- C2 Bit Fields                            ------ */
#define MCG_C2_IRCS_MASK                         (0x1U)                                              /*!< MCG_C2: IRCS Mask                       */
#define MCG_C2_IRCS_SHIFT                        (0U)                                                /*!< MCG_C2: IRCS Position                   */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_IRCS_SHIFT))&MCG_C2_IRCS_MASK) /*!< MCG_C2                                  */
#define MCG_C2_LP_MASK                           (0x2U)                                              /*!< MCG_C2: LP Mask                         */
#define MCG_C2_LP_SHIFT                          (1U)                                                /*!< MCG_C2: LP Position                     */
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<MCG_C2_LP_SHIFT))&MCG_C2_LP_MASK) /*!< MCG_C2                                  */
#define MCG_C2_EREFS0_MASK                       (0x4U)                                              /*!< MCG_C2: EREFS0 Mask                     */
#define MCG_C2_EREFS0_SHIFT                      (2U)                                                /*!< MCG_C2: EREFS0 Position                 */
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_EREFS0_SHIFT))&MCG_C2_EREFS0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_HGO0_MASK                         (0x8U)                                              /*!< MCG_C2: HGO0 Mask                       */
#define MCG_C2_HGO0_SHIFT                        (3U)                                                /*!< MCG_C2: HGO0 Position                   */
#define MCG_C2_HGO0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_HGO0_SHIFT))&MCG_C2_HGO0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_RANGE0_MASK                       (0x30U)                                             /*!< MCG_C2: RANGE0 Mask                     */
#define MCG_C2_RANGE0_SHIFT                      (4U)                                                /*!< MCG_C2: RANGE0 Position                 */
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_LOCRE0_MASK                       (0x80U)                                             /*!< MCG_C2: LOCRE0 Mask                     */
#define MCG_C2_LOCRE0_SHIFT                      (7U)                                                /*!< MCG_C2: LOCRE0 Position                 */
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_LOCRE0_SHIFT))&MCG_C2_LOCRE0_MASK) /*!< MCG_C2                                  */
/* ------- C3 Bit Fields                            ------ */
#define MCG_C3_SCTRIM_MASK                       (0xFFU)                                             /*!< MCG_C3: SCTRIM Mask                     */
#define MCG_C3_SCTRIM_SHIFT                      (0U)                                                /*!< MCG_C3: SCTRIM Position                 */
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK) /*!< MCG_C3                                  */
/* ------- C4 Bit Fields                            ------ */
#define MCG_C4_SCFTRIM_MASK                      (0x1U)                                              /*!< MCG_C4: SCFTRIM Mask                    */
#define MCG_C4_SCFTRIM_SHIFT                     (0U)                                                /*!< MCG_C4: SCFTRIM Position                */
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C4_SCFTRIM_SHIFT))&MCG_C4_SCFTRIM_MASK) /*!< MCG_C4                                  */
#define MCG_C4_FCTRIM_MASK                       (0x1EU)                                             /*!< MCG_C4: FCTRIM Mask                     */
#define MCG_C4_FCTRIM_SHIFT                      (1U)                                                /*!< MCG_C4: FCTRIM Position                 */
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DRST_DRS_MASK                     (0x60U)                                             /*!< MCG_C4: DRST_DRS Mask                   */
#define MCG_C4_DRST_DRS_SHIFT                    (5U)                                                /*!< MCG_C4: DRST_DRS Position               */
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DMX32_MASK                        (0x80U)                                             /*!< MCG_C4: DMX32 Mask                      */
#define MCG_C4_DMX32_SHIFT                       (7U)                                                /*!< MCG_C4: DMX32 Position                  */
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C4_DMX32_SHIFT))&MCG_C4_DMX32_MASK) /*!< MCG_C4                                  */
/* ------- C5 Bit Fields                            ------ */
#define MCG_C5_PRDIV0_MASK                       (0x1FU)                                             /*!< MCG_C5: PRDIV0 Mask                     */
#define MCG_C5_PRDIV0_SHIFT                      (0U)                                                /*!< MCG_C5: PRDIV0 Position                 */
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV0_SHIFT))&MCG_C5_PRDIV0_MASK) /*!< MCG_C5                                  */
#define MCG_C5_PLLSTEN0_MASK                     (0x20U)                                             /*!< MCG_C5: PLLSTEN0 Mask                   */
#define MCG_C5_PLLSTEN0_SHIFT                    (5U)                                                /*!< MCG_C5: PLLSTEN0 Position               */
#define MCG_C5_PLLSTEN0(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLSTEN0_SHIFT))&MCG_C5_PLLSTEN0_MASK) /*!< MCG_C5                                  */
#define MCG_C5_PLLCLKEN0_MASK                    (0x40U)                                             /*!< MCG_C5: PLLCLKEN0 Mask                  */
#define MCG_C5_PLLCLKEN0_SHIFT                   (6U)                                                /*!< MCG_C5: PLLCLKEN0 Position              */
#define MCG_C5_PLLCLKEN0(x)                      (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLCLKEN0_SHIFT))&MCG_C5_PLLCLKEN0_MASK) /*!< MCG_C5                                  */
/* ------- C6 Bit Fields                            ------ */
#define MCG_C6_VDIV0_MASK                        (0x1FU)                                             /*!< MCG_C6: VDIV0 Mask                      */
#define MCG_C6_VDIV0_SHIFT                       (0U)                                                /*!< MCG_C6: VDIV0 Position                  */
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV0_SHIFT))&MCG_C6_VDIV0_MASK) /*!< MCG_C6                                  */
#define MCG_C6_CME0_MASK                         (0x20U)                                             /*!< MCG_C6: CME0 Mask                       */
#define MCG_C6_CME0_SHIFT                        (5U)                                                /*!< MCG_C6: CME0 Position                   */
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_CME0_SHIFT))&MCG_C6_CME0_MASK) /*!< MCG_C6                                  */
#define MCG_C6_PLLS_MASK                         (0x40U)                                             /*!< MCG_C6: PLLS Mask                       */
#define MCG_C6_PLLS_SHIFT                        (6U)                                                /*!< MCG_C6: PLLS Position                   */
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_PLLS_SHIFT))&MCG_C6_PLLS_MASK) /*!< MCG_C6                                  */
#define MCG_C6_LOLIE0_MASK                       (0x80U)                                             /*!< MCG_C6: LOLIE0 Mask                     */
#define MCG_C6_LOLIE0_SHIFT                      (7U)                                                /*!< MCG_C6: LOLIE0 Position                 */
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C6_LOLIE0_SHIFT))&MCG_C6_LOLIE0_MASK) /*!< MCG_C6                                  */
/* ------- S Bit Fields                             ------ */
#define MCG_S_IRCST_MASK                         (0x1U)                                              /*!< MCG_S: IRCST Mask                       */
#define MCG_S_IRCST_SHIFT                        (0U)                                                /*!< MCG_S: IRCST Position                   */
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_IRCST_SHIFT))&MCG_S_IRCST_MASK) /*!< MCG_S                                   */
#define MCG_S_OSCINIT0_MASK                      (0x2U)                                              /*!< MCG_S: OSCINIT0 Mask                    */
#define MCG_S_OSCINIT0_SHIFT                     (1U)                                                /*!< MCG_S: OSCINIT0 Position                */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_S_OSCINIT0_SHIFT))&MCG_S_OSCINIT0_MASK) /*!< MCG_S                                   */
#define MCG_S_CLKST_MASK                         (0xCU)                                              /*!< MCG_S: CLKST Mask                       */
#define MCG_S_CLKST_SHIFT                        (2U)                                                /*!< MCG_S: CLKST Position                   */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK) /*!< MCG_S                                   */
#define MCG_S_IREFST_MASK                        (0x10U)                                             /*!< MCG_S: IREFST Mask                      */
#define MCG_S_IREFST_SHIFT                       (4U)                                                /*!< MCG_S: IREFST Position                  */
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_S_IREFST_SHIFT))&MCG_S_IREFST_MASK) /*!< MCG_S                                   */
#define MCG_S_PLLST_MASK                         (0x20U)                                             /*!< MCG_S: PLLST Mask                       */
#define MCG_S_PLLST_SHIFT                        (5U)                                                /*!< MCG_S: PLLST Position                   */
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_PLLST_SHIFT))&MCG_S_PLLST_MASK) /*!< MCG_S                                   */
#define MCG_S_LOCK0_MASK                         (0x40U)                                             /*!< MCG_S: LOCK0 Mask                       */
#define MCG_S_LOCK0_SHIFT                        (6U)                                                /*!< MCG_S: LOCK0 Position                   */
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOCK0_SHIFT))&MCG_S_LOCK0_MASK) /*!< MCG_S                                   */
#define MCG_S_LOLS0_MASK                         (0x80U)                                             /*!< MCG_S: LOLS0 Mask                       */
#define MCG_S_LOLS0_SHIFT                        (7U)                                                /*!< MCG_S: LOLS0 Position                   */
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOLS0_SHIFT))&MCG_S_LOLS0_MASK) /*!< MCG_S                                   */
/* ------- SC Bit Fields                            ------ */
#define MCG_SC_LOCS0_MASK                        (0x1U)                                              /*!< MCG_SC: LOCS0 Mask                      */
#define MCG_SC_LOCS0_SHIFT                       (0U)                                                /*!< MCG_SC: LOCS0 Position                  */
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_SC_LOCS0_SHIFT))&MCG_SC_LOCS0_MASK) /*!< MCG_SC                                  */
#define MCG_SC_FCRDIV_MASK                       (0xEU)                                              /*!< MCG_SC: FCRDIV Mask                     */
#define MCG_SC_FCRDIV_SHIFT                      (1U)                                                /*!< MCG_SC: FCRDIV Position                 */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK) /*!< MCG_SC                                  */
#define MCG_SC_FLTPRSRV_MASK                     (0x10U)                                             /*!< MCG_SC: FLTPRSRV Mask                   */
#define MCG_SC_FLTPRSRV_SHIFT                    (4U)                                                /*!< MCG_SC: FLTPRSRV Position               */
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_SC_FLTPRSRV_SHIFT))&MCG_SC_FLTPRSRV_MASK) /*!< MCG_SC                                  */
#define MCG_SC_ATMF_MASK                         (0x20U)                                             /*!< MCG_SC: ATMF Mask                       */
#define MCG_SC_ATMF_SHIFT                        (5U)                                                /*!< MCG_SC: ATMF Position                   */
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMF_SHIFT))&MCG_SC_ATMF_MASK) /*!< MCG_SC                                  */
#define MCG_SC_ATMS_MASK                         (0x40U)                                             /*!< MCG_SC: ATMS Mask                       */
#define MCG_SC_ATMS_SHIFT                        (6U)                                                /*!< MCG_SC: ATMS Position                   */
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMS_SHIFT))&MCG_SC_ATMS_MASK) /*!< MCG_SC                                  */
#define MCG_SC_ATME_MASK                         (0x80U)                                             /*!< MCG_SC: ATME Mask                       */
#define MCG_SC_ATME_SHIFT                        (7U)                                                /*!< MCG_SC: ATME Position                   */
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATME_SHIFT))&MCG_SC_ATME_MASK) /*!< MCG_SC                                  */
/* ------- ATCVH Bit Fields                         ------ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFU)                                             /*!< MCG_ATCVH: ATCVH Mask                   */
#define MCG_ATCVH_ATCVH_SHIFT                    (0U)                                                /*!< MCG_ATCVH: ATCVH Position               */
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK) /*!< MCG_ATCVH                               */
/* ------- ATCVL Bit Fields                         ------ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFU)                                             /*!< MCG_ATCVL: ATCVL Mask                   */
#define MCG_ATCVL_ATCVL_SHIFT                    (0U)                                                /*!< MCG_ATCVL: ATCVL Position               */
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK) /*!< MCG_ATCVL                               */
/* ------- C7 Bit Fields                            ------ */
#define MCG_C7_OSCSEL_MASK                       (0x1U)                                              /*!< MCG_C7: OSCSEL Mask                     */
#define MCG_C7_OSCSEL_SHIFT                      (0U)                                                /*!< MCG_C7: OSCSEL Position                 */
#define MCG_C7_OSCSEL(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C7_OSCSEL_SHIFT))&MCG_C7_OSCSEL_MASK) /*!< MCG_C7                                  */
/* ------- C8 Bit Fields                            ------ */
#define MCG_C8_LOCS1_MASK                        (0x1U)                                              /*!< MCG_C8: LOCS1 Mask                      */
#define MCG_C8_LOCS1_SHIFT                       (0U)                                                /*!< MCG_C8: LOCS1 Position                  */
#define MCG_C8_LOCS1(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOCS1_SHIFT))&MCG_C8_LOCS1_MASK) /*!< MCG_C8                                  */
#define MCG_C8_CME1_MASK                         (0x20U)                                             /*!< MCG_C8: CME1 Mask                       */
#define MCG_C8_CME1_SHIFT                        (5U)                                                /*!< MCG_C8: CME1 Position                   */
#define MCG_C8_CME1(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C8_CME1_SHIFT))&MCG_C8_CME1_MASK) /*!< MCG_C8                                  */
#define MCG_C8_LOLRE_MASK                        (0x40U)                                             /*!< MCG_C8: LOLRE Mask                      */
#define MCG_C8_LOLRE_SHIFT                       (6U)                                                /*!< MCG_C8: LOLRE Position                  */
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOLRE_SHIFT))&MCG_C8_LOLRE_MASK) /*!< MCG_C8                                  */
#define MCG_C8_LOCRE1_MASK                       (0x80U)                                             /*!< MCG_C8: LOCRE1 Mask                     */
#define MCG_C8_LOCRE1_SHIFT                      (7U)                                                /*!< MCG_C8: LOCRE1 Position                 */
#define MCG_C8_LOCRE1(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOCRE1_SHIFT))&MCG_C8_LOCRE1_MASK) /*!< MCG_C8                                  */
/**
 * @} */ /* End group MCG_Register_Masks_GROUP 
 */

/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0x40064000UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer
/**
 * @} */ /* End group MCG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer
* @brief C Struct for MCM
* @{
*/

/* ================================================================================ */
/* ================           MCM (file:MCM_MK11D5)                ================ */
/* ================================================================================ */

/**
 * @brief Core Platform Miscellaneous Control Module
 */
/**
* @addtogroup MCM_structs_GROUP MCM struct
* @brief Struct for MCM
* @{
*/
typedef struct {                                /*       MCM Structure                                                */
        uint8_t   RESERVED_0[8];               
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  PLACR;                        /**< 000C: Crossbar Switch (AXBS) Control Register                      */
} MCM_Type;

/**
 * @} */ /* End group MCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCM_Register_Masks_GROUP MCM Register Masks
* @brief Register Masks for MCM
* @{
*/
/* ------- PLASC Bit Fields                         ------ */
#define MCM_PLASC_ASC_MASK                       (0xFFU)                                             /*!< MCM_PLASC: ASC Mask                     */
#define MCM_PLASC_ASC_SHIFT                      (0U)                                                /*!< MCM_PLASC: ASC Position                 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK) /*!< MCM_PLASC                               */
/* ------- PLAMC Bit Fields                         ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFU)                                             /*!< MCM_PLAMC: AMC Mask                     */
#define MCM_PLAMC_AMC_SHIFT                      (0U)                                                /*!< MCM_PLAMC: AMC Position                 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK) /*!< MCM_PLAMC                               */
/* ------- PLACR Bit Fields                         ------ */
#define MCM_PLACR_ARB_MASK                       (0x200U)                                            /*!< MCM_PLACR: ARB Mask                     */
#define MCM_PLACR_ARB_SHIFT                      (9U)                                                /*!< MCM_PLACR: ARB Position                 */
#define MCM_PLACR_ARB(x)                         (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_ARB_SHIFT))&MCM_PLACR_ARB_MASK) /*!< MCM_PLACR                               */
/**
 * @} */ /* End group MCM_Register_Masks_GROUP 
 */

/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xE0080000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer
/**
 * @} */ /* End group MCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer
* @brief C Struct for NV
* @{
*/

/* ================================================================================ */
/* ================           NV (file:NV_FTFL)                    ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
/**
* @addtogroup NV_structs_GROUP NV struct
* @brief Struct for NV
* @{
*/
typedef struct {                                /*       NV Structure                                                 */
   __I  uint8_t   BACKKEY3;                     /**< 0000: Backdoor Comparison Key 3                                    */
   __I  uint8_t   BACKKEY2;                     /**< 0001: Backdoor Comparison Key 2                                    */
   __I  uint8_t   BACKKEY1;                     /**< 0002: Backdoor Comparison Key 1                                    */
   __I  uint8_t   BACKKEY0;                     /**< 0003: Backdoor Comparison Key 0                                    */
   __I  uint8_t   BACKKEY7;                     /**< 0004: Backdoor Comparison Key 7                                    */
   __I  uint8_t   BACKKEY6;                     /**< 0005: Backdoor Comparison Key 6                                    */
   __I  uint8_t   BACKKEY5;                     /**< 0006: Backdoor Comparison Key 5                                    */
   __I  uint8_t   BACKKEY4;                     /**< 0007: Backdoor Comparison Key 4                                    */
   __I  uint8_t   FPROT3;                       /**< 0008: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT2;                       /**< 0009: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT1;                       /**< 000A: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT0;                       /**< 000B: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FSEC;                         /**< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000D: Non-volatile Flash Option Register                           */
   __I  uint8_t   FEPROT;                       /**< 000E: Non-volatile EEPROM Protection Register                      */
   __I  uint8_t   FDPROT;                       /**< 000F: Non-volatile D-Flash Protection Register                     */
} NV_Type;

/**
 * @} */ /* End group NV_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup NV_Register_Masks_GROUP NV Register Masks
* @brief Register Masks for NV
* @{
*/
/* ------- BACKKEY Bit Fields                       ------ */
#define NV_BACKKEY_KEY_MASK                      (0xFFU)                                             /*!< NV_BACKKEY: KEY Mask                    */
#define NV_BACKKEY_KEY_SHIFT                     (0U)                                                /*!< NV_BACKKEY: KEY Position                */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY_KEY_SHIFT))&NV_BACKKEY_KEY_MASK) /*!< NV_BACKKEY                              */
/* ------- FPROT Bit Fields                         ------ */
#define NV_FPROT_PROT_MASK                       (0xFFU)                                             /*!< NV_FPROT: PROT Mask                     */
#define NV_FPROT_PROT_SHIFT                      (0U)                                                /*!< NV_FPROT: PROT Position                 */
#define NV_FPROT_PROT(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_PROT_SHIFT))&NV_FPROT_PROT_MASK) /*!< NV_FPROT                                */
/* ------- FSEC Bit Fields                          ------ */
#define NV_FSEC_SEC_MASK                         (0x3U)                                              /*!< NV_FSEC: SEC Mask                       */
#define NV_FSEC_SEC_SHIFT                        (0U)                                                /*!< NV_FSEC: SEC Position                   */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_FSLACC_MASK                      (0xCU)                                              /*!< NV_FSEC: FSLACC Mask                    */
#define NV_FSEC_FSLACC_SHIFT                     (2U)                                                /*!< NV_FSEC: FSLACC Position                */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_MEEN_MASK                        (0x30U)                                             /*!< NV_FSEC: MEEN Mask                      */
#define NV_FSEC_MEEN_SHIFT                       (4U)                                                /*!< NV_FSEC: MEEN Position                  */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_KEYEN_MASK                       (0xC0U)                                             /*!< NV_FSEC: KEYEN Mask                     */
#define NV_FSEC_KEYEN_SHIFT                      (6U)                                                /*!< NV_FSEC: KEYEN Position                 */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK) /*!< NV_FSEC                                 */
/* ------- FOPT Bit Fields                          ------ */
#define NV_FOPT_LPBOOT_MASK                      (0x1U)                                              /*!< NV_FOPT: LPBOOT Mask                    */
#define NV_FOPT_LPBOOT_SHIFT                     (0U)                                                /*!< NV_FOPT: LPBOOT Position                */
#define NV_FOPT_LPBOOT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT_SHIFT))&NV_FOPT_LPBOOT_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_EZPORT_DIS_MASK                  (0x2U)                                              /*!< NV_FOPT: EZPORT_DIS Mask                */
#define NV_FOPT_EZPORT_DIS_SHIFT                 (1U)                                                /*!< NV_FOPT: EZPORT_DIS Position            */
#define NV_FOPT_EZPORT_DIS(x)                    (((uint8_t)(((uint8_t)(x))<<NV_FOPT_EZPORT_DIS_SHIFT))&NV_FOPT_EZPORT_DIS_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_NMI_DIS_MASK                     (0x4U)                                              /*!< NV_FOPT: NMI_DIS Mask                   */
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)                                                /*!< NV_FOPT: NMI_DIS Position               */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_NMI_DIS_SHIFT))&NV_FOPT_NMI_DIS_MASK) /*!< NV_FOPT                                 */
/* ------- FEPROT Bit Fields                        ------ */
#define NV_FEPROT_EPROT_MASK                     (0xFFU)                                             /*!< NV_FEPROT: EPROT Mask                   */
#define NV_FEPROT_EPROT_SHIFT                    (0U)                                                /*!< NV_FEPROT: EPROT Position               */
#define NV_FEPROT_EPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FEPROT_EPROT_SHIFT))&NV_FEPROT_EPROT_MASK) /*!< NV_FEPROT                               */
/* ------- FDPROT Bit Fields                        ------ */
#define NV_FDPROT_DPROT_MASK                     (0xFFU)                                             /*!< NV_FDPROT: DPROT Mask                   */
#define NV_FDPROT_DPROT_SHIFT                    (0U)                                                /*!< NV_FDPROT: DPROT Position               */
#define NV_FDPROT_DPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FDPROT_DPROT_SHIFT))&NV_FDPROT_DPROT_MASK) /*!< NV_FDPROT                               */
/**
 * @} */ /* End group NV_Register_Masks_GROUP 
 */

/* NV - Peripheral instance base addresses */
#define NV_BasePtr                     0x00000400UL //!< Peripheral base address
#define NV                             ((NV_Type *) NV_BasePtr) //!< Freescale base pointer
#define NV_BASE_PTR                    (NV) //!< Freescale style base pointer
/**
 * @} */ /* End group NV_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer
* @brief C Struct for OSC
* @{
*/

/* ================================================================================ */
/* ================           OSC0 (file:OSC0_MK)                  ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
/**
* @addtogroup OSC_structs_GROUP OSC struct
* @brief Struct for OSC
* @{
*/
typedef struct {                                /*       OSC0 Structure                                               */
   __IO uint8_t   CR;                           /**< 0000: Control Register                                             */
} OSC_Type;

/**
 * @} */ /* End group OSC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup OSC_Register_Masks_GROUP OSC Register Masks
* @brief Register Masks for OSC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define OSC_CR_SCP_MASK                          (0xFU)                                              /*!< OSC0_CR: SCP Mask                       */
#define OSC_CR_SCP_SHIFT                         (0U)                                                /*!< OSC0_CR: SCP Position                   */
#define OSC_CR_SCP(x)                            (((uint8_t)(((uint8_t)(x))<<OSC_CR_SCP_SHIFT))&OSC_CR_SCP_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC16P_MASK                        (0x1U)                                              /*!< OSC0_CR: SC16P Mask                     */
#define OSC_CR_SC16P_SHIFT                       (0U)                                                /*!< OSC0_CR: SC16P Position                 */
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC16P_SHIFT))&OSC_CR_SC16P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC8P_MASK                         (0x2U)                                              /*!< OSC0_CR: SC8P Mask                      */
#define OSC_CR_SC8P_SHIFT                        (1U)                                                /*!< OSC0_CR: SC8P Position                  */
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC8P_SHIFT))&OSC_CR_SC8P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC4P_MASK                         (0x4U)                                              /*!< OSC0_CR: SC4P Mask                      */
#define OSC_CR_SC4P_SHIFT                        (2U)                                                /*!< OSC0_CR: SC4P Position                  */
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC4P_SHIFT))&OSC_CR_SC4P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC2P_MASK                         (0x8U)                                              /*!< OSC0_CR: SC2P Mask                      */
#define OSC_CR_SC2P_SHIFT                        (3U)                                                /*!< OSC0_CR: SC2P Position                  */
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC2P_SHIFT))&OSC_CR_SC2P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_EREFSTEN_MASK                     (0x20U)                                             /*!< OSC0_CR: EREFSTEN Mask                  */
#define OSC_CR_EREFSTEN_SHIFT                    (5U)                                                /*!< OSC0_CR: EREFSTEN Position              */
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<OSC_CR_EREFSTEN_SHIFT))&OSC_CR_EREFSTEN_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_ERCLKEN_MASK                      (0x80U)                                             /*!< OSC0_CR: ERCLKEN Mask                   */
#define OSC_CR_ERCLKEN_SHIFT                     (7U)                                                /*!< OSC0_CR: ERCLKEN Position               */
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_ERCLKEN_SHIFT))&OSC_CR_ERCLKEN_MASK) /*!< OSC0_CR                                 */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC0 - Peripheral instance base addresses */
#define OSC0_BasePtr                   0x40065000UL //!< Peripheral base address
#define OSC0                           ((OSC_Type *) OSC0_BasePtr) //!< Freescale base pointer
#define OSC0_BASE_PTR                  (OSC0) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB0 (file:PDB0_2CH_2TRIG_1DAC_2PO)       ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (2 channels, 2 triggers, 2 DAC, 4 pulse outputs)
 */
/**
* @addtogroup PDB_structs_GROUP PDB struct
* @brief Struct for PDB
* @{
*/
typedef struct {                                /*       PDB0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control Register                                  */
   __IO uint32_t  MOD;                          /**< 0004: Modulus Register                                             */
   __I  uint32_t  CNT;                          /**< 0008: Counter Register                                             */
   __IO uint32_t  IDLY;                         /**< 000C: Interrupt Delay Register                                     */
   struct {
      __IO uint32_t  C1;                        /**< 0010: Channel  Control Register 1                                  */
      __IO uint32_t  S;                         /**< 0014: Channel  Status Register                                     */
      __IO uint32_t  DLY[2];                    /**< 0018: Channel Delay  Register                                      */
           uint8_t   RESERVED_0[24];           
   } CH[2];                                     /**< 0010: (cluster: size=0x0050, 80)                                   */
        uint8_t   RESERVED_1[240];             
   struct {
      __IO uint32_t  INTC;                      /**< 0150: DAC Interval Trigger n Control Register                      */
      __IO uint32_t  INT;                       /**< 0154: DAC Interval n Register                                      */
   } DAC[1];                                    /**< 0150: (cluster: size=0x0008, 8)                                    */
        uint8_t   RESERVED_3[56];              
   __IO uint32_t  POEN;                         /**< 0190: Pulse-Out Enable Register                                    */
   __IO uint32_t  PODLY[2];                     /**< 0194: Pulse-Out  Delay Register                                    */
} PDB_Type;

/**
 * @} */ /* End group PDB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PDB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PDB_Register_Masks_GROUP PDB Register Masks
* @brief Register Masks for PDB
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define PDB_SC_LDOK_MASK                         (0x1U)                                              /*!< PDB0_SC: LDOK Mask                      */
#define PDB_SC_LDOK_SHIFT                        (0U)                                                /*!< PDB0_SC: LDOK Position                  */
#define PDB_SC_LDOK(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDOK_SHIFT))&PDB_SC_LDOK_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_CONT_MASK                         (0x2U)                                              /*!< PDB0_SC: CONT Mask                      */
#define PDB_SC_CONT_SHIFT                        (1U)                                                /*!< PDB0_SC: CONT Position                  */
#define PDB_SC_CONT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_CONT_SHIFT))&PDB_SC_CONT_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_MULT_MASK                         (0xCU)                                              /*!< PDB0_SC: MULT Mask                      */
#define PDB_SC_MULT_SHIFT                        (2U)                                                /*!< PDB0_SC: MULT Position                  */
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBIE_MASK                        (0x20U)                                             /*!< PDB0_SC: PDBIE Mask                     */
#define PDB_SC_PDBIE_SHIFT                       (5U)                                                /*!< PDB0_SC: PDBIE Position                 */
#define PDB_SC_PDBIE(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBIE_SHIFT))&PDB_SC_PDBIE_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBIF_MASK                        (0x40U)                                             /*!< PDB0_SC: PDBIF Mask                     */
#define PDB_SC_PDBIF_SHIFT                       (6U)                                                /*!< PDB0_SC: PDBIF Position                 */
#define PDB_SC_PDBIF(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBIF_SHIFT))&PDB_SC_PDBIF_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBEN_MASK                        (0x80U)                                             /*!< PDB0_SC: PDBEN Mask                     */
#define PDB_SC_PDBEN_SHIFT                       (7U)                                                /*!< PDB0_SC: PDBEN Position                 */
#define PDB_SC_PDBEN(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBEN_SHIFT))&PDB_SC_PDBEN_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_TRGSEL_MASK                       (0xF00U)                                            /*!< PDB0_SC: TRGSEL Mask                    */
#define PDB_SC_TRGSEL_SHIFT                      (8U)                                                /*!< PDB0_SC: TRGSEL Position                */
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PRESCALER_MASK                    (0x7000U)                                           /*!< PDB0_SC: PRESCALER Mask                 */
#define PDB_SC_PRESCALER_SHIFT                   (12U)                                               /*!< PDB0_SC: PRESCALER Position             */
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_DMAEN_MASK                        (0x8000U)                                           /*!< PDB0_SC: DMAEN Mask                     */
#define PDB_SC_DMAEN_SHIFT                       (15U)                                               /*!< PDB0_SC: DMAEN Position                 */
#define PDB_SC_DMAEN(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_DMAEN_SHIFT))&PDB_SC_DMAEN_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_SWTRIG_MASK                       (0x10000U)                                          /*!< PDB0_SC: SWTRIG Mask                    */
#define PDB_SC_SWTRIG_SHIFT                      (16U)                                               /*!< PDB0_SC: SWTRIG Position                */
#define PDB_SC_SWTRIG(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_SWTRIG_SHIFT))&PDB_SC_SWTRIG_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBEIE_MASK                       (0x20000U)                                          /*!< PDB0_SC: PDBEIE Mask                    */
#define PDB_SC_PDBEIE_SHIFT                      (17U)                                               /*!< PDB0_SC: PDBEIE Position                */
#define PDB_SC_PDBEIE(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBEIE_SHIFT))&PDB_SC_PDBEIE_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_LDMOD_MASK                        (0xC0000U)                                          /*!< PDB0_SC: LDMOD Mask                     */
#define PDB_SC_LDMOD_SHIFT                       (18U)                                               /*!< PDB0_SC: LDMOD Position                 */
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK) /*!< PDB0_SC                                 */
/* ------- MOD Bit Fields                           ------ */
#define PDB_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< PDB0_MOD: MOD Mask                      */
#define PDB_MOD_MOD_SHIFT                        (0U)                                                /*!< PDB0_MOD: MOD Position                  */
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK) /*!< PDB0_MOD                                */
/* ------- CNT Bit Fields                           ------ */
#define PDB_CNT_CNT_MASK                         (0xFFFFU)                                           /*!< PDB0_CNT: CNT Mask                      */
#define PDB_CNT_CNT_SHIFT                        (0U)                                                /*!< PDB0_CNT: CNT Position                  */
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK) /*!< PDB0_CNT                                */
/* ------- IDLY Bit Fields                          ------ */
#define PDB_IDLY_IDLY_MASK                       (0xFFFFU)                                           /*!< PDB0_IDLY: IDLY Mask                    */
#define PDB_IDLY_IDLY_SHIFT                      (0U)                                                /*!< PDB0_IDLY: IDLY Position                */
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK) /*!< PDB0_IDLY                               */
/* ------- C1 Bit Fields                            ------ */
#define PDB_C1_EN_MASK                           (0xFFU)                                             /*!< PDB0_C1: EN Mask                        */
#define PDB_C1_EN_SHIFT                          (0U)                                                /*!< PDB0_C1: EN Position                    */
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK) /*!< PDB0_C1                                 */
#define PDB_C1_TOS_MASK                          (0xFF00U)                                           /*!< PDB0_C1: TOS Mask                       */
#define PDB_C1_TOS_SHIFT                         (8U)                                                /*!< PDB0_C1: TOS Position                   */
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK) /*!< PDB0_C1                                 */
#define PDB_C1_BB_MASK                           (0xFF0000U)                                         /*!< PDB0_C1: BB Mask                        */
#define PDB_C1_BB_SHIFT                          (16U)                                               /*!< PDB0_C1: BB Position                    */
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK) /*!< PDB0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define PDB_S_ERR_MASK                           (0xFFU)                                             /*!< PDB0_S: ERR Mask                        */
#define PDB_S_ERR_SHIFT                          (0U)                                                /*!< PDB0_S: ERR Position                    */
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK) /*!< PDB0_S                                  */
#define PDB_S_CF_MASK                            (0xFF0000U)                                         /*!< PDB0_S: CF Mask                         */
#define PDB_S_CF_SHIFT                           (16U)                                               /*!< PDB0_S: CF Position                     */
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK) /*!< PDB0_S                                  */
/* ------- DLY Bit Fields                           ------ */
#define PDB_DLY_DLY_MASK                         (0xFFFFU)                                           /*!< PDB0_DLY: DLY Mask                      */
#define PDB_DLY_DLY_SHIFT                        (0U)                                                /*!< PDB0_DLY: DLY Position                  */
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK) /*!< PDB0_DLY                                */
/* ------- INTC Bit Fields                          ------ */
#define PDB_INTC_TOE_MASK                        (0x1U)                                              /*!< PDB0_INTC: TOE Mask                     */
#define PDB_INTC_TOE_SHIFT                       (0U)                                                /*!< PDB0_INTC: TOE Position                 */
#define PDB_INTC_TOE(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_INTC_TOE_SHIFT))&PDB_INTC_TOE_MASK) /*!< PDB0_INTC                               */
#define PDB_INTC_EXT_MASK                        (0x2U)                                              /*!< PDB0_INTC: EXT Mask                     */
#define PDB_INTC_EXT_SHIFT                       (1U)                                                /*!< PDB0_INTC: EXT Position                 */
#define PDB_INTC_EXT(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_INTC_EXT_SHIFT))&PDB_INTC_EXT_MASK) /*!< PDB0_INTC                               */
/* ------- INT Bit Fields                           ------ */
#define PDB_INT_INT_MASK                         (0xFFFFU)                                           /*!< PDB0_INT: INT Mask                      */
#define PDB_INT_INT_SHIFT                        (0U)                                                /*!< PDB0_INT: INT Position                  */
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_INT_INT_SHIFT))&PDB_INT_INT_MASK) /*!< PDB0_INT                                */
/* ------- POEN Bit Fields                          ------ */
#define PDB_POEN_POEN_MASK                       (0xFFU)                                             /*!< PDB0_POEN: POEN Mask                    */
#define PDB_POEN_POEN_SHIFT                      (0U)                                                /*!< PDB0_POEN: POEN Position                */
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK) /*!< PDB0_POEN                               */
/* ------- PODLY Bit Fields                         ------ */
#define PDB_PODLY_DLY2_MASK                      (0xFFFFU)                                           /*!< PDB0_PODLY: DLY2 Mask                   */
#define PDB_PODLY_DLY2_SHIFT                     (0U)                                                /*!< PDB0_PODLY: DLY2 Position               */
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY2_SHIFT))&PDB_PODLY_DLY2_MASK) /*!< PDB0_PODLY                              */
#define PDB_PODLY_DLY1_MASK                      (0xFFFF0000U)                                       /*!< PDB0_PODLY: DLY1 Mask                   */
#define PDB_PODLY_DLY1_SHIFT                     (16U)                                               /*!< PDB0_PODLY: DLY1 Position               */
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY1_SHIFT))&PDB_PODLY_DLY1_MASK) /*!< PDB0_PODLY                              */
/**
 * @} */ /* End group PDB_Register_Masks_GROUP 
 */

/* PDB0 - Peripheral instance base addresses */
#define PDB0_BasePtr                   0x40036000UL //!< Peripheral base address
#define PDB0                           ((PDB_Type *) PDB0_BasePtr) //!< Freescale base pointer
#define PDB0_BASE_PTR                  (PDB0) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT (file:PIT_4CH_CHAIN)             ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (4 channels)
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT Structure                                                */
   __IO uint32_t  MCR;                          /**< 0000: Module Control Register                                      */
        uint8_t   RESERVED_0[252];             
   struct {
      __IO uint32_t  LDVAL;                     /**< 0100: Timer Load Value Register                                    */
      __I  uint32_t  CVAL;                      /**< 0104: Current Timer Value Register                                 */
      __IO uint32_t  TCTRL;                     /**< 0108: Timer Control Register                                       */
      __IO uint32_t  TFLG;                      /**< 010C: Timer Flag Register                                          */
   } CHANNEL[4];                                /**< 0100: (cluster: size=0x0040, 64)                                   */
} PIT_Type;

/**
 * @} */ /* End group PIT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define PIT_MCR_FRZ_MASK                         (0x1U)                                              /*!< PIT_MCR: FRZ Mask                       */
#define PIT_MCR_FRZ_SHIFT                        (0U)                                                /*!< PIT_MCR: FRZ Position                   */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<PIT_MCR_FRZ_SHIFT))&PIT_MCR_FRZ_MASK) /*!< PIT_MCR                                 */
#define PIT_MCR_MDIS_MASK                        (0x2U)                                              /*!< PIT_MCR: MDIS Mask                      */
#define PIT_MCR_MDIS_SHIFT                       (1U)                                                /*!< PIT_MCR: MDIS Position                  */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_MCR_MDIS_SHIFT))&PIT_MCR_MDIS_MASK) /*!< PIT_MCR                                 */
/* ------- LDVAL Bit Fields                         ------ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)                                       /*!< PIT_LDVAL: TSV Mask                     */
#define PIT_LDVAL_TSV_SHIFT                      (0U)                                                /*!< PIT_LDVAL: TSV Position                 */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK) /*!< PIT_LDVAL                               */
/* ------- CVAL Bit Fields                          ------ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)                                       /*!< PIT_CVAL: TVL Mask                      */
#define PIT_CVAL_TVL_SHIFT                       (0U)                                                /*!< PIT_CVAL: TVL Position                  */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK) /*!< PIT_CVAL                                */
/* ------- TCTRL Bit Fields                         ------ */
#define PIT_TCTRL_TEN_MASK                       (0x1U)                                              /*!< PIT_TCTRL: TEN Mask                     */
#define PIT_TCTRL_TEN_SHIFT                      (0U)                                                /*!< PIT_TCTRL: TEN Position                 */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TEN_SHIFT))&PIT_TCTRL_TEN_MASK) /*!< PIT_TCTRL                               */
#define PIT_TCTRL_TIE_MASK                       (0x2U)                                              /*!< PIT_TCTRL: TIE Mask                     */
#define PIT_TCTRL_TIE_SHIFT                      (1U)                                                /*!< PIT_TCTRL: TIE Position                 */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TIE_SHIFT))&PIT_TCTRL_TIE_MASK) /*!< PIT_TCTRL                               */
#define PIT_TCTRL_CHN_MASK                       (0x4U)                                              /*!< PIT_TCTRL: CHN Mask                     */
#define PIT_TCTRL_CHN_SHIFT                      (2U)                                                /*!< PIT_TCTRL: CHN Position                 */
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_CHN_SHIFT))&PIT_TCTRL_CHN_MASK) /*!< PIT_TCTRL                               */
/* ------- TFLG Bit Fields                          ------ */
#define PIT_TFLG_TIF_MASK                        (0x1U)                                              /*!< PIT_TFLG: TIF Mask                      */
#define PIT_TFLG_TIF_SHIFT                       (0U)                                                /*!< PIT_TFLG: TIF Position                  */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_TFLG_TIF_SHIFT))&PIT_TFLG_TIF_MASK) /*!< PIT_TFLG                                */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT - Peripheral instance base addresses */
#define PIT_BasePtr                    0x40037000UL //!< Peripheral base address
#define PIT                            ((PIT_Type *) PIT_BasePtr) //!< Freescale base pointer
#define PIT_BASE_PTR                   (PIT) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MK)                    ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
* @addtogroup PMC_structs_GROUP PMC struct
* @brief Struct for PMC
* @{
*/
typedef struct {                                /*       PMC Structure                                                */
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Status and Control 1                             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Status and Control 2                             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status and Control                                 */
} PMC_Type;

/**
 * @} */ /* End group PMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMC_Register_Masks_GROUP PMC Register Masks
* @brief Register Masks for PMC
* @{
*/
/* ------- LVDSC1 Bit Fields                        ------ */
#define PMC_LVDSC1_LVDV_MASK                     (0x3U)                                              /*!< PMC_LVDSC1: LVDV Mask                   */
#define PMC_LVDSC1_LVDV_SHIFT                    (0U)                                                /*!< PMC_LVDSC1: LVDV Position               */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDRE_MASK                    (0x10U)                                             /*!< PMC_LVDSC1: LVDRE Mask                  */
#define PMC_LVDSC1_LVDRE_SHIFT                   (4U)                                                /*!< PMC_LVDSC1: LVDRE Position              */
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDRE_SHIFT))&PMC_LVDSC1_LVDRE_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC1: LVDIE Mask                  */
#define PMC_LVDSC1_LVDIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC1: LVDIE Position              */
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDIE_SHIFT))&PMC_LVDSC1_LVDIE_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC1: LVDACK Mask                 */
#define PMC_LVDSC1_LVDACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC1: LVDACK Position             */
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDACK_SHIFT))&PMC_LVDSC1_LVDACK_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDF_MASK                     (0x80U)                                             /*!< PMC_LVDSC1: LVDF Mask                   */
#define PMC_LVDSC1_LVDF_SHIFT                    (7U)                                                /*!< PMC_LVDSC1: LVDF Position               */
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDF_SHIFT))&PMC_LVDSC1_LVDF_MASK) /*!< PMC_LVDSC1                              */
/* ------- LVDSC2 Bit Fields                        ------ */
#define PMC_LVDSC2_LVWV_MASK                     (0x3U)                                              /*!< PMC_LVDSC2: LVWV Mask                   */
#define PMC_LVDSC2_LVWV_SHIFT                    (0U)                                                /*!< PMC_LVDSC2: LVWV Position               */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC2: LVWIE Mask                  */
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC2: LVWIE Position              */
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWIE_SHIFT))&PMC_LVDSC2_LVWIE_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC2: LVWACK Mask                 */
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC2: LVWACK Position             */
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWACK_SHIFT))&PMC_LVDSC2_LVWACK_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWF_MASK                     (0x80U)                                             /*!< PMC_LVDSC2: LVWF Mask                   */
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)                                                /*!< PMC_LVDSC2: LVWF Position               */
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWF_SHIFT))&PMC_LVDSC2_LVWF_MASK) /*!< PMC_LVDSC2                              */
/* ------- REGSC Bit Fields                         ------ */
#define PMC_REGSC_BGBE_MASK                      (0x1U)                                              /*!< PMC_REGSC: BGBE Mask                    */
#define PMC_REGSC_BGBE_SHIFT                     (0U)                                                /*!< PMC_REGSC: BGBE Position                */
#define PMC_REGSC_BGBE(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGBE_SHIFT))&PMC_REGSC_BGBE_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_REGONS_MASK                    (0x4U)                                              /*!< PMC_REGSC: REGONS Mask                  */
#define PMC_REGSC_REGONS_SHIFT                   (2U)                                                /*!< PMC_REGSC: REGONS Position              */
#define PMC_REGSC_REGONS(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_REGONS_SHIFT))&PMC_REGSC_REGONS_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_ACKISO_MASK                    (0x8U)                                              /*!< PMC_REGSC: ACKISO Mask                  */
#define PMC_REGSC_ACKISO_SHIFT                   (3U)                                                /*!< PMC_REGSC: ACKISO Position              */
#define PMC_REGSC_ACKISO(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_ACKISO_SHIFT))&PMC_REGSC_ACKISO_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_BGEN_MASK                      (0x10U)                                             /*!< PMC_REGSC: BGEN Mask                    */
#define PMC_REGSC_BGEN_SHIFT                     (4U)                                                /*!< PMC_REGSC: BGEN Position                */
#define PMC_REGSC_BGEN(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGEN_SHIFT))&PMC_REGSC_BGEN_MASK) /*!< PMC_REGSC                               */
/**
 * @} */ /* End group PMC_Register_Masks_GROUP 
 */

/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0x4007D000UL //!< Peripheral base address
#define PMC                            ((PMC_Type *) PMC_BasePtr) //!< Freescale base pointer
#define PMC_BASE_PTR                   (PMC) //!< Freescale style base pointer
/**
 * @} */ /* End group PMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTA (file:PORTA_DFER)              ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
* @addtogroup PORT_structs_GROUP PORT struct
* @brief Struct for PORT
* @{
*/
typedef struct {                                /*       PORTA Structure                                              */
   __IO uint32_t  PCR[32];                      /**< 0000: Pin Control Register                                         */
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
        uint8_t   RESERVED_0[24];              
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
        uint8_t   RESERVED_1[28];              
   __IO uint32_t  DFER;                         /**< 00C0: Digital Filter Enable Register                               */
   __IO uint32_t  DFCR;                         /**< 00C4: Digital Filter Clock Register                                */
   __IO uint32_t  DFWR;                         /**< 00C8: Digital Filter Width Register                                */
} PORT_Type;

/**
 * @} */ /* End group PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PORT_Register_Masks_GROUP PORT Register Masks
* @brief Register Masks for PORT
* @{
*/
/* ------- PCR Bit Fields                           ------ */
#define PORT_PCR_PS_MASK                         (0x1U)                                              /*!< PORTA_PCR: PS Mask                      */
#define PORT_PCR_PS_SHIFT                        (0U)                                                /*!< PORTA_PCR: PS Position                  */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_PE_MASK                         (0x2U)                                              /*!< PORTA_PCR: PE Mask                      */
#define PORT_PCR_PE_SHIFT                        (1U)                                                /*!< PORTA_PCR: PE Position                  */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_SRE_MASK                        (0x4U)                                              /*!< PORTA_PCR: SRE Mask                     */
#define PORT_PCR_SRE_SHIFT                       (2U)                                                /*!< PORTA_PCR: SRE Position                 */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_SRE_SHIFT))&PORT_PCR_SRE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_PFE_MASK                        (0x10U)                                             /*!< PORTA_PCR: PFE Mask                     */
#define PORT_PCR_PFE_SHIFT                       (4U)                                                /*!< PORTA_PCR: PFE Position                 */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_ODE_MASK                        (0x20U)                                             /*!< PORTA_PCR: ODE Mask                     */
#define PORT_PCR_ODE_SHIFT                       (5U)                                                /*!< PORTA_PCR: ODE Position                 */
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ODE_SHIFT))&PORT_PCR_ODE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_DSE_MASK                        (0x40U)                                             /*!< PORTA_PCR: DSE Mask                     */
#define PORT_PCR_DSE_SHIFT                       (6U)                                                /*!< PORTA_PCR: DSE Position                 */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_MUX_MASK                        (0x700U)                                            /*!< PORTA_PCR: MUX Mask                     */
#define PORT_PCR_MUX_SHIFT                       (8U)                                                /*!< PORTA_PCR: MUX Position                 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_LK_MASK                         (0x8000U)                                           /*!< PORTA_PCR: LK Mask                      */
#define PORT_PCR_LK_SHIFT                        (15U)                                               /*!< PORTA_PCR: LK Position                  */
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_LK_SHIFT))&PORT_PCR_LK_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_IRQC_MASK                       (0xF0000U)                                          /*!< PORTA_PCR: IRQC Mask                    */
#define PORT_PCR_IRQC_SHIFT                      (16U)                                               /*!< PORTA_PCR: IRQC Position                */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_ISF_MASK                        (0x1000000U)                                        /*!< PORTA_PCR: ISF Mask                     */
#define PORT_PCR_ISF_SHIFT                       (24U)                                               /*!< PORTA_PCR: ISF Position                 */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK) /*!< PORTA_PCR                               */
/* ------- GPCLR Bit Fields                         ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCLR: GPWD Mask                  */
#define PORT_GPCLR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCLR: GPWD Position              */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK) /*!< PORTA_GPCLR                             */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCLR: GPWE Mask                  */
#define PORT_GPCLR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCLR: GPWE Position              */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK) /*!< PORTA_GPCLR                             */
/* ------- GPCHR Bit Fields                         ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCHR: GPWD Mask                  */
#define PORT_GPCHR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCHR: GPWD Position              */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK) /*!< PORTA_GPCHR                             */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCHR: GPWE Mask                  */
#define PORT_GPCHR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCHR: GPWE Position              */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK) /*!< PORTA_GPCHR                             */
/* ------- ISFR Bit Fields                          ------ */
/* ------- DFER Bit Fields                          ------ */
/* ------- DFCR Bit Fields                          ------ */
#define PORT_DFCR_CS_MASK                        (0x1U)                                              /*!< PORTA_DFCR: CS Mask                     */
#define PORT_DFCR_CS_SHIFT                       (0U)                                                /*!< PORTA_DFCR: CS Position                 */
#define PORT_DFCR_CS(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_DFCR_CS_SHIFT))&PORT_DFCR_CS_MASK) /*!< PORTA_DFCR                              */
/* ------- DFWR Bit Fields                          ------ */
#define PORT_DFWR_FILT_MASK                      (0x1FU)                                             /*!< PORTA_DFWR: FILT Mask                   */
#define PORT_DFWR_FILT_SHIFT                     (0U)                                                /*!< PORTA_DFWR: FILT Position               */
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK) /*!< PORTA_DFWR                              */
/**
 * @} */ /* End group PORT_Register_Masks_GROUP 
 */

/* PORTA - Peripheral instance base addresses */
#define PORTA_BasePtr                  0x40049000UL //!< Peripheral base address
#define PORTA                          ((PORT_Type *) PORTA_BasePtr) //!< Freescale base pointer
#define PORTA_BASE_PTR                 (PORTA) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTB (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTB - Peripheral instance base addresses */
#define PORTB_BasePtr                  0x4004A000UL //!< Peripheral base address
#define PORTB                          ((PORT_Type *) PORTB_BasePtr) //!< Freescale base pointer
#define PORTB_BASE_PTR                 (PORTB) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTC (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTC - Peripheral instance base addresses */
#define PORTC_BasePtr                  0x4004B000UL //!< Peripheral base address
#define PORTC                          ((PORT_Type *) PORTC_BasePtr) //!< Freescale base pointer
#define PORTC_BASE_PTR                 (PORTC) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTD (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTD - Peripheral instance base addresses */
#define PORTD_BasePtr                  0x4004C000UL //!< Peripheral base address
#define PORTD                          ((PORT_Type *) PORTD_BasePtr) //!< Freescale base pointer
#define PORTD_BASE_PTR                 (PORTD) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTE (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTE - Peripheral instance base addresses */
#define PORTE_BasePtr                  0x4004D000UL //!< Peripheral base address
#define PORTE                          ((PORT_Type *) PORTE_BasePtr) //!< Freescale base pointer
#define PORTE_BASE_PTR                 (PORTE) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MK11D5WS)              ================ */
/* ================================================================================ */

/**
 * @brief Reset Control Module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct {                                /*       RCM Structure                                                */
   __I  uint8_t   SRS0;                         /**< 0000: System Reset Status Register 0                               */
   __I  uint8_t   SRS1;                         /**< 0001: System Reset Status Register 1                               */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width Register                              */
        uint8_t   RESERVED_1;                  
   __I  uint8_t   MR;                           /**< 0007: Mode Register                                                */
} RCM_Type;

/**
 * @} */ /* End group RCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RCM_Register_Masks_GROUP RCM Register Masks
* @brief Register Masks for RCM
* @{
*/
/* ------- SRS0 Bit Fields                          ------ */
#define RCM_SRS0_WAKEUP_MASK                     (0x1U)                                              /*!< RCM_SRS0: WAKEUP Mask                   */
#define RCM_SRS0_WAKEUP_SHIFT                    (0U)                                                /*!< RCM_SRS0: WAKEUP Position               */
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WAKEUP_SHIFT))&RCM_SRS0_WAKEUP_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_LVD_MASK                        (0x2U)                                              /*!< RCM_SRS0: LVD Mask                      */
#define RCM_SRS0_LVD_SHIFT                       (1U)                                                /*!< RCM_SRS0: LVD Position                  */
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LVD_SHIFT))&RCM_SRS0_LVD_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_LOC_MASK                        (0x4U)                                              /*!< RCM_SRS0: LOC Mask                      */
#define RCM_SRS0_LOC_SHIFT                       (2U)                                                /*!< RCM_SRS0: LOC Position                  */
#define RCM_SRS0_LOC(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LOC_SHIFT))&RCM_SRS0_LOC_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_LOL_MASK                        (0x8U)                                              /*!< RCM_SRS0: LOL Mask                      */
#define RCM_SRS0_LOL_SHIFT                       (3U)                                                /*!< RCM_SRS0: LOL Position                  */
#define RCM_SRS0_LOL(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LOL_SHIFT))&RCM_SRS0_LOL_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_WDOG_MASK                       (0x20U)                                             /*!< RCM_SRS0: WDOG Mask                     */
#define RCM_SRS0_WDOG_SHIFT                      (5U)                                                /*!< RCM_SRS0: WDOG Position                 */
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WDOG_SHIFT))&RCM_SRS0_WDOG_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_PIN_MASK                        (0x40U)                                             /*!< RCM_SRS0: PIN Mask                      */
#define RCM_SRS0_PIN_SHIFT                       (6U)                                                /*!< RCM_SRS0: PIN Position                  */
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_PIN_SHIFT))&RCM_SRS0_PIN_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_POR_MASK                        (0x80U)                                             /*!< RCM_SRS0: POR Mask                      */
#define RCM_SRS0_POR_SHIFT                       (7U)                                                /*!< RCM_SRS0: POR Position                  */
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_POR_SHIFT))&RCM_SRS0_POR_MASK) /*!< RCM_SRS0                                */
/* ------- SRS1 Bit Fields                          ------ */
#define RCM_SRS1_JTAG_MASK                       (0x1U)                                              /*!< RCM_SRS1: JTAG Mask                     */
#define RCM_SRS1_JTAG_SHIFT                      (0U)                                                /*!< RCM_SRS1: JTAG Position                 */
#define RCM_SRS1_JTAG(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_JTAG_SHIFT))&RCM_SRS1_JTAG_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_LOCKUP_MASK                     (0x2U)                                              /*!< RCM_SRS1: LOCKUP Mask                   */
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)                                                /*!< RCM_SRS1: LOCKUP Position               */
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_LOCKUP_SHIFT))&RCM_SRS1_LOCKUP_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_SW_MASK                         (0x4U)                                              /*!< RCM_SRS1: SW Mask                       */
#define RCM_SRS1_SW_SHIFT                        (2U)                                                /*!< RCM_SRS1: SW Position                   */
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SW_SHIFT))&RCM_SRS1_SW_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_MDM_AP_MASK                     (0x8U)                                              /*!< RCM_SRS1: MDM_AP Mask                   */
#define RCM_SRS1_MDM_AP_SHIFT                    (3U)                                                /*!< RCM_SRS1: MDM_AP Position               */
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_MDM_AP_SHIFT))&RCM_SRS1_MDM_AP_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_EZPT_MASK                       (0x10U)                                             /*!< RCM_SRS1: EZPT Mask                     */
#define RCM_SRS1_EZPT_SHIFT                      (4U)                                                /*!< RCM_SRS1: EZPT Position                 */
#define RCM_SRS1_EZPT(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_EZPT_SHIFT))&RCM_SRS1_EZPT_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_SACKERR_MASK                    (0x20U)                                             /*!< RCM_SRS1: SACKERR Mask                  */
#define RCM_SRS1_SACKERR_SHIFT                   (5U)                                                /*!< RCM_SRS1: SACKERR Position              */
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SACKERR_SHIFT))&RCM_SRS1_SACKERR_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_TAMPER_MASK                     (0x80U)                                             /*!< RCM_SRS1: TAMPER Mask                   */
#define RCM_SRS1_TAMPER_SHIFT                    (7U)                                                /*!< RCM_SRS1: TAMPER Position               */
#define RCM_SRS1_TAMPER(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_TAMPER_SHIFT))&RCM_SRS1_TAMPER_MASK) /*!< RCM_SRS1                                */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)                                              /*!< RCM_RPFC: RSTFLTSRW Mask                */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)                                                /*!< RCM_RPFC: RSTFLTSRW Position            */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK) /*!< RCM_RPFC                                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)                                              /*!< RCM_RPFC: RSTFLTSS Mask                 */
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)                                                /*!< RCM_RPFC: RSTFLTSS Position             */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSS_SHIFT))&RCM_RPFC_RSTFLTSS_MASK) /*!< RCM_RPFC                                */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)                                             /*!< RCM_RPFW: RSTFLTSEL Mask                */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)                                                /*!< RCM_RPFW: RSTFLTSEL Position            */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK) /*!< RCM_RPFW                                */
/* ------- MR Bit Fields                            ------ */
#define RCM_MR_EZP_MS_MASK                       (0x2U)                                              /*!< RCM_MR: EZP_MS Mask                     */
#define RCM_MR_EZP_MS_SHIFT                      (1U)                                                /*!< RCM_MR: EZP_MS Position                 */
#define RCM_MR_EZP_MS(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_MR_EZP_MS_SHIFT))&RCM_MR_EZP_MS_MASK) /*!< RCM_MR                                  */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x4007F000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer
/**
 * @} */ /* End group RCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RFSYS_Peripheral_access_layer_GROUP RFSYS Peripheral Access Layer
* @brief C Struct for RFSYS
* @{
*/

/* ================================================================================ */
/* ================           RFSYS (file:RFSYS_0)                 ================ */
/* ================================================================================ */

/**
 * @brief System register file
 */
/**
* @addtogroup RFSYS_structs_GROUP RFSYS struct
* @brief Struct for RFSYS
* @{
*/
typedef struct {                                /*       RFSYS Structure                                              */
   __IO uint32_t  REG[8];                       /**< 0000: Register file register                                       */
} RFSYS_Type;

/**
 * @} */ /* End group RFSYS_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RFSYS' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RFSYS_Register_Masks_GROUP RFSYS Register Masks
* @brief Register Masks for RFSYS
* @{
*/
/* ------- REG Bit Fields                           ------ */
#define RFSYS_REG_LL_MASK                        (0xFFU)                                             /*!< RFSYS_REG: LL Mask                      */
#define RFSYS_REG_LL_SHIFT                       (0U)                                                /*!< RFSYS_REG: LL Position                  */
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LL_SHIFT))&RFSYS_REG_LL_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_LH_MASK                        (0xFF00U)                                           /*!< RFSYS_REG: LH Mask                      */
#define RFSYS_REG_LH_SHIFT                       (8U)                                                /*!< RFSYS_REG: LH Position                  */
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LH_SHIFT))&RFSYS_REG_LH_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_HL_MASK                        (0xFF0000U)                                         /*!< RFSYS_REG: HL Mask                      */
#define RFSYS_REG_HL_SHIFT                       (16U)                                               /*!< RFSYS_REG: HL Position                  */
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HL_SHIFT))&RFSYS_REG_HL_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_HH_MASK                        (0xFF000000U)                                       /*!< RFSYS_REG: HH Mask                      */
#define RFSYS_REG_HH_SHIFT                       (24U)                                               /*!< RFSYS_REG: HH Position                  */
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HH_SHIFT))&RFSYS_REG_HH_MASK) /*!< RFSYS_REG                               */
/**
 * @} */ /* End group RFSYS_Register_Masks_GROUP 
 */

/* RFSYS - Peripheral instance base addresses */
#define RFSYS_BasePtr                  0x40041000UL //!< Peripheral base address
#define RFSYS                          ((RFSYS_Type *) RFSYS_BasePtr) //!< Freescale base pointer
#define RFSYS_BASE_PTR                 (RFSYS) //!< Freescale style base pointer
/**
 * @} */ /* End group RFSYS_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RFVBAT_Peripheral_access_layer_GROUP RFVBAT Peripheral Access Layer
* @brief C Struct for RFVBAT
* @{
*/

/* ================================================================================ */
/* ================           RFVBAT (file:RFVBAT_0)               ================ */
/* ================================================================================ */

/**
 * @brief VBAT register file
 */
/**
* @addtogroup RFVBAT_structs_GROUP RFVBAT struct
* @brief Struct for RFVBAT
* @{
*/
typedef struct {                                /*       RFVBAT Structure                                             */
   __IO uint32_t  REG[8];                       /**< 0000: VBAT register file register                                  */
} RFVBAT_Type;

/**
 * @} */ /* End group RFVBAT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RFVBAT' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RFVBAT_Register_Masks_GROUP RFVBAT Register Masks
* @brief Register Masks for RFVBAT
* @{
*/
/* ------- REG Bit Fields                           ------ */
#define RFVBAT_REG_LL_MASK                       (0xFFU)                                             /*!< RFVBAT_REG: LL Mask                     */
#define RFVBAT_REG_LL_SHIFT                      (0U)                                                /*!< RFVBAT_REG: LL Position                 */
#define RFVBAT_REG_LL(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_LL_SHIFT))&RFVBAT_REG_LL_MASK) /*!< RFVBAT_REG                              */
#define RFVBAT_REG_LH_MASK                       (0xFF00U)                                           /*!< RFVBAT_REG: LH Mask                     */
#define RFVBAT_REG_LH_SHIFT                      (8U)                                                /*!< RFVBAT_REG: LH Position                 */
#define RFVBAT_REG_LH(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_LH_SHIFT))&RFVBAT_REG_LH_MASK) /*!< RFVBAT_REG                              */
#define RFVBAT_REG_HL_MASK                       (0xFF0000U)                                         /*!< RFVBAT_REG: HL Mask                     */
#define RFVBAT_REG_HL_SHIFT                      (16U)                                               /*!< RFVBAT_REG: HL Position                 */
#define RFVBAT_REG_HL(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_HL_SHIFT))&RFVBAT_REG_HL_MASK) /*!< RFVBAT_REG                              */
#define RFVBAT_REG_HH_MASK                       (0xFF000000U)                                       /*!< RFVBAT_REG: HH Mask                     */
#define RFVBAT_REG_HH_SHIFT                      (24U)                                               /*!< RFVBAT_REG: HH Position                 */
#define RFVBAT_REG_HH(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_HH_SHIFT))&RFVBAT_REG_HH_MASK) /*!< RFVBAT_REG                              */
/**
 * @} */ /* End group RFVBAT_Register_Masks_GROUP 
 */

/* RFVBAT - Peripheral instance base addresses */
#define RFVBAT_BasePtr                 0x4003E000UL //!< Peripheral base address
#define RFVBAT                         ((RFVBAT_Type *) RFVBAT_BasePtr) //!< Freescale base pointer
#define RFVBAT_BASE_PTR                (RFVBAT) //!< Freescale style base pointer
/**
 * @} */ /* End group RFVBAT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RNG_Peripheral_access_layer_GROUP RNG Peripheral Access Layer
* @brief C Struct for RNG
* @{
*/

/* ================================================================================ */
/* ================           RNG (file:RNG_1)                     ================ */
/* ================================================================================ */

/**
 * @brief Random Number Generator Accelerator
 */
/**
* @addtogroup RNG_structs_GROUP RNG struct
* @brief Struct for RNG
* @{
*/
typedef struct {                                /*       RNG Structure                                                */
   __IO uint32_t  CR;                           /**< 0000: RNGA Control Register                                        */
   __I  uint32_t  SR;                           /**< 0004: RNGA Status Register                                         */
   __O  uint32_t  ER;                           /**< 0008: RNGA Entropy Register                                        */
   __I  uint32_t  OR;                           /**< 000C: RNGA Output Register                                         */
} RNG_Type;

/**
 * @} */ /* End group RNG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RNG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RNG_Register_Masks_GROUP RNG Register Masks
* @brief Register Masks for RNG
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define RNG_CR_GO_MASK                           (0x1U)                                              /*!< RNG_CR: GO Mask                         */
#define RNG_CR_GO_SHIFT                          (0U)                                                /*!< RNG_CR: GO Position                     */
#define RNG_CR_GO(x)                             (((uint32_t)(((uint32_t)(x))<<RNG_CR_GO_SHIFT))&RNG_CR_GO_MASK) /*!< RNG_CR                                  */
#define RNG_CR_HA_MASK                           (0x2U)                                              /*!< RNG_CR: HA Mask                         */
#define RNG_CR_HA_SHIFT                          (1U)                                                /*!< RNG_CR: HA Position                     */
#define RNG_CR_HA(x)                             (((uint32_t)(((uint32_t)(x))<<RNG_CR_HA_SHIFT))&RNG_CR_HA_MASK) /*!< RNG_CR                                  */
#define RNG_CR_INTM_MASK                         (0x4U)                                              /*!< RNG_CR: INTM Mask                       */
#define RNG_CR_INTM_SHIFT                        (2U)                                                /*!< RNG_CR: INTM Position                   */
#define RNG_CR_INTM(x)                           (((uint32_t)(((uint32_t)(x))<<RNG_CR_INTM_SHIFT))&RNG_CR_INTM_MASK) /*!< RNG_CR                                  */
#define RNG_CR_CLRI_MASK                         (0x8U)                                              /*!< RNG_CR: CLRI Mask                       */
#define RNG_CR_CLRI_SHIFT                        (3U)                                                /*!< RNG_CR: CLRI Position                   */
#define RNG_CR_CLRI(x)                           (((uint32_t)(((uint32_t)(x))<<RNG_CR_CLRI_SHIFT))&RNG_CR_CLRI_MASK) /*!< RNG_CR                                  */
#define RNG_CR_SLP_MASK                          (0x10U)                                             /*!< RNG_CR: SLP Mask                        */
#define RNG_CR_SLP_SHIFT                         (4U)                                                /*!< RNG_CR: SLP Position                    */
#define RNG_CR_SLP(x)                            (((uint32_t)(((uint32_t)(x))<<RNG_CR_SLP_SHIFT))&RNG_CR_SLP_MASK) /*!< RNG_CR                                  */
/* ------- SR Bit Fields                            ------ */
#define RNG_SR_SECV_MASK                         (0x1U)                                              /*!< RNG_SR: SECV Mask                       */
#define RNG_SR_SECV_SHIFT                        (0U)                                                /*!< RNG_SR: SECV Position                   */
#define RNG_SR_SECV(x)                           (((uint32_t)(((uint32_t)(x))<<RNG_SR_SECV_SHIFT))&RNG_SR_SECV_MASK) /*!< RNG_SR                                  */
#define RNG_SR_LRS_MASK                          (0x2U)                                              /*!< RNG_SR: LRS Mask                        */
#define RNG_SR_LRS_SHIFT                         (1U)                                                /*!< RNG_SR: LRS Position                    */
#define RNG_SR_LRS(x)                            (((uint32_t)(((uint32_t)(x))<<RNG_SR_LRS_SHIFT))&RNG_SR_LRS_MASK) /*!< RNG_SR                                  */
#define RNG_SR_ORU_MASK                          (0x4U)                                              /*!< RNG_SR: ORU Mask                        */
#define RNG_SR_ORU_SHIFT                         (2U)                                                /*!< RNG_SR: ORU Position                    */
#define RNG_SR_ORU(x)                            (((uint32_t)(((uint32_t)(x))<<RNG_SR_ORU_SHIFT))&RNG_SR_ORU_MASK) /*!< RNG_SR                                  */
#define RNG_SR_ERRI_MASK                         (0x8U)                                              /*!< RNG_SR: ERRI Mask                       */
#define RNG_SR_ERRI_SHIFT                        (3U)                                                /*!< RNG_SR: ERRI Position                   */
#define RNG_SR_ERRI(x)                           (((uint32_t)(((uint32_t)(x))<<RNG_SR_ERRI_SHIFT))&RNG_SR_ERRI_MASK) /*!< RNG_SR                                  */
#define RNG_SR_SLP_MASK                          (0x10U)                                             /*!< RNG_SR: SLP Mask                        */
#define RNG_SR_SLP_SHIFT                         (4U)                                                /*!< RNG_SR: SLP Position                    */
#define RNG_SR_SLP(x)                            (((uint32_t)(((uint32_t)(x))<<RNG_SR_SLP_SHIFT))&RNG_SR_SLP_MASK) /*!< RNG_SR                                  */
#define RNG_SR_OREG_LVL_MASK                     (0xFF00U)                                           /*!< RNG_SR: OREG_LVL Mask                   */
#define RNG_SR_OREG_LVL_SHIFT                    (8U)                                                /*!< RNG_SR: OREG_LVL Position               */
#define RNG_SR_OREG_LVL(x)                       (((uint32_t)(((uint32_t)(x))<<RNG_SR_OREG_LVL_SHIFT))&RNG_SR_OREG_LVL_MASK) /*!< RNG_SR                                  */
#define RNG_SR_OREG_SIZE_MASK                    (0xFF0000U)                                         /*!< RNG_SR: OREG_SIZE Mask                  */
#define RNG_SR_OREG_SIZE_SHIFT                   (16U)                                               /*!< RNG_SR: OREG_SIZE Position              */
#define RNG_SR_OREG_SIZE(x)                      (((uint32_t)(((uint32_t)(x))<<RNG_SR_OREG_SIZE_SHIFT))&RNG_SR_OREG_SIZE_MASK) /*!< RNG_SR                                  */
/* ------- ER Bit Fields                            ------ */
#define RNG_ER_EXT_ENT_MASK                      (0xFFFFFFFFU)                                       /*!< RNG_ER: EXT_ENT Mask                    */
#define RNG_ER_EXT_ENT_SHIFT                     (0U)                                                /*!< RNG_ER: EXT_ENT Position                */
#define RNG_ER_EXT_ENT(x)                        (((uint32_t)(((uint32_t)(x))<<RNG_ER_EXT_ENT_SHIFT))&RNG_ER_EXT_ENT_MASK) /*!< RNG_ER                                  */
/* ------- OR Bit Fields                            ------ */
#define RNG_OR_RANDOUT_MASK                      (0xFFFFFFFFU)                                       /*!< RNG_OR: RANDOUT Mask                    */
#define RNG_OR_RANDOUT_SHIFT                     (0U)                                                /*!< RNG_OR: RANDOUT Position                */
#define RNG_OR_RANDOUT(x)                        (((uint32_t)(((uint32_t)(x))<<RNG_OR_RANDOUT_SHIFT))&RNG_OR_RANDOUT_MASK) /*!< RNG_OR                                  */
/**
 * @} */ /* End group RNG_Register_Masks_GROUP 
 */

/* RNG - Peripheral instance base addresses */
#define RNG_BasePtr                    0x40029000UL //!< Peripheral base address
#define RNG                            ((RNG_Type *) RNG_BasePtr) //!< Freescale base pointer
#define RNG_BASE_PTR                   (RNG) //!< Freescale style base pointer
/**
 * @} */ /* End group RNG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:RTC_MK11D5WS)              ================ */
/* ================================================================================ */

/**
 * @brief Secure Real Time Clock
 */
/**
* @addtogroup RTC_structs_GROUP RTC struct
* @brief Struct for RTC
* @{
*/
typedef struct {                                /*       RTC Structure                                                */
   __IO uint32_t  TSR;                          /**< 0000: Time Seconds Register                                        */
   __IO uint32_t  TPR;                          /**< 0004: Time Prescaler Register                                      */
   __IO uint32_t  TAR;                          /**< 0008: Time Alarm Register                                          */
   __IO uint32_t  TCR;                          /**< 000C: Time Compensation Register                                   */
   __IO uint32_t  CR;                           /**< 0010: Control Register                                             */
   __IO uint32_t  SR;                           /**< 0014: Status Register                                              */
   __IO uint32_t  LR;                           /**< 0018: Lock Register                                                */
   __IO uint32_t  IER;                          /**< 001C: Interrupt Enable Register                                    */
   __I  uint32_t  TTSR;                         /**< 0020: Tamper Time Seconds Register                                 */
   __IO uint32_t  MER;                          /**< 0024: Monotonic Enable Register                                    */
   __IO uint32_t  MCLR;                         /**< 0028: Monotonic Counter Low Register                               */
   __IO uint32_t  MCHR;                         /**< 002C: Monotonic Counter High Register                              */
   __IO uint32_t  TER;                          /**< 0030: Tamper Enable Register                                       */
   __IO uint32_t  TDR;                          /**< 0034: Tamper Detect Register                                       */
   __IO uint32_t  TTR;                          /**< 0038: Tamper Trim Register                                         */
   __IO uint32_t  TIR;                          /**< 003C: Tamper Interrupt Register                                    */
        uint8_t   RESERVED_0[1984];            
   __IO uint32_t  WAR;                          /**< 0800: Write Access Register                                        */
   __IO uint32_t  RAR;                          /**< 0804: Read Access Register                                         */
} RTC_Type;

/**
 * @} */ /* End group RTC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RTC_Register_Masks_GROUP RTC Register Masks
* @brief Register Masks for RTC
* @{
*/
/* ------- TSR Bit Fields                           ------ */
#define RTC_TSR_TSR_MASK                         (0xFFFFFFFFU)                                       /*!< RTC_TSR: TSR Mask                       */
#define RTC_TSR_TSR_SHIFT                        (0U)                                                /*!< RTC_TSR: TSR Position                   */
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK) /*!< RTC_TSR                                 */
/* ------- TPR Bit Fields                           ------ */
#define RTC_TPR_TPR_MASK                         (0xFFFFU)                                           /*!< RTC_TPR: TPR Mask                       */
#define RTC_TPR_TPR_SHIFT                        (0U)                                                /*!< RTC_TPR: TPR Position                   */
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK) /*!< RTC_TPR                                 */
/* ------- TAR Bit Fields                           ------ */
#define RTC_TAR_TAR_MASK                         (0xFFFFFFFFU)                                       /*!< RTC_TAR: TAR Mask                       */
#define RTC_TAR_TAR_SHIFT                        (0U)                                                /*!< RTC_TAR: TAR Position                   */
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK) /*!< RTC_TAR                                 */
/* ------- TCR Bit Fields                           ------ */
#define RTC_TCR_TCR_MASK                         (0xFFU)                                             /*!< RTC_TCR: TCR Mask                       */
#define RTC_TCR_TCR_SHIFT                        (0U)                                                /*!< RTC_TCR: TCR Position                   */
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_CIR_MASK                         (0xFF00U)                                           /*!< RTC_TCR: CIR Mask                       */
#define RTC_TCR_CIR_SHIFT                        (8U)                                                /*!< RTC_TCR: CIR Position                   */
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_TCV_MASK                         (0xFF0000U)                                         /*!< RTC_TCR: TCV Mask                       */
#define RTC_TCR_TCV_SHIFT                        (16U)                                               /*!< RTC_TCR: TCV Position                   */
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_CIC_MASK                         (0xFF000000U)                                       /*!< RTC_TCR: CIC Mask                       */
#define RTC_TCR_CIC_SHIFT                        (24U)                                               /*!< RTC_TCR: CIC Position                   */
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK) /*!< RTC_TCR                                 */
/* ------- CR Bit Fields                            ------ */
#define RTC_CR_SWR_MASK                          (0x1U)                                              /*!< RTC_CR: SWR Mask                        */
#define RTC_CR_SWR_SHIFT                         (0U)                                                /*!< RTC_CR: SWR Position                    */
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SWR_SHIFT))&RTC_CR_SWR_MASK) /*!< RTC_CR                                  */
#define RTC_CR_WPE_MASK                          (0x2U)                                              /*!< RTC_CR: WPE Mask                        */
#define RTC_CR_WPE_SHIFT                         (1U)                                                /*!< RTC_CR: WPE Position                    */
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPE_SHIFT))&RTC_CR_WPE_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SUP_MASK                          (0x4U)                                              /*!< RTC_CR: SUP Mask                        */
#define RTC_CR_SUP_SHIFT                         (2U)                                                /*!< RTC_CR: SUP Position                    */
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SUP_SHIFT))&RTC_CR_SUP_MASK) /*!< RTC_CR                                  */
#define RTC_CR_UM_MASK                           (0x8U)                                              /*!< RTC_CR: UM Mask                         */
#define RTC_CR_UM_SHIFT                          (3U)                                                /*!< RTC_CR: UM Position                     */
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_CR_UM_SHIFT))&RTC_CR_UM_MASK) /*!< RTC_CR                                  */
#define RTC_CR_OSCE_MASK                         (0x100U)                                            /*!< RTC_CR: OSCE Mask                       */
#define RTC_CR_OSCE_SHIFT                        (8U)                                                /*!< RTC_CR: OSCE Position                   */
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_OSCE_SHIFT))&RTC_CR_OSCE_MASK) /*!< RTC_CR                                  */
#define RTC_CR_CLKO_MASK                         (0x200U)                                            /*!< RTC_CR: CLKO Mask                       */
#define RTC_CR_CLKO_SHIFT                        (9U)                                                /*!< RTC_CR: CLKO Position                   */
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_CLKO_SHIFT))&RTC_CR_CLKO_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SCP_MASK                          (0x3C00U)                                           /*!< RTC_CR: SCP Mask                        */
#define RTC_CR_SCP_SHIFT                         (10U)                                               /*!< RTC_CR: SCP Position                    */
#define RTC_CR_SCP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SCP_SHIFT))&RTC_CR_SCP_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC16P_MASK                        (0x400U)                                            /*!< RTC_CR: SC16P Mask                      */
#define RTC_CR_SC16P_SHIFT                       (10U)                                               /*!< RTC_CR: SC16P Position                  */
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC16P_SHIFT))&RTC_CR_SC16P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC8P_MASK                         (0x800U)                                            /*!< RTC_CR: SC8P Mask                       */
#define RTC_CR_SC8P_SHIFT                        (11U)                                               /*!< RTC_CR: SC8P Position                   */
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC8P_SHIFT))&RTC_CR_SC8P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC4P_MASK                         (0x1000U)                                           /*!< RTC_CR: SC4P Mask                       */
#define RTC_CR_SC4P_SHIFT                        (12U)                                               /*!< RTC_CR: SC4P Position                   */
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC4P_SHIFT))&RTC_CR_SC4P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC2P_MASK                         (0x2000U)                                           /*!< RTC_CR: SC2P Mask                       */
#define RTC_CR_SC2P_SHIFT                        (13U)                                               /*!< RTC_CR: SC2P Position                   */
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC2P_SHIFT))&RTC_CR_SC2P_MASK) /*!< RTC_CR                                  */
/* ------- SR Bit Fields                            ------ */
#define RTC_SR_TIF_MASK                          (0x1U)                                              /*!< RTC_SR: TIF Mask                        */
#define RTC_SR_TIF_SHIFT                         (0U)                                                /*!< RTC_SR: TIF Position                    */
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TIF_SHIFT))&RTC_SR_TIF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TOF_MASK                          (0x2U)                                              /*!< RTC_SR: TOF Mask                        */
#define RTC_SR_TOF_SHIFT                         (1U)                                                /*!< RTC_SR: TOF Position                    */
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TOF_SHIFT))&RTC_SR_TOF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TAF_MASK                          (0x4U)                                              /*!< RTC_SR: TAF Mask                        */
#define RTC_SR_TAF_SHIFT                         (2U)                                                /*!< RTC_SR: TAF Position                    */
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TAF_SHIFT))&RTC_SR_TAF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_MOF_MASK                          (0x8U)                                              /*!< RTC_SR: MOF Mask                        */
#define RTC_SR_MOF_SHIFT                         (3U)                                                /*!< RTC_SR: MOF Position                    */
#define RTC_SR_MOF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_MOF_SHIFT))&RTC_SR_MOF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TCE_MASK                          (0x10U)                                             /*!< RTC_SR: TCE Mask                        */
#define RTC_SR_TCE_SHIFT                         (4U)                                                /*!< RTC_SR: TCE Position                    */
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TCE_SHIFT))&RTC_SR_TCE_MASK) /*!< RTC_SR                                  */
/* ------- LR Bit Fields                            ------ */
#define RTC_LR_TCL_MASK                          (0x8U)                                              /*!< RTC_LR: TCL Mask                        */
#define RTC_LR_TCL_SHIFT                         (3U)                                                /*!< RTC_LR: TCL Position                    */
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TCL_SHIFT))&RTC_LR_TCL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_CRL_MASK                          (0x10U)                                             /*!< RTC_LR: CRL Mask                        */
#define RTC_LR_CRL_SHIFT                         (4U)                                                /*!< RTC_LR: CRL Position                    */
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_CRL_SHIFT))&RTC_LR_CRL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_SRL_MASK                          (0x20U)                                             /*!< RTC_LR: SRL Mask                        */
#define RTC_LR_SRL_SHIFT                         (5U)                                                /*!< RTC_LR: SRL Position                    */
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_SRL_SHIFT))&RTC_LR_SRL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_LRL_MASK                          (0x40U)                                             /*!< RTC_LR: LRL Mask                        */
#define RTC_LR_LRL_SHIFT                         (6U)                                                /*!< RTC_LR: LRL Position                    */
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_LRL_SHIFT))&RTC_LR_LRL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_TTSL_MASK                         (0x100U)                                            /*!< RTC_LR: TTSL Mask                       */
#define RTC_LR_TTSL_SHIFT                        (8U)                                                /*!< RTC_LR: TTSL Position                   */
#define RTC_LR_TTSL(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_LR_TTSL_SHIFT))&RTC_LR_TTSL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_MEL_MASK                          (0x200U)                                            /*!< RTC_LR: MEL Mask                        */
#define RTC_LR_MEL_SHIFT                         (9U)                                                /*!< RTC_LR: MEL Position                    */
#define RTC_LR_MEL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_MEL_SHIFT))&RTC_LR_MEL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_MCLL_MASK                         (0x400U)                                            /*!< RTC_LR: MCLL Mask                       */
#define RTC_LR_MCLL_SHIFT                        (10U)                                               /*!< RTC_LR: MCLL Position                   */
#define RTC_LR_MCLL(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_LR_MCLL_SHIFT))&RTC_LR_MCLL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_MCHL_MASK                         (0x800U)                                            /*!< RTC_LR: MCHL Mask                       */
#define RTC_LR_MCHL_SHIFT                        (11U)                                               /*!< RTC_LR: MCHL Position                   */
#define RTC_LR_MCHL(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_LR_MCHL_SHIFT))&RTC_LR_MCHL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_TEL_MASK                          (0x1000U)                                           /*!< RTC_LR: TEL Mask                        */
#define RTC_LR_TEL_SHIFT                         (12U)                                               /*!< RTC_LR: TEL Position                    */
#define RTC_LR_TEL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TEL_SHIFT))&RTC_LR_TEL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_TDL_MASK                          (0x2000U)                                           /*!< RTC_LR: TDL Mask                        */
#define RTC_LR_TDL_SHIFT                         (13U)                                               /*!< RTC_LR: TDL Position                    */
#define RTC_LR_TDL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TDL_SHIFT))&RTC_LR_TDL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_TTL_MASK                          (0x4000U)                                           /*!< RTC_LR: TTL Mask                        */
#define RTC_LR_TTL_SHIFT                         (14U)                                               /*!< RTC_LR: TTL Position                    */
#define RTC_LR_TTL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TTL_SHIFT))&RTC_LR_TTL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_TIL_MASK                          (0x8000U)                                           /*!< RTC_LR: TIL Mask                        */
#define RTC_LR_TIL_SHIFT                         (15U)                                               /*!< RTC_LR: TIL Position                    */
#define RTC_LR_TIL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TIL_SHIFT))&RTC_LR_TIL_MASK) /*!< RTC_LR                                  */
/* ------- IER Bit Fields                           ------ */
#define RTC_IER_TIIE_MASK                        (0x1U)                                              /*!< RTC_IER: TIIE Mask                      */
#define RTC_IER_TIIE_SHIFT                       (0U)                                                /*!< RTC_IER: TIIE Position                  */
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TIIE_SHIFT))&RTC_IER_TIIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TOIE_MASK                        (0x2U)                                              /*!< RTC_IER: TOIE Mask                      */
#define RTC_IER_TOIE_SHIFT                       (1U)                                                /*!< RTC_IER: TOIE Position                  */
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TOIE_SHIFT))&RTC_IER_TOIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TAIE_MASK                        (0x4U)                                              /*!< RTC_IER: TAIE Mask                      */
#define RTC_IER_TAIE_SHIFT                       (2U)                                                /*!< RTC_IER: TAIE Position                  */
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TAIE_SHIFT))&RTC_IER_TAIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_MOIE_MASK                        (0x8U)                                              /*!< RTC_IER: MOIE Mask                      */
#define RTC_IER_MOIE_SHIFT                       (3U)                                                /*!< RTC_IER: MOIE Position                  */
#define RTC_IER_MOIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_MOIE_SHIFT))&RTC_IER_MOIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TSIE_MASK                        (0x10U)                                             /*!< RTC_IER: TSIE Mask                      */
#define RTC_IER_TSIE_SHIFT                       (4U)                                                /*!< RTC_IER: TSIE Position                  */
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TSIE_SHIFT))&RTC_IER_TSIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_WPON_MASK                        (0x80U)                                             /*!< RTC_IER: WPON Mask                      */
#define RTC_IER_WPON_SHIFT                       (7U)                                                /*!< RTC_IER: WPON Position                  */
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_WPON_SHIFT))&RTC_IER_WPON_MASK) /*!< RTC_IER                                 */
/* ------- TTSR Bit Fields                          ------ */
#define RTC_TTSR_TTS_MASK                        (0xFFFFFFFFU)                                       /*!< RTC_TTSR: TTS Mask                      */
#define RTC_TTSR_TTS_SHIFT                       (0U)                                                /*!< RTC_TTSR: TTS Position                  */
#define RTC_TTSR_TTS(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TTSR_TTS_SHIFT))&RTC_TTSR_TTS_MASK) /*!< RTC_TTSR                                */
/* ------- MER Bit Fields                           ------ */
#define RTC_MER_MCE_MASK                         (0x10U)                                             /*!< RTC_MER: MCE Mask                       */
#define RTC_MER_MCE_SHIFT                        (4U)                                                /*!< RTC_MER: MCE Position                   */
#define RTC_MER_MCE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_MER_MCE_SHIFT))&RTC_MER_MCE_MASK) /*!< RTC_MER                                 */
/* ------- MCLR Bit Fields                          ------ */
#define RTC_MCLR_MCL_MASK                        (0xFFFFFFFFU)                                       /*!< RTC_MCLR: MCL Mask                      */
#define RTC_MCLR_MCL_SHIFT                       (0U)                                                /*!< RTC_MCLR: MCL Position                  */
#define RTC_MCLR_MCL(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_MCLR_MCL_SHIFT))&RTC_MCLR_MCL_MASK) /*!< RTC_MCLR                                */
/* ------- MCHR Bit Fields                          ------ */
#define RTC_MCHR_MCH_MASK                        (0xFFFFFFFFU)                                       /*!< RTC_MCHR: MCH Mask                      */
#define RTC_MCHR_MCH_SHIFT                       (0U)                                                /*!< RTC_MCHR: MCH Position                  */
#define RTC_MCHR_MCH(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_MCHR_MCH_SHIFT))&RTC_MCHR_MCH_MASK) /*!< RTC_MCHR                                */
/* ------- TER Bit Fields                           ------ */
#define RTC_TER_DTE_MASK                         (0x1U)                                              /*!< RTC_TER: DTE Mask                       */
#define RTC_TER_DTE_SHIFT                        (0U)                                                /*!< RTC_TER: DTE Position                   */
#define RTC_TER_DTE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TER_DTE_SHIFT))&RTC_TER_DTE_MASK) /*!< RTC_TER                                 */
#define RTC_TER_VTE_MASK                         (0x2U)                                              /*!< RTC_TER: VTE Mask                       */
#define RTC_TER_VTE_SHIFT                        (1U)                                                /*!< RTC_TER: VTE Position                   */
#define RTC_TER_VTE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TER_VTE_SHIFT))&RTC_TER_VTE_MASK) /*!< RTC_TER                                 */
#define RTC_TER_CTE_MASK                         (0x4U)                                              /*!< RTC_TER: CTE Mask                       */
#define RTC_TER_CTE_SHIFT                        (2U)                                                /*!< RTC_TER: CTE Position                   */
#define RTC_TER_CTE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TER_CTE_SHIFT))&RTC_TER_CTE_MASK) /*!< RTC_TER                                 */
#define RTC_TER_TTE_MASK                         (0x8U)                                              /*!< RTC_TER: TTE Mask                       */
#define RTC_TER_TTE_SHIFT                        (3U)                                                /*!< RTC_TER: TTE Position                   */
#define RTC_TER_TTE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TER_TTE_SHIFT))&RTC_TER_TTE_MASK) /*!< RTC_TER                                 */
#define RTC_TER_FSE_MASK                         (0x10U)                                             /*!< RTC_TER: FSE Mask                       */
#define RTC_TER_FSE_SHIFT                        (4U)                                                /*!< RTC_TER: FSE Position                   */
#define RTC_TER_FSE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TER_FSE_SHIFT))&RTC_TER_FSE_MASK) /*!< RTC_TER                                 */
#define RTC_TER_TME_MASK                         (0x20U)                                             /*!< RTC_TER: TME Mask                       */
#define RTC_TER_TME_SHIFT                        (5U)                                                /*!< RTC_TER: TME Position                   */
#define RTC_TER_TME(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TER_TME_SHIFT))&RTC_TER_TME_MASK) /*!< RTC_TER                                 */
/* ------- TDR Bit Fields                           ------ */
#define RTC_TDR_DTF_MASK                         (0x1U)                                              /*!< RTC_TDR: DTF Mask                       */
#define RTC_TDR_DTF_SHIFT                        (0U)                                                /*!< RTC_TDR: DTF Position                   */
#define RTC_TDR_DTF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TDR_DTF_SHIFT))&RTC_TDR_DTF_MASK) /*!< RTC_TDR                                 */
#define RTC_TDR_VTF_MASK                         (0x2U)                                              /*!< RTC_TDR: VTF Mask                       */
#define RTC_TDR_VTF_SHIFT                        (1U)                                                /*!< RTC_TDR: VTF Position                   */
#define RTC_TDR_VTF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TDR_VTF_SHIFT))&RTC_TDR_VTF_MASK) /*!< RTC_TDR                                 */
#define RTC_TDR_CTF_MASK                         (0x4U)                                              /*!< RTC_TDR: CTF Mask                       */
#define RTC_TDR_CTF_SHIFT                        (2U)                                                /*!< RTC_TDR: CTF Position                   */
#define RTC_TDR_CTF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TDR_CTF_SHIFT))&RTC_TDR_CTF_MASK) /*!< RTC_TDR                                 */
#define RTC_TDR_TTF_MASK                         (0x8U)                                              /*!< RTC_TDR: TTF Mask                       */
#define RTC_TDR_TTF_SHIFT                        (3U)                                                /*!< RTC_TDR: TTF Position                   */
#define RTC_TDR_TTF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TDR_TTF_SHIFT))&RTC_TDR_TTF_MASK) /*!< RTC_TDR                                 */
#define RTC_TDR_FSF_MASK                         (0x10U)                                             /*!< RTC_TDR: FSF Mask                       */
#define RTC_TDR_FSF_SHIFT                        (4U)                                                /*!< RTC_TDR: FSF Position                   */
#define RTC_TDR_FSF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TDR_FSF_SHIFT))&RTC_TDR_FSF_MASK) /*!< RTC_TDR                                 */
#define RTC_TDR_TMF_MASK                         (0x20U)                                             /*!< RTC_TDR: TMF Mask                       */
#define RTC_TDR_TMF_SHIFT                        (5U)                                                /*!< RTC_TDR: TMF Position                   */
#define RTC_TDR_TMF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TDR_TMF_SHIFT))&RTC_TDR_TMF_MASK) /*!< RTC_TDR                                 */
/* ------- TTR Bit Fields                           ------ */
#define RTC_TTR_VDTL_MASK                        (0x7U)                                              /*!< RTC_TTR: VDTL Mask                      */
#define RTC_TTR_VDTL_SHIFT                       (0U)                                                /*!< RTC_TTR: VDTL Position                  */
#define RTC_TTR_VDTL(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TTR_VDTL_SHIFT))&RTC_TTR_VDTL_MASK) /*!< RTC_TTR                                 */
#define RTC_TTR_VDTH_MASK                        (0x38U)                                             /*!< RTC_TTR: VDTH Mask                      */
#define RTC_TTR_VDTH_SHIFT                       (3U)                                                /*!< RTC_TTR: VDTH Position                  */
#define RTC_TTR_VDTH(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TTR_VDTH_SHIFT))&RTC_TTR_VDTH_MASK) /*!< RTC_TTR                                 */
#define RTC_TTR_CDTL_MASK                        (0x1C0U)                                            /*!< RTC_TTR: CDTL Mask                      */
#define RTC_TTR_CDTL_SHIFT                       (6U)                                                /*!< RTC_TTR: CDTL Position                  */
#define RTC_TTR_CDTL(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TTR_CDTL_SHIFT))&RTC_TTR_CDTL_MASK) /*!< RTC_TTR                                 */
#define RTC_TTR_CDTH_MASK                        (0xE00U)                                            /*!< RTC_TTR: CDTH Mask                      */
#define RTC_TTR_CDTH_SHIFT                       (9U)                                                /*!< RTC_TTR: CDTH Position                  */
#define RTC_TTR_CDTH(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TTR_CDTH_SHIFT))&RTC_TTR_CDTH_MASK) /*!< RTC_TTR                                 */
#define RTC_TTR_TDTH_MASK                        (0x7000U)                                           /*!< RTC_TTR: TDTH Mask                      */
#define RTC_TTR_TDTH_SHIFT                       (12U)                                               /*!< RTC_TTR: TDTH Position                  */
#define RTC_TTR_TDTH(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TTR_TDTH_SHIFT))&RTC_TTR_TDTH_MASK) /*!< RTC_TTR                                 */
#define RTC_TTR_TDTL_MASK                        (0x38000U)                                          /*!< RTC_TTR: TDTL Mask                      */
#define RTC_TTR_TDTL_SHIFT                       (15U)                                               /*!< RTC_TTR: TDTL Position                  */
#define RTC_TTR_TDTL(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TTR_TDTL_SHIFT))&RTC_TTR_TDTL_MASK) /*!< RTC_TTR                                 */
/* ------- TIR Bit Fields                           ------ */
#define RTC_TIR_DTIE_MASK                        (0x1U)                                              /*!< RTC_TIR: DTIE Mask                      */
#define RTC_TIR_DTIE_SHIFT                       (0U)                                                /*!< RTC_TIR: DTIE Position                  */
#define RTC_TIR_DTIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TIR_DTIE_SHIFT))&RTC_TIR_DTIE_MASK) /*!< RTC_TIR                                 */
#define RTC_TIR_VTIE_MASK                        (0x2U)                                              /*!< RTC_TIR: VTIE Mask                      */
#define RTC_TIR_VTIE_SHIFT                       (1U)                                                /*!< RTC_TIR: VTIE Position                  */
#define RTC_TIR_VTIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TIR_VTIE_SHIFT))&RTC_TIR_VTIE_MASK) /*!< RTC_TIR                                 */
#define RTC_TIR_CTIE_MASK                        (0x4U)                                              /*!< RTC_TIR: CTIE Mask                      */
#define RTC_TIR_CTIE_SHIFT                       (2U)                                                /*!< RTC_TIR: CTIE Position                  */
#define RTC_TIR_CTIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TIR_CTIE_SHIFT))&RTC_TIR_CTIE_MASK) /*!< RTC_TIR                                 */
#define RTC_TIR_TTIE_MASK                        (0x8U)                                              /*!< RTC_TIR: TTIE Mask                      */
#define RTC_TIR_TTIE_SHIFT                       (3U)                                                /*!< RTC_TIR: TTIE Position                  */
#define RTC_TIR_TTIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TIR_TTIE_SHIFT))&RTC_TIR_TTIE_MASK) /*!< RTC_TIR                                 */
#define RTC_TIR_FSIE_MASK                        (0x10U)                                             /*!< RTC_TIR: FSIE Mask                      */
#define RTC_TIR_FSIE_SHIFT                       (4U)                                                /*!< RTC_TIR: FSIE Position                  */
#define RTC_TIR_FSIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TIR_FSIE_SHIFT))&RTC_TIR_FSIE_MASK) /*!< RTC_TIR                                 */
#define RTC_TIR_TMIE_MASK                        (0x20U)                                             /*!< RTC_TIR: TMIE Mask                      */
#define RTC_TIR_TMIE_SHIFT                       (5U)                                                /*!< RTC_TIR: TMIE Position                  */
#define RTC_TIR_TMIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TIR_TMIE_SHIFT))&RTC_TIR_TMIE_MASK) /*!< RTC_TIR                                 */
/* ------- WAR Bit Fields                           ------ */
#define RTC_WAR_TSRW_MASK                        (0x1U)                                              /*!< RTC_WAR: TSRW Mask                      */
#define RTC_WAR_TSRW_SHIFT                       (0U)                                                /*!< RTC_WAR: TSRW Position                  */
#define RTC_WAR_TSRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TSRW_SHIFT))&RTC_WAR_TSRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TPRW_MASK                        (0x2U)                                              /*!< RTC_WAR: TPRW Mask                      */
#define RTC_WAR_TPRW_SHIFT                       (1U)                                                /*!< RTC_WAR: TPRW Position                  */
#define RTC_WAR_TPRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TPRW_SHIFT))&RTC_WAR_TPRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TARW_MASK                        (0x4U)                                              /*!< RTC_WAR: TARW Mask                      */
#define RTC_WAR_TARW_SHIFT                       (2U)                                                /*!< RTC_WAR: TARW Position                  */
#define RTC_WAR_TARW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TARW_SHIFT))&RTC_WAR_TARW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TCRW_MASK                        (0x8U)                                              /*!< RTC_WAR: TCRW Mask                      */
#define RTC_WAR_TCRW_SHIFT                       (3U)                                                /*!< RTC_WAR: TCRW Position                  */
#define RTC_WAR_TCRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TCRW_SHIFT))&RTC_WAR_TCRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_CRW_MASK                         (0x10U)                                             /*!< RTC_WAR: CRW Mask                       */
#define RTC_WAR_CRW_SHIFT                        (4U)                                                /*!< RTC_WAR: CRW Position                   */
#define RTC_WAR_CRW(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_WAR_CRW_SHIFT))&RTC_WAR_CRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_SRW_MASK                         (0x20U)                                             /*!< RTC_WAR: SRW Mask                       */
#define RTC_WAR_SRW_SHIFT                        (5U)                                                /*!< RTC_WAR: SRW Position                   */
#define RTC_WAR_SRW(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_WAR_SRW_SHIFT))&RTC_WAR_SRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_LRW_MASK                         (0x40U)                                             /*!< RTC_WAR: LRW Mask                       */
#define RTC_WAR_LRW_SHIFT                        (6U)                                                /*!< RTC_WAR: LRW Position                   */
#define RTC_WAR_LRW(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_WAR_LRW_SHIFT))&RTC_WAR_LRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_IERW_MASK                        (0x80U)                                             /*!< RTC_WAR: IERW Mask                      */
#define RTC_WAR_IERW_SHIFT                       (7U)                                                /*!< RTC_WAR: IERW Position                  */
#define RTC_WAR_IERW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_IERW_SHIFT))&RTC_WAR_IERW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TTSW_MASK                        (0x100U)                                            /*!< RTC_WAR: TTSW Mask                      */
#define RTC_WAR_TTSW_SHIFT                       (8U)                                                /*!< RTC_WAR: TTSW Position                  */
#define RTC_WAR_TTSW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TTSW_SHIFT))&RTC_WAR_TTSW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_MERW_MASK                        (0x200U)                                            /*!< RTC_WAR: MERW Mask                      */
#define RTC_WAR_MERW_SHIFT                       (9U)                                                /*!< RTC_WAR: MERW Position                  */
#define RTC_WAR_MERW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_MERW_SHIFT))&RTC_WAR_MERW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_MCLW_MASK                        (0x400U)                                            /*!< RTC_WAR: MCLW Mask                      */
#define RTC_WAR_MCLW_SHIFT                       (10U)                                               /*!< RTC_WAR: MCLW Position                  */
#define RTC_WAR_MCLW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_MCLW_SHIFT))&RTC_WAR_MCLW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_MCHW_MASK                        (0x800U)                                            /*!< RTC_WAR: MCHW Mask                      */
#define RTC_WAR_MCHW_SHIFT                       (11U)                                               /*!< RTC_WAR: MCHW Position                  */
#define RTC_WAR_MCHW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_MCHW_SHIFT))&RTC_WAR_MCHW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TERW_MASK                        (0x1000U)                                           /*!< RTC_WAR: TERW Mask                      */
#define RTC_WAR_TERW_SHIFT                       (12U)                                               /*!< RTC_WAR: TERW Position                  */
#define RTC_WAR_TERW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TERW_SHIFT))&RTC_WAR_TERW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TDRW_MASK                        (0x2000U)                                           /*!< RTC_WAR: TDRW Mask                      */
#define RTC_WAR_TDRW_SHIFT                       (13U)                                               /*!< RTC_WAR: TDRW Position                  */
#define RTC_WAR_TDRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TDRW_SHIFT))&RTC_WAR_TDRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TTRW_MASK                        (0x4000U)                                           /*!< RTC_WAR: TTRW Mask                      */
#define RTC_WAR_TTRW_SHIFT                       (14U)                                               /*!< RTC_WAR: TTRW Position                  */
#define RTC_WAR_TTRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TTRW_SHIFT))&RTC_WAR_TTRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TIRW_MASK                        (0x8000U)                                           /*!< RTC_WAR: TIRW Mask                      */
#define RTC_WAR_TIRW_SHIFT                       (15U)                                               /*!< RTC_WAR: TIRW Position                  */
#define RTC_WAR_TIRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TIRW_SHIFT))&RTC_WAR_TIRW_MASK) /*!< RTC_WAR                                 */
/* ------- RAR Bit Fields                           ------ */
#define RTC_RAR_TSRR_MASK                        (0x1U)                                              /*!< RTC_RAR: TSRR Mask                      */
#define RTC_RAR_TSRR_SHIFT                       (0U)                                                /*!< RTC_RAR: TSRR Position                  */
#define RTC_RAR_TSRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TSRR_SHIFT))&RTC_RAR_TSRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TPRR_MASK                        (0x2U)                                              /*!< RTC_RAR: TPRR Mask                      */
#define RTC_RAR_TPRR_SHIFT                       (1U)                                                /*!< RTC_RAR: TPRR Position                  */
#define RTC_RAR_TPRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TPRR_SHIFT))&RTC_RAR_TPRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TARR_MASK                        (0x4U)                                              /*!< RTC_RAR: TARR Mask                      */
#define RTC_RAR_TARR_SHIFT                       (2U)                                                /*!< RTC_RAR: TARR Position                  */
#define RTC_RAR_TARR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TARR_SHIFT))&RTC_RAR_TARR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TCRR_MASK                        (0x8U)                                              /*!< RTC_RAR: TCRR Mask                      */
#define RTC_RAR_TCRR_SHIFT                       (3U)                                                /*!< RTC_RAR: TCRR Position                  */
#define RTC_RAR_TCRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TCRR_SHIFT))&RTC_RAR_TCRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_CRR_MASK                         (0x10U)                                             /*!< RTC_RAR: CRR Mask                       */
#define RTC_RAR_CRR_SHIFT                        (4U)                                                /*!< RTC_RAR: CRR Position                   */
#define RTC_RAR_CRR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_RAR_CRR_SHIFT))&RTC_RAR_CRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_SRR_MASK                         (0x20U)                                             /*!< RTC_RAR: SRR Mask                       */
#define RTC_RAR_SRR_SHIFT                        (5U)                                                /*!< RTC_RAR: SRR Position                   */
#define RTC_RAR_SRR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_RAR_SRR_SHIFT))&RTC_RAR_SRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_LRR_MASK                         (0x40U)                                             /*!< RTC_RAR: LRR Mask                       */
#define RTC_RAR_LRR_SHIFT                        (6U)                                                /*!< RTC_RAR: LRR Position                   */
#define RTC_RAR_LRR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_RAR_LRR_SHIFT))&RTC_RAR_LRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_IERR_MASK                        (0x80U)                                             /*!< RTC_RAR: IERR Mask                      */
#define RTC_RAR_IERR_SHIFT                       (7U)                                                /*!< RTC_RAR: IERR Position                  */
#define RTC_RAR_IERR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_IERR_SHIFT))&RTC_RAR_IERR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TTSR_MASK                        (0x100U)                                            /*!< RTC_RAR: TTSR Mask                      */
#define RTC_RAR_TTSR_SHIFT                       (8U)                                                /*!< RTC_RAR: TTSR Position                  */
#define RTC_RAR_TTSR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TTSR_SHIFT))&RTC_RAR_TTSR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_MERR_MASK                        (0x200U)                                            /*!< RTC_RAR: MERR Mask                      */
#define RTC_RAR_MERR_SHIFT                       (9U)                                                /*!< RTC_RAR: MERR Position                  */
#define RTC_RAR_MERR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_MERR_SHIFT))&RTC_RAR_MERR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_MCLR_MASK                        (0x400U)                                            /*!< RTC_RAR: MCLR Mask                      */
#define RTC_RAR_MCLR_SHIFT                       (10U)                                               /*!< RTC_RAR: MCLR Position                  */
#define RTC_RAR_MCLR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_MCLR_SHIFT))&RTC_RAR_MCLR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_MCHR_MASK                        (0x800U)                                            /*!< RTC_RAR: MCHR Mask                      */
#define RTC_RAR_MCHR_SHIFT                       (11U)                                               /*!< RTC_RAR: MCHR Position                  */
#define RTC_RAR_MCHR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_MCHR_SHIFT))&RTC_RAR_MCHR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TERR_MASK                        (0x1000U)                                           /*!< RTC_RAR: TERR Mask                      */
#define RTC_RAR_TERR_SHIFT                       (12U)                                               /*!< RTC_RAR: TERR Position                  */
#define RTC_RAR_TERR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TERR_SHIFT))&RTC_RAR_TERR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TDRR_MASK                        (0x2000U)                                           /*!< RTC_RAR: TDRR Mask                      */
#define RTC_RAR_TDRR_SHIFT                       (13U)                                               /*!< RTC_RAR: TDRR Position                  */
#define RTC_RAR_TDRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TDRR_SHIFT))&RTC_RAR_TDRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TTRR_MASK                        (0x4000U)                                           /*!< RTC_RAR: TTRR Mask                      */
#define RTC_RAR_TTRR_SHIFT                       (14U)                                               /*!< RTC_RAR: TTRR Position                  */
#define RTC_RAR_TTRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TTRR_SHIFT))&RTC_RAR_TTRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TIRR_MASK                        (0x8000U)                                           /*!< RTC_RAR: TIRR Mask                      */
#define RTC_RAR_TIRR_SHIFT                       (15U)                                               /*!< RTC_RAR: TIRR Position                  */
#define RTC_RAR_TIRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TIRR_SHIFT))&RTC_RAR_TIRR_MASK) /*!< RTC_RAR                                 */
/**
 * @} */ /* End group RTC_Register_Masks_GROUP 
 */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x4003D000UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
/**
 * @} */ /* End group RTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer
* @brief C Struct for SIM
* @{
*/

/* ================================================================================ */
/* ================           SIM (file:SIM_MK11D5WS)              ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
* @addtogroup SIM_structs_GROUP SIM struct
* @brief Struct for SIM
* @{
*/
typedef struct {                                /*       SIM Structure                                                */
   __IO uint32_t  SOPT1;                        /**< 0000: System Options Register 1                                    */
        uint8_t   RESERVED_0[4096];            
   __IO uint32_t  SOPT2;                        /**< 1004: System Options Register 2                                    */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  SOPT4;                        /**< 100C: System Options Register 4                                    */
   __IO uint32_t  SOPT5;                        /**< 1010: System Options Register 5                                    */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  SOPT7;                        /**< 1018: System Options Register 7                                    */
        uint8_t   RESERVED_3[8];               
   __I  uint32_t  SDID;                         /**< 1024: System Device Identification Register                        */
        uint8_t   RESERVED_4[12];              
   __IO uint32_t  SCGC4;                        /**< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /**< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
   __I  uint32_t  CLKDIV2;                      /**< 1048: System Clock Divider Register 2                              */
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
   __I  uint32_t  UIDH;                         /**< 1054: Unique Identification Register High                          */
   __I  uint32_t  UIDMH;                        /**< 1058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 105C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 1060: Unique Identification Register Low                           */
} SIM_Type;

/**
 * @} */ /* End group SIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SIM_Register_Masks_GROUP SIM Register Masks
* @brief Register Masks for SIM
* @{
*/
/* ------- SOPT1 Bit Fields                         ------ */
#define SIM_SOPT1_RAMSIZE_MASK                   (0xF000U)                                           /*!< SIM_SOPT1: RAMSIZE Mask                 */
#define SIM_SOPT1_RAMSIZE_SHIFT                  (12U)                                               /*!< SIM_SOPT1: RAMSIZE Position             */
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_RAMSIZE_SHIFT))&SIM_SOPT1_RAMSIZE_MASK) /*!< SIM_SOPT1                               */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)                                          /*!< SIM_SOPT1: OSC32KSEL Mask               */
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)                                               /*!< SIM_SOPT1: OSC32KSEL Position           */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK) /*!< SIM_SOPT1                               */
/* ------- SOPT2 Bit Fields                         ------ */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              (0x10U)                                             /*!< SIM_SOPT2: RTCCLKOUTSEL Mask            */
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             (4U)                                                /*!< SIM_SOPT2: RTCCLKOUTSEL Position        */
#define SIM_SOPT2_RTCCLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_RTCCLKOUTSEL_SHIFT))&SIM_SOPT2_RTCCLKOUTSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)                                             /*!< SIM_SOPT2: CLKOUTSEL Mask               */
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)                                                /*!< SIM_SOPT2: CLKOUTSEL Position           */
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_PTD7PAD_MASK                   (0x800U)                                            /*!< SIM_SOPT2: PTD7PAD Mask                 */
#define SIM_SOPT2_PTD7PAD_SHIFT                  (11U)                                               /*!< SIM_SOPT2: PTD7PAD Position             */
#define SIM_SOPT2_PTD7PAD(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_PTD7PAD_SHIFT))&SIM_SOPT2_PTD7PAD_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_TRACECLKSEL_MASK               (0x1000U)                                           /*!< SIM_SOPT2: TRACECLKSEL Mask             */
#define SIM_SOPT2_TRACECLKSEL_SHIFT              (12U)                                               /*!< SIM_SOPT2: TRACECLKSEL Position         */
#define SIM_SOPT2_TRACECLKSEL(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_TRACECLKSEL_SHIFT))&SIM_SOPT2_TRACECLKSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_PLLFLLSEL_MASK                 (0x10000U)                                          /*!< SIM_SOPT2: PLLFLLSEL Mask               */
#define SIM_SOPT2_PLLFLLSEL_SHIFT                (16U)                                               /*!< SIM_SOPT2: PLLFLLSEL Position           */
#define SIM_SOPT2_PLLFLLSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_PLLFLLSEL_SHIFT))&SIM_SOPT2_PLLFLLSEL_MASK) /*!< SIM_SOPT2                               */
/* ------- SOPT4 Bit Fields                         ------ */
#define SIM_SOPT4_FTM0FLT0_MASK                  (0x1U)                                              /*!< SIM_SOPT4: FTM0FLT0 Mask                */
#define SIM_SOPT4_FTM0FLT0_SHIFT                 (0U)                                                /*!< SIM_SOPT4: FTM0FLT0 Position            */
#define SIM_SOPT4_FTM0FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT0_SHIFT))&SIM_SOPT4_FTM0FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0FLT1_MASK                  (0x2U)                                              /*!< SIM_SOPT4: FTM0FLT1 Mask                */
#define SIM_SOPT4_FTM0FLT1_SHIFT                 (1U)                                                /*!< SIM_SOPT4: FTM0FLT1 Position            */
#define SIM_SOPT4_FTM0FLT1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT1_SHIFT))&SIM_SOPT4_FTM0FLT1_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1FLT0_MASK                  (0x10U)                                             /*!< SIM_SOPT4: FTM1FLT0 Mask                */
#define SIM_SOPT4_FTM1FLT0_SHIFT                 (4U)                                                /*!< SIM_SOPT4: FTM1FLT0 Position            */
#define SIM_SOPT4_FTM1FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1FLT0_SHIFT))&SIM_SOPT4_FTM1FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2FLT0_MASK                  (0x100U)                                            /*!< SIM_SOPT4: FTM2FLT0 Mask                */
#define SIM_SOPT4_FTM2FLT0_SHIFT                 (8U)                                                /*!< SIM_SOPT4: FTM2FLT0 Position            */
#define SIM_SOPT4_FTM2FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2FLT0_SHIFT))&SIM_SOPT4_FTM2FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1CH0SRC_MASK                (0xC0000U)                                          /*!< SIM_SOPT4: FTM1CH0SRC Mask              */
#define SIM_SOPT4_FTM1CH0SRC_SHIFT               (18U)                                               /*!< SIM_SOPT4: FTM1CH0SRC Position          */
#define SIM_SOPT4_FTM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1CH0SRC_SHIFT))&SIM_SOPT4_FTM1CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2CH0SRC_MASK                (0x300000U)                                         /*!< SIM_SOPT4: FTM2CH0SRC Mask              */
#define SIM_SOPT4_FTM2CH0SRC_SHIFT               (20U)                                               /*!< SIM_SOPT4: FTM2CH0SRC Position          */
#define SIM_SOPT4_FTM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2CH0SRC_SHIFT))&SIM_SOPT4_FTM2CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0CLKSEL_MASK                (0x1000000U)                                        /*!< SIM_SOPT4: FTM0CLKSEL Mask              */
#define SIM_SOPT4_FTM0CLKSEL_SHIFT               (24U)                                               /*!< SIM_SOPT4: FTM0CLKSEL Position          */
#define SIM_SOPT4_FTM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0CLKSEL_SHIFT))&SIM_SOPT4_FTM0CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1CLKSEL_MASK                (0x2000000U)                                        /*!< SIM_SOPT4: FTM1CLKSEL Mask              */
#define SIM_SOPT4_FTM1CLKSEL_SHIFT               (25U)                                               /*!< SIM_SOPT4: FTM1CLKSEL Position          */
#define SIM_SOPT4_FTM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1CLKSEL_SHIFT))&SIM_SOPT4_FTM1CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2CLKSEL_MASK                (0x4000000U)                                        /*!< SIM_SOPT4: FTM2CLKSEL Mask              */
#define SIM_SOPT4_FTM2CLKSEL_SHIFT               (26U)                                               /*!< SIM_SOPT4: FTM2CLKSEL Position          */
#define SIM_SOPT4_FTM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2CLKSEL_SHIFT))&SIM_SOPT4_FTM2CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0TRG0SRC_MASK               (0x10000000U)                                       /*!< SIM_SOPT4: FTM0TRG0SRC Mask             */
#define SIM_SOPT4_FTM0TRG0SRC_SHIFT              (28U)                                               /*!< SIM_SOPT4: FTM0TRG0SRC Position         */
#define SIM_SOPT4_FTM0TRG0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0TRG0SRC_SHIFT))&SIM_SOPT4_FTM0TRG0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0TRG1SRC_MASK               (0x20000000U)                                       /*!< SIM_SOPT4: FTM0TRG1SRC Mask             */
#define SIM_SOPT4_FTM0TRG1SRC_SHIFT              (29U)                                               /*!< SIM_SOPT4: FTM0TRG1SRC Position         */
#define SIM_SOPT4_FTM0TRG1SRC(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0TRG1SRC_SHIFT))&SIM_SOPT4_FTM0TRG1SRC_MASK) /*!< SIM_SOPT4                               */
/* ------- SOPT5 Bit Fields                         ------ */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x3U)                                              /*!< SIM_SOPT5: UART0TXSRC Mask              */
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)                                                /*!< SIM_SOPT5: UART0TXSRC Position          */
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0TXSRC_SHIFT))&SIM_SOPT5_UART0TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART0RXSRC_MASK                (0xCU)                                              /*!< SIM_SOPT5: UART0RXSRC Mask              */
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)                                                /*!< SIM_SOPT5: UART0RXSRC Position          */
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0RXSRC_SHIFT))&SIM_SOPT5_UART0RXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART1TXSRC_MASK                (0x30U)                                             /*!< SIM_SOPT5: UART1TXSRC Mask              */
#define SIM_SOPT5_UART1TXSRC_SHIFT               (4U)                                                /*!< SIM_SOPT5: UART1TXSRC Position          */
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1TXSRC_SHIFT))&SIM_SOPT5_UART1TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART1RXSRC_MASK                (0xC0U)                                             /*!< SIM_SOPT5: UART1RXSRC Mask              */
#define SIM_SOPT5_UART1RXSRC_SHIFT               (6U)                                                /*!< SIM_SOPT5: UART1RXSRC Position          */
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1RXSRC_SHIFT))&SIM_SOPT5_UART1RXSRC_MASK) /*!< SIM_SOPT5                               */
/* ------- SOPT7 Bit Fields                         ------ */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)                                              /*!< SIM_SOPT7: ADC0TRGSEL Mask              */
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)                                                /*!< SIM_SOPT7: ADC0TRGSEL Position          */
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIFT))&SIM_SOPT7_ADC0TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x10U)                                             /*!< SIM_SOPT7: ADC0PRETRGSEL Mask           */
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            (4U)                                                /*!< SIM_SOPT7: ADC0PRETRGSEL Position       */
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0PRETRGSEL_SHIFT))&SIM_SOPT7_ADC0PRETRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x80U)                                             /*!< SIM_SOPT7: ADC0ALTTRGEN Mask            */
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             (7U)                                                /*!< SIM_SOPT7: ADC0ALTTRGEN Position        */
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0ALTTRGEN_SHIFT))&SIM_SOPT7_ADC0ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
/* ------- SDID Bit Fields                          ------ */
#define SIM_SDID_PINID_MASK                      (0xFU)                                              /*!< SIM_SDID: PINID Mask                    */
#define SIM_SDID_PINID_SHIFT                     (0U)                                                /*!< SIM_SDID: PINID Position                */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_FAMID_MASK                      (0x70U)                                             /*!< SIM_SDID: FAMID Mask                    */
#define SIM_SDID_FAMID_SHIFT                     (4U)                                                /*!< SIM_SDID: FAMID Position                */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_DIEID_MASK                      (0xF80U)                                            /*!< SIM_SDID: DIEID Mask                    */
#define SIM_SDID_DIEID_SHIFT                     (7U)                                                /*!< SIM_SDID: DIEID Position                */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_REVID_MASK                      (0xF000U)                                           /*!< SIM_SDID: REVID Mask                    */
#define SIM_SDID_REVID_SHIFT                     (12U)                                               /*!< SIM_SDID: REVID Position                */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK) /*!< SIM_SDID                                */
/* ------- SCGC4 Bit Fields                         ------ */
#define SIM_SCGC4_EWM_MASK                       (0x2U)                                              /*!< SIM_SCGC4: EWM Mask                     */
#define SIM_SCGC4_EWM_SHIFT                      (1U)                                                /*!< SIM_SCGC4: EWM Position                 */
#define SIM_SCGC4_EWM(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_EWM_SHIFT))&SIM_SCGC4_EWM_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_CMT_MASK                       (0x4U)                                              /*!< SIM_SCGC4: CMT Mask                     */
#define SIM_SCGC4_CMT_SHIFT                      (2U)                                                /*!< SIM_SCGC4: CMT Position                 */
#define SIM_SCGC4_CMT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMT_SHIFT))&SIM_SCGC4_CMT_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_I2C0_MASK                      (0x40U)                                             /*!< SIM_SCGC4: I2C0 Mask                    */
#define SIM_SCGC4_I2C0_SHIFT                     (6U)                                                /*!< SIM_SCGC4: I2C0 Position                */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C0_SHIFT))&SIM_SCGC4_I2C0_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_I2C1_MASK                      (0x80U)                                             /*!< SIM_SCGC4: I2C1 Mask                    */
#define SIM_SCGC4_I2C1_SHIFT                     (7U)                                                /*!< SIM_SCGC4: I2C1 Position                */
#define SIM_SCGC4_I2C1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C1_SHIFT))&SIM_SCGC4_I2C1_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART0_MASK                     (0x400U)                                            /*!< SIM_SCGC4: UART0 Mask                   */
#define SIM_SCGC4_UART0_SHIFT                    (10U)                                               /*!< SIM_SCGC4: UART0 Position               */
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART0_SHIFT))&SIM_SCGC4_UART0_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART1_MASK                     (0x800U)                                            /*!< SIM_SCGC4: UART1 Mask                   */
#define SIM_SCGC4_UART1_SHIFT                    (11U)                                               /*!< SIM_SCGC4: UART1 Position               */
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART1_SHIFT))&SIM_SCGC4_UART1_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART2_MASK                     (0x1000U)                                           /*!< SIM_SCGC4: UART2 Mask                   */
#define SIM_SCGC4_UART2_SHIFT                    (12U)                                               /*!< SIM_SCGC4: UART2 Position               */
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART2_SHIFT))&SIM_SCGC4_UART2_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART3_MASK                     (0x2000U)                                           /*!< SIM_SCGC4: UART3 Mask                   */
#define SIM_SCGC4_UART3_SHIFT                    (13U)                                               /*!< SIM_SCGC4: UART3 Position               */
#define SIM_SCGC4_UART3(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART3_SHIFT))&SIM_SCGC4_UART3_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_CMP_MASK                       (0x80000U)                                          /*!< SIM_SCGC4: CMP Mask                     */
#define SIM_SCGC4_CMP_SHIFT                      (19U)                                               /*!< SIM_SCGC4: CMP Position                 */
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMP_SHIFT))&SIM_SCGC4_CMP_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_VREF_MASK                      (0x100000U)                                         /*!< SIM_SCGC4: VREF Mask                    */
#define SIM_SCGC4_VREF_SHIFT                     (20U)                                               /*!< SIM_SCGC4: VREF Position                */
#define SIM_SCGC4_VREF(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_VREF_SHIFT))&SIM_SCGC4_VREF_MASK) /*!< SIM_SCGC4                               */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_LPTMR_MASK                     (0x1U)                                              /*!< SIM_SCGC5: LPTMR Mask                   */
#define SIM_SCGC5_LPTMR_SHIFT                    (0U)                                                /*!< SIM_SCGC5: LPTMR Position               */
#define SIM_SCGC5_LPTMR(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPTMR_SHIFT))&SIM_SCGC5_LPTMR_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_DRYICE_MASK                    (0x4U)                                              /*!< SIM_SCGC5: DRYICE Mask                  */
#define SIM_SCGC5_DRYICE_SHIFT                   (2U)                                                /*!< SIM_SCGC5: DRYICE Position              */
#define SIM_SCGC5_DRYICE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_DRYICE_SHIFT))&SIM_SCGC5_DRYICE_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_SECREG_MASK                    (0x8U)                                              /*!< SIM_SCGC5: SECREG Mask                  */
#define SIM_SCGC5_SECREG_SHIFT                   (3U)                                                /*!< SIM_SCGC5: SECREG Position              */
#define SIM_SCGC5_SECREG(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_SECREG_SHIFT))&SIM_SCGC5_SECREG_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTA_MASK                     (0x200U)                                            /*!< SIM_SCGC5: PORTA Mask                   */
#define SIM_SCGC5_PORTA_SHIFT                    (9U)                                                /*!< SIM_SCGC5: PORTA Position               */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTA_SHIFT))&SIM_SCGC5_PORTA_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTB_MASK                     (0x400U)                                            /*!< SIM_SCGC5: PORTB Mask                   */
#define SIM_SCGC5_PORTB_SHIFT                    (10U)                                               /*!< SIM_SCGC5: PORTB Position               */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTB_SHIFT))&SIM_SCGC5_PORTB_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTC_MASK                     (0x800U)                                            /*!< SIM_SCGC5: PORTC Mask                   */
#define SIM_SCGC5_PORTC_SHIFT                    (11U)                                               /*!< SIM_SCGC5: PORTC Position               */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTC_SHIFT))&SIM_SCGC5_PORTC_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)                                           /*!< SIM_SCGC5: PORTD Mask                   */
#define SIM_SCGC5_PORTD_SHIFT                    (12U)                                               /*!< SIM_SCGC5: PORTD Position               */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTD_SHIFT))&SIM_SCGC5_PORTD_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)                                           /*!< SIM_SCGC5: PORTE Mask                   */
#define SIM_SCGC5_PORTE_SHIFT                    (13U)                                               /*!< SIM_SCGC5: PORTE Position               */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTE_SHIFT))&SIM_SCGC5_PORTE_MASK) /*!< SIM_SCGC5                               */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_FTFL_MASK                      (0x1U)                                              /*!< SIM_SCGC6: FTFL Mask                    */
#define SIM_SCGC6_FTFL_SHIFT                     (0U)                                                /*!< SIM_SCGC6: FTFL Position                */
#define SIM_SCGC6_FTFL(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTFL_SHIFT))&SIM_SCGC6_FTFL_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x2U)                                              /*!< SIM_SCGC6: DMAMUX0 Mask                 */
#define SIM_SCGC6_DMAMUX0_SHIFT                  (1U)                                                /*!< SIM_SCGC6: DMAMUX0 Position             */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DMAMUX0_SHIFT))&SIM_SCGC6_DMAMUX0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_RNGA_MASK                      (0x200U)                                            /*!< SIM_SCGC6: RNGA Mask                    */
#define SIM_SCGC6_RNGA_SHIFT                     (9U)                                                /*!< SIM_SCGC6: RNGA Position                */
#define SIM_SCGC6_RNGA(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_RNGA_SHIFT))&SIM_SCGC6_RNGA_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_SPI0_MASK                      (0x1000U)                                           /*!< SIM_SCGC6: SPI0 Mask                    */
#define SIM_SCGC6_SPI0_SHIFT                     (12U)                                               /*!< SIM_SCGC6: SPI0 Position                */
#define SIM_SCGC6_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_SPI0_SHIFT))&SIM_SCGC6_SPI0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_SPI1_MASK                      (0x2000U)                                           /*!< SIM_SCGC6: SPI1 Mask                    */
#define SIM_SCGC6_SPI1_SHIFT                     (13U)                                               /*!< SIM_SCGC6: SPI1 Position                */
#define SIM_SCGC6_SPI1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_SPI1_SHIFT))&SIM_SCGC6_SPI1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_I2S_MASK                       (0x8000U)                                           /*!< SIM_SCGC6: I2S Mask                     */
#define SIM_SCGC6_I2S_SHIFT                      (15U)                                               /*!< SIM_SCGC6: I2S Position                 */
#define SIM_SCGC6_I2S(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_I2S_SHIFT))&SIM_SCGC6_I2S_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_CRC_MASK                       (0x40000U)                                          /*!< SIM_SCGC6: CRC Mask                     */
#define SIM_SCGC6_CRC_SHIFT                      (18U)                                               /*!< SIM_SCGC6: CRC Position                 */
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_CRC_SHIFT))&SIM_SCGC6_CRC_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PDB_MASK                       (0x400000U)                                         /*!< SIM_SCGC6: PDB Mask                     */
#define SIM_SCGC6_PDB_SHIFT                      (22U)                                               /*!< SIM_SCGC6: PDB Position                 */
#define SIM_SCGC6_PDB(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PDB_SHIFT))&SIM_SCGC6_PDB_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PIT_MASK                       (0x800000U)                                         /*!< SIM_SCGC6: PIT Mask                     */
#define SIM_SCGC6_PIT_SHIFT                      (23U)                                               /*!< SIM_SCGC6: PIT Position                 */
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PIT_SHIFT))&SIM_SCGC6_PIT_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM0_MASK                      (0x1000000U)                                        /*!< SIM_SCGC6: FTM0 Mask                    */
#define SIM_SCGC6_FTM0_SHIFT                     (24U)                                               /*!< SIM_SCGC6: FTM0 Position                */
#define SIM_SCGC6_FTM0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM0_SHIFT))&SIM_SCGC6_FTM0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM1_MASK                      (0x2000000U)                                        /*!< SIM_SCGC6: FTM1 Mask                    */
#define SIM_SCGC6_FTM1_SHIFT                     (25U)                                               /*!< SIM_SCGC6: FTM1 Position                */
#define SIM_SCGC6_FTM1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM1_SHIFT))&SIM_SCGC6_FTM1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM2_MASK                      (0x4000000U)                                        /*!< SIM_SCGC6: FTM2 Mask                    */
#define SIM_SCGC6_FTM2_SHIFT                     (26U)                                               /*!< SIM_SCGC6: FTM2 Position                */
#define SIM_SCGC6_FTM2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM2_SHIFT))&SIM_SCGC6_FTM2_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)                                        /*!< SIM_SCGC6: ADC0 Mask                    */
#define SIM_SCGC6_ADC0_SHIFT                     (27U)                                               /*!< SIM_SCGC6: ADC0 Position                */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC0_SHIFT))&SIM_SCGC6_ADC0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_RTC_MASK                       (0x20000000U)                                       /*!< SIM_SCGC6: RTC Mask                     */
#define SIM_SCGC6_RTC_SHIFT                      (29U)                                               /*!< SIM_SCGC6: RTC Position                 */
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_RTC_SHIFT))&SIM_SCGC6_RTC_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)                                       /*!< SIM_SCGC6: DAC0 Mask                    */
#define SIM_SCGC6_DAC0_SHIFT                     (31U)                                               /*!< SIM_SCGC6: DAC0 Position                */
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DAC0_SHIFT))&SIM_SCGC6_DAC0_MASK) /*!< SIM_SCGC6                               */
/* ------- SCGC7 Bit Fields                         ------ */
#define SIM_SCGC7_DMA_MASK                       (0x2U)                                              /*!< SIM_SCGC7: DMA Mask                     */
#define SIM_SCGC7_DMA_SHIFT                      (1U)                                                /*!< SIM_SCGC7: DMA Position                 */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_DMA_SHIFT))&SIM_SCGC7_DMA_MASK) /*!< SIM_SCGC7                               */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0xF0000U)                                          /*!< SIM_CLKDIV1: OUTDIV4 Mask               */
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)                                               /*!< SIM_CLKDIV1: OUTDIV4 Position           */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV2_MASK                 (0xF000000U)                                        /*!< SIM_CLKDIV1: OUTDIV2 Mask               */
#define SIM_CLKDIV1_OUTDIV2_SHIFT                (24U)                                               /*!< SIM_CLKDIV1: OUTDIV2 Position           */
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV2_SHIFT))&SIM_CLKDIV1_OUTDIV2_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)                                       /*!< SIM_CLKDIV1: OUTDIV1 Mask               */
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)                                               /*!< SIM_CLKDIV1: OUTDIV1 Position           */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK) /*!< SIM_CLKDIV1                             */
/* ------- CLKDIV2 Bit Fields                       ------ */
/* ------- FCFG1 Bit Fields                         ------ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)                                              /*!< SIM_FCFG1: FLASHDIS Mask                */
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)                                                /*!< SIM_FCFG1: FLASHDIS Position            */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDIS_SHIFT))&SIM_FCFG1_FLASHDIS_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)                                              /*!< SIM_FCFG1: FLASHDOZE Mask               */
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)                                                /*!< SIM_FCFG1: FLASHDOZE Position           */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDOZE_SHIFT))&SIM_FCFG1_FLASHDOZE_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_DEPART_MASK                    (0xF00U)                                            /*!< SIM_FCFG1: DEPART Mask                  */
#define SIM_FCFG1_DEPART_SHIFT                   (8U)                                                /*!< SIM_FCFG1: DEPART Position              */
#define SIM_FCFG1_DEPART(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_DEPART_SHIFT))&SIM_FCFG1_DEPART_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_EESIZE_MASK                    (0xF0000U)                                          /*!< SIM_FCFG1: EESIZE Mask                  */
#define SIM_FCFG1_EESIZE_SHIFT                   (16U)                                               /*!< SIM_FCFG1: EESIZE Position              */
#define SIM_FCFG1_EESIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_EESIZE_SHIFT))&SIM_FCFG1_EESIZE_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)                                        /*!< SIM_FCFG1: PFSIZE Mask                  */
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)                                               /*!< SIM_FCFG1: PFSIZE Position              */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_NVMSIZE_MASK                   (0xF0000000U)                                       /*!< SIM_FCFG1: NVMSIZE Mask                 */
#define SIM_FCFG1_NVMSIZE_SHIFT                  (28U)                                               /*!< SIM_FCFG1: NVMSIZE Position             */
#define SIM_FCFG1_NVMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_NVMSIZE_SHIFT))&SIM_FCFG1_NVMSIZE_MASK) /*!< SIM_FCFG1                               */
/* ------- FCFG2 Bit Fields                         ------ */
#define SIM_FCFG2_MAXADDR1_MASK                  (0x7F0000U)                                         /*!< SIM_FCFG2: MAXADDR1 Mask                */
#define SIM_FCFG2_MAXADDR1_SHIFT                 (16U)                                               /*!< SIM_FCFG2: MAXADDR1 Position            */
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR1_SHIFT))&SIM_FCFG2_MAXADDR1_MASK) /*!< SIM_FCFG2                               */
#define SIM_FCFG2_PFLSH_MASK                     (0x800000U)                                         /*!< SIM_FCFG2: PFLSH Mask                   */
#define SIM_FCFG2_PFLSH_SHIFT                    (23U)                                               /*!< SIM_FCFG2: PFLSH Position               */
#define SIM_FCFG2_PFLSH(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_PFLSH_SHIFT))&SIM_FCFG2_PFLSH_MASK) /*!< SIM_FCFG2                               */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)                                       /*!< SIM_FCFG2: MAXADDR0 Mask                */
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)                                               /*!< SIM_FCFG2: MAXADDR0 Position            */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR0_SHIFT))&SIM_FCFG2_MAXADDR0_MASK) /*!< SIM_FCFG2                               */
#define SIM_FCFG2_SWAPPFLSH_MASK                 (0x80000000U)                                       /*!< SIM_FCFG2: SWAPPFLSH Mask               */
#define SIM_FCFG2_SWAPPFLSH_SHIFT                (31U)                                               /*!< SIM_FCFG2: SWAPPFLSH Position           */
#define SIM_FCFG2_SWAPPFLSH(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_SWAPPFLSH_SHIFT))&SIM_FCFG2_SWAPPFLSH_MASK) /*!< SIM_FCFG2                               */
/* ------- UIDH Bit Fields                          ------ */
#define SIM_UIDH_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDH: UID Mask                      */
#define SIM_UIDH_UID_SHIFT                       (0U)                                                /*!< SIM_UIDH: UID Position                  */
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDH_UID_SHIFT))&SIM_UIDH_UID_MASK) /*!< SIM_UIDH                                */
/* ------- UIDMH Bit Fields                         ------ */
#define SIM_UIDMH_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDMH: UID Mask                     */
#define SIM_UIDMH_UID_SHIFT                      (0U)                                                /*!< SIM_UIDMH: UID Position                 */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK) /*!< SIM_UIDMH                               */
/* ------- UIDML Bit Fields                         ------ */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDML: UID Mask                     */
#define SIM_UIDML_UID_SHIFT                      (0U)                                                /*!< SIM_UIDML: UID Position                 */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK) /*!< SIM_UIDML                               */
/* ------- UIDL Bit Fields                          ------ */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDL: UID Mask                      */
#define SIM_UIDL_UID_SHIFT                       (0U)                                                /*!< SIM_UIDL: UID Position                  */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK) /*!< SIM_UIDL                                */
/**
 * @} */ /* End group SIM_Register_Masks_GROUP 
 */

/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x40047000UL //!< Peripheral base address
#define SIM                            ((SIM_Type *) SIM_BasePtr) //!< Freescale base pointer
#define SIM_BASE_PTR                   (SIM) //!< Freescale style base pointer
/**
 * @} */ /* End group SIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SMC_Peripheral_access_layer_GROUP SMC Peripheral Access Layer
* @brief C Struct for SMC
* @{
*/

/* ================================================================================ */
/* ================           SMC (file:SMC_MK11D5)                ================ */
/* ================================================================================ */

/**
 * @brief System Mode Controller
 */
/**
* @addtogroup SMC_structs_GROUP SMC struct
* @brief Struct for SMC
* @{
*/
typedef struct {                                /*       SMC Structure                                                */
   __IO uint8_t   PMPROT;                       /**< 0000: Power Mode Protection Register                               */
   __IO uint8_t   PMCTRL;                       /**< 0001: Power Mode Control Register                                  */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   STOPCTRL;                  /**< 0002: Stop Control Register                                        */
      __IO uint8_t   VLLSCTRL;                  /**< 0002: VLLS Control Register                                        */
   };
   __I  uint8_t   PMSTAT;                       /**< 0003: Power Mode Status Register                                   */
} SMC_Type;

/**
 * @} */ /* End group SMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SMC_Register_Masks_GROUP SMC Register Masks
* @brief Register Masks for SMC
* @{
*/
/* ------- PMPROT Bit Fields                        ------ */
#define SMC_PMPROT_AVLLS_MASK                    (0x2U)                                              /*!< SMC_PMPROT: AVLLS Mask                  */
#define SMC_PMPROT_AVLLS_SHIFT                   (1U)                                                /*!< SMC_PMPROT: AVLLS Position              */
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLLS_SHIFT))&SMC_PMPROT_AVLLS_MASK) /*!< SMC_PMPROT                              */
#define SMC_PMPROT_ALLS_MASK                     (0x8U)                                              /*!< SMC_PMPROT: ALLS Mask                   */
#define SMC_PMPROT_ALLS_SHIFT                    (3U)                                                /*!< SMC_PMPROT: ALLS Position               */
#define SMC_PMPROT_ALLS(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_ALLS_SHIFT))&SMC_PMPROT_ALLS_MASK) /*!< SMC_PMPROT                              */
#define SMC_PMPROT_AVLP_MASK                     (0x20U)                                             /*!< SMC_PMPROT: AVLP Mask                   */
#define SMC_PMPROT_AVLP_SHIFT                    (5U)                                                /*!< SMC_PMPROT: AVLP Position               */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLP_SHIFT))&SMC_PMPROT_AVLP_MASK) /*!< SMC_PMPROT                              */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x7U)                                              /*!< SMC_PMCTRL: STOPM Mask                  */
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)                                                /*!< SMC_PMCTRL: STOPM Position              */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_STOPA_MASK                    (0x8U)                                              /*!< SMC_PMCTRL: STOPA Mask                  */
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)                                                /*!< SMC_PMCTRL: STOPA Position              */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPA_SHIFT))&SMC_PMCTRL_STOPA_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_RUNM_MASK                     (0x60U)                                             /*!< SMC_PMCTRL: RUNM Mask                   */
#define SMC_PMCTRL_RUNM_SHIFT                    (5U)                                                /*!< SMC_PMCTRL: RUNM Position               */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_LPWUI_MASK                    (0x80U)                                             /*!< SMC_PMCTRL: LPWUI Mask                  */
#define SMC_PMCTRL_LPWUI_SHIFT                   (7U)                                                /*!< SMC_PMCTRL: LPWUI Position              */
#define SMC_PMCTRL_LPWUI(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_LPWUI_SHIFT))&SMC_PMCTRL_LPWUI_MASK) /*!< SMC_PMCTRL                              */
/* ------- STOPCTRL Bit Fields                      ------ */
#define SMC_STOPCTRL_LLSM_MASK                   (0x7U)                                              /*!< SMC_STOPCTRL: LLSM Mask                 */
#define SMC_STOPCTRL_LLSM_SHIFT                  (0U)                                                /*!< SMC_STOPCTRL: LLSM Position             */
#define SMC_STOPCTRL_LLSM(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_LLSM_SHIFT))&SMC_STOPCTRL_LLSM_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_VLLSM_MASK                  (0x7U)                                              /*!< SMC_STOPCTRL: VLLSM Mask                */
#define SMC_STOPCTRL_VLLSM_SHIFT                 (0U)                                                /*!< SMC_STOPCTRL: VLLSM Position            */
#define SMC_STOPCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_VLLSM_SHIFT))&SMC_STOPCTRL_VLLSM_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_RAM2PO_MASK                 (0x10U)                                             /*!< SMC_STOPCTRL: RAM2PO Mask               */
#define SMC_STOPCTRL_RAM2PO_SHIFT                (4U)                                                /*!< SMC_STOPCTRL: RAM2PO Position           */
#define SMC_STOPCTRL_RAM2PO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_RAM2PO_SHIFT))&SMC_STOPCTRL_RAM2PO_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_PORPO_MASK                  (0x20U)                                             /*!< SMC_STOPCTRL: PORPO Mask                */
#define SMC_STOPCTRL_PORPO_SHIFT                 (5U)                                                /*!< SMC_STOPCTRL: PORPO Position            */
#define SMC_STOPCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PORPO_SHIFT))&SMC_STOPCTRL_PORPO_MASK) /*!< SMC_STOPCTRL                            */
/* ------- VLLSCTRL Bit Fields                      ------ */
#define SMC_VLLSCTRL_LLSM_MASK                   (0x7U)                                              /*!< SMC_VLLSCTRL: LLSM Mask                 */
#define SMC_VLLSCTRL_LLSM_SHIFT                  (0U)                                                /*!< SMC_VLLSCTRL: LLSM Position             */
#define SMC_VLLSCTRL_LLSM(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_LLSM_SHIFT))&SMC_VLLSCTRL_LLSM_MASK) /*!< SMC_VLLSCTRL                            */
#define SMC_VLLSCTRL_VLLSM_MASK                  (0x7U)                                              /*!< SMC_VLLSCTRL: VLLSM Mask                */
#define SMC_VLLSCTRL_VLLSM_SHIFT                 (0U)                                                /*!< SMC_VLLSCTRL: VLLSM Position            */
#define SMC_VLLSCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_VLLSM_SHIFT))&SMC_VLLSCTRL_VLLSM_MASK) /*!< SMC_VLLSCTRL                            */
#define SMC_VLLSCTRL_RAM2PO_MASK                 (0x10U)                                             /*!< SMC_VLLSCTRL: RAM2PO Mask               */
#define SMC_VLLSCTRL_RAM2PO_SHIFT                (4U)                                                /*!< SMC_VLLSCTRL: RAM2PO Position           */
#define SMC_VLLSCTRL_RAM2PO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_RAM2PO_SHIFT))&SMC_VLLSCTRL_RAM2PO_MASK) /*!< SMC_VLLSCTRL                            */
#define SMC_VLLSCTRL_PORPO_MASK                  (0x20U)                                             /*!< SMC_VLLSCTRL: PORPO Mask                */
#define SMC_VLLSCTRL_PORPO_SHIFT                 (5U)                                                /*!< SMC_VLLSCTRL: PORPO Position            */
#define SMC_VLLSCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_PORPO_SHIFT))&SMC_VLLSCTRL_PORPO_MASK) /*!< SMC_VLLSCTRL                            */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)                                             /*!< SMC_PMSTAT: PMSTAT Mask                 */
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)                                                /*!< SMC_PMSTAT: PMSTAT Position             */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK) /*!< SMC_PMSTAT                              */
/**
 * @} */ /* End group SMC_Register_Masks_GROUP 
 */

/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0x4007E000UL //!< Peripheral base address
#define SMC                            ((SMC_Type *) SMC_BasePtr) //!< Freescale base pointer
#define SMC_BASE_PTR                   (SMC) //!< Freescale style base pointer
/**
 * @} */ /* End group SMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_MK_PCSIS6)           ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       SPI0 Structure                                               */
   __IO uint32_t  MCR;                          /**< 0000: Module Configuration Register                                */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  TCR;                          /**< 0008: Transfer Count Register                                      */
   union {                                      /**< 0000: (size=0008)                                                  */
      __IO uint32_t  CTAR[2];                   /**< 000C: Clock and Transfer Attributes Register (In Master Mode)      */
      __IO uint32_t  CTAR_SLAVE;                /**< 000C: Clock and Transfer Attributes Register (In Slave Mode)       */
   };
        uint8_t   RESERVED_1[24];              
   __IO uint32_t  SR;                           /**< 002C: Status register                                              */
   __IO uint32_t  RSER;                         /**< 0030: DMA/Interrupt Request Select and Enable Register             */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PUSHR;                     /**< 0034: PUSH TX FIFO Register In Master Mode                         */
      __IO uint32_t  PUSHR_SLAVE;               /**< 0034: PUSH TX FIFO Register In Slave Mode                          */
   };
   __I  uint32_t  POPR;                         /**< 0038: POP RX FIFO Register                                         */
   __I  uint32_t  TXFR[4];                      /**< 003C: Transmit FIFO                                                */
        uint8_t   RESERVED_2[48];              
   __I  uint32_t  RXFR[4];                      /**< 007C: Receive FIFO                                                 */
} SPI_Type;

/**
 * @} */ /* End group SPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SPI_Register_Masks_GROUP SPI Register Masks
* @brief Register Masks for SPI
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define SPI_MCR_HALT_MASK                        (0x1U)                                              /*!< SPI0_MCR: HALT Mask                     */
#define SPI_MCR_HALT_SHIFT                       (0U)                                                /*!< SPI0_MCR: HALT Position                 */
#define SPI_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_HALT_SHIFT))&SPI_MCR_HALT_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_SMPL_PT_MASK                     (0x300U)                                            /*!< SPI0_MCR: SMPL_PT Mask                  */
#define SPI_MCR_SMPL_PT_SHIFT                    (8U)                                                /*!< SPI0_MCR: SMPL_PT Position              */
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_SMPL_PT_SHIFT))&SPI_MCR_SMPL_PT_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_CLR_RXF_MASK                     (0x400U)                                            /*!< SPI0_MCR: CLR_RXF Mask                  */
#define SPI_MCR_CLR_RXF_SHIFT                    (10U)                                               /*!< SPI0_MCR: CLR_RXF Position              */
#define SPI_MCR_CLR_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_CLR_RXF_SHIFT))&SPI_MCR_CLR_RXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_CLR_TXF_MASK                     (0x800U)                                            /*!< SPI0_MCR: CLR_TXF Mask                  */
#define SPI_MCR_CLR_TXF_SHIFT                    (11U)                                               /*!< SPI0_MCR: CLR_TXF Position              */
#define SPI_MCR_CLR_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_CLR_TXF_SHIFT))&SPI_MCR_CLR_TXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DIS_RXF_MASK                     (0x1000U)                                           /*!< SPI0_MCR: DIS_RXF Mask                  */
#define SPI_MCR_DIS_RXF_SHIFT                    (12U)                                               /*!< SPI0_MCR: DIS_RXF Position              */
#define SPI_MCR_DIS_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DIS_RXF_SHIFT))&SPI_MCR_DIS_RXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DIS_TXF_MASK                     (0x2000U)                                           /*!< SPI0_MCR: DIS_TXF Mask                  */
#define SPI_MCR_DIS_TXF_SHIFT                    (13U)                                               /*!< SPI0_MCR: DIS_TXF Position              */
#define SPI_MCR_DIS_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DIS_TXF_SHIFT))&SPI_MCR_DIS_TXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_MDIS_MASK                        (0x4000U)                                           /*!< SPI0_MCR: MDIS Mask                     */
#define SPI_MCR_MDIS_SHIFT                       (14U)                                               /*!< SPI0_MCR: MDIS Position                 */
#define SPI_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_MDIS_SHIFT))&SPI_MCR_MDIS_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DOZE_MASK                        (0x8000U)                                           /*!< SPI0_MCR: DOZE Mask                     */
#define SPI_MCR_DOZE_SHIFT                       (15U)                                               /*!< SPI0_MCR: DOZE Position                 */
#define SPI_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DOZE_SHIFT))&SPI_MCR_DOZE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_PCSIS_MASK                       (0x3F0000U)                                         /*!< SPI0_MCR: PCSIS Mask                    */
#define SPI_MCR_PCSIS_SHIFT                      (16U)                                               /*!< SPI0_MCR: PCSIS Position                */
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_PCSIS_SHIFT))&SPI_MCR_PCSIS_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_ROOE_MASK                        (0x1000000U)                                        /*!< SPI0_MCR: ROOE Mask                     */
#define SPI_MCR_ROOE_SHIFT                       (24U)                                               /*!< SPI0_MCR: ROOE Position                 */
#define SPI_MCR_ROOE(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_ROOE_SHIFT))&SPI_MCR_ROOE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_MTFE_MASK                        (0x4000000U)                                        /*!< SPI0_MCR: MTFE Mask                     */
#define SPI_MCR_MTFE_SHIFT                       (26U)                                               /*!< SPI0_MCR: MTFE Position                 */
#define SPI_MCR_MTFE(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_MTFE_SHIFT))&SPI_MCR_MTFE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_FRZ_MASK                         (0x8000000U)                                        /*!< SPI0_MCR: FRZ Mask                      */
#define SPI_MCR_FRZ_SHIFT                        (27U)                                               /*!< SPI0_MCR: FRZ Position                  */
#define SPI_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_MCR_FRZ_SHIFT))&SPI_MCR_FRZ_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DCONF_MASK                       (0x30000000U)                                       /*!< SPI0_MCR: DCONF Mask                    */
#define SPI_MCR_DCONF_SHIFT                      (28U)                                               /*!< SPI0_MCR: DCONF Position                */
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DCONF_SHIFT))&SPI_MCR_DCONF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_CONT_SCKE_MASK                   (0x40000000U)                                       /*!< SPI0_MCR: CONT_SCKE Mask                */
#define SPI_MCR_CONT_SCKE_SHIFT                  (30U)                                               /*!< SPI0_MCR: CONT_SCKE Position            */
#define SPI_MCR_CONT_SCKE(x)                     (((uint32_t)(((uint32_t)(x))<<SPI_MCR_CONT_SCKE_SHIFT))&SPI_MCR_CONT_SCKE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_MSTR_MASK                        (0x80000000U)                                       /*!< SPI0_MCR: MSTR Mask                     */
#define SPI_MCR_MSTR_SHIFT                       (31U)                                               /*!< SPI0_MCR: MSTR Position                 */
#define SPI_MCR_MSTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_MSTR_SHIFT))&SPI_MCR_MSTR_MASK) /*!< SPI0_MCR                                */
/* ------- TCR Bit Fields                           ------ */
#define SPI_TCR_SPI_TCNT_MASK                    (0xFFFF0000U)                                       /*!< SPI0_TCR: SPI_TCNT Mask                 */
#define SPI_TCR_SPI_TCNT_SHIFT                   (16U)                                               /*!< SPI0_TCR: SPI_TCNT Position             */
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TCR_SPI_TCNT_SHIFT))&SPI_TCR_SPI_TCNT_MASK) /*!< SPI0_TCR                                */
/* ------- CTAR Bit Fields                          ------ */
#define SPI_CTAR_BR_MASK                         (0xFU)                                              /*!< SPI0_CTAR: BR Mask                      */
#define SPI_CTAR_BR_SHIFT                        (0U)                                                /*!< SPI0_CTAR: BR Position                  */
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_BR_SHIFT))&SPI_CTAR_BR_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_DT_MASK                         (0xF0U)                                             /*!< SPI0_CTAR: DT Mask                      */
#define SPI_CTAR_DT_SHIFT                        (4U)                                                /*!< SPI0_CTAR: DT Position                  */
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_DT_SHIFT))&SPI_CTAR_DT_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_ASC_MASK                        (0xF00U)                                            /*!< SPI0_CTAR: ASC Mask                     */
#define SPI_CTAR_ASC_SHIFT                       (8U)                                                /*!< SPI0_CTAR: ASC Position                 */
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_ASC_SHIFT))&SPI_CTAR_ASC_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_CSSCK_MASK                      (0xF000U)                                           /*!< SPI0_CTAR: CSSCK Mask                   */
#define SPI_CTAR_CSSCK_SHIFT                     (12U)                                               /*!< SPI0_CTAR: CSSCK Position               */
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CSSCK_SHIFT))&SPI_CTAR_CSSCK_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PBR_MASK                        (0x30000U)                                          /*!< SPI0_CTAR: PBR Mask                     */
#define SPI_CTAR_PBR_SHIFT                       (16U)                                               /*!< SPI0_CTAR: PBR Position                 */
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PBR_SHIFT))&SPI_CTAR_PBR_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PDT_MASK                        (0xC0000U)                                          /*!< SPI0_CTAR: PDT Mask                     */
#define SPI_CTAR_PDT_SHIFT                       (18U)                                               /*!< SPI0_CTAR: PDT Position                 */
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PDT_SHIFT))&SPI_CTAR_PDT_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PASC_MASK                       (0x300000U)                                         /*!< SPI0_CTAR: PASC Mask                    */
#define SPI_CTAR_PASC_SHIFT                      (20U)                                               /*!< SPI0_CTAR: PASC Position                */
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PASC_SHIFT))&SPI_CTAR_PASC_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PCSSCK_MASK                     (0xC00000U)                                         /*!< SPI0_CTAR: PCSSCK Mask                  */
#define SPI_CTAR_PCSSCK_SHIFT                    (22U)                                               /*!< SPI0_CTAR: PCSSCK Position              */
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PCSSCK_SHIFT))&SPI_CTAR_PCSSCK_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_LSBFE_MASK                      (0x1000000U)                                        /*!< SPI0_CTAR: LSBFE Mask                   */
#define SPI_CTAR_LSBFE_SHIFT                     (24U)                                               /*!< SPI0_CTAR: LSBFE Position               */
#define SPI_CTAR_LSBFE(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_LSBFE_SHIFT))&SPI_CTAR_LSBFE_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_MODE_MASK                       (0x6000000U)                                        /*!< SPI0_CTAR: MODE Mask                    */
#define SPI_CTAR_MODE_SHIFT                      (25U)                                               /*!< SPI0_CTAR: MODE Position                */
#define SPI_CTAR_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_MODE_SHIFT))&SPI_CTAR_MODE_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_CPHA_MASK                       (0x2000000U)                                        /*!< SPI0_CTAR: CPHA Mask                    */
#define SPI_CTAR_CPHA_SHIFT                      (25U)                                               /*!< SPI0_CTAR: CPHA Position                */
#define SPI_CTAR_CPHA(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CPHA_SHIFT))&SPI_CTAR_CPHA_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_CPOL_MASK                       (0x4000000U)                                        /*!< SPI0_CTAR: CPOL Mask                    */
#define SPI_CTAR_CPOL_SHIFT                      (26U)                                               /*!< SPI0_CTAR: CPOL Position                */
#define SPI_CTAR_CPOL(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CPOL_SHIFT))&SPI_CTAR_CPOL_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_FMSZ_MASK                       (0x78000000U)                                       /*!< SPI0_CTAR: FMSZ Mask                    */
#define SPI_CTAR_FMSZ_SHIFT                      (27U)                                               /*!< SPI0_CTAR: FMSZ Position                */
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_FMSZ_SHIFT))&SPI_CTAR_FMSZ_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_DBR_MASK                        (0x80000000U)                                       /*!< SPI0_CTAR: DBR Mask                     */
#define SPI_CTAR_DBR_SHIFT                       (31U)                                               /*!< SPI0_CTAR: DBR Position                 */
#define SPI_CTAR_DBR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_DBR_SHIFT))&SPI_CTAR_DBR_MASK) /*!< SPI0_CTAR                               */
/* ------- CTAR_SLAVE Bit Fields                    ------ */
#define SPI_CTAR_SLAVE_MODE_MASK                 (0x6000000U)                                        /*!< SPI0_CTAR_SLAVE: MODE Mask              */
#define SPI_CTAR_SLAVE_MODE_SHIFT                (25U)                                               /*!< SPI0_CTAR_SLAVE: MODE Position          */
#define SPI_CTAR_SLAVE_MODE(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_MODE_SHIFT))&SPI_CTAR_SLAVE_MODE_MASK) /*!< SPI0_CTAR_SLAVE                         */
#define SPI_CTAR_SLAVE_CPHA_MASK                 (0x2000000U)                                        /*!< SPI0_CTAR_SLAVE: CPHA Mask              */
#define SPI_CTAR_SLAVE_CPHA_SHIFT                (25U)                                               /*!< SPI0_CTAR_SLAVE: CPHA Position          */
#define SPI_CTAR_SLAVE_CPHA(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_CPHA_SHIFT))&SPI_CTAR_SLAVE_CPHA_MASK) /*!< SPI0_CTAR_SLAVE                         */
#define SPI_CTAR_SLAVE_CPOL_MASK                 (0x4000000U)                                        /*!< SPI0_CTAR_SLAVE: CPOL Mask              */
#define SPI_CTAR_SLAVE_CPOL_SHIFT                (26U)                                               /*!< SPI0_CTAR_SLAVE: CPOL Position          */
#define SPI_CTAR_SLAVE_CPOL(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_CPOL_SHIFT))&SPI_CTAR_SLAVE_CPOL_MASK) /*!< SPI0_CTAR_SLAVE                         */
#define SPI_CTAR_SLAVE_FMSZ_MASK                 (0xF8000000U)                                       /*!< SPI0_CTAR_SLAVE: FMSZ Mask              */
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                (27U)                                               /*!< SPI0_CTAR_SLAVE: FMSZ Position          */
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_FMSZ_SHIFT))&SPI_CTAR_SLAVE_FMSZ_MASK) /*!< SPI0_CTAR_SLAVE                         */
/* ------- SR Bit Fields                            ------ */
#define SPI_SR_POPNXTPTR_MASK                    (0xFU)                                              /*!< SPI0_SR: POPNXTPTR Mask                 */
#define SPI_SR_POPNXTPTR_SHIFT                   (0U)                                                /*!< SPI0_SR: POPNXTPTR Position             */
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_SR_POPNXTPTR_SHIFT))&SPI_SR_POPNXTPTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_RXCTR_MASK                        (0xF0U)                                             /*!< SPI0_SR: RXCTR Mask                     */
#define SPI_SR_RXCTR_SHIFT                       (4U)                                                /*!< SPI0_SR: RXCTR Position                 */
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_RXCTR_SHIFT))&SPI_SR_RXCTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TXNXTPTR_MASK                     (0xF00U)                                            /*!< SPI0_SR: TXNXTPTR Mask                  */
#define SPI_SR_TXNXTPTR_SHIFT                    (8U)                                                /*!< SPI0_SR: TXNXTPTR Position              */
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXNXTPTR_SHIFT))&SPI_SR_TXNXTPTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TXCTR_MASK                        (0xF000U)                                           /*!< SPI0_SR: TXCTR Mask                     */
#define SPI_SR_TXCTR_SHIFT                       (12U)                                               /*!< SPI0_SR: TXCTR Position                 */
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXCTR_SHIFT))&SPI_SR_TXCTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_RFDF_MASK                         (0x20000U)                                          /*!< SPI0_SR: RFDF Mask                      */
#define SPI_SR_RFDF_SHIFT                        (17U)                                               /*!< SPI0_SR: RFDF Position                  */
#define SPI_SR_RFDF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_RFDF_SHIFT))&SPI_SR_RFDF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_RFOF_MASK                         (0x80000U)                                          /*!< SPI0_SR: RFOF Mask                      */
#define SPI_SR_RFOF_SHIFT                        (19U)                                               /*!< SPI0_SR: RFOF Position                  */
#define SPI_SR_RFOF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_RFOF_SHIFT))&SPI_SR_RFOF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TFFF_MASK                         (0x2000000U)                                        /*!< SPI0_SR: TFFF Mask                      */
#define SPI_SR_TFFF_SHIFT                        (25U)                                               /*!< SPI0_SR: TFFF Position                  */
#define SPI_SR_TFFF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_TFFF_SHIFT))&SPI_SR_TFFF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TFUF_MASK                         (0x8000000U)                                        /*!< SPI0_SR: TFUF Mask                      */
#define SPI_SR_TFUF_SHIFT                        (27U)                                               /*!< SPI0_SR: TFUF Position                  */
#define SPI_SR_TFUF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_TFUF_SHIFT))&SPI_SR_TFUF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_EOQF_MASK                         (0x10000000U)                                       /*!< SPI0_SR: EOQF Mask                      */
#define SPI_SR_EOQF_SHIFT                        (28U)                                               /*!< SPI0_SR: EOQF Position                  */
#define SPI_SR_EOQF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_EOQF_SHIFT))&SPI_SR_EOQF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TXRXS_MASK                        (0x40000000U)                                       /*!< SPI0_SR: TXRXS Mask                     */
#define SPI_SR_TXRXS_SHIFT                       (30U)                                               /*!< SPI0_SR: TXRXS Position                 */
#define SPI_SR_TXRXS(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXRXS_SHIFT))&SPI_SR_TXRXS_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TCF_MASK                          (0x80000000U)                                       /*!< SPI0_SR: TCF Mask                       */
#define SPI_SR_TCF_SHIFT                         (31U)                                               /*!< SPI0_SR: TCF Position                   */
#define SPI_SR_TCF(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_SR_TCF_SHIFT))&SPI_SR_TCF_MASK) /*!< SPI0_SR                                 */
/* ------- RSER Bit Fields                          ------ */
#define SPI_RSER_RFDF_DIRS_MASK                  (0x10000U)                                          /*!< SPI0_RSER: RFDF_DIRS Mask               */
#define SPI_RSER_RFDF_DIRS_SHIFT                 (16U)                                               /*!< SPI0_RSER: RFDF_DIRS Position           */
#define SPI_RSER_RFDF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFDF_DIRS_SHIFT))&SPI_RSER_RFDF_DIRS_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_RFDF_RE_MASK                    (0x20000U)                                          /*!< SPI0_RSER: RFDF_RE Mask                 */
#define SPI_RSER_RFDF_RE_SHIFT                   (17U)                                               /*!< SPI0_RSER: RFDF_RE Position             */
#define SPI_RSER_RFDF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFDF_RE_SHIFT))&SPI_RSER_RFDF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_RFOF_RE_MASK                    (0x80000U)                                          /*!< SPI0_RSER: RFOF_RE Mask                 */
#define SPI_RSER_RFOF_RE_SHIFT                   (19U)                                               /*!< SPI0_RSER: RFOF_RE Position             */
#define SPI_RSER_RFOF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFOF_RE_SHIFT))&SPI_RSER_RFOF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TFFF_DIRS_MASK                  (0x1000000U)                                        /*!< SPI0_RSER: TFFF_DIRS Mask               */
#define SPI_RSER_TFFF_DIRS_SHIFT                 (24U)                                               /*!< SPI0_RSER: TFFF_DIRS Position           */
#define SPI_RSER_TFFF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFFF_DIRS_SHIFT))&SPI_RSER_TFFF_DIRS_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TFFF_RE_MASK                    (0x2000000U)                                        /*!< SPI0_RSER: TFFF_RE Mask                 */
#define SPI_RSER_TFFF_RE_SHIFT                   (25U)                                               /*!< SPI0_RSER: TFFF_RE Position             */
#define SPI_RSER_TFFF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFFF_RE_SHIFT))&SPI_RSER_TFFF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TFUF_RE_MASK                    (0x8000000U)                                        /*!< SPI0_RSER: TFUF_RE Mask                 */
#define SPI_RSER_TFUF_RE_SHIFT                   (27U)                                               /*!< SPI0_RSER: TFUF_RE Position             */
#define SPI_RSER_TFUF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFUF_RE_SHIFT))&SPI_RSER_TFUF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_EOQF_RE_MASK                    (0x10000000U)                                       /*!< SPI0_RSER: EOQF_RE Mask                 */
#define SPI_RSER_EOQF_RE_SHIFT                   (28U)                                               /*!< SPI0_RSER: EOQF_RE Position             */
#define SPI_RSER_EOQF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_EOQF_RE_SHIFT))&SPI_RSER_EOQF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TCF_RE_MASK                     (0x80000000U)                                       /*!< SPI0_RSER: TCF_RE Mask                  */
#define SPI_RSER_TCF_RE_SHIFT                    (31U)                                               /*!< SPI0_RSER: TCF_RE Position              */
#define SPI_RSER_TCF_RE(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TCF_RE_SHIFT))&SPI_RSER_TCF_RE_MASK) /*!< SPI0_RSER                               */
/* ------- PUSHR Bit Fields                         ------ */
#define SPI_PUSHR_TXDATA_MASK                    (0xFFFFU)                                           /*!< SPI0_PUSHR: TXDATA Mask                 */
#define SPI_PUSHR_TXDATA_SHIFT                   (0U)                                                /*!< SPI0_PUSHR: TXDATA Position             */
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_TXDATA_SHIFT))&SPI_PUSHR_TXDATA_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_PCS_MASK                       (0x3F0000U)                                         /*!< SPI0_PUSHR: PCS Mask                    */
#define SPI_PUSHR_PCS_SHIFT                      (16U)                                               /*!< SPI0_PUSHR: PCS Position                */
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_PCS_SHIFT))&SPI_PUSHR_PCS_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_CTCNT_MASK                     (0x4000000U)                                        /*!< SPI0_PUSHR: CTCNT Mask                  */
#define SPI_PUSHR_CTCNT_SHIFT                    (26U)                                               /*!< SPI0_PUSHR: CTCNT Position              */
#define SPI_PUSHR_CTCNT(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CTCNT_SHIFT))&SPI_PUSHR_CTCNT_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_EOQ_MASK                       (0x8000000U)                                        /*!< SPI0_PUSHR: EOQ Mask                    */
#define SPI_PUSHR_EOQ_SHIFT                      (27U)                                               /*!< SPI0_PUSHR: EOQ Position                */
#define SPI_PUSHR_EOQ(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_EOQ_SHIFT))&SPI_PUSHR_EOQ_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_CTAS_MASK                      (0x70000000U)                                       /*!< SPI0_PUSHR: CTAS Mask                   */
#define SPI_PUSHR_CTAS_SHIFT                     (28U)                                               /*!< SPI0_PUSHR: CTAS Position               */
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CTAS_SHIFT))&SPI_PUSHR_CTAS_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_CONT_MASK                      (0x80000000U)                                       /*!< SPI0_PUSHR: CONT Mask                   */
#define SPI_PUSHR_CONT_SHIFT                     (31U)                                               /*!< SPI0_PUSHR: CONT Position               */
#define SPI_PUSHR_CONT(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CONT_SHIFT))&SPI_PUSHR_CONT_MASK) /*!< SPI0_PUSHR                              */
/* ------- PUSHR_SLAVE Bit Fields                   ------ */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              (0xFFFFU)                                           /*!< SPI0_PUSHR_SLAVE: TXDATA Mask           */
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             (0U)                                                /*!< SPI0_PUSHR_SLAVE: TXDATA Position       */
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_SLAVE_TXDATA_SHIFT))&SPI_PUSHR_SLAVE_TXDATA_MASK) /*!< SPI0_PUSHR_SLAVE                        */
/* ------- POPR Bit Fields                          ------ */
#define SPI_POPR_RXDATA_MASK                     (0xFFFFFFFFU)                                       /*!< SPI0_POPR: RXDATA Mask                  */
#define SPI_POPR_RXDATA_SHIFT                    (0U)                                                /*!< SPI0_POPR: RXDATA Position              */
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_POPR_RXDATA_SHIFT))&SPI_POPR_RXDATA_MASK) /*!< SPI0_POPR                               */
/* ------- TXFR Bit Fields                          ------ */
#define SPI_TXFR_TXDATA_MASK                     (0xFFFFU)                                           /*!< SPI0_TXFR: TXDATA Mask                  */
#define SPI_TXFR_TXDATA_SHIFT                    (0U)                                                /*!< SPI0_TXFR: TXDATA Position              */
#define SPI_TXFR_TXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_TXFR_TXDATA_SHIFT))&SPI_TXFR_TXDATA_MASK) /*!< SPI0_TXFR                               */
#define SPI_TXFR_TXCMD_TXDATA_MASK               (0xFFFF0000U)                                       /*!< SPI0_TXFR: TXCMD_TXDATA Mask            */
#define SPI_TXFR_TXCMD_TXDATA_SHIFT              (16U)                                               /*!< SPI0_TXFR: TXCMD_TXDATA Position        */
#define SPI_TXFR_TXCMD_TXDATA(x)                 (((uint32_t)(((uint32_t)(x))<<SPI_TXFR_TXCMD_TXDATA_SHIFT))&SPI_TXFR_TXCMD_TXDATA_MASK) /*!< SPI0_TXFR                               */
/* ------- RXFR Bit Fields                          ------ */
#define SPI_RXFR_RXDATA_MASK                     (0xFFFFFFFFU)                                       /*!< SPI0_RXFR: RXDATA Mask                  */
#define SPI_RXFR_RXDATA_SHIFT                    (0U)                                                /*!< SPI0_RXFR: RXDATA Position              */
#define SPI_RXFR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_RXFR_RXDATA_SHIFT))&SPI_RXFR_RXDATA_MASK) /*!< SPI0_RXFR                               */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x4002C000UL //!< Peripheral base address
#define SPI0                           ((SPI_Type *) SPI0_BasePtr) //!< Freescale base pointer
#define SPI0_BASE_PTR                  (SPI0) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI1 (derived from SPI0)             ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */

/* SPI1 - Peripheral instance base addresses */
#define SPI1_BasePtr                   0x4002D000UL //!< Peripheral base address
#define SPI1                           ((SPI_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART0 (file:UART0_MK11D5_C7816)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART0 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __IO uint8_t   IR;                           /**< 000E: Infrared Register                                            */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   C7816;                        /**< 0018: 7816 Control Register                                        */
   __IO uint8_t   IE7816;                       /**< 0019: 7816 Interrupt Enable Register                               */
   __IO uint8_t   IS7816;                       /**< 001A: 7816 Interrupt Status Register                               */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   WP7816T0;                  /**< 001B: 7816 Wait Parameter Register                                 */
      __IO uint8_t   WP7816T1;                  /**< 001B: 7816 Wait Parameter Register                                 */
   };
   __IO uint8_t   WN7816;                       /**< 001C: 7816 Wait N Register                                         */
   __IO uint8_t   WF7816;                       /**< 001D: 7816 Wait FD Register                                        */
   __IO uint8_t   ET7816;                       /**< 001E: 7816 Error Threshold Register                                */
   __IO uint8_t   TL7816;                       /**< 001F: 7816 Transmit Length Register                                */
} UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
#define UART_BDH_SBR_MASK                        (0x1FU)                                             /*!< UART0_BDH: SBR Mask                     */
#define UART_BDH_SBR_SHIFT                       (0U)                                                /*!< UART0_BDH: SBR Position                 */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /*!< UART0_BDH                               */
#define UART_BDH_RXEDGIE_MASK                    (0x40U)                                             /*!< UART0_BDH: RXEDGIE Mask                 */
#define UART_BDH_RXEDGIE_SHIFT                   (6U)                                                /*!< UART0_BDH: RXEDGIE Position             */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_BDH_RXEDGIE_SHIFT))&UART_BDH_RXEDGIE_MASK) /*!< UART0_BDH                               */
#define UART_BDH_LBKDIE_MASK                     (0x80U)                                             /*!< UART0_BDH: LBKDIE Mask                  */
#define UART_BDH_LBKDIE_SHIFT                    (7U)                                                /*!< UART0_BDH: LBKDIE Position              */
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_BDH_LBKDIE_SHIFT))&UART_BDH_LBKDIE_MASK) /*!< UART0_BDH                               */
/* ------- BDL Bit Fields                           ------ */
#define UART_BDL_SBR_MASK                        (0xFFU)                                             /*!< UART0_BDL: SBR Mask                     */
#define UART_BDL_SBR_SHIFT                       (0U)                                                /*!< UART0_BDL: SBR Position                 */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /*!< UART0_BDL                               */
/* ------- C1 Bit Fields                            ------ */
#define UART_C1_PT_MASK                          (0x1U)                                              /*!< UART0_C1: PT Mask                       */
#define UART_C1_PT_SHIFT                         (0U)                                                /*!< UART0_C1: PT Position                   */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PT_SHIFT))&UART_C1_PT_MASK) /*!< UART0_C1                                */
#define UART_C1_PE_MASK                          (0x2U)                                              /*!< UART0_C1: PE Mask                       */
#define UART_C1_PE_SHIFT                         (1U)                                                /*!< UART0_C1: PE Position                   */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PE_SHIFT))&UART_C1_PE_MASK) /*!< UART0_C1                                */
#define UART_C1_ILT_MASK                         (0x4U)                                              /*!< UART0_C1: ILT Mask                      */
#define UART_C1_ILT_SHIFT                        (2U)                                                /*!< UART0_C1: ILT Position                  */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C1_ILT_SHIFT))&UART_C1_ILT_MASK) /*!< UART0_C1                                */
#define UART_C1_WAKE_MASK                        (0x8U)                                              /*!< UART0_C1: WAKE Mask                     */
#define UART_C1_WAKE_SHIFT                       (3U)                                                /*!< UART0_C1: WAKE Position                 */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_WAKE_SHIFT))&UART_C1_WAKE_MASK) /*!< UART0_C1                                */
#define UART_C1_M_MASK                           (0x10U)                                             /*!< UART0_C1: M Mask                        */
#define UART_C1_M_SHIFT                          (4U)                                                /*!< UART0_C1: M Position                    */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x))<<UART_C1_M_SHIFT))&UART_C1_M_MASK) /*!< UART0_C1                                */
#define UART_C1_RSRC_MASK                        (0x20U)                                             /*!< UART0_C1: RSRC Mask                     */
#define UART_C1_RSRC_SHIFT                       (5U)                                                /*!< UART0_C1: RSRC Position                 */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_RSRC_SHIFT))&UART_C1_RSRC_MASK) /*!< UART0_C1                                */
#define UART_C1_UARTSWAI_MASK                    (0x40U)                                             /*!< UART0_C1: UARTSWAI Mask                 */
#define UART_C1_UARTSWAI_SHIFT                   (6U)                                                /*!< UART0_C1: UARTSWAI Position             */
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C1_UARTSWAI_SHIFT))&UART_C1_UARTSWAI_MASK) /*!< UART0_C1                                */
#define UART_C1_LOOPS_MASK                       (0x80U)                                             /*!< UART0_C1: LOOPS Mask                    */
#define UART_C1_LOOPS_SHIFT                      (7U)                                                /*!< UART0_C1: LOOPS Position                */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C1_LOOPS_SHIFT))&UART_C1_LOOPS_MASK) /*!< UART0_C1                                */
/* ------- C2 Bit Fields                            ------ */
#define UART_C2_SBK_MASK                         (0x1U)                                              /*!< UART0_C2: SBK Mask                      */
#define UART_C2_SBK_SHIFT                        (0U)                                                /*!< UART0_C2: SBK Position                  */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_SBK_SHIFT))&UART_C2_SBK_MASK) /*!< UART0_C2                                */
#define UART_C2_RWU_MASK                         (0x2U)                                              /*!< UART0_C2: RWU Mask                      */
#define UART_C2_RWU_SHIFT                        (1U)                                                /*!< UART0_C2: RWU Position                  */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RWU_SHIFT))&UART_C2_RWU_MASK) /*!< UART0_C2                                */
#define UART_C2_RE_MASK                          (0x4U)                                              /*!< UART0_C2: RE Mask                       */
#define UART_C2_RE_SHIFT                         (2U)                                                /*!< UART0_C2: RE Position                   */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_RE_SHIFT))&UART_C2_RE_MASK) /*!< UART0_C2                                */
#define UART_C2_TE_MASK                          (0x8U)                                              /*!< UART0_C2: TE Mask                       */
#define UART_C2_TE_SHIFT                         (3U)                                                /*!< UART0_C2: TE Position                   */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_TE_SHIFT))&UART_C2_TE_MASK) /*!< UART0_C2                                */
#define UART_C2_ILIE_MASK                        (0x10U)                                             /*!< UART0_C2: ILIE Mask                     */
#define UART_C2_ILIE_SHIFT                       (4U)                                                /*!< UART0_C2: ILIE Position                 */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_ILIE_SHIFT))&UART_C2_ILIE_MASK) /*!< UART0_C2                                */
#define UART_C2_RIE_MASK                         (0x20U)                                             /*!< UART0_C2: RIE Mask                      */
#define UART_C2_RIE_SHIFT                        (5U)                                                /*!< UART0_C2: RIE Position                  */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RIE_SHIFT))&UART_C2_RIE_MASK) /*!< UART0_C2                                */
#define UART_C2_TCIE_MASK                        (0x40U)                                             /*!< UART0_C2: TCIE Mask                     */
#define UART_C2_TCIE_SHIFT                       (6U)                                                /*!< UART0_C2: TCIE Position                 */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_TCIE_SHIFT))&UART_C2_TCIE_MASK) /*!< UART0_C2                                */
#define UART_C2_TIE_MASK                         (0x80U)                                             /*!< UART0_C2: TIE Mask                      */
#define UART_C2_TIE_SHIFT                        (7U)                                                /*!< UART0_C2: TIE Position                  */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_TIE_SHIFT))&UART_C2_TIE_MASK) /*!< UART0_C2                                */
/* ------- S1 Bit Fields                            ------ */
#define UART_S1_PF_MASK                          (0x1U)                                              /*!< UART0_S1: PF Mask                       */
#define UART_S1_PF_SHIFT                         (0U)                                                /*!< UART0_S1: PF Position                   */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_PF_SHIFT))&UART_S1_PF_MASK) /*!< UART0_S1                                */
#define UART_S1_FE_MASK                          (0x2U)                                              /*!< UART0_S1: FE Mask                       */
#define UART_S1_FE_SHIFT                         (1U)                                                /*!< UART0_S1: FE Position                   */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_FE_SHIFT))&UART_S1_FE_MASK) /*!< UART0_S1                                */
#define UART_S1_NF_MASK                          (0x4U)                                              /*!< UART0_S1: NF Mask                       */
#define UART_S1_NF_SHIFT                         (2U)                                                /*!< UART0_S1: NF Position                   */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_NF_SHIFT))&UART_S1_NF_MASK) /*!< UART0_S1                                */
#define UART_S1_OR_MASK                          (0x8U)                                              /*!< UART0_S1: OR Mask                       */
#define UART_S1_OR_SHIFT                         (3U)                                                /*!< UART0_S1: OR Position                   */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_OR_SHIFT))&UART_S1_OR_MASK) /*!< UART0_S1                                */
#define UART_S1_IDLE_MASK                        (0x10U)                                             /*!< UART0_S1: IDLE Mask                     */
#define UART_S1_IDLE_SHIFT                       (4U)                                                /*!< UART0_S1: IDLE Position                 */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_IDLE_SHIFT))&UART_S1_IDLE_MASK) /*!< UART0_S1                                */
#define UART_S1_RDRF_MASK                        (0x20U)                                             /*!< UART0_S1: RDRF Mask                     */
#define UART_S1_RDRF_SHIFT                       (5U)                                                /*!< UART0_S1: RDRF Position                 */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_RDRF_SHIFT))&UART_S1_RDRF_MASK) /*!< UART0_S1                                */
#define UART_S1_TC_MASK                          (0x40U)                                             /*!< UART0_S1: TC Mask                       */
#define UART_S1_TC_SHIFT                         (6U)                                                /*!< UART0_S1: TC Position                   */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_TC_SHIFT))&UART_S1_TC_MASK) /*!< UART0_S1                                */
#define UART_S1_TDRE_MASK                        (0x80U)                                             /*!< UART0_S1: TDRE Mask                     */
#define UART_S1_TDRE_SHIFT                       (7U)                                                /*!< UART0_S1: TDRE Position                 */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_TDRE_SHIFT))&UART_S1_TDRE_MASK) /*!< UART0_S1                                */
/* ------- S2 Bit Fields                            ------ */
#define UART_S2_RAF_MASK                         (0x1U)                                              /*!< UART0_S2: RAF Mask                      */
#define UART_S2_RAF_SHIFT                        (0U)                                                /*!< UART0_S2: RAF Position                  */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x))<<UART_S2_RAF_SHIFT))&UART_S2_RAF_MASK) /*!< UART0_S2                                */
#define UART_S2_LBKDE_MASK                       (0x2U)                                              /*!< UART0_S2: LBKDE Mask                    */
#define UART_S2_LBKDE_SHIFT                      (1U)                                                /*!< UART0_S2: LBKDE Position                */
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDE_SHIFT))&UART_S2_LBKDE_MASK) /*!< UART0_S2                                */
#define UART_S2_BRK13_MASK                       (0x4U)                                              /*!< UART0_S2: BRK13 Mask                    */
#define UART_S2_BRK13_SHIFT                      (2U)                                                /*!< UART0_S2: BRK13 Position                */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_BRK13_SHIFT))&UART_S2_BRK13_MASK) /*!< UART0_S2                                */
#define UART_S2_RWUID_MASK                       (0x8U)                                              /*!< UART0_S2: RWUID Mask                    */
#define UART_S2_RWUID_SHIFT                      (3U)                                                /*!< UART0_S2: RWUID Position                */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RWUID_SHIFT))&UART_S2_RWUID_MASK) /*!< UART0_S2                                */
#define UART_S2_RXINV_MASK                       (0x10U)                                             /*!< UART0_S2: RXINV Mask                    */
#define UART_S2_RXINV_SHIFT                      (4U)                                                /*!< UART0_S2: RXINV Position                */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RXINV_SHIFT))&UART_S2_RXINV_MASK) /*!< UART0_S2                                */
#define UART_S2_MSBF_MASK                        (0x20U)                                             /*!< UART0_S2: MSBF Mask                     */
#define UART_S2_MSBF_SHIFT                       (5U)                                                /*!< UART0_S2: MSBF Position                 */
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S2_MSBF_SHIFT))&UART_S2_MSBF_MASK) /*!< UART0_S2                                */
#define UART_S2_RXEDGIF_MASK                     (0x40U)                                             /*!< UART0_S2: RXEDGIF Mask                  */
#define UART_S2_RXEDGIF_SHIFT                    (6U)                                                /*!< UART0_S2: RXEDGIF Position              */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_S2_RXEDGIF_SHIFT))&UART_S2_RXEDGIF_MASK) /*!< UART0_S2                                */
#define UART_S2_LBKDIF_MASK                      (0x80U)                                             /*!< UART0_S2: LBKDIF Mask                   */
#define UART_S2_LBKDIF_SHIFT                     (7U)                                                /*!< UART0_S2: LBKDIF Position               */
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDIF_SHIFT))&UART_S2_LBKDIF_MASK) /*!< UART0_S2                                */
/* ------- C3 Bit Fields                            ------ */
#define UART_C3_PEIE_MASK                        (0x1U)                                              /*!< UART0_C3: PEIE Mask                     */
#define UART_C3_PEIE_SHIFT                       (0U)                                                /*!< UART0_C3: PEIE Position                 */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_PEIE_SHIFT))&UART_C3_PEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_FEIE_MASK                        (0x2U)                                              /*!< UART0_C3: FEIE Mask                     */
#define UART_C3_FEIE_SHIFT                       (1U)                                                /*!< UART0_C3: FEIE Position                 */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_FEIE_SHIFT))&UART_C3_FEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_NEIE_MASK                        (0x4U)                                              /*!< UART0_C3: NEIE Mask                     */
#define UART_C3_NEIE_SHIFT                       (2U)                                                /*!< UART0_C3: NEIE Position                 */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_NEIE_SHIFT))&UART_C3_NEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_ORIE_MASK                        (0x8U)                                              /*!< UART0_C3: ORIE Mask                     */
#define UART_C3_ORIE_SHIFT                       (3U)                                                /*!< UART0_C3: ORIE Position                 */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_ORIE_SHIFT))&UART_C3_ORIE_MASK) /*!< UART0_C3                                */
#define UART_C3_TXINV_MASK                       (0x10U)                                             /*!< UART0_C3: TXINV Mask                    */
#define UART_C3_TXINV_SHIFT                      (4U)                                                /*!< UART0_C3: TXINV Position                */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXINV_SHIFT))&UART_C3_TXINV_MASK) /*!< UART0_C3                                */
#define UART_C3_TXDIR_MASK                       (0x20U)                                             /*!< UART0_C3: TXDIR Mask                    */
#define UART_C3_TXDIR_SHIFT                      (5U)                                                /*!< UART0_C3: TXDIR Position                */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXDIR_SHIFT))&UART_C3_TXDIR_MASK) /*!< UART0_C3                                */
#define UART_C3_T8_MASK                          (0x40U)                                             /*!< UART0_C3: T8 Mask                       */
#define UART_C3_T8_SHIFT                         (6U)                                                /*!< UART0_C3: T8 Position                   */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_T8_SHIFT))&UART_C3_T8_MASK) /*!< UART0_C3                                */
#define UART_C3_R8_MASK                          (0x80U)                                             /*!< UART0_C3: R8 Mask                       */
#define UART_C3_R8_SHIFT                         (7U)                                                /*!< UART0_C3: R8 Position                   */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_R8_SHIFT))&UART_C3_R8_MASK) /*!< UART0_C3                                */
/* ------- D Bit Fields                             ------ */
#define UART_D_RT_MASK                           (0xFFU)                                             /*!< UART0_D: RT Mask                        */
#define UART_D_RT_SHIFT                          (0U)                                                /*!< UART0_D: RT Position                    */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /*!< UART0_D                                 */
/* ------- MA Bit Fields                            ------ */
#define UART_MA_MA_MASK                          (0xFFU)                                             /*!< UART0_MA: MA Mask                       */
#define UART_MA_MA_SHIFT                         (0U)                                                /*!< UART0_MA: MA Position                   */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /*!< UART0_MA                                */
/* ------- C4 Bit Fields                            ------ */
#define UART_C4_BRFA_MASK                        (0x1FU)                                             /*!< UART0_C4: BRFA Mask                     */
#define UART_C4_BRFA_SHIFT                       (0U)                                                /*!< UART0_C4: BRFA Position                 */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK) /*!< UART0_C4                                */
#define UART_C4_M10_MASK                         (0x20U)                                             /*!< UART0_C4: M10 Mask                      */
#define UART_C4_M10_SHIFT                        (5U)                                                /*!< UART0_C4: M10 Position                  */
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C4_M10_SHIFT))&UART_C4_M10_MASK) /*!< UART0_C4                                */
#define UART_C4_MAEN2_MASK                       (0x40U)                                             /*!< UART0_C4: MAEN2 Mask                    */
#define UART_C4_MAEN2_SHIFT                      (6U)                                                /*!< UART0_C4: MAEN2 Position                */
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN2_SHIFT))&UART_C4_MAEN2_MASK) /*!< UART0_C4                                */
#define UART_C4_MAEN1_MASK                       (0x80U)                                             /*!< UART0_C4: MAEN1 Mask                    */
#define UART_C4_MAEN1_SHIFT                      (7U)                                                /*!< UART0_C4: MAEN1 Position                */
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN1_SHIFT))&UART_C4_MAEN1_MASK) /*!< UART0_C4                                */
/* ------- C5 Bit Fields                            ------ */
#define UART_C5_RDMAS_MASK                       (0x20U)                                             /*!< UART0_C5: RDMAS Mask                    */
#define UART_C5_RDMAS_SHIFT                      (5U)                                                /*!< UART0_C5: RDMAS Position                */
#define UART_C5_RDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_RDMAS_SHIFT))&UART_C5_RDMAS_MASK) /*!< UART0_C5                                */
#define UART_C5_TDMAS_MASK                       (0x80U)                                             /*!< UART0_C5: TDMAS Mask                    */
#define UART_C5_TDMAS_SHIFT                      (7U)                                                /*!< UART0_C5: TDMAS Position                */
#define UART_C5_TDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_TDMAS_SHIFT))&UART_C5_TDMAS_MASK) /*!< UART0_C5                                */
/* ------- ED Bit Fields                            ------ */
#define UART_ED_PARITYE_MASK                     (0x40U)                                             /*!< UART0_ED: PARITYE Mask                  */
#define UART_ED_PARITYE_SHIFT                    (6U)                                                /*!< UART0_ED: PARITYE Position              */
#define UART_ED_PARITYE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_ED_PARITYE_SHIFT))&UART_ED_PARITYE_MASK) /*!< UART0_ED                                */
#define UART_ED_NOISY_MASK                       (0x80U)                                             /*!< UART0_ED: NOISY Mask                    */
#define UART_ED_NOISY_SHIFT                      (7U)                                                /*!< UART0_ED: NOISY Position                */
#define UART_ED_NOISY(x)                         (((uint8_t)(((uint8_t)(x))<<UART_ED_NOISY_SHIFT))&UART_ED_NOISY_MASK) /*!< UART0_ED                                */
/* ------- MODEM Bit Fields                         ------ */
#define UART_MODEM_TXCTSE_MASK                   (0x1U)                                              /*!< UART0_MODEM: TXCTSE Mask                */
#define UART_MODEM_TXCTSE_SHIFT                  (0U)                                                /*!< UART0_MODEM: TXCTSE Position            */
#define UART_MODEM_TXCTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXCTSE_SHIFT))&UART_MODEM_TXCTSE_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_TXRTSE_MASK                   (0x2U)                                              /*!< UART0_MODEM: TXRTSE Mask                */
#define UART_MODEM_TXRTSE_SHIFT                  (1U)                                                /*!< UART0_MODEM: TXRTSE Position            */
#define UART_MODEM_TXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXRTSE_SHIFT))&UART_MODEM_TXRTSE_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_TXRTSPOL_MASK                 (0x4U)                                              /*!< UART0_MODEM: TXRTSPOL Mask              */
#define UART_MODEM_TXRTSPOL_SHIFT                (2U)                                                /*!< UART0_MODEM: TXRTSPOL Position          */
#define UART_MODEM_TXRTSPOL(x)                   (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXRTSPOL_SHIFT))&UART_MODEM_TXRTSPOL_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_RXRTSE_MASK                   (0x8U)                                              /*!< UART0_MODEM: RXRTSE Mask                */
#define UART_MODEM_RXRTSE_SHIFT                  (3U)                                                /*!< UART0_MODEM: RXRTSE Position            */
#define UART_MODEM_RXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_RXRTSE_SHIFT))&UART_MODEM_RXRTSE_MASK) /*!< UART0_MODEM                             */
/* ------- IR Bit Fields                            ------ */
#define UART_IR_TNP_MASK                         (0x3U)                                              /*!< UART0_IR: TNP Mask                      */
#define UART_IR_TNP_SHIFT                        (0U)                                                /*!< UART0_IR: TNP Position                  */
#define UART_IR_TNP(x)                           (((uint8_t)(((uint8_t)(x))<<UART_IR_TNP_SHIFT))&UART_IR_TNP_MASK) /*!< UART0_IR                                */
#define UART_IR_IREN_MASK                        (0x4U)                                              /*!< UART0_IR: IREN Mask                     */
#define UART_IR_IREN_SHIFT                       (2U)                                                /*!< UART0_IR: IREN Position                 */
#define UART_IR_IREN(x)                          (((uint8_t)(((uint8_t)(x))<<UART_IR_IREN_SHIFT))&UART_IR_IREN_MASK) /*!< UART0_IR                                */
/* ------- PFIFO Bit Fields                         ------ */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x7U)                                              /*!< UART0_PFIFO: RXFIFOSIZE Mask            */
#define UART_PFIFO_RXFIFOSIZE_SHIFT              (0U)                                                /*!< UART0_PFIFO: RXFIFOSIZE Position        */
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_RXFE_MASK                     (0x8U)                                              /*!< UART0_PFIFO: RXFE Mask                  */
#define UART_PFIFO_RXFE_SHIFT                    (3U)                                                /*!< UART0_PFIFO: RXFE Position              */
#define UART_PFIFO_RXFE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFE_SHIFT))&UART_PFIFO_RXFE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x70U)                                             /*!< UART0_PFIFO: TXFIFOSIZE Mask            */
#define UART_PFIFO_TXFIFOSIZE_SHIFT              (4U)                                                /*!< UART0_PFIFO: TXFIFOSIZE Position        */
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFE_MASK                     (0x80U)                                             /*!< UART0_PFIFO: TXFE Mask                  */
#define UART_PFIFO_TXFE_SHIFT                    (7U)                                                /*!< UART0_PFIFO: TXFE Position              */
#define UART_PFIFO_TXFE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFE_SHIFT))&UART_PFIFO_TXFE_MASK) /*!< UART0_PFIFO                             */
/* ------- CFIFO Bit Fields                         ------ */
#define UART_CFIFO_RXUFE_MASK                    (0x1U)                                              /*!< UART0_CFIFO: RXUFE Mask                 */
#define UART_CFIFO_RXUFE_SHIFT                   (0U)                                                /*!< UART0_CFIFO: RXUFE Position             */
#define UART_CFIFO_RXUFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXUFE_SHIFT))&UART_CFIFO_RXUFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_TXOFE_MASK                    (0x2U)                                              /*!< UART0_CFIFO: TXOFE Mask                 */
#define UART_CFIFO_TXOFE_SHIFT                   (1U)                                                /*!< UART0_CFIFO: TXOFE Position             */
#define UART_CFIFO_TXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_TXOFE_SHIFT))&UART_CFIFO_TXOFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_RXOFE_MASK                    (0x4U)                                              /*!< UART0_CFIFO: RXOFE Mask                 */
#define UART_CFIFO_RXOFE_SHIFT                   (2U)                                                /*!< UART0_CFIFO: RXOFE Position             */
#define UART_CFIFO_RXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXOFE_SHIFT))&UART_CFIFO_RXOFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_RXFLUSH_MASK                  (0x40U)                                             /*!< UART0_CFIFO: RXFLUSH Mask               */
#define UART_CFIFO_RXFLUSH_SHIFT                 (6U)                                                /*!< UART0_CFIFO: RXFLUSH Position           */
#define UART_CFIFO_RXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXFLUSH_SHIFT))&UART_CFIFO_RXFLUSH_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_TXFLUSH_MASK                  (0x80U)                                             /*!< UART0_CFIFO: TXFLUSH Mask               */
#define UART_CFIFO_TXFLUSH_SHIFT                 (7U)                                                /*!< UART0_CFIFO: TXFLUSH Position           */
#define UART_CFIFO_TXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_TXFLUSH_SHIFT))&UART_CFIFO_TXFLUSH_MASK) /*!< UART0_CFIFO                             */
/* ------- SFIFO Bit Fields                         ------ */
#define UART_SFIFO_RXUF_MASK                     (0x1U)                                              /*!< UART0_SFIFO: RXUF Mask                  */
#define UART_SFIFO_RXUF_SHIFT                    (0U)                                                /*!< UART0_SFIFO: RXUF Position              */
#define UART_SFIFO_RXUF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXUF_SHIFT))&UART_SFIFO_RXUF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_TXOF_MASK                     (0x2U)                                              /*!< UART0_SFIFO: TXOF Mask                  */
#define UART_SFIFO_TXOF_SHIFT                    (1U)                                                /*!< UART0_SFIFO: TXOF Position              */
#define UART_SFIFO_TXOF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_TXOF_SHIFT))&UART_SFIFO_TXOF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_RXOF_MASK                     (0x4U)                                              /*!< UART0_SFIFO: RXOF Mask                  */
#define UART_SFIFO_RXOF_SHIFT                    (2U)                                                /*!< UART0_SFIFO: RXOF Position              */
#define UART_SFIFO_RXOF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXOF_SHIFT))&UART_SFIFO_RXOF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_RXEMPT_MASK                   (0x40U)                                             /*!< UART0_SFIFO: RXEMPT Mask                */
#define UART_SFIFO_RXEMPT_SHIFT                  (6U)                                                /*!< UART0_SFIFO: RXEMPT Position            */
#define UART_SFIFO_RXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXEMPT_SHIFT))&UART_SFIFO_RXEMPT_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_TXEMPT_MASK                   (0x80U)                                             /*!< UART0_SFIFO: TXEMPT Mask                */
#define UART_SFIFO_TXEMPT_SHIFT                  (7U)                                                /*!< UART0_SFIFO: TXEMPT Position            */
#define UART_SFIFO_TXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_TXEMPT_SHIFT))&UART_SFIFO_TXEMPT_MASK) /*!< UART0_SFIFO                             */
/* ------- TWFIFO Bit Fields                        ------ */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFU)                                             /*!< UART0_TWFIFO: TXWATER Mask              */
#define UART_TWFIFO_TXWATER_SHIFT                (0U)                                                /*!< UART0_TWFIFO: TXWATER Position          */
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK) /*!< UART0_TWFIFO                            */
/* ------- TCFIFO Bit Fields                        ------ */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFU)                                             /*!< UART0_TCFIFO: TXCOUNT Mask              */
#define UART_TCFIFO_TXCOUNT_SHIFT                (0U)                                                /*!< UART0_TCFIFO: TXCOUNT Position          */
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK) /*!< UART0_TCFIFO                            */
/* ------- RWFIFO Bit Fields                        ------ */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFU)                                             /*!< UART0_RWFIFO: RXWATER Mask              */
#define UART_RWFIFO_RXWATER_SHIFT                (0U)                                                /*!< UART0_RWFIFO: RXWATER Position          */
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK) /*!< UART0_RWFIFO                            */
/* ------- RCFIFO Bit Fields                        ------ */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFU)                                             /*!< UART0_RCFIFO: RXCOUNT Mask              */
#define UART_RCFIFO_RXCOUNT_SHIFT                (0U)                                                /*!< UART0_RCFIFO: RXCOUNT Position          */
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK) /*!< UART0_RCFIFO                            */
/* ------- C7816 Bit Fields                         ------ */
#define UART_C7816_ISO_7816E_MASK                (0x1U)                                              /*!< UART0_C7816: ISO_7816E Mask             */
#define UART_C7816_ISO_7816E_SHIFT               (0U)                                                /*!< UART0_C7816: ISO_7816E Position         */
#define UART_C7816_ISO_7816E(x)                  (((uint8_t)(((uint8_t)(x))<<UART_C7816_ISO_7816E_SHIFT))&UART_C7816_ISO_7816E_MASK) /*!< UART0_C7816                             */
#define UART_C7816_TTYPE_MASK                    (0x2U)                                              /*!< UART0_C7816: TTYPE Mask                 */
#define UART_C7816_TTYPE_SHIFT                   (1U)                                                /*!< UART0_C7816: TTYPE Position             */
#define UART_C7816_TTYPE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_TTYPE_SHIFT))&UART_C7816_TTYPE_MASK) /*!< UART0_C7816                             */
#define UART_C7816_INIT_MASK                     (0x4U)                                              /*!< UART0_C7816: INIT Mask                  */
#define UART_C7816_INIT_SHIFT                    (2U)                                                /*!< UART0_C7816: INIT Position              */
#define UART_C7816_INIT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_C7816_INIT_SHIFT))&UART_C7816_INIT_MASK) /*!< UART0_C7816                             */
#define UART_C7816_ANACK_MASK                    (0x8U)                                              /*!< UART0_C7816: ANACK Mask                 */
#define UART_C7816_ANACK_SHIFT                   (3U)                                                /*!< UART0_C7816: ANACK Position             */
#define UART_C7816_ANACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ANACK_SHIFT))&UART_C7816_ANACK_MASK) /*!< UART0_C7816                             */
#define UART_C7816_ONACK_MASK                    (0x10U)                                             /*!< UART0_C7816: ONACK Mask                 */
#define UART_C7816_ONACK_SHIFT                   (4U)                                                /*!< UART0_C7816: ONACK Position             */
#define UART_C7816_ONACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ONACK_SHIFT))&UART_C7816_ONACK_MASK) /*!< UART0_C7816                             */
/* ------- IE7816 Bit Fields                        ------ */
#define UART_IE7816_RXTE_MASK                    (0x1U)                                              /*!< UART0_IE7816: RXTE Mask                 */
#define UART_IE7816_RXTE_SHIFT                   (0U)                                                /*!< UART0_IE7816: RXTE Position             */
#define UART_IE7816_RXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_RXTE_SHIFT))&UART_IE7816_RXTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_TXTE_MASK                    (0x2U)                                              /*!< UART0_IE7816: TXTE Mask                 */
#define UART_IE7816_TXTE_SHIFT                   (1U)                                                /*!< UART0_IE7816: TXTE Position             */
#define UART_IE7816_TXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_TXTE_SHIFT))&UART_IE7816_TXTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_GTVE_MASK                    (0x4U)                                              /*!< UART0_IE7816: GTVE Mask                 */
#define UART_IE7816_GTVE_SHIFT                   (2U)                                                /*!< UART0_IE7816: GTVE Position             */
#define UART_IE7816_GTVE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_GTVE_SHIFT))&UART_IE7816_GTVE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_INITDE_MASK                  (0x10U)                                             /*!< UART0_IE7816: INITDE Mask               */
#define UART_IE7816_INITDE_SHIFT                 (4U)                                                /*!< UART0_IE7816: INITDE Position           */
#define UART_IE7816_INITDE(x)                    (((uint8_t)(((uint8_t)(x))<<UART_IE7816_INITDE_SHIFT))&UART_IE7816_INITDE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_BWTE_MASK                    (0x20U)                                             /*!< UART0_IE7816: BWTE Mask                 */
#define UART_IE7816_BWTE_SHIFT                   (5U)                                                /*!< UART0_IE7816: BWTE Position             */
#define UART_IE7816_BWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_BWTE_SHIFT))&UART_IE7816_BWTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_CWTE_MASK                    (0x40U)                                             /*!< UART0_IE7816: CWTE Mask                 */
#define UART_IE7816_CWTE_SHIFT                   (6U)                                                /*!< UART0_IE7816: CWTE Position             */
#define UART_IE7816_CWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_CWTE_SHIFT))&UART_IE7816_CWTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_WTE_MASK                     (0x80U)                                             /*!< UART0_IE7816: WTE Mask                  */
#define UART_IE7816_WTE_SHIFT                    (7U)                                                /*!< UART0_IE7816: WTE Position              */
#define UART_IE7816_WTE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IE7816_WTE_SHIFT))&UART_IE7816_WTE_MASK) /*!< UART0_IE7816                            */
/* ------- IS7816 Bit Fields                        ------ */
#define UART_IS7816_RXT_MASK                     (0x1U)                                              /*!< UART0_IS7816: RXT Mask                  */
#define UART_IS7816_RXT_SHIFT                    (0U)                                                /*!< UART0_IS7816: RXT Position              */
#define UART_IS7816_RXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_RXT_SHIFT))&UART_IS7816_RXT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_TXT_MASK                     (0x2U)                                              /*!< UART0_IS7816: TXT Mask                  */
#define UART_IS7816_TXT_SHIFT                    (1U)                                                /*!< UART0_IS7816: TXT Position              */
#define UART_IS7816_TXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_TXT_SHIFT))&UART_IS7816_TXT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_GTV_MASK                     (0x4U)                                              /*!< UART0_IS7816: GTV Mask                  */
#define UART_IS7816_GTV_SHIFT                    (2U)                                                /*!< UART0_IS7816: GTV Position              */
#define UART_IS7816_GTV(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_GTV_SHIFT))&UART_IS7816_GTV_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_INITD_MASK                   (0x10U)                                             /*!< UART0_IS7816: INITD Mask                */
#define UART_IS7816_INITD_SHIFT                  (4U)                                                /*!< UART0_IS7816: INITD Position            */
#define UART_IS7816_INITD(x)                     (((uint8_t)(((uint8_t)(x))<<UART_IS7816_INITD_SHIFT))&UART_IS7816_INITD_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_BWT_MASK                     (0x20U)                                             /*!< UART0_IS7816: BWT Mask                  */
#define UART_IS7816_BWT_SHIFT                    (5U)                                                /*!< UART0_IS7816: BWT Position              */
#define UART_IS7816_BWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_BWT_SHIFT))&UART_IS7816_BWT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_CWT_MASK                     (0x40U)                                             /*!< UART0_IS7816: CWT Mask                  */
#define UART_IS7816_CWT_SHIFT                    (6U)                                                /*!< UART0_IS7816: CWT Position              */
#define UART_IS7816_CWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_CWT_SHIFT))&UART_IS7816_CWT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_WT_MASK                      (0x80U)                                             /*!< UART0_IS7816: WT Mask                   */
#define UART_IS7816_WT_SHIFT                     (7U)                                                /*!< UART0_IS7816: WT Position               */
#define UART_IS7816_WT(x)                        (((uint8_t)(((uint8_t)(x))<<UART_IS7816_WT_SHIFT))&UART_IS7816_WT_MASK) /*!< UART0_IS7816                            */
/* ------- WP7816T0 Bit Fields                      ------ */
#define UART_WP7816T0_WI_MASK                    (0xFFU)                                             /*!< UART0_WP7816T0: WI Mask                 */
#define UART_WP7816T0_WI_SHIFT                   (0U)                                                /*!< UART0_WP7816T0: WI Position             */
#define UART_WP7816T0_WI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WP7816T0_WI_SHIFT))&UART_WP7816T0_WI_MASK) /*!< UART0_WP7816T0                          */
/* ------- WP7816T1 Bit Fields                      ------ */
#define UART_WP7816T1_BWI_MASK                   (0xFU)                                              /*!< UART0_WP7816T1: BWI Mask                */
#define UART_WP7816T1_BWI_SHIFT                  (0U)                                                /*!< UART0_WP7816T1: BWI Position            */
#define UART_WP7816T1_BWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_BWI_SHIFT))&UART_WP7816T1_BWI_MASK) /*!< UART0_WP7816T1                          */
#define UART_WP7816T1_CWI_MASK                   (0xF0U)                                             /*!< UART0_WP7816T1: CWI Mask                */
#define UART_WP7816T1_CWI_SHIFT                  (4U)                                                /*!< UART0_WP7816T1: CWI Position            */
#define UART_WP7816T1_CWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_CWI_SHIFT))&UART_WP7816T1_CWI_MASK) /*!< UART0_WP7816T1                          */
/* ------- WN7816 Bit Fields                        ------ */
#define UART_WN7816_GTN_MASK                     (0xFFU)                                             /*!< UART0_WN7816: GTN Mask                  */
#define UART_WN7816_GTN_SHIFT                    (0U)                                                /*!< UART0_WN7816: GTN Position              */
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK) /*!< UART0_WN7816                            */
/* ------- WF7816 Bit Fields                        ------ */
#define UART_WF7816_GTFD_MASK                    (0xFFU)                                             /*!< UART0_WF7816: GTFD Mask                 */
#define UART_WF7816_GTFD_SHIFT                   (0U)                                                /*!< UART0_WF7816: GTFD Position             */
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK) /*!< UART0_WF7816                            */
/* ------- ET7816 Bit Fields                        ------ */
#define UART_ET7816_RXTHRESHOLD_MASK             (0xFU)                                              /*!< UART0_ET7816: RXTHRESHOLD Mask          */
#define UART_ET7816_RXTHRESHOLD_SHIFT            (0U)                                                /*!< UART0_ET7816: RXTHRESHOLD Position      */
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK) /*!< UART0_ET7816                            */
#define UART_ET7816_TXTHRESHOLD_MASK             (0xF0U)                                             /*!< UART0_ET7816: TXTHRESHOLD Mask          */
#define UART_ET7816_TXTHRESHOLD_SHIFT            (4U)                                                /*!< UART0_ET7816: TXTHRESHOLD Position      */
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK) /*!< UART0_ET7816                            */
/* ------- TL7816 Bit Fields                        ------ */
#define UART_TL7816_TLEN_MASK                    (0xFFU)                                             /*!< UART0_TL7816: TLEN Mask                 */
#define UART_TL7816_TLEN_SHIFT                   (0U)                                                /*!< UART0_TL7816: TLEN Position             */
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK) /*!< UART0_TL7816                            */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x4006A000UL //!< Peripheral base address
#define UART0                          ((UART_Type *) UART0_BasePtr) //!< Freescale base pointer
#define UART0_BASE_PTR                 (UART0) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART1 (file:UART1_MK10D10)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART1 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __IO uint8_t   IR;                           /**< 000E: Infrared Register                                            */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
} UART1_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART1' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
/* ------- BDL Bit Fields                           ------ */
/* ------- C1 Bit Fields                            ------ */
/* ------- C2 Bit Fields                            ------ */
/* ------- S1 Bit Fields                            ------ */
/* ------- S2 Bit Fields                            ------ */
/* ------- C3 Bit Fields                            ------ */
/* ------- D Bit Fields                             ------ */
/* ------- MA Bit Fields                            ------ */
/* ------- C4 Bit Fields                            ------ */
/* ------- C5 Bit Fields                            ------ */
/* ------- ED Bit Fields                            ------ */
/* ------- MODEM Bit Fields                         ------ */
/* ------- IR Bit Fields                            ------ */
/* ------- PFIFO Bit Fields                         ------ */
/* ------- CFIFO Bit Fields                         ------ */
/* ------- SFIFO Bit Fields                         ------ */
/* ------- TWFIFO Bit Fields                        ------ */
/* ------- TCFIFO Bit Fields                        ------ */
/* ------- RWFIFO Bit Fields                        ------ */
/* ------- RCFIFO Bit Fields                        ------ */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x4006B000UL //!< Peripheral base address
#define UART1                          ((UART1_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART2 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4006C000UL //!< Peripheral base address
#define UART2                          ((UART1_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART3 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART3 - Peripheral instance base addresses */
#define UART3_BasePtr                  0x4006D000UL //!< Peripheral base address
#define UART3                          ((UART1_Type *) UART3_BasePtr) //!< Freescale base pointer
#define UART3_BASE_PTR                 (UART3) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup VREF_Peripheral_access_layer_GROUP VREF Peripheral Access Layer
* @brief C Struct for VREF
* @{
*/

/* ================================================================================ */
/* ================           VREF (file:VREF_C)                   ================ */
/* ================================================================================ */

/**
 * @brief Voltage Reference
 */
/**
* @addtogroup VREF_structs_GROUP VREF struct
* @brief Struct for VREF
* @{
*/
typedef struct {                                /*       VREF Structure                                               */
   __IO uint8_t   TRM;                          /**< 0000: Trim Register                                                */
   __IO uint8_t   SC;                           /**< 0001: Status and Control Register                                  */
} VREF_Type;

/**
 * @} */ /* End group VREF_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'VREF' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup VREF_Register_Masks_GROUP VREF Register Masks
* @brief Register Masks for VREF
* @{
*/
/* ------- TRM Bit Fields                           ------ */
#define VREF_TRM_TRIM_MASK                       (0x3FU)                                             /*!< VREF_TRM: TRIM Mask                     */
#define VREF_TRM_TRIM_SHIFT                      (0U)                                                /*!< VREF_TRM: TRIM Position                 */
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK) /*!< VREF_TRM                                */
#define VREF_TRM_CHOPEN_MASK                     (0x40U)                                             /*!< VREF_TRM: CHOPEN Mask                   */
#define VREF_TRM_CHOPEN_SHIFT                    (6U)                                                /*!< VREF_TRM: CHOPEN Position               */
#define VREF_TRM_CHOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_TRM_CHOPEN_SHIFT))&VREF_TRM_CHOPEN_MASK) /*!< VREF_TRM                                */
/* ------- SC Bit Fields                            ------ */
#define VREF_SC_MODE_LV_MASK                     (0x3U)                                              /*!< VREF_SC: MODE_LV Mask                   */
#define VREF_SC_MODE_LV_SHIFT                    (0U)                                                /*!< VREF_SC: MODE_LV Position               */
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFST_MASK                      (0x4U)                                              /*!< VREF_SC: VREFST Mask                    */
#define VREF_SC_VREFST_SHIFT                     (2U)                                                /*!< VREF_SC: VREFST Position                */
#define VREF_SC_VREFST(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFST_SHIFT))&VREF_SC_VREFST_MASK) /*!< VREF_SC                                 */
#define VREF_SC_ICOMPEN_MASK                     (0x20U)                                             /*!< VREF_SC: ICOMPEN Mask                   */
#define VREF_SC_ICOMPEN_SHIFT                    (5U)                                                /*!< VREF_SC: ICOMPEN Position               */
#define VREF_SC_ICOMPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_ICOMPEN_SHIFT))&VREF_SC_ICOMPEN_MASK) /*!< VREF_SC                                 */
#define VREF_SC_REGEN_MASK                       (0x40U)                                             /*!< VREF_SC: REGEN Mask                     */
#define VREF_SC_REGEN_SHIFT                      (6U)                                                /*!< VREF_SC: REGEN Position                 */
#define VREF_SC_REGEN(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_SC_REGEN_SHIFT))&VREF_SC_REGEN_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFEN_MASK                      (0x80U)                                             /*!< VREF_SC: VREFEN Mask                    */
#define VREF_SC_VREFEN_SHIFT                     (7U)                                                /*!< VREF_SC: VREFEN Position                */
#define VREF_SC_VREFEN(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFEN_SHIFT))&VREF_SC_VREFEN_MASK) /*!< VREF_SC                                 */
/**
 * @} */ /* End group VREF_Register_Masks_GROUP 
 */

/* VREF - Peripheral instance base addresses */
#define VREF_BasePtr                   0x40074000UL //!< Peripheral base address
#define VREF                           ((VREF_Type *) VREF_BasePtr) //!< Freescale base pointer
#define VREF_BASE_PTR                  (VREF) //!< Freescale style base pointer
/**
 * @} */ /* End group VREF_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WDOG_Peripheral_access_layer_GROUP WDOG Peripheral Access Layer
* @brief C Struct for WDOG
* @{
*/

/* ================================================================================ */
/* ================           WDOG (file:WDOG_MK)                  ================ */
/* ================================================================================ */

/**
 * @brief Watchdog Timer
 */
/**
* @addtogroup WDOG_structs_GROUP WDOG struct
* @brief Struct for WDOG
* @{
*/
typedef struct {                                /*       WDOG Structure                                               */
   __IO uint16_t  STCTRLH;                      /**< 0000: Status and Control Register High                             */
   __IO uint16_t  STCTRLL;                      /**< 0002: Status and Control Register Low                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TOVAL;                     /**< 0004: Time-out Value Register High TOVALL:TOVALH                   */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TOVALH;                 /**< 0004: Time-out Value Register High                                 */
         __IO uint16_t  TOVALL;                 /**< 0006: Time-out Value Register Low                                  */
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  WIN;                       /**< 0008: Window Register (WINL:WINH)                                  */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  WINH;                   /**< 0008: Window Register High                                         */
         __IO uint16_t  WINL;                   /**< 000A: Window Register Low                                          */
      };
   };
   __IO uint16_t  REFRESH;                      /**< 000C: Refresh Register                                             */
   __IO uint16_t  UNLOCK;                       /**< 000E: Unlock Register                                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TMROUT;                    /**< 0010: Timer Output Register (TMROUTL:TMROUTH)                      */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TMROUTH;                /**< 0010: Timer Output Register High                                   */
         __IO uint16_t  TMROUTL;                /**< 0012: Timer Output Register Low                                    */
      };
   };
   __IO uint16_t  RSTCNT;                       /**< 0014: Reset Count Register                                         */
   __IO uint16_t  PRESC;                        /**< 0016: Prescaler Register                                           */
} WDOG_Type;

/**
 * @} */ /* End group WDOG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'WDOG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup WDOG_Register_Masks_GROUP WDOG Register Masks
* @brief Register Masks for WDOG
* @{
*/
/* ------- STCTRLH Bit Fields                       ------ */
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x1U)                                              /*!< WDOG_STCTRLH: WDOGEN Mask               */
#define WDOG_STCTRLH_WDOGEN_SHIFT                (0U)                                                /*!< WDOG_STCTRLH: WDOGEN Position           */
#define WDOG_STCTRLH_WDOGEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WDOGEN_SHIFT))&WDOG_STCTRLH_WDOGEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x2U)                                              /*!< WDOG_STCTRLH: CLKSRC Mask               */
#define WDOG_STCTRLH_CLKSRC_SHIFT                (1U)                                                /*!< WDOG_STCTRLH: CLKSRC Position           */
#define WDOG_STCTRLH_CLKSRC(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_CLKSRC_SHIFT))&WDOG_STCTRLH_CLKSRC_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x4U)                                              /*!< WDOG_STCTRLH: IRQRSTEN Mask             */
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              (2U)                                                /*!< WDOG_STCTRLH: IRQRSTEN Position         */
#define WDOG_STCTRLH_IRQRSTEN(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_IRQRSTEN_SHIFT))&WDOG_STCTRLH_IRQRSTEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_WINEN_MASK                  (0x8U)                                              /*!< WDOG_STCTRLH: WINEN Mask                */
#define WDOG_STCTRLH_WINEN_SHIFT                 (3U)                                                /*!< WDOG_STCTRLH: WINEN Position            */
#define WDOG_STCTRLH_WINEN(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WINEN_SHIFT))&WDOG_STCTRLH_WINEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x10U)                                             /*!< WDOG_STCTRLH: ALLOWUPDATE Mask          */
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           (4U)                                                /*!< WDOG_STCTRLH: ALLOWUPDATE Position      */
#define WDOG_STCTRLH_ALLOWUPDATE(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_ALLOWUPDATE_SHIFT))&WDOG_STCTRLH_ALLOWUPDATE_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DBGEN_MASK                  (0x20U)                                             /*!< WDOG_STCTRLH: DBGEN Mask                */
#define WDOG_STCTRLH_DBGEN_SHIFT                 (5U)                                                /*!< WDOG_STCTRLH: DBGEN Position            */
#define WDOG_STCTRLH_DBGEN(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_DBGEN_SHIFT))&WDOG_STCTRLH_DBGEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_STOPEN_MASK                 (0x40U)                                             /*!< WDOG_STCTRLH: STOPEN Mask               */
#define WDOG_STCTRLH_STOPEN_SHIFT                (6U)                                                /*!< WDOG_STCTRLH: STOPEN Position           */
#define WDOG_STCTRLH_STOPEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_STOPEN_SHIFT))&WDOG_STCTRLH_STOPEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_WAITEN_MASK                 (0x80U)                                             /*!< WDOG_STCTRLH: WAITEN Mask               */
#define WDOG_STCTRLH_WAITEN_SHIFT                (7U)                                                /*!< WDOG_STCTRLH: WAITEN Position           */
#define WDOG_STCTRLH_WAITEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WAITEN_SHIFT))&WDOG_STCTRLH_WAITEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x400U)                                            /*!< WDOG_STCTRLH: TESTWDOG Mask             */
#define WDOG_STCTRLH_TESTWDOG_SHIFT              (10U)                                               /*!< WDOG_STCTRLH: TESTWDOG Position         */
#define WDOG_STCTRLH_TESTWDOG(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_TESTWDOG_SHIFT))&WDOG_STCTRLH_TESTWDOG_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_TESTSEL_MASK                (0x800U)                                            /*!< WDOG_STCTRLH: TESTSEL Mask              */
#define WDOG_STCTRLH_TESTSEL_SHIFT               (11U)                                               /*!< WDOG_STCTRLH: TESTSEL Position          */
#define WDOG_STCTRLH_TESTSEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_TESTSEL_SHIFT))&WDOG_STCTRLH_TESTSEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_BYTESEL_MASK                (0x3000U)                                           /*!< WDOG_STCTRLH: BYTESEL Mask              */
#define WDOG_STCTRLH_BYTESEL_SHIFT               (12U)                                               /*!< WDOG_STCTRLH: BYTESEL Position          */
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_BYTESEL_SHIFT))&WDOG_STCTRLH_BYTESEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x4000U)                                           /*!< WDOG_STCTRLH: DISTESTWDOG Mask          */
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           (14U)                                               /*!< WDOG_STCTRLH: DISTESTWDOG Position      */
#define WDOG_STCTRLH_DISTESTWDOG(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_DISTESTWDOG_SHIFT))&WDOG_STCTRLH_DISTESTWDOG_MASK) /*!< WDOG_STCTRLH                            */
/* ------- STCTRLL Bit Fields                       ------ */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x8000U)                                           /*!< WDOG_STCTRLL: INTFLG Mask               */
#define WDOG_STCTRLL_INTFLG_SHIFT                (15U)                                               /*!< WDOG_STCTRLL: INTFLG Position           */
#define WDOG_STCTRLL_INTFLG(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLL_INTFLG_SHIFT))&WDOG_STCTRLL_INTFLG_MASK) /*!< WDOG_STCTRLL                            */
/* ------- TOVAL Bit Fields                         ------ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFFFFFU)                                       /*!< WDOG_TOVAL: TOVAL Mask                  */
#define WDOG_TOVAL_TOVAL_SHIFT                   (0U)                                                /*!< WDOG_TOVAL: TOVAL Position              */
#define WDOG_TOVAL_TOVAL(x)                      (((uint32_t)(((uint32_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK) /*!< WDOG_TOVAL                              */
/* ------- TOVALH Bit Fields                        ------ */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFU)                                           /*!< WDOG_TOVALH: TOVALHIGH Mask             */
#define WDOG_TOVALH_TOVALHIGH_SHIFT              (0U)                                                /*!< WDOG_TOVALH: TOVALHIGH Position         */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK) /*!< WDOG_TOVALH                             */
/* ------- TOVALL Bit Fields                        ------ */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFU)                                           /*!< WDOG_TOVALL: TOVALLOW Mask              */
#define WDOG_TOVALL_TOVALLOW_SHIFT               (0U)                                                /*!< WDOG_TOVALL: TOVALLOW Position          */
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK) /*!< WDOG_TOVALL                             */
/* ------- WIN Bit Fields                           ------ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFFFFFU)                                       /*!< WDOG_WIN: WIN Mask                      */
#define WDOG_WIN_WIN_SHIFT                       (0U)                                                /*!< WDOG_WIN: WIN Position                  */
#define WDOG_WIN_WIN(x)                          (((uint32_t)(((uint32_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK) /*!< WDOG_WIN                                */
/* ------- WINH Bit Fields                          ------ */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFU)                                           /*!< WDOG_WINH: WINHIGH Mask                 */
#define WDOG_WINH_WINHIGH_SHIFT                  (0U)                                                /*!< WDOG_WINH: WINHIGH Position             */
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK) /*!< WDOG_WINH                               */
/* ------- WINL Bit Fields                          ------ */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFU)                                           /*!< WDOG_WINL: WINLOW Mask                  */
#define WDOG_WINL_WINLOW_SHIFT                   (0U)                                                /*!< WDOG_WINL: WINLOW Position              */
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK) /*!< WDOG_WINL                               */
/* ------- REFRESH Bit Fields                       ------ */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFU)                                           /*!< WDOG_REFRESH: WDOGREFRESH Mask          */
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           (0U)                                                /*!< WDOG_REFRESH: WDOGREFRESH Position      */
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_REFRESH_WDOGREFRESH_SHIFT))&WDOG_REFRESH_WDOGREFRESH_MASK) /*!< WDOG_REFRESH                            */
/* ------- UNLOCK Bit Fields                        ------ */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFU)                                           /*!< WDOG_UNLOCK: WDOGUNLOCK Mask            */
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             (0U)                                                /*!< WDOG_UNLOCK: WDOGUNLOCK Position        */
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT))&WDOG_UNLOCK_WDOGUNLOCK_MASK) /*!< WDOG_UNLOCK                             */
/* ------- TMROUT Bit Fields                        ------ */
#define WDOG_TMROUT_TIMEROUTHIGH_MASK            (0xFFFFFFFFU)                                       /*!< WDOG_TMROUT: TIMEROUTHIGH Mask          */
#define WDOG_TMROUT_TIMEROUTHIGH_SHIFT           (0U)                                                /*!< WDOG_TMROUT: TIMEROUTHIGH Position      */
#define WDOG_TMROUT_TIMEROUTHIGH(x)              (((uint32_t)(((uint32_t)(x))<<WDOG_TMROUT_TIMEROUTHIGH_SHIFT))&WDOG_TMROUT_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUT                             */
/* ------- TMROUTH Bit Fields                       ------ */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFU)                                           /*!< WDOG_TMROUTH: TIMEROUTHIGH Mask         */
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          (0U)                                                /*!< WDOG_TMROUTH: TIMEROUTHIGH Position     */
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT))&WDOG_TMROUTH_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUTH                            */
/* ------- TMROUTL Bit Fields                       ------ */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFU)                                           /*!< WDOG_TMROUTL: TIMEROUTLOW Mask          */
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           (0U)                                                /*!< WDOG_TMROUTL: TIMEROUTLOW Position      */
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT))&WDOG_TMROUTL_TIMEROUTLOW_MASK) /*!< WDOG_TMROUTL                            */
/* ------- RSTCNT Bit Fields                        ------ */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFU)                                           /*!< WDOG_RSTCNT: RSTCNT Mask                */
#define WDOG_RSTCNT_RSTCNT_SHIFT                 (0U)                                                /*!< WDOG_RSTCNT: RSTCNT Position            */
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_RSTCNT_RSTCNT_SHIFT))&WDOG_RSTCNT_RSTCNT_MASK) /*!< WDOG_RSTCNT                             */
/* ------- PRESC Bit Fields                         ------ */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x700U)                                            /*!< WDOG_PRESC: PRESCVAL Mask               */
#define WDOG_PRESC_PRESCVAL_SHIFT                (8U)                                                /*!< WDOG_PRESC: PRESCVAL Position           */
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_PRESC_PRESCVAL_SHIFT))&WDOG_PRESC_PRESCVAL_MASK) /*!< WDOG_PRESC                              */
/**
 * @} */ /* End group WDOG_Register_Masks_GROUP 
 */

/* WDOG - Peripheral instance base addresses */
#define WDOG_BasePtr                   0x40052000UL //!< Peripheral base address
#define WDOG                           ((WDOG_Type *) WDOG_BasePtr) //!< Freescale base pointer
#define WDOG_BASE_PTR                  (WDOG) //!< Freescale style base pointer
/**
 * @} */ /* End group WDOG_Peripheral_access_layer_GROUP 
 */
/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif
/**
 * @} */ /* End group Peripheral_access_layer_GROUP 
 */

#ifdef __cplusplus
}
#endif


#endif  /* MCU_MK11D5WS */

