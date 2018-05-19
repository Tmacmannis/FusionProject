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

#define DATA_PIN1     18  
#define DATA_PIN2     19  
#define DATA_PIN3     20 
#define DATA_PIN4     21 
#define DATA_PIN5     12  
#define DATA_PIN6     11  
#define DATA_PIN7     10  
#define DATA_PIN8     9   


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
int val1 = 0, val2 = 0, val3 = 0, val4 = 0, val5 = 0, val6 = 0, val7 = 0, val8 = 0;

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
  pinMode(DATA_PIN1, INPUT);
  pinMode(DATA_PIN2, INPUT);
  pinMode(DATA_PIN3, INPUT);
  pinMode(DATA_PIN4, INPUT);
  pinMode(DATA_PIN5, INPUT);
  pinMode(DATA_PIN6, INPUT);
  pinMode(DATA_PIN7, INPUT);
  pinMode(DATA_PIN8, INPUT);


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
  val1 = digitalRead(DATA_PIN1);
  val2 = digitalRead(DATA_PIN2);
  val3 = digitalRead(DATA_PIN3);
  val4 = digitalRead(DATA_PIN4);//
  val5 = digitalRead(DATA_PIN5);
  val6 = digitalRead(DATA_PIN6);
  val7 = digitalRead(DATA_PIN7);
  val8 = digitalRead(DATA_PIN8);
  Serial.print(val1);
  Serial.print(val2);
  Serial.print(val3);
  Serial.print(val4);
  Serial.print(val5);
  Serial.print(val6);
  Serial.print(val7);
  Serial.println(val8);
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




