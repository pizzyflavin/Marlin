#include "../../../inc/MarlinConfig.h"

#if PIN_EXISTS(DOOR_SOLENOID)

#include "../../gcode.h"

/**
 * M132: Set door solenoid output state
 *
 *  S<bool> 0=Output LOW  1=Output HIGH
 */
void GcodeSuite::M132() {
  if (!parser.seenval('S')) return;
  WRITE(DOOR_SOLENOID_PIN, parser.value_bool());
}

#endif // PIN_EXISTS(DOOR_SOLENOID)
