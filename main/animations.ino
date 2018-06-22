//On Animations
void rainbow(){
  fadeToBlackBy( leds, NUM_LEDS, 20);
  FastLED.show();
  colorFlag = 0;
  counter = 0;
  while (true){
    for(int i =0; i<NUM_LEDS; i++){
      leds[i] = CHSV(hue + i, 255, currentBrightness);
    }
    showAnalogRGB1(CHSV(hue,255,currentBrightness));
    counter++;
    if (counter > currentSpeed){
      counter = 0; 
      hue++;
    }
    hue = hue%255;
    FastLED.show();

    //run a different pin checker if doing run show 
    if (showActive){
      currentProgram = readShowProgram;
    }
    else {
      readPins();
    }
    if (currentProgram == 4 || currentProgram == 5){ //lower or increase brightness
      programSelect();
    }
    else if (currentProgram == 9 || currentProgram == 10){ // hue up or down
      currentProgram = 6;
    }
    else if (currentProgram != 6){ 
      break;
    }
    else {}
    currentProgram = 6;
  }

}


void confetti() 
{
  counter = 0;
  colorFlag = 0;
  // random colored speckles that blink in and fade smoothly
  while(true){
    fadeToBlackBy( leds, NUM_LEDS, 10);
    int pos = random16(NUM_LEDS);
    leds[pos] += CHSV( hue + random8(64), 200, currentBrightness);
    FastLED.delay(1000/120);
    
    readPins();
    if (currentProgram == 4 || currentProgram == 5 || currentProgram == 9 || currentProgram == 10){ //updates brightness and hue
        programSelect();
      }
    else if (currentProgram != 8){
        break;
      }
    else {}

    currentProgram = 8; 

  }
}


void sinelon()
{
  colorFlag = 0;
  // a colored dot sweeping back and forth, with fading trails
  while(true){
    fadeToBlackBy( leds, NUM_LEDS, 20);
    int pos = beatsin16( 13, 0, NUM_LEDS-1 );
    leds[pos] += CHSV( hue, 255, currentBrightness);
    FastLED.delay(1000/120);
    readPins(); 
    if (currentProgram == 4 || currentProgram == 5 || currentProgram == 9 || currentProgram == 10){ //updates brightness and hue
        programSelect();
      }
    else if (currentProgram != 12){
        break;
      }
    else {}

    currentProgram = 12; 


  }
}

void sinelonDouble()
{
  colorFlag = 0;
  // a colored dot sweeping back and forth, with fading trails
  while(true){
    fadeToBlackBy( leds, NUM_LEDS, 20);
    int pos1 = beatsin16( 13, 0, 45 );
    int pos2 = beatsin16( 13, 46, NUM_LEDS-1);

    leds[pos1] += CHSV( hue, 255, currentBrightness);
    leds[pos2] += CHSV( hue, 255, currentBrightness);
    FastLED.delay(1000/120);
    readPins();
    if (currentProgram == 4 || currentProgram == 5 || currentProgram == 9 || currentProgram == 10){ //updates brightness and hue
        programSelect();
      }
    else if (currentProgram != 13){
        break;
      }
    else {}

    currentProgram = 13; 

  }
}
