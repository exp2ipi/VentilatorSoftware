// This test switches the binary solenoid between the open and closed position
//
// TODO - This test should be updated because the solenoid is now a proportional
//        solenoid with variable positions between 0 and 1 and no longer a
//        simple binary solenoid

#include "hal.h"

// test parameters
static constexpr int64_t delay_ms{1000};

void run_test() {
  Hal.init();

  bool solenoid_state = false;

  while (true) {
    Hal.PSOL_Value(solenoid_state ? 0.0f : 1.0f);

    Hal.delay(milliseconds(delay_ms));

    Hal.watchdog_handler();

    solenoid_state = !solenoid_state;
  }
}
