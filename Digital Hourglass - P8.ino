const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 10000;
void setup() {
  // put your setup code here, to run once:
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if((currentTime - previousTime) > interval)
  {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if(led == 7){
      //figure this out in a bit
      tone(10,262,1000); 
      //plays middle C for half a sec when all 6 LEDs are lit
    }
  }
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    for(int y = 2; y < 8; y++){
      digitalWrite(y, LOW);
    }
    led = 2;
    previousTime = currentTime;
    prevSwitchState = switchState;
  }

}
