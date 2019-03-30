/*
  string和char*类型的字符串的对比：
  1 char*是一个指针，String是一个类封装了char*，是一个char*型的容器。
  2 string封装了很多实用的成员方法
  3 不用考虑内存释放和越界
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// string 和 char* 互转
void test01()
{
  //string 转 char*
  string str = "lijunxi";
  const char *cstr = str.c_str();

  //char* 转 string
  const char *s = "lijunxi";
  string sstr(s);
}

// 构造函数
void test02()
{
  // string();                  //创建一个空的字符串 例如: string str;
  // string( string &str);      //使用一个string对象初始化另一个string对象
  // string(const char *s);     //使用字符串s初始化
  // string(int n, char c);     //使用n个字符c初始化

  //例子:
  //默认构造函数
  string s1;
  //拷贝构造函数
  string s2(s1);
  string s3 = s1;
  //带参数构造函数
  const char *str = "lijunxi";
  // 如果没有加 const -- ISO C++ forbids converting a string constant to ‘char*’
  string s4(str);
  string s5(10, 'a');
}

// string基本赋值操作
void test03()
{
  // string &operator=(const char *s);                  //char*类型字符串 赋值给当前的字符串
  // string &operator=(const string &s);                //把字符串s赋给当前的字符串
  // string &operator=(char c);                         //字符赋值给当前的字符串
  // string &assign(const char *s);                     //把字符串s赋给当前的字符串
  // string &assign(const char *s, int n);              //把字符串s的前n个字符赋给当前的字符串
  // string &assign(const string &s);                   //把字符串s赋给当前字符串
  // string &assign(int n, char c);                     //用n个字符c赋给当前字符串
  // string &assign(const string &s, int start, int n); //将s从start开始n个字符赋值给字符串
  
  //成员方法assign
  string s1;
  s1 = "lijunxi";
  cout << s1 << endl;
  s1.assign("ljx");
  cout << s1 << endl;
}

// string存取字符操作
void test04()
{
  // char &operator[](int n); //通过[]方式取字符
  // char &at(int n);         //通过at方法获取字符
  // 1 相同,[]和at都可以返回第n个字符
  // 2 不同，at访问越界会抛出异常，[]越界会直接程序会挂掉。

  //例子:
  string s = "lijunxi";
  char c = s[1];
  c = s.at(1);

  try
  {
    //cout << s[100] << endl;
    cout << s.at(100) << endl;
  }
  catch (...)
  {
    cout << "越界!" << endl;
  }
}

// string拼接操作
void test05()
{
  // string &operator+=(const string &str);           //重载+=操作符
  // string &operator+=(const char *str);             //重载+=操作符
  // string &operator+=(const char c);                //重载+=操作符
  // string &append(const char *s);                   //把字符串s连接到当前字符串结尾
  // string &append(const char *s, int n);            //把字符串s的前n个字符连接到当前字符串结尾
  // string &append(const string &s);                 //同operator+=()
  // string &append(const string &s, int pos, int n); //把字符串s中从pos开始的n个字符连接到当前字符串结尾
  // string &append(int n, char c);                   //在当前字符串结尾添加n个字符c

  string s = "aaaa";
  string s2 = "bbbb";
  s += "cccc";
  s += s2;
  cout << s << endl;

  string s3 = "dddd";
  s2.append(s3);
  cout << s2 << endl;

  string s4 = s2 + s3;
  cout << s4 << endl;
}

// string查找和替换
void test06()
{
  // int find(const string &str, int pos = 0) const;     //查找str第一次出现位置,从pos开始查找
  // int find(const char *s, int pos = 0) const;         //查找s第一次出现位置,从pos开始查找
  // int find(const char *s, int pos, int n) const;      //从pos位置查找s的前n个字符第一次位置
  // int find(const char c, int pos = 0) const;          //查找字符c第一次出现位置
  // int rfind(const string &str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
  // int rfind(const char *s, int pos = npos) const;     //查找s最后一次出现位置,从pos开始查找
  // int rfind(const char *s, int pos, int n) const;     //从pos查找s的前n个字符最后一次位置
  // int rfind(const char c, int pos = 0) const;         //查找字符c最后一次出现位置
  // string &replace(int pos, int n, const string &str); //替换从pos开始n个字符为字符串str
  // string &replace(int pos, int n, const char *s);     //替换从pos开始的n个字符为字符串s
  
  string s = "abcdefghjfgkl";
  //查找第一次出现的位置
  int pos = s.find("fg");
  cout << "pos:" << pos << endl;

  //查找最后一次出现的位置
  pos = s.rfind("fg");
  cout << "pos:" << pos << endl;

  string s1 = "abcdefg";
  s1.replace(0, 2, "111"); //注意下标的取值
  cout << s1 << endl;
}

void test07(){
  /*
    compare函数在>时返回 1，<时返回 -1，==时返回 0。
    比较区分大小写，比较时参考字典顺序，排越前面的越小。
    大写的A比小写的a小。
  */
  // int compare(const string &s) const; //与字符串s比较
  // int compare(const char *s) const;   //与字符串s比较

  string s1 = "abcd";
  string s2 = "abce";

  if (s1.compare(s2) == 0)
  {
    cout << "字符串相等!" << endl;
  }
  else
  {
    cout << "字符串不相等!" << endl;
  }
}

// string子串
void test08(){
  // string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
  
  string s = "abcdefg";
	string mysubstr = s.substr(1, 3);
	cout << mysubstr << endl;
}

// 插入和删除
void test()
{
  // string &insert(int pos, const char *s);     //插入字符串
  // string &insert(int pos, const string &str); //插入字符串
  // string &insert(int pos, int n, char c);     //在指定位置插入n个字符c
  // string &erase(int pos, int n = npos);       //删除从Pos开始的n个字符

  string s = "abcdefg";
  s.insert(3, "111");
  cout << s << endl;

  s.erase(0, 2);
  cout << s << endl;
}

int main()
{
  test();
  return 0;
}