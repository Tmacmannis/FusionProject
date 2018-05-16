void runShow(int number){
  int randNum = random(1,7);
  int randNum2 = random(2500,10000);
  Serial.println("hey");
  timer = millis();
  int endTimer = timer + number;
  while (timer < endTimer){

  switch(randNum){
    case 1:
      quadOn();
      quadOff();
      break;
    case 2:
      quadOn();
      bass(randNum2);
      scan0();
      break;
    case 3:
      quadOn();
      bass(randNum2);
      quadOff();
    default:
      quadOn();
      quadOff();
      break;
  }
  Serial.println("test");
  timer = millis();
}

 
 return;
}


//IDEAS

//Bass level horizontal in quadrants, start at 21 and beat up/down


