const int enA = 5;
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;
const int enB = 6;

const int lMid = 13;
const int left = 12;
const int right = 7;
const int rMid = 3;
const int mid = 2;
const int eye = 4;
int count = 0;
int x = 0;

int obstacleDetected = false;

void setup()
{
  // Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(left, INPUT);
  pinMode(mid, INPUT);
  pinMode(right, INPUT);
  pinMode(lMid, INPUT);
  pinMode(rMid, INPUT);
  pinMode(eye, INPUT);
}
void loop()
{
  int readL = digitalRead(left);
  int readlM = digitalRead(lMid);
  int readM = digitalRead(mid);
  int readrM = digitalRead(rMid);
  int readR = digitalRead(right);
  int readY = digitalRead(eye);

  if (readY == 0 && !obstacleDetected)
  {
    obstacleDetected = true;
  }
  if (obstacleDetected)
  {
    if ((readL == 1 && readM == 0 && readR == 0) || (readL == 1 && readlM == 1 && readM == 1 && readrM == 0 && readR == 0) || (readL==1 && readM==1 && readR==0))
    {
      turnLeft();
    }
    if((readL==0 && readlM==1 && readM==1 && readrM==0 && readR==0) || (readL==0 && readlM==1 && readM==0 && readrM==0 && readR==0)){
      turnLeft();
    }
    if((readL==0 && readlM==0 && readM==1 && readrM==1 && readR==0) || (readL==0 && readlM==0 && readM==0 && readrM==1 && readR==0)){
      turnRight();
    }
    if ((readL == 0 && readM == 0 && readR == 1) || (readL == 0 && readlM == 0 && readM == 1 && readrM == 1 && readR == 1) || (readL == 0 && readM == 1 && readR == 1))
    {
      turnRight();
    }
    if (readL == 0 && readlM == 0 && readM == 1 && readrM == 0 && readR == 0)
    {
      forward();
    }
    if (readL == 0 && readlM == 0 && readM == 0 && readrM == 0 && readR == 0)
    {
      forward();
    }
    if (readL == 0 && readlM == 0 && readM == 1 && readrM == 0 && readR == 0)
    {
      forward();
    }
    if(readL==1 && readM==1 && readR==1 || readL==0 && readM==0 && readR==0 || readL==1 && readM==0 && readR==1 || readL==0 && readM==1 && readR==0){
      forward();
    }
    if (readL == 1 && readlM == 1 && readM == 1 && readrM == 1 && readR == 1 && x == 0)
    {
      forward();
      x = 1;
      delay(800);
      // stop();
    }
    if (x == 1) {
      stop();
    }
  }
}
void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB,97);
  analogWrite(enA,97);
}
void turnLeft()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}
void turnRight()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}
void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
