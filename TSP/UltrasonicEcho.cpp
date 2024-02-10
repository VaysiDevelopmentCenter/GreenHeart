#include <wiringPi.h>
#include <stdio.h>
#include <fstream>

// Define GPIO pins for trigger, echo, and LED
#define TRIG_PIN  7
#define ECHO_PIN 8
#define LED_PIN   17

// Function to measure distance in centimeters
int measureDistance() {
    // ... (same as before)
}

int main() {
    // Setup GPIO pins
    wiringPiSetupGpio();
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    // Open log file in append mode
    std::ofstream logFile("/home/pi/sensor_data.txt", std::ios_base::app);

    while (1) {
        int distance = measureDistance();

        // Log distance to file
        logFile << distance << std::endl;

        printf("Distance: %d cm\n", distance);

        // Turn LED on/off based on distance threshold
        if (distance < 20) {
            digitalWrite(LED_PIN, HIGH);
            printf("LED ON (distance below 20 cm)\n");
        } else if (distance > 25) {
            digitalWrite(LED_PIN, LOW);
            printf("LED OFF (distance above 25 cm)\n");
        }

        // Add your desired actions for other distance ranges here

        delay(1000); // Delay between measurements (adjust as needed)
    }

    // Close log file
    logFile.close();

    return 0;
}
