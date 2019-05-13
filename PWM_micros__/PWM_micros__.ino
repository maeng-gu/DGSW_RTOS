unsigned long previousMicros;
unsigned long previousMillis;
int count=0;
int duty=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  unsigned long currentMillis;
  currentMillis=millis();

  unsigned long currentMicros = micros();
//----------------------5--------------------------
//  if(currentMicros - previousMicros >= 100){
//    previousMicros = currentMicros;
//    
//    if(count>=100){
//      count=0;
//      digitalWrite(13,1);  
//    }
//    if(count==10){
//      digitalWrite(13,0);
//    }
//    count++;
//  }
//-----------------------6---------------------------
//    if(currentMicros - previousMicros >= 100){
//      previousMicros = currentMicros;
//      if(count>=100){
//        count=0;
//        digitalWrite(13,1);
//      }
//      if(count==duty){
//        digitalWrite(13,0);
//      }
//      count++;
//    }
//    if(currentMillis - previousMillis >= 10){
//      previousMillis = currentMillis;
//      duty++;
//      if(duty==100){
//        duty=0;
//      }
//    }
}
