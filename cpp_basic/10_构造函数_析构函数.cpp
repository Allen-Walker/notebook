#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person
{
public:
  string m_name;
  int m_sex;
  Person() { cout << m_name << "对象调用默认构造函数" << endl; } //无参构造函数
  //当类中定义了拷⻉贝构造函数时,c++编译器不会提供无无参数构造函数
  Person(string name, int sex) //带参构造函数
  {
    m_name = name;
    m_sex = sex;
    cout << m_name << "对象调用带参构造函数" << endl;
  }

  Person(const Person &another) //拷贝构造函数
  {
    m_name = another.m_name;
    m_sex = another.m_sex;
    cout << m_name << "对象调用拷贝构造函数" << endl;
  }
  /*
    1)默认无参构造函数
      当类中没有定义构造函数时,编译器默认提供一个无参构造函数,并且其函数体为空
    2)默认拷贝构造函数
      当类中没有定义拷贝构造函数时,编译器默认提供一个默认拷贝构造函数,简单的进行成员变量的值复制 
  */
  void operator=(const Person &another) //操作重载运算符（=）类似于拷贝构造函数
  {
    m_name = another.m_name;
    m_sex = another.m_sex;
    cout << m_name << "对象调用=操作重载函数" << endl;
  }

  ~Person() { cout << m_name << "对象调用析构函数" << endl; }
  /*
  1 对象销毁时,自动调用。完成销毁的善后工作。
  2 无返值,与类名同,无参。不可以重载与默认参数。
  */
};

void printInfo(Person p)
{ //这里调用拷贝构造函数给形参赋值
  cout << p.m_name << endl;
  cout << p.m_sex << endl;
}

Person returnPerson()
{
  Person tmp = Person("小李", 1);
  return tmp; //返回一个对象
}

void test01()
{
  Person xiaohong;                 //调用无参构造函数
  cout << xiaohong.m_name << endl; //空
  cout << xiaohong.m_sex << endl;  //乱码 //应该在构造函数内进行初始化

  Person xiaoli("小李", 1);
  cout << xiaoli.m_name << endl;
  cout << xiaoli.m_sex << endl;
  //跟构造函相反，先构造的后析构
}

void test02()
{
  // 拷贝构造使用场景
  Person xg = Person("小刚", 1);
  cout << xg.m_name << endl;
  cout << xg.m_sex << endl;
  //(1)
  Person xg1 = xg; //注意这里调用拷贝构造函数
  cout << xg1.m_name << endl;
  cout << xg1.m_sex << endl;
}

void test03()
{
  // 拷贝构造使用场景
  Person xg = Person("小刚", 1);
  cout << xg.m_name << endl;
  cout << xg.m_sex << endl;
  //(2)
  Person xg2 = Person(xg); //同Person xg2 = xg;
  cout << xg2.m_name << endl;
  cout << xg2.m_sex << endl;
}

void test04()
{
  // 拷贝构造使用场景
  Person xg = Person("小刚", 1);
  cout << xg.m_name << endl;
  cout << xg.m_sex << endl;
  //(3)
  printInfo(xg); //等价于Person p=xg;调用拷贝构造函数给形参赋值
}

void test05()
{
  // 拷贝构造使用场景
  Person xg = Person("小刚", 1);
  cout << xg.m_name << endl;
  cout << xg.m_sex << endl;
  //(4)
  returnPerson(); //如果返回的对象没有被变量所保存，那么就是一个匿名对象，编译器会将其进行回收
  cout << "小李在这之前已经被析构" << endl;
}

void test06()
{
  //(5)
  Person rp = returnPerson(); //如果返回的对象被变量保存，匿名对象就会被转正为 rp,而并不会调用rp的拷贝构造函数
  cout << "小李还没有被析构，而是函数退出才被析构" << endl;
}

void test07()
{
  //(5)
  Person rp;           //对象rp已经调用默认构造函数初始化初始化
  rp = returnPerson(); //返回的对象被变量保存，但是此时变量已经的被初始化了，所以调用=重载函数
  cout<<"此时返回的匿名对象已经被析构，但是匿名对象利用=重载函数信息保存到了rp对象里"<<endl;
}

void test08()
{
  Person xg = Person("小刚", 1);
  cout << xg.m_name << endl;
  cout << xg.m_sex << endl;
  Person xg3;
  xg3 = xg; // 注意这里 =操作重载
  cout << xg3.m_name << endl;
  cout << xg3.m_sex << endl;
}

int main(void)
{
  test08();
  return 0;
}
