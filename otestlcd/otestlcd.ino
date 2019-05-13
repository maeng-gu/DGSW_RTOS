
#define RS 3
#define RW 4
#define E 5

unsigned long remocon_micro;
unsigned long offset_value[50];
unsigned int remocon_array[50];
bool remocon_callback;
int count, result;
unsigned char inst_settings[] = { 0x3,0x3,0x3,0x2,0x2,0x8,0x0,0x6,0x0,0xC,0x8,0x0 };
unsigned char data_settings[10][2] = { {0x3,0x1},{0x3,0x2},{0x3,0x3},{0x3,0x4},{0x3,0x5},{0x3,0x6},{0x3,0x7},{0x3,0x8},{0x3,0x9},{0x4,0xF}};

String data_map[] = {
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

void start_init() {
  for (int i = 0; i < 13; i++)
  {
    digitalWrite(RS, 0);
    digitalWrite(RW, 0);

    for (int j = 3; j >= 0; j--) {
      if (inst_settings[i] & (0x01 << j)) {
        digitalWrite(j + 10, 1);
        Serial.print("1");
      }
      else {
        digitalWrite(j + 10, 0);
        Serial.print("0");
      }

      digitalWrite(E, 1);
      digitalWrite(E, 0);

      digitalWrite(RS, 1);
      digitalWrite(RW, 1);
    }
  }
}

void start_data(int result) {
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(RS, 1);
    digitalWrite(RW, 0);

    for (int j = 3; j >= 0; j--) {
      if (data_settings[result][i] & (0x01 << j)) {
        digitalWrite(j + 10, 1);
        Serial.print("1");
      }
      else {
        digitalWrite(j + 10, 0);
        Serial.print("0");
      }

      digitalWrite(E, 1);
      digitalWrite(E, 0);

      digitalWrite(RS, 1);
      digitalWrite(RW, 1);
    }
    delayMicroseconds(100);
  }
}

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0, remocon_ISR, FALLING);
  for (int i = 3; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200);
  start_init();
}


void loop() {
  // put your main code here, to run repeatedly:
  if (remocon_callback == true)
  {
    String str = "";
    remocon_callback = false;
    for (int i = 18; i <= 25; i++) {
      if (offset_value[i] > 2000)
      {
        str += "1";
      }
      else {
        str += "0";
      }
    }
    for (int j = 0; j < 10; j++)
    {

      if (data_map[j] == str)
      {
        Serial.println(String(j));
        result = j - 1;
        start_data(result);
        
      }
    }
  }


}

void remocon_ISR()
{
  remocon_micro = micros();
  remocon_array[count] = remocon_micro;

  // input data
  if (count > 0)
    offset_value[count] = remocon_array[count] - remocon_array[count - 1];

  // 13.5ms
  if (offset_value[count] > 13000 && offset_value[count] < 14000)
    count = 1;

  // 11.5ms
  if (offset_value[count] > 11000 && offset_value[count] < 12000) {
    count = -1;
  }

  //callback
  count++;
  if (count > 33)
  {
    count = 0;
    remocon_callback = true;
  }
}
