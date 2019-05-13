int a[16];
int count;
bool toggle[17];
unsigned long per;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int set = 2; set < 10; set++)
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
        }
        else if (a[i] == 0 && (toggle[count]))
        {
          toggle[count] = false;
          Serial.println(String(count) + " :off");
        }
      }
    }
    count = 0;
  }
}
