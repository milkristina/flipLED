#include <ESP8266WiFi.h>   //error
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "Jūsų_WiFi_pavadinimas";
const char* password = "Jūsų_WiFi_slaptažodis";

ESP8266WebServer server(80);  // Webserveris port 80

void setup() {
  Serial.begin(9600);  // Komunikacija su Arduino
  
  // Jungiamės prie WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  // Nustatome serverio maršrutus
  server.on("/", HTTP_GET, handleRoot);
  server.on("/set-leds", HTTP_POST, handleLEDControl);
  
  server.begin();
}

void loop() {
  server.handleClient();  // Aptarnaujame HTTP užklausas
}

// Pagrindinis puslapis (testavimui)
void handleRoot() {
  server.send(200, "text/html", "<h1>LED Valdymo Sistema</h1>");
}

// API endpointas LED valdymui
void handleLEDControl() {
  if (server.hasArg("pattern")) {
    int pattern = server.arg("pattern").toInt();
    Serial.println(pattern);  // Siunčiame modelio numerį į Arduino
    server.send(200, "text/plain", "OK: " + String(pattern));
  } else {
    server.send(400, "text/plain", "Klaida: Nenurodytas 'pattern' parametras");
  }
}
