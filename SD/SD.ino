/*
  SD card read/write
  
  This example shows how to read and write data to and from an SD card file   
  The circuit:
  * SD card attached to SPI bus as follows:
  ** MOSI - pin 11
  ** MISO - pin 12
  ** CLK - pin 13
  ** CS - pin 4
  
  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe
  
  This example code is in the public domain.
*/

#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  Serial.print("Initializing SD card...");
  pinMode(53, OUTPUT);
  
  // SD카드를 사용하기 위해서는 꼭 10번 핀을 출력모드로 설정해야 한다.
  // 아두이노 mega를 쓰시는분은 53번핀으로 바꿔준다.
  if (!SD.begin(4)) {
    Serial.println("initialization faled!");
    return;
  }
  Serial.println("initialization done.");
  // test파일을 다시 열어준다.
  myFile = SD.open("code.txt");
  
  if (myFile) {
    // test 파일의 내용을 시리얼 모니터에 출력한다.
    while (myFile.available()) { 
    Serial.write(myFile.read());
  }
  
  //파일을 닫아준다.
  myFile.close();
  
  } else {
    // 파일이 열리지 않았다면 오류 메시지를 출력
    Serial.println("error opening test.txt");
  }
}

void loop() {

}
