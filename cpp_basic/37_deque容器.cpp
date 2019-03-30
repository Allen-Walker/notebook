/*
  deque是“double-ended queue”的缩写,和vector一样，deque也支持随机存取。
  vector是单向开口的连续性空间，deque则是一种双向开口的连续性空间。

  deque和vector的最大差异？
    一  在于deque允许常数时间内对头端进行元素插入和删除操作。
    二  在于deque没有容量的概念，因为它是动态的以分段的连续空间组合而成，随时
        可以增加一段新的空间并链接起来，换句话说，不会像vector那样“因旧空间不
        足而重新分配一块更大的空间，然后再复制元素，释放空间”。此deque没有必
        要提供所谓的空间保留功能。

  特性总结:
  1 双端插入和删除元素效率较高.
  2 指定位置插入也会导致数据元素移动,降低效率.
  3 可随机存取,效率高.

  deque是分段连续的内存空间，通过中控器维持一种连续内存空间的状态
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
using namespace std;

void PrintDeque(deque<int> &d)
{
  for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

//deque初始化
void test01()
{
  // deque<T> deqT;           //默认构造形式
  // deque(beg, end);         //构造函数将(beg, end)区间中的元素拷贝给本身。
  // deque(n, elem);          //构造函数将n个elem拷贝给本身。
  // deque(const deque &deq); //拷贝构造函数
  deque<int> d1;
  deque<int> d2(10, 5);
  deque<int> d3(d2.begin(), d2.end());
  deque<int> d4(d3);

  PrintDeque(d1);
  PrintDeque(d2);
  PrintDeque(d3);
  PrintDeque(d4);
}

//赋值操作 大小操作
void test02()
{
  // assign(beg, end);                   //将[beg, end)区间中的数据拷贝赋值给本身。
  // assign(n, elem);                    //将n个elem拷贝赋值给本身。
  // deque &operator=(const deque &deq); //重载等号操作符
  // swap(deq);                          // 将deq与本身的元素互换

  deque<int> d1;
  deque<int> d2;
  deque<int> d3;
  d1.assign(10, 5);
  d2.assign(d1.begin(), d1.end()); //迭代器指定区间赋值
  d3 = d2;                         //等号赋值

  d1.swap(d2); //交换两个空间元素

  // deque.size();            //返回容器中元素的个数
  // deque.empty();           //判断容器是否为空
  // deque.resize(num);       //重新指定容器的长度为num,若容器变长，则以默认值
  //                          //填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
  // deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值
  //                          //填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。

  if (d1.empty())
  {
    cout << "空!" << endl;
  }
  else
  {
    cout << "size:" << d1.size() << endl;
  }

  d1.resize(5); //10个元素，后五个元素扔掉
}

//deque双端插入和删除操作
void test03()
{
  // push_back(elem);  //在容器尾部添加一个数据
  // push_front(elem); //在容器头部插入一个数据
  // pop_back();       //删除容器最后一个数据
  // pop_front();      //删除容器第一个数据

  deque<int> d1;
  d1.push_back(100);
  d1.push_front(200);
  d1.push_back(300);
  d1.push_back(400);
  d1.push_front(500);

  PrintDeque(d1);

  int val = d1.front(); //拿到被删除的数据
  d1.pop_front();       //删除

  val = d1.back();
  d1.pop_back(); //删除最后一个元素
}

void test04(){
  // at(idx);    //返回索引idx所指的数据，如果idx越界，抛出out_of_range。
  // operator[]; //返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
  // front();    //返回第一个数据。
  // back();     //返回最后一个数据
}

// deque插入操作
void test05(){
  // insert(pos, elem);     //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
  // insert(pos, n, elem);  //在pos位置插入n个elem数据，无返回值。
  // insert(pos, beg, end); //在pos位置插入[beg,end)区间的数据，无返回值

  // 需要对deque容器元素进行排序的时候，建议先将deque容器中数据数据元素拷贝到vector容器
  // 中，对vector进行排序，然后再将排序完成的数据拷贝回deque容器。
}

// deque删除操作
void test06(){
  // clear();         //移除容器的所有数据
  // erase(beg, end); //删除(beg, end)区间的数据，返回下一个数据的位置。
  // erase(pos);      //删除pos位置的数据，返回下一个数据的位置。
}

int main(void)
{
  test06();
  return 0;
}