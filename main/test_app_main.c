#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// #include "driver/gpio.h"
#include "esp_log.h"
// #include "esp_system.h"


static const char *TAG = "MainApp";
static uint32_t cnt =0;
// Idle hook function (called when system is idle by FreeRTOS)
void vApplicationIdleHook(void)
{
    cnt++;
}

// Example task
void my_task(void *param)
{
    while (1) {
        ESP_LOGI(TAG, "Idle count: %ld", cnt);
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2 seconds
    }
}

void app_main(void)
{
    ESP_LOGI(TAG, "App started.");

    // Create a task
    xTaskCreate(my_task, "MainTask", 2048, NULL, 5, NULL);

    // Optional: Manually call the idle hook function (for testing/demo)
    vApplicationIdleHook();  // <-- This is just a one-time call

    // Note: the idle hook will also be called automatically by FreeRTOS when idle
}
