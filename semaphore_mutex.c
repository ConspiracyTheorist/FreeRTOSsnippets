#include "freertos/FreeRTOS.h"

SemaphoreHandle_t some_mutex;

/* Crate mutex */
some_mutex = xSemaphoreCreateMutex();

/* Take Mutex */
if(xSemaphoreTake(some_mutex,100/portTICK_PERIOD_MS) == pdTRUE){
  /* Do somthing */
  /* Then give mutex back */
  xSemaphoreGive(some_mutex);
}

/* Delete mutex */
vSemaphoreDelete(some_mutex);

