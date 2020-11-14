int Left_motor_back=9;     //左电机后退(IN1)
int Left_motor_go=5;     //左电机前进(IN2)
int Right_motor_go=6;    // 右电机前进(IN3)
int Right_motor_back=10;    // 右电机后退(IN4)

int L = 0, R = 0;
const int SensorRight = A2;     //右循迹红外传感器(P3.2 OUT1)
const int SensorLeft = A3;      //左循迹红外传感器(P3.3 OUT2)

int SL;    //左循迹红外传感器状态
int SR;    //右循迹红外传感器状态

void setup()
{
  //初始化电机驱动IO为输出方式
  pinMode(Left_motor_go,OUTPUT); // PIN 5 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 6 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 10 (PWM)
  pinMode(SensorRight, INPUT); //定义右循迹红外传感器为输入
  pinMode(SensorLeft, INPUT); //定义左循迹红外传感器为输入
}
void run()
{
  digitalWrite(Right_motor_go,HIGH);  // 右电机前进
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,120);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  // 左电机前进
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,90);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Left_motor_back,0);
  delay(100);   //执行时间，可以调整  
}
void left()
{
  digitalWrite(Right_motor_go,HIGH);  // 右电机前进
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,120); 
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go,HIGH);   //左轮后退
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  delay(100);  //执行时间，可以调整  
}
void right()
{
  digitalWrite(Right_motor_go,HIGH);   //右电机后退
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go,HIGH);//左电机前进
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,90); 
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  delay(100);  //执行时间，可以调整  
}
void loop()
{ 
  //有信号为LOW  没有信号为HIGH
  SR = digitalRead(SensorRight);//有信号表明在白色区域，车子底板上L3亮；没信号表明压在黑线上，车子底板上L3灭
  SL = digitalRead(SensorLeft);//有信号表明在白色区域，车子底板上L2亮；没信号表明压在黑线上，车子底板上L2灭
  if (SL == HIGH && SR == LOW){// 左循迹红外传感器,检测到信号，车子向右偏离轨道，向左转 
    L = 1;
    R = 0;
    left();
    //delay(1000);
  }
  else if (SR == HIGH && SL == LOW){// 右循迹红外传感器,检测到信号，车子向左偏离轨道，向右转  
    R = 1;
    L = 0;
    right();
    //delay(1000);
  }
  else if(SR == LOW&&SL == LOW)
  {
    if(R == 1){
      right();
    }
    else{
      left();
    }
  }
  else {
    L = R = 0;
    run();
    //delay(1000);
  }
}








