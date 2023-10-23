#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "stm32f4xx_hal.h"
extern RTC_HandleTypeDef hrtc;
extern RTC_TimeTypeDef RTC_Time;
extern RTC_DateTypeDef RTC_Date;
extern char buffer[700];
#include "main.h"
#include "string.h"
#include "cstdio"
extern "C"
{
     extern UART_HandleTypeDef huart6;
}
#include "ff.h"

#endif

Model::Model() : modelListener(0), button_State(false), counterValue(0)
{

}

void Model::tick()
{
#ifdef SIMULATOR
    // Code spécifique à la simulation
    // ...
#else
    // Code spécifique à l'exécution sur le matériel réel (STM32)
    HAL_RTC_GetTime(&hrtc, &RTC_Time, FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &RTC_Date, FORMAT_BIN);
    const char* texteDuBuffer = getTextFromBuffer();
    modelListener->updateTime(RTC_Time.Hours, RTC_Time.Minutes, RTC_Time.Seconds);
    modelListener->updateDate(RTC_Date.Date, RTC_Date.Month, RTC_Date.Year);
    modelListener->updateTextFromBuffer(texteDuBuffer);



    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3) || HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) || HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))
    {
        button_State = true;
        HAL_Delay(500);
        modelListener->count(true);
        saveButton(counterValue);
        char uartBuffer[20]; // Créer un tampon pour stocker la valeur
        snprintf(uartBuffer, sizeof(uartBuffer), "compt%d\n", counterValue);
        HAL_UART_Transmit(&huart6, (uint8_t *)uartBuffer, strlen(uartBuffer), 10);
    }
    else
    {
        button_State = false;
    }
#endif
}

void Model::saveButton(int counterValue)
{
    this->counterValue = counterValue;
    char countBuffer[20]; // Créer un tampon pour stocker la valeur
    snprintf(countBuffer, sizeof(countBuffer), "compt%d\n", counterValue);
    HAL_UART_Transmit(&huart6, (uint8_t *)countBuffer, strlen(countBuffer), 10);
}

int Model::getCounterValue() const
{
    return counterValue;
}
const char* Model::getTextFromBuffer()
{
    // Copier le contenu du buffer dans une chaîne de caractères
    static char texte[700];
    strncpy(texte, buffer, sizeof(texte));

    // Assurez-vous que la chaîne est terminée par un caractère nul
    texte[sizeof(texte) - 1] = '\0';

    return texte;
}
void Model::sendData(const char* data)
{
    FATFS fs;
    FIL file;

    // Monter la carte mémoire
    f_mount(&fs, "", 0);

    // Créer ou recréer le fichier "wifi" en mode écriture
    if (f_open(&file, "wifi.txt", FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
    {
        // Écrire le contenu du buffer dans le fichier
        f_printf(&file, "%s", data);

        // Fermer le fichier
        f_close(&file);
    }
    HAL_UART_Transmit(&huart6, (uint8_t *)data, strlen(data), 10);
    HAL_Delay(1000);
}
