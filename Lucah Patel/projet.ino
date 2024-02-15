#include<SoftwareSerial.h>
#include<Servo.h>

#define TX 1
#define RX 0

SoftwareSerial BC(RX, TX);

Servo servo1;
Servo servo2;

int PWM;
int ANG;
char DATA;

// Moteur A
#define IN1 11
#define IN2 10
// Moteur B
#define IN3 5
#define IN4 3

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  servo1.attach(2);
  servo2.attach(4);
  BC.begin(9600);
}

void loop() {
  if (BC.available()) {
    DATA = BC.read();
    if (DATA == 'F') {
      PWM = BC.parseInt();
      analogWrite(IN1, PWM);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, PWM);
    }
    if (DATA == 'R') {
      analogWrite(IN1, 200);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
    if (DATA == 'L') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 200);
    }
    if (DATA == 'S') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
    if (DATA == 'D') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 200);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
    if (DATA == 'G') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 200);
      analogWrite(IN4, 0);
    }
    if (DATA == 'B') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 255);
      analogWrite(IN3, 255);
      analogWrite(IN4, 0);
    }
    if (DATA == 'Z') {
      ANG = BC.parseInt();
      servo1.write(ANG);
    }
    if (DATA == 'X') {
      ANG = BC.parseInt();
      servo2.write(ANG);
    }
  }
}
