////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "sseg_display.h"

#include "../mcu_drivers/i2c.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Definition(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO expander I2C addresses.
#define SSEG_12_ADDR_WRITE 0x40
#define SSEG_12_ADDR_READ  0x41
#define SSEG_34_ADDR_WRITE 0x42
#define SSEG_34_ADDR_READ  0x43

// Control registers that set which LEDs are driven.
#define SSEG_OUTPUT_1 0x02
#define SSEG_OUTPUT_2 0x03

// Configuration registers that set if a pin is INPUT/OUTPUT.
#define SSEG_CONFIG_1 0x06
#define SSEG_CONFIG_2 0x07

// Drive strength control registers.
#define SSEG_DRIVE_1 0x40
#define SSEG_DRIVE_2 0x41
#define SSEG_DRIVE_3 0x42
#define SSEG_DRIVE_4 0x43

// SSEG Encoder Values
#define DISP_0 0x3F
#define DISP_1 0x06
#define DISP_2 0x5B
#define DISP_3 0x4F
#define DISP_4 0x66
#define DISP_5 0x6D
#define DISP_6 0x7D
#define DISP_7 0x07
#define DISP_8 0x7F
#define DISP_9 0x6F

////////////////////////////////////////////////////////////////////////////////////////////////////
void config_sseg_display(void)
{
   // Set all driver pins as outputs:
   i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_CONFIG_1, 0x00);
   i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_CONFIG_2, 0x00);

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void set_sseg_digit(uint8_t val)
{
   // Early return catch:
   if (val > 9U)
   {
      return;
   }

   uint8_t i2c_write_val = 0x00;

   switch (val)
   {
      case 0U:
         i2c_write_val = DISP_0;
         break;
      
      case 1U:
         i2c_write_val = DISP_1;
         break;
      
      case 2U:
         i2c_write_val = DISP_2;
         break;

      case 3U:
         i2c_write_val = DISP_3;
         break;

      case 4U:
         i2c_write_val = DISP_4;
         break;

      case 5U:
         i2c_write_val = DISP_5;
         break;
      
      case 6U:
         i2c_write_val = DISP_6;
         break;

      case 7U:
         i2c_write_val = DISP_7;
         break;

      case 8U:
         i2c_write_val = DISP_8;
         break;

      case 9U:
         i2c_write_val = DISP_9;
         break;
   }

   i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_OUTPUT_1, i2c_write_val);
   // i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_OUTPUT_2, 0x00);

   return;
}
