// RS : 2 // RW : 3 // E : 4 //
// DB0 : 5 ~ DB7 : 12 //

#define RS 3
#define RW 4
#define E 5


void inst_set(){
  unsigned char inst_settings[] = {0x3,0x3,0x3,0x2,0x2,0x8,0x0,0x6,0x0,0xC,0x8,0x0};
  for(int j=0;j<12;j++){
    inst_setting(j,inst_settings);
    delayMicroseconds(100);
    Serial.println();
  }
}

void inst_setting(int j, unsigned char inst_settings[]){
    digitalWrite(RS,0);
    digitalWrite(RW,0);
    
    for(int i=3;i>=0;i--){
      if(inst_settings[j] & (0x01<<i)){
        digitalWrite(i+10,1);
        Serial.print("1");
      }
      else{
        digitalWrite(i+10,0);
        Serial.print("0");
    }
    
    digitalWrite(E,1);
    digitalWrite(E,0);

    digitalWrite(RS,1);
    digitalWrite(RW,1);
  }
}

void setup() {
  for(int i=3;i<14;i++){
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);

  inst_set();
}
void loop() {
  ///// 3 ///////////////////////////////////////////
  digitalWrite(RS,1);
  digitalWrite(RW,0);
  /////////////////////////////
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,1);
  digitalWrite(10,1);
  ////////////////////////////
  digitalWrite(E,1);
  digitalWrite(E,0);
  digitalWrite(RS,1);
  digitalWrite(RW,1);
  delayMicroseconds(100);
  //////////////////////////////////////////////////


  ///// 1 ///////////////////////////////////////////
  digitalWrite(RS,1);
  digitalWrite(RW,0);
  /////////////////////////////
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,1);
  ////////////////////////////
  digitalWrite(E,1);
  digitalWrite(E,0);
  digitalWrite(RS,1);
  digitalWrite(RW,1);
  delayMicroseconds(100);
  //////////////////////////////////////////////////
}
