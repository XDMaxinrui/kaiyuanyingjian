#include <Keypad.h> 
void setup()
{
  
  pinMode (5, OUTPUT) ;
  pinMode (6, OUTPUT) ;
  pinMode (7, OUTPUT) ;
  pinMode (8, OUTPUT) ;
  pinMode (9, OUTPUT) ; 
  Serial.begin(9600);
       
}
void loop()
{
      digitalWrite (5, LOW) ;
      digitalWrite (6, LOW) ;
      digitalWrite (7, LOW) ;
      digitalWrite (8, LOW) ;
      digitalWrite (9, LOW) ;
  int income=0;
  while(Serial.available()>0)
  {
  
    income=Serial.read()-'0';
    if((income&1)==1)
    digitalWrite (5, HIGH) ;
      if((income>>1&1)==1)
    digitalWrite (6, HIGH) ;
      if((income>>2&1)==1)
    digitalWrite (7, HIGH) ;
      if((income>>3&1)==1)
    digitalWrite (8, HIGH) ;
    else
    digitalWrite (9, HIGH) ;
    delay(10);
}
}

