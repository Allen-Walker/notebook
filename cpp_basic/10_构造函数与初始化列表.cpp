#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
class A{
  public:
  A(){};
  A(int a){};
  ~A(){};
};

class B{
  public:
  B(){};
  ~B(){};

  A m_a;
  // error: no matching function for call to ‘A::A()’
  // 如果A声明带参构造函数，没有显示声明无参构造函数，会报错，因为不能初始化m_a
};

class C{
  public:
  C(){};
  C(int a){};
  ~C(){};
};

int gVal=100;
class D{
  public:
  //类成员中含有一个const对象时,或者是一个引用时,他们也必须要通过成员初始化列表进行初始化
  //构造对象成员的顺序跟初始化列表的顺序无关
  //而是和成员对象的定义顺序有关
  D(C c):c(c),iVal(0),ref(gVal){
    // iVal=1;
    // int a;
    // ref=a;
    //构造函数里只能是进行赋值，而不是进行初始化
  }
  D(int a):iVal(0),ref(gVal){}
  ~D(){};

  C c;
  const int iVal; //const 常量必须马上进行初始化
  int &ref;       //引用必须马上进行初始化
  // error: uninitialized const member in ‘const int’
  // error: uninitialized reference member in ‘int&’
};

int main(void)
{
	B b;
	return 0;
}