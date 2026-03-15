#include <Arduino.h>

#define BLUE_LED_PIN 4
#define RED_LED_PIN 13

enum class ledState : bool
{
  Off = LOW,
  On = HIGH
};

class Led
{
public:
  constexpr Led(uint8_t pin, uint32_t interval, ledState state) : mPin(pin), mInterval(interval), mState(state), mLastChangeTime(0) {}

  void init()
  {
    pinMode(mPin, OUTPUT);
    digitalWrite(mPin, static_cast<uint8_t>(mState));
  }

  void setState(ledState state)
  {
    mState = state;
    digitalWrite(mPin, static_cast<uint8_t>(mState));
  }

  void update()
  {
    uint32_t now = millis();
    if (now - mLastChangeTime >= mInterval)
    {
      mState = (mState == ledState::Off) ? ledState::On : ledState::Off;
      digitalWrite(mPin, static_cast<uint8_t>(mState));
      mLastChangeTime = now;
    }
  }

private:
  uint8_t mPin;
  uint32_t mInterval;
  uint32_t mLastChangeTime;
  ledState mState;
};

Led blueLed(BLUE_LED_PIN, 200, ledState::Off);
Led redLed(RED_LED_PIN, 200, ledState::On);

void setup()
{
  blueLed.init();
  redLed.init();
}

// void flash(int pin, int times, int onMs, int offMs)
// {
//   for (int i = 0; i < times; i++)
//   {
//     digitalWrite(pin, HIGH);
//     delay(onMs);
//     digitalWrite(pin, LOW);
//     delay(offMs);
//   }
// }

void loop()
{
  blueLed.update();
  redLed.update();
  // flash(BLUE_LED_PIN, 2, 100, 100);
  // flash(RED_LED_PIN, 2, 100, 100);
  // delay(300);
}
