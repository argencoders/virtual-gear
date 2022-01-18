#include "encoder.h"
#include "state.h"
#include "divider.h"
#include "button.h"
#include "alesadora.h"

class DataSheet {
  public:
    int clockPin = 2;
    int channelClock = 9;
    int channelData = 10;
    int pinIn = clockPin;
    int pinOut = 12;
    int buttonPin = 6;
    double divisor = 4.0;
} ds;

Button boton1;
Alesadora alesadora;
State state1;
Encoder encoder1;

void conectarDivisorAlReloj() {
  alesadora.setInput(state1.getOutput());
}


void cambiarPulsoPendiente(int delta) {
     alesadora.pulsosPendientes += delta*100;
}

void establecerDivisor() {
  int value = encoder1.getValue();
  Serial.println(value);
  alesadora.setDivisor(1.0 / value);
}

void resetearDivisor() {
  encoder1.setValue(ds.divisor);
}

void invertirSenal() {
   Serial.println("Invierte senal");
  state1.setInverted(!state1.getInverted());
}

void setup() {
  Serial.begin(9600);
  state1.inputPin(ds.pinIn);
  state1.onOutputChanged(conectarDivisorAlReloj);

  boton1.setPin(ds.buttonPin);
  boton1.onShortClick(invertirSenal);
  boton1.onLongClick(resetearDivisor);

  encoder1.clockPin(ds.channelClock);
  encoder1.dataPin(ds.channelData);
  encoder1.setMin(1.0);
  encoder1.setMax(10.0);
  encoder1.setStep(2.0);
  //encoder1.onValueChanged(establecerDivisor);
  encoder1.onPulse(cambiarPulsoPendiente);
  resetearDivisor();

  alesadora.outputPin(ds.pinOut);
  alesadora.setDivisor(1.0 / ds.divisor);
  attachInterrupt(digitalPinToInterrupt(ds.clockPin), tick, CHANGE);
}

void loop() {
  encoder1.loop();
  boton1.loop();
}

void tick() {
  state1.loop();
}
