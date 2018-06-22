void bass(){
  counter = 0;
  int musicLevels [] = {20,20,20,20,20,20,20,20,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};
  while (true){
    if (fft.available()) {
      double averaged = averageRead(1,2);
      averaged = averaged * 1000;
      int mappedHue = map(averaged,1,210,0,25);
      for(int i =0; i<NUM_LEDS; i++){
          leds[i] = CHSV(hue + i, 255, musicLevels[mappedHue]);
      }
      Serial.println(musicLevels[mappedHue]);
      showAnalogRGB1( CHSV( hue, 255, musicLevels[mappedHue]) );
      counter++;
      if (counter == 10){
        counter = 0; 
        hue++;
      }
      hue = hue%255;
      FastLED.show();   
    }
    readPins();
    if (currentProgram == 4 || currentProgram == 5 || currentProgram == 9 || currentProgram == 10){ //updates brightness and hue
      currentProgram = 14;
    }
    else if (currentProgram != 14){
      break;
    }
    else {}

    currentProgram = 14; 

  }
    return;
}


double averageRead(int a, int b){
  double result = 0;
  for (int i = a; i <= b; i++){
    result = result + fft.read(i);
  }
  result = result / ((b-a)+ 1);
  
  return result;
}


//Test 

  // if (fft.available()) {
  // // each time new FFT data is available
  // // print it all to the Arduino Serial Monitor
  // Serial.print("FFT: ");
  // for (i=1; i<70; i++) {
  // n = fft.read(i);
  // if (n >= 0.01) {
  // Serial.print(n);
  // Serial.print(" ");
  // } else {
  // Serial.print("  -  "); // don't print "0.00"
  // }

     
  //  }
  //  Serial.println();
  // }

