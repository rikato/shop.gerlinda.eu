

const int motor_1 = 3;
const int motor_2 = 5;
int motorSpeed = 255;

void setup() {
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
}

void loop() {
  // set the speed of motor 1:
  analogWrite(motor_1, motorSpeed);
}
