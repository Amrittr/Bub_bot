#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define SDA_PIN 4
#define SCL_PIN 5
#define TOUCH_PIN 6

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// WiFi
const char* ssid = "5666";
const char* password = "123456789";

// Touch
unsigned long lastTap = 0;
int tapCount = 0;

// Face
int mood = 0;
unsigned long lastBlink = 0;

// Clock
bool showClock = false;

void drawFace(bool open) {
  display.clearDisplay();

  if (open) {
    display.fillCircle(40, 26, 6, WHITE);
    display.fillCircle(88, 26, 6, WHITE);
  } else {
    display.drawLine(34, 26, 46, 26, WHITE);
    display.drawLine(82, 26, 94, 26, WHITE);
  }

  if (mood == 0) Serial.println("Mood: Happy");
  else if (mood == 1) Serial.println("Mood: Sad");
  else if (mood == 2) Serial.println("Mood: Angry");
  else if (mood == 3) Serial.println("Mood: Surprised");
  else if (mood == 4) Serial.println("Mood: Sleepy");

  if (mood == 0) {
    display.drawLine(48, 44, 80, 44, WHITE);
    display.drawLine(50, 45, 78, 45, WHITE);
  }
  else if (mood == 1) {
    display.drawLine(48, 48, 80, 48, WHITE);
    display.drawLine(50, 47, 78, 47, WHITE);
  }
  else if (mood == 2) {
    display.drawLine(48, 44, 80, 44, WHITE);
  }
  else if (mood == 3) {
    display.drawCircle(64, 46, 6, WHITE);
  }
  else if (mood == 4) {
    display.drawLine(48, 46, 80, 46, WHITE);
  }

  display.display();
}

void drawClock() {
  display.clearDisplay();
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to get time from WiFi");
    display.setCursor(10, 30);
    display.print("No Time");
    display.display();
    return;
  }

  char timeStr[10];
  char dateStr[20];
  strftime(timeStr, 10, "%H:%M:%S", &timeinfo);
  strftime(dateStr, 20, "%d %b %Y", &timeinfo);

  Serial.print("Time: ");
  Serial.println(timeStr);

  display.setTextSize(2);
  display.setCursor(10, 15);
  display.print(timeStr);

  display.setTextSize(1);
  display.setCursor(25, 40);
  display.print(dateStr);

  display.display();
}

void connectWiFi() {
  Serial.print("Connecting to WiFi ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nWiFi Connected!");
  Serial.println(WiFi.localIP());

  configTime(19800, 0, "pool.ntp.org");
  Serial.println("Time synced from NTP");
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Bubbot...");

  pinMode(TOUCH_PIN, INPUT);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (1);
  }

  Serial.println("OLED connected");

  connectWiFi();
  drawFace(true);
}

void loop() {
  if (digitalRead(TOUCH_PIN) == HIGH) {
    tapCount++;
    lastTap = millis();
    Serial.println("Touch detected");
    delay(200);
  }

  if (tapCount > 0 && millis() - lastTap > 400) {
    if (tapCount == 1) {
      mood = (mood + 1) % 5;
      Serial.println("Single Tap: Changing mood");
      showClock = false;
    }
    else if (tapCount == 2) {
      Serial.println("Double Tap: Showing time");
      showClock = true;
    }
    tapCount = 0;
  }

  if (digitalRead(TOUCH_PIN) == HIGH && millis() - lastTap > 1000) {
    Serial.println("Long Touch: Playing animation");
    for (int i = 0; i < 5; i++) {
      drawFace(false);
      delay(80);
      drawFace(true);
      delay(80);
    }
  }

  if (showClock) {
    drawClock();
  } else {
    if (millis() - lastBlink > 3000) {
      drawFace(false);
      delay(150);
      drawFace(true);
      lastBlink = millis();
      Serial.println("Blink");
    }
  }
}
