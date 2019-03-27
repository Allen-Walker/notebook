/*
静态成员是属于整个类的而不是某个对象,静态成员变量只存储
一份供所有对象共用。所以在所有对象中都可以共享它。使用静态成员变量实
现多个对象之间的数据共享不会破坏隐藏的原则,保证了安全性还可以节省内存。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class AA
{
public:
  AA(int a, int b)
  {
    m_a = a;
    m_b = b;
  }

  int getC()
  {
    m_c++;
    return m_c;
  }

  //静态的成员方法
  static int &getCC()
  {
    //m_a = 0;
    //静态成员函数内部不能使用类的非静态成员
    //error: invalid use of member ‘AA::m_a’ in static member function
    return m_c;
  }

private:
  //static修饰的静态成员变量
  static int m_c;
  int m_a;
  int m_b;
};

//静态成员变量的初始化，一定在类的外边。
int AA::m_c = 100;

class BB
{
public:
  static int a;
};
int BB::a = 0;

class CC
{
};

class DD
{
public:
  int m_a;
  int m_b;
  int m_c;
  static int m_d;
};
int DD::m_d = 0;

class EE
{
public:
  int m_a;
  int m_b;
  int m_c;
  int func()
  {
    return m_a;
  }
};

class FF
{
public:
  static int m_a;
  static int func()
  {
    return m_a;
  }
  int f()const{return m_a;}//const 修饰返回值
};
int FF::m_a = 0;

void test01()
{
  AA a1(10, 20);
  AA a2(100, 200);

  cout << a1.getC() << endl; //101
  cout << a2.getC() << endl; //102

  //a1.getCC() = 200;//函数返回静态变量的引用可以作左值
  AA::getCC() = 200;

  //所有对象中都可以共享类中静态成员变量
  cout << a1.getC() << endl; //201
  cout << a2.getC() << endl; //202
}

void test02()
{
  cout << sizeof(BB) << endl;  //1
  cout << sizeof(CC) << endl;  //1
  cout << sizeof(int) << endl; //4
  //static 成员类外存储,求类大小,并不包含在内。
}

void test03()
{
  cout << sizeof(CC) << endl;  //1
  cout << sizeof(DD) << endl;  //12
  cout << sizeof(EE) << endl;  //12
  cout << sizeof(FF) << endl;  //1
  //static 成员类外存储,求类大小,并不包含在内。
}

int main(void)
{
  test01();
  cout << "---------------" << endl;
  test02();
  cout << "---------------" << endl;
  test03();
  return 0;
}

/*
总结：
类的静态成员变量：
1,static 成员变量实现了同类对象间信息共享。
2,static 成员类外存储,求类大小,并不包含在内。
3,static 成员是命名空间属于类的全局变量,存储在 data 区。
4,static 成员只能类外初始化。
5,可以通过类名访问(无对象生成时亦可),也可以通过对象访问。

类的静态成员函数：
1,静态成员函数的意义,不在于信息共享,数据沟通,而在于管理静态数据成员, 完
成对静态数据成员的封装。
2,静态成员函数只能访问静态数据成员。原因:非静态成员函数,在调用时this 指
针被当作参数传进。而静态成员函数属于类,而不属于对象,没有 this 指针。

类成员存储：
C++类对象中的成员变量和成员函数是分开存储的
成员变量：普通成员变量——存储于对象中,与struct变量有相同的内存布局和字节对齐方式
        静态成员变量——存储于全局数据区中
成员函数:存储于代码段中。
*/