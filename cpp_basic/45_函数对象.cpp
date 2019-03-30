/*
  函数对象的概念
  重载函数调用操作符的类，其对象常称为函数对象（function object），即它们
  是行为类似函数的对象，也叫仿函数(functor),其实就是重载“()”操作符，使得类
  对象可以像函数那样调用。

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class FuncObject01
{
public:
  void operator()()
  {
    cout << "hello world" << endl;
  }
};

void FuncObject02()
{
  cout << "hello world" << endl;
}

//函数对象概念
void test01()
{

  FuncObject01 fobj;
  fobj();
  FuncObject02();
}

class FuncObject03
{
public:
  int operator()(int a, int b)
  {
    return a + b;
  }
};

int FuncObject04(int a, int b)
{
  return a + b;
}
//函数对象也可以像普通函数一样 具有返回值和参数
void test02()
{
  FuncObject03 fobj;
  int ret = fobj(10, 20);
  cout << "ret :" << ret << endl;

  ret = FuncObject04(10, 20);
  cout << "ret :" << ret << endl;
}

//函数对象超出了普通函数的功能，可以具有保存函数调用状态
//例如 我们要统计函数调用次数
class FuncObject05
{
public:
  FuncObject05() : count(0) {}
  void operator()()
  {
    cout << "hello world" << endl;
    count++;
  }
  int count;
};

//普通函数要统计调用次数 需要一个全局变量
int g_count = 0;
void FuncObject06()
{
  cout << "hello world" << endl;
  g_count++;
}
void test03()
{

  FuncObject06();
  FuncObject06();
  cout << "函数调用次数：" << g_count << endl;

  //使用函数对象 不需要使用全局变量
  FuncObject05 fobj;
  fobj();
  fobj();
  fobj();

  cout << "函数调用次数：" << fobj.count << endl;
}

//函数对象做参数和返回值
class print
{
public:
  print() : count(0) {}
  void operator()(const int &val)
  {
    cout << val << " ";
    count++;
  }
  int count;
};
void test04()
{

  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  v.push_back(2);

  //通过for_each算法 遍历容器元素
  print myprint;
  //函数对象做返回值和参数
  myprint = for_each(v.begin(), v.end(), myprint);
  cout << endl;

  cout << "函数对象调用次数:" << myprint.count << endl;
}

int main()
{
  test04();
  return 0;
}