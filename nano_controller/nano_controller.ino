#include <SoftwareSerial.h>
#include "FastLED.h"
#include <Wire.h>

#define Relay_PIN     2

int BLEinput;
int BLEprev;
SoftwareSerial mySerial(0, 1); // RX, TX  
byte x = 0x00;
byte reset = 0x00;

void setup() {  
  Serial.begin(9600);
  mySerial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  delay( 100 );
  pinMode(Relay_PIN, OUTPUT);

  digitalWrite(Relay_PIN,HIGH); //HIGH value on Relay_PIN closes relay, aka, completes the circuit 

}

void loop() {  
  BLEread();
  delay(100);
  
  }

void requestEvent(){
  Wire.write(x);
}
void receiveEvent(int bytes){
  if(Wire.available() != 0)
  {
    reset = Wire.read();
    if (reset == 0x01){
      x = 0x00;  
    }
  }
  Serial.println("reset");

}

void BLEread(){
  if (mySerial.available()) {
    BLEinput = mySerial.read();  
    Serial.println(BLEinput);
    BLEselect();
  }
}

void BLEselect(){
  switch (BLEinput){
    case 1:
      //red
      x = 0x01;
    break;
    case 2:
      //green
      x = 0x02;
    break;
    case 3:
      //blue
      x = 0x03;
    break;
    case 4:
      //blue
      x = 0x04;
    break;
    case 5:
      //blue
      x = 0x05;
    break;
    case 6:
      //blue
      x = 0x06;
    break;
    case 7:
      //blue
      x = 0x07;
    break;
    case 8:
      //blue
      x = 0x08;
    break;
    case 9:
      //blue
      x = 0x09;
    break;
    case 10:
      //blue
      x = 0x0A;
    break;
    case 11:
      //blue
      x = 0x0B;
    break;
    case 12:
      //blue
      x = 0x0C;
    break;
    case 13:
      //blue
      x = 0x0D;
    break;
    case 14:
      //blue
      x = 0x0E;
    break;
    default:
      x = 0x00;
    break;
  }

}
