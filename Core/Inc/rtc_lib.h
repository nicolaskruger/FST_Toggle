#ifndef __RTC_LIB_H
#define __RTC_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l0xx_hal.h"

struct Rtc_lib
{
	RTC_HandleTypeDef* hrtc;
	RTC_TimeTypeDef stime;
	RTC_DateTypeDef sdate;
};

void constructorRtc_lib(struct Rtc_lib* this,RTC_HandleTypeDef* hrtc);
void printRTC(struct Rtc_lib* this);
void atlTime(struct Rtc_lib* this);

#ifdef __cplusplus
}
#endif

#endif
