/*
 * led_lib.c
 *
 *  Created on: Jan 10, 2021
 *      Author: nicolas-kruger
 */

#include "led_lib.h"

void constructorLed_lib(struct Led_lib* this, GPIO_TypeDef* port,uint16_t pin){
	this->port=port;
	this->pin=pin;
}
void ledOn(struct Led_lib* this){
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_SET);
}
void ledOff(struct Led_lib* this){
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_RESET);
}
