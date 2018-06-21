void runShow(int number){
  showActive = true;
  
  int randNum = random(1,7);
  int randNum2 = random(2500,10000);
  Serial.println("hey");
  timer = millis();
  int endTimer = timer + number;
  while (timer < endTimer){

  switch(randNum){
    case 1:
      
      break;
    case 2:
      
      bass(randNum2);
      break;
    case 3:
      
    default:
      
      break;
  }
  Serial.println("test");
  timer = millis();
}

 
 return;
}


//IDEAS

//Bass level horizontal in quadrants, start at 21 and beat up/down


