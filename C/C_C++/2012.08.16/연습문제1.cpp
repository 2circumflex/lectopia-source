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

	cout<<"두 실수 입력 : ";
	cin>>a>>b;
	d_res = max(a, b);
	cout<<"큰 값 : "<<d_res<<endl;

	cout<<"두 문자열 입력 : ";
	cin>>str1>>str2;
	str_res = max(str1, str2);
	cout<<"긴 문자열 : "<<str_res<<endl;

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