void programSelect(){
  switch (currentProgram){
    case 32:
      //red
      red();
      break;
    case 33:
      //green
      green();
      break;
    case 34:
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
    case 35:
      //Rainbow
      rainbow();
      break;
    case 36:
      //Lights Off
      clearStrip();
      break;
    case 40:
      //Custom Color
      confetti();
      break;
    case 38:
      //hue increase
      increaseHue();
      break;
    case 39:
      //hue decrease
      lowerHue();
      break;
    case 37:
      //custom color
      customColor();
      break;
    case 41:
      //single chaser
      sinelon();
      break;
    case 42:
      //single chaser
      sinelonDouble();
      break;
    case 43:
      //bass bumping
      bass();
      break;


    default:
    break;
   // }
  }

}


/*
Program Number code:
red: 32
green: 33
blue: 34
increaseBrightness: 4
lowerBrightness: 5
rainbow: 35
clearStrip: 36
confetti: 40
increaseHue: 38
lowerHue: 39
customColor: 37
sinelon: 41
sinelonDouble: 42
bass: 43
*/
