/* ��¥ : 2012�� 2�� 7��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �������� �Է¹޾� 1���� �Է��� ���ڱ����� ������ ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int input();
void output(int);
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
	int s;
	printf("# �������� �Է��Ͻÿ� : ");
	scanf("%d", &s);

	return s;
}

void output(int num)
{
	int i=1, tot=0;

	while(i<=num)
	{
		tot += i;
		i++;
	}

	printf("1���� %d������ ���� %d�Դϴ�.\n\n", num, tot);

	return;
}


