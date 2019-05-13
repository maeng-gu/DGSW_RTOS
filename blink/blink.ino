int count=0;
int duty=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  //-------------------------------------------
//  for(int j=0;j<100;j++){
//    for(int i=0;i<100;i++){
//      digitalWrite(13,1);
//      delayMicroseconds(j);
//      digitalWrite(13,0);
//      delayMicroseconds(100-j);
//    }
//  }
  //-------------------------------------------

  //---------------------3---------------------
  count++;
  if(count == 100){
    count=0;
    digitalWrite(13,1);
  }
  else if(count==50){
    digitalWrite(13,0);
  }
  delayMicroseconds(100);
  //---------------------3---------------------

  //---------------------4---------------------
//  count++;
//  if(count == 100){
//    count=0;
//    digitalWrite(13,1);
//    duty++;
//  }
//  else if(count==duty){
//    digitalWrite(13,0);
//  }
//
//  if(duty==100){
//    duty=0;
//  }
//  delayMicroseconds(100);
  //---------------------4---------------------
}
