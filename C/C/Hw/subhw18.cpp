/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : Ű����κ��� ����� �Է� �ް� �׶����� �Էµ� ������ ���� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)
int input();
void output(int);
int main()
{
	int num, sum=0;

	while(1)
	{
		num = input();

		if(num < 0)	{ break;}
		
		sum += num;

		output(sum);
	}	

	return 0;
}

int input()
{
	int su;
	printf("����� �Է��ϼ��� : ");
	scanf("%d", &su);

	return su;
}

void output(int n)
{
	printf("���ݱ��� �Էµ� ���� �� : %d\n", n);

	return;
}