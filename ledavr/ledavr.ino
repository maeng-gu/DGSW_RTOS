int count;
bool flag;
void setup() {
  TCCR1A = 0x00;
  TCCR1B = 0x0C;
  TCCR1C = 0x00;
  OCR1A = 62500;
  TIMSK1 = 0x02;
  pinMode(13, OUTPUT);
}

SIGNAL(TIMER1_COMPA_vect)
{
    if (flag) {
      digitalWrite(13, 1);
      flag = false;
    }
    else {
      digitalWrite(13, 0);
      flag = true;
    }
}


void loop() {
  
}
