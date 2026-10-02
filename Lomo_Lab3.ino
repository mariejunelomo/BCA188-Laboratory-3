#include <Arduino.h>

const int BUTTON_PIN = 4;
const int LED1_PIN = 18;
const int LED2_PIN = 19;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // Button is initially NOT PRESSED
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, HIGH);
}

void loop() {

  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // BUTTON PRESSED
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);

    Serial.println("PRESSED  | LED1: ON  | LED2: OFF");
  }
  else {
    // BUTTON NOT PRESSED
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);

    Serial.println("RELEASED | LED1: OFF | LED2: ON");
  }

  delay(200);
}