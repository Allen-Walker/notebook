#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//方法一： 直接定义一个 包含10个int的数组 类型
typedef int(ARRAY_INT_10)[10];

//方法二：定义一个 包含10个int的数组 类型 的指针
typedef int (*ARRAY_INT_10_P)[10];

int main(void)
{
  int array[10]; //array 是一个指向int类型指针。
  // array 是 int* const 类型的，不可以作为左值，正好的等于 &array[0]
  

  //方法一：
  //ARRAY_INT_10 *array_10_p = &array; //*array_10_p === array

  //方法二：
  ARRAY_INT_10_P array_10_p = &array;

  for (int i = 0; i < 10; i++)
  {
    (*array_10_p)[i] = i + 10;
  }

  for (int i = 0; i < 10; i++)
  {
    cout << array[i] << endl;
  }

  //方法三：p为数组指针，指向 包含10个int类型的数组
  int(*p)[10] = &array;

  cout << "------" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << (*p)[i] << endl;
  }

  return 0;
}

/*
数组指针
  int (*p)[n];
  ()优先级高，首先说明p是一个指针，指向一个整型的一维数组，这个一维数组的长度是n，也可以
  说是p的步长。也就是说执行p+1时，p要跨过n个整型数据的长度。

指针数组
  int *p[n];
  []优先级高，先与p结合成为一个数组，再由int*说明这是一个整型指针数组，它有n个指针类型的数
  组元素。

*/