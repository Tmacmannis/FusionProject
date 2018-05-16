/* Notes
 *  
 *  Must unplug nano from pcb before programming
 *  2 data lines working, 8 lines will give 64 combinations.. plenty
 */

#include <SoftwareSerial.h>
//test 
#include "FastLED.h"
#include <Wire.h>
#define LED_PIN     13
#define NUM_LEDS    171
#define BRIGHTNESS  200
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

CRGB currentColor;
int BLEinput;
int BLEprev;
int currentBrightness = 200;

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

SoftwareSerial mySerial(0, 1); // RX, TX  

void setup() {  
  Serial.begin(9600);

  mySerial.begin(9600);
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);

  digitalWrite(19, LOW);
  digitalWrite(18, LOW);

  //Wire.begin(8);                // join i2c bus with address #8
  //Wire.onRequest(BLEselect);
  //pinMode(13, OUTPUT);
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
