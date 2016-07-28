const int sensorPin = A0;
const float baselineTemp = 20.0;
const int numberOfLights = 6;

void setup(){
  Serial.begin(9600); //open a serial port
  
  for(int pinNumber = 2; pinNumber<numberOfLights+2; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
}

void loop(){
  
  int sensorVal = analogRead(sensorPin);
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  //convert the ADC readings to voltage
  float voltage = (sensorVal/1024.0)*5.0;
  
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  
  //power lights according to temp
  for(int pinNumber = 2; pinNumber<numberOfLights+2; pinNumber++){
    int lightNumber = pinNumber-1;
    if(temperature > baselineTemp + lightNumber + 1){
      digitalWrite(pinNumber, HIGH);
    } else {
      digitalWrite(pinNumber, LOW);
    }
    delay(2);
  }
}
