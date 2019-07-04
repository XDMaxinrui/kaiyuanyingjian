#include <Keypad.h> 
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void loop()
{

  while(Serial.available() > 0)
  {
    int j=5, str;//端口接受数字
    str= Serial.read()-'0';//编码转化
    while( j <= 8)
    {
      if (str % 2 == 1)
      {
        digitalWrite(j, HIGH);
      } else 
      {
        digitalWrite(j, LOW);
      }
        str /= 2;
        j=j+1;
    }
    }
  delay(10);
  }
