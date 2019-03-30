/*
STL内建了一些函数对象。分为:算数类函数对象,关系运算类函数对象，逻辑运算
类仿函数。这些仿函数所产生的对象，用法和一般函数完全相同，当然我们还可以
产生无名的临时对象来履行函数功能。使用内建函数对象，需要引入头文件 
#include<functional>。

6个算数类函数对象,除了negate是一元运算，其他都是二元运算。
template<class T> T plus<T>       //加法仿函数
template<class T> T minute<T>     //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T>    //除法仿函数
template<class T> T modulus<T>    //取模仿函数
template<class T> T negate<T>     //取反仿函数

6个关系运算类函数对象,每一种都是二元运算。
template<class T> bool equal_to<T>      //等于
template<class T> bool not_equal_to<T>  //不等于
template<class T> bool greater<T>       //大于
template<class T> bool greater_equal<T> //大于等于
template<class T> bool less<T>          //小于
template<class T> bool less_equal<T>    //小于等于

逻辑运算类运算函数,not为一元运算，其余为二元运算。
template<class T> bool logical_and<T>   //逻辑与
template<class T> bool logical_or<T>    //逻辑或
template<class T> bool logical_not<T>   //逻辑非

*/

