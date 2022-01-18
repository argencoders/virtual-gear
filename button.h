#ifndef button_h
#define button_h

#include "Arduino.h"
#include "state.h"

class Button  {
  public:
    void setPin(int pin);
    void loop();
    void onShortClick(void callback()); 
    void onLongClick(void callback()); 
  private:
    int pin;
    int state;
    unsigned long buttonDownMs;
    void (*onShortClickCallback)();
    void (*onLongClickCallback)();
  protected:
    void virtual onShortClick();
    void virtual onLongClick();
    
};



#endif
