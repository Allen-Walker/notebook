/*
  queue是一种先进先出(first in first out, FIFO)的数据类型,他有两个口，
  数据元素只能从一个口进，从另一个口出。queue和stack一样不具有遍历行为。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

void test()
{
  // queue构造函数
  // queue<T> queT;           //queue采用模板类实现，queue对象的默认构造形式：
  // queue(const queue &que); //拷贝构造函数
  // queue<int> q;            //创建队列

  // queue存取、插入和删除操作
  // push(elem); //往队尾添加元素
  // pop();      //从队头移除第一个元素
  // back();     //返回最后一个元素
  // front();    //返回第一个元素
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  cout << "队尾：" << q.back() << endl;

  // queue赋值操作
  // queue &operator=(const queue &que); //重载等号操作符

  // queue大小操作
  // empty(); //判断队列是否为空
  // size();  //返回队列的大小
  while (q.size() > 0)
  {
    cout << q.front() << " "; //输出队头元素
    q.pop();                  //删除队头
  }
}

int main(void)
{
  test();
  return 0;
}