
const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 1;
int prevSwitchState = 1;
int led = 3;
long interval = 1000;
boolean inverted = false;

void setup() {
  for(int x = 3;x<8;x++){
    pinMode(x, OUTPUT);
    pinMode(x+6, OUTPUT);
    digitalWrite(x, HIGH);
  }
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    Serial.print("led: ");
    Serial.print(led);
    Serial.print(" Inverted?: ");
    Serial.print(inverted);
    Serial.print("\n");
    if(!inverted && led <= 7){
      digitalWrite(led, LOW);
      digitalWrite(led+6, HIGH);
      if(led < 7){
        led++;
      }
    }
    if(inverted && led >= 3){    
      digitalWrite(led, HIGH);
      digitalWrite(led+6, LOW);
      if(led > 3){
        led--;
      }
    }
    /*if(led == 7 && !inverted || led ==3 && inverted){
      for(int x = 3;x<8;x++){
        digitalWrite(x, HIGH);
        digitalWrite(x+6, HIGH);
      }
    }*/
  }
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState && switchState == 1){
    previousTime = currentTime;
    inverted = !inverted;
  }
  prevSwitchState = switchState;
}

