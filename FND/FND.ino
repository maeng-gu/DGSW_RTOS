#define D 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=3;i<=13;i++){
    pinMode(i,OUTPUT);
  }
}
int x,y;
int fnd[10][7] {
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
//7세그먼트 선택 핀
int digit_select_pin[] = {3,4,5,6};
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

void loop() {
  // put your main code here, to run repeatedly:
  show_digit(1,5);
  delay(D);
  show_digit(2,2);
  delay(D);
  show_digit(3,3);
  delay(D);
  show_digit(4,4);
  delay(D);
}
  
  
