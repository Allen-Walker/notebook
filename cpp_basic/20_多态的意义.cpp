#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//英雄类
//1999
class Hero
{
public:
  virtual int getAd()
  {
    return 10;
  }
};

//1999
class AdvHero : public Hero
{
public:
  virtual int getAd() 
  {// 这里加不加virtual并没有太意义，习惯上加上，代表重写父类的虚函数，增加可读性
    return 1001;
  }
};

//怪兽类
//1999
class Monster
{
public:
  int getAd()
  {
    return 1000;
  }
};

//战斗方法
//1999 //写的架构函数，可以调用未来。
void playerFight(Hero *hp, Monster *mp)
{
  //多态对于编译器来讲的，也是一个动态联编，也是一个迟邦定。
  if (hp->getAd() > mp->getAd())
  { //hp->getAd 发生了多态
    cout << "英雄胜利， 怪兽被打死" << endl;
  }
  else
  {
    cout << "英雄挂了，怪兽赢了" << endl;
  }
}

//2020年
// 按照这种设计方法，如果想要升级程序，可以不用改变程序的框架
class BugHero : public Hero
{
public:
  virtual int getAd()
  {
    cout << "调用了bugHero的方法" << endl;
    return 66666;
  }
};

int main(void)
{
  Hero h;
  Monster m;
  playerFight(&h, &m);
  AdvHero advH;
  playerFight(&advH, &m);
  BugHero bH;
  playerFight(&bH, &m);

  return 0;
}