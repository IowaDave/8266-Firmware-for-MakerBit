# 8266-Firmware-for-MakerBit
8266 mounted on a Companion Board interacts with a MakerBit via Serial commands.

The folder contains the firmware as an Arduino IDE project. Open your copy in Arduino, compile and upload to an 8266. My project used a Wemos-style ESP-12F development module. It might work for other boards also?

### The Companion Board

A tutorial for building a companion board is available at the following url: [https://iowadave.github.io/8266-Firmware-for-MakerBit/](https://iowadave.github.io/8266-Firmware-for-MakerBit/).


### MakeCode

The MakerBit sends commands to the companion board and receives requested data from the companion board using serial communications. The tutorial mentioned above explains how to connect the two devices.

MakeCode is a popular programming environment for the BBC micro:bit, a microcontroller that supplies the "brains" for a MakerBit. There are two ways to use MakeCode with this 8266 firmware.

1. The Hard Way: You may write your own MakeCode instructions in JavaScript to interact send commands to the 8266. Commands are sent as short strings of text. The strings are listed in the firmware code files. This article will explain where to find them, a little farther on.

2. The Easy Way: Use pre-written instructions designed as custom Blocks, taking advantage of MakeCode's graphical programming features. 

A set of custom Blocks designed for the MakeCode language is provided as an Extension package at the following url: [https://github.com/IowaDave/pxt-makerbit-esp12](https://github.com/IowaDave/pxt-makerbit-esp12). Copy the link, then paste it into the Extensions search box in the MakeCode editor. The editor will offer you the choice to import the extension package into your MakeCode project.

Documentation for the Blocks is available at the following URL: https://iowadave.github.io/pxt-makerbit-esp12/  

**TODO: Write that documentation!**

### A Tour of the Code Files

The firmware code is organized in modules. Each module handles part of the job. This tour aims to help readers to locate parts of the code that interest them.

Readers of all ability levels are welcome. Understanding this article will vary depending on the reader's prior acquired of programming in the C and C++ languages, and in the use of the Arduino IDE software.

The author has tried to make it interesting and informative for everyone. Think of it as a sightseeing tour of the code, not a college course in coding.

#### The MakerBit-8266-Companion-Board-Firmware Folder

This folder contains files for all of the modules.

* The main code file is *MakerBit-8266-Companion-Board-Firmware.ino*. 
* Each module comprises a pair of files having the same name, but different suffixes. For example, the *command* module consists of: 
  * command.h
  * command.cpp

#### MakerBit-8266-Companion-Board-Firmware.ino

This is the main code file. The Arduino IDE requires that it have the same name as the folder. If you choose to rename your copy of the sketch, be sure to change the name for both the folder and this file.

The code imports the other modules and defines one global variable. Like all Arduino programs, it implements two functions:

* setup() performs a bit of one-time initialization, 
* loop() repeats "forever":
  * get a command from the serial port
  * process the command

#### 'command' module

This module defines the commands known to the firmware. It also provides a function for counting the number of known commands.

* command.h provides the *commandEnum* to be disussed below

* command.cpp defines several data containers:
  * a number of *conSTruct* data structures, one for each known command;
  * an array named *commandList* containing pointers to the data structures for the commands.

Note that the container definitions include the *PROGMEM* modifier. It means the structures and the data they contain will reside on the 8266 in its abundant flash memory, rather than in its somewhat limited RAM. That is a good thing to do with text and data that will never change during execution of the code. Save RAM for values that do need to change.

#### How To Add A New Command to the List

The process involves steps to take in three, different files. First (and second), place identifying information for the command into both files of the 'command' module. 
* Add an entry in the *commandEnum* of command.h
* Define *conSTruct* data structure for it.
* Add a pointer to the conStruct into the *commandList* array. IMPORTANT: be sure to leave the *&sVoid* entry as the final one in the array. A look at the *countCommands()* function will explain why.

The third step is to implement the new command. Implementation is handled in another module, described next.

#### 'd_handleCommand' module

The strange-looking name of this module was chosen for alphabetical listing reasons. The author begs the reader to humor his decison.

* d_handleCommand.h sets things up for the module and makes some of its contents available to the rest of the program.
* d_handleCommand.cpp implements the core functionality of the firmware. 
  * the *handleCommand()* function determines which known command has been received. It:
    *  examines the incoming text string
    *  if recognized, it matches the string to its corresponding enum value
  * the *doCommand()* function executes the block of instructions corresponding to the enum value

**Implementing a new command** is done by adding a *case* statement for the command's enum value into the *switch* statement in the *doCommand()* function.

That pretty much covers everything about adding a command to the firmware.

---

The rest of this document is merely descriptive regarding the remaining modules in the folder.

#### 'getCommand' module

This module establishes a buffer for text characters coming in via serial. 

The *getCommand()* function copies incoming characters from the serial port into a buffer named *incomingCommand*. It then calls the *parseCommand()* function (in another module) to process the buffer.


#### 'parseCommand' module

The *parseCommand()* function returns a set of pointers to various parts of the *incomingCommand* buffer. The pointers are contained in a struct named of the *cmdPointerList* type.

Using a struct made of pointers in this way avoids manipulating the text characters. The approach seeks to reduce processing time and to limit risks for side effects on memory.

#### 'lcd' module

Here is an example of a module designed for a particular external device library, in this case, a Liquid Crystal Display accessible by the I2C protocol.

This module addresses a knotty programming challenge: how to create a C++ object in one function, then make it available for use in another, different function.

It looks difficult to do, at first, because an object that is *defined* inside a function has no existence outside the closure (that is, the '{}' braces) of that function.

A solution is to create the object with the *new* statement in C++, which returns a pointer to the object. The function then, in turn, returns the pointer to its caller, allowing the pointer to be assigned to a global variable.

In fact, this approach might be the only way to make an object available outside of the function that created it.

The pointer variable has access to all of the object's properties and methods. The only difference is that the arrow ('->') operator is used in place of the dot ('.') operator.

#### 'showCommand' module

This one exists as an aid to debugging. It is not used in normal execution of the firmware. However, the author found it helpful on occasion to see the results of parsing a commmand. One can add *case* statements as needed. The module is left here for archeological interest, and for convenience should the need arise again in future.






