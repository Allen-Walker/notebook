#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//void 和 void* 一点关系都没有 后者为万能指针

class A
{
public:
	A()
	{
		cout << "A()..." << endl;
	}
	A(int a) {
		cout << "A(int)..." << endl;
		this->a = a;
	}

	//重载的new操作符 依然会触发对象的构造函数 
  //new和malloc的区别是new会触发构造函数 同理free和delete
	void * operator new(size_t size)
	{
		cout << "重载了new操作符" << endl;
		return malloc(size);
	}

	void *operator new[](size_t size)
	{
		cout << "重载了new[]操作符" << endl;
		return malloc(size);
	}

	void operator delete(void * p)
	{
		cout << "重载了delete操作符" << endl;
		if (p != NULL) {
			free(p);
			p = NULL;
		}
	}

	void operator delete[](void *p)
	{
		cout << "重载了delete[]操作符" << endl;
		if (p != NULL) {
			free(p);
			p = NULL;
		}
	}

	~A() {
		cout << "~A().... " << endl;
	}

private:
	int a;
};

int main(void)
{
	A *arr = new A[10];
  //arr->operator new[10];
	delete[] arr;

	A *a = new A(10);
  //a->operator new(sizeof(A));
  //这里和10没有关系，重点在于怎么触发构造函数
	delete a;
	
	return 0;
}