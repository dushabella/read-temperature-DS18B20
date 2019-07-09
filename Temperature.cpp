#include "Temperature.h"

// constructor
Temperature::Temperature(int pin){
	pinMode(pin, OUTPUT);	
	_pin = pin;
}

void Temperature::setup_serial(){
	while(!Serial);
	Serial.begin(9600);
}

float Temperature::measure(int pin){
	// init libraries
	OneWire onewire(pin);
	DS18B20 sensors(&onewire);

	Temperature::setup_serial();

	// read serial number of the connected sensor
	byte address[8];
	onewire.reset_search();
	while(onewire.search(address))
	{
		if (address[0] != 0x28)
			continue;
		if (OneWire::crc8(address, 7) != address[7]){
			Serial.println(F("Bledny adres, sprawdz polaczenia"));
			break;
		}
	}
	
	E(sensors.begin());
	E(sensors.request(address));
	E(sensors.readTemperature(address));

	if (sensors.available()){
		float temperature = sensors.readTemperature(address);
		TE(temperature);
		return temperature;
	}
	else{
		Serial.println("measure: sensory niedostepne!");
		delay(5000);
	}

}

void Temperature::display(int pin, int period){
	float temp;
	temp = Temperature::measure(pin);

	Serial.print(temp);
	Serial.println(F(" 'C"));

	delay(period);
}