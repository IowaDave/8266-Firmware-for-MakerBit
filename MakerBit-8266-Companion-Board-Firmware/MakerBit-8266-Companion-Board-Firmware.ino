

/********************************************************
 * MakerBit-8266-Companion-Board-Firmware               *
 * by David "IowaDave" Sparks                           *
 * Version 2.0  Initial 2020-09-10                      *
 *                                                      *
 * Receive predefined instructions via serial           *
 * Execute the instructions on the companion board      *
 * Transmit data via serial in response to requests     *
 *                                                      *
 * Inspired by Roger Wagner's request for a way to      *
 * program an 8266 in MakeCode (makecode.microbit.org)  *
 ********************************************************/

// include the following modules in this sketch folder
#include "command.h"
#include "getCommand.h"
#include "parseCommand.h"
#include "lcd.h"
#include "showCommand.h"
#include "d_handleCommand.h"

// left here for reference; not used, I believe
//#define SCL_PIN D1
//#define SDA_PIN D2

// declare a global struct of pointers for processing commands
cmdPointerList commandDetails;


void setup() {
  Serial.begin(115200);
  delay(1000);
   
  // this global variable needs to be initialized once, here
  numberOfKnownCommands = countTheCommands();

  // set the range of 8266 PWM to min 0 max 100
  analogWriteRange(100);
}

void loop() {
  // wait for a command
  boolean commandReceived = getCommand(); // fill buffer with new command, if any
  // when command received, process it
  if (commandReceived) {
    // parse the command into pointers
    commandDetails = parseCommand(incomingCommand);
    // execute the command by reference to the pointers
    handleCommand(commandDetails);
  }
}
