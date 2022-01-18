#include "divider.h"

void Divider::setDivisor(double divisor) {
  this->divisor = divisor;
  this->c = 0;
}

void Divider::onInputChanged(int value) {
  if (value) {
    c += divisor;
    if (c >= 1) {
      setOutput(HIGH);
      c -= 1;
    } else {
      setOutput(LOW);
    }
  } else {
    setOutput(LOW);
  }
}
