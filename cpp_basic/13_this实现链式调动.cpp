#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Num
{
public:
  Num(int m) { this->_m = m; }
  Num &add(Num &num)
  {
    this->_m += num.getM();
    return *this; //返回对象的本身
  }
  int getM() { return this->_m; }

private:
  int _m;
};

void test01()
{
  Num n1(1);
  Num n2(2);
  //n1=n1+n2+n2+n2
  n1.add(n2).add(n2).add(n2);

  cout << n1.getM() << endl; //7
  cout << n2.getM() << endl; //2
}

int main()
{
  test01();
  return 0;
}