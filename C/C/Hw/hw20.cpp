/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������ �Է¹޾� �� �������� 10��ŭ ū ������ ��� */
#include <stdio.h>
#pragma warning (disable : 4996)
int input();
void output(int);
int main()
{
	int su;
	su = input();
	output(su);

	return 0;
}

int input()
{
	int su;
	printf("* ������ �Է��Ͻÿ� : ");
	scanf("%d", &su);
	return su;
}

void output(int num)
{
	int i;
	for(i=num; i<=num+10; i++)
	{
		printf("[%d] ", i);
	}
	printf("\n");

	return;
}