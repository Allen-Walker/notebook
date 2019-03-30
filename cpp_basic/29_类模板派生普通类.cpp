#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//类模板
template <class T>
class MyClass
{
public:
  MyClass(T a)
  {
    m_a = a;
  }
public:
  T m_a;
};

//子模板类派生时,需要具体化模板类,c++编译器要知道父类的数据类型具体是什么样的
//因为 c++编译器要分配内存,必须知道父类所占内存大小
class SubClass : public MyClass<int>
{
public:
  SubClass(int b) : MyClass<int>(20)
  {
    this->m_b = b;
  }
  void Show()
  {
    cout << "m_a:" << m_a
         << " m_b:" << m_b << endl;
  }
public:
  int m_b;
};

//基本语法
void test01()
{
  SubClass sclass(10);
  sclass.Show();
}
int main()
{
  test01();
  return 0;
}