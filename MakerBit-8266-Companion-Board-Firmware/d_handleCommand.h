

// need Arduino.h for certain macro definitions
#include "Arduino.h"

// need struct and enum declarations from command.h
#include "command.h"

// need the LCD library
#include "lcd.h"

// need the showCommand header
#include "showCommand.h"

// prototypes made public here
void handleCommand( cmdPointerList theCommand );
void showCommandParts( cmdPointerList theCommand );

// variables defined in this module
// made global here
extern const char debugGetDP[];
extern const char debugSetDP[];

// variables defined elsewhere, used in this module
extern int lcdCursorColumn;
extern int lcdCursorRow;
extern int lcdAddress;
extern LiquidCrystal_I2C * lcd;
extern int numberOfKnownCommands;
