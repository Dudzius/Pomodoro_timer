#pragma once
#include "DisplayManager.h"

class TimerLogic {
public:
  void begin(DisplayManager* display);
  void update();
  void toggleRunning();
  void reset();

private:
  DisplayManager* display;
  bool running = false;
  bool work = true;
  unsigned long lastTick = 0;
  uint32_t remaining = 25 * 60;
};
