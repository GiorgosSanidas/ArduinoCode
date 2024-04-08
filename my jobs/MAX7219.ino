//www.elegoo.com
//2016.12.9

//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime1=500;
unsigned long delaytime2=50;
void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix.
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte d[5]={B00111000,B01000100,B10000010,B10000010,B11111110};
  byte i[5]={B00000000,B00000010,B10111110,B00100010,B00000000};
  byte m[5]={B00111110,B00100000,B00111110,B00100000,B00111110};
  byte t[5]={B00100000,B00100010,B11111110,B00100000,B00100000};
  byte r[5]={B00100000,B00100000,B00010000,B00111110,B00000000};
  byte s[5]={B10000110,B10001110,B10010010,B11100010,B11000010};


  /* now display them one by one with a small delay */
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(1000);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(1000);
  lc.setRow(0,0,m[0]);
  lc.setRow(0,1,m[1]);
  lc.setRow(0,2,m[2]);
  lc.setRow(0,3,m[3]);
  lc.setRow(0,4,m[4]);
  delay(1000);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(1000);
  lc.setRow(0,0,t[0]);
  lc.setRow(0,1,t[1]);
  lc.setRow(0,2,t[2]);
  lc.setRow(0,3,t[3]);
  lc.setRow(0,4,t[4]);
  delay(1000);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(1000);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(1000);
  lc.setRow(0,0,s[0]);
  lc.setRow(0,1,s[1]);
  lc.setRow(0,2,s[2]);
  lc.setRow(0,3,s[3]);
  lc.setRow(0,4,s[4]);
  delay(1000);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime1);
}

///*
//  This function lights up a some Leds in a row.
// The pattern will be repeated on every row.
// The pattern will blink along with the row-number.
// row number 4 (index==3) will blink 4 times etc.
// */
//void rows() {
//  for(int row=0;row<8;row++) {
//    delay(delaytime2);
//    lc.setRow(0,row,B10100000);
//    delay(delaytime2);
//    lc.setRow(0,row,(byte)0);
//    for(int i=0;i<row;i++) {
//      delay(delaytime2);
//      lc.setRow(0,row,B10100000);
//      delay(delaytime2);
//      lc.setRow(0,row,(byte)0);
//    }
//  }
//}

///*
//  This function lights up a some Leds in a column.
// The pattern will be repeated on every column.
// The pattern will blink along with the column-number.
// column number 4 (index==3) will blink 4 times etc.
// */
//void columns() {
//  for(int col=0;col<8;col++) {
//    delay(delaytime2);
//    lc.setColumn(0,col,B10100000);
//    delay(delaytime2);
//    lc.setColumn(0,col,(byte)0);
//    for(int i=0;i<col;i++) {
//      delay(delaytime2);
//      lc.setColumn(0,col,B10100000);
//      delay(delaytime2);
//      lc.setColumn(0,col,(byte)0);
//    }
//  }
//}

///*
// This function will light up every Led on the matrix.
// The led will blink along with the row-number.
// row number 4 (index==3) will blink 4 times etc.
// */
//void single() {
//  for(int row=0;row<8;row++) {
//    for(int col=0;col<8;col++) {
//      delay(delaytime2);
//      lc.setLed(0,row,col,true);
//      delay(delaytime2);
//      for(int i=0;i<col;i++) {
//        lc.setLed(0,row,col,false);
//        delay(delaytime2);
//        lc.setLed(0,row,col,true);
//        delay(delaytime2);
//      }
//    }
//  }
//}

void loop() {
  writeArduinoOnMatrix();
}
