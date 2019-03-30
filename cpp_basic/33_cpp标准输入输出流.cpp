// cout; //全局流对象 输出数据到显示器
// cin;
// cerr; //标准错误  输出数据到显示器
// clog; //标准日志  输出数据到显示器

/*
注意事项：
1 cout流在内存中对应开辟了一个缓冲区,用来存放流中的数据,当向cout流插入一个
  endl时,不论缓冲区是否已满,都立即输出流中所有数据,然后插入一个换行符,并刷新
  流(清空缓冲区)。注意如果插人一个换行符”\n“(如cout<<a<<"\n"),则只输出和换
  行,而不刷新cout流(但并不是所有编译系统都体现出这一区别)。
2 cerr是不经过缓冲区,直接向显示器上输出有关信息,而clog
  中的信息存放在缓冲区中,缓冲区满后或遇endl时向显示器输出。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <iomanip>
#include <string.h>

/*
标准输入流对象 cin,重点掌握的函数
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
void test01()
{
  char ch;
  while ((ch = cin.get()) != EOF)
  {
    cout << ch << endl;
  }
  // 只要输入字符，就会进行显示。包含换行符。死循环
}

void test02()
{
  char c1, c2, c3;
  //链式编程
  cin.get(c1).get(c2).get(c3);
  cout << c1 << endl;
  cout << c2 << endl;
  cout << c3 << endl;
}

void test03()
{
  char str[256];
  //读入字符串
  cin >> str; //碰到空格不继续输出了
  cout << str << endl;
}

void test04()
{
  char str[256];
  //读入字符串
  cin.getline(str, 256); //读入一行数据，自动跳过换行符
  cout << str << endl;
}

void test05()
{
  //cin.ignore() 默认忽略当前的字符 形参n表示从当前位置开始忽略n个字符
  char buf1[256];
  cin >> buf1;
  cout << "buf1:" << buf1 << endl;
  cin.ignore(2);

  char c = cin.peek(); //peek 只是偷窥缓冲区中的数据,并不取走数据
  cout << c << endl;

  char buf2[256];
  cin.getline(buf2, 256);
  cout << "buf2:" << buf2 << endl;
}

void test06()
{
  cout << "输入一个字符串或者一个数字：" << endl;
  char ch = cin.get(); //从缓冲区取走一个字符
  if (ch >= '0' && ch <= '9')
  {
    int number;
    cin.putback(ch);
    cin >> number; //cin.putback() 将数据放回缓冲区
    cout << "数字：" << number << endl;
  }
  else
  {
    char buf[1024] = {0};
    cin.putback(ch);
    cin.getline(buf, 1024);
    cout << "字符串:" << buf << endl;
  }
  //这里数字开头的字符串不能很好的区分
}

/*
cout.flush() //刷新缓冲区
cout.put() //向缓冲区写字符
cout.write() //二进制流的输出
cout.width() //输出格式控制
cout.fill()
cout.setf(标记)
*/
void test07()
{
  cout << "hello world!" << endl;
  cout.put('h').put('e').put('l') << endl;
}

void test08()
{
  const char *str = "hello world!";
  //warning: ISO C++ forbids converting a string constant to ‘char*’
  cout.write(str, strlen(str)) << endl;
  cout.write(str, strlen(str) - 2) << endl;
}

void test09()
{
  int a;
  cout << "input a:";
  cin >> a;
  cout << "dec:" << dec << a << endl;             //以十进制形式输出整数
  cout << "hex:" << hex << a << endl;             //以十六进制形式输出整数 a
  cout << "oct:" << setbase(8) << a << endl;      //以八进制形式输出整数 a
  const char *pt = "China";                       //pt 指向字符串"China"
  cout << setw(10) << pt << endl;                 //指定域宽为,输出字符串
  cout << setfill('*') << setw(10) << pt << endl; //指定域宽,输出字符串,空白处以'*'填充
  double pi = 22.0 / 7.0;                         //计算 pi 值
  //按指数形式输出,8 位小数
  cout << setiosflags(ios::scientific) << setprecision(8);
  cout << "pi=" << pi << endl;                            //输出 pi 值
  cout << "pi=" << setprecision(4) << pi << endl;         //改为位小数
  cout << "pi=" << setiosflags(ios::fixed) << pi << endl; //改为小数形式输出

  //成员方法的方式
  int number = 10;
  cout << number << endl;
  cout.unsetf(ios::dec); //卸载当前默认的的10进制输出方式
  cout.setf(ios::oct);   //八进制输出
  cout.setf(ios::showbase);
  cout << number << endl;
  cout.unsetf(ios::oct); //卸载8进制
  cout.setf(ios::hex);
  cout << number << endl;

  cout.width(10);
  cout.fill('*');
  cout.setf(ios::left);
  cout << number << endl;

  //通过控制符
  int number2 = 10;
  cout << hex
       << setiosflags(ios::showbase)
       << setw(10)
       << setfill('*')
       << setiosflags(ios::left)
       << number2
       << endl;
}

void test()
{
  int a = 21;
  cout.setf(ios::showbase);    //显示基数符号(0x 或)
  cout << "dec:" << a << endl; //默认以十进制形式输出 a
  cout.unsetf(ios::dec);       //终止十进制的格式设置
  cout.setf(ios::hex);         //设置以十六进制输出的状态
  cout << "hex:" << a << endl; //以十六进制形式输出 a
  cout.unsetf(ios::hex);       //终止十六进制的格式设置
  cout.setf(ios::oct);         //设置以八进制输出的状态
  cout << "oct:" << a << endl; //以八进制形式输出 a
  cout.unsetf(ios::oct);
  const char *pt = "China";           //pt 指向字符串"China"
  cout.width(10);               //指定域宽为
  cout << pt << endl;           //输出字符串
  cout.width(10);               //指定域宽为
  cout.fill('*');               //指定空白处以'*'填充
  cout << pt << endl;           //输出字符串
  double pi = 22.0 / 7.0;       //输出 pi 值
  cout.setf(ios::scientific);   //指定用科学记数法输出
  cout << "pi=";                //输出"pi="
  cout.width(14);               //指定域宽为
  cout << pi << endl;           //输出 pi 值
  cout.unsetf(ios::scientific); //终止科学记数法状态
  cout.setf(ios::fixed);        //指定用定点形式输出
  cout.width(12);               //指定域宽为
  cout.setf(ios::showpos);      //正数输出“+”号
  cout.setf(ios::internal);     //数符出现在左侧
  cout.precision(6);            //保留位小数
  cout << pi << endl;           //输出 pi,注意数符“+”的位置
}

int main(void)
{
  test();
  return 0;
}