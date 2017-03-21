#define lowPin 0
#define highPin 3
#define sleepMS 250

int currentPin;
int dir;

void setup() {                
  for (int i=lowPin; i<=highPin; i++) {
    pinMode(i, OUTPUT);
  }
  currentPin = 0;
  dir = 1;
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(currentPin, LOW);
  currentPin += dir;
  if ((dir > 0 && currentPin == highPin) || (dir < 0 && currentPin == lowPin)) {
    dir *= -1;
  }
  digitalWrite(currentPin, HIGH);
  delay(sleepMS);
}
