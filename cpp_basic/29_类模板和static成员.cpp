#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class T>
class Person
{
public:
  static int a;
};

//类外初始化
template <class T>
int Person<T>::a = 0;

/* 	
当编译器看⻅A<int>被调用用,将执行二次编译,生成如下的类A
class A
{
public:
  static int s_value;
};
int A::s_value = 0;
*/
/* 	
当编译器看⻅A<char>被调用用,将执行二次编译,生成如下的类A
class A
{
public:
  static int s_value;
};
int A::s_value = 0;
*/	

int main(void)
{

  Person<int> p1, p2, p3;
  Person<char> pp1, pp2, pp3;

  p1.a = 10;
  pp1.a = 100;

  cout << p1.a << " " << p2.a << " " << p3.a << endl;
  cout << pp1.a << " " << pp2.a << " " << pp3.a << endl;
  //通过以上结果,说明a1,a2,a3是属于A<int>家族的他们共享A<int>::s_value;	
  //b1,b2,b3是属于A<char>家族的他们共享A<char>::s_value;	
  
  return 0;
}
