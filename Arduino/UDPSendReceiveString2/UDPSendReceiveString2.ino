

#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         


int pin = 7;
volatile int state = LOW;

byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 79, 100);
unsigned int localPort = 5005;      

char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged; state =";       // a string to send back
char  On[] = "on";       // a string to send back
char Off[] = "off";

EthernetUDP Udp;

void setup() {
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);

  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  attachInterrupt(0, blink, CHANGE); //INTERRUPT 0 ON PIN 2
  
}

void loop() {
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  digitalWrite(pin, state);
  if(packetSize)
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i =0; i < 4; i++)
    {
      Serial.print(remote[i], DEC);
      if (i < 3)
      {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");
    Serial.println(packetBuffer);

    // send a reply, to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    if (state == 1){
      Udp.write(On);
    }
    else{
      Udp.write(Off);
    }
    Udp.endPacket();
  }
  delay(10);
}

void blink()
{
  state = !state;
}


