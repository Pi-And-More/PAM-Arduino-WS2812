#include <Adafruit_NeoPixel.h>

#define CIRCLEPIN 6

#define PIXELCOUNT 16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELCOUNT,CIRCLEPIN,
  NEO_GRB+NEO_KHZ800);

int degree = 0;

void setup() {
  Serial.begin(115200);
  pixels.begin();
  for(int i=0;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
}

void loop() {
  Serial.println(degree);
  for(int i=0;i<PIXELCOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  int thisPixel = (degree*16)/360;
  pixels.setPixelColor((thisPixel+3)%16,pixels.Color(255,0,0));
  pixels.setPixelColor((thisPixel+2)%16,pixels.Color(100,0,0));
  pixels.setPixelColor((thisPixel+1)%16,pixels.Color(40,0,0));
  pixels.setPixelColor((thisPixel)%16,pixels.Color(15,0,0));
  pixels.show();
  delay(50);
  degree += 10;
  if (degree>=360) {
    degree -= 360;
  }
}

