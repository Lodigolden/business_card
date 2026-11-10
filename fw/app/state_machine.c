////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "state_machine.h"

#include <xc.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Definition(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#define TICK_RATE 1000

////////////////////////////////////////////////////////////////////////////////////////////////////
// Global(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
volatile bool g_mode = false;

////////////////////////////////////////////////////////////////////////////////////////////////////
void system_state_machine(void)
{
   // State Variables
   uint8_t print_data[4U];
   uint8_t clock_data[4U];

   while(1)
   {
      if (clock_data[0U] < 9U)
      {
         clock_data[0U]++;
      }
      else
      {
         clock_data[0U] = 0U;
         if (clock_data[1U] < 9U)
         {
            clock_data[1U]++;
         }
         else
         {
            clock_data[1U] = 0U;
            if (clock_data[2U] < 9U)
            {
               clock_data[2U]++;
            }
            else
            {
               clock_data[2U] = 0U;
               if (clock_data[3U] < 9U)
               {
                  clock_data[3U]++;
               }
               else
               {
                  clock_data[3U] = 0U;
               }
            }
         }
      }

      if (g_mode) // Therm
      {
         read_temp(print_data, true);
      }
      else // Clock
      {
         for (size_t idx = 0U; idx < 4U; idx++)
         {
            print_data[idx] = clock_data[idx];
         }
      }

      set_sseg_digit(0U, print_data[0U]);
      set_sseg_digit(1U, print_data[1U]);
      set_sseg_digit(2U, print_data[2U]);
      set_sseg_digit(3U, print_data[3U]);

      __delay_ms(TICK_RATE);
   }

   return;
}
