# 开源硬件课程总结
## 一丶国际双创周开源硬件课程参与情况
## 第一天：入门介绍
1.提供了基本的学习软件如frizting,processing,Github.

2.介绍了Arduino硬件

3.提出了开源硬件最重要的学习方法——自学及资源共享的思想。

第一天的作业是下载了三个软件及建立Github代码仓

[image](https://github.com/XDMaxinrui/Original-hardware/tree/master/%E7%94%A8%E5%88%B0%E7%9A%84image)

[image](https://github.com/XDMaxinrui/Original-hardware/blob/master/%E7%94%A8%E5%88%B0%E7%9A%84image/image2.png)

[image](https://github.com/XDMaxinrui/Original-hardware/tree/master/%E7%94%A8%E5%88%B0%E7%9A%84image)

## 第二天：Arduino基本编程操作
1.介绍了Arduino编程语言并建立arduino库函数

2.介绍了串口，morse等概念

3.讲解morse库函数并通过串口接受字符转化为morse发出。
morse代码

``` #include "Arduino.h"
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
}  ```
