#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Facts");
  lcd.setCursor(0, 1);
  lcd.print("about Daisy!");

}

void loop() {
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Daisy");
      lcd.setCursor(0, 1);
      switch(reply){
        case 0:
        lcd.print("is cuteiful!");
        break;
        case 1:
        lcd.print("is amazing!");
        break;
        case 2:
        lcd.print("will kill you!");
        break;
        case 3:
        lcd.print("needs blood!");
        break;
        case 4:
        lcd.print("is number one!");
        break;
        case 5:
        lcd.print("Daisy Daisy!!!!!");
        break;
        case 6:
        lcd.print("is a potato!");
        break;
        case 7:
        lcd.print("is so cute!");
        break;
      }
    }
  }
  prevSwitchState = switchState;    
}
