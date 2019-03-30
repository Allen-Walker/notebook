/*
  特点：
  1 vector是动态数组，连续内存空间，具有随机存取效率高的优点。  
  2 vector是单口容器，在队尾插入和删除元素效率高，在指定位置插入会导致数据元素移动，效率低。

  vector如何实现动态增长?当vector空间满的时候，再当插入新元素的时候，vector会重新申请一块
  更大的内存空间，将原空间数据拷贝到新的内存空间，然后释放旧的内存空间，再将新元素插入到新空
  间中，以此可以看出vector的空间动态增长效率较低。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

// 构造函数
void test01()
{
  // vector<T> v;                //采用模板实现类实现，默认构造函数
  // vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
  // vector(n, elem);            //构造函数将n个elem拷贝给本身。
  // vector(const vector &vec);  //拷贝构造函数。

  vector<int> v1; //默认构造
  int arr[] = {10, 20, 30, 40};
  vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
  vector<int> v3(v2.begin(), v2.end());
  vector<int> v4(v3);

  printVector(v2);
  printVector(v3);
  printVector(v4);
}

// 常用赋值操作
void test02()
{
  // assign(beg, end);                     //将[beg, end)区间中的数据拷贝赋值给本身。
  // assign(n, elem);                      //将n个elem拷贝赋值给本身。
  // vector &operator=(const vector &vec); //重载等号操作符
  // swap(vec);                            // 将vec与本身的元素互换。

  int arr[] = {10, 20, 30, 40};
  vector<int> v1(arr, arr + sizeof(arr) / sizeof(int)); //默认构造

  //成员方法
  vector<int> v2;
  v2.assign(v1.begin(), v1.end());

  //重载=
  vector<int> v3;
  v3 = v2;

  int arr1[] = {100, 200, 300, 400};
  vector<int> v4(arr1, arr1 + sizeof(arr) / sizeof(int)); //默认构造

  printVector(v1);
  printVector(v2);
  printVector(v3);
  printVector(v4);

  cout << "------------------" << endl;

  v4.swap(v1);
  printVector(v1);
  printVector(v2);
  printVector(v3);
  printVector(v4);
}

// vector 大小操作
void test03()
{
  // size();                //返回容器中元素的个数
  // empty();               //判断容器是否为空
  // resize(int num);       //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
  // resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
  // capacity();            //容器的容量
  // reserve(int len);      //容器预留len个元素长度，预留位置不初始化，元素不可访问。

  int arr1[] = {100, 200, 300, 400};
  vector<int> v(arr1, arr1 + sizeof(arr1) / sizeof(int)); //默认构造

  cout << "size：" << v.size() << endl;
  if (v.empty() == true)
  {
    cout << "空！" << endl;
  }
  else
  {
    cout << "不空！" << endl;
  }

  printVector(v);
  v.resize(2);
  printVector(v);
  v.resize(6);
  printVector(v);
  v.resize(8, 1);
  printVector(v);

  for (int i = 0; i < 10000; i++)
  {
    v.push_back(i);
  }
  cout << "size：" << v.size() << endl;    //元素的个数
  cout << "容量:" << v.capacity() << endl; //容量

  /*
  reserv和resize的区别?
  reserve是容器预留空间，但在空间内不真正创建元素对象，所以在没有添加新的对象之前，不能引用
  容器内的元素.
  resize是改变容器的大小，且在创建对象，因此，调用这个函数之后，就可以引用容器内的对象了.
*/
  cout << "vector 容量增长" << endl;
  vector<int> v1;
  int *p = NULL;
  int count = 0; // 统计vector容量增长几次？
  for (int i = 0; i < 100000; i++)
  {
    v1.push_back(i);
    if (p != &v1[0])
    {
      p = &v1[0];
      count++;
    }
  }
  cout << "vector容量增长count:" << count << endl; //打印出
  cout << "size：" << v1.size() << endl;           //元素的个数
  cout << "容量:" << v1.capacity() << endl;        //容量

  // 巧用reserve增加程序效率？
  cout << "巧用reserve增加程序效率" << endl;
  vector<int> v2;
  v2.reserve(100000);
  int *p2 = NULL;
  int count2 = 0; // 统计vector容量增长几次？
  for (int i = 0; i < 100000; i++)
  {
    v2.push_back(i);
    if (p2 != &v2[0])
    {
      p2 = &v2[0];
      count2++;
    }
  }
  cout << "vector容量增长count:" << count2 << endl; //打印出
  cout << "size：" << v2.size() << endl;            //元素的个数
  cout << "容量:" << v2.capacity() << endl;         //容量
  /*
    当我们知道我们存储的元素大概有多少的时候,我们就可以使用reserve方法，来减少
    vector重新申请内存-拷贝数据-释放旧空间的次数。
  */
}

// vector存取数据
void test04()
{
  // at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
  // operator[];  //返回索引idx所指的数据，越界时，运行直接报错
  // front();     //返回容器中第一个数据元素
  // back();      //返回容器中最后一个数据元素

  int arr1[] = {100, 200, 300, 400};
  vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int)); //默认构造

  for (int i = 0; i < v4.size(); i++)
  {
    cout << v4[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < v4.size(); i++)
  {
    cout << v4.at(i) << " ";
  }
  cout << endl;

  //区别: at抛异常 []不抛异常

  cout << "front:" << v4.front() << endl;
  cout << "back:" << v4.back() << endl;
}

//插入和删除
void test05()
{
  // insert(const_iterator pos, int count, ele);      //迭代器指向位置pos插入count个元素ele.
  // push_back(ele);                                  //尾部插入元素ele
  // pop_back();                                      //删除最后一个元素
  // erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
  // erase(const_iterator pos);                       //删除迭代器指向的元素
  // clear();                                         //删除容器中所有元素

  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  
  v.insert(v.begin(), 30);//头部插入
  v.insert(v.end(), 40);  //尾部插入

  v.insert(v.begin() + 2, 100); //vector支持随机访问
  //支持数组下标，一般都支持随机访问
  //迭代器可以直接+n/-n操作

  printVector(v);

  //删除
  v.erase(v.begin());
  printVector(v);
  v.erase(v.begin() + 1, v.end());
  printVector(v);
  v.clear();
  cout << "size:" << v.size() << endl;
  cout << "size:" << v.capacity() << endl;
}

//巧用swap缩减空间
void test()
{
  //vector添加元素,capacity会自动增长 删除元素时候，capacity不会自动减少

  vector<int> v;
  for (int i = 0; i < 100000; i++)
  {
    v.push_back(i);
  }

  cout << "size:" << v.size() << endl;
  cout << "capacity:" << v.capacity() << endl;

  v.resize(10);
  cout << "--------------" << endl;
  cout << "size:" << v.size() << endl;
  cout << "capacity:" << v.capacity() << endl;

  //收缩空间
  vector<int>(v).swap(v);
  cout << "--------------" << endl;
  cout << "size:" << v.size() << endl;
  cout << "capacity:" << v.capacity() << endl;
}

int main(void)
{
  test();
  return 0;
}