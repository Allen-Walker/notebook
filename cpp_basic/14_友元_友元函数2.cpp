#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

class Point; //声明Point,否则在PointManager看不到

class PointManager
{
public:
  double PointDistance(Point &p1, Point &p2);//不可在这里实现，这里看不到Point的成员
};

class Point
{
public:
  friend double PointManager::PointDistance(Point &p1, Point &p2);

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

//有了Point实现，可以看到的Point的成员的，在这里实现PointManager
double PointManager::PointDistance(Point &p1, Point &p2)
{
  double dis;
  int dd_x = p1.x - p2.x;
  int dd_y = p1.y - p2.y;

  dis = sqrt(dd_x * dd_x + dd_y * dd_y);

  return dis;
}

int main(void)
{

  Point p1(1, 2);
  Point p2(2, 2);

  PointManager pm;
  cout << pm.PointDistance(p1, p2) << endl;

  return 0;
}