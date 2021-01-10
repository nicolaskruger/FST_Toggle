/*
 * rtc_lib.c
 *
 *  Created on: Jan 10, 2021
 *      Author: nicolas-kruger
 */
#include "rtc_lib.h"

void constructorRtc_lib(struct Rtc_lib* this,RTC_HandleTypeDef* hrtc){
	this->hrtc = hrtc;
}
void printRTC(struct Rtc_lib* this){
	printf("%02d/%02d/%02d %02d:%02d:%02d\n\r",this->sdate.Date,this->sdate.Month,this->sdate.Year,
			this->stime.Hours,this->stime.Minutes,this->stime.Seconds);
}
void atlTime(struct Rtc_lib* this){
	HAL_RTC_GetDate(this->hrtc, &this->sdate, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(this->hrtc, &this->stime, RTC_FORMAT_BIN);
}


