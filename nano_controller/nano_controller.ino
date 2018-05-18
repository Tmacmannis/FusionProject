/* Notes
 *  
 *  Must unplug nano from pcb before programming
 *  2 data lines working, 8 lines will give 256 combinations.. plenty
 *  
 *  To Do:
 *    - Check how BLEread behaves, if it is possible to reset pins back to low after receiving a command. 
 *    - Add more data lines, 8 total would allow for 256 possible commands
 *  Brightness Control: 
 *    - Use 10% increments of brightness
 *    - leaves you with 246 free data lines...
 *    - Up and down brightness, implement a timed delay pin reset to null after each received ble command, assuming only prints BLEinput when a command is sent
 */

#include <SoftwareSerial.h>
//test 
#include "FastLED.h"

int BLEinput;
int BLEprev;
SoftwareSerial mySerial(0, 1); // RX, TX  

void setup() {  
  Serial.begin(9600);
  mySerial.begin(9600);
  delay( 3000 ); // power-up safety delay
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);

  digitalWrite(19, LOW);
  digitalWrite(18, LOW);

}

void loop() {  
  BLEread();
  delay(100);
  BLEselect();

    
  }




void BLEread(){
  if (mySerial.available()) {
    BLEinput = mySerial.read();  
    Serial.println(BLEinput);
  }
}

void BLEselect(){
    BLEread();
      switch (BLEinput){
      case 1:
      digitalWrite(19, HIGH);
      digitalWrite(18, HIGH);
        break;
      case 3:
        digitalWrite(19, HIGH);
        digitalWrite(18, LOW);
        break;
      case 4:
        digitalWrite(19, LOW);
        digitalWrite(18, HIGH);
        break;
      default:
      break;
  }
}
