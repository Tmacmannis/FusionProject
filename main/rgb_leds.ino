void colorBars()
{
  showAnalogRGB2( CRGB::Red );   delay(500);
  showAnalogRGB2( CRGB::Green ); delay(500);
  showAnalogRGB2( CRGB::Blue );  delay(500);
  showAnalogRGB2( CRGB::Black ); delay(500);
  showAnalogRGB1( CRGB::Red );   delay(500);
  showAnalogRGB1( CRGB::Green ); delay(500);
  showAnalogRGB1( CRGB::Blue );  delay(500);
  showAnalogRGB1( CRGB::Black ); delay(500);
}

void showAnalogRGB1( const CRGB& rgb)
{
  analogWrite(RGB_RED1,   rgb.r );
  analogWrite(RGB_GREEN1, rgb.g );
  analogWrite(RGB_BLUE1,  rgb.b );
}

void showAnalogRGB2( const CRGB& rgb)
{
  analogWrite(RGB_RED2,   rgb.r );
  analogWrite(RGB_GREEN2, rgb.g );
  analogWrite(RGB_BLUE2,  rgb.b );
}

