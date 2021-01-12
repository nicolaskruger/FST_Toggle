#ifndef __RTC_LIB_H
#define __RTC_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l0xx_hal.h"

typedef struct rtc_lib
{
	RTC_HandleTypeDef* hrtc;
	RTC_TimeTypeDef stime;
	RTC_DateTypeDef sdate;
}rtc_lib;

void constructorRtc_lib(struct rtc_lib* this,RTC_HandleTypeDef* hrtc);
void printRTC(struct rtc_lib* this);
void atlTime(struct rtc_lib* this);

#ifdef __cplusplus
}
#endif

#endif
