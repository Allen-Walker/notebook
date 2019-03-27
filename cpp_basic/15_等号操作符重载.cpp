#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Person
{
public:
  char *m_name; //char m_name[64] //则不用担心深拷贝浅拷贝的问题
  int m_sex;

  Person()
  {
    this->m_sex = 0;
    this->m_name = NULL;
  }

  Person(const char *name, int sex)
  {
    if (name)
    {
      m_name = (char *)malloc(strlen(name) + 1);
      strcpy(m_name, name);
    }

    m_sex = sex;
  }

  Person(const Person &another)
  {
    //深拷贝

    m_name = new char[strlen(another.m_name) + 1];
    strcpy(m_name, another.m_name);
    m_sex = another.m_sex;
  }

  Person &operator=(const Person &another) //返回值为Person & -- 可以进行连等操作
  {
    //防止自身赋值
    if (this == &another)
      return *this;
    //回收自身堆中资源
    if (this->m_name)
    {
      delete[] this->m_name;
      this->m_sex = 0;
    }
    // 进行深拷贝
    m_name = new char[strlen(another.m_name) + 1];
    strcpy(m_name, another.m_name);
    m_sex = another.m_sex;
    return *this;
  }

  ~Person()
  {
    if (m_name)
    {
      delete[] this->m_name;
      this->m_name = NULL;
    }
  }
};

int main(void)
{

  return 0;
}