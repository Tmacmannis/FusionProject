

void setBrightness(int value){
	//value 1-10
	//Serial.println(value);
	int mappedVal = map(value, 0, 10, 0, 255);
	currentBrightness = mappedVal;
	if (colorFlag != 0){
  		currentProgram = colorFlag;
  		Serial.println(currentProgram);
  		programSelect();
	}
}

void lowerBrightness(){
  currentBrightness -= 25;
  if (currentBrightness < 0){
  	currentBrightness = 0;
  }
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
  if (colorFlag != 0){
  	currentProgram = colorFlag;
  	programSelect();
  }
}

void lowerHue(){
  hue = ((hue-25)%255);
  if (colorFlag != 0){
  	currentProgram = colorFlag;
  	programSelect();
  }
}

void increaseHue(){
  hue = ((hue+25)%255);
  if (colorFlag != 0){
  	currentProgram = colorFlag;
  	programSelect();
  }
}