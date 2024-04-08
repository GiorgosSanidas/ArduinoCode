//www.elegoo.com
//2016.12.9

#include "IRremote.h"
#include "LedControl.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
LedControl lc=LedControl(12,10,9,1); 

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

unsigned long delaytime1=500;
unsigned long delaytime2=50;


/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 



{
  byte i0[7]={B01111100,B10000010,B10000010,B10000010,B01111100};
  byte i1[5]={B00000000,B00000010,B11111110,B01000010,B00000000};
  byte i2[5]={B00000000,B11100010,B10010010,B10001110,B00000000};
  byte i3[5]={B11111110,B10010010,B10010010,B10000010,B00000000};
  byte i4[5]={B11111110,B00010000,B00010000,B11110000,B00000000};
  byte i5[5]={B10011110,B10010010,B10010010,B11110010,B00000000};
  byte i6[5]={B10011110,B10010010,B10010010,B11111110,B00000000};
  byte i7[5]={B11100000,B10010000,B10001000,B10000110,B00000000};
  byte i8[5]={B11111110,B10010010,B10010010,B11111110,B00000000};
  byte i9[5]={B11111110,B10010010,B10010010,B11110000,B00000000};
  

  switch(results.value)

  {

  case 0xFF6897: 
  {
    Serial.println("0");
    lc.setRow(0,0,i0[0]);
    lc.setRow(0,1,i0[1]);
    lc.setRow(0,2,i0[2]);
    lc.setRow(0,3,i0[3]);
    lc.setRow(0,4,i0[4]);

   break;
  }    
  case 0xFF30CF:{
    Serial.println("1");
    lc.setRow(0,0,i1[0]);
    lc.setRow(0,1,i1[1]);
    lc.setRow(0,2,i1[2]);
    lc.setRow(0,3,i1[3]);
    lc.setRow(0,4,i1[4]);

    
    break;
  }
  case 0xFF18E7:{
    Serial.println("2");
    lc.setRow(0,0,i2[0]);
    lc.setRow(0,1,i2[1]);
    lc.setRow(0,2,i2[2]);
    lc.setRow(0,3,i2[3]);
    lc.setRow(0,4,i2[4]);

    break;
  }
  case 0xFF7A85:{
    Serial.println("3");
    lc.setRow(0,0,i3[0]);
    lc.setRow(0,1,i3[1]);
    lc.setRow(0,2,i3[2]);
    lc.setRow(0,3,i3[3]);
    lc.setRow(0,4,i3[4]);

    break;
  }
  case 0xFF10EF:{
    Serial.println("4");
    lc.setRow(0,0,i4[0]);
    lc.setRow(0,1,i4[1]);
    lc.setRow(0,2,i4[2]);
    lc.setRow(0,3,i4[3]);
    lc.setRow(0,4,i4[4]);
    break;
  }
  case 0xFF38C7:{
    Serial.println("5");
    lc.setRow(0,0,i5[0]);
    lc.setRow(0,1,i5[1]);
    lc.setRow(0,2,i5[2]);
    lc.setRow(0,3,i5[3]);
    lc.setRow(0,4,i5[4]);
    
    
    break;
  }
  case 0xFF5AA5:{
    Serial.println("6");
    lc.setRow(0,0,i6[0]);
    lc.setRow(0,1,i6[1]);
    lc.setRow(0,2,i6[2]);
    lc.setRow(0,3,i6[3]);
    lc.setRow(0,4,i6[4]);
    
    break;
  }
  case 0xFF42BD:{
    Serial.println("7");
    lc.setRow(0,0,i7[0]);
    lc.setRow(0,1,i7[1]);
    lc.setRow(0,2,i7[2]);
    lc.setRow(0,3,i7[3]);
    lc.setRow(0,4,i7[4]);
    
    break;
  }
  case 0xFF4AB5:{
    Serial.println("8"); 
    lc.setRow(0,0,i8[0]);
    lc.setRow(0,1,i8[1]);
    lc.setRow(0,2,i8[2]);
    lc.setRow(0,3,i8[3]);
    lc.setRow(0,4,i8[4]);
    
    break;
  }
  case 0xFF52AD: {
    Serial.println("9");
    lc.setRow(0,0,i9[0]);
    lc.setRow(0,1,i9[1]);
    lc.setRow(0,2,i9[2]);
    lc.setRow(0,3,i9[3]);
    lc.setRow(0,4,i9[4]);
  
  break;}
  

  //default: 
    //Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR



void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver

    /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{// writeArduinoOnMatrix();
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */
