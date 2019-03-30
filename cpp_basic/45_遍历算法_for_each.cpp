/*
  for_each算法 遍历容器元素
	@param beg 开始迭代器
	@param end 结束迭代器
	@param _callback  函数回调或者函数对象
	@return 函数对象
*/
// for_each(iterator beg, iterator end, _callback);

// 基本正向遍历和逆向遍历
// for_each绑定参数输出
// for_each修改容器元素
// for_each返回值

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//for_each正向遍历 反向遍历
struct print01
{
  void operator()(int v)
  {
    cout << v << " ";
  }
};
void test01()
{

  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(rand() % 100);
  }

  //正向遍历
  for_each(v.begin(), v.end(), print01());
  cout << endl;
  //反向遍历
  for_each(v.rbegin(), v.rend(), print01());
  cout << endl;
}

//for_each算法 绑定参数
//将容器中的元素加上100 再输出
struct print2 : public binary_function<int, int, void>
{
  void operator()(int v1, int v2) const
  {
    cout << v1 + v2 << " ";
  }
};
void print21(int v1, int v2)
{
  cout << v1 + v2 << " ";
}
void test02()
{
  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(rand() % 100);
  }

  for_each(v.begin(), v.end(), print01());
  cout << endl;

  //函数对象做参数
  for_each(v.begin(), v.end(), bind2nd(print2(), 100));
  cout << endl;
  //普通回调函数做参数，并且绑定参数
  for_each(v.begin(), v.end(), bind2nd(ptr_fun(print21), 100));
  cout << endl;
}

//for_each修改元素值
struct print3
{
  void operator()(int &v1) const
  {
    v1 = v1 + 100;
    cout << v1 << " ";
  }
};
void test03()
{

  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(rand() % 100);
  }

  for_each(v.begin(), v.end(), print01());
  cout << endl;

  for_each(v.begin(), v.end(), print3());
  cout << endl;

  for_each(v.begin(), v.end(), print01());
  cout << endl;
}

//for_each返回值
struct print4
{
  print4() : count(0) {}
  void operator()(int v1)
  {
    count++;
    cout << v1 << " ";
  }
  int count;
};
void test04()
{

  vector<int> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(rand() % 100);
  }
  print4 temp1;
  print4 temp2 = for_each(v.begin(), v.end(), temp1);
  cout << endl;

  cout << "temp1:" << temp1.count << endl;
  cout << "temp2:" << temp2.count << endl;
}
int main()
{
  test04();
  return 0;
}