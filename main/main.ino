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

//globals
int currentProgram = 0;
int currentBrightness = 200;
int currentSpeed = 10;
int colorFlag = 0;
int hue = 0;
int preset1Hue = 0;
double counter = 0; 
int maxBrightness = 255;
unsigned long timer;

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

//audio setup
const int myInput = AUDIO_INPUT_LINEIN;
AudioInputAnalog adc1(A2);         
AudioAnalyzeFFT1024 fft;
AudioConnection patchCord1(adc1, fft);
AudioControlSGTL5000 audioShield;

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
  readPins();
  programSelect();
}

void readPins(){
  Wire.requestFrom(8, 1);
  while (Wire.available()) { 
    c = Wire.read(); 
  }
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
      break;
      case 0x02:
        //green
        currentProgram = 2;
      break;
      case 0x03:
        //blue
        currentProgram = 3;
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
      case 0x0C:
        //preset 1
        currentProgram = 12;
      break;
      case 0x0D:
        //preset 1
        currentProgram = 13;
      break;
      case 0x0E:
        //preset 1
        currentProgram = 14;
      break;
      default:
        currentProgram = 0;
        Serial.println("read pins 0");
      break;
    }  
  }
}