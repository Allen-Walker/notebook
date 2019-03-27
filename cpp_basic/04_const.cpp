#include <iostream>

class A
{
public:
  const int func() const
  {
    //第一个const
    //修饰返回值，表示返回值不能被修改，即不能作为左值

    //第二个const
    //m_a=1;
    //assignment of member ‘A::m_a’ in read-only object
    //此时const修饰的是this指针，this指针原本是A* const类型的，现在则为 const A* const
    //即this为 常量类型的常量指针
    return m_a;
  }
  int m_a;
};

void test01()
{
  //const 定义常量 意味只读
  //const int a=0 类似 #define a 0
  //const int a=0 编译器处理，提供类型检查和作用域检查
  //#define a 0   宏定义由预处理器处理,单纯的文本替换

  const int a = 0;
  int const b = 0;
  //第一一个第二个意思一样 代表一个常整形数 必须进行初始化

  const int *c;
  int x = 0;
  c = &x;
  //第三个c是一个指向常整形数的指针(所指向的内存数据不能被修改, 但是本身身可以修改)——常量指针

  int y = 0;
  int *const d = &y;
  *d = 10;
  //第四个d常指针(指针变量不能被修改, 但是它所指向内存空间可以被修改)——指针常量

  int tmp = 0;
  const int *const e = &tmp;
  //第五个e指向常整形的常指针(指针和它所指向的内存空间, 均不能被修改)
}

int main(void)
{
  test01();
  return 0;
}
