#ifndef encoder_h
#define encoder_h

#include "Arduino.h"
class Encoder {

  public:
    void clockPin(int pin);
    void dataPin(int pin);
    void loop();
    double getValue();
    void setValue(double newValue);
    void setMin(double minValue);
    void setMax(double maxValue);
    void setStep(double stepValue);
    void onValueChanged(void callback());
    void onPulse(void callback(int direction));
    
    
  protected:
    void virtual onPulse(int direction); 
    void virtual onValueChanged(double value);
    void (*onValueChangedCallback)();
    void (*onPulseCallback)(int direction);
       
  private:
    int clock;
    int data;
    unsigned char stateChannelClock;
    unsigned char stateChannelData;
    unsigned char prevStateChannelClock = 0;
    double value;
    double min=0.0;
    double max=20.0;
    double step=1.0;
};

#endif
