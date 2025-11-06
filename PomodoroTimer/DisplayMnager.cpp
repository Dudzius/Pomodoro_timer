#include "DisplayManager.h"
#include "icons.h"

DisplayManager::DisplayManager()
    : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1) {}

void DisplayManager::begin() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.display();
}

void DisplayManager::showTimer(uint32_t remaining, bool work, bool running) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);

  if (work)
    display.println("FOCUS");
  else
    display.println("BREAK");

  display.setCursor(0, 40);
  display.setTextSize(3);
  uint8_t minutes = remaining / 60;
  uint8_t seconds = remaining % 60;
  if (minutes < 10) display.print("0");
  display.print(minutes);
  display.print(":");
  if (seconds < 10) display.print("0");
  display.println(seconds);
  display.drawBitmap(100, 10, playPauseBitmap, 25, 17, WHITE);
  display.drawBitmap(100, 40, resetBitmap, 25, 25, WHITE);
  display.display();
}

void DisplayManager::clear() {
  display.clearDisplay();
  display.display();
}
