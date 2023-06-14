#include <stdio.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define delayTAG "DELAY"

void logLevelPractice();
void delayPractice();
void digitalOutput(int);
void digitalInput();

void app_main(void)
{
}

void logLevelPractice()
{
    esp_log_level_set("LOG", ESP_LOG_INFO);
    ESP_LOGE("LOG", "This is an error");
    ESP_LOGW("LOG", "This is a warning");
    ESP_LOGI("LOG", "This is an info");
    ESP_LOGD("LOG", "This is a debug");
    ESP_LOGV("LOG", "This is a verbose");
}
void delayPractice()
{
    int i = 0;
    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        ESP_LOGI(delayTAG, "loop %d", i++);
    }
}
void digitalOutput(int _delay)
{
    int ledPin = 2;
    int ledStatus = 0;
    gpio_reset_pin(ledPin);
    gpio_set_direction(ledPin, GPIO_MODE_OUTPUT);
    ESP_LOGI("ledBlink", "Blinking GPIO: %d every: %d seconds", ledPin, _delay);
    while (true)
    {
        ledStatus = !ledStatus;
        ESP_LOGI("ledBlink", "Led Staus: %d", ledStatus);
        gpio_set_level(ledPin, ledStatus);
        vTaskDelay(_delay / portTICK_PERIOD_MS);
    }
}
void digitalInput()
{
    int inputPin = 4;
    gpio_reset_pin(inputPin);
    gpio_set_direction(inputPin, GPIO_MODE_INPUT);
    // gpio_pulldown_en(inputPin);
    gpio_pullup_en(inputPin);
    while (true)
    {
        ESP_LOGI("digitalInput", "Status of GPIO %d is: %d", inputPin, gpio_get_level(inputPin));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}