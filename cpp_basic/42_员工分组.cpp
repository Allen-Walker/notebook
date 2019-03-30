#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//multimap 案例
//公司今天招聘了 5 个员工，5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息

#define SALE_DEPATMENT 1     //销售部门
#define DEVELOP_DEPATMENT 2  //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门
#define ALL_DEPATMENT 4      //所有部门

//员工类
class person
{
public:
  string name;   //员工姓名
  int age;       //员工年龄
  double salary; //员工工资
  string tele;   //员工电话
};

//创建5个员工
void CreatePerson(vector<person> &vlist)
{

  string seed = "ABCDE";
  for (int i = 0; i < 5; i++)
  {
    person p;
    p.name = "员工";
    p.name += seed[i];
    p.age = rand() % 30 + 20;
    p.salary = rand() % 20000 + 10000;
    p.tele = "010-8888888";
    vlist.push_back(p);
  }
}

//5名员工分配到不同的部门
void PersonByGroup(vector<person> &vlist, multimap<int, person> &plist)
{

  int operate = -1; //用户的操作

  for (vector<person>::iterator it = vlist.begin(); it != vlist.end(); it++)
  {

    cout << "当前员工信息:" << endl;
    cout << "姓名：" << it->name << " 年龄:" << it->age << " 工资:" << it->salary << " 电话：" << it->tele << endl;
    cout << "请对该员工进行部门分配(1 销售部门, 2 研发部门, 3 财务部门):" << endl;
    scanf("%d", &operate);

    while (true)
    {

      if (operate == SALE_DEPATMENT)
      { //将该员工加入到销售部门
        plist.insert(make_pair(SALE_DEPATMENT, *it));
        break;
      }
      else if (operate == DEVELOP_DEPATMENT)
      {
        plist.insert(make_pair(DEVELOP_DEPATMENT, *it));
        break;
      }
      else if (operate == FINACIAL_DEPATMENT)
      {
        plist.insert(make_pair(FINACIAL_DEPATMENT, *it));
        break;
      }
      else
      {
        cout << "您的输入有误，请重新输入(1 销售部门, 2 研发部门, 3 财务部门):" << endl;
        scanf("%d", &operate);
      }
    }
  }
  cout << "员工部门分配完毕!" << endl;
  cout << "***********************************************************" << endl;
}

//打印员工信息
void printList(multimap<int, person> &plist, int myoperate)
{

  if (myoperate == ALL_DEPATMENT)
  {
    for (multimap<int, person>::iterator it = plist.begin(); it != plist.end(); it++)
    {
      cout << "姓名：" << it->second.name << " 年龄:" << it->second.age << " 工资:" << it->second.salary << " 电话：" << it->second.tele << endl;
    }
    return;
  }

  multimap<int, person>::iterator it = plist.find(myoperate);
  int depatCount = plist.count(myoperate);
  int num = 0;
  if (it != plist.end())
  {
    while (it != plist.end() && num < depatCount)
    {
      cout << "姓名：" << it->second.name << " 年龄:" << it->second.age << " 工资:" << it->second.salary << " 电话：" << it->second.tele << endl;
      it++;
      num++;
    }
  }
}

//根据用户操作显示不同部门的人员列表
void ShowPersonList(multimap<int, person> &plist, int myoperate)
{

  switch (myoperate)
  {
  case SALE_DEPATMENT:
    printList(plist, SALE_DEPATMENT);
    break;
  case DEVELOP_DEPATMENT:
    printList(plist, DEVELOP_DEPATMENT);
    break;
  case FINACIAL_DEPATMENT:
    printList(plist, FINACIAL_DEPATMENT);
    break;
  case ALL_DEPATMENT:
    printList(plist, ALL_DEPATMENT);
    break;
  }
}

//用户操作菜单
void PersonMenue(multimap<int, person> &plist)
{

  int flag = -1;
  int isexit = 0;
  while (true)
  {
    cout << "请输入您的操作((1 销售部门, 2 研发部门, 3 财务部门, 4 所有部门, 0退出)：" << endl;
    scanf("%d", &flag);

    switch (flag)
    {
    case SALE_DEPATMENT:
      ShowPersonList(plist, SALE_DEPATMENT);
      break;
    case DEVELOP_DEPATMENT:
      ShowPersonList(plist, DEVELOP_DEPATMENT);
      break;
    case FINACIAL_DEPATMENT:
      ShowPersonList(plist, FINACIAL_DEPATMENT);
      break;
    case ALL_DEPATMENT:
      ShowPersonList(plist, ALL_DEPATMENT);
      break;
    case 0:
      isexit = 1;
      break;
    default:
      cout << "您的输入有误，请重新输入!" << endl;
      break;
    }

    if (isexit == 1)
    {
      break;
    }
  }
}

int main()
{

  vector<person> vlist;        //创建的5个员工 未分组
  multimap<int, person> plist; //保存分组后员工信息

  //创建5个员工
  CreatePerson(vlist);
  //5名员工分配到不同的部门
  PersonByGroup(vlist, plist);
  //根据用户输入显示不同部门员工信息列表 或者 显示全部员工的信息列表
  PersonMenue(plist);

  system("pause");
  return EXIT_SUCCESS;
}