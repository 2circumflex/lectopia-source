/* ��¥ : 2012�� 2�� 9��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : 10������ �Է� �޾� 2������ ����ϴ� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)
int input(short *);
void output(short);
int main()
{
	int res;
	short su;

	while(1)
	{
		res = input(&su);

		if(res == -1)
		{
			break;
		}
		else
		{
			output(su);
		}
	}

	return 0;
}

void output(short num)
{
	int i=0;
	short res;
	unsigned short sh = 0x8000;
	printf("\n%hd(10) = ", num);
	
	while(i<16)
	{
		res = num & sh;
		sh = sh>>1;

		if(res == 0)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
		i++;
	}
	printf("(2)\n\n");
	
	return;
}

int input(short *su)
{
	int res;

	printf("* 10���� ������ �Է��Ͻÿ� : ");	
	fflush(stdin);
	res = scanf("%hd", su);

	while(res == 0)
	{
		printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
		fflush(stdin);
		res = scanf("%hd", su);

		if(res == -1)
		{
			break;
		}
	}

	return  res;
}