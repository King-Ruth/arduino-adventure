int notes[4] = {262, 294, 330, 349};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyVal = analogRead(A0);
  Serial.println(keyVal);
  if(keyVal <= 1023 && keyVal >= 700){
    tone(8, notes[0]);
  } else if(keyVal >= 600 && keyVal <= 250){
    tone(8, notes[1]);
  } else if(keyVal >= 200 && keyVal <= 590){
    tone(8, notes[2]);
  } else if(keyVal >= 5 && keyVal <= 20){
    tone(8, notes[3]);
  } else{
    noTone(8);
  }


}
