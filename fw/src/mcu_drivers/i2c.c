////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "i2c.h"

#include <xc.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Definition(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
// PPS Input Selection
#define PPS_SCL1 0x07 // SCL Peripheral
#define PPS_SDA1 0x08 // SDA Peripheral

// SSPxCON1 Bits
#define SSPEN (1U << 5U) // Host Synchronous Serial Port Enable
#define SSPM 8U // Host Synchronous Serail Port Mode Select

// SSPxCON2 Bits
#define SEN 1U // Start Condition Enable Bit
#define PEN (1U << 2U) // Stop Condition Enable Bit

// RxyI2C Bits
#define TH 1U // I2C Input Thresholds
#define SLEW (1U << 6U) // I2C Slew Rate Limiting Enable

// xxxPPS Bits
#define PPS_PORTB (1U << 3U) // PORT B

// ANSELx Bits
#define ANSELx4 (1U << 4U) // Pin 4
#define ANSELx6 (1U << 6U) // Pin 6

// ODCONB Bits
#define ODCx4 (1U << 4U) // Pin 4
#define ODCx6 (1U << 6U) // Pin 6

// SSPxADD Bits
#define BAUD_DIV 0x4F // 100kHz BAUD (32MHz FOSC)

// PIR1 Bits
#define SSP1IF (1U << 1U) // MSSP1 Interrupt Flag

////////////////////////////////////////////////////////////////////////////////////////////////////
void config_i2c(void)
{
   // Disable Serial Peripheral:
   SSP1CON1 &= ~SSPEN;

   // I2C Threshold Config:
   RB4I2C |= SLEW | TH;
   RB6I2C |= SLEW | TH;

   // Set Peripheral Input to I2C:
   SSP1CLKPPS = PPS_PORTB | 4U; // PORT B PIN 4
   SSP1DATPPS = PPS_PORTB | 6U; // PORT B PIN 6

   // Set Peripheral Output to I2C:
   RB4PPS = PPS_SCL1;
   RB6PPS = PPS_SDA1;

   // Disable Analog Functions on I2C Pins:
   ANSELB &= ~(ANSELx4 | ANSELx6);

   // Set I2C Pins as Open Drain:
   ODCONB |= ODCx4 | ODCx6;

   // MSSP Baud Rate Divider:
   SSP1ADD = BAUD_DIV;

   // MSSP Control Register Config:
   SSP1CON1 |= SSPM;

   // Enable Serial Peripheral:
   SSP1CON1 |= SSPEN;

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
   PIR1 &= ~SSP1IF;

   // Initiate start condition.
   SSP1CON2 |= SEN;

   // Wait for MSP Interrupt:
   while (!(PIR1 & SSP1IF))
   {
      ; // Wait for hardware to set interrupt.
   }

   // Clear the interrupt:
   PIR1 &= ~SSP1IF;

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void _i2c_stop(void)
{
   // Clear I2C interrupt:
   PIR1 &= ~SSP1IF;

   // Send stop condition.
   SSP1CON2 |= PEN; // Set PEN bit.

   // Wait for MSP Interrupt:
   while (!(PIR1 & SSP1IF))
   {
      ; // Wait for hardware to set interrupt.
   }

   // Clear the interrupt:
   PIR1 &= ~SSP1IF;

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void _i2c_write_byte(uint8_t data)
{
   // Load I2C buffer w/ client address.
   SSP1BUF = data;

   // Wait for MSP interrupt:
   while (!(PIR1 & SSP1IF))
   {
      ; // Wait for hardware to set interrupt.
   }

   // Clear the interrupt:
   PIR1 &= ~SSP1IF;

   return;
}
