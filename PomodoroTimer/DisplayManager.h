#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

class DisplayManager {
public:
  DisplayManager();
  void begin();
  void showTimer(uint32_t remaining, bool work, bool running);
  void clear();

private:
  Adafruit_SSD1306 display;
};
