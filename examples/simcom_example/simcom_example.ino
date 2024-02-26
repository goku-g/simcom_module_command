#include "simcom_module.h"

void setup()
{
    Serial.begin(115200);

    SIMCOM::init(9, 10, 115200);
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