//void goAhead(){
//  pinMode(A0,OUTPUT);
//  digitalWrite(A0,LOW);
//  pinMode(A1,OUTPUT);
//  digitalWrite(A1,HIGH);
//  pinMode(A2,OUTPUT);
//  digitalWrite(A2,HIGH);
//  pinMode(A3,OUTPUT);
//  digitalWrite(A3,LOW);
//  analogWrite(3,120);
//  analogWrite(5,120);
//}
//void goBack(){
//  pinMode(A0,OUTPUT);
//  digitalWrite(A0,HIGH);
//  pinMode(A1,OUTPUT);
//  digitalWrite(A1,LOW);
//  pinMode(A2,OUTPUT);
//  digitalWrite(A2,LOW);
//  pinMode(A3,OUTPUT);
//  digitalWrite(A3,HIGH);
//  analogWrite(3,120);
//  analogWrite(5,120);
//}
//void turnLeft(){
//  pinMode(A0,OUTPUT);
//  digitalWrite(A0,HIGH);
//  pinMode(A1,OUTPUT);
//  digitalWrite(A1,LOW);
//  pinMode(A2,OUTPUT);
//  digitalWrite(A2,LOW);
//  pinMode(A3,OUTPUT);
//  digitalWrite(A3,HIGH);
//  analogWrite(3,0);
//  analogWrite(5,120);
//}
//void turnRigt(){
//  pinMode(A0,OUTPUT);
//  digitalWrite(A0,LOW);
//  pinMode(A1,OUTPUT);
//  digitalWrite(A1,HIGH);
//  pinMode(A2,OUTPUT);
//  digitalWrite(A2,HIGH);
//  pinMode(A3,OUTPUT);
//  digitalWrite(A3,LOW);
//  analogWrite(3,120);
//  analogWrite(5,0);
//}
//============================亚博智能===========================
//  智能小车前进实验
//===============================================================

int Left_motor_go=6;     //左电机前进(IN2)
int Left_motor_back=9;     //左电机后退(IN1)

int Right_motor_go=10;    // 右电机前进(IN3)
int Right_motor_back=11;    // 右电机后退(IN4)

void setup()
{
  //初始化电机驱动IO为输出方式
  pinMode(Left_motor_go,OUTPUT); // PIN 8 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 10 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 11 (PWM)
  pinMode(5,INPUT);
  pinMode(2,INPUT);
}
void runway1()     // 前进
{
  digitalWrite(Right_motor_go,HIGH);  // 右电机前进
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,70);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  // 左电机前进
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,70);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Left_motor_back,0);
}
void run()
{
  digitalWrite(Right_motor_go,HIGH); 
  delay(500);
  digitalWrite(Left_motor_go,HIGH); 
  delay(500);
  }
void runway2(int time)     // 后退
{
  digitalWrite(Right_motor_go,LOW);  // 右电机前进
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Right_motor_back,100);
  digitalWrite(Left_motor_go,LOW);  // 左电机前进
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Left_motor_back,100);
  delay(time * 100);
}

void runwayL()     // 左转
{
  digitalWrite(Right_motor_go,HIGH);  // 右电机前进
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,70);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  // 左电机前进
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,60);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Left_motor_back,0);
}

void runwayR(){//右转
  digitalWrite(Right_motor_go,HIGH);  // 右电机前进
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,60);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  // 左电机前进
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,70);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Left_motor_back,0);
}
void loop() {
   if (!digitalRead(5)){
    runwayR();
    delay(10);
  }
   if (!digitalRead(2)){
    runwayL();
    delay(10);
  }
  runway1();
}
