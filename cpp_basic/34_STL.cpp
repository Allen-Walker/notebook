/*
  STL从广义上分为: 容器(container) 算法(algorithm) 迭代器：一种对象，它能够用来遍历标准模板库容器中的部分或全部元素，每个迭代器对象代表容器中的确定的地址。(iterator),容器
  和算法之间通过迭代器进行无缝连接。
  
  在c++标准中，STL被组织成以下13个头文件：  <algorithm>、<deque>、
  <functional>、<iterator>、<vector>、<list>、  <map>、<memory>、
  <numeric>、<queue>、<set>、<stack> 和<utility>

  优点：
  1 STL是C++的一部分，被内建在编译器之内。
  2 数据结构和算法的分离。例如:在STL的vector容器中，可以放入元素、基础数据类型变
    量、元素的地址；STL的sort() 排序函数可以用来操作vector,list等容器。
  3 STL具有高可重用性，高性能，高移植性，跨平台的优点。

  容器：STL中容器分为：容器是指存储有限数据元素的一种数据结构。容器可以包含容器。可
       分为序列式容器和关联式容器。
  迭代器：一种对象，它能够用来遍历标准模板库容器中的部分或全部元素，每个迭代器对象代
        表容器中的确定的地址。
  算法：STL提供了大约100个实现算法的模版函数
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//STL中的容器 算法 迭代器
void test01()
{

  vector<int> v;  //STL中的标准容器之一 ：动态数组
  v.push_back(1); //vector容器提供的插入数据的方法
  v.push_back(5);
  v.push_back(3);
  v.push_back(7);

  //迭代器
  vector<int>::iterator pStart = v.begin(); //vector容器提供了begin()方法 返回指向第一个元素的迭代器
  vector<int>::iterator pEnd = v.end();     //vector容器提供了end()方法 返回指向最后一个元素下一个位置的迭代器

  //通过迭代器遍历
  while (pStart != pEnd)
  {
    cout << *pStart << " ";
    pStart++;
  }
  cout << endl;

  //算法 count算法 用于统计元素的个数
  int n = count(pStart, pEnd, 5);
  cout << "n:" << n << endl;
}

//STL容器不单单可以存储基础数据类型，也可以存储类对象
class Teacher
{
public:
  Teacher(int age) : age(age){};
  ~Teacher(){};

public:
  int age;
};

void test02()
{

  vector<Teacher> v; //存储Teacher类型数据的容器
  Teacher t1(10), t2(20), t3(30);
  v.push_back(t1);
  v.push_back(t2);
  v.push_back(t3);

  vector<Teacher>::iterator pStart = v.begin();
  vector<Teacher>::iterator pEnd = v.end();

  //通过迭代器遍历
  while (pStart != pEnd)
  {
    cout << pStart->age << " ";
    pStart++;
  }
  cout << endl;
}

//存储Teacher类型指针
void test03()
{

  vector<Teacher *> v; //存储Teacher类型指针
  Teacher *t1 = new Teacher(10);
  Teacher *t2 = new Teacher(20);
  Teacher *t3 = new Teacher(30);

  v.push_back(t1);
  v.push_back(t2);
  v.push_back(t3);

  //拿到容器迭代器
  vector<Teacher *>::iterator pStart = v.begin();
  vector<Teacher *>::iterator pEnd = v.end();

  //通过迭代器遍历
  while (pStart != pEnd)
  {
    cout << (*pStart)->age << " ";
    pStart++;
  }
  cout << endl;
}

//容器嵌套容器  难点(不理解，可以跳过)
void test04()
{

  vector<vector<int>> v; //容器中存储容器
  vector<int> v1, v2, v3;
  v1.push_back(1);
  v1.push_back(2);

  v2.push_back(10);

  v3.push_back(100);
  v3.push_back(200);

  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);

  //拿到容器迭代器
  vector<vector<int>>::iterator pStart = v.begin();
  vector<vector<int>>::iterator pEnd = v.end();

  //通过迭代器遍历
  while (pStart != pEnd)
  {
    vector<int> vTemp = *pStart; //获得迭代器当前指向的容器

    vector<int>::iterator tmpStart = vTemp.begin();
    vector<int>::iterator tmpEnd = vTemp.end();
    for (; tmpStart != tmpEnd; tmpStart++)
    {
      cout << *tmpStart << " ";
    }
    cout << endl;
    pStart++;
  }
}

//算法
int mycount(int *start, int *end, int val)
{
  int n = 0;
  for (int *it = start; it != end; it++)
  {
    if (*it == val)
    {
      n++;
    }
  }
  return n;
}

void test05()
{
  //容器=>数组
  int arr[] = {1, 2, 3, 5, 4, 5, 6};
  //迭代器 [] int*p []也是一种迭代器
  int *pStart = arr;                             //开始迭代器
  int *pEnd = &(arr[sizeof(arr) / sizeof(int)]); //结束迭代器
  
  //遍历容器
  while (pStart != pEnd)
  {
    cout << *pStart << endl;
    pStart++;
  }

  pStart = arr;
  int n = mycount(pStart, pEnd, 5); //算法 通过迭代器对容器中的元素进行统计
  cout << "n:" << n << endl;
}

int main()
{
  test05();
  return 0;
}