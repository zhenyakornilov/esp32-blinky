#include <Arduino.h>

#define BLUE_LED 4
#define RED_LED 13

void setup()
{
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void flash(int pin, int times, int onMs, int offMs)
{
  for (int i = 0; i < times; i++)
  {
    digitalWrite(pin, HIGH);
    delay(onMs);
    digitalWrite(pin, LOW);
    delay(offMs);
  }
}

void loop()
{
  flash(BLUE_LED, 2, 100, 100);
  flash(RED_LED, 2, 100, 100);
  delay(300);
}
