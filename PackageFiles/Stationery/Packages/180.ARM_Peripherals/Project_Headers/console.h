/**
 * @file    console.h  (180.ARM_Peripherals/Project_Headers/console.h)
 * @brief   Basic UART routines for console
 * @date    13 June 2015
 */
#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <derivative.h>
#include "hardware.h"
#if defined(USBDM_UART0_IS_DEFINED) || defined(USBDM_UART1_IS_DEFINED) || defined(USBDM_UART2_IS_DEFINED) || defined(USBDM_UART3_IS_DEFINED) || defined(USBDM_UART4_IS_DEFINED)
#include "uart.h"
#endif
#if defined(USBDM_LPUART0_IS_DEFINED) || defined(USBDM_LPUART1_IS_DEFINED) || defined(USBDM_LPUART2_IS_DEFINED)
#include "lpuart.h"
#endif

 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */


#define USE_CONSOLE $(/Console/consoleEnable:0)

#if USE_CONSOLE

#ifdef __cplusplus
namespace USBDM {

/**
 * @addtogroup CONSOLE_Group Console, Console
 * @brief Console serial interface
 * @{
 */

//! Default baud rate for console
constexpr int defaultBaudRate = $(/Console/defaultBaudRate:115200);

//! Maps console to UART used
using  Console = $(/Console/consoleDevice:USBDM::Uart0);

//! Console instance
extern Console console;

/**
 * @}
 */

} // End namespace USBDM
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The following functions are a C-wrapper used by the C library
 * low-level stdio support.
 */
/**
 * Initialises the Console
 */
void console_initialise();
/**
 * Set Console baud rate
 *
 * @param[in]  baudRate - the baud rate to use
 */
void console_setBaudRate(int baudRate);
/**
 * Transmits a single character over the Console (blocking)
 *
 * @param[in]  ch - character to send
 */
void console_txChar(int ch);
/**
 * Receives a single character over the Console (blocking)
 *
 * @return - character received
 */
int  console_rxChar(void);

#ifdef __cplusplus
}
#endif

#endif /* USE_CONSOLE */

#endif /* CONSOLE_H_ */
