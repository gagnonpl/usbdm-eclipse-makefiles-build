 /**
  * @file     gpio.cpp (from gpio-MKE06Z4.cpp)
  *
  * @brief   Pin declarations for MKE06Z4
  */

#include "gpio.h"
#include "pin_mapping.h"

namespace USBDM {

#if (DO_MAP_PINS_ON_RESET>0)
struct PinInit {
   uint32_t pcrValue;
   uint32_t volatile *pcr;
};

static constexpr PinInit pinInit[] = {
#if (PTA0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[0]},
#endif
#if (PTA1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[1]},
#endif
#if (PTA2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[2]},
#endif
#if (PTA3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[3]},
#endif
#if (PTA4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[4]},
#endif
#if (PTA5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[5]},
#endif
#if (PTA6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[6]},
#endif
#if (PTA7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTA7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTA->PCR[7]},
#endif
#if (PTB0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[0]},
#endif
#if (PTB1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[1]},
#endif
#if (PTB2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[2]},
#endif
#if (PTB3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[3]},
#endif
#if (PTB4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[4]},
#endif
#if (PTB5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[5]},
#endif
#if (PTB6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[6]},
#endif
#if (PTB7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTB7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTB->PCR[7]},
#endif
#if (PTC0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[0]},
#endif
#if (PTC1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[1]},
#endif
#if (PTC2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[2]},
#endif
#if (PTC3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[3]},
#endif
#if (PTC4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[4]},
#endif
#if (PTC5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[5]},
#endif
#if (PTC6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[6]},
#endif
#if (PTC7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTC7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTC->PCR[7]},
#endif
#if (PTD0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[0]},
#endif
#if (PTD1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[1]},
#endif
#if (PTD2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[2]},
#endif
#if (PTD3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[3]},
#endif
#if (PTD4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[4]},
#endif
#if (PTD5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[5]},
#endif
#if (PTD6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[6]},
#endif
#if (PTD7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTD7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTD->PCR[7]},
#endif
#if (PTE0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[0]},
#endif
#if (PTE1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[1]},
#endif
#if (PTE2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[2]},
#endif
#if (PTE3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[3]},
#endif
#if (PTE4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[4]},
#endif
#if (PTE5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[5]},
#endif
#if (PTE6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[6]},
#endif
#if (PTE7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTE7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTE->PCR[7]},
#endif
#if (PTF0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[0]},
#endif
#if (PTF1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[1]},
#endif
#if (PTF2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[2]},
#endif
#if (PTF3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[3]},
#endif
#if (PTF4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[4]},
#endif
#if (PTF5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[5]},
#endif
#if (PTF6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[6]},
#endif
#if (PTF7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTF7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTF->PCR[7]},
#endif
#if (PTG0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[0]},
#endif
#if (PTG1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[1]},
#endif
#if (PTG2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[2]},
#endif
#if (PTG3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[3]},
#endif
#if (PTG4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[4]},
#endif
#if (PTG5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[5]},
#endif
#if (PTG6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[6]},
#endif
#if (PTG7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTG7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTG->PCR[7]},
#endif
#if (PTH0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[0]},
#endif
#if (PTH1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[1]},
#endif
#if (PTH2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[2]},
#endif
#if (PTH3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[3]},
#endif
#if (PTH4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[4]},
#endif
#if (PTH5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[5]},
#endif
#if (PTH6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[6]},
#endif
#if (PTH7_SIG_SEL>=0)
   { PORT_PCR_MUX(PTH7_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTH->PCR[7]},
#endif
#if (PTI0_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI0_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTI->PCR[0]},
#endif
#if (PTI1_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI1_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTI->PCR[1]},
#endif
#if (PTI2_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI2_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTI->PCR[2]},
#endif
#if (PTI3_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI3_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTI->PCR[3]},
#endif
#if (PTI4_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI4_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTI->PCR[4]},
#endif
#if (PTI5_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI5_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTI->PCR[5]},
#endif
#if (PTI6_SIG_SEL>=0)
   { PORT_PCR_MUX(PTI6_SIG_SEL)|USBDM::DEFAULT_PCR, &PORTI->PCR[6]},
#endif
};

/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
void usbdm_PinMapping() {
#if (PTA0_SIG_SEL>=0) || (PTA1_SIG_SEL>=0) || (PTA2_SIG_SEL>=0) || (PTA3_SIG_SEL>=0) || \
    (PTA4_SIG_SEL>=0) || (PTA5_SIG_SEL>=0) || (PTA6_SIG_SEL>=0) || (PTA7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTA_CLOCK_MASK;
#endif

#if (PTB0_SIG_SEL>=0) || \
    (PTB1_SIG_SEL>=0) || (PTB2_SIG_SEL>=0) || (PTB3_SIG_SEL>=0) || (PTB4_SIG_SEL>=0) || \
    (PTB5_SIG_SEL>=0) || (PTB6_SIG_SEL>=0) || (PTB7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTB_CLOCK_MASK;
#endif

#if (PTC0_SIG_SEL>=0) || (PTC1_SIG_SEL>=0) || \
    (PTC2_SIG_SEL>=0) || (PTC3_SIG_SEL>=0) || (PTC4_SIG_SEL>=0) || (PTC5_SIG_SEL>=0) || \
    (PTC6_SIG_SEL>=0) || (PTC7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTC_CLOCK_MASK;
#endif

#if (PTD0_SIG_SEL>=0) || (PTD1_SIG_SEL>=0) || (PTD2_SIG_SEL>=0) || \
    (PTD3_SIG_SEL>=0) || (PTD4_SIG_SEL>=0) || (PTD5_SIG_SEL>=0) || (PTD6_SIG_SEL>=0) || \
    (PTD7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTD_CLOCK_MASK;
#endif

#if (PTE0_SIG_SEL>=0) || (PTE1_SIG_SEL>=0) || (PTE2_SIG_SEL>=0) || (PTE3_SIG_SEL>=0) || \
    (PTE4_SIG_SEL>=0) || (PTE5_SIG_SEL>=0) || (PTE6_SIG_SEL>=0) || (PTE7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTE_CLOCK_MASK;
#endif

#if (PTF0_SIG_SEL>=0) || \
    (PTF1_SIG_SEL>=0) || (PTF2_SIG_SEL>=0) || (PTF3_SIG_SEL>=0) || (PTF4_SIG_SEL>=0) || \
    (PTF5_SIG_SEL>=0) || (PTF6_SIG_SEL>=0) || (PTF7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTF_CLOCK_MASK;
#endif

#if (PTG0_SIG_SEL>=0) || (PTG1_SIG_SEL>=0) || \
    (PTG2_SIG_SEL>=0) || (PTG3_SIG_SEL>=0) || (PTG4_SIG_SEL>=0) || (PTG5_SIG_SEL>=0) || \
    (PTG6_SIG_SEL>=0) || (PTG7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTG_CLOCK_MASK;
#endif

#if (PTH0_SIG_SEL>=0) || (PTH1_SIG_SEL>=0) || (PTH2_SIG_SEL>=0) || \
    (PTH3_SIG_SEL>=0) || (PTH4_SIG_SEL>=0) || (PTH5_SIG_SEL>=0) || (PTH6_SIG_SEL>=0) || \
    (PTH7_SIG_SEL>=0)

   SIM->FIXED_PORT_CLOCK_REG |= PORTH_CLOCK_MASK;
#endif

#if (PTI0_SIG_SEL>=0) || (PTI1_SIG_SEL>=0) || (PTI2_SIG_SEL>=0) || (PTI3_SIG_SEL>=0) || \
    (PTI4_SIG_SEL>=0) || (PTI5_SIG_SEL>=0) || (PTI6_SIG_SEL>=0)
   SIM->FIXED_PORT_CLOCK_REG |= PORTI_CLOCK_MASK;

#endif

   for (const PinInit *p=pinInit; p<(pinInit+(sizeof(pinInit)/sizeof(pinInit[0]))); p++) {
      *(p->pcr) = p->pcrValue;
   }
}
#endif

} // End namespace USBDM
