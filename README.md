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

Arduinos ADC is 0-5v and 10 bit, normalized 0-1023.
The general consensus is that this resolution is low. I challange that becasue; a typical microPLC such as the Siemens LOGO! also uses 10 bits, normalized 0-1000. Of course on a hardware level, the LOGO! would outperform any arduino board.

Thus both an Arduino (AT MEGA2560) and Siemens LOGO! can read 1/1000ths of a volt, i.e. 3.670V.

However it's not good practice to make use of that fine of a resolution. This is because of noise and many other aspects that affect the reliability of the analog signal.

Additionally, your chosen sensor will have it's performance charactaristics; accuracy, non-linearity, hystersis and others.

The ADC performance should compliment the sensors capability. A high end ADC (from a high end PLC) will not give you a more precise signal if you use a low performance sensor or if you use the wrong sensor range. Example:

High End 0-5,000psi sensor with +/-0.25% accuracy = +/-12.5psi.
Low end 0-100psi sensor with +/-1% accuracy = +/- 1psi.

Wether using a high end PLC or Arduino ATMega2560, the signal accuracy will be the same.

Short answer is that we have 0-5V and an internal value between 0-1023.

## Signal Conversion

The example code uses two pressure transmitters, PT1 and PT2. However any other analog signals can be handled by this same code.

To make the signal readable/usable, we must apply Scaling, Offset and Gain.
Note that these are defined variables in the code, they are not the same as the internal paramaters of the microcontroller.

### Scaling

Scaling is rather misleading term. The simple explanation is the maximum real value of your sensor.
Example, a pressure sensor rated from 0-150psi or VFD analog output for motor current, max 24Amps.
To scale either of those analog signals, input their max value in Scaling.
Scaling is the mx in y = mx+b.

### Offset 

Offset is how you can shift (offset) an analog signal up or down. Another term is "zeroing" the sensor.
Example, when creating a diaphram isolated sensor, the isolation fluid will extert some pressure in the sensor (unless you have expensive tools). You can compensate for this by including a negative offset to account for the diaphragm fluid pressure.
Offset is the +/-b in y=mx+b.

### Gain

Gain is a simple value used to increase or decease a the final output. It's typically used when you need to calibrate a sensor.

### Final Value

After applying all three values, you are left with a final usable value of your sensor. Call this (and only this) value for the remainder of your your code.
In PLC terms, this is the Engineering Units. 

### The Code
main.ino shows how to implement this library into your code.
AnalogSignalHandler.c

More Reading:

Atmel datasheet, section 28 for in depth ADC information.
https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf

Sample general purpose pressure sensor performance data.
https://www.sick.com/ca/en/catalog/products/process-sensors/pressure-sensors/pbt/pbt-rp160sn1ss0uma0z/p/p309021?tab=detail


