#include "str.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	MyString a, b;
	char tmp1[100], tmp2[100];

	cout << "첫번재 문자열 입력 : ";
	cin.getline(tmp1, strlen(tmp1));

	cout << "두번째 문자열 입력 : ";
	cin.getline(tmp2, strlen(tmp2));

	a.setStr(tmp1);
	b.setStr(tmp2);

	cout << "더 긴 문자열은 : ";
	if(a.getLen() >= b.getLen())
	{
		cout << a.getStr() << "(" << a.getLen() << ")" << endl;
	}
	else
	{
		cout << b.getStr() << "(" << b.getLen() << ")" << endl;
	}
	
	return 0;
}