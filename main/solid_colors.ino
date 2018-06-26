void red(){
  colorFlag = 1;
  for(int i =0; i<NUM_LEDS; i++){
    leds[i] = CHSV(0, 255, currentBrightness);
  }
  showAnalogRGB1(CHSV(0,255,currentBrightness));
  showAnalogRGB2(CHSV(0,255,currentBrightness));
  hue = 0;
  FastLED.show();
}

void blue(){
  colorFlag = 3;
  for(int i =0; i<NUM_LEDS; i++){
    leds[i] = CHSV(160, 255, currentBrightness);
  }
  showAnalogRGB1(CHSV(160,255,currentBrightness));
  showAnalogRGB2(CHSV(160,255,currentBrightness));
  hue = 160;
  FastLED.show();
}

void green(){
  colorFlag = 2;
  for(int i =0; i<NUM_LEDS; i++){
  leds[i] = CHSV(96, 255, currentBrightness);
  }
  showAnalogRGB1(CHSV(96,255,currentBrightness));
  showAnalogRGB2(CHSV(96,255,currentBrightness));
  hue = 96;
  FastLED.show();
}

void customColor(){
  colorFlag = 11;    //has to match program number
  for(int i =0; i<NUM_LEDS; i++){
  leds[i] = CHSV(hue, 255, currentBrightness);
  }
  showAnalogRGB1(CHSV(hue,255,currentBrightness));
  showAnalogRGB2(CHSV(hue,255,currentBrightness));
  FastLED.show();
}

//saved color presets
void colorPreset1(){
  colorFlag = 11;    //has to match program number
  for(int i =0; i<NUM_LEDS; i++){
  leds[i] = CHSV(preset1Hue, 255, currentBrightness);
  }
  FastLED.show();
}

void colorPreset2(){

}

void colorPreset3(){

}

void clearStrip(){
  rgbfade = true;
  currentProgram = 0;
}

