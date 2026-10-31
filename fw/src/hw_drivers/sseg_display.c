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
#define SSEG_12_ADDR_READ 0x41
#define SSEG_34_ADDR_WRITE 0x42
#define SSEG_34_ADDR_READ 0x43

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

////////////////////////////////////////////////////////////////////////////////////////////////////
void config_sseg_display(void)
{
   // Set all driver pins as outputs:
   i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_CONFIG_1, 0x00);
   i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_CONFIG_2, 0x00);

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void set_sseg_digit(void)
{
   i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_OUTPUT_1, 0xFF);
   i2c_transmit_data(SSEG_12_ADDR_WRITE, SSEG_OUTPUT_2, 0xFF);
}
