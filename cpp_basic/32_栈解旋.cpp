#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
public:
  Person()
  {
    cout << "对象构建!" << endl;
  }
  ~Person()
  {
    cout << "对象析构!" << endl;
  }
};

int divide(int x, int y)
{

  Person p1, p2;

  if (y == 0)
  {
    cout << "抛出异常之前对象就被虚构了" << endl;
    /*
      异常被抛出后,从进入try块起,到异常被抛掷前,这期间在栈上的构造的所有对象,都会被自动析构。
      析构的顺序与构造的顺序相反。这一过程称为栈的解旋。
    */
    throw y; //相当于return，下面语句不会执行
    cout << "异常被抛出" << endl;
  }
  return x / y;
}

void test01()
{

  try
  {
    cout << "进入try" << endl;
    Person p1, p2;
    cout << "进入异常函数" << endl;
    divide(10, 0);
  }
  catch (int e)
  {
    cout << "异常捕获！" << endl;
  }
}

int main(void)
{
  test01();
  return 0;
}