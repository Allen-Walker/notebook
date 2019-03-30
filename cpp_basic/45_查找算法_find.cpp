/*
	find算法 查找元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return 返回查找元素的位置
*/
// find(iterator beg, iterator end, value)

/*
	adjacent_find算法 查找相邻重复元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
	@return 返回相邻元素的第一个位置的迭代器
*/
// adjacent_find(iterator beg, iterator end, _callback);

/*
	binary_search算法 二分查找法
	注意: 在无序序列中不可用
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return bool 查找返回true 否则false
*/
// bool binary_search(iterator beg, iterator end, value);

/*
	find_if算法 条件查找
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return bool 查找返回true 否则false
*/
// find_if(iterator beg, iterator end, _callback);

/*
	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  value回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
*/
// count(iterator beg, iterator end, value);

/*
	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
*/
// count_if(iterator beg, iterator end, _callback);

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//find 算法
void test01()
{
  int arr[] = {5, 2, 8, 9, 1, 3};
  vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

  //这里注意find返回值 如果没有找到 返回 v.end()
  vector<int>::iterator it = find(v.begin(), v.end(), 1);
  //可以这样判断是否找到元素
  if (it == v.end())
  {
    cout << "没有找到!" << endl;
  }
  else
  {
    cout << *it << endl;
  }
}

//find查找对象
class sutdent
{
public:
  sutdent(int age, int salary) : age(age), salary(salary) {}
  int age;
  int salary;

  bool operator==(const sutdent &stu)
  {
    if (this->age == stu.age && this->salary == stu.salary)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};
void test02()
{
  //对象查找  重载==操作符
  sutdent s1(1, 2), s2(3, 4), s3(5, 6);
  vector<sutdent> vs;
  vs.push_back(s1);
  vs.push_back(s2);
  vs.push_back(s3);

  vector<sutdent>::iterator its = find(vs.begin(), vs.end(), s2);
  if (its == vs.end())
  {
    cout << "s2没有找到！" << endl;
  }
  else
  {
    cout << "s2找到！" << endl;
  }
}

int main()
{
  test();
  return 0;
}
