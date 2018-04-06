int photoPin = 0;
int ledPin = 7;

const int threshold = 2;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(analogRead(0));
    
  if(analogRead(0) < threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  
  delay(500);
}
