#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory> //智能指针auto_ptr

using namespace std;

class A
{
public:
	A(int a)
	{
		cout << "A()..." << endl;
		this->a = a;
	}

	void func() {
		cout << "a = " << this->a << endl;
	}

	~A() {
		cout << "~A()..." << endl;
	}
private:
	int a;
};


class MyAutoPtr
{
public:
	MyAutoPtr(A * ptr)
	{
		this->ptr = ptr;//ptr = new A(10)
	}

	~MyAutoPtr() {
		if (this->ptr != NULL) {
			cout << "delete ptr" << endl;
			delete ptr;
			this->ptr = NULL;
		}
	}

	A* operator->()
	{
		return this->ptr;
	}


	A& operator*()
	{
		return *ptr;
	}

private:
	A *ptr;
};

void test1()
{
	auto_ptr<A> ptr(new A(10));
	//warning: ‘template<class> class std::auto_ptr’ is deprecated
	ptr->func();
	(*ptr).func();
	//智能指针会调用类的构造函数和析构函数
}


void test2()
{
	MyAutoPtr my_p(new A(10));
	my_p->func();   //my_p.ptr -> func()
	(*my_p).func(); //*ptr.func()
	//自定义智能指针会调用类的构造函数和析构函数
}

int main(void)
{
	
	test2();
	return 0;
}