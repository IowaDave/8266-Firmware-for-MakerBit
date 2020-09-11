

#include "getCommand.h"

// define this string here
char incomingCommand[INCOMING_COMMAND_BUFFER_SIZE]; // accept command strings of up to 100 chars long


boolean getCommand() {
  // initialize
  int bufIndex = 0; // initialize to zero
  boolean commandBufferHasNewContents = false;
  char testChar;
  if (Serial.available() > 0) {
    // pause briefly to allow the receive buffer to fill
    delay(50);
    while ( Serial.available() > 0 )
    {
      // read a char
      testChar = Serial.read();
      // exit if it has any one of the following values
      if (
        testChar == -1
        || testChar == 0
        || testChar == 10
        || testChar == 13
        || testChar == 126 ) 
      {
          break;
      }
      // valid char passes the test
      // add it to buffer and increment the buffer index
      incomingCommand[bufIndex] = testChar;
      bufIndex += 1;
      // also set the return value to true
      commandBufferHasNewContents = true;
      // is the buffer full?
      if (bufIndex == INCOMING_COMMAND_BUFFER_SIZE) {
      // yes, it is; exit the while loop
      break;
      }
      // otherwise reiterate the while loop
    } // end of while loop
    // terminate the buffer
    incomingCommand[bufIndex] = '\0'; // null terminates a C-type string
  }
  return commandBufferHasNewContents;
}
