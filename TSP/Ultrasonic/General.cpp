// main.cpp
#include "Sensor.h"

Sensor sensor(ULTRASONIC, A0); // create a sensor object with ultrasonic type and pin A0

void setup() {
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  sensor.read(); // read the sensor value
  Serial.println(sensor.getValue()); // print the sensor value
  delay(1000); // wait for a second
  static unsigned long lastSwitch = 0; // keep track of the last time the sensor type was switched
  if (millis() - lastSwitch > 5000) { // if 5 seconds have passed
    sensor.switchType(sensor.type == ULTRASONIC ? OPTICAL : ULTRASONIC); // switch the sensor type
    lastSwitch = millis(); // update the last switch time
  }
}

