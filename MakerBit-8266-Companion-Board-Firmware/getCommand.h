

// need Arduino.h for Serial object
#include "Arduino.h"

#define INCOMING_COMMAND_BUFFER_SIZE 101


// prototypes
boolean getCommand();

// defined in this module, made global here
extern char incomingCommand[];
