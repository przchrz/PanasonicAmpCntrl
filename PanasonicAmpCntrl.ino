#include<SoftwareSerial.h>

int RX;
SoftwareSerial RS485(8,9);

void setup() {
  
  Serial.begin(9600);
  Serial.println("configuring serial:\n");
  RS485.begin(9600);
  Serial.println("configuring RS485" );
  Serial.println("set up done!!");
}

void loop() {
  if (RS485.available()) 
  {
    RX = RS485.read();   // Read the byte 
    
    Serial.println(RX, HEX);
    //Serial.write(RX);   
    }
  else {Serial.println("Oops!!!");  // print this if serial is not available
  delay(1000);}
}
