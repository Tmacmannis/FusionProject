void colorBars()
{
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

