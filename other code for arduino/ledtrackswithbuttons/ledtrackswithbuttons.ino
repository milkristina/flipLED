#include <Adafruit_NeoPixel.h>

#define LED_PIN 6      
#define LED_COUNT 197 
#define NUM_PATTERNS 5

const int BUTTONS[NUM_PATTERNS] = {2, 3, 4, 5, 7};
int buttonStates[NUM_PATTERNS] = {HIGH};
int lastButtonStates[NUM_PATTERNS] = {HIGH};

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  for (int i = 0; i < NUM_PATTERNS; i++) {
    pinMode(BUTTONS[i], INPUT_PULLUP);
  }
  
  strip.begin();       
  strip.show(); 
  strip.setBrightness(50);
}

void loop() {
  for (int i = 0; i < NUM_PATTERNS; i++) {
    buttonStates[i] = digitalRead(BUTTONS[i]);
    
    if (buttonStates[i] == LOW && lastButtonStates[i] == HIGH) {
      applyPattern(i + 1); 
      delay(50);  
    }
    
    lastButtonStates[i] = buttonStates[i];
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
      // 2
      int red1[] = {3, 18, 33, 36, 55, 65, 69, 89, 112, 122, 129, 146, 167, 177, 180};
      int white1[] = {5, 9, 10, 24, 27, 30, 40, 45, 49, 62, 76, 80, 84, 86, 94, 97, 101, 117, 132, 136, 140, 142, 149, 153, 157, 171, 174, 187, 188, 192, 194};
      int blue1[] = {4, 11, 21, 52, 58, 72, 104, 108, 114, 124, 161, 163, 186, 193};
      int special1[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red1, sizeof(red1)/sizeof(red1[0]), strip.Color(255, 0, 0));
      setLEDs(white1, sizeof(white1)/sizeof(white1[0]), strip.Color(255, 255, 255));
      setLEDs(blue1, sizeof(blue1)/sizeof(blue1[0]), strip.Color(0, 0, 255));
      setLEDs(special1, sizeof(special1)/sizeof(special1[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 2: {
      // 3
      int red2[] = {3, 8, 11, 24, 48, 54, 62, 69, 95, 98, 109, 121, 140, 145, 153, 160, 171, 179, 193};
      int white2[] = {4, 5, 10, 18, 22, 23, 30, 39, 55, 61, 64, 65, 68, 72, 103, 110, 111, 126, 128, 133, 137, 142, 164, 168, 169, 170, 173, 178, 180,  181, 182, 194, 197};
      int blue2[] = {9, 27, 48, 53, 63, 74, 99, 104, 114, 117, 146, 149, 156, 179, 199};
      int special2[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red2, sizeof(red2)/sizeof(red2[0]), strip.Color(255, 0, 0));
      setLEDs(white2, sizeof(white2)/sizeof(white2[0]), strip.Color(255, 255, 255));
      setLEDs(blue2, sizeof(blue2)/sizeof(blue2[0]), strip.Color(0, 0, 255));
      setLEDs(special2, sizeof(special2)/sizeof(special2[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 3: {
      // 4
      int red3[] = {17, 22, 24, 27, 73, 77, 80, 111, 124, 138, 154, 163,  189, 194};
      int white3[] = {3, 4, 9, 10, 11, 18, 21, 25, 30, 33, 41, 44, 51, 55, 58, 61, 64, 69, 74, 75, 76, 84, 86,  89, 102, 103, 109, 110, 121, 125, 128, 132, 135, 136, 137, 139, 140, 141, 161, 168, 169, 176, 182, 184, 185, 186, 187,  192, 193, 196};
      int blue3[] = {9, 27, 35, 53, 63, 74, 104, 146, 149, 156, 174, 188, 195};
      int special3[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red3, sizeof(red3)/sizeof(red3[0]), strip.Color(255, 0, 0));
      setLEDs(white3, sizeof(white3)/sizeof(white3[0]), strip.Color(255, 255, 255));
      setLEDs(blue3, sizeof(blue3)/sizeof(blue3[0]), strip.Color(0, 0, 255));
      setLEDs(special3, sizeof(special3)/sizeof(special3[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 4: {
      // 5
      int red4[] = {6, 27, 36, 39, 44, 52, 59, 77, 101, 109, 112, 131, 137, 148, 177, 185, 188, 191, 193};
      int white4[] = {4, 5, 7, 9, 17, 18, 21, 31, 32, 48, 60, 62, 63, 70, 72, 81, 84, 85, 93, 97, 103, 104, 110, 111, 132, 133, 138, 142,  146, 151, 157, 161, 168, 169, 175, 181, 186, 192, 195, 196 };
      int blue4[] = {3, 8, 33, 41, 47, 50, 58, 65, 89, 102, 136, 139, 152, 163, 187, 194, 197};
      int special4[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red4, sizeof(red4)/sizeof(red4[0]), strip.Color(255, 0, 0));
      setLEDs(white4, sizeof(white4)/sizeof(white4[0]), strip.Color(255, 255, 255));
      setLEDs(blue4, sizeof(blue4)/sizeof(blue4[0]), strip.Color(0, 0, 255));
      setLEDs(special4, sizeof(special4)/sizeof(special4[0]), strip.Color(225, 225, 255));
      break;
    }
      
    case 5: {
      // 6
      int red5[] = {21, 25, 40, 61, 66, 71, 88, 108, 155, 157, 162, 168, 174, 176};
      int white5[] = {4, 8, 9, 10, 17, 18, 24, 27, 28, 36, 43, 44, 47, 50, 52, 56, 59, 60, 64, 65, 70, 84, 85, 87, 89, 94, 95, 98, 100, 112, 113, 114, 115, 117, 122, 129, 130, 137, 143, 145, 146, 149, 150, 153, 154, 158, 163, 166, 169, 182, 184, 185, 186, 188, 189, 192, 193, 194, 196};
      int blue5[] = {3, 19, 30, 34, 46, 58, 64, 68, 74, 86, 104, 125, 131, 138, 142, 148, 159, 165, 187, 182, 195};
      int special5[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red5, sizeof(red5)/sizeof(red5[0]), strip.Color(255, 0, 0));
      setLEDs(white5, sizeof(white5)/sizeof(white5[0]), strip.Color(255, 255, 255));
      setLEDs(blue5, sizeof(blue5)/sizeof(blue5[0]), strip.Color(0, 0, 255));
      setLEDs(special5, sizeof(special5)/sizeof(special5[0]), strip.Color(225, 225, 255));
      break;
    }
  }
  
  strip.show(); 
}
