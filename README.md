# AnalogSignalHandler
A simple yet powerful Analog Signal handler for Arduino.
Could also be adapter to other micro controllers.

# Features
Full signal manipulation: scaling, offset, gain.

Moving Average Noise Filter.

Separated into a header & class file to keep your code clean.

Minimal lines requried in your main code.

Fast. No internal delays, no millis, no hacks.

Fully documented.

# Understanding Analog Signals and ADCs
This code uses two pressure transmitters, PT1 and PT2 as an example. However any other analog signals can be handled by this same code.

Arduinos ADC is 0-5v and 10 bit, normalized 0-1023. 
The general consensus is that this resolution is low, I challange that becasue; a typical microPLC such as the Siemens LOGO! also uses 10 bits, normalized 0-1000. Of course on a hardware level, the LOGO! would outperform any arduino board.

The imporant takeaway is that using an Arduino we can read 1/1000ths of a volt, i.e. 3.670V. 
However it's not good to rely on that fine of a resolution. If you don't 




PT = Pressure Transmitter. You can use any type of analog signal.
// Scaling is rather misleading term. The simple explanation is the maximum real value of your sensor.
// Example, a sensor which returns a maximum value of 150, the analog input would read max volts.
// In this example it is a pressure sensor rated for 150 psi, and the board will see max volts at 150psi.
// Scaling is the mx in y = mx+b
// Offset is how you can shift (offset) an analog signal up or down. Another term is "zeroing" the sensor. 
// Example, when creating a diaphram isolated sensor, the isolation fluid will extert some pressure (unless you have expensive tools)
// You can use the offset value to account for the isolation fluid pressure.
// Gain is a simple value used to increase or decease a the final output. It's used when you need to calibrate a sensor range.
