// pin toekenning
int LDR = 0;
int lightArray[20];
int sum = 0;
int avgLight = 0;


const int motor_1 = 3;
const int motor_2 = 5;
int motorSpeed = 255;

//int i = 0;
// seriele poort initialiseren
// bepalen van input en output
void setup()
{
 pinMode(LDR, INPUT);
 pinMode(motor_1, OUTPUT);
 pinMode(motor_2, OUTPUT);
 
 Serial.begin(9600);
  
 for(int i = 0; i < 20; i++){
  int volt = analogRead(LDR);
  lightArray[i] = volt;
  Serial.println(lightArray[i]);
  if(i == 19){
    for(int j = 0; j < 20; j++){
      sum += lightArray[j];
    }
    avgLight = sum / 19;
    Serial.println("avg:");
    Serial.println(avgLight);
   }
   delay(500);
 }


 
}
// uitlezen van de analoge input verbonden aan de LDR
// druk de waarde af op de seriele poort.
// om het leesbaar te houden eventueel de delay aanpassen
void loop()
{
  analogWrite(motor_1, motorSpeed);
  int volt = analogRead(LDR);
//  if(volt < avgLight){
//    analogWrite(motor_1, 0);
//  }else{
//    analogWrite(motor_1, motorSpeed);
//  }


}
