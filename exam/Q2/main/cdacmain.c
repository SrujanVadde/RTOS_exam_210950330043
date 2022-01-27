#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>

TaskHandle_t xHandle1,xHandle2,xHandle3;
TimerHandle_t timer_handler;
int count=0;

void Task1(void *pvParameteres)
{
    int a=0;
    while(1)
    {
    a++;
    printf("Task 1 Value of a is %d\n",a);
    vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}

void Task2(void *pvParameteres)
{
    int b=0;
    while(1)
    {
    b++;
    printf("Task 2 Value of b is %d\n",b);
    vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}

void Task_1(TimerHandle_t xTimer)
{

    printf("Timer Task\n");
}

void Task3(void *pvParameteres)
{
    int c=0;
    while(1)
    {
    vTaskDelay(5000/ portTICK_PERIOD_MS);
    c++;
    printf("Task 3 Value of c is  %d\n",c);
    
    if(c==2)
    {
    timer_handler=xTimerCreate("OFF",pdMS_TO_TICKS(1000),pdFALSE,NULL,Task_1);
    xTimerStart(timer_handler,0);
    }

    }
}


void app_main()
{
    BaseType_t r;
    r=  xTaskCreate(Task1,"Task1",2048,NULL,5,&xHandle1);
        if(r==pdPASS)
    {
        printf("Task 1 created\n");
    }
    
    r=  xTaskCreate(Task2,"Task1",2048,NULL,6,&xHandle2);
        if(r==pdPASS)
    {
        printf("Task 2 created\n");
    }
    r=  xTaskCreate(Task3,"Task1",2048,NULL,7,&xHandle3);
        if(r==pdPASS)
    {
        printf("Task 3 created\n");
    }
    

}
