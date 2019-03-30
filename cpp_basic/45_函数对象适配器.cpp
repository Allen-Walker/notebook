/*
函数对象适配器是完成一些配接工作，这些配接包括绑定(bind)，否定(negate),
以及对一般函数或成员函数的修饰，使其成为函数对象。

bind1st ：将参数绑定为函数对象的第一个参数
bind2nd ： 将参数绑定为函数对象的第二个参数
not1 ：  对一元函数对象取反
not2 : 对二元函数对象取反
ptr_fun ： 将普通函数修饰成函数对象
mem_fun ： 修饰成员函数
mem_fun_ref ： 修饰成员函数
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//预定义函数对象
class print
{
public:
  void operator()(int v)
  {
    cout << v << "    ";
  }
};

void test01()
{
  plus<int> myplus; //实例化一个对象
  int ret = myplus(10, 20);
  cout << "ret : " << ret << endl;

  cout << plus<int>()(30, 40) << endl;

  vector<int> v1, v2, v3;
  for (int i = 0; i < 10; i++)
  {
    v1.push_back(i);
    v2.push_back(i + 1);
  }

  v3.resize(v1.size());
  transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());

  for_each(v1.begin(), v1.end(), print());
  cout << endl;

  for_each(v2.begin(), v2.end(), print());
  cout << endl;

  for_each(v3.begin(), v3.end(), print());
  cout << endl;
}

//函数适配器bind1st bind2nd
//现在我有这个需求 在遍历容器的时候，我希望将容器中的值全部加上100之后显示出来，怎么做哇？
struct myprint : public binary_function<int, int, void>
{ //二元函数对象 所以需要继承 binary_fucntion<参数类型,参数类型,返回值类型>
  void operator()(int v1, int v2) const
  {
    cout << v1 + v2 << " ";
  }
};

void test02()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  //我们直接给函数对象绑定参数 编译阶段就会报错
  //如果我们想使用绑定适配器,需要我们自己的函数对象继承binary_function 或者 unary_function
  //根据我们函数对象是一元函数对象 还是二元函数对象
  for_each(v.begin(), v.end(), bind2nd(myprint(), 100));
  cout << endl;

  //总结：  bind1st和bind2nd区别?
  //bind1st ： 将参数绑定为函数对象的第一个参数
  //bind2nd ： 将参数绑定为函数对象的第二个参数
}

//函数对象适配器 not1 not2
struct myprint02
{
  void operator()(int v1) const
  {
    cout << v1 << " ";
  }
};

void test03()
{
  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(5);
  v.push_back(4);

  vector<int>::iterator it = find_if(v.begin(), v.end(), not1(bind2nd(less_equal<int>(), 2)));
  cout << "it:" << *it << endl;
  sort(v.begin(), v.end(), not2(greater<int>()));

  for_each(v.begin(), v.end(), myprint02());
  cout << endl;

  //not1 对一元函数对象取反
  //not2 对二元函数对象取反
}

//如何给一个普通函数使用绑定适配器(bind1st bind2nd)绑定一个参数？(拓展)
//ptr_fun
void myprint04(int v1, int v2)
{
  cout << v1 + v2 << " ";
}

void test04()
{

  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(5);
  v.push_back(4);

  //1 将普通函数适配成函数对象
  //2 然后通过绑定器绑定参数
  for_each(v.begin(), v.end(), bind2nd(ptr_fun(myprint04), 100));
  cout << endl;

  //总结: ptr_fun 将普通函数转变为函数对象
}

//mem_fun mem_fun_ref
//如果我们容器中存储的是对象或者对象指针，如果能指定某个成员函数处理成员数据。
class student
{
public:
  student(string name, int age) : name(name), age(age) {}
  void print()
  {
    cout << "name:" << name << " age:" << age << endl;
  }
  void print2(int a)
  {
    cout << "name:" << name << " age:" << age << " a:" << a << endl;
  }
  int age;
  string name;
};

void test()
{
  //mem_fun : 如果存储的是对象指针，需要使用mem_fun
  vector<student *> v;
  student *s1 = new student("zhaosi", 10);
  student *s2 = new student("liuneng", 20);
  student *s3 = new student("shenyang", 30);
  student *s4 = new student("xiaobao", 40);

  v.push_back(s1);
  v.push_back(s2);
  v.push_back(s3);
  v.push_back(s4);

  for_each(v.begin(), v.end(), mem_fun(&student::print));
  cout << "-----------------------------" << endl;

  //mem_fun_ref : 如果存储的是对象，需要使用mem_fun_ref
  vector<student> v2;
  v2.push_back(student("zhaosi", 50));
  v2.push_back(student("liuneng", 60));
  v2.push_back(student("shenyang", 70));
  v2.push_back(student("xiaobao", 80));

  for_each(v2.begin(), v2.end(), mem_fun_ref(&student::print));
}

int main()
{
  test();
  return 0;
}

/*
如果希望函数对象适配器能对我们自己编写的函数对象有效，我们需要根据我们的函数对象
类型继承STL的父类对象。
二元函数继承：public binary_function<参数类型,参数类型,返回类型>
一元函数继承：public unary_function<参数类型,返回类型>
*/