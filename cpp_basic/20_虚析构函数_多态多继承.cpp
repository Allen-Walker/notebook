#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class A
{
public:
  A()
  {
    cout << "construct A" << endl;
  }
  ~A()
  {
    cout << "delete A" << endl;
  }
};

class B
{
public:
  B()
  {
    cout << "construct B" << endl;
  }
  virtual ~B()
  {
    cout << "delete B" << endl;
  }
};

class C : public A, public B
{
public:
  C()
  {
    cout << "construct C" << endl;
  }
  ~C()
  {
    cout << "delete C" << endl;
  }
};

void test01()
{
  // 父类(没有定义虚析构函数)指针指向子类对象，通过父类指针释放资源
  A *pa = new C();
  delete pa;

  /*结果：
    construct A
    construct B
    construct C
    delete A
  */
}

void test02()
{
  // 父类(没有定义虚析构函数)指针指向子类对象，但是通过子类指针释放资源
  C *pc = new C();
  A *pa = pc;
  delete pc;
  /*结果：
    construct A
    construct B
    construct C
    delete C
    delete B
    delete A
  */
}

void test03()
{
  // 父类(定义虚析构函数)指针指向子类对象，通过父类指针释放资源
  B *pb = new C();
  delete pb;
  /*结果：
    construct A
    construct B
    construct C
    delete C
    delete B
    delete A
  */
  // 看来父类指针指向子类对象，父类必须要实现虚析构函数，
  // 不然delete父类指针，子类不会调用自己的虚析构函数
}

int main()
{
  test03();
  return 0;
}
