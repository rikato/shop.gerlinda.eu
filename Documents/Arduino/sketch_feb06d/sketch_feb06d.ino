
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {


             for (int i = 0; i < 5; i++){
                        digitalWrite(11, HIGH);   
  delay(100);                       
  digitalWrite(11, LOW);    
  delay(100);
              }
}

