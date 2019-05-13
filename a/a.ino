#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19
#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24
#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13
#define FAN_PIN            9
#define PS_ON_PIN          12
#define KILL_PIN           -1
#define HEATER_0_PIN       10
#define HEATER_1_PIN       8
#define TEMP_0_PIN          13   // ANALOG NUMBERING
#define TEMP_1_PIN          14   // ANALOG NUMBERING

#include <math.h>

bool toggle_start_x, toggle_start_y; // 작동 시작 토글
bool toggle_PWM_x, toggle_PWM_y; // PWM 토글 변수
int count_x, count_y; // 움직일 값만큼 움직여주는 변수
int position_x, position_y; // 현재 위치
int moving_x, moving_y; // 움직일 값



void setup() {
  Serial.begin(115200);
  ////////////////// TIMER 1 SETTING
  TCCR1A = 0x00;
  TCCR1B = 0x0A; // 0x0A CTC, 8분주
  TCCR1C = 0x00;
  OCR1A = 400;
  TIMSK1 = 0x02;

  ////////////////// TIMER 3 SETTING
  TCCR3A = 0x00;
  TCCR3B = 0x0A; // 0x0A CTC, 8분주
  TCCR3C = 0x00;
  OCR3A = 400;
  TIMSK3 = 0x02;
}

void loop() {
  Input_Key();
}

void choice_dir(int stepx, int stepy) {
  if (stepx < 0) digitalWrite(X_DIR_PIN, 1);
  else digitalWrite(X_DIR_PIN, 0);
  if (stepy < 0) digitalWrite(Y_DIR_PIN, 1);
  else digitalWrite(Y_DIR_PIN, 0);
}
//Moving에서 숫자가 음수이면 좌측, 양수이면 우측으로 바꾸어주는 함수
void Moving(int stepx, int stepy)
{
  choice_dir(stepx, stepy);
  if (stepx == 0)
  {
    toggle_start_y = 0;
    moving_y = stepy;
  }
  else if (stepy == 0)
  {
    toggle_start_x = 0;
    moving_x = stepx;
  }
  else
  {
    toggle_start_x = 0;
    toggle_start_y = 0;
    moving_x = stepx;
    moving_y = stepy;
  }
}
//인자 stepx 만큼 x스텝, stepy 만큼 y스텝 움직이는 함수
void Input_Key()
{
  if (Serial.available())
  {
    char key = Serial.read();
    if (key == 'a') {
      Moving(-200, 0);
    }
    if (key == 'd') {
      Moving(200, 0);
    }
    if (key == 'w') {
      Moving(0, -200);
    }
    if (key == 's') {
      Moving(0, 200);
    }
  }
}


SIGNAL(TIMER1_COMPA_vect)
{

  if (toggle_start_x) {
    if (toggle_PWM_x == true)
    {
      count_x++;
      if (digitalRead(X_DIR_PIN)) position_x--;
      else position_x++;

      if (count_x >= abs(moving_x))
      {
        toggle_start_x = true;
        count_x = 0;
      }
      digitalWrite(X_STEP_PIN, 1);
      toggle_PWM_x = false;
    }
    else
    {
      digitalWrite(X_STEP_PIN, 0);
      toggle_PWM_x = true;
    }
  }
}
//OCR1A x 0.5us마다 X 모터 PWM제어

SIGNAL(TIMER3_COMPA_vect)
{

}
//OCR3A x 0.5us마다 Y 모터 PWM제어
