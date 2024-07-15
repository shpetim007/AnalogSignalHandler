#include <SPI.h>
#include <LiquidCrystal.h>
#include "AnalogSignalHandler.h"

// Sensor variables
// This is for two sensors. If you have more analog inputs, you'll need to new set of variables
// Always setup defaults
float PT1scale = 150;
float PT1offset = 0;
float PT1gain = 1;
float PT2scale = 150;
float PT2offset = 0;
float PT2gain = 1;

// Moving average filter variables.
// 10 is a good default.
const int SAMPLE_SIZE = 10;  

// Buffers to store last N samples for analog readings.
// Add more for each analog singal
float PT1_samples[SAMPLE_SIZE];
float PT2_samples[SAMPLE_SIZE];

int sampleIndex = 0;  // Current index for inserting the next sample

// Initialize total sums for averaging
// Add more for each analog signal
float PT1_sum = 0;
float PT2_sum = 0;

// Creates the signal handler class for each Analog Signal
// Class Object(constructor paramaters)
// Add more for each analog signal
AnalogSignalHandler PT1Handler(PT1scale, PT1offset, PT1gain, SAMPLE_SIZE);
AnalogSignalHandler PT2Handler(PT2scale, PT2offset, PT2gain, SAMPLE_SIZE);

void setup() {

// your code here

}

void loop() {
  // your code here


// Analog Read of the raw signal (volts -> bits), change to your pinout or add more as needed
    int PT1raw = analogRead(A0);
    int PT2raw = analogRead(A1);

// calls the PT#Handler class for each analog signal
    PT1Handler.update(PT1raw);
    PT2Handler.update(PT2raw);

// This is the final result, the actual value you want. Call this variable in the rest of your code as needed.
// It
    float PT1 = PT1Handler.getAverage();
    float PT2 = PT2Handler.getAverage();
    float dP = PT1 - PT2;

  // Print readings to serial bus
  Serial.print("PT1: "); Serial.println(PT1);
  Serial.print("PT2: "); Serial.println(PT2);

}
