#ifndef AnalogSignalHandler_h
#define AnalogSignalHandler_h

class AnalogSignalHandler {

public:
  // Constructor to initialize the signal handler and all variables it needs
  AnalogSignalHandler(float scale, float offset, float gain, int sampleSize);

  // Function to update the signal handler with a new raw value
  void update(int rawValue);

  // Function to get the average of the stored samples
  float getAverage();

private:
  float scale_;
  float offset_;
  float gain_;
  //# of samples for averaging noise analog value
  int sampleSize_;  
  // float pointer array magic to store the signal samples
  float* samples_;
  // Index for tracking the current position in the sample array
  int sampleIndex_;
  // Running sum of samples used for calculating the average
  float sum_;
};

#endif  // AnalogSignalHandler_h
