// cd C:\Users\Ekin\Documents\Arduino\libraries\Blynk\scripts
// blynk-ser.bat -c COM7

#define BLYNK_PRINT DebugSerial

#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

char auth[] = "-BnVmvZpbjGyu7rARK4O20gUtshos803";

void setup() {
  
  DebugSerial.begin(9600);

  Serial.begin(9600);
  Blynk.begin(Serial, auth);

}

void loop() {

  Blynk.run();

}