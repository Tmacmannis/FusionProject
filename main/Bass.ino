void bass(int number){
  counter = 0;
  timer = millis();
  int endTimer = timer + number;
  while (timer < endTimer){
  if (fft.available()) {
  double averaged = averageRead(1,5);
  averaged = averaged * 1000;
  int mappedHue = map(averaged,1,210,0,255); 
  //Serial.print(hue);
   for(int i =0; i<168; i++){
      leds[i] = CHSV(hue + i, 255, mappedHue);
       }
       counter++;
       if (counter == 10){
        counter = 0; 
        hue++;
       }
       hue = hue%255;
      timer = millis();
      FastLED.show();
 
      
  }
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


