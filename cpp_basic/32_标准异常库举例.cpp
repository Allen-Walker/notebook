#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>//C++标准异常库
#include <string.h>
using namespace std;

class Person
{
public:
  Person()
  {
    mAge = 0;
  }
  void setAge(int age)
  {
    if (age < 0 || age > 100)
    {
      throw out_of_range("年龄应该在0-100之间!");
    }
    this->mAge = age;
  }

public:
  int mAge;
};

void test01()
{

  Person p;

  try
  {
    p.setAge(1000);
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }
}

class MyOutOfRange : public exception
{
public:
  MyOutOfRange(const char *error)
  {
    pError = new char[strlen(error) + 1];
    strcpy(pError, error);
  }
  ~MyOutOfRange()
  {
    if (pError != NULL)
    {
      delete[] pError;
    }
  }
  
  virtual const char* what()//const //这里为什么不能使用const修饰
  {//error: overriding ‘virtual const char* std::exception::what() const noexcept’
    return pError;
  };

public:
  char *pError;
};

void fun02()
{
  throw MyOutOfRange("我自己的out_of_range!");
}

void test02()
{

  try
  {
    fun02();
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }
}

int main(void)
{
  test01();
  //test02();
  return 0;
}
/*
编写自己的异常类——添加自己的信息
1 自己的异常类要继承标准异常类。
2 当继承标准异常类时,应该重载父类的 what 函数和虚析构函数。
3 因为栈展开的过程中,要复制异常类型,那么要根据你在类中添加的成员考虑是否提供自己的复制构造函数。
*/