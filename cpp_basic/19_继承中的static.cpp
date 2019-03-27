#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class A
{
public:
  static int a;

private:
};

class B : public A
{
public:
private:
};

int A::a = 100; //静态成员变量 初始化

int main(void)
{
  A a1;
  A a2;

  cout << a1.a << endl;
  cout << a2.a << endl;

  A::a = 300;

  cout << a1.a << endl;
  cout << a2.a << endl;
  // 同一类中静态成员变量为所有类对象共享

  if (&a1.a == &a2.a)
  {
    // cout << &a1 << endl;
    // cout << &a2 << endl;

    // cout << &a1.a << endl;
    // cout << &a2.a << endl;

    cout << "同一类中静态成员变量为所有类对象共享" << endl;
  }

  B b1;
  B b2;
  A::a = 400;

  cout << "------" << endl;
  cout << b1.a << endl;
  cout << b2.a << endl;
  cout << a1.a << endl;
  cout << a2.a << endl;
  // 子类对象和父类对象一样，共享父类的静态成员变量

  return 0;
}