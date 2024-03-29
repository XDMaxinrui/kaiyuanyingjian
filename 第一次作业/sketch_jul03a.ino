#include <Morse.h>

Morse morse(13);

char MORSE[][4] = {
  {'.', '-', '*', '*'}, 
  {'-', '.', '.', '.'},
  {'-', '.', '-', '.'}, 
  {'-', '.', '.', '*'}, 
  {'.', '*', '*', '*'}, 
  {'.', '.', '-', '.'}, 
  {'-', '-', '.', '*'},
  {'.', '.', '.', '.'},
  {'.', '.', '*', '*'},
  {'.', '-', '-', '-'},
  {'-', '.', '-', '*'},
  {'.', '-', '.', '.'},
  {'-', '-', '*', '*'},
  {'-', '.', '*', '*'},
  {'-', '-', '-', '*'},
  {'.', '-', '-', '.'},
  {'-', '-', '.', '-'},
  {'.', '-', '.', '*'},
  {'.', '.', '.', '*'},
  {'-', '*', '*', '*'},
  {'.', '.', '-', '*'},
  {'.', '.', '.', '-'},
  {'.', '-', '-', '*'},
  {'-', '.', '.', '-'},
  {'-', '.', '-', '-'},
  {'-', '-', '.', '.'} 
};
void setup()
{
     Serial.begin(9600); 
}
void loop() //main函数
{
  String incomes = "";  
  String morse_str= ""; 
  int n=0; 
  int i, j, flag = 0;
  
  if(Serial.available() > 0)
  {
    flag= 1;  
    incomes=incomes+char(Serial.read());
    n++;
   delay(2);
  }

  if (flag)
  {
    for (i = 0; i < n; i++)
    {
       if (incomes[i] >96 && incomes[i] < 123) 
      {
         for (j= 0; j < 4; j++)
        {
           morse_str= morse_str+char(MORSE[int(incomes[i] - 97)][j]);
        }
      }
          if (int(incomes[i])==32)
          {morse_str=morse_str+'/';}
          else{morse_str=morse_str+' ';}
    }
    Serial.println(morse_str); 
    for (i = 0; morse_str[i]!='\0' ; i++)
    {
      if (morse_str[i] == '.')
      {
       morse.dot();
      }
      if (morse_str[i] == '-')
      {
       morse.dash();
      }
      if (morse_str[i] == ' ')
      {
       morse.w_space();
      }
      if (morse_str[i] ==  '/')
      {
       morse.c_space();
      }
    }
    delay(2);
  }
}
