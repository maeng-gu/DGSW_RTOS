// COL 10~17
// ROW 2~9
char a = 0x0F;
int k,z,m,s;
char b[10][8] = {
              {0x00,0x38,0x44,0x4c,0x54,0x64,0x44,0x38},
              {0x00,0x10,0x30,0x50,0x10,0x10,0x10,0x7c},
              {0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c},
              {0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38},
              {0x00,0x08,0x18,0x28,0x48,0x7c,0x08,0x08},
              {0x00,0x7c,0x40,0x78,0x04,0x04,0x44,0x38},
              {0x00,0x38,0x40,0x40,0x78,0x44,0x44,0x38},
              {0x00,0x7c,0x04,0x08,0x10,0x20,0x20,0x20},
              {0x00,0x38,0x44,0x44,0x38,0x44,0x44,0x38},
              {0x00,0x38,0x44,0x44,0x3c,0x04,0x44,0x38}
              };
char b2[10][8] = {
              {0x00,0x38,0x44,0x4c,0x54,0x64,0x44,0x38},
              {0x00,0x10,0x30,0x50,0x10,0x10,0x10,0x7c},
              {0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c},
              {0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38},
              {0x00,0x08,0x18,0x28,0x48,0x7c,0x08,0x08},
              {0x00,0x7c,0x40,0x78,0x04,0x04,0x44,0x38},
              {0x00,0x38,0x40,0x40,0x78,0x44,0x44,0x38},
              {0x00,0x7c,0x04,0x08,0x10,0x20,0x20,0x20},
              {0x00,0x38,0x44,0x44,0x38,0x44,0x44,0x38},
              {0x00,0x38,0x44,0x44,0x3c,0x04,0x44,0x38}
              };

unsigned long per;

void setup() {
  for(int i=2;i<18;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() {
  unsigned long cur = micros();
  if(cur-per > 1000){
    per=cur;
    for(int j=0;j<8;j++){
        digitalWrite(j+2,1);
        for(int i=0;i<8;i++)
        { 
          if(b[m][j]&(0x80 >> i)) digitalWrite(i+10,0);
          else digitalWrite(i+10,1);
        }
        for(int i=0;i<8;i++)
        {
          digitalWrite(i+10,1);
        }
        digitalWrite(j+2,0);
      }
    z++;
    if(z%100==0)
    {
      for(int i=0;i<8;i++){
        b[m][i] >>=1;
      }
      k++;
      if(k==8)
      {
        m++;
        if(m==10) {
          m=0;
          for(int i=0;i<10;i++)
            for(int j=0;j<8;j++)
              b[i][j]=b2[i][j];
        }
        k=0;
      }
    }
  }
}
