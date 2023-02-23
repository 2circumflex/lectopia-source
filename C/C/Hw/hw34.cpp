/* 날짜 : 2012년 2월 15일   
   작성자 : 이로운   
   프로그램의 기능 : 3행 4열짜리 2차원 int 배열의 열의 합을 구하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
void input(int (*)[4], int);
void output(int (*)[4]);
int main() 
{
	int num[3][4];
	int row;
	row = sizeof(num) / sizeof(num[0]);	

	input(num, row);
	printf("\n");
	output(num);
	
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
}

void output(int (*num)[4])
{
	int i, j, r_sum=0, c_sum=0;

	for(i=0; i<3; i++)
	{
		r_sum = 0;
		printf("    %d행 : ",i);
		for(j=0; j<4; j++)
		{
			printf("%2d  ", num[i][j]);
			r_sum += num[i][j];
		}
		printf("   %d행의 합 : %d\n", i, r_sum);
	}

	printf(" 열의합 : ");
	for(i=0; i<4; i++)
	{
		c_sum = 0;
		for(j=0; j<3; j++)
		{
			c_sum += num[j][i];
		}
		printf("%2d  ", c_sum);
	}
	printf("\n\n");

	return;
}