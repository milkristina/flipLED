#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>  // Use <WiFi.h> if using ESP32

#define LED_PIN 6      
#define LED_COUNT 196 
#define NUM_PATTERNS 5

const int BUTTONS[NUM_PATTERNS] = {2, 3, 4, 5, 7};
int buttonStates[NUM_PATTERNS] = {HIGH};
int lastButtonStates[NUM_PATTERNS] = {HIGH};

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_PATTERNS; i++) {
    pinMode(BUTTONS[i], INPUT_PULLUP);
  }
  
  strip.begin();       
  strip.show(); 
  strip.setBrightness(50);

  // Connect to WiFi
  connectToWiFi();
  
  server.begin();
  Serial.println("Server started, waiting for clients...");
}

void loop() {
  // Handle incoming client connections
  WiFiClient client = server.available();
  if (client) {
    String cmd = client.readStringUntil('\n');
    cmd.trim();
    if (cmd.length() > 0) {
      Serial.print("Received command: ");
      Serial.println(cmd);
      processCommand(cmd);
    }
    client.stop();
  }

  // Handle button inputs
  for (int i = 0; i < NUM_PATTERNS; i++) {
    buttonStates[i] = digitalRead(BUTTONS[i]);
    if (buttonStates[i] == LOW && lastButtonStates[i] == HIGH) {
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.println(" pressed");
      applyPattern(i + 1);
      delay(50);
    }
    lastButtonStates[i] = buttonStates[i];
  }
}

void connectToWiFi() {
  Serial.println("Scanning for available networks...");
  int numNetworks = WiFi.scanNetworks();
  Serial.println("Scan complete. Available networks:");

  for (int i = 0; i < numNetworks; i++) {
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" (");
    Serial.print(WiFi.RSSI(i));
    Serial.println(" dBm)");
  }

  Serial.println("Enter the number of the network you want to connect to:");
  while (Serial.available() == 0) {} // Wait for user input
  int networkIndex = Serial.parseInt() - 1; // Get the selected network index

  if (networkIndex >= 0 && networkIndex < numNetworks) {
    String ssid = WiFi.SSID(networkIndex);
    Serial.print("Selected network: ");
    Serial.println(ssid);
    
    Serial.println("Enter the password for the selected network:");
    while (Serial.available() == 0) {} // Wait for user input
    String password = Serial.readStringUntil('\n'); // Read the password

    WiFi.begin(ssid.c_str(), password.c_str());
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Invalid network selection.");
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
      int red1[] = {3, 18, 33, 36, 55, 65, 69, 89, 112, 122, 129, 146, 168, 177, 180};
      int white1[] = {5, 9, 10, 24, 27, 30, 40, 45, 49, 62, 76, 80, 84, 86, 94, 97, 101, 117, 132, 136, 140, 142, 149, 153, 157, 171, 174, 187, 188, 192, 194};
      int blue1[] = {4, 11, 21, 52, 58, 72, 104, 108, 114, 124, 162, 164, 186, 193};
      int special1[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red1, sizeof(red1)/sizeof(red1[0]), strip.Color(255, 0, 0));
      setLEDs(white1, sizeof(white1)/sizeof(white1[0]), strip.Color(255, 255, 255));
      setLEDs(blue1, sizeof(blue1)/sizeof(blue1[0]), strip.Color(0, 0, 255));
      setLEDs(special1, sizeof(special1)/sizeof(special1[0]), strip.Color(225, 225, 255));
      break;
    }
    case 2: {
      int red2[] = {3, 8, 11, 24, 48, 54, 62, 69, 95, 98, 109, 121, 140, 145, 153, 162, 171, 179, 192};
      int white2[] = {4, 5, 10, 18, 22, 23, 30, 39, 55, 61, 64, 65, 68, 72, 103, 110, 111, 128, 133, 137, 142, 164, 169, 193, 194};
      int blue2[] = {3};
      int special2[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red2, sizeof(red2)/sizeof(red2[0]), strip.Color(255, 0, 0));
      setLEDs(white2, sizeof(white2)/sizeof(white2[0]), strip.Color(255, 255, 255));
      setLEDs(blue2, sizeof(blue2)/sizeof(blue2[0]), strip.Color(0, 0, 255));
      setLEDs(special2, sizeof(special2)/sizeof(special2[0]), strip.Color(225, 225, 255));
      break;
    }
    case 3: {
      int red3[] = {17, 22, 24, 27, 73, 77, 80, 111, 124, 133, 138, 147, 157, 188, 192, 194};
      int white3[] = {4, 9, 18, 21, 26, 30, 33, 41, 44, 50, 52, 58, 61, 64, 69, 74, 75, 76, 84, 89, 103, 109, 110, 118, 121, 122, 125, 128, 135, 136, 137, 142, 149, 171, 175, 177, 181, 16, 187, 191, 193};
      int blue3[] = {9, 27, 38, 53, 63, 74, 99, 104, 114, 117, 146, 149, 156, 174, 178, 195};
      int special3[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red3, sizeof(red3)/sizeof(red3[0]), strip.Color(255, 0, 0));
      setLEDs(white3, sizeof(white3)/sizeof(white3[0]), strip.Color(255, 255, 255));
      setLEDs(blue3, sizeof(blue3)/sizeof(blue3[0]), strip.Color(0, 0, 255));
      setLEDs(special3, sizeof(special3)/sizeof(special3[0]), strip.Color(225, 225, 255));
      break;
    }
    case 4: {
      int red4[] = {6, 27, 36, 39, 44, 52, 59, 77, 101, 109, 112, 131, 137, 148, 170, 176, 187, 192};
      int white4[] = {4, 5, 7, 9, 17, 18, 21, 31, 32, 48, 60, 62, 63, 70, 72, 81, 84, 85, 93, 97, 103, 104, 110, 111, 132, 133, 138, 146, 151, 157, 165, 168, 169, 174, 180, 188, 189, 189, 194, 195 };
      int blue4[] = {3, 8, 33, 41, 47, 50, 58, 65, 89, 102, 114, 136, 143, 152, 163, 186, 193, 196};
      int special4[] = {91, 92, 105, 106, 107, 119, 120};
      
      setLEDs(red4, sizeof(red4)/sizeof(red4[0]), strip.Color(255, 0, 0));
      setLEDs(white4, sizeof(white4)/sizeof(white4[0]), strip.Color(255, 255, 255));
      setLEDs(blue4, sizeof(blue4)/sizeof(blue4[0]), strip.Color(0, 0, 255));
      setLEDs(special4, sizeof(special4)/sizeof(special4[0]), strip.Color(225, 225, 255));
      break;
    }
    case 5: {
      int red5[] = {21, 25, 40, 61, 66, 71, 88, 108, 157, 161, 168, 174, 176};
      int white5[] = {4, 8, 9, 10, 12, 17, 18, 23, 24, 27, 28, 36, 44, 45, 47, 50, 52, 56, 59, 60, 62, 65, 70, 87, 89, 94, 95, 98, 100, 112, 114, 117, 122, 128, 130, 137, 140, 143, 146, 147, 149, 152, 153, 160, 163, 164, 169, 171, 172, 173, 179, 187, 188, 1189, 191, 192, 193};
      int blue5[] = {3, 19, 30, 34, 46, 49, 55, 68, 74, 86, 104, 125, 131, 138, 142, 148, 15, 186, 194};
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

void processCommand(String cmd) {
  cmd.toUpperCase();
  cmd.trim();
  
  if (cmd.startsWith("PATTERN")) {
    int number = cmd.charAt(7) - '0';
    if (number >= 1 && number <= NUM_PATTERNS) {
      Serial.print("Applying pattern from command: ");
      Serial.println(number);
      applyPattern(number);
    } else {
      Serial.println("Invalid pattern number received.");
    }
  } else {
    Serial.println("Unknown command.");
  }
}
