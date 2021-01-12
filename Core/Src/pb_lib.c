/*
 * pb_lib.c
 *
 *  Created on: Jan 10, 2021
 *      Author: nicolas-kruger
 */
#include "pb_lib.h"

void pb_lib_init(struct pb_lib* this,GPIO_TypeDef* port,uint16_t pin){
	this->pin = pin;
	this->port= port;
	this->state = DOWN;
}
int pb_lib_click(struct pb_lib* this){
	int state = HAL_GPIO_ReadPin(this->port, this->pin);
	for(int i= 0;i<STEEP_LOOP_PB;i++){
		if(state!=HAL_GPIO_ReadPin(this->port, this->pin))
			return UNCLICKED;
		HAL_Delay(DELAY_PB);
	}
	int ret = UNCLICKED;
	if(this->state==DOWN&&state!=this->state){
		ret = CLICKED;
	}
	this->state = state;
	return ret;
}
