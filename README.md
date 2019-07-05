# 开源硬件课程总结
## 一丶国际双创周开源硬件课程参与情况
## 第一天：入门介绍
1.提供了基本的学习软件如frizting,processing,Github.

2.介绍了Arduino硬件

3.提出了开源硬件最重要的学习方法——自学及资源共享的思想。

第一天的作业是下载了三个软件及建立Github代码仓

![Image text](https://github.com/XDMaxinrui/Original-hardware/blob/master/%E7%94%A8%E5%88%B0%E7%9A%84image/image1.jpg)

![Image text](https://github.com/XDMaxinrui/Original-hardware/blob/master/%E7%94%A8%E5%88%B0%E7%9A%84image/image2.png)

![Image text](https://github.com/XDMaxinrui/Original-hardware/blob/master/%E7%94%A8%E5%88%B0%E7%9A%84image/image3.jpg)

## 第二天：Arduino基本编程操作
1.介绍了Arduino编程语言并建立arduino库函数

2.介绍了串口，morse等概念

3.讲解morse库函数并通过串口接受字符转化为morse发出。
morse代码

morse.cpp
```
 #include "Arduino.h"
 #include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
} 
```
```
morse.h 
ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};
#endif /*_MORSE_H*/
```
```
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
```

### 第三天

1.介绍如何使用Arduino仿真网站Tinkercad及电机的使用

2.以及使用CD4511控制7段数码管编程, 显示端口数字

作业:

1.控制小车电机

2.通过串口输入数字在数码管显示

![Image](https://github.com/XDMaxinrui/Original-hardware/blob/master/%E8%AF%BE%E5%A0%82%E4%BD%9C%E4%B8%9A/TIM%E5%9B%BE%E7%89%8720190704162009.png)

```
#include <Keypad.h> 
void forward(){
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);    
     }
void backward(){
      digitalWrite (6, HIGH) ;
      digitalWrite (5, LOW);
      digitalWrite (10, HIGH) ;
      digitalWrite(9, LOW) ;
       }

       void left(){
      digitalWrite (5, HIGH) ;
      digitalWrite(6, LOW) ;
      digitalWrite (10, HIGH) ;
      digitalWrite(9, LOW) ;
       }

       void right(){      
      digitalWrite(6, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
       }
      void stop(){
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(9, LOW);
      digitalWrite (10,LOW);
        }



void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
int income;

void loop()
{
  if(Serial.available()>0){
     income=Serial.read();
     }
     switch(income)
     {
       case 'f':
       forward();
       break;
       case 'b':
       backward();
       break;
       case'l':
       left();
       break;
       case'r':
       right();
       break;
       case's':
       stop();
       break;
   }
     
  }
  ```
  ![Image](https://github.com/XDMaxinrui/Original-hardware/blob/master/%E7%AC%AC%E4%BA%8C%E6%AC%A1%E4%BD%9C%E4%B8%9A/%E7%94%B5%E8%B7%AF.png)
  
  ```
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
  ```
  
