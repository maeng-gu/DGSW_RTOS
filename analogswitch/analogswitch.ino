bool toggle31 = false;
bool toggle33 = false;
int state=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(33,INPUT);
  digitalWrite(33,HIGH);
  pinMode(31,INPUT);
  digitalWrite(31,HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
int EN2 = digitalRead(33);
//  if(toggle33 == false && EN2 == 1){
//    Serial.println("EN2 : " + String(EN2));
//    toggle33 = true;
//  }
//  if(toggle33 == true && EN2 == 0){
//    Serial.println("EN2 : " + String(EN2));
//    toggle33 = false;
//  }
//  
//  
 int EN1 = digitalRead(31);
//  if(toggle31 == false && EN1 == 1){
//    Serial.println("EN1 : " + String(EN1));
//    toggle31 = true;
//  }
//  if(toggle31 == true && EN1 == 0){
//    Serial.println("EN1 : " + String(EN1));
//    toggle31 = false;
//  }


  /* state 0 */
  if(state == 0)
  {
    if(EN1 == 0)
      state = 1;
    if(EN2 == 0)
      state = 11;
    
  }

  /* right */
  if(state == 1)
  {
    if(EN2 == 0)
      state = 2;
    if(EN1 == 1)
      state = 0;
  }
  if(state == 2)
  {
    if(EN1 == 1 && EN2 == 0)
      state = 3;
  }
  if(state == 3)
  {
    if(EN1 == 1 && EN2 == 1)
    {
      state = 0;
      Serial.println("right");
    }
  }

  /* left */
  if(state == 11)
  {
    if(EN2 == 1)
      state = 0;
    if(EN1 == 0)
      state = 12;
  }
  if(state == 12)
  {
    if(EN1 == 0 && EN2 == 1)
      state = 13;
  }
  if(state == 13)
  {
    if(EN1 == 1 && EN2 == 1)
    {
      state = 0;
      Serial.println("left");
    }
  }

  
  delay(1);
}
