#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

class Test
{
private:
	char str[80];
public:
	Test(char *s) { strcpy(str, s); }
	~Test() { cout << str << "��ü�� �Ҹ��� ȣ��.." << endl; }
};

int mod1(int x, int y);
int mod2(int x, int y);

int main()
{
	int a, b, res;
	Test ob("main�� ob��ü");

	cout << "�� ���� �Է� : ";
	cin >> a >> b;

	try
	{
		res = mod2(a, b);
	}
	catch(char *s)
	{
		cout << s << endl;
		//exit(1);
		return 0;
	}

	cout << "���� �ι� : " << res << endl;

	return 0;
}

int mod2(int x, int y)
{
	Test a("mod2");
	int r;

	r = 2 * mod1(x, y);
	return r;
}

int mod1(int x, int y)
{
	Test a("mod1");
	if(y==0)
	{
		throw "0���� ���� �� �����ϴ�.";
	}
	return x/y;
}