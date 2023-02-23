#include <iostream>
using namespace std;
int my_strlen(char *sp, char ch=0);

int main()
{
	char str[100];
	char ch;
	int cnt;

	cout<<"문자열 입력 : ";
	cin.getline(str, sizeof(str));
	cnt = my_strlen(str);
	cout<<"문자열의 길이 : "<<cnt<<endl;

	cout<<"문자 입력 : ";
	ch = cin.get();
	cnt = my_strlen(str, ch);
	cout<<ch<<"이전까지의 길이 : "<<cnt<<endl;
	
	return 0;
}

int my_strlen(char *sp, char ch)
{
	int i=0;

	if(ch != 0)
	{
		while(sp[i] != ch)
		{
			i++;
		}
		return i;
	}

	return strlen(sp);
}