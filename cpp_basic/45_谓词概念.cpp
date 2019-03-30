/*
  谓词是指普通函数或重载的operator()返回值是bool类型的函数对象(仿函数)。

  如果operator接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做
  二元谓词，谓词可作为一个判断式。
*/

// struct myfuncobj01
// {
//   bool operator(int v) {} //接受一个参数，并且返回值为Bool 即一元谓词
// }
// bool compare01(int v);  //同样是叫做一元谓词

// struct myfuncobj02
// {
//   bool operator(int v1，int v2) {} //接受两个参数，返回值为Bool 即二元谓词
// }
// bool compare02(int v1，int v2);  //同样是叫做二元谓词

/*
  一元函数对象  应用举例: for_each
  一元谓词     应用举例：find_if
  二元函数对象  应用举例: transform
  二元谓词     应用举例 : sort
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//一元函数对象
class print
{
public:
  void operator()(const int &v)
  {
    cout << v << " ";
  }
};

void test01()
{
  vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(5);
  v.push_back(3);

  //一元函数对象
  for_each(v.begin(), v.end(), print());
  cout << endl;
}

//一元谓词
class mygreater
{
public:
  bool operator()(const int &v)
  {
    return v > 2;
  }
};

void test02()
{

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(5);
  v.push_back(3);

  vector<int>::iterator it = find_if(v.begin(), v.end(), mygreater()); //匿名函数对象
  //Find the first element in a sequence for which a predicate is true
  cout << *it << endl;
}

//二元函数对象
class myplus
{
public:
  int operator()(int v1, int v2)
  {
    return v1 + v2;
  }
};

void test03()
{

  vector<int> v1, v2, v3;
  v1.push_back(3);
  v1.push_back(4);
  v1.push_back(5);

  v2.push_back(7);
  v2.push_back(8);
  v2.push_back(2);

  v3.resize(v1.size() + v2.size()); // 给v3开辟空间

  transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), myplus());
  // Perform an operation on corresponding elements of two sequences.

  for_each(v3.begin(), v3.end(), print());
  cout << endl;
}

//二元谓词
class mycompare
{
public:
  bool operator()(int v1, int v2)
  {
    return v1 > v2;
  }
};

void test()
{

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(5);
  v.push_back(3);

  sort(v.begin(), v.end(), mycompare());
  for_each(v.begin(), v.end(), print());
  cout << endl;
}

int main()
{
  test();
  return 0;
}
