#include "button.h"

void Button::setPin(int pin) {
  this->pin = pin;
  pinMode(this->pin, INPUT_PULLUP);
  this->state = HIGH;
}

void Button::onShortClick(void callback()){
   this->onShortClickCallback = callback;
}

void Button::onLongClick(void callback()){
   this->onLongClickCallback = callback;
}

void Button::onShortClick(){}
void Button::onLongClick(){}

void Button::loop() {
  int prevState = state;
  state = digitalRead(pin);
  if (prevState == HIGH && state == LOW) {
    buttonDownMs = millis();
  }
  else if (prevState == LOW && state == HIGH) {
    if (millis() - buttonDownMs < 20) {
      // ignore this for debounce
    }
    else if (millis() - buttonDownMs < 250) {
      // short click
      this->onShortClick();
      if (onShortClickCallback) {
        this->onShortClickCallback();
      }
    }
    else  {
      // long click
      this->onLongClick();
      if (onLongClickCallback) {
        this->onLongClickCallback();
      }
    }
  }

}
