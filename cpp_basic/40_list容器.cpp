/*
  特性总结:
    采用动态存储分配，不会造成内存浪费和溢出
    链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
    链表灵活，但是空间和时间额外耗费较大
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

template <class T>
void printList(list<T> &mlist)
{
  for (typename list<T>::iterator it = mlist.begin(); it != mlist.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}
/*
error: need ‘typename’ before ‘std::__cxx11::list<T>::iterator’ because ‘std::__cxx11::list<T>’ is a dependent scope
error: dependent-name ‘std::__cxx11::list<T>::iterator’ is parsed as a non-type, but instantiation yields a type

vector<T>还是一个模板类型, 如何实例化还需要取决于外部实际传进来的类型参数T
（二次编译：模板-模板实例化）

解决方法：
用 ‘typename’ 修饰 ‘std::__cxx11::list<T>::iterator’
调用时候显示指定类型，以便模板编译时候进行实例化
*/

//初始化
void test01()
{
  // list构造函数
  // list<T> lstT;          //list采用采用模板类实现,对象的默认构造形式：
  // list(beg, end);        //构造函数将[beg, end)区间中的元素拷贝给本身。
  // list(n, elem);         //构造函数将n个elem拷贝给本身。
  // list(const list &lst); //拷贝构造函数。
  list<int> mlist1;
  list<int> mlist2(10, 10); //有参构造
  list<int> mlist3(mlist2); //拷贝构造
  list<int> mlist4(mlist2.begin(), mlist2.end());
  printList<int>(mlist1);
  cout << endl;
}

// list容器插入删除
void test02()
{
  //list数据元素插入和删除操作
  // push_back(elem);       //在容器尾部加入一个元素
  // pop_back();            //删除容器中最后一个元素
  // push_front(elem);      //在容器开头插入一个元素
  // pop_front();           //从容器开头移除第一个元素
  // insert(pos, elem);     //在pos位置插elem元素的拷贝，返回新数据的位置。
  // insert(pos, n, elem);  //在pos位置插入n个elem数据，无返回值。
  // insert(pos, beg, end); //在pos位置插入[beg,end)区间的数据，无返回值。
  // clear();               //移除容器的所有数据
  // erase(beg, end);       //删除[beg,end)区间的数据，返回下一个数据的位置。
  // erase(pos);            //删除pos位置的数据，返回下一个数据的位置。
  // remove(elem);          //删除容器中所有与elem值匹配的元素。

  list<int> mlist;

  //插入操作
  mlist.push_back(100);
  mlist.push_front(200);

  mlist.insert(mlist.begin(), 300);
  mlist.insert(mlist.end(), 400);
  mlist.insert(mlist.end(), 200);

  list<int>::iterator it = mlist.begin();
  it++;
  it++;
  mlist.insert(it, 500);
  mlist.insert(mlist.end(), 200);
  //删除
  // mlist.pop_back();
  // mlist.pop_front();
  // mlist.erase(mlist.begin(), mlist.end()); //mlist.clear();
  mlist.remove(200); //删除匹配所有值

  list<int>::iterator testit = mlist.begin();
  for (int i = 0; i < mlist.size() - 1; i++)
  {
    testit++;
  }

  cout << (*(mlist.end())) << endl;

  cout << "------------" << endl;
  cout << (*testit) << endl;
  cout << mlist.back() << endl;
  cout << "------------" << endl;

  //删除所有200 还是删除第一次出现的200
  printList<int>(mlist);
}

// list大小操作
// size();            //返回容器中元素的个数
// empty();           //判断容器是否为空
// resize(num);       //重新指定容器的长度为num，
//                    // 若容器变长，则以默认值填充新位置。
//                    // 如果容器变短，则末尾超出容器长度的元素被删除。
// resize(num, elem); //重新指定容器的长度为num，
//                    // 若容器变长，则以elem值填充新位置。
//                    // 如果容器变短，则末尾超出容器长度的元素被删除。

// 赋值操作
void test03()
{
  // list赋值操作
  // assign(beg, end);                 //将[beg, end)区间中的数据拷贝赋值给本身。
  // assign(n, elem);                  //将n个elem拷贝赋值给本身。
  // list &operator=(const list &lst); //重载等号操作符
  // swap(lst);                        //将lst与本身的元素互换。
  list<int> mlist;
  mlist.assign(10, 10);

  list<int> mlist2;
  mlist2 = mlist;

  mlist2.swap(mlist);
}

// list数据的存取
// front(); //返回第一个元素。
// back();  //返回最后一个元素。

//排序 翻转
void test04()
{
  // list反转排列排序
  // reverse(); //反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
  // sort();    //list排序

  list<int> mlist;
  for (int i = 0; i < 10; i++)
  {
    mlist.push_back(i);
  }

  printList<int>(mlist);

  //容器元素反转
  mlist.reverse();

  printList<int>(mlist);
}

bool mycompare(int v1, int v2)
{
  return v1 > v2;
}

//排序
void test()
{

  list<int> mlist;
  mlist.push_back(2);
  mlist.push_back(1);
  mlist.push_back(7);
  mlist.push_back(5);

  printList<int>(mlist);

  //排序  对象怎么排序? 默认从小到大
  mlist.sort();
  printList<int>(mlist);

  //从大到小
  mlist.sort(mycompare);
  printList<int>(mlist);

  //算法sort 支持可随机访问的
}

int main(void)
{
  test();
  return 0;
}