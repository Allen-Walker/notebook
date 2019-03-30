#include <iostream>
using namespace std;

//异常基本语法
int divide(int x, int y)
{
  if (y == 0)
  {
    throw y; //抛异常
  }

  return x / y;
}

void test01()
{
  //试着去捕获异常
  try
  {
    divide(10, 0);
  }
  catch (int e) //异常时根据类型进行匹配，e是你抛出去的对象
  {
    cout << "除数不能为：" << e << "!" << endl;
  }
}

void CallDivide(int x, int y)
{
  divide(x, y);
  //没有对异常进行处理
}

void test02()
{
  try
  {
    CallDivide(10, 0);
  }
  catch (int e)
  {
    cout << "除数不能为：" << e << endl;
  }
}

int main()
{
  //test01();

  //test02();

  //CallDivide(10, 0);
  //terminate called after throwing an instance of 'int'
  //Aborted (core dumped)

  //总结：
  //将问题检测和问题处理相分离
  //异常跨函数,子函数产生的异常没有处理抛到调用函数，一层一层往上，到顶层没有处理，就会终止程序。
  //异常必须处理

  //在 C 语言的世界中,对错误的处理总是围绕着两种方法:一是使用整型的返回值
  //标识错误;二是使用 errno 宏(可以简单的理解为一个全局整型变量)去记录错误。

}
