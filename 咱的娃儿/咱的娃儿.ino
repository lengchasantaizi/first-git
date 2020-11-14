//============================车车小组===========================
//                         咱的娃成长日记
//===============================================================
//蓝牙模式初始值设定
#define STOP      48 //停止
#define RUN       49 //前进
#define BACK      50 //后退
#define SPEED_UP    51  //加速
#define SPEED_DOWM  52  //减速
#define SPEED_LEFT_UP     53 //左加速
#define SPEED_LEFT_DOWM   54 //左减速
#define SPEED_RIGHT_UP    55 //右加速
#define SPEED_RIGHT_DOWM  56 //右减速

//蓝牙加减速大小
const int speedUnit = 10;

//电机引脚初始化
int pin_Left_go = 6;       //左电机前进(IN2)
int pin_Left_back = 9;     //左电机后退(IN1)
int pin_Right_go = 10;     //右电机前进(IN3)
int pin_Right_back = 11;   //右电机后退(IN4)

//电机数值初始化
int value_Left_go = 10;   //左电机前进数值
int value_Left_back = 0;   //左电机后退数值
int value_Right_go = 10;  //右电机前进数值
int value_Right_back = 0;  //右电机后退数值

void setup()
{
  
  Serial.begin(9600);
  
  //初始化电机驱动IO为输出方式
  pinMode(pin_Left_go,OUTPUT);    // PIN 6 (PWM)
  pinMode(pin_Left_back,OUTPUT);  // PIN 9 (PWM)
  pinMode(pin_Right_go,OUTPUT);   // PIN 10 (PWM) 
  pinMode(pin_Right_back,OUTPUT); // PIN 11 (PWM)
  pinMode(2,INPUT);  //红外左
  pinMode(5,INPUT);  //红外右
}

void walk(){
  //左电机
  digitalWrite(pin_Left_go,HIGH);              
  digitalWrite(pin_Left_back,LOW);
  analogWrite(pin_Left_go,value_Left_go);       //PWM比例0~255调速，左右轮差异略增减
  analogWrite(pin_Left_back,value_Left_back);
  //右电机
  digitalWrite(pin_Right_go,HIGH);  
  digitalWrite(pin_Right_back,LOW);
  analogWrite(pin_Right_go,value_Right_go);      //PWM比例0~255调速，左右轮差异略增减
  analogWrite(pin_Right_back,value_Right_back);
}

void turnLeft(){  //左拐
  value_Left_go -= value_Left_go * 0.1;
  value_Right_go += value_Right_go * 0.1;
}
void turnRight(){ //右拐
  value_Left_go += value_Left_go * 0.1;
  value_Right_go -= value_Right_go * 0.1;
}
void goStraight(){ //直行
  value_Left_go = (value_Left_go + value_Right_go)/2;
  value_Right_go = value_Left_go;
}

//循迹模块
void tracking(){
  if(!digitalRead(2))
    turnLeft();
  else if(!digitalRead(5))
    turnRight();
  else
    goStraight();
}

//蓝牙模块
void bluetooth(){
  if(Serial.available() == 0)
    return;
  
  int cmd = Serial.read();
  switch(cmd){
    case STOP: //停止
      value_Left_go = 0;
      value_Right_go = 0;
      break;
    case RUN : //前进
      pin_Left_go = 6; 
      pin_Left_back = 9;  
      pin_Right_go = 10; 
      pin_Right_back = 11; 
      value_Left_go = 100;
      value_Right_go = 100;
      break;
    case BACK: //后退
      pin_Left_go = 9; 
      pin_Left_back = 6;  
      pin_Right_go = 11; 
      pin_Right_back = 10; 
      value_Left_go = 50;
      value_Right_go = 50;
      break;
    case SPEED_UP: //加速
      value_Left_go += speedUnit;
      value_Right_go += speedUnit;
      break;
    case SPEED_DOWM: //减速
      value_Left_go -= speedUnit;
      value_Right_go -= speedUnit;
      break;
    case SPEED_LEFT_UP:    //左加速
      value_Left_go += speedUnit;
      break;
    case SPEED_LEFT_DOWM:  //左减速
      value_Left_go -= speedUnit;
      break;
    case SPEED_RIGHT_UP:   //右加速
      value_Right_go += speedUnit;
      break;
    case SPEED_RIGHT_DOWM: //右减速
      value_Right_go -= speedUnit;
      break;
  }
  
}

int time = 0;
//显示速度
void show(){
  ++time;
  if(time % 500) return;
  
  float num = time * 0.05;
  Serial.println("------------------------------------\n");
  Serial.println(num);//第几秒电机转度
  Serial.println(value_Left_go, value_Left_back);//左转速
  Serial.println(value_Right_go, value_Right_back);//右转速
}
  
void loop() {
  //蓝牙模块
  //一共有九个功能，按输入的数字进行操作
  bluetooth();
  
  //循迹模块
  //判断是否压线，压线进行对应的操作
  //左压线，向左拐，压线时间越长，拐弯幅度越大，
  //向左拐按比例加减数值
  tracking();

  //显示速度
  show();
  
  //行动
  walk();
  delay(50);
}

