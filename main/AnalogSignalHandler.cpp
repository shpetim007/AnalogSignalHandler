#include "AnalogSignalHandler.h"

// Constructor for AnalogSignalHandler class
AnalogSignalHandler::AnalogSignalHandler(float scale, float offset, float gain, int sampleSize)
  : scale_(scale), offset_(offset), gain_(gain), sampleSize_(sampleSize) {

  // Allocate memory for the sample array using new operator
  samples_ = new float[sampleSize_];

  // Initialize all elements in the sample array to 0
  for (int i = 0; i < sampleSize_; i++) {
    samples_[i] = 0;
  }

  // Initialize sample index to 0 (tracks current position in circular buffer)
  sampleIndex_ = 0;

  // Initialize sum to 0 (used to calculate average)
  sum_ = 0;
}

// Function to update the signal handler with a new raw analog value
void AnalogSignalHandler::update(int rawValue) {
  // Remove the oldest sample value from the sum
  sum_ -= samples_[sampleIndex_];

  // Calculate the scaled, offset, and gained value from the raw value
  samples_[sampleIndex_] = (((float)rawValue / 1023.0) * scale_ + offset_) * gain_;

  // Add the new sample value to the sum
  sum_ += samples_[sampleIndex_];

  // Update sample index for circular buffer (wraps around when reaching sampleSize)
  sampleIndex_ = (sampleIndex_ + 1) % sampleSize_;
}

// Function to get the average of the stored samples
float AnalogSignalHandler::getAverage() {
  // Return the sum of samples divided by the sample size (average)
  return sum_ / sampleSize_;
}
