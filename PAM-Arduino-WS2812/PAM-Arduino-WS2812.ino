////////////////////////////////////////////////////////////////////////////////////
//
//                               PI and more
//                      Arduino & WS2812 led circle
//
// https://piandmore.wordpress.com/2016/10/04/arduino-or-esp-ws2812/
//
////////////////////////////////////////////////////////////////////////////////////
//
// The library from Adafruit which enables the use of the WS2812
// or NeoPixel
//
#include <Adafruit_NeoPixel.h>

//
// The pin the circle of WS2812 leds is connected to
//
#define CIRCLEPIN 6
//
// The number of leds in our circle
//
#define PIXELCOUNT 16

//
// Initialize the Adafruit library
//
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELCOUNT,CIRCLEPIN,
  NEO_GRB+NEO_KHZ800);

//
// The current position in degrees
//
int degree = 0;

void setup() {
  Serial.begin(115200);
  //
  // Start the led string and turn them all off
  //
  pixels.begin();
  for(int i=0;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
}

void loop() {
  Serial.println(degree);
  //
  // Turn all leds to black
  //
  for(int i=0;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  //
  // Convert degrees to the pixel position
  //
  int thisPixel = (degree*PIXELCOUNT)/360;
  //
  // Set the pixels with a trailing tail
  //
  pixels.setPixelColor((thisPixel+3)%16,pixels.Color(255,0,0));
  pixels.setPixelColor((thisPixel+2)%16,pixels.Color(100,0,0));
  pixels.setPixelColor((thisPixel+1)%16,pixels.Color(40,0,0));
  pixels.setPixelColor((thisPixel)%16,pixels.Color(15,0,0));
  //
  // Don't forget to call the pixels.show();
  //
  pixels.show();
  delay(50);
  degree += 10;
  if (degree>=360) {
    degree -= 360;
  }
}

