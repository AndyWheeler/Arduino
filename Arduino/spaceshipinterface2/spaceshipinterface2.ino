int switchState = 0;
int priorSwitchState = 0;
int mode = 0;

void setup(){
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  switchState = digitalRead(2);
  priorSwitchState = switchState;
}

void loop(){
  switchState = digitalRead(2);
  if (priorSwitchState == HIGH && switchState == LOW){
    //button has been released; toggle mode
    mode++;
    mode  = mode%2;
  }
  priorSwitchState = switchState;
  //display based on mode
  if (mode == 0){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }
}
