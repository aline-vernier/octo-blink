#include "LPD8806.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

// Example to control LPD8806-based RGB LED Modules in a strip

/*****************************************************************************/

// Number of RGB LEDs in strand:
int nLEDs = 16;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 2;
int clockPin = 3;

// First parameter is the number of LEDs in the strand.  The LED strips
// are 32 LEDs per meter but you can extend or cut the strip.  Next two
// parameters are SPI data and clock pins:
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

// You can optionally use hardware SPI for faster writes, just leave out
// the data and clock pin parameters.  But this does limit use to very
// specific pins on the Arduino.  For "classic" Arduinos (Uno, Duemilanove,
// etc.), data = pin 11, clock = pin 13.  For Arduino Mega, data = pin 51,
// clock = pin 52.  For 32u4 Breakout Board+ and Teensy, data = pin B2,
// clock = pin B1.  For Leonardo, this can ONLY be done on the ICSP pins.
//LPD8806 strip = LPD8806(nLEDs);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  // Start up the LED strip
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();
  Serial.begin(9600);
}


void loop() {

  randomSeed(analogRead(0));  
//  strip.setPixelColor( 3, strip.Color(0,   0,   127));
//  delay(1000);

  colorWipe(strip.Color(0,   0,  0), 2);  

  Collide();
}

// Fill the dots progressively along the strip.
void colorWipe(uint32_t c, uint8_t wait) {
  int i;

  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
/* Helper functions */

//Input a value 0 to 384 to get a color value.
//The colours are a transition r - g -b - back to r

uint32_t Wheel(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128;   //Red down
      g = WheelPos % 128;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 127 - WheelPos % 128;  //green down
      b = WheelPos % 128;      //blue up
      r = 0;                  //red off
      break; 
    case 2:
      b = 127 - WheelPos % 128;  //blue down 
      r = WheelPos % 128;      //red up
      g = 0;                  //green off
      break; 
  }
  return(strip.Color(r,g,b));
}

uint32_t Collide(){
  int i=0;
  int x1 = 0;
  int x2 = strip.numPixels()-1;
  
  int now, then1, then2, dt1, dt2;
  
  randomSeed(analogRead(0)); 
  int tau1 =  random(100, 500);
  int tau2 =  random(100, 500);
  
  randomSeed(analogRead(0));
  int r1 = random(0, 127);
  int g1 = random(0, 100 - r1);
  int b1 = 100 - r1 - g1;
  
  randomSeed(analogRead(0));
  int r2 = random(0, 127);
  int g2 = random(0, 100 - r2);
  int b2 = 100 - r2 - g2;
  
  int color1 = strip.Color(r1, g1, b1);
  int color2 = strip.Color(r2, g2, b2);

//
//  
  strip.show(); 
 // strip.setPixelColor(x1, color1);
 // strip.setPixelColor(x2, color2);
  x1++;
  x2--;
  
  then1 = millis();
  then2 = then1;
  
  do
  {
        strip.setPixelColor(x1-1, strip.Color(0,0,0));
        strip.show();      
        strip.setPixelColor(x2+1,strip.Color(0,0,0));
        strip.show();
      //  colorWipe(strip.Color(0,   0,  0), 2);
        strip.setPixelColor(x1, color1);
        strip.show();
        strip.setPixelColor(x2, color2);
        strip.show();

//        
       now = millis();
       dt1 = now - then1;    
       dt2 = now - then2; 
       
       if(dt1 > tau1){
          x1++;
          dt1 = 0;}    
       if(dt2 > tau2){
          x2--;
          dt2 = 0;}
      Serial.print(x1, DEC); 
      Serial.print("\n");
      delay(3);
//     
  } while ((x1 < x2)&&(x1 < strip.numPixels()-1)&&(x2 > 0));
  if(x1 = x2)
        strip.setPixelColor(x1-1, strip.Color(0,0,0));
        strip.show();      
        strip.setPixelColor(x2+1,strip.Color(0,0,0));
        strip.show();

      delay(50);
      
      strip.show();
      

}



