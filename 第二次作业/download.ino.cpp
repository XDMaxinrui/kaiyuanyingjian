#include <Keypad.h> 
void setup()
{
  Serial.begin(9600);
  pinMode (5, OUTPUT) ;//不接0-1引脚
  pinMode (6, OUTPUT) ;
  pinMode (7, OUTPUT) ;
  pinMode (8, OUTPUT) ;
  pinMode (9, OUTPUT) ; 
  
       
}
void loop()
{
      digitalWrite (5, LOW) ;
      digitalWrite (6, LOW) ;
      digitalWrite (7, LOW) ;
      digitalWrite (8, LOW) ;
      digitalWrite (9, LOW) ;
  int number=0;
  while(Serial.available()>0)
  {
  
    number=Serial.read()-'0';
    if((number&1)==1)
    digitalWrite (5, HIGH) ;
      if((number>>1&1)==1)
    digitalWrite (6, HIGH) ;
      if((number>>2&1)==1)
    digitalWrite (7, HIGH) ;
      if((number>>3&1)==1)
    digitalWrite (8, HIGH) ;
    else
    digitalWrite (9, HIGH) ;
    delay(10);//wait for 10ms
}
}

