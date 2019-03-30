/*
  set/multiset的特性是所有元素会根据元素的值自动进行排序。set是以RB-tree（红
  黑树，平衡二叉树的一种）为底层机制，其查找效率非常好。set容器中不允许重复元素,
  multiset允许重复元素。

  二叉搜索树，是指二叉树中的节点按照一定的规则进行排序，使得对二叉树中元素访问更加
  高效。二叉搜索树的放置规则是：任何节点的元素值一定大于其左子树中的每一个节点的元
  素值，并且小于其右子树的值。因此从根节点一直向左走，一直到无路可走，即得到最小值，
  一直向右走，直至无路可走，可得到最大值。

  我们可以通过set的迭代器改变元素的值吗？不行，因为set集合是根据元素值进行排序，关
  系到set的排序规则，如果任意改变set的元素值，会严重破坏set组织。

  问题: 我们发现打印出来set集合中的元素是从小到大的升序排列，那么我们如何指定排序为
  降序呢？这个问题呢？我们需要了解函数对象的概念。
*/

// set构造函数
// set<T> st;          //set默认构造函数：
// mulitset<T> mst;    //multiset默认构造函数:
// set(const set &st); //拷贝构造函数

// set赋值操作
// set &operator=(const set &st); //重载等号操作符
// swap(st);                      //交换两个集合容器

// set大小操作
// size();  //返回容器中元素的数目
// empty(); //判断容器是否为空

//set插入和删除操作
// insert(elem);    //在容器中插入元素。
// clear();         //清除所有元素
// erase(pos);      //删除pos迭代器所指的元素，返回下一个元素的迭代器。
// erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
// erase(elem);     //删除容器中值为elem的元素。

//set查找操作
// find(key);            //查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
// lower_bound(keyElem); //返回第一个key>=keyElem元素的迭代器。
// upper_bound(keyElem); //返回第一个key>keyElem元素的迭代器。
// equal_range(keyElem); //返回容器中key与keyElem相等的上下限的两个迭代器。

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <list>
using namespace std;

//仿函数
class mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 < v2;
	}
};

//set容器初始化
void test01()
{
	set<int, mycompare> s1; //自动进行排序 默认从小到大
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//删除操作
	s1.erase(s1.begin());
	s1.erase(7);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//先序遍历 中序遍历 后序遍历
	//如何改变默认排序？
}

//set查找
void test02()
{

	set<int> s1;
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);

	set<int>::iterator ret = s1.find(14);
	if (ret == s1.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "ret:" << *ret << endl;
	}

	//找第一个大于等于key的元素
	ret = s1.lower_bound(2);
	if (ret == s1.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "ret:" << *ret << endl;
	}

	//找第一个大于key的值
	ret = s1.upper_bound(2);
	if (ret == s1.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "ret:" << *ret << endl;
	}

	//equal_range 返回Lower_bound 和 upper_bound值
	pair<set<int>::iterator, set<int>::iterator> myret = s1.equal_range(2);
	if (myret.first == s1.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "myret:" << *(myret.first) << endl;
	}

	if (myret.second == s1.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "myret:" << *(myret.second) << endl;
	}
}

class Person
{
public:
	Person(int age, int id) : id(id), age(age) {}

public:
	int id;
	int age;
};

class mycompare2
{
public:
	bool operator()(Person p1, Person p2)
	{
		if (p1.id == p2.id)
		{
			return p1.age > p2.age;
		}
		else
		{
			return p1.id > p2.id;
		}
	}
};

void test()
{

	set<Person, mycompare2> sp; // set需要排序，当你放对象，set知道怎么排吗？

	Person p1(10, 20), p2(20, 20), p3(50, 60);
	sp.insert(p1);
	sp.insert(p2);
	sp.insert(p3);

	Person p4(10, 30);

	for (set<Person, mycompare2>::iterator it = sp.begin(); it != sp.end(); it++)
	{
		cout << (*it).age << " " << (*it).id << endl;
	}

	//查找
	set<Person, mycompare2>::iterator ret = sp.find(p4);
	if (ret == sp.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到：" << (*ret).id << " " << (*ret).age << endl;
	}
}

int main()
{
	test();
	return 0;
}
