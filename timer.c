#include "freertos/FreeRTOS.h"

static TimerHandle_t timer=NULL;

void timer_func(TimerHandle_t xTimer){
   /* Do something */ 
}

/* Create timeout timer */
timer = xTimerCreate("timer",15000/portTICK_PERIOD_MS,pdFALSE,NULL,timer_func);

/* Create periodically call timer */
timer = xTimerCreate("timer",15000/portTICK_PERIOD_MS,pdTRUE,NULL,timer_func);

/* Start timer */
xTimerStart(timer,0);
/* Stop timer */
xTimerStop(timer,0);

/* Reset timer */
xTimerReset(timer,0);
/* Change timer period */
xTimerChangePeriod(timer,5000/portTICK_PERIOD_MS,0);
