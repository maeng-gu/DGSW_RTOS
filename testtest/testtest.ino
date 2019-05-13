int dataPin = 10;
int clockPin = 11;
int latchPin = 12;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

}

char data1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
char data2[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void loop() {
  for (int i=0; i<8; i++) {
    digitalWrite(dataPin, data1[i]);    // insert data
    digitalWrite(clockPin, HIGH);   // shift bit
    digitalWrite(clockPin, LOW);
  }
  digitalWrite(latchPin, HIGH);   // latch로 storage register에 있던 8bit를 output pin으로 출력
  digitalWrite(latchPin, LOW);
  
  delay(1000);

  
  for (int i=0; i<8; i++) {
    digitalWrite(dataPin, data2[i]);    // insert data
    digitalWrite(clockPin, HIGH);   // shift bit
    digitalWrite(clockPin, LOW);
  }
  digitalWrite(latchPin, HIGH);   // latch로 storage register에 있던 8bit를 output pin으로 출력
  digitalWrite(latchPin, LOW);
  
  delay(1000);
}
