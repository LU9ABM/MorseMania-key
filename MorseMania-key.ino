#include <Keyboard.h>

#define DIT 2
#define DAH 3

#define DEBOUNCE 10

volatile bool press_A = false;
unsigned long last_A = 0;

volatile bool press_S = false;
unsigned long last_S = 0;

void setup() {
  Keyboard.begin();
  pinMode(DIT, INPUT_PULLUP);
  pinMode(DAH, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(DIT), P_DIT, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DAH), P_DAH, CHANGE);
}

void loop() {
  delay(1000);
}

void P_DIT() {
  if (last_A + DEBOUNCE > millis()) return;
  if (!digitalRead(DIT)) {
    if (!press_A) {
        press_A = true;
        Keyboard.press('A');
        last_A = millis();
    }
  } else {
    if (press_A) {
      Keyboard.release('A');
      press_A = false;
      last_A = millis();
    }
  }
}

void P_DAH() {
  if (last_S + DEBOUNCE > millis()) return;
  if (!digitalRead(DAH)) {
    if (!press_S) {
        press_S = true;
        Keyboard.press('S');
        last_S = millis();
    }
  } else {
    if (press_S) {
      Keyboard.release('S');
      press_S = false;
      last_S = millis();
    }
  }
}
