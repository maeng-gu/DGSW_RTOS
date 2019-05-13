#include <Servo.h>
Servo myservo;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  myservo.attach(7);
}

void loop() {
char c=Serial.read();
  switch(c)
  {
    case '1':myservo.write(10); break;
    case '2':myservo.write(20); break;
    case '3':myservo.write(30); break;
    case '4':myservo.write(40); break;
  }
}
