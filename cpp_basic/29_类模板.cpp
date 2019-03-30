#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//类的类型参数化
//单个模板类
template <class T>
class Person
{
public:
  Person(T age)
  {
    m_age = age;
  }
  void Show()
  {
    cout << "m_age:" << m_age << endl;
  }

public:
  T m_age;
};

//基本语法
void test01()
{
  //调用时候进行自动推导
  Person<int> person(10);
  person.Show();
}

//类模板做函数参数
void print(Person<int> &person)
{
  person.Show();
}

void test02()
{
  Person<int> p1(10), p2(20), p3(30);
  print(p1);
  print(p2);
  print(p3);
}

int main(){
  test01();
  test02();
  return 0;
}
