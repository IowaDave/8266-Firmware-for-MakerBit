/*
 * showCommand.h   declarations for showing command info via the serial port
 */

// need Arduino library for Serial object
#include "Arduino.h"

// need command.h header for certain declarations
#include "command.h"

// prototype defined in this module made global here
void showCommand(commandEnum command, char * valuePtr);
