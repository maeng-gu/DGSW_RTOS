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

void data_set(unsigned char b) {
  digitalWrite(RS, HIGH);
  
  for(int i=3; i>=0; i--) {
  if (b & (0x01 << i)){
    digitalWrite(9+i, HIGH);
    Serial.print("1");
  }
  else{
    digitalWrite(9+i,LOW);
    Serial.print("0");
  }
 }
  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(RS, HIGH);
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

void ch_btn(int a){
  if(a<100&a>85){ // left
    if(flag == 0){
      flag=1;
      move_left();
    }
  }
  if(a<710&a>690){ // up
    if(flag == 0){
      flag=1;
      move_up();
    }
  }
  if(a<340&a>320){ //center
    if(flag == 0){
      flag=1;
      center();
    }
  }
  if(a<190&a>170){ // down
    if(flag == 0){
      flag=1;
      move_down();
    }
  }
  if(a<520&a>500){ // right
    if(flag == 0){
      flag=1;
      move_right();
    }
  }
  if(a>1000){
    flag=0;
  }
}

void move_right(){
  if(x==0&&y==0){
    inst_set(0x80);
    data_set(0x2);
    data_set(0x0);
    data_set(0x3);
    data_set(0xE);
  }
  else{
    inst_set(pinmap[y][x]);
    data_set(0x2);
    data_set(0x0);
    data_set(0x3);
    data_set(0xE);
  }
  x++;
}

void move_left(){
    inst_set(pinmap[y][x]);
    data_set(0x2);
    data_set(0x0);
    x--;
    inst_set(pinmap[y][x]);
    data_set(0x3);
    data_set(0xE);
}

void move_down(){
    inst_set(pinmap[y][x]);
    data_set(0x2);
    data_set(0x0);
    y++;
    inst_set(pinmap[y][x]);
    data_set(0x3);
    data_set(0xE);
}

void move_up(){
    inst_set(pinmap[y][x]);
    data_set(0x2);
    data_set(0x0);
    y--;
    inst_set(pinmap[y][x]);
    data_set(0x3);
    data_set(0xE);
}

void center(){
   inst_set(0x01);
   x=0;
   y=0;
   inst_set(pinmap[y][x]);
   data_set(0x3);
   data_set(0xE);
}


void setup() {
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
  data_set(0x3);
  data_set(0xE);
}
void loop() {
  int btn = analogRead(A0);
  ch_btn(btn);
}
