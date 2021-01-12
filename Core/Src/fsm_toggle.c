/*
 * fsm_toggle.c
 *
 *  Created on: Jan 10, 2021
 *      Author: nicolas-kruger
 */
#include "fsm_toggle.h"

void fsm_toggle_init(struct fsm_toggle* this,GPIO_TypeDef* port,uint16_t pin,
		RTC_HandleTypeDef* hrtc,GPIO_TypeDef* portLed,uint16_t pinLed){
	pb_lib_init(&this->pb, port, pin);
	constructorRtc_lib(&this->rtc, hrtc);
	led_t_init(&this->led, portLed, pinLed);
	__init_states(this);
}
void fsm_toggle_call(struct fsm_toggle* this){
	this->state[this->currentState](this);
}
void fsm_toggle_up(struct fsm_toggle* this){
	if(pb_lib_click(&this->pb)==CLICKED)
		this->currentState = STATE_DOWNING;
}
void fsm_toggle_upping(struct fsm_toggle* this){
	led_on(&this->led);
	atlTime(&this->rtc);
	printRTC(&this->rtc);
	this->currentState = STATE_UP;
}
void fsm_toggle_down(struct fsm_toggle* this){
	if(pb_lib_click(&this->pb)==CLICKED)
			this->currentState = STATE_UPPING;
}
void fsm_toggle_dowing(struct fsm_toggle* this){
	led_off(&this->led);
	atlTime(&this->rtc);
	printRTC(&this->rtc);
	this->currentState = STATE_DOWN;
}
void __init_states(struct fsm_toggle* this){
	this->currentState = STATE_DOWN;
	this->state[STATE_UP] = &fsm_toggle_up;
	this->state[STATE_DOWN] = &fsm_toggle_down;
	this->state[STATE_UPPING] = &fsm_toggle_upping;
	this->state[STATE_DOWNING] = &fsm_toggle_dowing;
}



