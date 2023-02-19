#include <Servo.h>

Servo waiter;
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
void setup() {
  // put your setup code here, to run once:
  waiter.attach(9);
  pinMode(switchPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  if(switchState == HIGH){
    for(int i = 1; i < 180; i++)
    {
      waiter.write(i);
    }
  }
  else
  {
  }

}
