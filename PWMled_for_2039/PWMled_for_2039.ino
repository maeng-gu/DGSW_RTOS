void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j=0;j<100;j++){
    for(int i=0;i<100;i++)
    {
     digitalWrite(13,HIGH);
     delayMicroseconds(j*20);
     digitalWrite(13,LOW);
     delayMicroseconds(1000-j*20);
     digitalWrite(12,HIGH);
     delayMicroseconds(j*10);
     digitalWrite(12,LOW);
     delayMicroseconds(1000-j*10);
    }
  }
  for(int j=0;j<100;j++){
    for(int i=0;i<100;i++)
    {
     digitalWrite(13,HIGH);
     delayMicroseconds(1000-j*20);
     digitalWrite(13,LOW);
     delayMicroseconds(j*20);
     digitalWrite(12,HIGH);
     delayMicroseconds(1000-j*10);
     digitalWrite(12,LOW);
     delayMicroseconds(j*10);
    }
  }

  
}
