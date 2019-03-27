#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
public:
	int a; 
	// 使用域名操作符，子类中使用Parent::a，访问父类a，this->a访问子类a。
private:
	int b; 
	//子类和父类成员重名，对于private成员父类需要构造getter和setter方法，子类才能访问
};

class Child : public Parent
{
public:
	Child(int p_a, int c_a) : Parent(p_a)//显示调用父类的构造函数，可以设置父类的私有成员
	{
		this->a = c_a;
	}

	void print()
	{
		cout << Parent::a << endl;
		cout << this->a << endl; //child's a
	}
	int a;
};

int main(void)
{
	Child c(10, 100);
	c.print();

	return 0;
}