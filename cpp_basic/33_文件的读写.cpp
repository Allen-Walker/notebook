/*
文件的读写
文件输入流 ifstream
文件输出流 ofstream
文件输入输出流 fstream
文件的打开方式
文件流的状态
文件流的定位:文件指针(输入指针、输出指针)
文本文件和二进制文件

ifstream 类,它是从 istream 类派生的,用来支持从磁盘文件的输入。
ofstream 类,它是从 ostream 类派生的,用来支持向磁盘文件的输出。
fstream 类,它是从 iostream 类派生的,用来支持对磁盘文件的输入输出。
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream> //文件读写

/*
  1)file.open()为文件流对象和指定的磁盘文件建立关联,以便使文件流流向指定的磁盘文件。
    指定文件的工作方式,如,该文件是作为输入文件还是输出文件,是ASCII文件还是二进制文
    件等。可以用“位或”运算符“|”对输入输出方式进行组合
    ios::in | ios:: noreplace //打开一个输入文件,若文件不存在则返回打开失败的信息
    ios::app | ios::nocreate //打开一个输出文件,在文件尾接着写数据,若文件不存在,则
                             //返回打开失败的信息
    ios::out | ios::noreplace //打开一个新文件作为输出文件,如果文件已存在则返回打开失败的信息
    ios::in | ios::out | ios::binary //打开一个二进制文件,可读可写
    ios::ate 文件打开后定位到文件尾,ios:app 就包含有此属性
    ios::trunc 如果文件存在,把文件长度设为0
    但不能组合互相排斥的方式,如 ios::nocreate l ios::noreplace。
  
  2)如果打开操作失败,open函数的返回值为0(假),如果是用调用构造函数的方式打开文件的,则流对
    象的值为0。可以据此测试打开是否成功。

  3)每一个打开的文件都有一个文件指针,该指针的初始位置由I/O方式指定,每次读写都
    从文件指针的当前位置开始。每读入一个字节,指针就后移一个字节。当文件指针移到最
    后,就会遇到文件结束EOF(文件结束符也占一个字节,其值为-1),此时流对象的成员函数
    eof的值为非0值(一般设为1),表示文件结束了。
  
  4)file.close();//将输出文件流所关联的磁盘文件关闭.解除该磁盘文件与文件流的关联,原来
    设置的工作方式也失效,这样,就不能再通过文件流对该文件进行输入或输出。

  5)openprot 属性表
    属性 含义
    0   普通文件,打开访问
    1   只读文件
    2   隐含文件
    4   系统文件
*/
void test01()
{
  ofstream outfile;                 //定义ofstream类(输出文件流类)对象outfile
  outfile.open("f1.dat", ios::out); //使文件流与f1.dat文件建立关联
  outfile.close();
}

/*
C++对 ASCII 文件的读写操作
ASCII 文件——文件的每一个字节中均以 ASCII 代码形式存放数据
1) 用流插入运算符“<<”和流提取运算符“>>”输入输出标准类型的数据。
2）用文件流的 put、get、geiline 等成员函数进行字符的输入输出。
  用 C++流成员函数 put输出单个字符、C++ get()函数读入一个字符和
  C++ getline()函数读入一行字符。
*/
void test02()
{ //ofstream 是输出流，我 将信息输出 到 文件
  //ifstream 是输入流，文件 将信息输入 到 我
  //文件流对象是第一个形参,标准输入输出重载<<和>>也是第一个形参
  const char *fileName = "text.txt";
  ofstream fout(fileName, ios::app | ios::trunc);
  fout << "1111111111111111111\n";
  fout << "2222222222222222222\n";
  //cin.ignore(1,'\n');

  char buffer[256];
  cin.getline(buffer, 255); //从键盘输入
  fout << buffer << "\n";
  fout.close();

  ifstream fin(fileName);
  cout << "Here's the the content of the file: \n";
  char ch;
  while (fin.get(ch))
    cout << ch;
  cout << "\n***End of file contents.***\n";
  fin.close();
}

/*
C++对二进制文件的读写操作
二进制文件——不是以 ASCII 代码存放数据的,它将内存中数据存储形式不加转换地传送到
          磁盘文件,因此它又称为内存数据的映像文件。

istream& read(char *buffer,int len);
ostream& write(const char * buffer,int len);
字符指针 buffer 指向内存中一段存储空间。len 是读写的字节数。
*/
// 图片文件
void test03()
{
  ofstream fout("new.png", ios::binary);
  if (!fout)
  {
    return;
  }

  ifstream fin("1.png", ios::binary);
  if (!fin)
  {
    return;
  }

  char buffer[256];
  // fin被读 fout被写
  while (fin.read(buffer, 256))
  {
    fout.write(buffer, 256);
  }

  if (fout)
    fout.close();
  if (fin)
    fin.close();
}

int main(void)
{
  test02();
  return 0;
}