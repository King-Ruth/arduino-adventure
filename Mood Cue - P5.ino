#include <Servo.h>
Servo butler;
const int potPin = A0;
int potVal;
int angle;
void setup() {
  // put your setup code here, to run once:
  butler.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  butler.write(angle);
  delay(15);

}
