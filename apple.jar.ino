int Lpin = A0;  // For the Left sensor
int Rpin = A1;  // For the Right Sensor 
int led  = A2;  // For LED
int L0;
int R0;

// Counts Number of People
int cnt;

// MODIFY THESE TO CHANGE BEHAVIOR
double pdiff = 0.80;  // Controls Sensitivity
int period = 500;     // Controls delay for detection

void setup()
{
    Serial.begin(9600);  //Begin serial communcation

    // Perform quick delay
    delay(100);
    // Init Count to 0
    cnt = 0;
    // Set up Ambient Light Init Reading
    L0 = analogRead(Lpin);
    R0 = analogRead(Rpin);

}

void loop()
{
  for(int itr = 0; itr < 10; itr++)
  {
    if(L0*pdiff > analogRead(Lpin))
    {
      for(int i = 0; i < period; i++)
      {
        if(R0*pdiff > analogRead(Rpin))
        {
          cnt++;
          break;
        }
        delay(1);
      }

    }
    
    delay(20);
    
    if(R0*pdiff > analogRead(Rpin))
    {
      for(int i = 0; i < period; i++)
      {
        if(L0*pdiff > analogRead(Lpin))
        {
          if(cnt > 0) {cnt--;}
          break;
        }
        delay(1);
      }

    }

    delay(10);
  }
  if(cnt > 0)
  {
    analogWrite(led, 1023);
  }
    delay(10);

    //Serial.print("Count: ");
    Serial.println(cnt);
    /*
    Serial.print("Left: ");
    Serial.println(analogRead(Lpin));
    
    Serial.print("Right: ");
    Serial.println(analogRead(Rpin));

    Serial.println("=====\n\n");
    */
    delay(50);
}
