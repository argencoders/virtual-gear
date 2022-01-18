#include "alesadora.h"

void Alesadora::setDivisor(double divisor) {
  this->divisor = divisor;
  this->c = 0;
}

void Alesadora::onInputChanged(int value) {
  if (value) {
    c += divisor;
    if (c >= 1) {
      if (pulsosPendientes < 0) {
        pulsosPendientes++;
      } else {
        setOutput(HIGH);
      }
      hayEspacioParaPulsoPendiente = true;
      c -= 1;
    } else {
      if (hayEspacioParaPulsoPendiente && pulsosPendientes > 0) {
        setOutput(HIGH);
        pulsosPendientes--;
      } else {
        //setOutput(LOW);
      }
      hayEspacioParaPulsoPendiente = false;
    }
  } else {
    setOutput(LOW);
  }
}
