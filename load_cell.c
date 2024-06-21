/*
    Project name : ESP8266 Load Cell
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-load-cell
*/

#include <HX711.h>

// Define the pins connected to the HX711 module
const int DOUT_PIN = D5; // Data pin
const int SCK_PIN = D6;  // Clock pin

// Initialize the HX711 library instance
HX711 scale;

void setup() {
  Serial.begin(9600); // Initialize serial communication

  // Initialize the HX711 module with the specified pins
  scale.begin(DOUT_PIN, SCK_PIN);

  // Set the scale gain to 128, adjust as necessary
  scale.set_gain(128);
}

void loop() {
  // Read the raw ADC value from the load cell
  long rawValue = scale.read();

  // Print the raw ADC value to the Serial Monitor
  Serial.print("Raw ADC Value: ");
  Serial.println(rawValue);

  // Calculate the weight based on calibration factors
  // Adjust the calibration_factor according to your load cell and setup
  float calibration_factor = 5050; // Adjust this calibration factor
  float weight = rawValue / calibration_factor;

  // Print the weight (in kg) to the Serial Monitor
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" kg");

  delay(1000); // Add a short delay before the next reading
}
