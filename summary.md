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
  int i, j, flag = 0,n=0; 
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
```

### 第三天  使用Tinkercad仿真

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
  
  ## 第四天 介绍不使用库的Morse及用Tinkercad仿真
  
  作业 
  * 不使用库函数的Morse代码
  * 课程summary
  ！[Image](https://github.com/XDMaxinrui/Original-hardware/blob/master/%E7%AC%AC%E5%9B%9B%E5%A4%A9%E4%BD%9C%E4%B8%9A/MORSE.png)
 
 ```
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
  int i, j, flag = 0,n = 0; 
  if (Serial.available() > 0)
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
```
# 二、国际双创周的收益

* 了解到了Arduino 的基础知识以及掌握了许多开源硬件的必要应用和网站，为以后自己学习开源硬件打下了良好的基础

*  同时在四天的课程中体会到了自学能力对开源硬件的重要性，从开始的一头雾水到自己查资料，了解，和与同学交流，直到模拟成功的过程是这四天最重要的经历。
同时因为我是微电子学院的大一，对编程语言和电路知识都特别欠缺，所以在学习方面有点困难，经过四天的学习，在编程等方面的基础知识都有了一定的提升。

* 理解了老师强调的：开源最重要的是共享。与他人分享的过程更是一个碰撞出创意的火花的过程。在交流的过程中不仅仅解决了自己的问题，也可能有一些意料之外的收获。

# 三、意见与建议
* 首先，我觉得学校开设的国际双创周课程是对学生很有好处的。但是，它也有一些不足。我觉得，在开课之前应与教师沟通，确认课程所需要的基本工具和软件。以及一些基础知识。应为我们四天的课程有一部分时间是花在了Linux系统和Github网站上。我觉得基础的知识和工具的使用是可以通过课前的沟通让学生自己掌握。而在课上则是更加关注于知识的讲解。

* 其次我觉得应该考虑教学班的人数，我们班共计有三百多人，在第一天开课时，我甚至找不到座位，教学效果更是因为人数过多而受到影响，而且老师也说因为人数过多所以有一些活动是没法开展的。我可以理解学校因为教学资源有限所以加大课容量，但是我也希望能考虑教学效果。

* 其次，我觉得应该加强在平时学习中关于知识实践的强化，因为我们学习编程语言是只是学习了语法，并没有与硬件相结合进行实践，这导致在这次课程中我很茫然，从来都没有想过我学过的东西还能控制七段数码管。

* 最终，感谢学校和老师，给了我一个开阔视野的机会。记得老师在第一天开课就说过：我能为你们做的是帮你们打开一扇门，现在我对开源硬件已经有了一定的了解，在以后我也会继续学习它的。
