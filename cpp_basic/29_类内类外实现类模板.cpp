#include <iostream>
using namespace std;

//1. 类模板函数写在类的内部
template <class T>
class Person01
{
public:
  Person01(T a)
  {
    m_age = a;
  }
  void Show()
  {
    cout << "m_age:" << m_age << endl;
  }

public:
  T m_age;
};

void test01()
{
  Person01<int> person(10);
  person.Show();
}

//2. 类模板函数写在类的外部
template <class T>
class Person02
{
public:
  Person02(T a);
  void Show();

public:
  T m_age;
};

template <class T>
Person02<T>::Person02(T a)
{
  m_age = a;
}

template <class T>
void Person02<T>::Show()
{
  cout << "m_age:" << m_age << endl;
}

void test02()
{
  Person02<int> person(10);
  person.Show();
}

template <class T>
class Person03
{
  //普通友元函数
  template <class T1>
  friend void PrintPerson(Person03<T1> &p); 
  //如果不加template <class T1>有些编译器编译不通过，为什么这里不能使用T呢？
  //warning: friend declaration ‘void PrintPerson(Person03<T>&)’ declares a non-template function
  //template <class T>friend void PrintPerson(Person03<T> &p); 
  //error: declaration of template parameter ‘T’ shadows template parameter

  //友元函数 左移运算符重载
  template <class T1>
  friend ostream &operator<<(ostream &cout, Person03<T1> &p); //有些编译器编译不通过

public:
  Person03(T a);
  //+号运算符重载
  Person03 operator+(Person03 &p);
  void Show();

private:
  T m_a;
};

//类的定义写在外部
template <class T>
Person03<T>::Person03(T a)
{
  this->m_a = a;
}

template <class T>
void Person03<T>::Show()
{
  cout << "m_a:" << this->m_a << endl;
}

template <class T>
Person03<T> Person03<T>::operator+(Person03<T> &p)
{
  Person03<T> person(this->m_a + p.m_a);
  return person;
}

//友元函数—左移右移运算符重载
template <class T>
ostream &operator<<(ostream &cout, Person03<T> &p)
{
  cout << p.m_a << " ";
  return cout;
}

//普通友元函数
template <class T>
void PrintPerson(Person03<T> &p)
{
  cout << p.m_a << endl;
}

void test03()
{
  Person03<int> person(10);
  cout << person << endl;
  //调用友元函数
  PrintPerson(person);
}

int main()
{
  test03();
  return 0;
}