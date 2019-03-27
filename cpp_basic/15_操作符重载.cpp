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

  friend const Complex complexAdd(Complex &c1, Complex &c2);
  //友元重载——操作符重载写在全局
  friend const Complex operator+(Complex &c1, Complex &c2);

  const Complex complexSub(Complex &another) const
  {
    Complex temp(this->a - another.a, this->b - another.b);
    return temp;
  }

  // Complex operator+(Complex &another)
  // {
  // 	Complex temp(this->a + another.a, this->b + another.b);
  // 	return temp;
  // }//ambiguous overload for ‘operator+’ (operand types are ‘Complex’ and ‘Complex’)

  //成员重载——操作符重载写在局部
  const Complex operator-(Complex &another) const
  {
    Complex temp(this->a - another.a, this->b - another.b);
    return temp;
  }
  //Complex & operator-(Complex &another)
  //warning: reference to local variable ‘temp’ returned-->Segmentation fault (core dumped)
  //只能返回值不能返回引用

private:
  int a; //实数
  int b; //虚数
};

const Complex complexAdd(Complex &c1, Complex &c2)
{
  Complex temp(c1.a + c2.a, c1.b + c2.b);
  return temp;
}

//操作符重载写在全局
const Complex operator+(Complex &c1, Complex &c2)
{
  Complex temp(c1.a + c2.a, c1.b + c2.b);
  return temp;
}

void test01()
{
  Complex c1(1, 2);
  Complex c2(2, 3);
  
  Complex c3 = c1 + c2;
  c3.printComplex();

  c3 = c1.operator-(c2);//局部的调用方式
  c3.printComplex();
  
  c3=operator+(c1, c2);//全局的调用方式
  c3.printComplex();

  c3 = c1 - c2;
  c3.printComplex();
  //显然全局和局部的写法都是可以的，所以如果对同一符号提供全局和内部的方法，就会产生二义性

  c3 = c1 - c2 - c2;
  c3.printComplex();

  // c3 = c1 + c2 + c2;
  // c3.printComplex();
  //这种方式不支持
}

int main(void)
{
  test01(); 
  return 0;
}
