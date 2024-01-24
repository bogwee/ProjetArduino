#define MG1 4
#define MD1 5
#define MG2 9
#define MD2 3

void setup() {
  Serial.begin(9600);
  pinMode(MG1, INPUT);
  pinMode(MD1, INPUT);
  pinMode(MG2, INPUT);
  pinMode(MD2, INPUT);
  analogWrite(MG1, 0);
  analogWrite(MD1, 0);
  analogWrite(MG2, 0);
  analogWrite(MD2, 0);
}

void loop() {
  analogWrite(MG1, 240);
  analogWrite(MD1, 0);
  analogWrite(MG2, 0);
  analogWrite(MD2, 240);
}
