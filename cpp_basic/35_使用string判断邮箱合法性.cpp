//用户邮箱地址验证
// 1 判断邮箱有效性 是否包含@和. 并且.在@之后
// 2 判断用户输入的用户名中是否包含除了小写字母之外字符(ASCII范围97~122)
// 3 判断用户输入的邮箱地址是否正确(zhaosi@itcast.cn)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// 1 判断邮箱有效性 是否包含@和.并且.在@之后
bool Check_Valid(string &email)
{

  int pos1 = email.find("@");
  int pos2 = email.find(".");

  //判断@和.是否存在
  if (pos1 == -1 || pos2 == -1)
  {
    return false;
  }
  //判断@在.之前
  if (pos1 > pos2)
  {
    return false;
  }

  return true;
}

//2 判断用户输入的用户名中是否包含除了小写字母之外字符(ASCII范围97~122)
bool Check_Username(string &email)
{

  int pos = email.find("@");
  string username = email.substr(0, pos - 1);
  for (string::iterator it = username.begin(); it != username.end(); it++)
  {
    if (*it < 97 || *it > 122)
    {
      return false;
    }
  }

  return true;
}

// 3 判断用户输入的邮箱地址是否正确(zhaosi@itcast.cn)
bool Check_EqualtTo(string &email)
{

  string rightEmail = "zhaosi@itcast.cn";
  if (email.compare(rightEmail) != 0)
  {
    return false;
  }
  return true;
}

void testEmail()
{

  //用户邮箱地址验证
  // 1 判断邮箱有效性 是否包含@和. 并且.在@之后
  // 2 判断用户输入的用户名中是否包含除了小写字母之外字符(ASCII范围97~122)
  // 3 判断用户输入的邮箱地址是否正确(zhaosi@itcast.cn)

  string email;
  cout << "请输入您的邮箱：" << endl;
  cin >> email;

  bool flag = Check_Valid(email);
  if (!flag)
  {
    cout << "emain格式不合法!" << endl;
    return;
  }

  flag = Check_Username(email);
  if (!flag)
  {
    cout << "用户名中包含除小写字母之外的字母!" << endl;
    return;
  }

  flag = Check_EqualtTo(email);
  if (!flag)
  {
    cout << "邮箱地址不正确!" << endl;
    return;
  }

  cout << "邮箱输入正确!" << endl;
}

int main()
{
  testEmail();
  return 0;
}