
const int analogInPin = A0;
int i;


void loop()
{
   
    int sensorValue = 0;
    int mult = 0;
    int rd = 0;
    // if the LED is off turn it on and vice-versa:
   
    sensorValue = analogRead(analogInPin);  
    rd = sensorValue - sensorValue% 100;
   
    Serial.print("sensor = " );                       
    Serial.print(sensorValue);      
    Serial.print("\t rd = ");      
    Serial.println(rd);   

    // set the LED with the ledState of the variable:
    //digitalWrite(ledPin, ledState);
  
}

