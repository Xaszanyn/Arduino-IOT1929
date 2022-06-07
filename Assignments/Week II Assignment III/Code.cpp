#include <Joystick.h>
Joystick_ joystick;

#include <Servo.h>
Servo servob;
Servo servoi;

void setup() {

  Serial.begin(9600);

  servob.attach(5);
  servoi.attach(6);

  joystick.begin();

}

void loop() {

  int birincil = analogRead(A0);
  int ikincil = analogRead(A1);

  Serial.print(birincil);
  Serial.print(" ");
  Serial.println(ikincil);

  joystick.setXAxis(birincil);
  joystick.setYAxis(ikincil);

  birincil = map(birincil, 255, 1023, 0, 180);
  if(birincil < 0) birincil = 0;

  ikincil = map(ikincil, 255, 1023, 0, 180);
  if(ikincil < 0) ikincil = 0 ;

  Serial.print(birincil);
  Serial.print(" ");
  Serial.println(ikincil);
  
  servob.write(birincil);
  servoi.write(ikincil);

  // Servolar için delay(100);
}