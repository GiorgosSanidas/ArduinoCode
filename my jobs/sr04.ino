#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define led 7

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
  pinMode(led, OUTPUT);
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
 if(a<=20)

{
   digitalWrite(led, HIGH);

}
else { digitalWrite(led, LOW);}
   delay(1000);

}