#include "Person.h"

//函数模板 经过2次编译
//并没有生成具体的函数
template <class T>
Person<T>::Person(T age)
{
  this->age = age;
}

template <class T>
void Person<T>::Show()
{
  cout << "Age：" << age << endl;
}

// 解决模板c文件和h文件分开书写未定义的错误
// void test(){
//   Person<int> p(10); 
//   p.Show();
// }
