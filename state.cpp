#include "state.h"

void State::setInput(int newInputValue) {
  if (inputValue != newInputValue) {
    inputValue = newInputValue;
    onInputChanged(inputValue);
    if (onInputChangedCallback) {
      onInputChangedCallback();
    }
  }
}

void State::onInputChanged(int value) {
  //parece no ser el mejor lugar para hacer esto
  //setOutput(inverted ? !value : value);
  setOutput(value);
}

int State::getInput() {
  return inputValue;
}

void State::setOutput(int newOutputValue) {
  newOutputValue = inverted ? !newOutputValue : newOutputValue;

  if (outputValue != newOutputValue) {
    outputValue = newOutputValue;
    if (pin_out > -1) {
      digitalWrite(pin_out, outputValue);
    }
    onOutputChanged(outputValue);
    if (onOutputChangedCallback) {
      onOutputChangedCallback();
    }
  }
}

void State::onOutputChanged(int value) {

}

void State::setInverted(bool value) {
  this->inverted = value;
}
bool State::getInverted() {
  return this->inverted;
}


int State::getOutput() {
  return outputValue;
}

void State::inputPin(int pin) {
  pin_in = pin;
  pinMode(pin_in, INPUT);
}

void State::outputPin(int pin) {
  pin_out = pin;
  pinMode(pin_out, OUTPUT);
}

void State::onInputChanged(void callback()) {
  this->onInputChangedCallback = callback;
}

void State::onOutputChanged(void callback()) {
  this->onOutputChangedCallback = callback;
}


void State::loop() {
  if (pin_in > -1) {
    setInput(digitalRead(pin_in));
  }
}
