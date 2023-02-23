#include <iostream>
#include <string.h>
using namespace std;

struct Profile{
	char *np;
	int age;
};

void ProfileCopy(Profile &a, Profile &b);

int main()
{
	Profile *hong, *sin;
	int len;

	len = strlen("ȫ�浿");
	hong = new Profile;
	hong->np = new char[len + 1];
	strcpy(hong->np, "ȫ�浿");
	hong->age = 20;

	len = strlen("�Ż��Ӵ�");
	sin = new Profile;
	sin->np = new char[len + 1];
	strcpy(sin->np, "�Ż��Ӵ�");
	sin->age = 30;


	cout << "hong => " << hong->np << " : " << hong->age << endl;
	cout << "sin => " << sin->np << " : " << sin->age << endl;

	ProfileCopy(*hong, *sin);

	cout << "hong => " << hong->np << " : " << hong->age << endl;
	cout << "sin => " << sin->np << " : " << sin->age << endl;

	return 0;
}

void ProfileCopy(Profile &a, Profile &b)
{
	int len;
	len = strlen(b.np);
	delete[] a.np;
	a.np = new char[len + 1];
	strcpy(a.np, b.np);
	a.age = b.age;
}