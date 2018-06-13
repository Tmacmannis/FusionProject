//On Animations
void rainbow(){
  colorFlag = 0;
  counter = 0;
  while (true){
  for(int i =0; i<NUM_LEDS; i++){
      leds[i] = CHSV(hue + i, 255, currentBrightness);
       }
       counter++;
       if (counter > currentSpeed){
        counter = 0; 
        hue++;
       }
       hue = hue%255;
       FastLED.show();

       readPins();
      if (currentProgram == 4 || currentProgram == 5){
        programSelect();
      }
      else if (currentProgram != 6){
        break;
      }
      else {}
      currentProgram = 6;
  }

}

//Turning On Animations
int halfs[] = {21, 63, 105, 147}; // 42 84 126 168

void quadOn(){
   int randNum = random(4,20);
  hue = random(0,255);
  for(int i =0; i<21; i++){

      if (i == 0){
        leds[halfs[0]] = CHSV(hue + i, 255, maxBrightness);
        leds[halfs[1]] = CHSV(hue + i, 255, maxBrightness);
        leds[halfs[2]] = CHSV(hue + i, 255, maxBrightness);
        leds[halfs[3]] = CHSV(hue + i, 255, maxBrightness);
      }
      else
      {
      
      leds[halfs[0] + i] = CHSV(hue + i, 255, maxBrightness);
      leds[halfs[0] - i] = CHSV(hue + i, 255, maxBrightness);

      leds[halfs[1] + i] = CHSV(hue + i, 255, maxBrightness);
      leds[halfs[1] - i] = CHSV(hue + i, 255, maxBrightness);

      leds[halfs[2] + i] = CHSV(hue + i, 255, maxBrightness);
      leds[halfs[2] - i] = CHSV(hue + i, 255, maxBrightness);

      leds[halfs[3] + i] = CHSV(hue + i, 255, maxBrightness);
      leds[halfs[3] - i] = CHSV(hue + i, 255, maxBrightness);

      }
        
       FastLED.show();
       delay(randNum);
       //delay(100);
       }

       
  return;
}


//Clearing Animations

void quadOff(){
  int randNum = random(1,20);
  hue = random(0,255);
  for(int i =0; i<21; i++){

      if (i == 0){
        leds[halfs[0]] = CHSV(hue + i, 255, 0);
        leds[halfs[1]] = CHSV(hue + i, 255, 0);
        leds[halfs[2]] = CHSV(hue + i, 255, 0);
        leds[halfs[3]] = CHSV(hue + i, 255, 0);
      }
      else
      {
      
      leds[halfs[0] + i] = CHSV(hue + i, 255, 0);
      leds[halfs[0] - i] = CHSV(hue + i, 255, 0);

      leds[halfs[1] + i] = CHSV(hue + i, 255, 0);
      leds[halfs[1] - i] = CHSV(hue + i, 255, 0);

      leds[halfs[2] + i] = CHSV(hue + i, 255, 0);
      leds[halfs[2] - i] = CHSV(hue + i, 255, 0);

      leds[halfs[3] + i] = CHSV(hue + i, 255, 0);
      leds[halfs[3] - i] = CHSV(hue + i, 255, 0);

      }
        
       FastLED.show();
       delay(randNum);
       // delay(100);
       }

       
  return;
}


void scan0(){
  int randNum = random(4,15);
  int x = 0;
  int y = 167;
  for(int i =83; i>=0; i--){
      leds[x] = CHSV(hue + i, 255, 0);
      leds[y] = CHSV(hue + i, 255, 0);
       FastLED.show();
       delay(randNum);
       x++;
       y--;
       }
      
  return;
}
