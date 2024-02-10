#include <wiringPi.h>
#include <stdio.h>

// Define GPIO pins for trigger and echo
#define TRIG_PIN  7
#define ECHO_PIN 8

// Function to measure distance in centimeters
int measureDistance() {
    // Send 10us pulse on trigger pin
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure echo pulse duration
    long startTime = micros();
    while (digitalRead(ECHO_PIN) == LOW);
    long endTime = micros();
    long pulseDuration = endTime - startTime;

    // Calculate distance in centimeters
    float distance = pulseDuration * 0.034 / 2; // Speed of sound is 340 m/s

    return (int)distance;
}

int main() {
    // Setup GPIO pins
    wiringPiSetupGpio();
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    while (1) {
        int distance = measureDistance();
        printf("Distance: %d cm\n", distance);

        // Add your desired actions based on measured distance here

        delay(1000); // Delay between measurements (adjust as needed)
    }

    return 0;
}
