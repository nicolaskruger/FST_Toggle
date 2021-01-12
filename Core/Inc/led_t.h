#ifndef __LED_LIB_H
#define __LED_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l0xx_hal.h"


typedef struct led_t
{
	uint16_t pin;
	GPIO_TypeDef* port;
}let_t ;

void led_t_init(struct led_t* this, GPIO_TypeDef* port,uint16_t pin);
void led_on(struct led_t* this);
void led_off(struct led_t* this);
#ifdef __cplusplus
}
#endif

#endif
