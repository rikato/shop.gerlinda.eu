int startPin = 2; 
int endPin = 11;  

int letterDisplay = 10;
int numberDisplay = 11;

int a = 3;
int b = 2;
int c = 7;
int d = 8;
int e = 9;
int f = 4;
int g = 5;
int dp = 6;

int timer = 100;          
void setup() {
  for (int thisPin = startPin; thisPin <= endPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {  
  display(9);
}

void display(int number){
  
  //Start writing letter "L"
  digitalWrite(letterDisplay, LOW);
  digitalWrite(numberDisplay, HIGH);

  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);

  delay(1);

  digitalWrite(numberDisplay, LOW);
  digitalWrite(letterDisplay, HIGH);

  digitalWrite(f, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
  //End writing of letter "L"

  switch(number){
    case 1:
      digitalWrite(f, HIGH);
      digitalWrite(e, HIGH);
      delay(1);
      digitalWrite(f, LOW);
      digitalWrite(e, LOW);
      break;
    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      delay(1);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(g, LOW);
      digitalWrite(e, LOW);
      digitalWrite(d, LOW);
      break;
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      delay(1);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(g, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      break;
    case 4:
      digitalWrite(f, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      delay(1);
      digitalWrite(f, LOW);
      digitalWrite(b, LOW);
      digitalWrite(g, LOW);
      digitalWrite(c, LOW);
      break;
    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      delay(1);
      digitalWrite(a, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      break;
    case 6:
      digitalWrite(a, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      delay(1);
      digitalWrite(a, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      break;
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      delay(1);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      break;
    case 8:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(1);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 9:
      digitalWrite(a, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      delay(1);
      digitalWrite(a, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      break;
  } 
}
