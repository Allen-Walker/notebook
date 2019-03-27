#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//抽象的员工
class Employee
{
public:
  Employee()
  {
    cout << "Employee()..." << endl;
    id = startNum++;
    level = 1;
    salary = 0.0;
  }
  virtual ~Employee()
  {
    cout << "~Employee().." << endl;
  }

  //提供一个现实的初始化员工的函数
  virtual void init() = 0;

  //提供员工薪资的计算方法
  virtual void getPay() = 0;
  //显示员工的信息
  void displayStatus()
  {
    cout << "员工姓名" << this->name << endl;
    cout << "员工的级别" << this->level << endl;
    cout << "员工的月薪 " << this->salary << endl;
    cout << "员工的ID" << this->id << endl;
  }
  //提供修改员工级别的方法
  virtual void upLevel(int level) = 0;

protected:
  string name;   //姓名
  int id;        //编号
  double salary; //薪资
  int level;     //级别

  //员工的编号基础值
  static int startNum;
};
// 静态类成员类外初始化
int Employee::startNum = 1000;

class Manager : virtual public Employee
{
public:
  Manager()
  {
    cout << "Manager().." << endl;
  }

  ~Manager()
  {
    cout << "~Manager().." << endl;
  }

  //提供一个现实的初始化员工的函数
  virtual void init()
  {
    cout << "请输入经理的姓名" << endl;
    cin >> name;
    this->fixSalary = 8000;
  }

  virtual void getPay()
  {
    //计算薪水的方式
    this->salary = this->fixSalary;
  }

  //提供修改员工级别的方法
  virtual void upLevel(int level)
  {
    this->level += level;

    if (this->level == 1)
    {
      this->fixSalary = 8000;
    }
    else if (this->level == 2)
    {
      this->fixSalary = 10000;
    }
  }

protected:
  double fixSalary; //经理的固定工资
};

class SalesMan : virtual public Employee
{
public:
  SalesMan()
  {
    cout << "SaleMan()..." << endl;
  }
  ~SalesMan()
  {
    cout << "~SaleMan().." << endl;
  }

  //提供员工薪资的计算方法
  virtual void getPay()
  {
    cout << "请输入当月的销售额" << endl;
    cin >> this->saleAmount;

    //计算当月的月薪
    this->salary = this->saleAmount * this->salePercent;
  }

  virtual void init()
  {
    cout << "请输入销售员工的姓名" << endl;
    cin >> this->name;
    this->salePercent = 0.04;
  }

  //提供修改员工级别的方法
  virtual void upLevel(int level)
  {
    this->level += level;
    if (this->level == 1)
    {
      this->salePercent = 0.04;
    }
  }

protected:
  //当月的销售额
  int saleAmount;
  //提成的比率
  double salePercent;
};

class SalesManager : public Manager, public SalesMan
{
public:
  SalesManager()
  {
    cout << "SalesManager().." << endl;
  }
  ~SalesManager()
  {
    cout << "~SalesManager()..." << endl;
  }

  virtual void init()
  {
    cout << "请输入销售经理的姓名" << endl;
    cin >> name;
    fixSalary = 5000;
    salePercent = 0.05;
  }

  //提供员工薪资的计算方法
  virtual void getPay()
  {
    cout << "请输入当月的销售额" << endl;
    cin >> this->saleAmount;

    this->salary = this->saleAmount * this->salePercent + this->fixSalary;
  }

  //提供修改员工级别的方法
  virtual void upLevel(int level)
  {
    this->level += level;
  }
};

class Technician : public Employee
{
public:
  Technician()
  {
    cout << "Technician().." << endl;
  }
  ~Technician()
  {
    cout << "~Technician()..." << endl;
  }

  virtual void init()
  {
    cout << "请输入员工的姓名" << endl;
    cin >> name;
    perHourMoney = 100; //默认员工每小时赚100元
  }

  //提供员工薪资的计算方法
  virtual void getPay()
  {
    cout << "请输入该员工 一共工作了多少小时" << endl;
    cin >> workHour;

    this->salary = this->perHourMoney * this->workHour;
  }

  //升级的方法
  virtual void upLevel(int level)
  {
    this->level += level;
  }

private:
  //一个月工作了多少小时
  int workHour;
  //每小时多钱
  double perHourMoney;
};

int main(void)
{

#if 0
	Employee *em1 = new Technician;

	em1->getPay();
	em1->upLevel(1);
	em1->displayStatus();

	delete em1;
#endif
#if 0
	Employee *em = new Manager;
	em->upLevel(1);
	em->getPay();
	em->displayStatus();
	
	delete em;
#endif
#if 0
	Employee *em = new SalesMan;

	em->upLevel(0);
	em->getPay();
	em->displayStatus();

	delete em;
#endif
#if 0
	Employee *em = new SalesManager;
	
	em->init();
	em->upLevel(1);
	em->getPay();
	em->displayStatus();

	delete em;
#endif
  Employee *person_array[] = {new Technician, new Manager, new SalesMan, new SalesManager};

  for (int i = 0; i < sizeof(person_array) / sizeof(person_array[0]); i++)
  {
    person_array[i]->init();
    person_array[i]->upLevel(0);
    person_array[i]->getPay();
    person_array[i]->displayStatus();
  }

  for (int i = 0; i < sizeof(person_array) / sizeof(person_array[0]); i++)
  {
    delete person_array[i];
  }

  return 0;
}