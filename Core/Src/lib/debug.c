//
// Created by tobias on 26-2-25.
//
#include "lib/debug.h"
#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart1;

void fDebugPrint(char* fmt, ...) {
  va_list args;
  va_start(args, fmt);

  char buf[64];
  vsprintf(buf, fmt, args);

  va_end(args);

  HAL_UART_Transmit(&huart1, (uint8_t *) buf, strlen(buf) + 1, HAL_TIMEOUT);
}
