/*
STL容器共性机制
STL容器所提供的都是值(value)寓意，而非引用(reference)寓意，也就是说当我们给容器中插
入元素的时候，容器内部实施了拷贝动作，将我们要插入的元素再另行拷贝一份放入到容器中，而不
是将原数据元素直接放进容器中，也就是说我们提供的元素必须能够被拷贝。

除了queue和stack之外，每个容器都提供可返回迭代器的函数，运用返回的迭代器就可以访问元素。
通常STL不会抛出异常，需要使用者传入正确参数。
每个容器都提供了一个默认的构造函数和默认的拷贝构造函数。
大小相关的构造方法:  1 size()返回容器中元素的个数 2 empty()判断容器是否为空
*/
#if 0
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class myclass
{
public:
  myclass(const char *data)
  {
    int len = strlen(data) + 1; //计算传进来的字符串长度
    this->data = new char[len]; //在堆区分配了len字节内存
    strcpy(this->data, data);   //将数据拷贝到我们在堆分配的内存中
  }
  //既然我们在堆区分配了内存，需要在析构函数中释放内存
  ~myclass()
  {
    delete[] this->data;
    this->data = NULL;
  }

private:
  char *data;
};

void test_deep_copy()
{
  char *data = "abcd";
  myclass mc(data); //创建myclass的实例 并用char*字符串data初始化对象

  vector<myclass> v; //创建vector容器 
  v.push_back(mc);   //将mc实例插入到vector容器尾部
}

int main()
{
  test_deep_copy(); //调用测试函数
  return 0;
}

/*
由于我们没有提供拷贝构造函数,没有重载=操作符，vector对我们的mc对象进行的
简单的浅拷贝，将拷贝的对象插入到容器中，导致我们的mc对象的data指针和容器中
mc对象的拷贝对象中的data指针都指向了我们在堆区分配的内存，当函数结束，两个
对象都调用了析构函数，先调用析构函数的对象成功释放了堆区内存，后调用析构函数
的对象一释放，程序挂掉了。

原因在于两个指针指向了同一块堆区内存，这样会导致不可预知的结果，函数结束其中
一个调用析构函数，销毁了data指向的内存空间，而另一个对象析构的时候就会挂掉。

问题的解决办法就是，给我们的对象提供一个拷贝构造函数，并且重载=操作符,两个指
针分别指向自己的那一块内存，互不影响。
*/
#endif

#if 1
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class myclass
{
public:
  myclass(char *data)
  {
    int len = strlen(data) + 1; //计算传进来的字符串长度
    this->data = new char[len]; //在堆区分配了len字节内存
    strcpy(this->data, data);   //将数据拷贝到我们在堆分配的内存中
  }
  //增加拷贝构造函数
  myclass(const myclass &mc)
  {
    int len = strlen(mc.data) + 1;
    this->data = new char[len];
    strcpy(this->data, mc.data);
  }
  //重载operator=操作符
  myclass &operator=(const myclass &mc)
  {
    int len = strlen(mc.data) + 1;
    this->data = new char[len];
    strcpy(this->data, mc.data);
    return *this;
  }
  //既然我们在堆区分配了内存，需要在析构函数中释放内存
  ~myclass()
  {
    if (NULL != this->data)
    {
      delete[] this->data;
      this->data = NULL;
    }
  }

private:
  char *data;
};

void test_deep_copy()
{
  char *data = “abcd”;
  myclass mc(data); //创建myclass的实例 并用char*字符串data初始化对象

  vector<myclass> v; //创建vector容器
  v.push_back(mc);   //将mc实例插入到vector容器尾部
}

int main()
{
  test_deep_copy(); //调用测试函数
  return 0;
}
#endif
