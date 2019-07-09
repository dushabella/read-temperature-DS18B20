/*
 * przykładowe zastosowanie biblioteki Temperature.h do pomiaru temperatury czujnikiem DS18B20
 */
#include <Temperature.h>

int PIN_temp = 6;
int measure_period = 3000;

Temperature temp(PIN_temp);

void setup() {
}

void loop() {
  /*
   *zmierz temperaturę (wywołanie zwraca float'a)
   *temp.measure(port_podpiecia)
   */
  temp.measure(PIN_temp);

  /*
   *wyświetl temp. co jakiś okres czasu
   *temp.display(port_podpiecia, czas_pomiedzy_pomiarami_w_ms);
   */
  temp.display(PIN_temp, measure_period);
}
