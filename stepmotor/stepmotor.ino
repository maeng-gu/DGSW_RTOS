#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38
#define X_MIN_PIN 3
#define X_MAX_PIN 2

#define Y_STEP_PIN 60
#define Y_DIR_PIN 61
#define Y_ENABLE_PIN 56
#define Y_MIN_PIN 14
#define Y_MAX_PIN 15

#define Z_STEP_PIN 46
#define Z_DIR_PIN 48
#define Z_ENABLE_PIN 62
#define Z_MIN_PIN 18
#define Z_MAX_PIN 19

#define E_STEP_PIN 26
#define E_DIR_PIN 28
#define E_ENABLE_PIN 24

void setup() {
  // put your setup code here, to run once:
  pinMode(Y_ENABLE_PIN,OUTPUT); // 0작동 1멈춤
  pinMode(Y_STEP_PIN,OUTPUT); // 500ms마다 신호를 줌 pwm
  pinMode(Y_DIR_PIN,OUTPUT); // 방향
  digitalWrite(Y_ENABLE_PIN,0);
  digitalWrite(Y_DIR_PIN,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(Y_STEP_PIN,1);
  delayMicroseconds(500);
  digitalWrite(Y_STEP_PIN,0);
  delayMicroseconds(500);
}
