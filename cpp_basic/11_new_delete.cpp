#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class MyClass
{
public:
  int m_a;
  MyClass() { cout << "构造函数被调用" << endl; };
  ~MyClass() { cout << "析构函数被调用" << endl; }

  void showA() { cout << m_a << endl; }
};

//C语言中
void test01()
{
  int *p = (int *)malloc(sizeof(int));
  *p = 10;
  if (p != NULL)
  {
    free(p);
    //delete p;
    p = NULL;
  }

  int *pArray = (int *)malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++)
  {
    pArray[i] = i + 1;
  }
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", pArray[i]);
  }
  if (pArray != NULL)
  {
    free(pArray);
    pArray = NULL;
  }

  printf("\n");

  MyClass *mc = (MyClass *)malloc(sizeof(MyClass));
  mc->showA();
  if (mc != NULL)
  {
    free(mc);
    mc = NULL;
  }
}

//malloc free 是函数，标准库，stdlib.h
//malloc不会调用类的构造函数,而new会调用类的构造函数
//Free不会调用类的析构函数,而delete会调用类的析构函数

//C++中
void test02()
{
  int *p = new int;
  *p = 10;
  if (p != NULL)
  {
    free(p);
    p = NULL;
  }

  int *array_p = new int[10];
  for (int i = 0; i < 10; i++)
  {
    array_p[i] = i + 1;
  }
  for (int i = 0; i < 10; i++)
  {
    cout << array_p[i] << " ";
  }
  if (array_p != NULL)
  {
    delete[] array_p;
  }

  cout << endl;

  MyClass *mc = new MyClass;
  mc->showA();
  if (mc != NULL)
  {
    delete mc;
    mc = NULL;
  }
}

int main(void)
{
  test01();
  cout << "-----------" << endl;
  test02();
  return 0;
}
