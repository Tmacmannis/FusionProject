#include "FastLED.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <SoftwareSerial.h>

#define LED_PIN     13
#define NUM_LEDS    80
#define BRIGHTNESS  200
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
  
extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

CRGB leds[NUM_LEDS];
CRGB currentColor;

int currentProgram = 0;
int currentBrightness = 50;
int currentSpeed = 10;
int colorFlag = 0;
int hue = 0;
int preset1Hue = 0;

double counter = 0; 
int maxBrightness = 255;
unsigned long timer;

char my_str[7];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

const int myInput = AUDIO_INPUT_LINEIN;
AudioInputAnalog adc1(A2);         // audio shield: mic or line-in
AudioAnalyzeFFT1024 fft;
AudioConnection patchCord1(adc1, fft);        // audio shield: headphones & line-out
AudioControlSGTL5000 audioShield;
String val1 = 0, val2 = 0, val3 = 0, val4 = 0, val5 = 0, val6 = 0, val7 = 0, val8 = 0;
byte c = 0x00;
  
void setup() {

  AudioMemory(12);
  audioShield.enable();
  audioShield.inputSelect(myInput);
  audioShield.volume(0.5);

  //LED setup
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  FastLED.clear();
  FastLED.show();

  Serial.begin(9600);
  Wire.begin(); 
  pinMode(13, OUTPUT);

}

void loop() {


//  if (fft.available()) {
    // each time new FFT data is available
    // print it all to the Arduino Serial Monitor
//    Serial.print("FFT: ");
//    for (i=1; i<70; i++) {
//      n = fft.read(i);
//      if (n >= 0.01) {
//        Serial.print(n);
//        Serial.print(" ");
//      } else {
//        Serial.print("  -  "); // don't print "0.00"
//      }
//
//      
//    }
//    Serial.println();
    
  //quadOn();
  //quadOff();
  //scan0();
  //bass(5000);
  //rainbow();
  //runShow(5000);

  // BLEread();
  // delay(100);
  // if (BLEinput == 000001){
  //   digitalWrite(13, HIGH);
  // }
  // if (BLEinput == 000003){
  //   digitalWrite(13, LOW);
  // }

  //delay(5);
  //Serial.println("test");
  //BLEselect(BLEinput);
  //Serial.println(BLEinput);

  //hello
  readPins();
  programSelect();
  //Serial.println(currentProgram);

  //red();
  //flashCurrent();
  
}


void readPins(){
  Wire.requestFrom(8, 1);
  while (Wire.available()) { // slave may send less than requested
    c = Wire.read(); // receive a byte as character
  }
  //Serial.println(c);
  //currentProgram = 0;
  delay(1);
  if (c != 0x00){
    byte reset = 0x01;
    Wire.beginTransmission(8);   
    Wire.write(reset);                
    Wire.endTransmission();
    
    switch (c){
    case 0x01:
        //red
        currentProgram = 1;
        Serial.println("in read pins" + currentProgram);
      break;
      case 0x02:
        //green
        currentProgram = 2;
        Serial.println("in read pins" + currentProgram);
      break;
      case 0x03:
        //blue
        currentProgram = 3;
        Serial.println("in read pins" + currentProgram);
      break;
      case 0x04:
        //Increase Brightness
        currentProgram = 4;
      break;
      case 0x05:
        //Decrease Brightness
        currentProgram = 5;
      break;
      case 0x06:
        //Rainbow
        currentProgram = 6;
      break;
      case 0x07:
        //Off
        currentProgram = 7;
      break;
      case 0x08:
        //custom color
        currentProgram = 8;
      break;
      case 0x09:
        //hue increase
        currentProgram = 9;
      break;
      case 0x0A:
        //hue decrease
        currentProgram = 10;
      break;
      case 0x0B:
        //preset 1
        currentProgram = 11;
      break;
      default:
        currentProgram = 0;
        Serial.println("read pins 0");
      break;
    }
    
  }

  //Update variables 


}