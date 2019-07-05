#define pin 13
#define dottime 10

void morsedot() {
  digitalWrite(pin, HIGH);
  delay(dottime);
  digitalWrite(13, LOW);
  delay(dottime);
}

void morsedash() {
  digitalWrite(pin, HIGH);
  delay(dottime * 4);
  digitalWrite(13, LOW);
  delay(dottime);
}

void morsec_space() {
  digitalWrite(pin, LOW);
  delay(dottime * 3);
}

void morsew_space() {
  digitalWrite(pin, LOW);
  delay(dottime * 7);
}

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
  String morse_incomes= ""; 
  int i, j, flag = 0;
  int n = 0; 
  while (Serial.available() > 0)
  {
    flag= 1;  
    incomes+= char(Serial.read());
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
           morse_incomes= morse_incomes+char(MORSE[int(incomes[i] - 97)][j]);
        }
      }
          if (int(incomes[i])==32)
          {morse_incomes=morse_incomes+'/';}
          else{morse_incomes=morse_incomes+' ';}
    }
    Serial.println(morse_incomes); 
    for (i = 0; morse_incomes[i]!='\0' ; i++)
    {
      if (morse_incomes[i] == '.')
      {
       morsedot();
      }
      if (morse_incomes[i]== '-')
      {
       morsedash();
      }
      if (morse_incomes[i] == ' ')
      {
       morsew_space();
      }
      if (morse_incomes[i]==  '/')
      {
       morsec_space();
      }
    }
    delay(2);
  }
}
