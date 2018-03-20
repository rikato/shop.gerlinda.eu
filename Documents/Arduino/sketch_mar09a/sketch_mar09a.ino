void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

int speed = 0;

void loop() {
   digitalWrite(4, HIGH);
   analogWrite(5, speed);
   analogWrite(6, speed);
   digitalWrite(7, HIGH);
}
