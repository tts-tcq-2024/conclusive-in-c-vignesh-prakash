#include "CheckTemperatureBreach.h"
#include "AlertTemperatureBreach.h"
#include <stdio.h>
#include <string.h>

int main() {
    AlertTarget alertTarget = TO_CONTROLLER;
   
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    strncpy(batteryChar.brand, "BOSCH", sizeof(batteryChar.brand) - 1);
    batteryChar.brand[sizeof(batteryChar.brand) - 1] = '\0';

    double temperatureInC = 40.0;
    
    checkAndAlert(alertTarget,batteryChar,temperatureInC);

    return 0;
}

