#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

class PointManager; //让Point中能看到PointManager

class Point
{
public:
  friend PointManager;

  Point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }

  int getX()
  {
    return this->x;
  }

  int getY()
  {
    return this->y;
  }

private:
  int x;
  int y;
};

class PointManager
{
public:
  double PointDistance(Point &p1, Point &p2)
  {
    double dis;
    int dd_x = p1.x - p2.x;
    int dd_y = p1.y - p2.y;

    dis = sqrt(dd_x * dd_x + dd_y * dd_y);

    return dis;
  }
};

int main(void)
{

  Point p1(1, 2);
  Point p2(2, 2);

  PointManager pm;
  cout << pm.PointDistance(p1, p2) << endl;

  return 0;
}

// 如果B是A友元，且B中还有A的实例，这个和 B是A的子类 这种设计方法有什么异同和有缺点？

/*
1 友元声明以关键字friend 开始,它只能出现在类定义中。因为友元不是授
  权类的成员,所以它不受其所在类的声明区域public private 和protected 的影
  响。通常我们选择把所有友元声明组织在一起并放在类头之后.
2 友元不是类成员,但是它可以访问类中的私有成员。
3 注意事项
  (1)友元关系不能被继承。
  (2)友元关系是单向的,不具有交换性。若类 B 是类 A 的友元,类 A 不一定是类B 的友元,要看在类中是否有相应的声明。
  (3)友元关系不具有传递性。若类 B 是类 A 的友元,类 C 是 B 的友元,类 C 不一定是类 A 的友元,同样要看类中是否有相应的声明。
*/