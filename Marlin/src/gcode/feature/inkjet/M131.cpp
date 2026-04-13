#include "../../../inc/MarlinConfig.h"

#if ENABLED(HP45_INKJET)

#include "../../gcode.h"
#include "../../../HAL/shared/Delay.h"

/**
 * M131: Send enable signal to HP45 controller
 */
void GcodeSuite::M131() {
  HP45_ENABLE_PORT->BSRR = HP45_ENABLE_PIN_MASK << 16; // Pull LOW
  DELAY_US(5);
  //safe_delay(1);
  HP45_ENABLE_PORT->BSRR = HP45_ENABLE_PIN_MASK; // Pull HIGH
}

#endif // HP45_INKJET
