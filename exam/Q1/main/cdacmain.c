#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/queue.h>

TaskHandle_t xHandle1,xHandle2,xHandle3,xHandle4,xHandle5;
QueueHandle_t queue;

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

void Task3(void *pvParameteres)
{
    int c=0;
    while(1)
    {
    c++;
    printf("Task 3 Value of c is %d\n",c);
    vTaskDelay(5000/ portTICK_PERIOD_MS);

    }
}

void Task4(void *pvParameteres)
{
    int send_data=0;
    while(1)
    {
    send_data++;
    xQueueSend(queue,&send_data,portMAX_DELAY);
    vTaskDelay(500/ portTICK_PERIOD_MS);

    }
}

void Task5(void *pvParameteres)
{
    int get_data=0;
    while(1)
    {
    xQueueReceive(queue,&get_data,portMAX_DELAY);
    printf("The value recived from task 4 to task 5 is %d\n",get_data);
    vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t r;
    queue=xQueueCreate(10,sizeof(int));

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
    
    r=  xTaskCreate(Task4,"Task1",2048,NULL,8,&xHandle4);
        if(r==pdPASS)
    {
        printf("Task 4 created\n");
    }
    
    r=  xTaskCreate(Task5,"Task1",2048,NULL,9,&xHandle5);
        if(r==pdPASS)
    {
        printf("Task 5 created\n");
    }
}
