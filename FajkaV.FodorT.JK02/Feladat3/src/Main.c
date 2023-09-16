//=========================================================
// src/lab_02_3_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

#define BTN0 P0_B2
#define LED0 P1_B4
#define PRELL 50U
//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

uint8_t counter = 0; //counter for BTN0
uint8_t led_counter = 0; //counter for LED0

void Delay(){
  while(counter < PRELL);
}

void Blink(uint8_t *index){
  static uint8_t half_periods[3] = {100U, 50U, 10U};
  LED0 = !LED0;
  while(led_counter < (half_periods[*index]));
  led_counter = 0;
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------

int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();

  while (1) 
  {
      static uint8_t i = 0;
      Blink(&i);
      if(!BTN0){
              Delay();
              i++;
              if(i > 2){
                  i = 0;
              }
              while(!BTN0);
              counter = 0;
              Delay();
       }

   }
}
