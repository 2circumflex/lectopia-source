#include <iostream>
using namespace std;
void square(short);
void square(float);

int main()
{
	char ch='A';
	short sh=10;
	float ft=3.4f;
	double db=3.4;

	square(ch);
	square(sh);
	square(ft);
	square(db);

	return 0;
}

void square(short a)
{
	cout<<"int 형으로 호출 : "<<a*a<<endl;
}

void square(float a)
{
	cout <<"double 형으로 호출 : "<<a*a<<endl;
}