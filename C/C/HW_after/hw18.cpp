/* ��¥ : 2012�� 7�� 12��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : 10������ �Է� �޾� 2������ ����ϴ� ���α׷� */
#include <stdio.h>
#pragma warning (disable:4996)

int input(short *);
void output(short);
int main()
{
	short jsu;
	int re;
	while(1)
	{
		re = input(&jsu);

		if(re == -1)
		{
			break;
		}
		else if(re == 0)
		{
			printf("�߸��Է�����\n\n");
		}
		else if(re == 1)
		{
			output(jsu);
		}
	}

	return 0;
}

int input(short *su)
{
	int ch;
	printf("* 10���� ������ �Է��Ͻÿ� : ");
	ch = scanf("%hd", su);
	fflush(stdin);

	return ch;
}

void output(short su)
{
	int i;
	unsigned short a;
	printf("\n%hd(10) = ", su);
	
	for(i=15; i>=0; i--)
	{
		a = su & (0x0001<< i);
		printf("%hu", a>>i);
	}
	printf("(2)\n\n");
}