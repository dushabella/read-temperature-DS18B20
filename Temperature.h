/*

Temperature.h - a library for measuring temperature on Arduino with DS18B20 sensor.

Author: dushabella
e-mail: izabela.dusza@stechnika.pl

This library is based on OneWire and DS18B20 libraries.

display(int pin, int period) - simply measures and displays a temperature;
measure(int pin) - measures and returns a temperature for each period of time;

*/

#ifndef Temperature_h
#define Temperature_h

#include "Arduino.h"
#include "OneWire.h"
#include "DS18B20.h"

class Temperature
{
  public:
    Temperature(int pin);
    void setup_serial();
    void display(int pin, int period);
    float measure(int pin);
  private:
    int _pin;
};

#endif