/*
	transform算法 将指定容器区间元素搬运到另一容器中
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
	@param beg1 源容器开始迭代器
	@param end1 源容器结束迭代器
	@param beg2 目标容器开始迭代器
	@param _cakkback 回调函数或者函数对象
	@return 返回目标容器迭代器
*/
// transform(iterator beg1, iterator end1, iterator beg2, _callbakc)

// 从一个容器经过处理搬运到另一个容器:两个容器数据处理搬运到第三个容器

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//容器中元素加10 搬运到另一容器中
void print1(int v)
{
  cout << v << " ";
}
struct myplus01
{
  int operator()(int v1)
  {
    return v1 + 100;
  }
};
void test01()
{
  vector<int> v, dest;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(rand() % 100);
  }
  for_each(v.begin(), v.end(), print1);
  cout << endl;
  //首先给dest开辟足够内存
  dest.resize(v.size());
  //搬运元素
  transform(v.begin(), v.end(), dest.begin(), myplus01());
  for_each(dest.begin(), dest.end(), print1);
  cout << endl;
}

//容器1的元素 + 容器2的元素 搬运到 第三个容器中
struct myplus02
{
  int operator()(int v1, int v2)
  {
    return v1 + v2;
  }
};
void test02()
{

  vector<int> v1, v2, dest;
  for (int i = 0; i < 10; i++)
  {
    v1.push_back(i);
    v2.push_back(i + 1);
  }
  for_each(v1.begin(), v1.end(), print1);
  cout << endl;

  dest.resize(v1.size());
  transform(v1.begin(), v1.end(), v2.begin(), dest.begin(), myplus02());

  for_each(dest.begin(), dest.end(), print1);
  cout << endl;
}
int main()
{
  test02();
  return 0;
}