#include <iostream>
using namespace std;
int my_strlen(char *sp, char ch=0);

int main()
{
	char str[100];
	char ch;
	int cnt;

	cout<<"���ڿ� �Է� : ";
	cin.getline(str, sizeof(str));
	cnt = my_strlen(str);
	cout<<"���ڿ��� ���� : "<<cnt<<endl;

	cout<<"���� �Է� : ";
	ch = cin.get();
	cnt = my_strlen(str, ch);
	cout<<ch<<"���������� ���� : "<<cnt<<endl;
	
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