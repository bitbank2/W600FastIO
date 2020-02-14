#ifndef _W600FASTIO_
#define _W600FASTIO_

#include <stdint.h>

// W600 GPIO addresses
#define GPIOA_BASE 0x40010C00
#define GPIOB_BASE 0x40011200
#define GPIO_AB_DIFF (GPIOB_BASE - GPIOA_BASE)

#define PB_GPIO GPIOA_BASE
#define PB_GPIO_EN (PB_GPIO + 4)
#define PB_GPIO_DIR (PB_GPIO + 8)
#define PB_GPIO_PULL_EN (PB_GPIO + 12)
#define PB_GPIO_AF_SEL (PB_GPIO + 16)

#define GPIO_OUTPUT 0
#define GPIO_INPUT 1
#define GPIO_INPUT_PULLUP 2
#define GPIO_INPUT_PULLDOWN 3

#ifndef WM_IO_H
enum {
  WM_IO_PA_00=0,
  WM_IO_PA_01,
  WM_IO_PA_02,
  WM_IO_PA_03,
  WM_IO_PA_04,
  WM_IO_PA_05,
  WM_IO_PA_06,
  WM_IO_PA_07,
  WM_IO_PA_08,
  WM_IO_PA_09,
  WM_IO_PA_10,
  WM_IO_PA_11,
  WM_IO_PA_12,
  WM_IO_PA_13,
  WM_IO_PA_14,
  WM_IO_PA_15,
  WM_IO_PB_00,
  WM_IO_PB_01,
  WM_IO_PB_02,
  WM_IO_PB_03,
  WM_IO_PB_04,
  WM_IO_PB_05,
  WM_IO_PB_06,
  WM_IO_PB_07,
  WM_IO_PB_08,
  WM_IO_PB_09,
  WM_IO_PB_10,
  WM_IO_PB_11,
  WM_IO_PB_12,
  WM_IO_PB_13,
  WM_IO_PB_14,
  WM_IO_PB_15,
  WM_IO_PB_16,
  WM_IO_PB_17,
  WM_IO_PB_18
};
#endif // GPIO pin names

void w600PinMode(int pin, int mode);
int w600DigitalRead(int pin);
void w600DigitalWrite(int pin, int value);


#endif // _W600FASTIO_
