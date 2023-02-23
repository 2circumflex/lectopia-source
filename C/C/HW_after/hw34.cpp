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
	printf("각방 %d개의 값을 모두 입력 받습니다.\n\n", row*4);
}

void output(int (*num)[4], int row)
{
	int r_sum=0, c_sum=0, i, j;

	for(i=0; i<row; i++)
	{
		printf("%5d행 :", i);
		for(j=0; j<4; j++)
		{
			printf("%5d", num[i][j]);
			r_sum += num[i][j];
		}
		printf("%8d행의 합 : %d\n", i, r_sum);
		r_sum = 0;
	}
	printf("열의 합 :");
	
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