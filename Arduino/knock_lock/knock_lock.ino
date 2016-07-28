#include <Servo.h>
Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int redLED = 5;
int knockVal;
int switchVal;
const int quietKnock = 20;
const int loudKnock = 100;
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(switchPin, INPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(greenLED, HIGH);
  myServo.write(0);
  Serial.println("Mechanism unlocked.");
}

void loop() {
  if(locked == false){
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLED, LOW);
      myServo.write(90);
      delay(20);
      digitalWrite(redLED, HIGH);
      Serial.println("Mechanism locked.");
      delay(1000);
    }
  }
  if(locked == true){
    knockVal = analogRead(piezo);
    if(numberOfKnocks < 3 && knockVal > 0){
      if(checkForKnocks(knockVal) == true){
        numberOfKnocks++;
      }
      Serial.print(3-numberOfKnocks);
      Serial.println(" more knocks to go.");
    }
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(redLED, LOW);
      delay(20);
      digitalWrite(greenLED, HIGH);
      Serial.println("Mechanism unlocked.");
      numberOfKnocks = 0;
    }
  }
}

boolean checkForKnocks(int value){
  if (value > quietKnock && value < loudKnock){
    digitalWrite(yellowLED, HIGH);
    delay(50);
    digitalWrite(yellowLED, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else {
    Serial.print("Invalid knock of value ");
    Serial.println(value);
    return false;
  }
}
