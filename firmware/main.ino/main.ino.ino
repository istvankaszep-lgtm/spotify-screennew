#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <ESP32Encoder.h>
#include <SpotifyEsp32.h>

// --- ADATOK (Később tölthető ki a saját adataiddal) ---
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Spotify Developer Dashboard kulcsok:
const char* clientId = "YOUR_SPOTIFY_CLIENT_ID";
const char* clientSecret = "YOUR_SPOTIFY_CLIENT_SECRET";

// --- PIN KIOSZTÁS (Schematic alapján) ---
#define ENCODER_CLK 25
#define ENCODER_DT  26
#define ENCODER_SW  27

// Objektek inicializálása
TFT_eSPI tft = TFT_eSPI();
ESP32Encoder encoder;
WiFiClientSecure client;
SpotifyEsp32 spotify(client, clientId, clientSecret);

long oldPosition = 0;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  // Kijelző inicializálása
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString("Spotify Remote", 10, 10, 4);

  // Forgógomb konfigurálása
  pinMode(ENCODER_SW, INPUT_PULLUP);
  ESP32Encoder::useInternalWeakPullResistors = UP;
  encoder.attachHalfQuad(ENCODER_CLK, ENCODER_DT);
  encoder.clearCount();

  // Wi-Fi csatlakozás indítása
  tft.drawString("WiFi Csatlakozas...", 10, 50, 2);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  tft.fillScreen(TFT_BLACK);
  tft.drawString("WiFi Kesz!", 10, 10, 4);
  
  // SSL tanúsítvány elfogadása a Spotify API-hoz
  client.setInsecure();
}

void loop() {
  // 1. Forgógomb eltekerésének kezelése
  long newPosition = encoder.getCount() / 2;
  if (newPosition != oldPosition) {
    if (newPosition > oldPosition) {
      Serial.println("Kovetkezo szam...");
      spotify.nextTrack();
    } else {
      Serial.println("Elozo szam...");
      spotify.previousTrack();
    }
    oldPosition = newPosition;
  }

  // 2. Gombnyomás kezelése (Play/Pause)
  bool buttonState = digitalRead(ENCODER_SW);
  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("Play/Pause gomb megnyomva!");
    delay(200); // Debounce késleltetés
  }
  lastButtonState = buttonState;

  delay(10);
}