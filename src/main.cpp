#include <Arduino.h>

#define BLUE_LED 4
#define RED_LED 13

enum class ledState : bool
{
  Off = LOW,
  On = HIGH
};

class Led
{
public:
  constexpr Led(uint8_t pin, uint32_t interval) : mPin(pin), mInterval(interval) {}

private:
  uint8_t mPin;
  uint32_t mInterval;
};

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
