#include<SoftwareSerial.h>

#define TX 11
#define RX 107
SoftwareSerial RC(RX, TX);
int PWM;
char DATA;
// Moteur A
#define IN1 3
#define IN2 5
// Moteur B
#define IN3 6
#define IN4 9

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  RC.begin(9600);
}

// valeur du moteur compris entre 0 (tourne lentement) et 255(tourne rapidement)


void loop() {
  if (RC.available()) {
    DATA = RC.read();
    if (DATA == 'F') {
      PWM = RC.parseInt();
      Serial.println(PWM);
      analogWrite(IN1, PWM);
      analogWrite(IN2, 0);
      analogWrite(IN3, PWM);
      analogWrite(IN4, 0);
    }
  }
}

