#include "uart_cmd.h"

#define TIME_OUT 0x40000000
uint32_t time_out = 0;

UINT8 uart0_read_1_byte(void) {
  UINT8 c;

  while (!RI) {
    time_out++;
    if (time_out > TIME_OUT) return 0;
  }

  c = SBUF;
  RI = 0;
  return (c);
}

char get_uart_data(uint8_t *uart_buf, uint8_t num_bytes) {
  UINT8 c;
  UINT8 i = 0;
  uint8_t cnt_bytes = 0;

  do {
    c = uart0_read_1_byte();

    if (time_out > TIME_OUT)
      return 0;
    else
      time_out = 0;

    if (c != 0) {
      uart_buf[cnt_bytes] = c;
      cnt_bytes += 1;
    }

  } while (cnt_bytes < num_bytes);

  RI = 0;

  for (i = 0; i < num_bytes; i++) {
    debug("%c", uart_buf[i]);
  }
  debug("\r\n");

  return num_bytes;
}