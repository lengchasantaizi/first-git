int pushButton = 10; //定义数字10 接口
void setup()
{
  Serial.begin(9600);//串口通信初始化，每秒9600
  pinMode(pushButton,INPUT);
}
void loop()
{
  int buttonState = digitalRead(pushButton);
  Serial.println(pushButton);
  delay(1000);
}
