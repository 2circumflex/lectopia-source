#include <stdio.h>
#pragma warning (disable:4996)

void input(char *, int *,  int *);
void char_printf(char, int, int);
int main() 
{
	char ch;
	int su, li;

	while(1)
	{
		input(&ch, &su, &li);
		char_printf(ch, su, li);		
	}
	

	return 0;
}

void input(char *ch, int * su, int *li)
{
	fflush(stdin);
	printf("* ����� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%c", ch);
	printf("* ���ٿ� �ݺ��� ȸ���� �Է��Ͻÿ� : ");
	scanf("%d", su);
	printf("* �ݺ������ ���μ��� �Է��Ͻÿ� : ");
	scanf("%d", li);
	printf("\n");
}

void char_printf(char ch, int su, int li)
{
	int i,j;

	for(i=0; i<li; i++)
	{
		for(j=0; j<su; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	printf("\n");
}