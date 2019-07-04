void setup()
{
  
  pinMode(5, OUTPUT);//不能从0-1开始，应为会出现混乱
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int j, str;
    str= Serial.read()-'0';
    for (j= 5; j<= 8; j++)
    {
      if (str % 2 == 1)
      {
        digitalWrite(j, HIGH);
      } 
      else if 
      {
        digitalWrite(j, LOW);
      }
        number/= 2;
      }
    }
  }

