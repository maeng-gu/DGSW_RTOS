unsigned long t=0;
unsigned long bt=0;
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,myISR,CHANGE);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void myISR()
{
  t=millis();
  if(digitalRead(2)){
   bt=t;
  }
  else{
    Serial.print("time : ");
    Serial.println(t-bt);
    t=0;
  }
}
