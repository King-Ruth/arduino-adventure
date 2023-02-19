#include <WiFiNINA.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LEDR,   0);
  analogWrite(LEDG, 201);
  analogWrite(LEDB,  204);
  delay(1000);
  analogWrite(LEDR,   52);
  analogWrite(LEDG, 168);
  analogWrite(LEDB,  83);
  delay(1000);
  analogWrite(LEDR,   247);
  analogWrite(LEDG, 120);
  analogWrite(LEDB,  138);
  delay(1000);


}
