#define RS 2
#define E 4
int flag;
int x=0,y=0;
int pinmap[4][20] =
{
  {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93},
  {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3},
  {0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7},
  {0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7}
};
char *d[4] = {"qwer","asdf","zxcv","uiop"};

void data_set(unsigned char b) {
int tmp = 0x80;
  for(int i=0;i<2;i++){
    digitalWrite(RS, HIGH);
    for(int j=12;j>=9;j--){
      if (b & tmp){
        digitalWrite(j, HIGH);
        Serial.print("1");
      }
      else{
        digitalWrite(j, LOW);
        Serial.print("0");
      }
      tmp >>= 1;
    }
    Serial.print(" ");
    digitalWrite(E, HIGH);
    digitalWrite(E, LOW);

    digitalWrite(RS, HIGH);

    delayMicroseconds(100);
  }
}

void inst_set(unsigned char a) {
  int tmp = 0x80;
  for(int i=0;i<2;i++){
    digitalWrite(RS, LOW);
    for(int j=12;j>=9;j--){
      if (a & tmp){
        digitalWrite(j, HIGH);
        Serial.print("1");
      }
      else{
        digitalWrite(j, LOW);
        Serial.print("0");
      }
      tmp >>= 1;
    }
    Serial.print(" ");
    digitalWrite(E, HIGH);
    digitalWrite(E, LOW);

    digitalWrite(RS, HIGH);

    delayMicroseconds(100);
  }
}

void setup()
{
  Serial.begin(9600);
  for(int i=2; i<13; i++) {
    pinMode(i, OUTPUT);
  }
  digitalWrite(RS, LOW);
  inst_set(0x3);
  inst_set(0x3);
  inst_set(0x3);
  inst_set(0x2);
  inst_set(0x28);
  inst_set(0x0C);
  inst_set(0x80);
  inst_set(0x01);
  
  for(int i=0;i<4;i++)
  {
    inst_set(pinmap[i][0]);
    for(int j=0;j<4;j++)
    {
      data_set(*(*(d+i)+j));
    }
    
  }
}

void loop()
{
 
}
  
