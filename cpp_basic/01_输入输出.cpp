#include <iostream>
using namespace std;

int main(void)
{
	int a = 0;
	cout << "hello world" << endl;
	cout << std::hex << 3.4 << endl;

	cin >> a;
	cout << "a= " << a << endl;

	return 0;
}

#if 0
#include <stdio.h>

int main(void)
{
	int a = 0;
	printf("hello world\n");

	scanf("%d", &a);

	return 0;
}
#endif