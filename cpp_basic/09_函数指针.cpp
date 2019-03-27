#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//方法一:
//声明一个函数类型
typedef int(myTypeFunc)(int a, int b);
//定义一个函数指针
myTypeFunc *myfuncp = NULL;

//方法二:
//声明一个函数指针类型
typedef double (*myPTypeFunc)(double a, double b);
//定义一个函数指针
myPTypeFunc fp = NULL;

//方法三:
//定义一个函数指针 变量
float (*myVarPFunc)(float a, float b);

int func(int a, int b) { cout << "int " << (a > b ? a : b) << endl; }
float func(float a, float b) { cout << "float " << (a > b ? a : b) << endl; }
double func(double a, double b) { cout << "double " << (a > b ? a : b) << endl; }

int main()
{
  // 函数指针类型
  myTypeFunc *tf = func;
  tf(1, 2);

  // 执行函数指针类型的指针
  myPTypeFunc ptf = func;
  ptf(1.0, 2.0);

  //函数的指针变量
  myVarPFunc = func;
  myVarPFunc(1.0, 2.0);

  return 0;
}
