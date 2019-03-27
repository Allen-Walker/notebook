#include <iostream>
//当使用<iostream.h>时,相当于在c中调用库函数,使用的是全局命名空间,也就是早期的c++实现;
//iostream 提供一个叫命名空间的东西， 标准的命名空间是 std
//后缀为.h的头文件c++标准已经明确提出不支持了

//C中的命名空间 在C语言中只有一个全局作用域
//C语言中所有的全局标识符共享同一个作用域
//标识符之间可能发生冲突	
  
//C++中的命名空间
//命名空间将全局作用域分成不同的部分
//不同命名空间中的标识符可以同名而不会发生冲突
//命名空间可以相互嵌套
//全局作用域也叫默认命名空间

//方式二：
#if 0
using std::cout; //声明命名空间中的一个变量
using std::endl;
using std::cin;
#endif

//方式三
using namespace std;

int main(void)
{
	int a = 0;
#if 0
	//方式一：
	std::cout << "一花一世界" << std::endl;
	std::cout << "一花一世界" << std::endl;
#endif

	cout << "一花一世界" << endl;

	cin >> a;

	return 0;
}