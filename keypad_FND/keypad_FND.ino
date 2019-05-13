int fnd[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, //0
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 0, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 1, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0},
};

int digit_select_pin[] = {19,20};
int number;
void show_digit(int num)
{
  for(int x=0;x<9;x++){
    digitalWrite(x+10,!(fnd[num][x]));
  }
}


int a[16];
int count;
bool toggle[17];
unsigned long per;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int set = 2; set < 20; set++)
  {
    if (set <= 5) pinMode(set, INPUT);
    else pinMode(set, OUTPUT);
  }
}

void loop() {
  unsigned long cur = millis();
  if (cur - per >= 10)
  {
    per = cur;
    
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(9, 0);
        digitalWrite(j + 6, 1);
        count++;
        a[i] = digitalRead(i + 2);
        if (a[i] == 1 && (!toggle[count]))
        {
          toggle[count] = true;
          Serial.println(String(count) + " :on");
          number=count;
        }
        else if (a[i] == 0 && (toggle[count]))
        {
          toggle[count] = false;
          Serial.println(String(count) + " :off");
        }
      }
    }
    count = 0;
    
    if(number>10)
    {
       digitalWrite(digit_select_pin[0],1);
       show_digit(1);
       delayMicroseconds(10);
       digitalWrite(digit_select_pin[0],0);
       digitalWrite(digit_select_pin[1],1);
       show_digit(number-10);
       delayMicroseconds(10);
       digitalWrite(digit_select_pin[1],0);
    }
    else{
      digitalWrite(digit_select_pin[0],1);
      show_digit(number);
    }
    Serial.println(number);
  }
}
