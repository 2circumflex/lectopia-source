/* ��¥ : 2012�� 2�� 7��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �������� �Է¹޾� �� ���� ��ŭ ��(*)�� ����ϵ� ���ٿ� 5���� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

void output(int);
int input();
int main()
{
	int su;
	while(1)
	{
		su = input();
		output(su);
	}


	return 0;
}

int input()
{
	int num;
	
	printf("# �������� �Է��ϼ��� : ");
	scanf("%d", &num);

	return num;
}

void output(int num)
{
	int fstar = num/5;
	int nstar = num%5;
	while(fstar > 0)
	{
		printf("*****\n");
		fstar--;
	}
	while(nstar > 0)
	{
		printf("*");
		nstar--;
	}
	printf("\n");

	return;
}