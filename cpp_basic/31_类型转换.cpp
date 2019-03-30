#include <iostream>
using namespace std;

class Building
{
  public:
  Building(){cout<<"Building()..."<<endl;}
  int num;
};
class Animal
{
  public:
  Animal(){cout<<"Animal()..."<<endl;}
  virtual void func(){cout<<"Animal::func()..."<<endl;}
};
class Cat : public Animal
{
  public:
  Cat(){cout<<"Cat()..."<<endl;}
  virtual void func(){cout<<"Cat::func()..."<<endl;}
private:
  int m_age;
};

//static_cast 在编译期内即可决定其类型的转换
void test01()
{
  //基本数据类型
  double dpi=3.1415926;
  int ipi1=(int)dpi;
  int ipi2=(int)dpi;
  cout<<ipi1<<" "<<ipi2<<endl;

  char cpi1=(char)dpi;
  char cpi2=dpi;
  cout<<cpi1<<" "<<cpi2<<endl;

  //静态的类型转换:在编译的时进行基本类型的转换能替代c风格的类型转换，可以进行一部分检查 
  //进行一般类型转换
  int ipi3=static_cast<int>(dpi);
  cout<<ipi3<<endl;
  char cpi3=static_cast<char>(dpi);
  cout<<cpi3<<endl;
  //以上编译链接没有报错

  //基础数据类型指针
  //int* ippi = static_cast<int*>(&dpi);
  //error: invalid static_cast from type ‘double*’ to type ‘int*’

  //对象指针
  // Building* building = NULL;
  // Animal* ani = static_cast<Animal*>(building);
  //error: invalid static_cast from type ‘Building*’ to type ‘Animal*’

  //转换具有继承关系的对象指针
  //父类指针转成子类指针
  Animal *ani = NULL;
  Cat *cat = static_cast<Cat *>(ani);

  //子类指针转成父类指针
  Cat *soncat = NULL;
  Animal *anifather = static_cast<Animal *>(soncat);
  

  Animal aniobj;
  Animal& aniref = aniobj;
  Cat& catref = static_cast<Cat&>(aniref);

  Cat catobj;
  Cat &catref2 = catobj;
  Animal &anifather2 = static_cast<Animal &>(catref2);

  //总结
  //static_cast 用于内置的数据类型，
  //还有具有继承关系的指针或者引用
}

// //dynamic_cast 用于多态中父子类型的转换（多态是动态联编）
void test02()
{
  // double dpi=3.1415926;
  // int* ipi3=dynamic_cast<int*>(&dpi);
  //error: cannot dynamic_cast ‘& dpi’ (of type ‘double*’) to type ‘int*’ (target is not pointer or reference to class)

  //非继承关系的指针
  Animal* ani = NULL;
  Building* building = dynamic_cast<Building*>(ani);

  //具有继承关系指针
  Animal* ani1 = NULL;
  Cat* cat1 = dynamic_cast<Cat*>(ani1);
  //原因在于 dynamic做类型安全检查

  Cat *cat2 = NULL;
  Animal *ani2 = dynamic_cast<Animal *>(cat2);

  //结论:dynamic只能转换具有继承关系的指针或者引用，并且
  //只能由子类型转成基类型
  //可能是编译器原因，并没有这些相关的限制。
}

//const_cast 指针 引用或者对象指针
void test03()
{

  //1 基础数据类型
  int a = 10;
	const int& b = a;
	//b = 10;// error: assignment of read-only reference ‘b’
	int& c = const_cast<int&>(b);
	c = 20;
  cout<<"c="<<c<<" b="<<b<<" a="<<a<<endl;//c=20 b=20 a=20

  const int aa = 10;
  const int &pp = aa;
  int &cc = const_cast<int &>(pp);
  cc = 100;
  cout<<"cc="<<cc<<" aa="<<aa<<endl;//cc=100 aa=10

  //指针
  const int *p = NULL;
  int *p2 = const_cast<int *>(p);

  int *p3 = NULL;
  const int *p4 = const_cast<const int *>(p3);

  //增加或者去除变量的const性
}

//reinterpret_cast 强制类型转换 无关的指针类型，包括函数指针都可以进行转换
//数据的二进制形式重新解释,但是不改变其值。
typedef void (*FUNC1)(int, int);
typedef int (*FUNC2)(int, char *);
void test04()
{
  //1. 无关的指针类型都可以进行转换
  Building *building = NULL;
  Animal *ani = reinterpret_cast<Animal *>(building);

  //2. 函数指针转换
  FUNC1 func1;
  FUNC2 func2 = reinterpret_cast<FUNC2>(func1);
}

int main(void)
{
  test04();
  return 0;
}