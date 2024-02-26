#include "simcom_module.h"

#define SERIAL_BAUD_RATE 115200

void setup()
{
    Serial.begin(115200);

    SIMCOM::init(SERIAL_BAUD_RATE);
}

void loop()
{
    uint8_t stat = SIMCOM::runATCommand(AT, 200);
    
    if(stat)
    {
        Serial.println("AT Command executed successfully.");
    }
    else
    {
        Serial.println("AT Command failed.");
    }
}