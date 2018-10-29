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
    case 48:
      //brightness set to zero
      setBrightness(0);
      break;  
    case 49:
      //brightness set to 1/10
      setBrightness(1);
      break;
    case 50:
      //brightness set to 2/10
      setBrightness(2);
      break;    
    case 51:
      //brightness set to 3/10
      setBrightness(3);
      break;   
    case 52:
      //brightness set to 4/10
      setBrightness(4);
      break;   
    case 53:
      //brightness set to 5/10
      setBrightness(5);
      break; 
    case 54:
      //brightness set to 6/10
      setBrightness(6);
      break;  
    case 55:
      //brightness set to 7/10
      setBrightness(7);
      break;   
    case 56:
      //brightness set to 8/10
      setBrightness(8);
      break;
    case 57:
      //brightness set to 9/10
      setBrightness(9);
      break;
    case 58:
      //brightness set to 10/10
      setBrightness(10);
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
