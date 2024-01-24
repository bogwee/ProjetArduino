#include<SoftwareSerial.h>

#define TX 11
#define RX 10
SoftwareSerial BC(RX, TX);
int PWM;
char DATA;
// Moteur A
#define IN1 3  //IN1 fait avancer
#define IN2 5  //IN2 fait reculer
// Moteur B
#define IN3 6  //IN3 fait avancer
#define IN4 9  //IN4 fait reculer

//Les moteurs sont asymetriques dons pour avancer le module il faut que le moteur A avance et le moteur B recule

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  BC.begin(9600);
}

// valeur du moteur compris entre 0 (tourne lentement) et 255(tourne rapidement)
  
void loop() {
  if (BC.available()) {
    DATA = BC.read();
    if (DATA == 'F') {
      PWM = BC.parseInt();
      Serial.println(PWM);
      analogWrite(IN1, PWM);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, PWM);
    }
    if (DATA == 'R') {
      analogWrite(IN1, 240);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
    if (DATA == 'L') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 240);
    }
    if (DATA == 'S') {
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
    }
  }
}

