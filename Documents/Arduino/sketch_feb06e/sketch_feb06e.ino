int timer = 1000;
int startPin = 2;
int endPin = 7;

void setup() {
  for (int pin = startPin; pin <= endPin; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = startPin; pin <= endPin; pin++) {
    digitalWrite(pin, HIGH);

  }
}
