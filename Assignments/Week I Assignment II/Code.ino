void setup()
{
}

void loop()
{
  digitalWrite(2, 1);
  delay(10000);
  digitalWrite(3, 1);
  delay(12000);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 1);
  delay(5000);
  digitalWrite(4, 0);
}