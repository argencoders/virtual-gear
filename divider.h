#ifndef divider_h
#define divider_h

#include "Arduino.h"
#include "state.h"

class Divider : public State {
  public:
    void setDivisor(double value);
  private:
    double divisor;
    double c;
  protected:
    void virtual onInputChanged(int value);
};



#endif
