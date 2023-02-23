#include <stdio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� ��
int random(int);
void input(int (*)[5], int);
void output(int (*)[5], int);
int main() 
{
	int num[5][5], row;
	row = sizeof(num) / sizeof(num[0]);
	srand( time (0) );

	input(num, row);
	output(num, row);

	return 0;
}

void output(int (*num)[5], int row)
{
	int i, j, sum1=0, sum2=0, sum3=0;
	
	for(i=0; i<row; i++)
	{
		printf("%d�� �� :", i);
		for(j=0; j<5; j++)
		{
			printf("%4d", num[i][j]);

			if(i==j)		sum1 += num[i][j];
			else if(i<j)	sum2 += num[i][j];
			else if(i>j)	sum3 += num[i][j];
		}
		printf("\n");	
	}
	printf("\n");
	printf("sum1 = %d\n", sum1);
	printf("sum2 = %d\n", sum2);
	printf("sum3 = %d\n", sum3);
}

void input(int (*num)[5], int row)
{
	int i, j;

	for(i=0; i<row; i++)
	{
		for(j=0; j<5; j++)
		{
			num[i][j] = random(20) + 1;			
		}
	}
}

int random(int n) 
{ 
	int res; 
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res; 
} 