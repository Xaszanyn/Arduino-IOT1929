void setup()
{
}

void loop()
{
  int A0 = analogRead(A0);
  analogWrite(3, map(A0, 0, 1023, 0, 255));
  
  if(A0 > 510) {
    digitalWrite(2, 1);
  } else {
    digitalWrite(2, 0);
  }
}