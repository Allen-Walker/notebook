#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person
{
public: //公有 对象内部-可访问 对象外部-可访问
  string m_name;
  int m_sex;
  Person(){}; //默认构造函数
  Person(string name, int sex)
  {
    m_name = name;
    m_sex = sex;
  }

  ~Person(){};

  void printInfo()
  {
    cout << "name = " << m_name << endl;
    cout << "sex = " << m_sex << endl;
  }

protected: //保护 对象内部-可访问 对象外部-不可访问
  int m_age;
  int showAge()
  {
    cout << "m_age" << m_age << endl;
  }

private: //私有 对象内部-可访问 对象外部-不可访问
  int m_money;
  int showMoney()
  {
    cout << "m_money" << m_money << endl;
  }
};

int main(void)
{
  Person xiaohong;//调用无参构造函数
  cout << xiaohong.m_name << endl; //空
  cout << xiaohong.m_sex << endl;  //乱码

  Person *xiaoming = new Person("小明", 1);

  cout << xiaoming->m_name << endl;
  cout << xiaoming->m_sex << endl;

  //cout << xiaoming->m_age << endl;
  // error: ‘int Person::m_age’ is protected within this context
  //cout << xiaoming->m_money << endl;
  // error: ‘int Person::m_money’ is private within this context

  return 0;
}