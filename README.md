# Build an 8266 Companion Board
Wire a breadboard to provide many different types of connections for an 8266 ESP-12 module.

Readers who complete the project described in this will have a breadboard similar to the one shown in Figure 1. 

![Companion Board](https://raw.githubusercontent.com/IowaDave/8266-Firmware-for-MakerBit/gh-pages/images/CompanionBoard.png)

The 8266 is on the module at the bottom of the photo. This one happens to be a Wemos-style (Lolin) ESP-12F development module. The breadboard is called a companion board because it helps the 8266 do more than merely connect to WiFi.

It can connect directly to a wide variety of sensors and actuators, when it is mounted on a companion board like this. An 8266 on a companion board can control many types of projects standing alone, like a small Arduino.

Even better, the companion board can work as a companion to another controller, such as a MakerBit. The other controller can send commands via a serial connection to the 8266 and request data be sent back from it. Call this combination a Super Companion Board

To make the Super Companion work is a two-part process:

<ul>
<li>Part 1: Code on the 8266 receives instructions from the MakerBit, processes the instructions, and transmits any data the MakerBit requests.</li>
<li>Part 2: Code on the MakerBit sends instructions and requests, then receives and processes data the 8266 sends back.</li>
</ul>

This has to be custom code, where each part is designed and tested to work correctly with the other part. Links at the end of the article give access to a set of custom code files designed for the MakerBit and the Companion Board.

Readers who complete assembly of this project will have a breadboard that can enable "plug 'n play" connections for a wide variety of sensors and actuators. For example:

* installed resistors enable direct connection of LEDs.
* an onboard power converter provides a round barrel connector for a wall wart and an on/off switch.
* the power rails supply 3.3 volts along one side of the board and 5 volts along the other side.
* a logic level shifter enables connection for both 3.3-volt and 5-volt signals.
* an optional voltage divider supplies a 0.9-volt source for use with certain 8266 modules that limit analog input to a maximum of 1 volt.
* I2C connection is conveniently supported for 4-lead Dupont plugs.
* serial connection is similarly supported for a 3-lead Dupont plug.

Here are the links to the code files:

* For the 8266: [https://github.com/IowaDave/8266-Firmware-for-MakerBit](https://github.com/IowaDave/8266-Firmware-for-MakerBit)
* For the MakerBit: [https://github.com/IowaDave/pxt-makerbit-esp12](https://github.com/IowaDave/pxt-makerbit-esp12)

The README files in those locations explain how to put the code onto your devices.