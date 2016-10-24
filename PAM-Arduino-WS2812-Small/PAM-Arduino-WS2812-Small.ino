#include <Adafruit_NeoPixel.h>

#define CIRCLEPIN 6

#define PIXELCOUNT 16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELCOUNT,CIRCLEPIN,
  NEO_GRB+NEO_KHZ800);

byte thisPixel = 0;

void setup() {
  pixels.begin();
  for(int i=0;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
}

void loop() {
  pixels.setPixelColor((thisPixel+4)%16,pixels.Color(255,0,0));
  pixels.setPixelColor((thisPixel+3)%16,pixels.Color(100,0,0));
  pixels.setPixelColor((thisPixel+2)%16,pixels.Color(40,0,0));
  pixels.setPixelColor((thisPixel+1)%16,pixels.Color(15,0,0));
  pixels.setPixelColor((thisPixel)%16,pixels.Color(0,0,0));
  pixels.show();
  delay(30);
  thisPixel++;
  if (thisPixel>16) {
    thisPixel = 0;
  }
}

