void lowerBrightness(){
  currentBrightness -= 25;
  if (currentBrightness < 0){
  	currentBrightness = 0;
  }
  Serial.println("current brightness: " + currentBrightness);
  if (colorFlag != 0){
  	currentProgram = colorFlag;
  	programSelect();
  }
}

void increaseBrightness(){
  currentBrightness += 25;
  if (currentBrightness > 255){
  	currentBrightness = 255;
  }
  Serial.println("current brightness: " + currentBrightness);
  if (colorFlag != 0){
  	currentProgram = colorFlag;
  	programSelect();
  }
}

void lowerHue(){
  hue -= 25;
  if (hue < 0){
    hue = 0;
  }
  Serial.println("current hue: " + hue);
  if (colorFlag != 0){
    currentProgram = colorFlag;
    programSelect();
  }
}

void increaseHue(){
  hue += 25;
  if (hue > 255){
    hue = 255;
  }
  Serial.println("current hue: " + hue);
  if (colorFlag != 0){
    currentProgram = colorFlag;
    programSelect();
  }
}