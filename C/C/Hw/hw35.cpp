/* ��¥ : 2012�� 2�� 15��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �밢���� �ձ��ϱ� */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� ��
int random(int);
void output(int (*)[5]);
#pragma warning (disable : 4996)
int main() 
{
	int num[5][5];

	srand( time (0) );

	output(num);
	
	return 0;
}

int random(int n) // �����߻��Լ�
{ 
	int res; 
	res = (rand() % n)+1; // 0���� n-1������ ���� ���� �߻� 
	return res; 
}

void output(int (*num)[5])	// ����Լ�
{
	int i, j, res, sum1=0, sum2=0, sum3=0;

	for(i=0; i<5; i++)
	{
		printf("%d�� �� : ", i);
		for(j=0; j<5; j++)
		{
			res = random(20);
			num[i][j] = res;
			printf("%2d  ", num[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0; i<5; i++)	// sum1 ����
	{
		for(j=i; j<=i; j++)
		{
			sum1 += num[i][j];
		}
	}

	for(i=0; i<4; i++)	// sum2 ����
	{
		for(j=i+1; j<5; j++)
		{
			sum2 += num[i][j];
		}
	}

	for(i=1; i<5; i++)	// sum3 ����
	{
		for(j=0; j<i; j++)
		{
			sum3 += num[i][j];
		}
	}	

	printf("sum1 = %d\n", sum1);
	printf("sum2 = %d\n", sum2);
	printf("sum3 = %d\n", sum3);
	
	return;
}