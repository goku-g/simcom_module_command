#include "simcom_module.h"

#include <SoftwareSerial.h>

// init simcom uart object

void SIMCOM::SIMCOM(uint32_t baudrate, uint8_t rx_pin, uint8_t tx_pin)
{
    Serial.println("SIMCOM Initializing...");
    
    SoftwareSerial SimCom(rx_pin, tx_pin);

    SimCom.begin(baudrate);
}

String SIMCOM::UARTRead(uint32_t time_out)
{
    Serial.println("SIMCOM's UART Reading.");

    uint32_t prev_time= millis();
    while(!(SimCom.available()) && !(millis() > prev_time + time_out)){}
    
    if(SimCom.available())
    {
        return SimCom.readString();
    }
    return "TimeOut";
}

uint8_t SIMCOM::runATCommand(ATCommands command, uint32_t time_out)
{
    uint8_t status = 0;
    String res_buf;

    Serial.println("Executing "+String(command)+" Commands.");

    SIMCOM::UARTRead(time_out); // release all string from buffer!

    switch(command)
    {
        case AT:
            SimCom.println(F("AT"));
            res_buf = SIMCOM::UARTRead(time_out);
            if(res_buf.indexOf(F("OK")) != -1) status = 1;
            break;

        /* Add cases according to you needs and conditions */
        /* USER CODE START*/

        /* USER CODE END*/

        default:
            Serial.println("runATCommand() failed! Please check your command.");
            break;
    }
    Serial.println(res_buf);
    return status;
}

/* Add functions definations here (replace function name with SIMCOM::<name>) */
/* USER CODE START*/
    
/* USER CODE END*/