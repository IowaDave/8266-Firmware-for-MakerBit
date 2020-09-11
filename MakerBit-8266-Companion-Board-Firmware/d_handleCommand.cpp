



#include "d_handleCommand.h"

// initialize PWM values for pins 0 - 8 to be 0 = "off"
int pwmValue[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

// prototype defined in this file
int pinLevel(char * x);

// variables private to this file?
// certain strings used to process commands and errors
const char debugSetDP[] PROGMEM = "Sets the value of digital pin D%d to %s\n";
const char debugSetAP[] PROGMEM = "Error~"; // Analog pin on 8266 is read-only
const char debugGetDP[] PROGMEM = "D%d=%d~"; // return value of digital pin
const char debugGetAP[] PROGMEM = "A0=%d~"; // return value of analog pin
const char debugSetPWM[] PROGMEM = "Performs analogWrite(D%d, %s)\n";
const char debugGetPWM[] PROGMEM = "PWM%d=%d~"; // return PWM value for digital pin
const char debugLCDX[] PROGMEM = "Sets the LCD cursor to column %s\n";
const char debugLCDY[] PROGMEM = "Sets the LCD cursor to row %s\n";
const char debugLCDC[] PROGMEM = "Clears the LCD display\n";
const char debugLCDP1[] PROGMEM = "Writes the following text to the LCD\n";
const char debugLCDP2[] PROGMEM = ">>  %s  <<\n";

/*
 * implementations for the specific commands
 */


void showCommandParts( cmdPointerList theCommand ) {
  Serial.print("Instruction: "); Serial.println(theCommand.instructionPtr);
  Serial.print("Token: "); Serial.println(theCommand.tokenPtr);
  Serial.print("Value: "); Serial.println(theCommand.valuePtr);
}



void doCommand(commandEnum command, char * commandValue) {


/*
const char debugSetDP[] PROGMEM = "Sets the value of digital pin D%d to %s\n";
const char debugSetAP[] PROGMEM = "Error~"; // Analog pin on 8266 is read-only
const char debugGetDP[] PROGMEM = "D%d=%d~"; // return value of digital pin
const char debugGetAP[] PROGMEM = "A0=%d~"; // return value of analog pin
const char debugSetPWM[] PROGMEM = "Performs analogWrite(D%d, %s)\n";
const char debugGetPWM[] PROGMEM = "PWM%d=%d~"; // return PWM value for digital pin
const char debugLCDX[] PROGMEM = "Sets the LCD cursor to column %s\n";
const char debugLCDY[] PROGMEM = "Sets the LCD cursor to row %s\n";
const char debugLCDC[] PROGMEM = "Clears the LCD display\n";
const char debugLCDP1[] PROGMEM = "Writes the following text to the LCD\n";
const char debugLCDP2[] PROGMEM = ">>  %s  <<\n";
*/
  int pinSetting;
  
  switch (command) {
    case SETDP0:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D0, OUTPUT);
          digitalWrite(D0, pinSetting);
      }
      // Serial.printf("Implement setting D0 to %d\n", pinSetting);
      break;

    case SETDP1:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D1, OUTPUT);
          digitalWrite(D1, pinSetting);
      }
      break;

    case SETDP2:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D2, OUTPUT);
          digitalWrite(D2, pinSetting);
      }
      break;

    case SETDP3:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D3, OUTPUT);
          digitalWrite(D3, pinSetting);
      }
      break;

    case SETDP4:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D4, OUTPUT);
          digitalWrite(D4, pinSetting);
      }
      break;

    case SETDP5:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D5, OUTPUT);
          digitalWrite(D5, pinSetting);
      }
      break;

    case SETDP6:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D6, OUTPUT);
          digitalWrite(D6, pinSetting);
      }
      break;

    case SETDP7:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D7, OUTPUT);
          digitalWrite(D7, pinSetting);
      }
      break;

    case SETDP8:
      pinSetting = pinLevel(commandValue);
      if (pinSetting >= 0) {
        pinMode(D8, OUTPUT);
          digitalWrite(D8, pinSetting);
      }
      break;

    case GETDP0:
      Serial.printf_P(debugGetDP, 0, digitalRead(D0));
      break;

    case GETDP1:
      Serial.printf_P(debugGetDP, 1, digitalRead(D1));
      break;

    case GETDP2:
      Serial.printf_P(debugGetDP, 2, digitalRead(D2));
      break;

    case GETDP3:
      Serial.printf_P(debugGetDP, 3, digitalRead(D3));
      break;

    case GETDP4:
      Serial.printf_P(debugGetDP, 4, digitalRead(D4));
      break;

    case GETDP5:
      Serial.printf_P(debugGetDP, 5, digitalRead(D5));
      break;

    case GETDP6:
      Serial.printf_P(debugGetDP, 6, digitalRead(D6));
      break;

    case GETDP7:
      Serial.printf_P(debugGetDP, 7, digitalRead(D7));
      break;

    case GETDP8:
      Serial.printf_P(debugGetDP, 8, digitalRead(D8));
      break;

    case GETAP0:
      pinMode(A0, INPUT);
      Serial.printf_P(debugGetAP, analogRead(A0));
      break;

    case SETPWM0:
      pinMode(D0, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[0] = pinSetting;
        analogWrite(D0, pwmValue[0]);
      }
      break;

    case SETPWM1:
      pinMode(D1, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[1] = pinSetting;
        analogWrite(D1, pwmValue[1]);
      }
      break;

    case SETPWM2:
      pinMode(D2, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting < 100) && (pinSetting >= 0) ) {
        pwmValue[2] = pinSetting;
        analogWrite(D2, pwmValue[2]);
      }
      break;

    case SETPWM3:
      pinMode(D3, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[3] = pinSetting;
        analogWrite(D3, pwmValue[3]);
      }
      break;

    case SETPWM4:
      pinMode(D4, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[4] = pinSetting;
        analogWrite(D4, pwmValue[4]);
      }
      break;

    case SETPWM5:
      pinMode(D5, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[5] = pinSetting;
        analogWrite(D5, pwmValue[5]);
      }
      break;

    case SETPWM6:
      pinMode(D6, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[6] = pinSetting;
        analogWrite(D6, pwmValue[6]);
      }
      break;

    case SETPWM7:
      pinMode(D7, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[7] = pinSetting;
        analogWrite(D7, pwmValue[7]);
      }
      break;

    case SETPWM8:
      pinMode(D8, OUTPUT);
      pinSetting = atoi(commandValue);
      if ( (pinSetting <= 100) && (pinSetting >= 0) ) {
        pwmValue[8] = pinSetting;
        analogWrite(D8, pwmValue[8]);
      }
      break;

    case LCDSetCurX: // LCD column
      pinSetting = atoi(commandValue);
      if ( (pinSetting >= 0) && (pinSetting < 16) ) {
        lcdCursorColumn = pinSetting;
      }
      break;

    case LCDSetCurY: // LCD row
      pinSetting = atoi(commandValue);
      if ( (pinSetting >= 0) && (pinSetting < 2) ) {
        lcdCursorRow = pinSetting;
      }
      break;

    case LCDClear:
      lcd->clear();
      break;

    case LCDPrint: // LCDprint
      lcd->setCursor(lcdCursorColumn, lcdCursorRow);
      lcd->print(commandValue);
      break;
      
    case GETPWM0: // getPWM0
      Serial.printf(debugGetPWM, 0, pwmValue[0]);
      break;

    case GETPWM1: // getPWM1
      Serial.printf(debugGetPWM, 1, pwmValue[1]);
      break;

    case GETPWM2: // getPWM2
      Serial.printf(debugGetPWM, 2, pwmValue[2]);
      break;

    case GETPWM3: // getPWM3
      Serial.printf(debugGetPWM, 3, pwmValue[3]);
      break;

    case GETPWM4: // getPWM4
      Serial.printf(debugGetPWM, 4, pwmValue[4]);
      break;

    case GETPWM5: // getPWM5
      Serial.printf(debugGetPWM, 5, pwmValue[5]);
      break;

    case GETPWM6: // getPWM6
      Serial.printf(debugGetPWM, 6, pwmValue[6]);
      break;

    case GETPWM7: // getPWM7
      Serial.printf(debugGetPWM, 7, pwmValue[7]);
      break;

    case GETPWM8: // getPWM8
      Serial.printf(debugGetPWM, 8, pwmValue[8]);
      break;

    case LCDSetAddr:
      lcdAddress = atoi(commandValue);
      break;

    case LCDSetRows:
      lcdNumberOfRows = atoi(commandValue);
      break;

    case LCDSetCols:
      lcdNumberOfColumns = atoi(commandValue);
      break;

    case LCDInit:
      lcd = createLcdObject();
      lcd->init();
      lcd->backlight();
      lcd->clear();
      lcd->setCursor(0,0);
      lcd->print("LCD");
      lcd->setCursor(0,1);
      lcd->print("Started");      
      lcdCreated = true;
      break;

    default:
       delay(1);
  }
}

// convert text "HIGH" and "LOW" into integers
int pinLevel(char * commandWord) {
  // some digital pin processing strings
  static const char pinHIGH[] = "HIGH";
  static const char pinhigh[] = "high";
  static const char pinOne[] = "1";
  static const char pinLOW[] = "LOW";
  static const char pinlow[] = "low";
  static const char pinZero[] = "0";

  if (strcmp(commandWord, pinLOW) == 0
      || strcmp(commandWord, pinlow) == 0
      || strcmp(commandWord, pinZero) == 0) {
    // we have a valid set-to-LOW instruction
    return LOW;
  }
  if (strcmp(commandWord, pinHIGH) == 0
      || strcmp(commandWord, pinhigh) == 0
      || strcmp(commandWord, pinOne) == 0) {
    // we have a valid set-to-HIGH instruction
    return HIGH;
  }
  // if we get here, no match, return error value
  return -1;
}

// handle commands
void handleCommand( cmdPointerList theCommand ) {
  int i = 0; // index into the array of pointers to known, candidate commands
  // step through the array
  while ( i < numberOfKnownCommands ) {
    // dereference the candidate command pointer directly from the array
    int sizeOfCandidate = strlen_P(commandList[i]->commandText);
    if (strlen(theCommand.instructionPtr) >= sizeOfCandidate) {
      // compare theCommand to the next one in the array
      if ( strncmp_P(theCommand.instructionPtr,
            commandList[i]->commandText, 
            sizeOfCandidate) == 0 ) {
        // a zero result indicates a match
        // so exit the while loop
        break;
      }
    }
    // arriving on this line means that either
    //  - theCommand was too short for comparison
    //  - or there was not a match
    // increment the index and try again
    i++;
  }
  // does the command match one in the cmdArray?
  if (i < numberOfKnownCommands) {
    // yes it does. Go do what it says.

    // un-comment the next line to send certain debugger messages
    // showCommand(commandList[i]->command, theCommand.valuePtr);

    // comment-out the next line to prevent implementing commands
    doCommand(commandList[i]->command, theCommand.valuePtr);
  } else {
    // no, it does not. Pronounce failure
    // Serial.printf("Not a known command.\n");
  }
}
