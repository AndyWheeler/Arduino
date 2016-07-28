long notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);
  long knobVal = analogRead(A1);
  long pitch = 0;
  if(keyVal == 1023){
    pitch = long(notes[0])*long(knobVal)/1023;
    tone(8, notes[0]*knobVal/1023);
  } else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]*knobVal/1023);
  } else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]*knobVal/1023);
  } else if(keyVal >= 3 && keyVal <= 15){
    tone(8, notes[3]*knobVal/1023);
  } else {
    noTone(8);
  }
}
