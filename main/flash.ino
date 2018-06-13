void flashCurrent(){
  // while (BLEinput == 2 || BLEinput == -1){
  //     for(int i =0; i<168; i++){
  //       leds[i] = currentColor;
  //     }
  //     FastLED.show();
  //     delay(50);
  //     FastLED.clear();
  //     FastLED.show();
  //     delay(50);
  //     //BLEinput = mySerial.read();
  //     Serial.println(BLEinput);
  //     }

  for(int i =0; i<23; i++){
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(1000);

    }
}
