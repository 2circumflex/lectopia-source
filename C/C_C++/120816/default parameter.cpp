#include <iostream>
using namespace std;
void char_prn(char ch='#', int cnt=5);
//void char_prn(char='#', int=5);	//���𿡼��Ű����� �̸��� ��������
int main()
{
	char_prn();
	char_prn('@');
	char_prn('@', 10);

	//char_prn( ,7);
	char_prn(65);
	return 0;
}

void char_prn(char ch, int cnt)
{
	int i;
	for(i=0; i<cnt; i++)
	{
		cout<<ch;
	}
	cout<<endl;
}