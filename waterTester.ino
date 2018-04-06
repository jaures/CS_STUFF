int readPin = A7;
int initRead = 0;
double thresh = 1.05;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initRead = analogRead(readPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Initial: ");
  Serial.println(initRead);
  Serial.print("Current Value: ");
  Serial.println(analogRead(readPin));

  while( analogRead(readPin) > initRead * thresh)
  {
    Serial.println("Poisoned!!");
    delay(5000);
  }
  delay(100);
}
