#include <stdio.h>
#include "CheckTemperatureBreach.h"

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
    const char* recipient = "a.b@c.com";
    const char* messages[] = {
        "Hi, the temperature is normal",     // NORMAL (0)
        "Hi, the temperature is too low",    // TOO_LOW (1)
        "Hi, the temperature is too high"    // TOO_HIGH (2)
    };
    if (breachType >= NORMAL && breachType <= TOO_HIGH) {
        printf("To: %s\n", recipient);
        printf("%s\n", messages[breachType]);
    } 
}

void sendAlert(AlertTarget alertTarget, BreachType breachType) {
    if (alertTarget == TO_CONTROLLER) {
        sendToController(breachType);
    } else if (alertTarget == TO_EMAIL) {
        sendToEmail(breachType);
    } 
}
