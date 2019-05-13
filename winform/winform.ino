void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char c = Serial.read();
  if(c=='1') digitalWrite(13,1);
  else digitalWrite(13,0);
}
