void setup() {
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
}
