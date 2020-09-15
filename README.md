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

Some of the wiring will be run underneath the logic devices. See Figure 2. Begin by making the connections listed in Table 1:

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

[Table 1]

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

There is room to route the wires for A0 and D0 down in the center divider, underneath the resistors. It keeps things tidy.

This arrangement moderates the voltage only on the right-hand side of the row. It leaves the left-hand side capable of the digital pin's full 3.3-volt potential.

The *greater-numbered* row next to each digital-pin row provides a connection to ground. Bring a wire from the blue rail across to column "j" on each of these rows: 19, 22, 25, 28, 31, 34, 37, 40 and 43.

Users can plug an LED directly into the Board. The red oval in Figure 3 simulates an LED connected to digital pin D0. The anode (longer leg) is in row 18. The cathode (shorter leg, flat spot on the rim) goes into row 19, where it connects to ground.

##### Logic Level Shifter

Install the Logic Level Shifter at this time. Examine it carefully. The two sides are different: one for higher voltage (HV), the other for lower voltage (LV). 

Place the LV side to the left, closest to the 3.3-Volt power rail, with its pins in column d, rows 45 through 50. The pins for the HV side go into column f on the same rows.

![Figure 3](https://raw.githubusercontent.com/IowaDave/8266-Firmware-for-MakerBit/gh-pages/images/Step2.png)

[Figure 3: Resistors and Logic Level Shifter]

### Step 3: the Under-Over-and-Around Wires

The project needs a wire from each of the digital pins on the 8266 to its respective row on the Companion Board. This is where builders get to start using their imagination. Arrange the wiring so as to please the eye. 

Figure 4 illlustrates routing some of the wires under the 8266 then up over the Logic Level Shifter.

The design here takes advantage of the fact that the I2C SDC and SDA pins have a dual purpose. They operate also as digital pins D1 and D2, respectively. This means we can take their signal from the rows where they already connect to the Logic Level Shifter.

It is difficult to see in the photo, but there are actually 2 wires coming off the upper-left corner of the Shifter. They lie atop one another and wrap around before passing up over the resistors.

Install wiring for the connections listed in Table 2:

| Under-Over-and-Around Wires   ||
|From       | Function  |    To     |
|:-----:|:---------:|:---------:|
| 44c   | D1        | 21d       |
| 45c   | D2        | 24d       |
| 60g   | D3        | 27d       |
| 61g   | D4        | 30d       |
| 57e   | A0        | 15e       |
| 58d   | D0        | 18d       |
| 62j   | Ground    | blue rail |
| 63a   | 3.3 volt  | red rail  |

[Table 2]

![Figure 4](https://raw.githubusercontent.com/IowaDave/8266-Firmware-for-MakerBit/gh-pages/images/Step3.png)

[Figure 4: Over-Under-and-Around Wires]

### Step 4: Wire the Final Four Digital Pins

There is not enough room underneath the 8266 module to fit all of the wires the Companion Board needs. The final four take off from outside the module, as shown in Figure 5.

Align the pins of the 8266 module to sit on columns b and i, spanning rows 56 through 63. Press it firmly down into place. Nudge those wires underneath it until they lie flat. You want the black "feet" of the module to rest on the surface of the Companion Board.

Install wiring for the connections listed in Table 4:

| Final Four Digital Pins   ||
|From       | Function  |    To     |
|:-----:|:---------:|:---------:|
| 59a   | D5        | 33d       |
| 60a   | D6        | 36d       |
| 61a   | D7        | 39d       |
| 62a   | D8        | 42d       |

[Table 4]

Figure 5 illustrates a blue LED connected to digital pin D0. Try to visualize how the Companion Board provides that connection. Review the previous Figures to help you get the pathway clearly in your mind.

![Figure 5](https://raw.githubusercontent.com/IowaDave/8266-Firmware-for-MakerBit/gh-pages/images/Step4.png)

[Figure 5: Final Four Wires]

### Step 5: Optional Voltage Divider

The Companion Board might actually be complete at this point, if it will an 8266 module that tolerates 3.3 volts on its analog (A0) input pin. For example, some models of the Wemos-style module illustrated in this project claim that capability. 

However, many modules cannot withstand more than 1 volt of analog input. The Companion Board can be upgraded with a Voltage Divider to accommodate this limitation. 

Figure 1, shown above and repeated for convenience below, shows a way to use row 14 for the purpose. A 4.7K-Ohm resistor brings 5-volt power across to position 14j. This is carried across the central divider to position 14e on the left-hand side of the row. A second, 1K-Ohm resistor connects position 14a to the blue (ground) rail. 

Ohm's Law predicts a potential of about 0.87 volts on positions 14b, 14c, and 14d, as they are located between the two resistors. Measure your actual voltage to make sure.

You can plug a resistive-type of sensor across the left-hand sides of rows 14 and 15. For example, place a simple photocell at positions 14c and 15c.

It is outside the scope of this article to discuss how the 8266 transforms a voltage found on pin A0 into a number your code can interpret. A web search will reveal many tutorials for taking analog readings with a microcontroller. Experimental learning is a good teacher, and we leave it as a go-the-extra-mile challenge for the reader.

![Companion Board](https://raw.githubusercontent.com/IowaDave/8266-Firmware-for-MakerBit/gh-pages/images/CompanionBoard.png)

[Figure 1: Companion Board With Voltage Divider]

### Step 6: Connect to the Companion Board

The Companion Board is designed to make many types of connections easy. Just plug into the board.

* An LED can be plugged into pairs of positions on the right-hand side of the board. For example, digital pin D0 would activate an LED on positions 18h-19h, as shown in Figure 1, above.

* A servo or other device that needs the full 3.3-volt potential of a digital pin could connect to the left-hand side of a digital pin row, for example, to position 33b for activation by pin D5.

* Pins D1 and D2 (coresponding to I2C SCL and SDA, respectively) have an extra feature. The Logic Level Shifter can transform their signal to 5 volts on the right-hand sides of rows 44 and 45.
  * This capability makes it possible to connect with devices such as LCD displays that require a 5-volt signal.
  * Figure 1 illustrates this feature with a green highlight.

* Finally, the serial pins Tx and Rx (for Transmit and Receive) are available on rows 49 and 50.
  * 3.3-volt level is on the left-hand side, in columns b and c.
  * 5-volt level is enabled by the Logic Level Shifter on the right-hand sides of those rows, in columns g through j.

The Companion Board becomes Super when it connects the serial pins to their corresponding positions on a MakerBit. The 3.3-volt side of things is safest for both devices. Make the connections listed in Table 5:

| Super Hookup   ||
|Companion Board       | Function  |    MakerBit     |
|:-----:|:---------:|:---------:|
| 48c   | Ground | Gnd, or any black pin |
| 49c   | Board Tx, MakerBit Rx        | P1       |
| 50c   | Board Rx, MakerBit Tx        | P0       |

[Table 5]

With suitable instructions installed in their firmware, the MakerBit and the 8266 Companion can  work together on projects that neither one of them could execute standing alone. A set of code files is provided below by way of example.

### The Code Files

Here are the links to the code files:

* For the 8266: [https://github.com/IowaDave/8266-Firmware-for-MakerBit](https://github.com/IowaDave/8266-Firmware-for-MakerBit)
* For the MakerBit: [https://github.com/IowaDave/pxt-makerbit-esp12](https://github.com/IowaDave/pxt-makerbit-esp12)

The README files in those locations explain how to put the code onto your devices.