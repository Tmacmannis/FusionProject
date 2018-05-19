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

#define DATA_PIN1     18
#define DATA_PIN2     19
#define DATA_PIN3     8
#define DATA_PIN4     7
#define DATA_PIN5     12
#define DATA_PIN6     11
#define DATA_PIN7     10
#define DATA_PIN8     9

int BLEinput;
int BLEprev;
SoftwareSerial mySerial(0, 1); // RX, TX  

void setup() {  
  Serial.begin(9600);
  mySerial.begin(9600);
  delay( 3000 ); // power-up safety delay
  pinMode(DATA_PIN1, OUTPUT);
  pinMode(DATA_PIN2, OUTPUT);
  pinMode(DATA_PIN3, OUTPUT);
  pinMode(DATA_PIN4, OUTPUT);
  pinMode(DATA_PIN5, OUTPUT);
  pinMode(DATA_PIN6, OUTPUT);
  pinMode(DATA_PIN7, OUTPUT);
  pinMode(DATA_PIN8, OUTPUT);

  digitalWrite(DATA_PIN1, LOW);
  digitalWrite(DATA_PIN2, LOW);
  digitalWrite(DATA_PIN3, LOW);
  digitalWrite(DATA_PIN4, LOW);
  digitalWrite(DATA_PIN5, LOW);
  digitalWrite(DATA_PIN6, LOW);
  digitalWrite(DATA_PIN7, LOW);
  digitalWrite(DATA_PIN8, LOW);

}

void loop() {  
  BLEread();
  delay(100);
  BLEselect();
  BLEinput = 0; //reset

  }

void BLEread(){
  if (mySerial.available()) {
    BLEinput = mySerial.read();  
    Serial.println(BLEinput);
  }
}

void BLEselect(){
  switch (BLEinput){
    case 1:
      digitalWrite(DATA_PIN1, HIGH);
      digitalWrite(DATA_PIN2, HIGH);
      digitalWrite(DATA_PIN3, HIGH);
      digitalWrite(DATA_PIN4, HIGH);
      digitalWrite(DATA_PIN5, HIGH);
      digitalWrite(DATA_PIN6, HIGH);
      digitalWrite(DATA_PIN7, HIGH);
      digitalWrite(DATA_PIN8, HIGH);
    break;
    case 3:
      digitalWrite(DATA_PIN1, HIGH);
      digitalWrite(DATA_PIN2, HIGH);
      digitalWrite(DATA_PIN3, HIGH);
      digitalWrite(DATA_PIN4, HIGH);
      digitalWrite(DATA_PIN5, LOW);
      digitalWrite(DATA_PIN6, LOW);
      digitalWrite(DATA_PIN7, LOW);
      digitalWrite(DATA_PIN8, LOW);
    break;
    case 4:
      digitalWrite(DATA_PIN1, LOW);
      digitalWrite(DATA_PIN2, LOW);
      digitalWrite(DATA_PIN3, LOW);
      digitalWrite(DATA_PIN4, LOW);
      digitalWrite(DATA_PIN5, HIGH);
      digitalWrite(DATA_PIN6, HIGH);
      digitalWrite(DATA_PIN7, HIGH);
      digitalWrite(DATA_PIN8, HIGH);
    break;
    default:
      digitalWrite(DATA_PIN1, LOW);
      digitalWrite(DATA_PIN2, LOW);
      digitalWrite(DATA_PIN3, LOW);
      digitalWrite(DATA_PIN4, LOW);
      digitalWrite(DATA_PIN5, LOW);
      digitalWrite(DATA_PIN6, LOW);
      digitalWrite(DATA_PIN7, LOW);
      digitalWrite(DATA_PIN8, LOW);
    break;
  }

  // Delay and reset all pins to low
  delay(100);
  digitalWrite(DATA_PIN1, LOW);
  digitalWrite(DATA_PIN2, LOW);
  digitalWrite(DATA_PIN3, LOW);
  digitalWrite(DATA_PIN4, LOW);
  digitalWrite(DATA_PIN5, LOW);
  digitalWrite(DATA_PIN6, LOW);
  digitalWrite(DATA_PIN7, LOW);
  digitalWrite(DATA_PIN8, LOW);
}
