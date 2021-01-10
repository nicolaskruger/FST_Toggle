#ifndef __FSM_TOGGLE_H
#define __FSM_TOGGLE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l0xx_hal.h"
#include "pb_lib.h"
#include "rtc_lib.h"
#include "led_lib.h"

#define FSM_DOWNING 3
#define FSM_UP 2
#define FSM_UPPING 1
#define FSM_DOWN 0

struct FSM_toggle
{
	struct Pb_lib pb;
	struct Rtc_lib rtc;
	struct Led_lib led;
	void (*state[4])(struct FSM_toggle* this);
	int currentState;

};

void constructorFSM_toggle(struct FSM_toggle* this,GPIO_TypeDef* port,uint16_t pin,
		RTC_HandleTypeDef* hrtc,GPIO_TypeDef* portLed,uint16_t pinLed);
void call(struct FSM_toggle* this);
void fsmUp(struct FSM_toggle* this);
void fsmUpping(struct FSM_toggle* this);
void fsmDown(struct FSM_toggle* this);
void fsmDowing(struct FSM_toggle* this);

#ifdef __cplusplus
}
#endif

#endif
