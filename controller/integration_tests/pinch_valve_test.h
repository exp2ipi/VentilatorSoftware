// This test repeatedly opens and closes a pinch valve

#include "hal.h"
#include "pinch_valve.h"

// test parameters
static constexpr int64_t delay_ms{1000};

void run_test() {
  Hal.init();
  PinchValve pinch_valve(0);
  pinch_valve.Home();

  bool valve_open{false};
  while (true) {
    pinch_valve.SetOutput(valve_open ? 1.0f : 0.0f);
    Hal.delay(milliseconds(delay_ms));

    Hal.watchdog_handler();

    valve_open = !valve_open;
  }
}
