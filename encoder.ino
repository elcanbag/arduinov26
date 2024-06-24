int clkPin = 2;
int dtPin = 3;
int counter = 0;
int currentStateCLK;
int lastStateCLK;

void setup() {
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  Serial.begin(9600);
  lastStateCLK = digitalRead(clkPin);
}

void loop() {
  currentStateCLK = digitalRead(clkPin);
  if (currentStateCLK != lastStateCLK) {
    if (digitalRead(dtPin) != currentStateCLK) {
      counter++;
    } else {
      counter--;
    }
    Serial.println(counter);
  }
  lastStateCLK = currentStateCLK;
}
