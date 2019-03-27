#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/* 
 * 引用可以看作一个已定义变量的别名
 * C++编译器在编译过程中使用常指针作为引用的内部实现,因此引用所占用的空间大小与指针相同。
 * 从使用的角度,引用会让人误会其只是一个别名,没有自己的存储空间。
 */

//引用作为返回值，不要返回局部变量的引用。
//warning: reference to local variable ‘a’ returned [-Wreturn-local-addr]
//返回栈变量: 不能成为其它引用的初始值(不能作为左值使用)
int &func1()
{
  int a = 10;
  cout << "in func:a=" << a << endl;
  return a;
}

//当函数返回值为引用时若返回静态变量或全局变量
//可以成为其他引用的初始值(可作为右值使用,也可作为左值使用)
int &func2()
{
  static int a = 10; //局部静态变量，初始化一次，函数退出，内存没有释放
  cout << "in func:a=" << a << endl;
  return a;
}

int main()
{
  func2()=100;    //in func:a=10
  int &a=func2(); //由于是静态区域,内存合法	//in func:a=100
  return 0;
}

