/*
 *函数模板和普通函数的区别?
 * 函数模板不允许自动类型转化
 * 普通函数能够自动进行类型转化
 *
 *函数模板和普通函数在一起调用规则:
 * 函数模板可以想普通函数那样可以被重载
 * c++编译器优先考虑普通函数
 * 如果函数模板可以产生一个更好的匹配,那么选择模板
 * 可以通过空模板实参列表的语法限定编译器只能通过模板匹配
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//普通函数
void SwapData(int a, int b)
{
  cout << "普通函数!" << endl;
  int temp = a;
  a = b;
  b = temp;
}

//模板函数
template <class Type>
void SwapData(Type &a, Type &b)
{
  cout << "函数模板!" << endl;
  Type temp = a;
  a = b;
  b = temp;
}
//重载函数模板
template <class Type>
void SwapData(Type &a, Type &b, Type &c)
{
  cout << "函数模板!" << endl;
  Type temp = a;
  a = b;
  b = temp;
}
int main()
{
  int a = 10;
  int b = 20;
  double c = 3.0;
  double d = 4.0;
  
  SwapData(a, b);    //普通函数和函数模板都符合条件,这种情况下优先考虑普通函数
  SwapData<>(b, a);  //告诉编译器,只使用函数模板
  SwapData(c, d);    //如何函数模板能产生更好的匹配 使用函数模板
  SwapData(a, b, b); //函数模板
  SwapData(a, c);    //调用普通函数,可隐式转换
  //函数模板调用,将会严格匹配类型,不会进行自动类型转换
  //普通函数调用,可以进行隐式类型转换
  return 0;
}