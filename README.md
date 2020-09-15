# Build an 8266 Companion Board
Wire a breadboard to provide many different types of connections for an 8266 ESP-12 module.

Readers who complete the project described in this will have a breadboard similar to the one shown in Figure 1. 

![Companion Board](https://raw.githubusercontent.com/IowaDave/8266-Firmware-for-MakerBit/gh-pages/images/CompanionBoard.png)

[Figure 1: An 8266 Companion Board]

The 8266 is on the module at the bottom of the photo. This one happens to be a Wemos-style (Lolin) ESP-12F development module. The breadboard is called a companion board because it helps the 8266 do more than merely connect to WiFi.

It can connect directly to a wide variety of sensors and actuators, when it is mounted on a companion board like this. An 8266 on a companion board can control many types of projects standing alone, like a small Arduino.

### Make It a Super-Companion

Even better, the companion board can work as a companion to another controller, such as a MakerBit. The other controller can send commands via a serial connection to the 8266 and request data be sent back from it. Call this combination a Super Companion Board

To make the Super Companion work is a two-part process:

<ul>
<li>Part 1: Code on the 8266 receives instructions from the MakerBit, processes the instructions, and transmits any data the MakerBit requests.</li>
<li>Part 2: Code on the MakerBit sends instructions and requests, then receives and processes data the 8266 sends back.</li>
</ul>

This has to be custom code, where each part is designed and tested to work correctly with the other part. Links at the end of the article give access to a set of custom code files designed for the MakerBit and the Companion Board.

### What Can a Companion Board Do For You?

Readers who complete assembly of this project will have a breadboard that can enable "plug 'n play" connections for a wide variety of sensors and actuators. For example:

* installed resistors enable direct connection of LEDs.
* an onboard power converter provides a round barrel connector for a wall wart and an on/off switch.
* the power rails supply 3.3 volts along one side of the board and 5 volts along the other side.
* a logic level shifter enables connection for both 3.3-volt and 5-volt signals.
* an optional voltage divider supplies a 0.9-volt source for use with certain 8266 modules that limit analog input to a maximum of 1 volt.
* I2C connection is conveniently supported for 4-lead Dupont plugs.
* serial connection is similarly supported for a 3-lead Dupont plug.

## Building the Companion Board

### Step 1: Wiring Under the Logic Devices

The companion board in this project uses two logic devices:

* a Wemos-style (Lolin) D1 Mini ESP-12F module
* a four-channel logic level converter

Some of the wiring will be run underneath the logic devices. See Figure 2. Begin by making the following connections:

| Wiring Under the Logic Devices   ||
|From       | Function  |    To     |
|:-----:|:---------:|:---------:|
| 56f   | Serial TX | 49e       |
| 57g   | Serial RX | 50e       |
| 58h   | I2C SCL   | 45e       |
| 59g   | I2C SDA   | 46e       |
| 57e   | A0        | 15e       |
| 58d   | D0        | 18d       |
| 62j   | Ground    | blue rail |
| 63a   | 3.3 volt  | red rail  |

Install the power converter on the top rows of the breadboard. Set the jumpers as shown in Figure 2:

* Left side 3.3 Volts
* Right side 5 Volts

Bring power and ground across to both sides of rows 47 and 48:

* 3.3 Volts to position 47a
* 5 Volts to position 47j
* Ground to positions 48a and 48j

![Figure 2](https://raw.githubusercontent.com/IowaDave/8266-Firmware-for-MakerBit/gh-pages/images/Step1.png)

[Figure 2: Wiring underneath the logic devices]

### Step 2: Install Resistors for LEDs

This step takes inspiration from the MakerBit (and HyperDuino) by Roger Wagner. Make it easy for users to connect LEDs.

LEDs need resistors plus wiring to both ground and a digital pin. The Companion Board puts all that in place, as illustrated in Figure 3.

The 8266 puts 3.3 volts out on its digital pins. Typical small LEDs can perform well with 220-Ohm resistors. I have used 330-Ohm resistors successfully also; the light is a little less bright.

Note: the different colors of LEDs take different amounts of electrical current. This means that some colors may be brighter than others on a Companion Board that uses just one type of resistor.

Position the resistors on the rows for the digital pins, so they bridge across the center divider of the breadboard. There are nine of these rows, located at 3-point intervals: 18, 21, 24, 27, 30, 33, 36, 39 and 42.

This arrangement moderates the voltage only on the right-hand side of the row. It leaves the left-hand side capable of the digital pin's full 3.3-volt potential.

The *greater-numbered* row next to each digital-pin row provides a connection to ground. Bring a wire from the blue rail across to column "j" on each of these rows: 19, 22, 25, 28, 31, 34, 37, 40 and 43.

Users can plug an LED directly into the Board. The red oval in Figure 3 simulates an LED connected to digital pin D0. The anode (longer leg) is in row 18. The cathode (shorter leg, flat spot on the rim) goes into row 19, where it connects to ground.

##### Logic Level Shifter

Install the Logic Level Shifter at this time. Examine it carefully. The two sides are different: one for higher voltage (HV), the other for lower voltage (LV). 

Place the LV side to the left, closest to the 3.3-Volt power rail, with its pins in column d, rows 45 through 50. The pins for the HV side go into column f on the same rows.

### The Code Files

Here are the links to the code files:

* For the 8266: [https://github.com/IowaDave/8266-Firmware-for-MakerBit](https://github.com/IowaDave/8266-Firmware-for-MakerBit)
* For the MakerBit: [https://github.com/IowaDave/pxt-makerbit-esp12](https://github.com/IowaDave/pxt-makerbit-esp12)

The README files in those locations explain how to put the code onto your devices.