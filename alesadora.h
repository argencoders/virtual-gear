#ifndef alesadora_h
#define alesadora_h

#include "Arduino.h"
#include "state.h"

class Alesadora : public State {
  public:
    void setDivisor(double value);
    int pulsosPendientes;
  private:
    double divisor;
    double c;
    bool hayEspacioParaPulsoPendiente;
  protected:
    void virtual onInputChanged(int value);
};



#endif
