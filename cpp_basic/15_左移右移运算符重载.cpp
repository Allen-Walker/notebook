#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Complex
{
public:
  Complex(int a, int b)
  {
    this->a = a;
    this->b = b;
  }

  void printComplex()
  {
    cout << "( " << this->a << ", " << this->b << "i )" << endl;
  }

  friend ostream &operator<<(ostream &os, Complex &c);
  friend istream &operator>>(istream &is, Complex &c);

  // <<操作符只能写在全局，不能够写在成员方法中。否则调用的顺序会变反，调用方式变为 c1<<cout，这种方式含义变了，至于是否使用友元函数，看看类中是否提供getter和setter。
  // ostream& operator<<(ostream &os) //c1.operator<<(cout)
  // {
  // 	os << "( " << this->a << ", " << this->b << "i )";
  // 	return os;
  // }

  // 同理，>> 操作符也不适合使用成员函数方式

private:
  int a; //实数
  int b; //虚数
};

ostream &operator<<(ostream &os, Complex &c)
{
  os << "( " << c.a << ", " << c.b << "i )";

  return os;
}

istream &operator>>(istream &is, Complex &c)
{
  cout << "a:";
  is >> c.a;
  cout << "b:";
  is >> c.b;

  return is;
}

void test01()
{
  Complex c1(1, 2);
  cin >> c1;                       //operaotr>>(cin, c1)
  cout << c1 << " " << c1 << endl; //operator<<(cout, c1);
  // 显然operator<< 必须返回cout对象才能进行上面的链式调用
}

// void test02()
// {
//   Complex c1(1, 2);
//   c1 << cout;
//   cout.operator<<(c1);
//   cout << c1 << "   " << c1 << endl;
// }

int main(void)
{
  test01();
  return 0;
}