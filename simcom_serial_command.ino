#include "simcom_module.h"

void setup()
{
    Serial.begin(115200);

    SIM7672X::init(9, 10, 115200);
}

void loop()
{
    uint8_t stat = SIM7672X::runATCommand(AT, 200);
    
    if(stat)
    {
        Serial.println("AT Command executed successfully.");
    }
    else
    {
        Serial.println("AT Command failed.");
    }
}