/*
 Name:    RTlcd.ino
 Created: 2019-04-19 오전 10:05:10
 Author:  V3LOTTE
*/
#define RS 3
#define RW 4
#define EN 5
#define DB0 6
#define DB1 6
#define DB2 6
#define DB3 6
#define DB4 6
#define DB5 6
#define DB6 6
#define DB7 6

// the setup function runs once when you press reset or power the board
void setup() {

  for (int i = 3; i < 14; i++) {
    pinMode(i, OUTPUT);

    Serial.begin(9600);
    digitalWrite(RS, HIGH);
    digitalWrite(RW, HIGH);

  }

  digitalWrite(RS, LOW);
  digitalWrite(RW, LOW);
  //data 0x30
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);

  ///////////////////////////////


  /////////////////////////////

  digitalWrite(RS, LOW);
  digitalWrite(RW, LOW);
  //data 0x30
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);

  ///////////////////////////////

  /////////////////////////////

  digitalWrite(RS, LOW);
  digitalWrite(RW, LOW);
  //data 0x30
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);

  ///////////////////////////////

  /////////////////////////////

   //0x38 -> 00111000
  digitalWrite(RS, LOW);
  digitalWrite(RW, LOW);


  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);

  ////////////////////////////////////

  //0x06 -> 00000110
  digitalWrite(RS, LOW);
  digitalWrite(RW, LOW);


  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);

  ////////////////////////////////////////////

  //0x0C -> 00001100
  digitalWrite(RS, LOW);
  digitalWrite(RW, LOW);


  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);

  ////////////////////////////////////////////


   //0x80 -> 10000000
  digitalWrite(RS, LOW);
  digitalWrite(RW, LOW);


  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);
  //Serial.begin(9600);
}
  // the loop function runs over and over again until power down or reset
void loop() {

  /////////////////////////////

  

  /////////////////////////////////

   //0x31 -> 00110001
  digitalWrite(RS, HIGH);
  digitalWrite(RW, LOW);


  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);

  digitalWrite(EN, HIGH);
  digitalWrite(EN, LOW);

  digitalWrite(RS, HIGH);
  digitalWrite(RW, HIGH);

  delayMicroseconds(100);

  //////////////////////////////

}
