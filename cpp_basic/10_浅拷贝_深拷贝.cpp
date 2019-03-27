/*
系统提供默认的拷贝构造器,一经定义不再提供
系统提供的默认拷贝是浅拷贝
如果类中包含的数据元素全部在栈上,浅拷贝可以满足需求的；
如果是堆上的数据,则会发生多次析构行为
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Person
{
public:
  char *m_name;
  int m_sex;

  Person() { cout << "对象调用默认构造函数" << endl; }

  Person(const char *name, int sex)
  {
    if (name)
    {
      m_name = (char *)malloc(strlen(name) + 1);
      strcpy(m_name, name);
    }

    m_sex = sex;
    cout << m_name << "对象调用带参构造函数" << endl;
  }

  Person(const Person &another)
  {
    //深拷贝
    if (another.m_name)
    {
      m_name = (char *)malloc(strlen(another.m_name) + 1);
      strcpy(m_name, another.m_name);
    }

    //默认浅拷贝 coredump 多次拷贝造成多个对象的m_name指向同一堆内存
    //m_name = another.m_name;

    m_sex = another.m_sex;
    cout << m_name << "对象调用拷贝构造函数" << endl;
  }

  Person &operator=(const Person &another) //返回值为Person & -- 可以进行连等操作
  {
    cout << m_name << "对象调用=操作重载函数" << endl;
    //防止自身赋值
    if (this == &another)
      return *this;
    //回收自身堆中资源
    if (this->m_name)
    {
      free(this->m_name);
      this->m_sex = 0;
    }
    // 进行深拷贝
    m_name = (char *)malloc(strlen(another.m_name) + 1);
    strcpy(m_name, another.m_name);
    m_sex = another.m_sex;
    return *this;
  }

  ~Person()
  {
    cout << m_name << "对象调用析构函数" << endl;
    if (m_name)
    {
      free(m_name); //浅拷贝，多个对象使用的同一块堆内存，多次释放
      m_name = NULL;
      cout << "释放堆空间内存" << endl;
    }
  }
};

void test01()
{
  Person p = Person("小李", 1);
  Person p1 = p;
  cout << p1.m_name << " " << p1.m_sex << endl;
  Person p2 = p;
  cout << p2.m_name << " " << p2.m_sex << endl;
}

void test02()
{
  Person p = Person("小李", 1);
  Person p3;
  p3 = p;
  cout << p3.m_name << " " << p3.m_sex << endl;
  Person p4;
  p4 = p; //调用=重载函数，类似拷贝构造函数，也要注意堆空间释放问题
  cout << p4.m_name << " " << p4.m_sex << endl;
}

void test03()
{
  char name[64] = "小李";
  //浅拷贝这块内存会被多个对象所指向，同时也会对象的析构函数多次释放
  //所以你不能保证这块内存什么时候被回收，或者是在main中回收，或许被对象析构时回收
  //所以在需要进行深拷贝的操作，每个对象都要建立一个副本

  char *name1 = new char[64];
  strcpy(name1, "小李");
  delete (name1);
  //这种方式也是同样

  Person p = Person(name, 1);
  Person p1 = p;
  cout << p1.m_name << " " << p1.m_sex << endl;
  Person p2 = p;
  cout << p2.m_name << " " << p2.m_sex << endl;
}

int main(void)
{
  test03();
  return 0;
}