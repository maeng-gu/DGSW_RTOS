#include "gcode_sample_100.h"

void setup() {
  int i;
  
  Serial.begin(9600);

  for (i = 0; i < 100; i++) {
        Serial.print((xy_pos[i][0]-xy_pos[i-1][0]) / 0.01);
        Serial.print(", ");
        Serial.println((xy_pos[i][1]-xy_pos[i-1][1]) / 0.01);
      }

      Serial.println(" ");

      for (i = 0; i < 100; i++) {
        Serial.print(int((xy_pos[i][0] - xy_pos[i - 1][0]) / 0.01 + 0.5));
        Serial.print(", ");
        Serial.println(int((xy_pos[i][1] - xy_pos[i - 1][1]) / 0.01 + 0.5));
      }
}  

void loop() {
  
}
