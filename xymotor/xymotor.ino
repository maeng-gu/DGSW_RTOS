
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



bool toggle_stop_x, toggle_stop_y;
bool toggle_x, toggle_y;
bool toggle_dir_x, toggle_dir_y;
unsigned long per, per2;
int count_x, count_y;



void setup() {
  Serial.begin(9600);

  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(X_MIN_PIN, INPUT);
  pinMode(Y_MIN_PIN, INPUT);
  ////////////// PINMODE //////////////
  digitalWrite(X_MIN_PIN,1);
  digitalWrite(Y_MIN_PIN,1);
  digitalWrite(X_ENABLE_PIN, 0);
  digitalWrite(Y_ENABLE_PIN, 0);
  // enable
}

void move_X(unsigned long cer)
{
  if (cer - per >= 100)
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

  if (count_x >= 1000)
  {
    count_x = 0;
    if (toggle_dir_x == true)
    {
      digitalWrite(X_DIR_PIN, 1);
      toggle_dir_x = false;
    }
    else
    {
      digitalWrite(X_DIR_PIN, 0);
      toggle_dir_x = true;
    }
  } 
  //x_dir
}

void move_Y(unsigned long cer)
{
  if (cer - per2 >= 500)
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

  if (count_y >= 1000)
  {
    count_y = 0;
    if (toggle_dir_y == true)
    {
      digitalWrite(Y_DIR_PIN, 1);
      toggle_dir_y = false;
    }
    else
    {
      digitalWrite(Y_DIR_PIN, 0);
      toggle_dir_y = true;
    }
  }
  //y_dir
}

void move_X_stop(unsigned long cer)
{
  if (cer - per >= 100)
  {
    per = cer;
    count_x++;

    if (digitalRead(!X_MIN_PIN)) toggle_stop_x = true;
    else toggle_stop_x = false;
    
    if (!toggle_stop_x) {
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
}

void move_Y_stop(unsigned long cer)
{
  if (cer - per2 >= 100)
  {
    per2 = cer;
    count_y++;
    if (!toggle_stop_y) {
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


void loop() {
  // put your main code here, to run repeatedly:
  unsigned long cer = micros();
  move_X(cer);
  move_Y(cer);
  //move_X_stop(cer);
}
