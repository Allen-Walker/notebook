#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void func1(int a, int b, int c = 100, int d = 1000)
{
  cout << a << " " << b << " " << c << " " << d << endl;
  /*
  在默认参数规则,如果默认参数出现,那么右边的都必须有默认参数
  */
}

void func2(int a, int b, int, int=0)
{
  cout << a << " " << b << endl;
  /*
   占位参数只有参数类型声明,而没有参数名声明
   一一般情况下,在函数体内部无法使用用占位参数
  */
}

int main()
{
  func1(1, 10);
  func2(1, 10, 100, 1000);
  return 0;
}