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
    showAnalogRGB2(CHSV(hue + 60,255,currentBrightness));
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
  int rgbConfettiBrightness = 0;
  activeFadeConfetti = false;
  int rgb1Hue = 0;
  
  // random colored speckles that blink in and fade smoothly
  while(true){
    fadeToBlackBy( leds, NUM_LEDS, 10);
    int pos = random16(NUM_LEDS);
    leds[pos] += CHSV( hue + random8(64), 200, currentBrightness);
    FastLED.delay(1000/120);

    int rgb1 = random16(50);
    if (rgb1 == 1){
      rgbConfettiBrightness = currentBrightness;
      rgb1Hue = hue + random8(64);
      showAnalogRGB1(CHSV(rgb1,200,rgbConfettiBrightness));
      activeFadeConfetti = true;
    }
    if (activeFadeConfetti){
      rgbConfettiController(rgbConfettiBrightness, rgb1Hue);
    }
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

void rgbConfettiController(int rgbConfettiBrightness, int rgb1){
  if (tempBrightConfetti > rgbConfettiBrightness){
    tempBrightConfetti = 0;
  }
  int brightVar = rgbConfettiBrightness - tempBrightConfetti;
  if (brightVar < 4){
    brightVar = 0;
    activeFadeConfetti = false;
  }
  showAnalogRGB1(CHSV(rgb1,255,brightVar));
  tempBrightConfetti += 3;
    //fadeToBlackBy( leds, NUM_LEDS, 10);
    //FastLED.show(); 
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
