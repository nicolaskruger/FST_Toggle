#ifndef __LED_LIB_H
#define __LED_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l0xx_hal.h"


struct Led_lib
{
	uint16_t pin;
	GPIO_TypeDef* port;
};

void constructorLed_lib(struct Led_lib* this, GPIO_TypeDef* port,uint16_t pin);
void ledOn(struct Led_lib* this);
void ledOff(struct Led_lib* this);
#ifdef __cplusplus
}
#endif

#endif
