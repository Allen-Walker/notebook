#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// 思考：前缀++和后缀++怎么区别？使用占位符

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
	// 使用友元函数方式重载前缀++
	friend Complex &operator++(Complex &c);
	// 使用成员函数方式重载前缀--
	Complex &operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}

	// 使用友元函数方式重载后缀++,int为占位符
	const friend Complex &operator++(Complex &c, int);

	// 使用成员函数方式重载后缀--,int为占位符
	const Complex &operator--(int)
	{
		Complex tmp(this->a, this->b);
		tmp.a--;
		tmp.b--;
		return tmp;
	}

private:
	int a; //实数
	int b; //虚数
};

Complex &operator++(Complex &c)
{
	c.a++;
	c.b++;
	return c;
}

const Complex &operator++(Complex &c, int)
{
	Complex tmp(c.a, c.b);
	tmp.a++;
	tmp.b++;
	return tmp;
}

void test01()
{
	Complex c1(1, 2);
	++c1;
	++++c1; //连续使用前缀++，每次调用必须能返回改变的c1对象
	c1.printComplex();

	Complex c2(1, 2);
	--c2;
	----c2; //连续使用前缀--，每次调用必须能返回改变的c2对象
	c2.printComplex();
}

void test02()
{
	Complex c1(1, 2);
	c1++;
	// c1++++; //c1++返回const对象；如果想连续使用后缀++，每次调用必须返回非const的c1对象
	c1.printComplex();

	Complex c2(1, 2);
	c2--;
	// c2----; //c2--返回const对象；如果想连续使用后缀--，每次调用必须返回非const的c2对象
	c2.printComplex();
}

void test03()
{
	int a = 10;

	// 区别1：
	//a++++; //error: lvalue required as increment operand -- a++返回const的对象
	//++++a; //12 -- ++a 返回对象,可以进行修改

	//区别二
	cout << ++a << endl;
	cout << a++ << endl;
	cout << a << endl;
}

int main(void)
{
	test03();
	return 0;
}