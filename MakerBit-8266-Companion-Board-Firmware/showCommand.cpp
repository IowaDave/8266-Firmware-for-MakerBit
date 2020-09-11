/*
 * showCommand.cpp   implement the showCommand() function
 */

#include "showCommand.h"

void showCommand(commandEnum command, char * valuePtr) {

  switch (command) {

    case SETDP0:
      Serial.printf("Set DP0 to %s\n", valuePtr);
      break;

    case SETDP1:
      Serial.printf("Set DP1 to %s\n", valuePtr);
      break;

    case SETDP2:
      Serial.printf("Set DP2 to %s\n", valuePtr);
      break;

    case SETDP3:
      Serial.printf("Set DP3 to %s\n", valuePtr);
      break;

    case SETDP4:
      Serial.printf("Set DP4 to %s\n", valuePtr);
      break;

    case SETDP5:
      Serial.printf("Set DP5 to %s\n", valuePtr);
      break;

    case SETDP6:
      Serial.printf("Set DP6 to %s\n", valuePtr);
      break;

    case SETDP7:
      Serial.printf("Set DP7 to %s\n", valuePtr);
      break;

    case SETDP8:
      Serial.printf("Set DP8 to %s\n", valuePtr);
      break;

    default:
      delay(1);
  }
  
}
