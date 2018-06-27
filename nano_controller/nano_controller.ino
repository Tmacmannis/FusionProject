#include <SoftwareSerial.h>
#include "FastLED.h"
#include <Wire.h>

#define Relay_PIN     2

SoftwareSerial mySerial(0, 1); // RX, TX  
byte x = 0x00, reset = 0x00, offValue = 0x00;
int BLEinput, BLEprev, sensorValue, current = 0, prev = 0, stillOn = 0, offCount = 0, prev2 = 0, current2 = 0, notMoving = 0, xCount = 0;
bool off = true, sensorOnline = true, offOverride = false;

void setup() {  
  Serial.begin(9600);
  mySerial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  delay(100);
  pinMode(Relay_PIN, OUTPUT);
  digitalWrite(Relay_PIN,HIGH); //HIGH value on Relay_PIN closes relay, aka, completes the circuit 
  sensorValue = analogRead(A1);
}

void loop() {  
  BLEread();
  delay(10);
  checkDoor();
  EVERY_N_MILLISECONDS(500){
    checkMovement();
  }
  if (x != 0){
  Serial.print("x is: ");
  Serial.println(x);
  }
  
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
  notMoving = 0;

}

void BLEread(){
  if (mySerial.available()) {
    BLEinput = mySerial.read();  
    Serial.println(BLEinput);
    BLEselect();
  }
}

void BLEselect(){
  if(BLEinput != 7){
    off = false;
    stillOn = 0;
    sensorOnline = false;
    offCount = 0;
  }
  switch (BLEinput){
    case 1:
      //red
      x = 0x01;   //TESTNG TESTING TESTING! if works can remove case statement
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
      off = true;
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

void checkDoor(){
  if (off && sensorOnline){

    if (prev == 0){ //for initial measurement
      for (int i = 0; i < 10; i++){
        prev = prev + analogRead(A1);
      }
      prev = prev/10;
      delay(250);
  }

    
    sensorValue = 0;
    for (int i = 0; i < 10; i++){
      sensorValue = sensorValue + analogRead(A1);
    }
    current = sensorValue/10;
    sensorValue = current;
    if ((current > (prev + 50) || current < (prev - 50))){
      Serial.println("Trigger!");
      off = false;
      notMoving = 0; 
      sensorOnline = false;
      x = 0x01; // start up animation, red for now, will be fade on to blue
    }
    else {
      prev = 0;
    }
    prev = sensorValue;
    delay(10);
  }
}

void checkMovement(){
  if (prev2 == 0){ //for initial measurement
    for (int i = 0; i < 10; i++){
      prev2 = prev2 + analogRead(A1);
    }
    prev2 = prev2/10;
    delay(250);
  }

  for (int i = 0; i < 10; i++){
    current2 = current2 + analogRead(A1);
  }
  current2 = current2/10;

  if (!(current2 > (prev2 + 5) || current2 < (prev2 - 5))){
    notMoving++;
    
  }
  else{
    notMoving = 0;
    prev2 = 0;
  }

  prev2 = current2;

  if(notMoving > 120){ // = 2 minutes 
    if(off){
      notMoving = 0;
      sensorOnline = true;
      offCount = 0;
      Serial.println("sensor hasnt moved, back online!");
    }
    else { //turn lights off and sensor on
      //notMoving = 0;
      sensorOnline = true;
      offCount = 0;
      x = 0x07;
      off = true;
      Serial.println("sensor hasnt moved, lights off and sensor back online!");
    } 

    prev = 0;
  } 
  if (notMoving == 5 || notMoving == 15){
    Serial.println(notMoving);
  }
  delay(10); 
}

