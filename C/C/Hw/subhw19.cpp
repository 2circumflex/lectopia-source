/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : Ű����κ��� ����� �Է� �ް� �׶����� �Էµ� ������ ���� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)
int input(int);
void output(int);
int main()
{
	int i, su, sum = 0;

	for(i=1; i<=5; i++)
	{
		su = input(i);

		if(su > 0)
		{
			sum += su;			
		}
		else
		{
			i--;
		}
	}
	output(sum);

	return 0;
}

int input(int i)
{
	int su;

	printf("0���� ū���� �Է��Ͻÿ�(%d��°) : ", i);
	scanf("%d", &su);
	
	return su;
}

void output(int sum)
{
	printf("�Էµ� ���� �� �� : %d\n", sum);
	return;
}