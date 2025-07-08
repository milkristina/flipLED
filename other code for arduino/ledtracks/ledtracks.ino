#include <Adafruit_NeoPixel.h>

#define LED_PIN 6      
#define LED_COUNT 195 
#define NUM_PATTERNS 6 

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);  
  strip.begin();       
  strip.show();        
}

void loop() {
  if (Serial.available() > 0) {
    int pattern = Serial.parseInt(); 
    
    if (pattern >= 1 && pattern <= NUM_PATTERNS) {
      applyPattern(pattern);
    }
  }
}

void setLEDs(int ledNumbers[], int size, uint32_t color) {
  for (int i = 0; i < size; i++) {
    int ledIndex = ledNumbers[i] - 1;
    if (ledIndex >= 0 && ledIndex < LED_COUNT) {
      strip.setPixelColor(ledIndex, color);
    }
  }
}

void applyPattern(int patternNumber) {
  strip.clear();
  
  switch (patternNumber) {
    case 1: {
      // 6 players
      int red1[] = {19, 23, 38, 57, 62, 66, 82, 100, 145, 148, 155, 162, 164, 191};
      int white1[] = {4, 8, 9, 10, 12, 15, 16, 21, 22, 25, 26, 34, 40, 41, 43, 46, 48, 52, 56, 58, 61, 65, 81, 83, 88, 89, 91, 92, 104, 106, 109, 114, 118, 120, 127, 190, 133, 136, 137, 139, 142, 143, 147, 150, 151, 156, 158, 160, 161, 165, 167, 171, 175, 177, 186, 188, 192, 194};
      int blue1[] = {3, 17, 32, 28, 42, 51, 64, 68, 80, 96, 117, 121, 128, 132, 138, 152, 172};
      int special1[] = {85, 86, 97, 98, 111, 112};
      
      setLEDs(red1, sizeof(red1)/sizeof(red1[0]), strip.Color(255, 0, 0));
      setLEDs(white1, sizeof(white1)/sizeof(white1[0]), strip.Color(255, 255, 255));
      setLEDs(blue1, sizeof(blue1)/sizeof(blue1[0]), strip.Color(0, 0, 255));
      setLEDs(special1, sizeof(special1)/sizeof(special1[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 2: {
      // 5 players
      int red2[] = {17, 21, 26, 31, 46, 69, 83, 91, 95, 126, 150, 169, 174, 179, 181, 193};
      int white2[] = {2, 7, 8, 10, 11, 23, 24, 28, 33, 36, 41, 42, 44, 48, 54, 60, 66, 70, 74, 77, 82, 96, 99, 106, 107, 109, 122, 132, 136, 138, 141, 142, 145, 152, 156, 171, 175, 177, 180, 189, 192};
      int blue2[] = {3, 9, 16, 52, 57, 61, 63, 65, 81, 87, 93, 108, 121, 130, 139, 158, 161, 163, 190, 194};
      int special2[] = {85, 86, 97, 98, 111, 112};
      
      setLEDs(red2, sizeof(red2)/sizeof(red2[0]), strip.Color(255, 0, 0));
      setLEDs(white2, sizeof(white2)/sizeof(white2[0]), strip.Color(255, 255, 255));
      setLEDs(blue2, sizeof(blue2)/sizeof(blue2[0]), strip.Color(0, 0, 255));
      setLEDs(special2, sizeof(special2)/sizeof(special2[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 3: {
      // 4 players
      int red3[] = {15, 20, 22, 25, 67, 71, 74, 103, 116, 123, 128, 137, 145, 174, 180, 188};
      int white3[] = {4, 9, 11, 16, 19, 24, 28, 31, 39, 46, 48, 54, 57, 60, 65, 68, 69, 70, 78, 83, 95, 101, 102, 110, 113, 114, 117, 118, 125, 126, 127, 132, 139, 158, 163, 165, 169, 177, 179, 193, 194};
      int blue3[] = {5, 10, 33, 40, 52, 82, 99, 129, 143, 148, 150, 155, 171, 181, 187, 192};
      int special3[] = {85, 86, 97, 98, 111, 112};
      
      setLEDs(red3, sizeof(red3)/sizeof(red3[0]), strip.Color(255, 0, 0));
      setLEDs(white3, sizeof(white3)/sizeof(white3[0]), strip.Color(255, 255, 255));
      setLEDs(blue3, sizeof(blue3)/sizeof(blue3[0]), strip.Color(0, 0, 255));
      setLEDs(special3, sizeof(special3)/sizeof(special3[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 4: {
      // 3 players
      int red4[] = {4, 34, 91, 100, 104, 121, 136, 148, 188, 194};
      int white4[] = {5, 15, 16, 18, 19, 20, 22, 24, 25, 28, 31, 37, 41, 45, 54, 57, 60, 65, 66, 69, 71, 74, 77, 80, 83, 89, 93, 95, 106, 109, 114, 117, 118, 120, 127, 130, 132, 134, 137, 138, 139, 142, 145, 152, 161, 165, 167, 171, 175, 176, 177, 180, 186, 187, 192, 193};
      int blue4[] = {36, 39, 48, 52, 70, 133, 143, 160, 172, 191};
      int special4[] = {85, 86, 97, 98, 111, 112};
      
      setLEDs(red4, sizeof(red4)/sizeof(red4[0]), strip.Color(255, 0, 0));
      setLEDs(white4, sizeof(white4)/sizeof(white4[0]), strip.Color(255, 255, 255));
      setLEDs(blue4, sizeof(blue4)/sizeof(blue4[0]), strip.Color(0, 0, 255));
      setLEDs(special4, sizeof(special4)/sizeof(special4[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 5: {
      // 2 players
      int red5[] = {3, 16, 31, 34, 51, 61, 65, 83, 104, 114, 119, 136, 155, 165, 168};
      int white5[] = {5, 9, 10, 22, 25, 28, 38, 41, 45, 58, 70, 74, 78, 80, 88, 91, 93, 109, 122, 126, 130, 132, 139, 143, 145, 159, 162, 173, 174, 178, 180};
      int blue5[] = {4, 11, 19, 48, 54, 66, 96, 100, 106, 116, 149, 151, 172, 179};
      int special5[] = {85, 86, 97, 98, 111, 112};
      
      setLEDs(red5, sizeof(red5)/sizeof(red5[0]), strip.Color(255, 0, 0));
      setLEDs(white5, sizeof(white5)/sizeof(white5[0]), strip.Color(255, 255, 255));
      setLEDs(blue5, sizeof(blue5)/sizeof(blue5[0]), strip.Color(0, 0, 255));
      setLEDs(special5, sizeof(special5)/sizeof(special5[0]), strip.Color(225, 225, 255));
      break;
    }
  }
  
  strip.show(); 
}
