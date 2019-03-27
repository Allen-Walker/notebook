#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//定义一个命名空间
namespace spaceA {
	int a = 10;
}

void test01(){
	//方式1：
	//using spaceA::a;
	//cout << a << endl;

	//方式2：
	//cout << spaceA::a << endl;
	
	//方式3：
	using namespace spaceA;
	cout << a << endl;
}

namespace spaceB {
	string name="spaceB";
	namespace spaceC {
		string name="spaceC";
	}

	namespace spaceD {
		string name="spaceD";
	}
	// using namespace spaceC;
	// using namespace spaceD;
	// 注释string name="spaceB";
	// 会报错 reference to ‘name’ is ambiguous 
	// 注意空间嵌套避免产生二义性。
}

void test02(){
	cout<<spaceB::name<<endl;        //spaceD
	cout<<spaceB::spaceC::name<<endl;//spaceC
	cout<<spaceB::spaceD::name<<endl;//spaceD
}

int main(void)
{
	test01();
	cout<<"------------------------------------------------------------"<<endl;

test02();

	return 0;
}