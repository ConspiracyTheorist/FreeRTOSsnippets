#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdint.h>

/* Example of task params */
typedef struct{
  uint16_t value;
  char* str;
} run_params_t;

/* Task function */ 
void run_task(void *pvParameters){
    /* Get params */
    run_params_t *par = pvParameters!=NULL ? 
      (run_params_t*)pvParameters : (run_params_t*)malloc(sizeof(run_params_t));
    par->value++;
    asprintf(&par->str,"value is %d",par->value);
    while(1){
      /* Some actions */
      vTaskDelay(100/portTICK_RATE_MS); //Wait 100ms
    }
    free(par->str);
    /* Delete this task after job is done */
    vTaskDelete(NULL);
}

/* Created task handle */
const TaskHandle_t run_task_handle; 
/* Task params */
run_params_t run_params = { .value = 10, .str = "string" };

/* Task settings
 * 1*1024 - Stack size 
 * 2 - Prioryty, 0..configMAX_PRIORITIES-1 0 - higher 
 */

/* Create task variants */
/*    named task with params */
xTaskCreate(&run_task,"task name",1*1024,(void*)&run_params,configMAX_PRIORITIES/2,&run_task_handle);
/*    named task without params */
xTaskCreate(&run_task,"task name",1*1024,NULL,configMAX_PRIORITIES/2,&run_task_handle);
/*    anonymous task with params */
xTaskCreate(&run_task,"task name",1*1024,(void*)&run_params,configMAX_PRIORITIES/2,NULL);
/*    anonymous task */
xTaskCreate(&run_task,"task name",1*1024,NULL,configMAX_PRIORITIES/2,NULL);

/* Delete named task */
vTaskDelete(run_task_handle);

/* Change task prioryty */
vTaskPrioritySet(run_task_handle,configMAX_PRIORITIES-1);

/* Suspend task (task will not run untill vTaskResume called)  */
vTaskSuspend(run_task_handle);
/* Resume task */
vTaskResume(run_task_handle);

