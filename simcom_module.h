#ifndef SIMCOM_A7672X_H
#define SIMCOM_A7672X_H

#include <Arduino.h>

#define RX_PIN 0    // change rx pin according to your need
#define TX_PIN 1    // change tx pin according to your need

enum ATCommands
{
    /* Add required commands here (separate with comma)*/
    /* USER CODE START*/
    AT = 0
        
    /* USER CODE END*/
};

class SIMCOM
{
public:
    SIMCOM(uint32_t baudrate, uint8_t rx_pin, uint8_t tx_pin);
    String UARTRead(uint32_t time_out);
    uint8_t runATCommand(ATCommands command, uint32_t time_out);

private:
    uint32_t _baudrate;
    uint8_t _rx_pin;
    uint8_t _tx_pin;
};

#endif