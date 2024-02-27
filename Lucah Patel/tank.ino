#include<SoftwareSerial.h>
#include<Servo.h>

//Bleutooth
#define TX 1
#define RX 0

SoftwareSerial BC(RX, TX);

//Servomoteurs
Servo servo1;
Servo servo2;

//Variable
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
  pinMode(T1, INPUT);
  pinMode(T2, INPUT);
  servo1.attach(2);
  servo2.attach(4);
  servo1.write(65);
  servo2.write(60);
  BC.begin(9600);
}

void loop() {
  if (BC.available()) {
    DATA = BC.read();
    switch(DATA) {
      case 'F':                    //Forward
        analogWrite(IN1, 0);
        analogWrite(IN2, 255);
        analogWrite(IN3, 255);
        analogWrite(IN4, 0);
        break;
        
      case 'R':                    //Right
        analogWrite(IN1, 0);
        analogWrite(IN2, 255);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);
        break;
        
      case 'L':                    //Left
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 255);
        analogWrite(IN4, 0);
        break;
        
      case 'S':                     //Stop
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);
        break;
        
      case 'D':                    //Reverse Left
        analogWrite(IN1, 255);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);
        break;
        
      case 'G':                    //Reverse Right
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 255);
        break;
        
      case 'B':                    //Backward
        analogWrite(IN1, 255);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 255);
        break;
        
      case 'Z':                    //Z axis rotation
        ANG = BC.parseInt();
        servo1.write(ANG);
        break;
        
      case 'X':                    //X axis rotation
        ANG = BC.parseInt();
        servo2.write(ANG);
        break;
        
      case 'K':                    //Kill, shoot
        analogWrite(T1, 255);
        analogWrite(T2, 255);
        break;
        
      case 'E':                    //End stop shooting
        analogWrite(T1, 0);
        analogWrite(T2, 0);
        break;
  
      default :
        break;
        
    }
  }
}
