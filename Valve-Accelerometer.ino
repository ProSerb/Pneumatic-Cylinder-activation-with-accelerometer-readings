/******************************************************************
   MREN241AccelerometerLIS3DH (v1.8)

   Original by H. Fernando, 24/04/2022
   Modified by B. Surgenor, 02/05/2022
 
   Basic demo for accelerometer readings with LIS3DH (digital)
   Plots 500 points, button press will repeat
   Sends signal to relay to open/close valve

   Need to install the library Adafruit_LIS3DH
   Red: 3 or 5V, Black: Ground, Blue (SCL): A5, Yellow (SDA): A4

******************************************************************/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

Adafruit_LIS3DH lis = Adafruit_LIS3DH();

int GRN = 5;
int YLW = 6;           //used for relay
int BUTTON = 8;
int ii;

void setup(void) {

  pinMode(GRN,OUTPUT);
  pinMode(YLW,OUTPUT);
  pinMode (BUTTON, INPUT);
  
  Serial.begin(500000);
///  Serial.begin(38400);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("LIS3DH test!");

  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");

  lis.setRange(LIS3DH_RANGE_16_G);   // 2, 4, 8 or 16 G!
  lis.setDataRate(LIS3DH_DATARATE_400_HZ);
}

void loop() {
   digitalWrite(YLW, LOW);
   do {
    toggleLED(GRN);    // wait for button press to continue
  }while(digitalRead(BUTTON)== LOW);
  
  turnOnLED(GRN);

  unsigned long current_time = micros();

  for(ii = 0; ii<500; ii++){
    /* Get a new sensor event, acceleration in m/s^2 */
    sensors_event_t event;
    
    //sample at 400 Hz
    while((micros()-current_time) < 2500);
    current_time = micros();
    
    lis.getEvent(&event);
    if (ii > 50 && ii < 250){
       digitalWrite(YLW, HIGH);  // YLW is solenoid
    }
    else{
       digitalWrite(YLW, LOW);
    }   
    Serial.print(float(micros()/1000.0));
    Serial.print(',');
    Serial.println(event.acceleration.y);
  }
}

// ************** function calls ******************

//Turn on a single LED, and all others off
void turnOnLED(int COLOUR){
  digitalWrite(GRN, LOW);
  digitalWrite(YLW, LOW);
  digitalWrite(COLOUR, HIGH);
}

//Toggle an LED on and off
void toggleLED(int colour){
  digitalWrite(colour, HIGH);
  delay(250);
  digitalWrite(colour, LOW);
  delay(250); 
}
