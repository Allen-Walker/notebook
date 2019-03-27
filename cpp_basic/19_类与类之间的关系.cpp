#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class A
{
public:
  void func()
  {
    cout << "funcA" << endl;
  }
  int a;
};

//类B拥有类A的成员变量，B has A
class B
{
public:
  void funcB()
  {
  }
  A a;
};

//类C的成员方法需要类A的形参， C use A
class C
{
public:
  void funcC(A *a)
  {
  }

  void funcC2()
  {
  }
};

//D继承与A  D is A
class D : public A
{
public:
  void funcD()
  {
    cout << this->a << endl;
  }
};

class E : public D
{
};

int main(void)
{

  return 0;
}