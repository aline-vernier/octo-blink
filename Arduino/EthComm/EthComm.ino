
#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x15, 0x49}; 

// NTP Servers:
IPAddress timeServer(132, 163, 4, 101); // time-a.timefreq.bldrdoc.gov
const int timeZone = 1;     // Central European Time



EthernetUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets

void setup() 
{
  Serial.begin(9600);
  delay(250);
  Serial.println("TimeNTP Example");
  if (Ethernet.begin(mac) == 0) {
    while (1) {
      Serial.println("Failed to configure Ethernet using DHCP");
      delay(10000);
    }
  }
  Serial.print("IP number assigned by DHCP is ");
  Serial.println(Ethernet.localIP());

}



void loop()
{  
 
}

