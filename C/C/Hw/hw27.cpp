/* ��¥ : 2012�� 2�� 13��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���������� ī��Ʈ ���α׷� */
#include <stdio.h> 
#pragma warning (disable : 4996)
void output(int, int, int, int);
int main(void) 
{ 
	char ch;
	int eng=0, su=0, ste=0, etc=0;

	printf("�ƹ��ų� �Է��Ͻÿ�(�����ctrl+z) : ");

	while((ch=getchar()) != EOF)
	{		
		if(ch == '\n')
		{
			ste++;
			output(eng, su, ste, etc);
			eng=0, su=0, ste=0, etc=0;
			printf("�ƹ��ų� �Է��Ͻÿ�(�����ctrl+z) : ");
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			eng++;
		}
		else if(ch >= 'a' && ch <= 'z')
		{
			eng++;
		}
		else if(ch >= '0' && ch <= '9')
		{
			su++;
		}
		else if(ch == ' ' || ch == '\t')
		{
			ste++;
		}
		else
		{
			etc++;
		}		
	}	

	return 0; 
}

void output(int a, int b, int c, int d)
{
	printf("* �����ڴ�ҹ��� : %2d ��\n", a);
	printf("* ���ڹ��� : %2d ��\n", b);
	printf("* ���鹮��(space, tab, enter) : %2d ��\n", c);
	printf("* �׿� ��Ÿ���� : %2d ��\n\n", d);
	return;
}
