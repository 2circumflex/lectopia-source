#include <iostream>
using namespace std;
void sub(int *p, char &pp);
int main()
{
	int a  = 10;
	char ch = '#';
	sub(&a, ch);
	cout<<a<<' '<<ch<<endl;
}

void sub(int *p, char &pp)
{
	*p = 20;
	pp = 'a';
}