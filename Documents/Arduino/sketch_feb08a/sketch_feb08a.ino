int startPin = 2;
int endPin = 8;
long randNumber;


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  // put your setup code here, to run once:
  for (int pin = startPin; pin <= endPin; pin++){
    pinMode(pin, OUTPUT);
  }
}

void loop() {
    randNumber = random(2, 7);
    Serial.println(randNumber - 1);

    if(randNumber == 2){
      digitalWrite(5, HIGH);
    }
    if(randNumber == 3){
      digitalWrite(2, HIGH);
      digitalWrite(8, HIGH);
    }
    if(randNumber == 4){
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
    }
    if(randNumber == 5){
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(8, HIGH);
    }
    if(randNumber == 6){
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(8, HIGH);
    }
    if(randNumber == 7){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    }

    delay(1000);
    
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
}
