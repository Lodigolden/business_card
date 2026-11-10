////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "tmp_snsr.h"

#include "../mcu_drivers/i2c.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Definition(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
// Temperature sensor I2C addresses.
#define TMP_SNSR_ADDR 0x48

// Temperature sensor register size.
#define TMP_SNSR_REG_SIZE 2U

// Registers
#define TEMP_REG 0x00 // Read-only, returns temperature.

////////////////////////////////////////////////////////////////////////////////////////////////////
void read_temp(uint8_t* p_data, bool is_f)
{
   uint8_t data[TMP_SNSR_REG_SIZE];
   i2c_receive_data(TMP_SNSR_ADDR, TMP_SNSR_REG_SIZE, TEMP_REG, &data);

   uint8_t data_converted = data[0U];
   if (is_f)
   {
      data_converted = (1.8*data[0U] + 32);
   }

   if (data[0U] & (1U << 7U)) // Negative Temperature
   {
      ;
   }
   else // Positive Temperature
   {
      *(p_data + 3U) = data_converted / 100U;
      *(p_data + 2U) = (data_converted % 100U) / 10U;
      *(p_data + 1U) = (data_converted % 10);
   }

   return;
}
