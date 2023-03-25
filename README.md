
## Pneumatic-Cylinder-activation-with-accelerometer-readings
#### Description:
A mechanical switch when pressed activates a pneumatic double acting cylinder by programming a microcontroller to send a low current signal to a motor driver, which then transfers the signal to a higher-current signal that can switch the state of a solenoid valve, allowing air to flow from an air compressor into the pneumatic cylinder, linearly actuating the piston rod, while also recording the output of an accelerometer (Adafruit LIS3DH) mounted on the piston rod.

_Program language_: C++

#### Embedded devices setup:
LED's are defined that signal a certain colour for different phases of the pneumatic activation. GREEN when the system is ready for the switch to be pressed and YELLOW when the switch is activated and the pneumatic cylinder is in operation. | The switches's analog pin is defined. | i2c communication protocol is followed to have the Arduino UNO retrieve the accelerometer's readings.

#### Work flow:
Blink GREEN LED, indicating that it is waiting for the switch to be pressed. If switch is pressed than GREEN LED stays on, and the accelerometer is set to send an acceleration reading every 2.5 microseconds (400Hz sampling) for 500 iterations (amounts to 1.25 seconds). During that time the YLW led if set ON indicating that the pneumatic cylinder is being pressurized and linearly actuating a piston rod. Once the 500 iterations ends, the same procedure follows starting with the switch being pressed or not. If the switch is continued to be pressed after the 500 iterations it will commence the 500 iterations again, if not then the GREEN LED will be blinking, indicating that it waiting for the switch to be pressed.
