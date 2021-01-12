#ifndef __FSM_TOGGLE_H
#define __FSM_TOGGLE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l0xx_hal.h"
#include "pb_lib.h"
#include "rtc_lib.h"
#include <led_t.h>


typedef enum states_e{
	STATE_DOWN  = 0,
	STATE_UPPING,
	STATE_UP,
	STATE_DOWNING,
	__END_OF_STATES__,
};

typedef struct fsm_toggle
{
	struct pb_lib pb;
	struct rtc_lib rtc;
	struct led_t led;
	void (*state[__END_OF_STATES__])(struct fsm_toggle* this);
	int currentState;

}fsm_toggle;

void fsm_toggle_init(struct fsm_toggle* this,GPIO_TypeDef* port,uint16_t pin,
		RTC_HandleTypeDef* hrtc,GPIO_TypeDef* portLed,uint16_t pinLed);
void fsm_toggle_call(struct fsm_toggle* this);

#ifdef __cplusplus
}
#endif

#endif
