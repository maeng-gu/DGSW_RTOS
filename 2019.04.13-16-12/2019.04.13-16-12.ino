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

bool init_x = true, init_y = true;
bool center_x = false, center_y = false;
bool toggle_x, toggle_y;
bool toggle_dir_x, toggle_dir_y;
bool toggle_stop_x, toggle_stop_y;
unsigned long per, per2, milpre;
int count_x, count_y;
unsigned long limit_x,limit_y;


void firstSetting()
{
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(X_MIN_PIN, INPUT);
  pinMode(Y_MIN_PIN, INPUT);
  ////////////// PINMODE //////////////
  digitalWrite(X_MIN_PIN, 1);
  digitalWrite(Y_MIN_PIN, 1);
  digitalWrite(X_ENABLE_PIN, 0);
  digitalWrite(Y_ENABLE_PIN, 0);
  digitalWrite(X_DIR_PIN, 1);
  digitalWrite(Y_DIR_PIN, 1);
  toggle_stop_x = 0;
  center_x = 0;
}

void Input_Key()
{
  if (Serial.available())
  {
    char key = Serial.read();
    if (key == 'a') {
      toggle_stop_x = 0;
      digitalWrite(X_DIR_PIN, 0);
    }
    if (key == 'd') {
      toggle_stop_x = 0;
      digitalWrite(X_DIR_PIN, 1);
    }
    if (key == 'w') {
      toggle_stop_y = 0;
      digitalWrite(Y_DIR_PIN, 0);
    }
    if (key == 's') {
      toggle_stop_y = 0;
      digitalWrite(Y_DIR_PIN, 1);
    }
    if (key == 'r') {
      toggle_stop_x = 0;
      toggle_stop_y = 0;
      digitalWrite(X_DIR_PIN, 1);
      digitalWrite(Y_DIR_PIN, 1);
      init_x = true;
      init_y = true;
    }
    if (key == 'o')
    {
      toggle_stop_x = 0;
      toggle_stop_y = 0;

      if (limit_x > 12500) digitalWrite(X_DIR_PIN, 1);
      else digitalWrite(X_DIR_PIN, 0);

      if (limit_x > 11500) digitalWrite(Y_DIR_PIN, 1);
      else digitalWrite(Y_DIR_PIN, 0);

      center_x = true;
      center_y = true;
    }
  }
}

void MOVE_XY(unsigned long cur)
{
  if (cur - per >= 100 && toggle_stop_x == 0)
  {
    per = cur;
    limit_switch_check('x');
    limit_position_check('x');
    center_position_check('x');

    
    //center position

    if (toggle_x == true)
    {
      count_x++;
      if (digitalRead(X_DIR_PIN)) limit_x--;
      else limit_x++;

      if (center_x) count_x = 0;
      else if (init_x) count_x = 0;
      else if (count_x >= 300)
      {
        toggle_stop_x = 1;
        count_x = 0;
      }
      digitalWrite(X_STEP_PIN, 1);
      toggle_x = false;
    }
    else
    {
      digitalWrite(X_STEP_PIN, 0);
      toggle_x = true;
    }
    //PWM
  }
  //x

  if (cur - per2 >= 100 && toggle_stop_y == 0)
  {
    per2 = cur;
    limit_switch_check('y');
    limit_position_check('y');
    center_position_check('y');

    

    if (toggle_y == true)
    {
      count_y++;
      if (digitalRead(Y_DIR_PIN)) limit_y--;
      else limit_y++;

      if (center_x) count_y = 0;
      else if (init_y) count_y = 0;
      else if (count_y >= 300)
      {
        toggle_stop_y = 1;
        count_y = 0;
      }
      digitalWrite(Y_STEP_PIN, 1);
      toggle_y = false;
    }
    else
    {
      digitalWrite(Y_STEP_PIN, 0);
      toggle_y = true;
    }
  }
  //y
}

void limit_switch_check(char xy)
{
  if (xy == 'x')
  {
    if (!(digitalRead(X_MIN_PIN)))
    {
      if (digitalRead(X_DIR_PIN)) toggle_stop_x = 1;
      else toggle_stop_x = 0;
      limit_x = 0;
      init_x = false;

    }
  }
  else
  {
    if (!(digitalRead(Y_MIN_PIN)))
    {
      if (digitalRead(Y_DIR_PIN)) toggle_stop_y = 1;
      else toggle_stop_y = 0;
      limit_y = 0;
      init_y = false;
    }
  }
}
void limit_position_check(char xy)
{
  if (xy == 'x')
  {
    if (limit_x >= 19000)
    {
      if (!(digitalRead(X_DIR_PIN))) toggle_stop_x = 1;
      else toggle_stop_x = 0;
    }
  }
  else
  {
    if (limit_y >= 18000)
    {
      if (!(digitalRead(Y_DIR_PIN))) toggle_stop_y = 1;
      else toggle_stop_y = 0;
    }
  }
}
void center_position_check(char xy) 
{
  if (xy == 'x')
  {
    if (limit_x == 12500)
    {
      toggle_stop_x = 1;
      center_x = false;
    }
  }
  else
  {
    if (limit_y == 11500)
    {
      toggle_stop_y = 1;
      center_y = false;
    }
  }
}

/*void ToPoint_XY(unsigned long cer, long x, long y, bool xd, bool yd){
  if (xd) digitalWrite(X_DIR_PIN, 1);
  else digitalWrite(X_DIR_PIN, 0);

  if (yd) digitalWrite(Y_DIR_PIN, 1);
  else digitalWrite(Y_DIR_PIN, 0);

  if (cer - per >= 100 && toggle_stop_x == 0)
  {
    per = cer;
    count_x++;
    if (toggle_x == true)
    {
      digitalWrite(X_STEP_PIN, 1);
      toggle_x = false;
    }
    else
    {
      digitalWrite(X_STEP_PIN, 0);
      toggle_x = true;
    }
  }
  //x_pwm
  if (count_x >= x)
  {
    toggle_stop_x = 1;
  }
  //x_dis


  if (cer - per2 >= 100 && toggle_stop_y == 0)
  {
    per2 = cer;
    count_y++;
    if (toggle_y == true)
    {
      digitalWrite(Y_STEP_PIN, 1);
      toggle_y = false;
    }
    else
    {
      digitalWrite(Y_STEP_PIN, 0);
      toggle_y = true;
    }
  }
  //y_pwm
  if (count_y >= y)
  {
    toggle_stop_y = 1;
  }
  //y_dis
}

void move_XY_stop(unsigned long cer)
{
  if (cer - per >= 165)
  {
    per = cer;
    count_x++;
    if (digitalRead(X_MIN_PIN)) toggle_stop_x = true;
    else toggle_stop_x = false;

    if (toggle_stop_x) {
      if (toggle_x)
      {
        digitalWrite(X_STEP_PIN, 1);
        toggle_x = false;
      }
      else
      {
        digitalWrite(X_STEP_PIN, 0);
        toggle_x = true;
      }
    }
  }
  if (cer - per2 >= 200)
  {
    if (digitalRead(Y_MIN_PIN)) toggle_stop_y = true;
    else toggle_stop_y = false;
    per2 = cer;
    count_y++;
    if (toggle_stop_y) {
      if (toggle_y)
      {
        digitalWrite(Y_STEP_PIN, 1);
        toggle_y = false;
      }
      else
      {
        digitalWrite(Y_STEP_PIN, 0);
        toggle_y = true;
      }
    }
  }
}
