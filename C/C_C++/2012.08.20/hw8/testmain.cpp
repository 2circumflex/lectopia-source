#include "str.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	MyString a, b;
	char tmp1[100], tmp2[100];

	cout << "ù���� ���ڿ� �Է� : ";
	cin.getline(tmp1, strlen(tmp1));

	cout << "�ι�° ���ڿ� �Է� : ";
	cin.getline(tmp2, strlen(tmp2));

	a.setStr(tmp1);
	b.setStr(tmp2);

	cout << "�� �� ���ڿ��� : ";
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