/****************************************************
 * command.h   Header for "command" module          *
 *                                                  *
 * Known commands are defined in this module        *
 * and implemented in the handleCommand module      *
 * Add a command definition by the following steps: *
 *   1. In this file, add it to the commandEnum     *
 *   2. In the command.cpp file:                           *
 *      a. add a conSTruct for it                   *
 *      b. add the conStruct to the commandList     *
 *   3. In the handleCommand.cpp file:              *
 *       implement in the switch statement          *
 *       within the doCommand procedure             *
 ****************************************************/

// include pgmspace library for PROGMEM
#include <avr/pgmspace.h>  // the correct lilbrary for Arduino 1.8.13

// declare (only once!) structs and enum - to appear globally

#ifndef COMMAND_H
#define COMMAND_H

  typedef char KnownCommandBuffer[12]; // note: 32-bit aligned buffer, 11-char max command

  // Associate command names with integers
  // by means of an enum
  enum commandEnum {
    SETDP0, 
    SETDP1, 
    SETDP2, 
    SETDP3, 
    SETDP4, 
    SETDP5, 
    SETDP6, 
    SETDP7, 
    SETDP8, 
    GETDP0, 
    GETDP1, 
    GETDP2, 
    GETDP3, 
    GETDP4, 
    GETDP5, 
    GETDP6, 
    GETDP7, 
    GETDP8,
    GETAP0,
    SETPWM0, 
    SETPWM1, 
    SETPWM2, 
    SETPWM3, 
    SETPWM4, 
    SETPWM5, 
    SETPWM6, 
    SETPWM7, 
    SETPWM8,
    GETPWM0, 
    GETPWM1, 
    GETPWM2, 
    GETPWM3, 
    GETPWM4, 
    GETPWM5, 
    GETPWM6, 
    GETPWM7, 
    GETPWM8,
    LCDSetCurX,
    LCDSetCurY,
    LCDSetAddr,
    LCDSetRows,
    LCDSetCols,
    LCDClear,
    LCDPrint,
    LCDInit, 
    VOID
  };

  // associate command numbers with text
  // by means of a struct
  // note: the struct members are qualified as const
  struct conSTruct {
    const commandEnum command;
    const KnownCommandBuffer commandText;
  }; 

  // struct for command pointers
  struct cmdPointerList {
    char * instructionPtr; // everything following "AT+", or "ERROR", or "AT"
    char * tokenPtr; // points to "?" or "=", otherwise NULL
    char * valuePtr; // points to everything following a "=", otherwise NULL
  };

#endif

// function prototypes defined in this module and made global here
int countTheCommands();

// data containers defined in this module and made global here
extern const conSTruct * const commandList[];
extern int numberOfKnownCommands;
