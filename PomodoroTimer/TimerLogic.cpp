#include "TimerLogic.h"

void TimerLogic::begin(DisplayManager* disp) {
  display = disp;
  display->showTimer(remaining, work, running);
}

void TimerLogic::update() {
  if (!running) return;

  unsigned long now = millis();
  if (now - lastTick >= 1000) {
    lastTick = now;
    if (remaining > 0) {
      remaining--;
      display->showTimer(remaining, work, running);
    } else {
      // switch state
      work = !work;
      remaining = work ? 25 * 60 : 5 * 60;
      display->showTimer(remaining, work, running);
    }
  }
}

void TimerLogic::toggleRunning() {
  running = !running;
  display->showTimer(remaining, work, running);
}

void TimerLogic::reset() {
  running = false;
  work = true;
  remaining = 25 * 60;
  display->showTimer(remaining, work, running);
}
