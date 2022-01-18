#include "encoder.h"

void Encoder::clockPin(int pin) {
  this->clock = pin;
  pinMode(this->clock, INPUT);
}

void Encoder::dataPin(int pin) {
  this->data = pin;
  pinMode(this->data, INPUT);
}

void Encoder::onValueChanged(void callback()) {
  this->onValueChangedCallback = callback;
}

void Encoder::onPulse(void callback(int direction)) {
  this->onPulseCallback = callback;
}


void Encoder::loop() {
  stateChannelClock = digitalRead(clock);
  stateChannelData = digitalRead(data);
  if (stateChannelClock != prevStateChannelClock)
  {
    if (stateChannelClock == stateChannelData)
    {
      onPulse(-1);
      if (onPulseCallback) {
        onPulseCallback(-1);
      }
      setValue(value - step);
    }
    else
    {
      onPulse(1);
      if (onPulseCallback) {
        onPulseCallback(1);
      }
      setValue(value + step);
    }
  }
  prevStateChannelClock = stateChannelClock;
}

double Encoder::getValue() {
  return this->value;
}

void Encoder::setValue(double newValue) {
  if (newValue < min) newValue = min;
  if (newValue > max) newValue = max;

  if (value != newValue) {
    this->value = newValue;
    onValueChanged(newValue);
    if (onValueChangedCallback) {
      onValueChangedCallback();
    }
  }
}

void Encoder::onPulse(int direction) {

}

void Encoder::onValueChanged(double value) {

}

void  Encoder::setMin(double minValue) {
  this->min = minValue;
}
void  Encoder::setMax(double maxValue) {
  this->max = maxValue;
}
void  Encoder::setStep(double stepValue) {
  this->step = stepValue;
}




//void Encoder::onChanged(int value) {
//Serial.println(value > 0 ? "++" : "--");
//}
