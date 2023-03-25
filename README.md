
## Pneumatic-Cylinder-activation-with-accelerometer-readings
#### Description:
A mechanical switch when pressed activates a pneumatic double acting cylinder by programming a microcontroller to send a low current signal to a motor driver, which then transfers the signal to a higher-current signal that can switch the state of a solenoid valve, allowing air to flow from an air compressor into the pneumatic cylinder, while also recording the output of an accelerometer mounted on the cylinder.

_Program language_: C++

#### Embedded devices setup:
LED's are defined that signal a certain colour for different phases of the pneumatic activation. GREEN when the system is ready for the switch to be pressed and YELLOW when the switch is activated and the pneumatic cylinder is in operation. | The switches's analog pin is defined. | i2c communication protocol is followed to have the Arduino UNO retrieve the accelerometer's readings.

#### Work flow:
Blink GREEN LED, indicating that it is waiting for the switch to be pressed. If switch is pressed than GREEN LED stays on,  
