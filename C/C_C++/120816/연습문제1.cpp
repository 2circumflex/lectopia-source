#include <iostream>
#include <string.h>
using namespace std;
char * max(char *a, char *b);
double max(double a, double b);

int main()
{
	double a, b, d_res;
	char str1[100], str2[100];
	char *str_res;

	cout<<"�� �Ǽ� �Է� : ";
	cin>>a>>b;
	d_res = max(a, b);
	cout<<"ū �� : "<<d_res<<endl;

	cout<<"�� ���ڿ� �Է� : ";
	cin>>str1>>str2;
	str_res = max(str1, str2);
	cout<<"�� ���ڿ� : "<<str_res<<endl;

}

double max(double a, double b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

char * max(char *a, char *b)
{
	if(strlen(a)>=strlen(b))
	{
		return a;
	}
	else
	{
		return b;
	}
}