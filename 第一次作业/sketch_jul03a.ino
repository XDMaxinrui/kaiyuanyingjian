#include <Morse.h>

Morse morse(13);

char MORSE[][4] = {
 {'.', '-', '*', '*'},{'-', '.', '.', '.'},{'-', '.', '-', '.'},{'-', '.', '.', '*'},{'.', '*', '*', '*'},{'.', '.', '-', '.'},{'-', '-', '.', '*'},{'.', '.', '.', '.'},{'.', '.', '*', '*'},{'.', '-', '-', '-'},{'-', '.', '-', '*'},{'.', '-', '.', '.'},{'-', '-', '*', '*'},{'-', '.', '*', '*'}, {'-', '-', '-', '*'}, {'.', '-', '-', '.'},{'-', '-', '.', '-'}, {'.', '-', '.', '*'}，{'.', '.', '.', '*'}，{'-', '*', '*', '*'}, {'.', '.', '-', '*'}, {'.', '.', '.', '-'},{'.', '-', '-', '*'},{'-', '.', '.', '-'}，{'-', '.', '-', '-'},  {'-', '-', '.', '.'} 
};//各大写字母的摩尔斯电码字符数组

void setup()
{
    pinMode(LED_PIN,OUTPUT);     //初始化LED引脚为输出模式
    Serial.begin(9600);       //初始化串口波特率为9600
    digitalWrite(LED_PIN,OFF_LED);//初始状态LED熄灭
}

void loop() //主循环,实现串口控制LED的亮灭
{
  String str = "";  
  String morse_str= ""; 
  int i=0, j=0, flag = 0;
  int n = 0;  //对传入字符个数计数
  while (Serial.available() > 0)
  {
    flag= 1;  
    str += char(Serial.read());
    delay(2);
    n++;
  }

  if (flag)
  {
    for (i = 0; i < n; i++)
    {
      for (j= 0; j < 4; j++)
      {
           if (str[i] > 96&& str[i] <123)
        { morse_str= morse_str+char(MORSE[int(str[i] - 97)][j]);
        }
      }
           morse_str=morse_str+' ';
    }
    Serial.println(morse_str);  //串口传入
    for (i = 0; morse_str[i]!='\0' ; i++)//从头到尾读取莫尔斯电码
    {
      if (morse_str[i] == '.')
      {
       morse.dot();
      }
      else if (morse_str[i] == '-')
      {
       morse.dash();
      }
      else if (morse_str[i] == ' ')
      {
       morse.w_space();
      }
      if (morse_str[i] != ' ' && str[i] != '*')
      {
       morse.c_space();
      }
    }
    Serial.println("完成");
    delay(2);
    uart_rx_buf = 0;            //清除接收到的字符
  }
}
