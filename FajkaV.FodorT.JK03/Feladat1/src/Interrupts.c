//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>

#define LED0 P1_B4
#define REACT_TIME 200 //200 ms time for the user's reaction
#define DELAY_UNIT 100 //100 ms used to count up to seconds
//-----------------------------------------------------------------------------
// TIMER0_ISR
//-----------------------------------------------------------------------------
//
// TIMER0 ISR Content goes here. Remember to clear flag bits:
// TCON::TF0 (Timer 0 Overflow Flag)
//
//-----------------------------------------------------------------------------
extern uint16_t counter;
extern uint16_t delay_counter;
extern volatile bit start;
extern volatile bit stop;

SI_INTERRUPT (TIMER0_ISR, TIMER0_IRQn)
{
    TCON_TF0 = 0;
    counter++;
}

