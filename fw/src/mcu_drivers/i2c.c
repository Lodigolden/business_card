////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "i2c.h"

#include <xc.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
void config_i2c(void)
{
   // Disable Serial Peripheral:
   SSP1CON1 &= ~(1U << 5U);

   // I2C Threshold Config:
   RB4I2C |= (1U << 6U) | 1U; // I2C Slew Rate, I2C Input Thresholds
   RB6I2C |= (1U << 6U) | 1U; // I2C Slew Rate, I2C Input Thresholds

   // Set Peripheral Input to I2C:
   SSP1CLKPPS = (1U << 3U) | 4U; // PORT B PIN 4
   SSP1DATPPS = (1U << 3U) | 6U; // PORT B PIN 6

   // Set Peripheral Output to I2C:
   RB4PPS = 0x07; // SCL1
   RB6PPS = 0x08; // SDA1

   // Disable Analog Functions on I2C Pins:
   ANSELB &= ~((1U << 4U) | (1U << 6U));

   // Set I2C Pins as Open Drain:
   ODCONB |= (1U << 4U) | (1U << 6U);

   // MSSP Baud Rate Divider:
   SSP1ADD = 0x4F; // 100kHz BAUD (32MHz FOSC)

   // MSSP Control Register Config:
   SSP1CON1 |= 8U; // I2C host mode.

   // Enable Serial Peripheral:
   SSP1CON1 |= (1U << 5U);

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void i2c_transmit_data(uint8_t addr, uint8_t reg, uint8_t data)
{
   _i2c_start();
   _i2c_write_byte(addr);
   _i2c_write_byte(reg);
   _i2c_write_byte(data);
   _i2c_stop();

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void _i2c_start(void)
{
   // Clear I2C interrupt:
   PIR1 &= ~(1U << 1U);

   // Initiate start condition.
   SSP1CON2 |= 1U; // Set SEN bit.

   // Wait for MSP Interrupt:
   while ((PIR1 & (1U << 1U)) == 0U)
   {
      ; // Wait for hardware to set interrupt.
   }

   // Clear the interrupt:
   PIR1 &= ~(1U << 1U);

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void _i2c_stop(void)
{
   // Clear I2C interrupt:
   PIR1 &= ~(1U << 1U);

   // Send stop condition.
   SSP1CON2 |= (1U << 2U); // Set PEN bit.

   // Wait for MSP Interrupt:
   while ((PIR1 & (1U << 1U)) == 0U)
   {
      ; // Wait for hardware to set interrupt.
   }

   // Clear the interrupt:
   PIR1 &= ~(1U << 1U);

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void _i2c_write_byte(uint8_t data)
{
   // Load I2C buffer w/ client address.
   SSP1BUF = data;

   // Wait for MSP interrupt:
   while ((PIR1 & (1U << 1U)) == 0U)
   {
      ; // Wait for hardware to set interrupt.
   }

   // Clear the interrupt:
   PIR1 &= ~(1U << 1U);

   return;
}
