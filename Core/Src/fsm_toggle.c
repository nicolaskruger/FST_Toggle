/*
 * fsm_toggle.c
 *
 *  Created on: Jan 10, 2021
 *      Author: nicolas-kruger
 */
#include "fsm_toggle.h"

void constructorFSM_toggle(struct FSM_toggle* this,GPIO_TypeDef* port,uint16_t pin,
		RTC_HandleTypeDef* hrtc,GPIO_TypeDef* portLed,uint16_t pinLed){
	constructorPb_lib(&this->pb, port, pin);
	constructorRtc_lib(&this->rtc, hrtc);
	constructorLed_lib(&this->led, portLed, pinLed);
	this->currentState = FSM_DOWN;
	this->state[FSM_UP] = &fsmUp;
	this->state[FSM_DOWN] = &fsmDown;
	this->state[FSM_UPPING] = &fsmUpping;
	this->state[FSM_DOWNING] = &fsmDowing;

}
void call(struct FSM_toggle* this){
	this->state[this->currentState](this);
}
void fsmUp(struct FSM_toggle* this){
	if(click(&this->pb)==CLICKED)
		this->currentState = FSM_DOWNING;
}
void fsmUpping(struct FSM_toggle* this){
	ledOn(&this->led);
	atlTime(&this->rtc);
	printRTC(&this->rtc);
	this->currentState = FSM_UP;
}
void fsmDown(struct FSM_toggle* this){
	if(click(&this->pb)==CLICKED)
			this->currentState = FSM_UPPING;
}
void fsmDowing(struct FSM_toggle* this){
	ledOff(&this->led);
	atlTime(&this->rtc);
	printRTC(&this->rtc);
	this->currentState = FSM_DOWN;
}


