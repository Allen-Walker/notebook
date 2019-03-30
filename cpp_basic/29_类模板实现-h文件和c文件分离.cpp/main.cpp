#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Person.h"
//#include "Person.hpp"
#include "Person.cpp"

//函数模板二次编译 会生成具体函数
int main(void)
{
  Person<int> p(10); 
  p.Show();
  // /tmp/cciQBpRZ.o：在函数‘main’中：
  // main.cpp:(.text+0x24)：对‘Person<int>::Person(int)’未定义的引用
  // main.cpp:(.text+0x30)：对‘Person<int>::Show()’未定义的引用
  // collect2: error: ld returned 1 exit status

  // 原因分析
  //.cpp文件是单独编译，使用g++ -C fileName.cpp -o fileName.o
  //发现main和Person都是没有报错的——编译时候遇到该文件中找不到的字符
  //就会在对应的位置生成一个标志，然后在链接生成可执行文件的时候，链接
  //器件就要在对应的文件中找到这些符号含义，如果没有找到，就会报错。
  //模板的编译进行二次编译，首先是模板本身的编译，第二是模板具体调用的时候会
  //编译成相应的具体实现，由于是单独编译，所以Person.cpp中不知道main.cpp
  //是否调用了模板，并没有进行第二次编译生成具体的实例。所以就有了未定义
  //错误。

  // 解决方法1
  //在Person.cpp中加上相应的调用代码。
  // 解决方法2
  //将模板的声明和定义单独写在.hpp文件中，然后在调用的文件中包含,.hpp只是为了增加可读性

  return 0;
}