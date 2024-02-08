#include "Servo.h"

Servo servo;

void setup() {
  servo.attach(4);
  // put your setup code here, to run once:

}

void loop() {
  servo.write(0);
  delay(2000);
  servo.write(75);
  delay(2000);
  // put your main code here, to run repeatedly:

}
