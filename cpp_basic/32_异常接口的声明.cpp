#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//void func() throw(A, B, C, D); //这个函数func()能够且只能抛出类型A B C D 及其子类型的异常。
//这个函数只能抛出int float char三种类型异常，抛出其他的就报错
// void func() throw(int, float, char)
// {//warning: dynamic exception specifications are deprecated in C++11
//   throw "abc";
// }

//不能抛出任何异常
void func02() throw()
{
  throw - 1;
}

//可以抛出任何类型异常
void func03()
{
}

int main(void)
{
  try
  {
    func03();
  }
  catch (char *str)
  {
    cout << str << endl;
  }
  catch (int e)
  {
    cout << "异常!" << endl;
  }
  catch (...)
  { //捕获所有异常
    cout << "未知类型异常！" << endl;
  }

  return 0;
}