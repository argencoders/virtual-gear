#ifndef state_h
#define state_h

#include "Arduino.h"

class State {
  public:
    void inputPin(int pin);
    void outputPin(int pin);
    void setInput(int value);
    int getOutput();
    void loop();
    void setInverted(bool value);
    bool getInverted();
    void onInputChanged(void callback());
    void onOutputChanged(void callback());

  protected:
    int getInput();
    void setOutput(int newOutputValue);
    void virtual onInputChanged(int value);
    void virtual onOutputChanged(int value);


  private:
    int pin_in = -1;
    int pin_out = -1;
    int inputValue = LOW;
    int outputValue = LOW;
    bool inverted = false;
    void (*onInputChangedCallback)();
    void (*onOutputChangedCallback)();
};

#endif
