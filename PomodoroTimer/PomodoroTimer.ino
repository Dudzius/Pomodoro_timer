#include "DisplayManager.h"
#include "TimerLogic.h"

// --- Pins ---
#define BTN_STARTSTOP 2
#define BTN_RESET 3

TimerLogic timerLogic;
DisplayManager displayManager;

bool lastStartStopState = HIGH;

void setup() {
  Serial.begin(9600);
  Serial.println("Pomodoro Timer");

  // Initialize display
  displayManager.begin();

  // Initialize buttons
  pinMode(BTN_STARTSTOP, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);

  // Initialize timer logic
  timerLogic.begin(&displayManager);
}

void loop() {
  // --- Button handling ---
  int startStop = digitalRead(BTN_STARTSTOP);
  int reset = digitalRead(BTN_RESET);

  if (reset == LOW) {
    timerLogic.reset();
    delay(200);
  }

  if (startStop == LOW && lastStartStopState == HIGH) {
    timerLogic.toggleRunning();
    delay(200);
  }
  lastStartStopState = startStop;

  // --- Update logic every frame ---
  timerLogic.update();
}
