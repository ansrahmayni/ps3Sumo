#include <Ps3Controller.h>
#include "kontrol.h"

void notify() {
  handlePS3();
}

void onConnect() {
  Serial.println("Tersambunggg");
}

void setup() {
  Serial.begin(115200);

  motor();

  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("01:02:03:04:05:06");
}

void loop() {
}