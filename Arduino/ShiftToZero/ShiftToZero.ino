
const int latchPin = 2;      // the number of the LED pin
const int clockPin = 3;
const int SerialData = 4;

int ledState = HIGH;  

long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(latchPin, OUTPUT);   
  pinMode(clockPin, OUTPUT);   
  pinMode(SerialData, OUTPUT);
}

void loop()
{
  int i = 0;  

      ledState = LOW;
      
  digitalWrite(SerialData, ledState);    // Change data pin
  
  digitalWrite(clockPin, HIGH);    // Change Clock pin
  delay(1);
  digitalWrite(clockPin, LOW);    // Change Clock pin
 
  
  for(i=0; i<7; i++){
     digitalWrite(latchPin, HIGH);    // Change Clock pin
     delay(1);
     digitalWrite(latchPin, LOW);    // Change Clock pin
     delay(1);
    
  }
  

  delay(100);
}

