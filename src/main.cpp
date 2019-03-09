#include <Arduino.h>
#include "Keyboard.h"
#include "Keypad.h"

const byte ROWS = 1;
const byte COLS = 3;
const byte PREV_BUTTON = 1;
const byte PLAY_BUTTON = 2;
const byte NEXT_BUTTON = 3;

char keys[ROWS][COLS] = {
  {PREV_BUTTON, PLAY_BUTTON, NEXT_BUTTON},
};

byte rowPins[ROWS] = {2}; // Only one row
byte colPins[COLS] = {3, 4, 5}; // prev, play, next

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void keypadEvent(KeypadEvent button) {
  Serial.println("button pressed");
  switch(keypad.getState()) {
    case PRESSED:
      if (button == PREV_BUTTON) {
        Keyboard.print("p");
        Serial.println("Prev");
      }

      if (button == PLAY_BUTTON) {
        Keyboard.print(" ");
        Serial.println("Play");
      }

      if (button == NEXT_BUTTON) {
        Keyboard.print("n");
        Serial.println("Next");
      }
      break;
  };
}

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  keypad.addEventListener(keypadEvent);
}

void loop() {
  keypad.getKey();
}
