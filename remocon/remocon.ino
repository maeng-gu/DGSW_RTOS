#define D 5
int count;
unsigned long remocon_micro;
unsigned long offset_value[50];
unsigned int remocon_array[50];
bool remocon_callback;
int digit_select_pin[] = {3,4,5,6};
int x,y;
int showdigit;
int showdigitarray[5];

String data_map[]={
  "01101000",
  "00110000",
  "00011000",
  "01111010",
  "00010000",
  "00111000",
  "01011010",
  "01000010",
  "01001010",
  "01010010"
};

int fnd[11][7] {
  {0 ,0 ,0 ,0 ,0 ,0 ,0},
  {1, 1, 1, 1, 1, 0, 1},
  {0, 0, 0, 0, 1, 0, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {0, 1, 0, 0, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 0},
  {1, 1, 0, 0, 1, 0, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 1}
};
void show_digit(int pos,int num)
{
  for(int i = 0; i < 4; i++)
  {
    if(i+1 == pos){
      //해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], 1);
      Serial.print(i);
    }
    else{
      //나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], 0);
    }
  }
  for(int x=0;x<7;x++){
    digitalWrite(x+7,!(fnd[num][x]));
  }
}
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,remocon_ISR,FALLING);
   for(int i=3;i<=13;i++){
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(remocon_callback == true)
  {
    String str="";
    remocon_callback = false;
    for(int i = 18; i <= 25;i++){
      if(offset_value[i]>2000) 
      {
        str += "1";
      }
      else{
        str += "0";
      }
    }
    for(int j=0;j<10;j++)
    {
      
      if(data_map[j]==str) 
      {
        Serial.println(String(j));
        showdigitarray[x] = j+1;
        x++;
      }
    }
  }
  for(int k=0;k<5;k++)
  {
    show_digit(k,showdigitarray[k]);
    delay(D);
  }
  
  
//  for(x=0;x<7;x++){
//    digitalWrite(x+7,0);
//  }
}



void remocon_ISR()
{
  remocon_micro = micros();
  remocon_array[count] = remocon_micro;

  // input data
  if(count > 0)
    offset_value[count] = remocon_array[count]  - remocon_array[count-1];
  
  // 13.5ms
  if(offset_value[count]>13000&&offset_value[count]<14000)
      count = 1;
      
  // 11.5ms
  if(offset_value[count]>11000&&offset_value[count]<12000){
      count = -1;
  }

  //callback
  count++;
  if(count>33)
  {
    count = 0;
    remocon_callback = true;
  }
}
