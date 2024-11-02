#include <gtest/gtest.h>
#include "CheckTemperatureBreach.h"
#include "AlertTemperatureBreach.h"

class MockAlert {
public:
    MOCK_METHOD(void, sendToController, (BreachType), ());
    MOCK_METHOD(void, sendToEmail, (BreachType), ());
};

// Global mock alert instance
MockAlert mockAlert;

TEST(TypeWiseAlertTestSuite, CheckAndAlertNormalTemperature) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;

    EXPECT_CALL(mockAlert, sendToEmail(NORMAL)).Times(1);
    checkAndAlert(TO_EMAIL, batteryChar, 25);  // Within PASSIVE_COOLING limit
}

TEST(TypeWiseAlertTestSuite, CheckAndAlertHighTemperature) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;

    EXPECT_CALL(mockAlert, sendToEmail(TOO_HIGH)).Times(1);
    checkAndAlert(TO_EMAIL, batteryChar, 46);  // Exceeds HI_ACTIVE_COOLING limit
}

TEST(TypeWiseAlertTestSuite, CheckAndAlertLowTemperature) {
    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;

    EXPECT_CALL(mockAlert, sendToEmail(TOO_LOW)).Times(1);
    checkAndAlert(TO_EMAIL, batteryChar, -5);  // Below MED_ACTIVE_COOLING limit
}
