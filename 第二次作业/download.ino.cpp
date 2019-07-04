void setup()
{
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);//不从0-1开始是因为会出现混乱
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int j, str;
  str= Serial.read()-'0';
    for (j = 5; j <= 8; j++)
    {
      if (str % 2 == 1)
      {
        digitalWrite(j, HIGH);
      } else {
        digitalWrite(j, LOW);
      }
        str /= 2;
      }
    }
  }
