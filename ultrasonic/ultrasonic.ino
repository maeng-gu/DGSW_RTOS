int triggerpin=3;
unsigned long t=0;
unsigned long bt=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerpin, OUTPUT);
  attachInterrupt(0,myISR,CHANGE);
}

void loop() {
  digitalWrite(triggerpin,1);
  delayMicroseconds(10);
  digitalWrite(triggerpin,0);
  delay(1000);
}

void myISR()
{
  //t=micros();
  if(digitalRead(2)){
   t = micros();
  }
  else{
    bt = micros();
    Serial.print("time : ");
    Serial.println(bt-t);
  }
}
