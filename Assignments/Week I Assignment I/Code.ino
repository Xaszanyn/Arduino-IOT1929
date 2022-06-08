void setup()
{
}

void loop()
{
  for(int pin = 2; pin <= 9; pin++) {
    
    digitalWrite(pin, 1);
    delay(500);
    digitalWrite(pin, 0);
  }
  for(int pin = 8; pin >= 3; pin--) {
    
    digitalWrite(pin, 1);
    delay(500);
    digitalWrite(pin, 0);
  }
  
  /*digitalWrite(2, 1);
  delay(100);
  digitalWrite(2, 0);
  delay(1000);*/
}