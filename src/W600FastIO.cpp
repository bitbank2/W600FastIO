#include <W600FastIO.h>

#ifdef W600_EV

// convenient pointers to access the memory mapped registers
volatile uint32_t *pGPIO = (uint32_t *)PB_GPIO;
volatile uint32_t *pGPIO_EN = (uint32_t *)PB_GPIO_EN;
volatile uint32_t *pGPIO_DIR = (uint32_t *)PB_GPIO_DIR;
volatile uint32_t *pGPIO_PULL_EN = (uint32_t *)PB_GPIO_PULL_EN;
volatile uint32_t *pGPIO_AF_SEL = (uint32_t *)PB_GPIO_AF_SEL;

//
// Set the GPIO port direction and pull type for a pin
// pin is WM_IO_PA_00 to WM_IO_PA_15 or WM_IO_PB_00 to WM_IO_PB_31
//
void w600PinMode(int pin, int mode)
{
  int iOffset = 0;
  
  if (pin >= WM_IO_PB_00)
  {
    pin -= WM_IO_PB_00;
    iOffset = GPIO_AB_DIFF/4;
  }
  pGPIO_AF_SEL[iOffset] &= ~(1<<pin); // clr to enable GPIO pin function
  if (mode == GPIO_OUTPUT)
  {
    pGPIO_DIR[iOffset] |= (1<<pin); // set for output
  }
  else // must be input
  {
    pGPIO_DIR[iOffset] &= ~(1<<pin); // clr for input
    if (mode == GPIO_INPUT) // input floating
    {
      pGPIO_PULL_EN[iOffset] |= (1 << pin); // 1 to disable
    }
    else if (mode == GPIO_INPUT_PULLUP || mode == GPIO_INPUT_PULLDOWN) // pull up or down (depends on GPIO)
    {
      pGPIO_PULL_EN[iOffset] &= ~(1 << pin); // 0 to enable
    }
  }
} /* w600PinMode() */

//
// Quick GPIO read from B ports
// pin is WM_IO_PA_00 to WM_IO_PA_15 or WM_IO_PB_00 to WM_IO_PB_31
//
int w600DigitalRead(int pin)
{
  int iOffset = 0;
  
  if (pin >= WM_IO_PB_00)
  {
    pin -= WM_IO_PB_00;
    iOffset = GPIO_AB_DIFF/4;
  }
  return (pGPIO[iOffset] >> pin) & 1;
} /* w600DigitalRead() */
//
// Quick GPIO write to B ports
// pin is WM_IO_PA_00 to WM_IO_PA_15 or WM_IO_PB_00 to WM_IO_PB_31
//
void w600DigitalWrite(int pin, int value)
{
uint32_t reg;
  int iOffset = 0;
  
  if (pin >= WM_IO_PB_00)
  {
    pin -= WM_IO_PB_00;
    iOffset = GPIO_AB_DIFF/4;
  }
 reg = pGPIO[iOffset];
 if(value)
   pGPIO[iOffset] = reg | (1<<pin);
 else
   pGPIO[iOffset] = reg & ~(1<<pin);
} /* w600DigitalWrite() */
#endif // W600_EV
