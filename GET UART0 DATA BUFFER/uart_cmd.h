#ifndef _UART_CMD_
#define _UART_CMD_

#include "Common.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"

char get_uart_data(uint8_t *uart_buf, uint8_t num_bytes);

#endif