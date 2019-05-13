unsigned long previousMillis=0;
unsigned long previousMillis2=0;
int toggle=0;
int toggle2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if(currentMillis-previousMillis >= 1000){
    previousMillis = currentMillis;
    if(toggle==0){
      toggle=1;
      Serial.println("1 : UP");
      Serial.println(previousMillis);
    }
    else{
      toggle=0;
      Serial.println("1 : DOWN");
    }
  }
  if(currentMillis-previousMillis2 >= 500){
    previousMillis2 = currentMillis;
    if(toggle2==0){
      toggle2=1;
      Serial.println("2 : UP");
    }
    else{
      toggle2=0;
      Serial.println("2 : DOWN");
    }
  }
}
