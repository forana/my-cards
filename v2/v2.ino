#include "Adafruit_SSD1306.h"

#define lowPin 0
#define highPin 7
#define sleepMS 250
#define text "alex foran"
#define textLen 10
#define textMax 20

Adafruit_SSD1306 display(4);

int currentPin;
int dir;

int counter = 0;

void setup() {
  for (int i=lowPin; i<=highPin; i++) {
    pinMode(i, OUTPUT);
  }
  currentPin = 0;
  dir = 1;

  // reconfigure if you have a different display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.display();
}



void loop() {
  digitalWrite(currentPin, LOW);
  currentPin += dir;
  if ((dir > 0 && currentPin == highPin) || (dir < 0 && currentPin == lowPin)) {
    dir *= -1;
  }
  digitalWrite(currentPin, HIGH);
  delay(sleepMS);

  if (counter >= textMax) {
    counter = 0;
    display.clearDisplay();
    display.setCursor(0, 0);
  }
  
  display.print(text[counter % textLen]);
  display.display();
  counter++;
}
