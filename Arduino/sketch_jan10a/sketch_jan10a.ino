
const byte LED = 13;
const byte BUTTON = 2;
int time=0;
int ledState=LOW;
long previousMillis = 0; 
long interval = 200; 
volatile int interr = 0;
volatile  int i=0;

// Interrupt Service Routine (ISR)
void pinChange ()
{
int j = 0;
int dum = 0;
  interr = 1;
  for(i=0;i<10; i++){
//    for(j=0;j<100000;j++){
//      dum = dum +1;
//    }
     digitalWrite(LED, ledState);
     if(ledState==LOW){
      ledState=HIGH;}
     else{
      ledState=LOW;
     }
  };
//    unsigned long currentMillis = millis();
// while(i<10){ 
//    if(currentMillis - previousMillis > interval) {
//    // save the last time you blinked the LED 
//    previousMillis = currentMillis;   
//
//    // if the LED is off turn it on and vice-versa:
//
//     digitalWrite(LED, HIGH);
//     delayMicroseconds(6000);
//     digitalWrite(LED, LOW);
//    // set the LED with the ledState of the variable:
//    
//    
//  }
//  i++;
// } 

}  // end of pinChange


void setup ()
{
  pinMode (LED, OUTPUT);  // so we can update the LED
  digitalWrite (BUTTON, HIGH);  // internal pull-up resistor
  attachInterrupt (0, pinChange, CHANGE);  // attach interrupt handler
  Serial.begin(9600);
}  // end of setup

void loop ()
{
  Serial.println("interrupt : ");
  if(interr == 1){
    interr=0;
    Serial.println("yes");
    Serial.println(i,DEC);
    i=0;
  }
  else{
     Serial.println("no");
     Serial.println(i,DEC);
  }
  delay(1000);
 // time = millis();
 // Serial.println("stuff ");
  // delay(3000);
 /* time = millis()-time;
  //prints time since program started
  Serial.println(time);*/

} 
