#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void swapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapChar(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

/*模板技术 类型参数化 编写代码可以忽略类型*/
/*为了让编译器区分是普通函数  模板函数*/
template <class Type> /*告诉编译器 下面是模板函数*/
void swapTemplate(Type &a, Type &b)
{
	cout << "swapTemplate called!" << endl;
	Type temp = a;
	a = b;
	b = temp;
}

int main()
{
	{
		int a = 10;
		int b = 20;
		swapInt(a, b);
		cout << "a:" << a << " b:" << b << endl;
	}
	{
		char a = 'a';
		char b = 'b';
		swapChar(a, b);
		cout << "a:" << a << " b:" << b << endl;
	}
	{
		int a = 10;
		int b = 20;
		/*1 自动类型推导*/
		swapTemplate(a, b); /*编译器根据你传的值 进行类型自动推导*/
		cout << "a:" << a << " b:" << b << endl;
		/*2. 显式的指定类型*/
		swapTemplate<int>(a, b);
		cout << "a:" << a << " b:" << b << endl;
	}
	return 0；
}
