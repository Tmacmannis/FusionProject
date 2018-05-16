void BLEselect(int BLEinput){
  
//  if (BLEinput == 5){
//    lowerBrightness();
//    BLEinput = -2;
//    Serial.print("current num: ");
//    Serial.println(BLEinput);
//    BLEread();
//    
//  }
  if (BLEinput == BLEprev && BLEprev == 1){
    runShow(1000);
  }

  else if(BLEinput == BLEprev){
    
    }
  
  else{
      BLEprev = BLEinput;
      switch (BLEinput){
        
      case 1:
        runShow(1000);
        break;
      case 3:
        blue();
        break;
      case 4:
        green();
        break;
      case 5:
        
        lowerBrightness();
        break;
      case 6:
        currentBrightness = 255;
        FastLED.setBrightness(255);
        FastLED.show();
        break;
      case 0:
        clearStrip();
        break;
      case 2: //flash
        flashCurrent();
        break;
      
      default:
      break;
   // }
  }
}
}

