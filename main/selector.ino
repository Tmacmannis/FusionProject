void programSelect(){
  switch (currentProgram){
    case 1:
      //red
      red();
      break;
    case 2:
      //green
      green();
      break;
    case 3:
      //blue
      blue();
      break;
    case 4:
      //Increase Brightness
      increaseBrightness();
      break;
    case 5:
      //Decrease Brightness
      lowerBrightness();
      break;
    case 6:
      //Rainbow
      rainbow();
      break;
    case 7:
      //Lights Off
      clearStrip();
      break;
    case 8:
      //Custom Color
      confetti();
      break;
    case 9:
      //hue increase
      increaseHue();
      break;
    case 10:
      //hue decrease
      lowerHue();
      break;
    case 11:
      //custom color
      customColor();
      break;
    case 12:
      //single chaser
      sinelon();
      break;
    case 13:
      //single chaser
      sinelonDouble();
      break;


    default:
    break;
   // }
  }

}


