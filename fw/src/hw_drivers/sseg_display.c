////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "sseg_display.h"

#include "../mcu_drivers/i2c.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Definition(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO expander I2C addresses.
#define SSEG_32_ADDR 0x20
#define SSEG_10_ADDR 0x21

// GPIO expander register size.
#define SSEG_REG_SIZE 1U

// Configuration registers that set if a pin is INPUT/OUTPUT.
#define SSEG_CONFIG_1 0x06
#define SSEG_CONFIG_2 0x07

// Control registers that set which LEDs are driven.
#define SSEG_OUTPUT_1 0x02
#define SSEG_OUTPUT_0 0x03

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
#define DISP_A 0x77
#define DISP_B 0x7C
#define DISP_C 0x39
#define DISP_D 0x5E
#define DISP_E 0x79
#define DISP_F 0x71
#define DISP_DP 0x08

////////////////////////////////////////////////////////////////////////////////////////////////////
void config_sseg_display(void)
{
   // Set all driver pins as outputs:
   i2c_transmit_data(SSEG_32_ADDR, SSEG_REG_SIZE, SSEG_CONFIG_1, 0x00);
   i2c_transmit_data(SSEG_32_ADDR, SSEG_REG_SIZE, SSEG_CONFIG_2, 0x00);
   i2c_transmit_data(SSEG_10_ADDR, SSEG_REG_SIZE, SSEG_CONFIG_1, 0x00);
   i2c_transmit_data(SSEG_10_ADDR, SSEG_REG_SIZE, SSEG_CONFIG_2, 0x00);

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void set_sseg_digit(uint8_t dig, uint8_t val)
{
   // Early return catch:
   if ((val > 15U) || (dig > 3U))
   {
      return;
   }

   // Set digit.
   uint8_t device = SSEG_32_ADDR;
   uint8_t output = SSEG_OUTPUT_1;

   switch (dig)
   {
      case 0U:
         device = SSEG_10_ADDR;
         output = SSEG_OUTPUT_0;
         break;
      case 1U:
         device = SSEG_10_ADDR;
         break;
      case 2U:
         output = SSEG_OUTPUT_0;
         break;
      case 3U:
         break;
   }

   uint8_t digit_val = _encode_dec(val);

   i2c_transmit_data(device, SSEG_REG_SIZE, output, &digit_val);

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t _encode_dec(uint8_t val_dec)
{
   uint8_t val_hex = 0x00;

   switch (val_dec)
   {
      case 0U:
         val_hex = DISP_0;
         break;
      case 1U:
         val_hex = DISP_1;
         break;
      case 2U:
         val_hex = DISP_2;
         break;
      case 3U:
         val_hex = DISP_3;
         break;
      case 4U:
         val_hex = DISP_4;
         break;
      case 5U:
         val_hex = DISP_5;
         break;
      case 6U:
         val_hex = DISP_6;
         break;
      case 7U:
         val_hex = DISP_7;
         break;
      case 8U:
         val_hex = DISP_8;
         break;
      case 9U:
         val_hex = DISP_9;
         break;
      case 10U:
         val_hex = DISP_A;
         break;
      case 11U:
         val_hex = DISP_B;
         break;
      case 12U:
         val_hex = DISP_C;
         break;
      case 13U:
         val_hex = DISP_D;
         break;
      case 14U:
         val_hex = DISP_E;
         break;
      case 15U:
         val_hex = DISP_F;
         break;
   }

   return val_hex;
}
