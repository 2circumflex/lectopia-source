#include <stdio.h>
#pragma warning (disable:4996)

int main() 
{
	int eng=0, su=0, ste=0, etc=0;
	char ch;

	printf("�ƹ��ų� �Է� : ");

	while((ch=getchar())!=EOF)
	{
		
		if((ch >= 'A' && ch<= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			eng++;
		}
		else if(ch >= '0' && ch <= '9')
		{
			su++;
		}
		else if(ch == ' ' || ch == '\t' || ch == '\n')
		{
			ste++;
		}
		else
		{
			etc++;
		}
	}

	printf("* �����ڴ�ҹ��� : %d ��\n", eng);
	printf("* ���ڹ��� : %d ��\n", su);
	printf("* ���鹮��(space,tab,enter) : %d ��\n", ste);
	printf("* �׿� ��Ÿ���� : %d ��\n", etc);

	return 0;
}

