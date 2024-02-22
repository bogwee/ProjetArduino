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

// Tube
#define T1 6
#define T2 9

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
      analogWrite(IN1, 255);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 255);
    }
    if (DATA == 'R') {
      analogWrite(IN1, 255);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
    if (DATA == 'L') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 255);
    }
    if (DATA == 'S') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
    if (DATA == 'D') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 255);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
    if (DATA == 'G') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 255);
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
    if (DATA == 'K') {
      analogWrite(T1, 255);
      analogWrite(T2, 255);
    }
    if (DATA == 'E') {
      analogWrite(T1, 0);
      analogWrite(T2, 0);
    }
  }
}
