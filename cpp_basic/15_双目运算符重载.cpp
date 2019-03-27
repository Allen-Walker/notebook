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

  //友元函数 全局方式
	friend Complex &operator-=(Complex &c1, Complex &c2);

  //成员函数 局部方式
	Complex &operator+=(Complex &another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}
private:
	int a;//实数
	int b;//虚数
};

Complex &operator-=(Complex &c1, Complex &c2)
{
	c1.a -= c2.a;
	c1.b -= c2.b;

	return c1;
}

void test01()
{
	Complex c1(1, 2);
	Complex c2(2, 4);

	//(c1 += c2)+=c2;
	//c1.operator+=(c2).operator+=(c2);

	c1.printComplex();
	c2.printComplex();

	c1 -= c2;
	c1.printComplex();
}

void test02()
{
	Complex c1(1, 2);
	Complex c2(2, 4);

	(c1 -= c2)-=c2;

	c1.printComplex();
	c2.printComplex();
}

int main(void)
{
	test02();
	return 0;
}