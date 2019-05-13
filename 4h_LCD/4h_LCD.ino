char flag = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0);
  if(a<100&a>85){
    if(flag == 0){
      Serial.println("LEFT");
      flag=1;
    }
  }
  if(a<710&a>690){
    if(flag == 0){
      Serial.println("UP");
      flag=1;
    }
  }
  if(a<340&a>320){
    if(flag == 0){
      Serial.println("CENTER");
      flag=1;
    }
  }
  if(a<190&a>170){
    if(flag == 0){
      Serial.println("DOWN");
      flag=1;
    }
  }
  if(a<520&a>500){
    if(flag == 0){
      Serial.println("RIGHT");
      flag=1;
    }
  }

  if(a>1000){
    flag=0;
  }
}
