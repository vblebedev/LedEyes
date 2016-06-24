/* 
  For testing MAX7219
*/
//We always have to include the LedControl library
#include "LedControl.h"

/*
 Create LetControl object, define pin connections
 */
#define PIN_EYES_DIN 12
#define PIN_EYES_CS 11
#define PIN_EYES_CLK 10

// Testing only one Led
LedControl lc = LedControl(PIN_EYES_DIN, PIN_EYES_CLK, PIN_EYES_CS, 1);

/*
  Arduino setup
*/
void setup() 
{
  // MAX7219 is in power-saving mode on startup, we have to do a wakeup call
  lc.shutdown(0,false);
  // set the brightness to low
  lc.setIntensity(0,1);
  // clear module
  lc.clearDisplay(0);
}

/*
  Arduino loop
*/
void loop() 
{ 
  // LED test
  // vertical line
  byte b = B10000000;
  for (int c=0; c<=7; c++)
  {
    for (int r=0; r<=7; r++)
    {
      lc.setRow(0, r, b);
    }
    b = b >> 1;
    delay(50);
  }
  // full module
  b = B11111111;
  for (int r=0; r<=7; r++)
  {
    lc.setRow(0, r, b);
  }
  delay(500);
}
