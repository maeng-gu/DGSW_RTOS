// RS : 2 // RW : 3 // E : 4 //
// DB0 : 5 ~ DB7 : 12 //

#define RS 2
#define RW 3
#define E 4

void inst_set(){
  int inst_settings[] = {0x30,0x30,0x30,0x38,0x06,0x0C,0x80};
  for(int j=0;j<=7;j++){
    inst_setting(j,inst_settings);
    delayMicroseconds(100);
  }
}

void inst_setting(int j, int inst_settings[]){
    digitalWrite(RS,0);
    digitalWrite(RW,0);
    
    for(int i=7;i>=0;i--){
      if(inst_settings[j] & (0x01<<i))
        digitalWrite(i+5,1);
      else
        digitalWrite(i+5,0);
    }

    digitalWrite(E,1);
    digitalWrite(E,0);

    digitalWrite(RS,1);
    digitalWrite(RW,1);
}

void data_set(){
  int data_settings[] = {0x53,0x54,0x41,0x52,0x43,0x52,0x41,0x46,0x54,0x39,0x3A,0x41,0x42,0x43,0x44,0x45
                        ,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53,0x54,0x55};
  for(int j=0;j<=32;j++){
    data_setting(j,data_settings);
    delayMicroseconds(100);
  }
}

void data_setting(int j, int data_settings[]){
    digitalWrite(RS,1);
    digitalWrite(RW,0);
    
    for(int i=7;i>=0;i--){
      if(data_settings[j] & (0x01<<i))
        digitalWrite(i+5,1);
      else
        digitalWrite(i+5,0);
    }

    digitalWrite(E,1);
    digitalWrite(E,0);

    digitalWrite(RS,1);
    digitalWrite(RW,1);
    delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=2;i<=12;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(RS,1);
  digitalWrite(RW,1);

  inst_set();
}
void loop() {
  
  
  data_set();
//  ///////////////////////////////////////////////////////////
//  digitalWrite(RS,1);
//  digitalWrite(RW,0);
//
//  //0x31 -> 00110000////////
//  digitalWrite(12,0);
//  digitalWrite(11,0);
//  digitalWrite(10,1);
//  digitalWrite(9,1);
//  digitalWrite(8,0);
//  digitalWrite(7,0);
//  digitalWrite(6,0);
//  digitalWrite(5,1);
//  //////////////////////////
//  
//  digitalWrite(E,1);
//  digitalWrite(E,0);
//
//  digitalWrite(RS,1);
//  digitalWrite(RW,1);
//  
//  delayMicroseconds(100);
//  ///////////////////////////////////////////////////////////

  
}
