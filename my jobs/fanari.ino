// variables
int green = 8;
int yellow = 9;
int red = 10;
int greenDe = 6;
int yellowDe = 2;
int redDe = 6;
int buzzer = 5;
bool redFlag = false; //patame to koumpi otan to fanari einai kokino
bool greenFlag = false;
bool redDisplay = false; //ekane ta 10 deft sto kokino (mas bgazei apo to loop)
bool displayGreen = false; 
bool buzzerFlag = false; //tsekarei pote einai se 6 h 10 defterolepta
int times = 0;
#define button digitalRead(7) == 0 //koumpi sto 7

// basic functions                
void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {             //edo einai main
  green_light(greenDe);
  yellow_light(yellowDe);
  red_light(redDe);
}

void green_light(int delayGreen) {  
  int i = 0;
  while (i < delayGreen) { // oso i<delayGreen anavei to prasino
    greenFlag = true;
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    i ++;
    delay(1000);
    push_switch(i);
    if (displayGreen) {        // kovei to while
      i = delayGreen + 2;
    }
    redFlag = false;
    displayGreen = false;
    greenFlag = false;
  }
}

void yellow_light(int delayYellow) {
  int i = 0;
  while (i < delayYellow) {
    redFlag = false;
    greenFlag = false;
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    i++;
    delay(1000);
  }
}

void red_light(int delayRed) { 
  int i = 0;

  while (i < delayRed) {
    redFlag = true;
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    i++;
    if (buzzerFlag) {         
      tone(buzzer, 659);
    }
    delay(1000);
    noTone(buzzer);
    push_switch(i);   //elegxei an einai patimeno to koumpi
    if (redDisplay == true) { 
      i =  delayRed + 2;
    }
    redFlag = false;
    greenFlag = false;
    redDisplay = false;
  }
}

void push_switch(int remainingTime) {
  if (!button) { // ginete true
    if (redFlag) {
      buzzerFlag = true;
      red_light(10);
      buzzerFlag = false;
      redDisplay = true;
      redFlag = false;
      return;
    } else if (greenFlag) {
      if (remainingTime < 3) {
        digitalWrite(green, HIGH);
        delay(3000);
        greenOperation();
      } else {
        int times = (greenDe - remainingTime) * 1000; //apominantas xronos se milisecond
        digitalWrite(green, HIGH);
        delay(times);
        greenOperation();
      }
    }
  }
}

void greenOperation() { //otan patame to koumpi sto prasino
  buzzerFlag = true;
  yellow_light(2);
  red_light(10);
  green_light(6);
  redFlag = false;
  displayGreen = true;
  greenFlag = false;
  buzzerFlag = false;
  delay(100);
}
