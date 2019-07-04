void setup()
{
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available() > 0)
  {
    int j, str;//端口接受数字
    str= Serial.read()-'0';//编码转化
    for (j = 5; j <= 8; j++)
    {
      if (str % 2 == 1)
      {
        digitalWrite(j, HIGH);
      } else 
      {
        digitalWrite(j, LOW);
      }
        str /= 2;
      }
    }
  }
