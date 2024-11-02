#include "CheckTemperatureBreach.h"
#include "AlertTemperatureBreach.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

RangeOfTemperature getTemperatureRange(CoolingType coolingType) {
    if (coolingType < PASSIVE_COOLING || coolingType > MED_ACTIVE_COOLING) {
        fprintf(stderr, "Error: Invalid cooling type.\n");
    }
    return Range[coolingType];
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  RangeOfTemperature RangeOfCooling = getTemperatureRange(coolingType);
  return inferBreach(temperatureInC, RangeOfCooling.lowerLimit, RangeOfCooling.upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  sendAlert(alertTarget, breachType);
}
