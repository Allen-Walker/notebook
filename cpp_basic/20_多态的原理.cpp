/*
虚函数表和vptr指针
  1 当类中声明虚函数时,编译器会在类中生成一个虚函数表;
  2 虚函数表是一个存储类成员函数指针的数据结构;
  3 虚函数表是由编译器自动生成与维护的;
  4 virtual成员函数会被编译器放入虚函数表中,子类继承了父类，并重写父类虚函数，
   也会默认将该函数加入自身的虚函数表中，无论是否重写的时候显示指定重写的函数为
   virtual。
  5 类中存在虚函数时,每个类实例对象中都有一个指向虚函数表的指针(vptr指针)，发送
   多态时候，默认优先搜索父类对象所指向子类对象的虚函数表。

说明:
1. 通过虚函数表指针VPTR调用重写函数是在程序运行时进行的,因此需要通
  过寻址操作才能确定真正应该调用的函数。而普通成员函数是在编译时就确
  定了调用的函数。在效率上,虚函数的效率要低很多。
2.出于效率考虑,没有必要将所有成员函数都声明为虚函数.
3.C++编译器,执行run函数,不需要区分是子类对象还是父类对象,而是直接
  通过p的VPTR指针所指向的对象函数执行即可。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Parent
{
public:
  Parent(int a)
  {
    this->a = a;
  }

  virtual void func(int a)
  {
    cout << "Parent::func(int)..." << endl;
  }

  virtual void func(int a, int b, int c)
  {
    cout << "Parent::func(int ,int ,int )...." << endl;
  }

private:
  int a;
};

class Child : public Parent
{
public:
  Child(int a, int b) : Parent(a)
  {
    this->b = b;
  }
  virtual void func(int a)
  {
    cout << "Child: func(int)..." << endl;
  }

  void func(int a, int b)
  {
    cout << "Child :func(int ,int )..." << endl;
  }

  virtual void func(int a, int b, int c)
  {
    cout << "Child ::func(int ,int ,int )..." << endl;
  }

private:
  int b;
};

void myFunc(Parent *pp)
{
  pp->func(10);
}

int main(void)
{
  //Parent *pp = new Parent(10);
  //Parent *cp = new Child(100, 200);

  Parent *pp = new Child(100, 200);

  pp->func(10); //Parent ？ Child
                //如果调用一个普通函数，编译器根本就不会查找虚函数表。
                //只有你调用的函数，是虚函数的时候，才会去查找虚函数表

  pp->func(10, 20, 30);

  return 0;
}