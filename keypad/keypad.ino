#define ROW1 2
#define ROW2 3
#define ROW3 4
#define ROW4 5
#define COL1 6
#define COL2 7
#define COL3 8
#define COL4 9
int a,b;
bool toggle1,toggle2,toggle3,toggle4;
int asdf[16];
bool toggle[16];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ROW1,INPUT);
  pinMode(ROW2,INPUT);
  pinMode(COL1,OUTPUT);
  pinMode(COL2,OUTPUT);
}

void loop() {


  for(int i=0;i<4;i++)
  {
    
  }

  
  
  // put your main code here, to run repeatedly:
  /////////////////////////////////////////// 1
  digitalWrite(COL1,1);
  digitalWrite(COL2,0);
  a=digitalRead(ROW1);
  if(a==1&&(!toggle1))
  {
    toggle1 = true;
    Serial.println("1:on");
  }
  else if(a==0&&(toggle1))
  {
    toggle1 = false;
    Serial.println("1:off");
  }
  ///////////////////////////////////////////

  /////////////////////////////////////////// 2
  digitalWrite(COL1,0);
  digitalWrite(COL2,1);
  a=digitalRead(ROW1);
  if(a==1&&(!toggle2))
  {
    toggle2 = true;
    Serial.println("2:on");
  }
  else if(a==0&&(toggle2))
  {
    toggle2 = false;
    Serial.println("2:off");
  }
  ///////////////////////////////////////////

  /////////////////////////////////////////// 3
  digitalWrite(COL1,1);
  digitalWrite(COL2,0);
  b=digitalRead(ROW2);
  if(b==1&&(!toggle3))
  {
    toggle3 = true;
    Serial.println("3:on");
  }
  else if(b==0&&(toggle3))
  {
    toggle3 = false;
    Serial.println("3:off");
  }
  ///////////////////////////////////////////

  /////////////////////////////////////////// 4
  digitalWrite(COL1,0);
  digitalWrite(COL2,1);
  b=digitalRead(ROW2);
  if(b==1&&(!toggle4))
  {
    toggle4 = true;
    Serial.println("4:on");
  }
  else if(b==0&&(toggle4))
  {
    toggle4 = false;
    Serial.println("4:off");
  }
  ///////////////////////////////////////////
  
  delay(10);
}
