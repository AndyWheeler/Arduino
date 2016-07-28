
const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 3;
long interval = 18000;

void setup() {
  for(int x = 3;x<8;x++){
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if(led == 7){
      
    }
  }
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    for(int x=3;x<8;x++){
      digitalWrite(x, LOW);
    }
    led = 3;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
