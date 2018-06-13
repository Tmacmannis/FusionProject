void programSelect(){
  switch (currentProgram){
    case 1:
      Serial.println("red");
      red();
      break;
    case 2:
      Serial.println("green");
      green();
      break;
    case 3:
      Serial.println("blue");
      blue();
      break;
    case 4:
      Serial.println("Increase Brightness");
      increaseBrightness();
      break;
    case 5:
      Serial.println("Decrease Brightness");
      lowerBrightness();
      break;
    case 6:
      Serial.println("Rainbow");
      rainbow();
      break;
    case 7:
      Serial.println("Off");
      clearStrip();
      break;
    case 8:
      Serial.println("Custom Color");
      customColor();
      break;
    case 9:
      Serial.println("hue increase");
      increaseHue();
      break;
    case 10:
      Serial.println("hue decrease");
      lowerHue();
      break;
    case 11:
      Serial.println("Preset 1");
      colorPreset1 = hue;
      colorPreset1();
      break;

    default:
    break;
   // }
  }

}


