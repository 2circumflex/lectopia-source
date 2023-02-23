#include <stdio.h>
#pragma warning(disable:4996)
void input(int (*)[4], int);
void output(int (*)[4], int);
int main() 
{
	int num[3][4], row;
	row = sizeof(num) / sizeof(num[0]);

	input(num, row);
	output(num, row);
	
	return 0;
}

void input(int (*num)[4], int row)
{
	int i, j;

	for(i=0; i<row; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("num[%d][%d] = ", i, j);
			scanf("%d", &num[i][j]);
		}
	}
	printf("���� %d���� ���� ��� �Է� �޽��ϴ�.\n\n", row*4);
}

void output(int (*num)[4], int row)
{
	int r_sum=0, c_sum=0, i, j;

	for(i=0; i<row; i++)
	{
		printf("%5d�� :", i);
		for(j=0; j<4; j++)
		{
			printf("%5d", num[i][j]);
			r_sum += num[i][j];
		}
		printf("%8d���� �� : %d\n", i, r_sum);
		r_sum = 0;
	}
	printf("���� �� :");
	
	for(i=0; i<4; i++)
	{
		for(j=0; j<row; j++)
		{
			c_sum += num[j][i];			
		}
		printf("%5d", c_sum);
		c_sum=0;
	}
	printf("\n");
}