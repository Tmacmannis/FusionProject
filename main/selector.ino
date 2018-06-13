void programSelect(){
  switch (currentProgram){
    case 1:
      Serial.println("red");
      //leds[0] = CRGB::Red;
      red();
      break;
    case 2:
      Serial.println("green");
      //leds[0] = CRGB::Green;
      green();
      break;
    case 3:
      Serial.println("blue");
      //leds[0] = CRGB::Blue;
      blue();
      break;
    case 4:
      Serial.println("Increase Brightness");
      //leds[0] = CRGB::Blue;
      increaseBrightness();
      break;
    case 5:
      Serial.println("Decrease Brightness");
      //leds[0] = CRGB::Blue;
      lowerBrightness();
      break;
    case 6:
      Serial.println("Rainbow");
      //leds[0] = CRGB::Blue;
      rainbow();
      break;
    case 7:
      Serial.println("Off");
      //leds[0] = CRGB::Blue;
      clearStrip();
      break;

    default:
    break;
   // }
  }

}


