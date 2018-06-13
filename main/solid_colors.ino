void red(){
  colorFlag = 1;
  Serial.println("red");
  for(int i =0; i<NUM_LEDS; i++){
  leds[i] = CHSV(0, 255, currentBrightness);
  }
  FastLED.show();
}

void blue(){
  colorFlag = 3;
  for(int i =0; i<NUM_LEDS; i++){
  leds[i] = CHSV(160, 255, currentBrightness);
  }
  FastLED.show();
  //FastLED.clear();
}

void green(){
  colorFlag = 2;
  for(int i =0; i<NUM_LEDS; i++){
  leds[i] = CHSV(96, 255, currentBrightness);
  }
  FastLED.show();
  //FastLED.clear();
}
void clearStrip(){
  colorFlag = 0;
  FastLED.clear();
  FastLED.show();
}

