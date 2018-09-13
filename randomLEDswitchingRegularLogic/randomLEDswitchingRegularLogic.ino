long OffTime = 3000;
long previousMillis = 0;

int ledPin[] = {2,3,4,5,6,7,8,9};

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int j; j <8; j++) {
    pinMode(ledPin[j], OUTPUT);
    digitalWrite(ledPin[j],LOW);
  }
  digitalWrite(ledPin[0], HIGH);
}

int i = 0;
int previousState = 0;
void loop() {
  // put your main code here, to run repeatedly:
  long currentMillis = millis();
  int seed = random(0,8);
  
  if(seed != previousState){
      digitalWrite(ledPin[seed],LOW);
    while (currentMillis - previousMillis >= OffTime) {
      Serial.println(seed);
      digitalWrite(ledPin[seed], HIGH);
      previousMillis = currentMillis;
      previousState = seed;
    }
  } 
}
