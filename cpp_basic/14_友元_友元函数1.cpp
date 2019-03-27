/*
采用类的机制后实现了数据的隐藏与封装,类的数据成员一般定义为私有成
员,成员函数一般定义为公有的,依此提供类与外界间的通信接口。但是,有时需
要定义一些函数,这些函数不是类的一部分,但又需要频繁地访问类的数据成员,
这时可以将这些函数定义为该函数的友元函数。除了友元函数外,还有友元类,
两者统称为友元。友元的作用是提高了程序的运行效率(即减少了类型检查和
安全性检查等都需要时间开销),但它破坏了类的封装性和隐藏性,使得非成员函
数可以访问类的私有成员。
友元可以是一个函数,该函数被称为友元函数;友元也可以是一个类,该类被
称为友元类。

常见应用：
1 使用友元的方式代替类中getter和setter方法
2 使用友元的函数的方式重载运算操作符，当然使用getter和setter方法也可以进行
	这两种方式都是全局函数的方式
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
	//声明全局函数 PointDistance 是类Point类的一个友元函数。
	//这个声明可以放置在类的任何位置,可以访问类中私有变量
	friend double PointDistance(Point &p1, Point &p2);
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}
private:
	int x;
	int y;
};

//使用友元函数
double PointDistance(Point &p1, Point &p2)
{
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;

	dis = sqrt(dd_x*dd_x + dd_y *dd_y);

	return dis;
}

/*
// 不使用友元，不可以直接访问类的私有变量
double PointDistance(Point &p1, Point &p2)
{
	double dis;
	int dd_x = p1.getX() - p2.getX();
	int dd_y = p1.getY() - p2.getY();

	dis = sqrt(dd_x*dd_x + dd_y *dd_y);

	return dis;
}
*/

int main(void)
{
	
	Point p1(1, 2);
	Point p2(2, 2);

	cout << PointDistance(p1, p2) << endl;

	return 0;
}