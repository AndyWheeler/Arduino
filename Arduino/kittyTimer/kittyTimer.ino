

int switchState = 0;
boolean partyTime = false;

void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
}

void loop(){
  int h = Time.hour();
  /*countdown mode*/
  if (!partyTime) {
    
  }
  /*party mode*/
  else {
    switchState = digitalRead(2);
  }
}
