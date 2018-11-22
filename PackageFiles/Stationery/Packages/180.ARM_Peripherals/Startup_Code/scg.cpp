/*
 * @file scg.cpp (180.ARM_Peripherals/Startup_Code/mcg.cpp)
 *
 * Generic SCG
 *    1 FLL (FRDIV=/1-/128, /32-/1024, /1280, /1536)
 *    1 PLL (VCO PRDIV=/1-/24, VDIV=pll_vdiv_min+x) (pll_vdiv_min=x16,x24)
 *
 *  Created on: 04/03/2012
 *      Author: podonoghue
 */
#include "string.h"
#include "derivative.h" /* include peripheral declarations */
#include "system.h"
#include "utilities.h"
#include "stdbool.h"
#include "hardware.h"
#include "scg.h"
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
extern "C" uint32_t SystemCoreClock;
extern "C" uint32_t SystemBusClock;

namespace USBDM {

   /**
    * Table of clock settings
    */
   const ScgInfo::ClockInfo Scg::clockInfo[] = {
$(/SCG/ScgClockInfoEntries:!!!!!!!Not found!!!!!!!)
   };

/** Core/System clock (from SCGOUTCLK/CLKDIV) */
volatile uint32_t SystemCoreClock;

/** Bus clock (from SCGOUTCLK/CLKDIV) */
volatile uint32_t SystemBusClock;

/** LPO - Low power oscillator 1kHz clock available in LP modes */
volatile uint32_t SystemLpoClock;

/** Callback for programmatically set handler */
SCGCallbackFunction Scg::callback = {0};

/** Current clock mode (FEI out of reset) */
ScgInfo::ClockMode Scg::currentClockMode = ScgInfo::ClockMode::ClockMode_FIRC;

/**
 * Get name for clock mode
 *
 * @return Pointer to static string
 */
const char *Scg::getClockModeName(ScgInfo::ClockMode clockMode) {
   static const char *modeNames[] {
         "FIRC",
         "SOSC",
         "SIRC",
         "SYSPLL",
   };

   if (clockMode<0) {
      return "Not set";
   }
   if ((unsigned)clockMode>=(sizeof(modeNames)/sizeof(modeNames[0]))) {
      return "Illegal";
   }
   return modeNames[clockMode];
}

/**
 * Transition from current clock mode to mode given
 *
 * @param to Clock mode to transition to
 *
 * @return E_NO_ERROR on success
 */
ErrorCode Scg::clockTransition(const ScgInfo::ClockInfo &clockInfo) {
   ScgInfo::ClockMode to = clockInfo.clockMode;

   // Configure all clocks and clock dividers
   scg().FIRCCFG = clockInfo.firccfg;
   scg().FIRCDIV = clockInfo.fircdiv;
   scg().FIRCCSR = clockInfo.firccsr;
   scg().SOSCCFG = clockInfo.sosccfg;
   scg().SOSCDIV = clockInfo.soscdiv;
   scg().SOSCCSR = clockInfo.sosccsr;
   scg().SIRCCFG = clockInfo.sirccfg;
   scg().SIRCDIV = clockInfo.sircdiv;
   scg().SIRCCSR = clockInfo.sirccsr;
   scg().SPLLCFG = clockInfo.spllcfg;
   scg().SPLLDIV = clockInfo.splldiv;
   scg().SPLLCSR = clockInfo.spllcsr;

   switch(to) {
      case  ScgInfo::ClockMode_None:
         break;

      case  ScgInfo::ClockMode_FIRC:
         // Wait until FIRC operating
         while ((scg().FIRCCSR&SCG_FIRCCSR_FIRCVLD_MASK) == 0) {
            __asm__("nop");
         }
         scg().RCCR    = SCG_RCCR_SCS(0b0011)|clockInfo.runccr;
         scg().HCCR    = SCG_HCCR_SCS(0b0011)|clockInfo.altccr;
         // Wait until FIRC is system clock
         while ((scg().FIRCCSR&SCG_FIRCCSR_FIRCSEL_MASK) == 0) {
            __asm__("nop");
         }
         break;

      case  ScgInfo::ClockMode_SIRC:
         // Wait until SIRC operating
         while ((scg().SIRCCSR&SCG_SIRCCSR_SIRCVLD_MASK) == 0) {
            __asm__("nop");
         }
         scg().RCCR    = SCG_RCCR_SCS(0b0010)|clockInfo.runccr;
         scg().VCCR    = SCG_VCCR_SCS(0b0010)|clockInfo.altccr;
         // Wait until SIRC is system clock
         while ((scg().SIRCCSR&SCG_SIRCCSR_SIRCSEL_MASK) == 0) {
            __asm__("nop");
         }
         break;

      case  ScgInfo::ClockMode_SOSC:
         // Wait until SOSC operating
         while ((scg().SOSCCSR&SCG_SOSCCSR_SOSCVLD_MASK) == 0) {
            __asm__("nop");
         }
         scg().RCCR    = SCG_RCCR_SCS(0b0001)|clockInfo.runccr;
         // Wait until SOSC is system clock
         while ((scg().SOSCCSR&SCG_SOSCCSR_SOSCSEL_MASK) == 0) {
            __asm__("nop");
         }
         break;

      case  ScgInfo::ClockMode_SPLL:
         // Wait until SPLL operating
         while ((scg().SPLLCSR&SCG_SPLLCSR_SPLLVLD_MASK) == 0) {
            __asm__("nop");
         }
         scg().RCCR    = SCG_RCCR_SCS(0b0110)|clockInfo.runccr;
         scg().HCCR    = SCG_HCCR_SCS(0b0110)|clockInfo.altccr;
         // Wait until SPLL is system clock
         while ((scg().SPLLCSR&SCG_SPLLCSR_SPLLSEL_MASK) == 0) {
            __asm__("nop");
         }
         break;
   }
   SystemCoreClockUpdate();

   return E_NO_ERROR;
}

/**
 * Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void Scg::SystemCoreClockUpdate() {

   SystemLpoClock    = 1000;

   uint32_t clockFrequency = 0;

   switch (scg().CSR & SCG_CSR_SCS_MASK) {
      case SCG_RCCR_SCS(0b0001) : // SOSC
         clockFrequency = ScgInfo::getSoscFrequency();
         break;
      case SCG_RCCR_SCS(0b0010) : // SIRC
         clockFrequency = ScgInfo::getSircFrequency();
         break;
      case SCG_RCCR_SCS(0b0011) : // FIRC
         clockFrequency = ScgInfo::getFircFrequency();
         break;
      case SCG_RCCR_SCS(0b0110) : // SPLL
         clockFrequency = ScgInfo::getSpllFrequency();
         break;
   }
   ::SystemCoreClock = ScgInfo::getSystemDividedClock(clockFrequency,    (scg().CSR&SCG_RCCR_DIVCORE_MASK)>>SCG_RCCR_DIVCORE_SHIFT);
   ::SystemBusClock  = ScgInfo::getSystemDividedClock(::SystemCoreClock, (scg().CSR&SCG_RCCR_DIVBUS_MASK)>>SCG_RCCR_DIVBUS_SHIFT);
}

/**
 * Initialise SCG to default settings.
 */
void Scg::defaultConfigure() {

   currentClockMode = ScgInfo::ClockMode::ClockMode_None;

   // Transition to desired clock mode
   clockTransition(clockInfo[ClockConfig_default]);

   enableNvicInterrupts();

   SystemCoreClockUpdate();
}

} // end namespace USBDM

/**
 * Sets up the clock out of RESET
 */
extern "C"
void clock_initialise(void) {

#ifdef USBDM_SCG_IS_DEFINED
   USBDM::Scg::initialise();
#endif

}

