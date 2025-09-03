#define enA 5
#define enB 6
#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define right 7
#define middle 2
#define left 12
#define midright 3
#define midleft 13
#define vatCan 4
int speedA;
int speedB;
int check=0;
int checkVatCan=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(middle,INPUT);
  pinMode(right,INPUT);
  pinMode(left,INPUT);
  pinMode(midleft,INPUT);
  pinMode(midright,INPUT);
  pinMode(vatCan,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int readvatCan=digitalRead(vatCan);
  int readRight=digitalRead(right);
  int readLeft=digitalRead(left);
  Serial.println(readLeft);
  int readmiddle=digitalRead(middle);
  int readmidleft=digitalRead(midleft);
  int readmidright=digitalRead(midright);
  if(readvatCan==0){
    checkVatCan=1;
  }
  if(checkVatCan==0){
    stop();
  }
  if(check==0 && checkVatCan==1){
  if(readLeft==1 && readmiddle==0 && readRight==0 || readLeft==1 && readmiddle==1 && readRight==0){
    turnLeft();
  }
  if(readLeft==0 && readmiddle==0 && readRight==1 || readLeft==0 && readmiddle==1 && readRight==1){
    turnRight();
  }
  if(readLeft==1 && readmiddle==0 && readRight==1 || readLeft==0 && readmiddle==1 && readRight==0 || readLeft==0 && readmiddle==0 && readRight==0 || readLeft==1 && readmiddle==1 &&  readRight==1 ){
    forward();
  }
  if(readLeft==1 && readmidleft==1 && readmidright==1 && readRight==1){
    forward();
  }
  if( readLeft==0 && readmidleft==1 && readmiddle==1 && readmidright==0 && readRight==0|| readLeft==0 && readmidleft==1 && readmiddle==0 && readmidright==0 && readRight==0 || readLeft==1 && readmidleft==1 && readmiddle==0 && readmidright==0 && readRight==0 || readLeft==1 && readmidleft==1 && readmiddle==1 && readmidright==0 && readRight==0){
    turnLeft();
  }
  if( readLeft==0 && readmidleft==0 && readmiddle==1 && readmidright==1 && readRight==0 || readLeft==0 && readmidleft==0 && readmiddle==0 && readmidright==1 && readRight==0 || readLeft==0 && readmidleft==0 && readmiddle==0 && readmidright==1 && readRight==1 || readLeft==0 && readmidleft==0 && readmiddle==1 && readmidright==1 && readRight==1){
    turnRight();
  }
  }
  if(readLeft==1 && readmidleft ==1 && readmiddle==1 && readmidright==1 && readRight==1 && check==0){
    forward();
    delay(1450);
    stop();
    check=1;
  }
}
void forward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enA,110);
  analogWrite(enB,110);
}
void turnRight(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enA,235);
  analogWrite(enB,235);
}
void turnLeft(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enA,235);
  analogWrite(enB,235);
}
void turnrightnhe(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enA,0);
  analogWrite(enB,100);
}
void turnleftnhe(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enA,100);
  analogWrite(enB,0);
}
void stop(){
  analogWrite(enA,0);
  analogWrite(enB,0);
}