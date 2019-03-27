#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class AA
{
public:
  int m_a;
  //类成员函数（非静态）隐含this指针，接受调用对象的地址
  void setA(AA *pThis, int a)
  {
    pThis->m_a = a;
  }
  void setA(int a)
  {
    this->m_a = a;
    //m_a=a;
  }
  void func1()
  {
    //this++; //this指针是一个常量 为 AA* const 类型的
    this->m_a = 100; // 由于this指向的内容可以修改，所以this 不是const AA* 类型的指针
  }
  
  void func1()const
  {
    //这里const修饰的是this指针，this指针原本是A* const类型的，
    //现在则为 const A* const,即现在this为 常量类型的常量指针
    //this->m_a = 100;
  }

};

void test01()
{
  AA a;
  a.setA(&a, 10);
  cout << a.m_a << endl;
  a.setA(100);
  cout << a.m_a << endl;
}

int main(void)
{
  test01();
  return 0;
}
