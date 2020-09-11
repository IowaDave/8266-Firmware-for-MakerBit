

#include "command.h"

//define this variable here for use elsewhere
int numberOfKnownCommands;

// initialize the associations, one struct for each command
const conSTruct setDP0 PROGMEM = { SETDP0, "DP0=" };
const conSTruct setDP1 PROGMEM = { SETDP1, "DP1=" };
const conSTruct setDP2 PROGMEM = { SETDP2, "DP2=" };
const conSTruct setDP3 PROGMEM = { SETDP3, "DP3=" };
const conSTruct setDP4 PROGMEM = { SETDP4, "DP4=" };
const conSTruct setDP5 PROGMEM = { SETDP5, "DP5=" };
const conSTruct setDP6 PROGMEM = { SETDP6, "DP6=" };
const conSTruct setDP7 PROGMEM = { SETDP7, "DP7=" };
const conSTruct setDP8 PROGMEM = { SETDP8, "DP8=" };
const conSTruct getDP0 PROGMEM = { GETDP0, "DP0?" };
const conSTruct getDP1 PROGMEM = { GETDP1, "DP1?" };
const conSTruct getDP2 PROGMEM = { GETDP2, "DP2?" };
const conSTruct getDP3 PROGMEM = { GETDP3, "DP3?" };
const conSTruct getDP4 PROGMEM = { GETDP4, "DP4?" };
const conSTruct getDP5 PROGMEM = { GETDP5, "DP5?" };
const conSTruct getDP6 PROGMEM = { GETDP6, "DP6?" };
const conSTruct getDP7 PROGMEM = { GETDP7, "DP7?" };
const conSTruct getDP8 PROGMEM = { GETDP8, "DP8?" };
const conSTruct getAP0 PROGMEM = { GETAP0, "AP0?" };
const conSTruct setPWM0 PROGMEM = { SETPWM0, "PWM0=" };
const conSTruct setPWM1 PROGMEM = { SETPWM1, "PWM1=" };
const conSTruct setPWM2 PROGMEM = { SETPWM2, "PWM2=" };
const conSTruct setPWM3 PROGMEM = { SETPWM3, "PWM3=" };
const conSTruct setPWM4 PROGMEM = { SETPWM4, "PWM4=" };
const conSTruct setPWM5 PROGMEM = { SETPWM5, "PWM5=" };
const conSTruct setPWM6 PROGMEM = { SETPWM6, "PWM6=" };
const conSTruct setPWM7 PROGMEM = { SETPWM7, "PWM7=" };
const conSTruct setPWM8 PROGMEM = { SETPWM8, "PWM8=" };
const conSTruct getPWM0 PROGMEM = { GETPWM0, "PWM0?" };
const conSTruct getPWM1 PROGMEM = { GETPWM1, "PWM1?" };
const conSTruct getPWM2 PROGMEM = { GETPWM2, "PWM2?" };
const conSTruct getPWM3 PROGMEM = { GETPWM3, "PWM3?" };
const conSTruct getPWM4 PROGMEM = { GETPWM4, "PWM4?" };
const conSTruct getPWM5 PROGMEM = { GETPWM5, "PWM5?" };
const conSTruct getPWM6 PROGMEM = { GETPWM6, "PWM6?" };
const conSTruct getPWM7 PROGMEM = { GETPWM7, "PWM7?" };
const conSTruct getPWM8 PROGMEM = { GETPWM8, "PWM8?" };
const conSTruct lcdSetCurX PROGMEM = { LCDSetCurX, "LCDX=" };
const conSTruct lcdSetCurY PROGMEM = { LCDSetCurY, "LCDY=" };
const conSTruct lcdSetAddr PROGMEM = { LCDSetAddr, "LCDA=" };
const conSTruct lcdSetRows PROGMEM = { LCDSetRows, "LCDR=" };
const conSTruct lcdSetCols PROGMEM = { LCDSetCols, "LCDC=" };
const conSTruct lcdClear PROGMEM = { LCDClear, "LCDCLR" };
const conSTruct lcdPrint PROGMEM = { LCDPrint, "LCDP=" };
const conSTruct lcdInit PROGMEM = { LCDInit, "LCDI" };
// This one marks the end of the list. Used to count the commands.
const conSTruct sVoid PROGMEM = {VOID, ""};

// create a list of the associations
// as an array of pointers to the structs
// notice that both the pointers and the array itself
// are qualified as const
const conSTruct * const commandList[] PROGMEM = { &setDP0,
  &setDP1,
  &setDP2,
  &setDP3,
  &setDP4,
  &setDP5,
  &setDP6,
  &setDP7,
  &setDP8,
  &getDP0,
  &getDP1,
  &getDP2,
  &getDP3,
  &getDP4,
  &getDP5,
  &getDP6,
  &getDP7,
  &getDP8,
  &getAP0,
  &setPWM0,
  &setPWM1,
  &setPWM2,
  &setPWM3,
  &setPWM4,
  &setPWM5,
  &setPWM6,
  &setPWM7,
  &setPWM8,
  &getPWM0,  
  &getPWM1,  
  &getPWM2,  
  &getPWM3,  
  &getPWM4,  
  &getPWM5,  
  &getPWM6,  
  &getPWM7,  
  &getPWM8, 
  &lcdSetCurX,
  &lcdSetCurY,
  &lcdSetAddr,
  &lcdSetRows,
  &lcdSetCols,
  &lcdClear,
  &lcdPrint,
  &lcdInit, 
// and don't forget this last one   
  &sVoid };

  // read through the list of commands once
  // to count the number of commands
int countTheCommands() {
  int i = 0;
  while (commandList[i]->command != VOID) {
    i++;
  } 
  return i; // this returns the count; the last good index into the array is one less than this number
}
