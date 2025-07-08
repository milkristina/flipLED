#include <Adafruit_NeoPixel.h>

#define LED_PIN 6      
#define LED_COUNT 96

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(50);
  
  // blue
  int b[] = {1,2,3,4,6,7,8,9,10,11,13,14,15,16};
  for(int i=0; i<16; i++) strip.setPixelColor(b[i]-1, 0, 50, 240);
  
  // green
  int g[] = {17,19,20,21,22,23,24,25,26,28,29,30,31,32};
  for(int i=0; i<16; i++) strip.setPixelColor(g[i]-1, 0, 180, 0);

  // purple
  int P[] = {33,34,35,36,37,39,40,41,42,43,44,46,47,48};
  for(int i=0; i<16; i++) strip.setPixelColor(P[i]-1, 120, 40, 210);

  // yellow
  int y[] = {49,50,51,52,53,54,56,57,58,59,61,62,63,64};
  for(int i=0; i<16; i++) strip.setPixelColor(y[i]-1, 250, 170, 0);
  
  // Red
  int r[] = {65,66,67,68,69,71,72,73,74,75,76,78,79,80};
  for(int i=0; i<16; i++) strip.setPixelColor(r[i]-1, 255, 50, 50);
  
  // pink
  int p[] = {81,82,83,85,86,87,88,90,91,92,93,94,95,96};
  for(int i=0; i<16; i++) strip.setPixelColor(p[i]-1, 255, 60, 180);
  strip.show();

  //special
  int s[] = {5,12,18,27,38,45,55,60,70,77,84,89};
  for(int i=0; i<16; i++) strip.setPixelColor(s[i]-1, 1, 50, 240);
  strip.show();
}

void loop() {}
