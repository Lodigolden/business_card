////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "gpio.h"

#include <xc.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
void set_pin(char bank, uint8_t pin)
{
   // Check that pin is within range:
   if (pin > 7U)
   {
      return;
   }

   // Enable Output:
   switch (bank)
   {
      case 'A':
         TRISA &= ~(1U << pin);
         LATA |= 1U << pin;
         break;

      case 'B':
         TRISB &= ~(1U << pin);
         LATB |= 1U << pin;
         break;

      case 'C':
         TRISC &= ~(1U << pin);
         LATC |= 1U << pin;
         break;
         
      default:
         return;
   }

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void clear_pin(char bank, uint8_t pin)
{
   // Check that pin is within range:
   if (pin > 7U)
   {
      return;
   }

   // Disable Output:
   switch (bank)
   {
      case 'A':
         LATA &= ~(1U << pin);
         break;

      case 'B':
         LATB &= ~(1U << pin);
         break;

      case 'C':
         LATC &= ~(1U << pin);
         break;
         
      default:
         return;
   }

   return;
}
