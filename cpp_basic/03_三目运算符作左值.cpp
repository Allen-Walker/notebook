#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
  int a = 10;
  int b = 20;
  int c = 0;
  c = (a < b) ? a : b;
  cout << c << endl;
  
  //三目运算符 可以当左值。
  ((a < b) ? a : b) = 50;

  cout << "a = " << a << endl;//a = 50
  cout << "b = " << b << endl;//b = 20

  return 0;
}