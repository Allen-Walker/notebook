/*
  stack是一种先进后出(first in last out,FILO)的数据结构，它只有一个出口，
  stack只允许在栈顶新增元素，移除元素，获得顶端元素，但是除了顶端之外，其他地
  方不允许存取元素，只有栈顶元素可以被外界使用，也就是说stack不具有遍历行为，
  没有迭代器。


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

void test()
{
  // stack构造函数
  // stack<T> stkT;           //stack采用模板类实现， stack对象的默认构造形式：
  // stack(const stack &stk); //拷贝构造函数
  stack<int> s1;
  stack<int> s2(s1);

  // stack赋值操作
  // stack& operator=(const stack &stk);//重载等号操作符

  // stack数据存取操作
  // push(elem);     //向栈顶添加元素
  // pop();          //从栈顶移除第一个元素
  // top();          //返回栈顶元素
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(100);
  cout << "栈顶元素:" << s1.top() << endl;
  s1.pop(); //删除栈顶元素

  // stack大小操作
  // empty(); //判断堆栈是否为空
  // size();  //返回堆栈的大小
  while (!s1.empty())
  {
    cout << s1.top() << " ";
    s1.pop();
  }

  cout << "size：" << s1.size() << endl;
}

int main(void)
{
  test();
  return 0;
}