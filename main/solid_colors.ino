void red(){
  Serial.println("red");
  for(int i =0; i<168; i++){
  leds[i] = CRGB::Red;
  }
  currentColor= CRGB::Red;
  //BLEread();
  
  FastLED.show();
  //FastLED.clear();
}

void blue(){
  Serial.println("blue");
  for(int i =0; i<168; i++){
  leds[i] = CRGB::Blue;
  Serial.println(i);
  }
  currentColor= CRGB::Blue;
  FastLED.show();
  //FastLED.clear();
}

void green(){
  Serial.println("green");
  for(int i =0; i<168; i++){
  leds[i] = CRGB::Green;
  }
  currentColor= CRGB::Green;
  FastLED.show();
  //FastLED.clear();
}
void clearStrip(){
  FastLED.clear();
  FastLED.show();
}

