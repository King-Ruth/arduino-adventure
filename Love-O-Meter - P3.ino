const int sensorPin = A0;
float baselineTemp = 9.2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //open a serial port
  for(int pinNo = 2; pinNo < 5; pinNo++){
    pinMode(pinNo, OUTPUT); //initialising the pins 2 to 4 as output
    digitalWrite(pinNo, LOW); //turning all the LEDs off to start
  }
  // // turn on LED to signal the start of the calibration period:
  // pinMode(13, OUTPUT);
  // digitalWrite(13, HIGH);
  // // calibrate during the first five seconds
  // float values[100];
  // float total = 0;
  // for(int i = 0; i < 100; i++)
  // {
  // 	values[i] = ((analogRead(sensorPin)/1024.0 * 5.0) - 0.5) * 100.0;
  // 	total += values[i];
  // 	delay(50);
  // }
  // baselineTemp = total/100.0; //base temp is average of 100 values
  // // signal the end of the calibration period
  // digitalWrite(13, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin); //gives you a number between 0 and 1023
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0) * 5.0; //converts the ADC reading to a specific voltage between 0 and 5V
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  float temp = (voltage - 0.5) * 100.0;
  Serial.println(temp);

  if(baselineTemp - temp <= 1){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if(temp > baselineTemp + 2 && temp <= baselineTemp + 4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  if(temp > baselineTemp + 4 && temp <= baselineTemp + 6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if(temp > baselineTemp + 6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(10);


}
