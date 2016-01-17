
#include <stdio.h>

static FILE uartout = {0} ;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int rd = 0;
float rdFloat = 0;

static int uart_putchar (char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  // fill in the UART file descriptor with pointer to writer.
  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  // The uart is the standard output device STDOUT.
   stdout = &uartout ;
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);    
  rd = sensorValue % 100;  
  //rd = map(rd, 0, 99, 0, 255);
  rdFloat = (float)(rd)/100.0;
  // map it to the range of the analog out:
  //outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);           

  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t rdFloat = ");      
  Serial.println(rdFloat);   
  fprintf( &uartout, "My Rd = %lf\n", rdFloat ) ;

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(3000);                     
}
