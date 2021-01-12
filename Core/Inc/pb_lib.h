#ifndef __PB_LIB_H
#define __PB_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l0xx_hal.h"
#define CLICKED 1
#define UNCLICKED 0
#define DELAY_PB 1
#define STEEP_LOOP_PB 10
#define UP 1
#define DOWN 0

typedef struct pb_lib
{
	uint16_t pin;
	GPIO_TypeDef* port;
	uint16_t state;
}pb_lib;

void pb_lib_init(struct pb_lib* this,GPIO_TypeDef* port,uint16_t pin);
int pb_lib_click(struct pb_lib* this);

#ifdef __cplusplus
}
#endif

#endif
