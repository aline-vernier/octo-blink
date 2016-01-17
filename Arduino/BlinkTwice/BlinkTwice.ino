/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 10;
int led2 = 11;
int i = 0;
int state1 = 0;
int state2 = 0;
int prdmin = 80;
int fac = 3;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);   
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led1, state1);  
  
  for(i=0; i<fac; i++){
    digitalWrite(led2, state2);  
    state2 = (state2+1)%2;
    delay(prdmin);
  }   
  
state1 = (state1+1)%2;
}
