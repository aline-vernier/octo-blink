#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>

#include <Boards.h>



const int latchPin = 2;      // the number of the LED pin
const int clockPin = 3;
const int SerialData = 4;

int Zero[8] = {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW};
int Un[8] = {LOW, LOW, HIGH, LOW, LOW, LOW, HIGH, LOW};
int Deux[8] = {HIGH, HIGH, LOW, HIGH, LOW, HIGH, HIGH, LOW};
int Trois[8] = {LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH};
int Quatre[8] = {LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, LOW};
int Cinq[8] = {LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW };
int Six[8] =  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW};
int Sept[8] = {LOW, LOW, HIGH, LOW, LOW, HIGH, HIGH, LOW};
int Huit[8] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW};
int Neuf[8] = {LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW};

int* DisplayStuff[10];
int* number;

int NumStatus = 0; 

void setup() {
  // set the digital pin as output:
  pinMode(latchPin, OUTPUT);   
  pinMode(clockPin, OUTPUT);   
  pinMode(SerialData, OUTPUT);
  
  DisplayStuff[0] = Zero;
  DisplayStuff[1] = Un;
  DisplayStuff[2] = Deux;
  DisplayStuff[3] = Trois;
  DisplayStuff[4] = Quatre;
  DisplayStuff[5] = Cinq;
  DisplayStuff[6] = Six;
  DisplayStuff[7] = Sept;
  DisplayStuff[8] = Huit;
  DisplayStuff[9] = Neuf;

  
  Serial.begin(9600);
  
}


void loop()
{
  int i = 0; 
  
  for(i=0; i<8; i++){
    
    digitalWrite(SerialData, DisplayStuff[NumStatus][i]); 
    
    digitalWrite(clockPin, HIGH);    // Change Clock pin
    delay(1);
    digitalWrite(clockPin, LOW);    // Change Clock pin
   
  }
       digitalWrite(latchPin, HIGH);   
       delay(1);
       digitalWrite(latchPin, LOW);   
       delay(1);

  delay(1000);
  
  
  NumStatus = (NumStatus+1)%10;
  
}

