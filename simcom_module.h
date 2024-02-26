#ifndef SIMCOM_A7672X_H
#define SIMCOM_A7672X_H

#include <Arduino.h>

#define RX_PIN 0
#define TX_PIN 1

enum ATCommands
{
    AT = 0
    /* Add required commands here */
    /* USER CODE START*/
        
    /* USER CODE END*/
};

namespace SIMCOM
{
    void init(uint8_t rx, uint8_t tx, uint32_t baudrate);
    String UARTRead(uint32_t time_out);
    uint8_t runATCommand(ATCommands command, uint32_t time_out);
};

#endif