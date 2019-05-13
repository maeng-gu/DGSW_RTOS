int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0;
int duty1=0;
int duty2=0;
int duty3=0;
int duty4=0;
int duty5=0;
long pm = 0;
int ledstate=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
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


/*
void loop(){
  count1++;
  count2++;
  count3++;
  count4++;
  count5++;
  if(count==100)
  {
    count=0;
    digitalWrite(13,HIGH);
  }
  else if(count==10){
    digitalWrite(13,LOW);
  }
  if(count2==100)
  {
    digitalWrite(12,HIGH);
    count2=0;
  }
  else if(count2==90){
    digitalWrite(12,LOW);
  }

  if(count1==duty1){
    digitalWrite(13,LOW);
  }
  if(count1==125){
    digitalWrite(13,HIGH);
    count1=0;
    duty1++;
    if(duty1>=25){
      duty1=0;
    }
  }

  if(count2==duty2){
    digitalWrite(12,LOW);
  }
  if(count2==150){
    digitalWrite(12,HIGH);
    count2=0;
    duty2++;
    if(duty2>=50){
      duty2=0;
    }
  }

  if(count3==duty3){
    digitalWrite(8,LOW);
  }
  if(count3==175){
    digitalWrite(8,HIGH);
    count3=0;
    duty3++;
    if(duty3==75){
      duty3=0;
    }
  }

  if(count4==duty4){
    digitalWrite(7,LOW);
  }
  if(count4==200){
    digitalWrite(7,HIGH);
    count4=0;
    duty4++;
    if(duty4==75){
      duty4=0;
    }
  }

  
  
  
  
  delayMicroseconds(100);
}
*/
/*
void loop(){
  
  unsigned long cm = micros();

  if(cm - pm > 100){
    pm=cm;
    count5++;
    if(count5==duty5){
    digitalWrite(4,LOW);
    }     digitalWrite(4,HIGH);
     count5=0;
     duty5++;
     if(duty5==150){
     duty5=0;
     }
    }
  }
  */
