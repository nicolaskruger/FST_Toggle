/*
 * led_lib.c
 *
 *  Created on: Jan 10, 2021
 *      Author: nicolas-kruger
 */

#include <led_t.h>

void led_t_init(struct led_t* this, GPIO_TypeDef* port,uint16_t pin){
	this->port=port;
	this->pin=pin;
}
void led_on(struct led_t* this){
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_SET);
}
void led_off(struct led_t* this){
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_RESET);
}
