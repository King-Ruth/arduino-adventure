#include <Servo.h>

Servo valet;
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;
int knockVal;
int switchVal;
const int quietKnock = 500; //originally 10, but that didn't work IRL
const int loudKnock = 1000; //originally 100, but that ended up being way too low
//all my "knocks" ended up being between 600 and 800
bool locked = false;
int numberOfKnocks = 0;

void setup() {
  // put your setup code here, to run once:
  valet.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  valet.write(0);
  Serial.println("The box is unlocked!");

}

void loop() {
  // put your main code here, to run repeatedly:
  if(locked == false){
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH)
    {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      valet.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
  if(locked == true)
  {
    knockVal = analogRead(piezo);
    if(numberOfKnocks < 3 && knockVal > 0)
    {
      if(checkForKnock(knockVal) == true)
      {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" many knocks to go.");
    }
    if(numberOfKnocks >= 3)
    {
      locked = false;
      valet.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
    }
  }

}

bool checkForKnock(int value)
{
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  } else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
