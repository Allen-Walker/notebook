#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class A
{
public:
  A()
  {
    cout << "A()..." << endl;
    this->p = new char[64];
    memset(this->p, 0, 64);
    strcpy(this->p, "A String..");
  }

  virtual void print()
  {
    cout << "A: " << this->p << endl;
  }

  virtual ~A()
  { //必须要写成虚函数，其子类调用析构时候才能触发多态，调用其析构函数，回收自身资源
    cout << "~A()..." << endl;
    if (this->p != NULL)
    {
      delete[] this->p;
      this->p = NULL;
    }
  }

private:
  char *p;
};

class B : public A
{
public:
  B() //此刻会触发A()
  {
    cout << "B()..." << endl;
    this->p = new char[64];
    memset(this->p, 0, 64);
    strcpy(this->p, "B String..");
  }

  virtual void print()
  {
    cout << "B: " << this->p << endl;
  }

  virtual ~B()
  {
    cout << "~B()..." << endl;
    if (this->p != NULL)
    {
      delete[] this->p;
      this->p = NULL;
    }
  }

private:
  char *p;
};

void func(A *ap)
{
  ap->print(); //在此发生多态
}

void test01()
{
  A *ap = new A;
  func(ap);
  // 如果这里直接退出函数，没有执行父类的析构函数
  delete ap; //需要自己调用delete回收对象资源
}

void test02()
{
  B *bp = new B;
  func(bp);
  // 如果这里直接退出函数，没有执行父类的析构函数
  delete bp; // 需要自己调用delete回收对象资源，此时会调用父类的析构函数
}

void test03()
{
  B bp;
  func(&bp);
  // new出来的对象需要delete，不然不会调用析构函数
  // 构造函数和析构函数需要配对
  // new和delete需要配对，不然就会内存泄露--智能指针怎么解决这个问题的？
  // 使用一个对象来管理
}

int main(void)
{
  test02();
  return 0;
}