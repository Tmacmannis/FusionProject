#include "FastLED.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <SoftwareSerial.h>

#define LED_PIN     13
#define NUM_LEDS    168
#define BRIGHTNESS  200
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

CRGB leds[NUM_LEDS];

CRGB currentColor;

double counter = 0; 
int hue;
int maxBrightness = 255;
unsigned long timer;
int BLEinput;
char BLEinput2;
int BLEprev;
int currentBrightness = 200;
char my_str[7];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

const int myInput = AUDIO_INPUT_LINEIN;
AudioInputAnalog adc1(A2);         // audio shield: mic or line-in
AudioAnalyzeFFT1024 fft;
AudioConnection patchCord1(adc1, fft);        // audio shield: headphones & line-out
AudioControlSGTL5000 audioShield;
int val = 0, val2 = 0;

//SoftwareSerial mySerial(7, 8); // RX, TX  

void setup() {

  AudioMemory(12);
  audioShield.enable();
  audioShield.inputSelect(myInput);
  audioShield.volume(0.5);

  //LED setup
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  Serial.begin(9600);
  //mySerial.begin(9600);

  Wire.begin(); 
  pinMode(19, INPUT);

}

void loop() {
  float n;
  int i;


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

  val = digitalRead(19);
  val2 = digitalRead(18);
  Serial.print(val);
  Serial.println(val2);
  delay(100);


}


void BLEread(){
  Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8
  while (Wire.available()) { // slave may send less than requested
    //char c = Wire.read(); // receive a byte as character
    for (int i = 0; i < 6; i++){
      char c = Wire.read();
      my_str[i] = c;
    }
    my_str[6] = 0;
    BLEinput = atoi(my_str);
    Serial.println(BLEinput);

    }         // print the character
  }




