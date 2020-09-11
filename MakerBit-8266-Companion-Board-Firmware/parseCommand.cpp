

#include "parseCommand.h"


// not really global, but too lazy to change names yet
// additional global declarations
char * globalErrorString0 = "ERROR0";
char * globalErrorString1 = "ERROR1";
char * globalErrorString2 = "ERROR2";
char * globalErrorString3 = "ERROR3";
char * globalErrorString4 = "ERROR4";
char * globalAtString = "AT"; // used only when the command is "AT", exactly


cmdPointerList parseCommand(char * cmdString) {
  // initialize a working copy of the struct
  cmdPointerList result;
  result.tokenPtr = NULL;
  result.valuePtr = NULL;
  // Error if it is more than 100 chars long
  if (strlen(cmdString) > 100) {
    // point to error
    result.instructionPtr = globalErrorString0;
    return result;
  }
  // Error if it does not begin with "AT"
  if (strncmp(cmdString, globalAtString, 2) != 0) {
    result.instructionPtr = globalErrorString1;
    return result;
  }
  // is it "AT", only? Check based on length == 2
  if (strlen(cmdString) == 2) {
    // in this case, return the "AT" string
    result.instructionPtr = globalAtString;
    return result;
  }
  // Error if the next character is not '+'
  if (cmdString[2] != '+') {
    result.instructionPtr = globalErrorString2;
    return result;
  }
  // point to the command name
  result.instructionPtr = cmdString + 3;
  // look for a token
  // deal first with the '=' token
  // this code might not be optimally brief, yet, but it will work
  result.tokenPtr = strchr(cmdString, '=');
  // if the result is not NULL then proceed to handle '='
  if (result.tokenPtr != NULL) {
    // '=' found.
    // Error if nothing follows it
    if ( strlen(result.tokenPtr+1) < 1) {
      // change the instructionPtr to error
      result.instructionPtr = globalErrorString4;
      // change the tokenPtr back to NULL
      result.tokenPtr = NULL;
    } else {
      // we have some chars following the '=' token
      // accept whatever that may be as the value of the command
      result.valuePtr = result.tokenPtr + 1;
    }
    // return the resulting pointer list
    return result;
  } // end of handling '='
  // deal with the '?' token only if no '=' token found
  // notice that if '?' also is not found, then parsing is complete
  result.tokenPtr = strchr(cmdString, '?');
  // return with NULL tokenPtr if '?' not found
  if (result.tokenPtr == NULL) return result;
  // check for an instruction string between '+' and '?'
  if (result.tokenPtr - result.instructionPtr > 0) {

    // one or more instruction characters exist
    // meaning that the '?' token is in good order, therefore
    // return with token pointed to and valuePtr still set to NULL

  } else {
    // we do not have a valid instruction
    // change the instructionPtr to error
    result.instructionPtr = globalErrorString3;
    // change the tokenPtr back to NULL
    result.tokenPtr = NULL;
  }  
  return result;
}
