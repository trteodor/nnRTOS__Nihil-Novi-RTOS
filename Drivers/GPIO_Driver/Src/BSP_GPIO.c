#include "BSP_GPIO.h"

#define GPIO_NUMBER           16u

void BSP_LedGPIO_Init(void)
{
RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

GPIOD->MODER |= (GPIO_MODER_MODER12_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER15_0);

}

void tooglePIN(GPIO_TypeDef *GPIOx, Gpio_Ch_st GPIO_Pin)
{
  uint32_t odr;
  odr = GPIOx->ODR;
  GPIOx->BSRR = ((odr & GPIO_Pin) << GPIO_NUMBER) | (~odr & GPIO_Pin); //taki trick
}

void GPIO_PinSet(GPIO_TypeDef *GPIOx, Gpio_Ch_st GPIO_Pin)
{
  GPIOx->BSRR = GPIO_Pin;
  
}

void GPIO_PinReset(GPIO_TypeDef *GPIOx, Gpio_Ch_st GPIO_Pin)
{
  uint32_t odr;
  odr = GPIOx->ODR;
  GPIOx->BSRR = ((odr & GPIO_Pin) << GPIO_NUMBER);
}
