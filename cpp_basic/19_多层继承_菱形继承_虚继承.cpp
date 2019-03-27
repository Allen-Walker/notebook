#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//家具类
class Furniture
{
public:
	int m; //材质
};

//将父亲类继承爷爷类指定为虚继承， 防止儿子在多继承我的时候，出现爷爷中的变量会拷贝多份。
class Bed : virtual public Furniture
{
public:
	void sleep()
	{
		cout << "在床上睡觉" << endl;
	}
};

class Sofa : virtual public Furniture
{
public:
	void sit()
	{
		cout << "在沙发上休息" << endl;
	}
};

//沙发床
class SofaBed : public Bed, public Sofa
{
public:
	void SleepAndSit()
	{
		sleep();
		sit();
	}
};

int main(void)
{
	Bed b;
	b.sleep();
	cout << b.m << endl;
	cout << " ------ " << endl;

	Sofa s;
	s.sit();
	cout << s.m << endl;
	cout << " ------ " << endl;

	SofaBed sb;
	sb.SleepAndSit();
	sb.m = 123;////此时只有一个m
	cout << &sb.m << endl;
	cout << &sb.Bed::m << endl;
	cout << &sb.Sofa::m << endl;

	return 0;
}