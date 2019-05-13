//7세그먼트 선택 핀
int digit_select_pin[] = {2,3,4,5};
//7세그먼트 제어 핀
int segment_pin[] = {6,7,8,9,10,11,12,13};
//자릿수 표현 사이의 지연 시간, ms 단위
int time_delay = 5;
//0~9까지의 숫자 표시를 위한 세그먼트 a~dp의 점멸 패턴
//켜지는 부분이 1로 표현됨
byte digits_data[10]={0xFC, 0x60, 0xDA, 0xF2, 
0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
 
void setup()
{
  //자릿수 선택 핀을 출력으로 설정
  for(int i = 0; i < 4; i++)
  {
    pinMode(digit_select_pin[i], OUTPUT);
  }
  // 세그먼트 제어 핀을 풀력으로 설정
  for(int i = 0; i < 8; i++)
  {
    pinMode(segment_pin[i], OUTPUT);
  }
}
//해당 자릿수에 숫자 하나를 표시하는 함수
//(위치, 출력할 숫자)
void show_digit(int pos, int number)
{
  for(int i = 0; i < 4; i++)
  {
    if(i+1 ==pos)
      //해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else
      //나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  // 8개 세그먼트 제어
  for(int i = 0; i < 8; i++)
  {
    byte segment_data = (digits_data[number] 
    & (0x01 << i)) >> i;
    if(segment_data == 1)
      digitalWrite(segment_pin[7-i], HIGH);
    else
      digitalWrite(segment_pin[7-i], LOW);
  }
}
void loop()
{
  show_digit(1, 1);
  delay(time_delay);
  show_digit(2, 2);
  delay(time_delay);
  show_digit(3, 3);
  delay(time_delay);
  show_digit(4, 4);
  delay(time_delay);
}
