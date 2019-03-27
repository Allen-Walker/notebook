/*
重载规则：
函数名相同
参数个数不同,参数的类型不同,参数顺序不同,均可构成重载
返回值类型不同则不可以构成重载
*/
/*
调用规则
严格匹配,找到则调用。
通过隐式转换寻求一个匹配,找到则调用。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int func(int a, int b) { cout << "int " << (a > b ? a : b) << endl; }
float func(float a, float b) { cout << "float " << (a > b ? a : b) << endl; }
double func(double a, double b) { cout << "double " << (a > b ? a : b) << endl; }
//int func(int a, int b, int c = 0) { cout << "int " << (a > b ? a : b) << endl; } 
//error: call of overloaded ‘func(int, int)’ is ambiguous

int main()
{
  func(1, 2);     //int 2
  func(1.0, 2.0); //double 2
  return 0;
}
