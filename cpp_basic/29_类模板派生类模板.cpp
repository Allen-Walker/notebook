#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//类模板
//动物都有年龄这个属性，也有显示年龄这个方法
template <class T>
class Animal
{
public:
  Animal(T a)
  {
    m_age = a;
  }
  void showAge()
  {
    cout << "m_age:" << m_age << endl;
  }

public:
  T m_age;
};

//猫继承与动物这个类，不同的是猫是4条腿的动物
template <class T>
class Cat : public Animal<T>
{
public:
  Cat(T b) : Animal<T>(b)
  {
    this->m_legs = 4; //猫是4条腿的
  }

  void Show()
  {
    cout << "m_age:" << this->m_age << " "
         << "m_legs" << m_legs << endl;
    //直接m_age会报错 error: ‘m_age’ was not declared in this scope
  }
  void showLegs()
  {
    cout << "m_legs" << m_legs << endl;
  }

public:
  int m_legs;
};

//基本语法
void test01()
{
  Cat<int> cat(10);
  cat.Show();
  cat.showAge();
  cat.showLegs();
}

int main()
{
  test01();
  return 0;
}