#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void)
{
  //变量的常引用
  int a = 10;
  const int &constRef = a;
  //constRef=20;// assignment of read-only reference ‘constRef’
  a = 20;

  //常量引用
  const int b = 10;
  const int &ref2Const = b;
  //ref2Const=20;// assignment of read-only reference ‘ref2Const‘
  //b=20; //assignment of read-only variable ‘b’

  double c = 3.14;
  const int &iRef = c;//等价于 int tmp = c; const int &iRef = tmp;//改变的c，不会影响iRef
  double &dRef = c;
  cout << iRef << endl;//3
  cout << dRef << endl;//3.14
  c = 2.18;
  cout << iRef << endl;//3
  cout << dRef << endl;//2.18

  //用变量初始化常引用
  int xx=10;
  const int&xxRef=xx;

  //用字面面量初始化常量引用
  const int num=20;//c++编译器把a放在符号表中	
  
  const int &numRef=30;
  //c++编译器会分配内存空间	
  //int temp = 43;
	//const int &m = temp;

  //总结
  //const int & e 相当于 const int * const e
  //普通引用 相当于 int *const e
  //当使用常量(字面量)对const引用进行初始化时,C++编译器会为常量值分配空间,并将引用名作为这段空间的别名
  //使用字面量对const引用初始化后,将生成一个只读变量

  //int *const p 指针（类型的）常量
  //const int *p 常量（类型的）指针
 
  return 0;
}
