void lowerBrightness(){
  currentBrightness -= 25;
  FastLED.setBrightness(currentBrightness);
  Serial.println(currentBrightness);
  FastLED.show();
  
  
}

