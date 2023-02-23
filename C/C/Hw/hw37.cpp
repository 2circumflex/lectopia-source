/* 날짜 : 2012년 2월 16일   
   작성자 : 이로운   
   프로그램의 기능 : 3차원 배열 출력하기 */
#include <stdio.h>
void output(int (*)[3][4]);
int main() 
{
	int ary[3][3][4];
	int i,j,k;

	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<4; k++)
			{
				ary[i][j][k] = j+k+1;

				if(i==1)  { ary[i][j][k] +=3; }						
			}			
		}
	}

	for(j=0; j<3; j++)
	{
		for(k=0; k<4; k++)
		{
			ary[2][j][k] = ary[0][j][k] + ary[1][j][k];
		}
	}

	output(ary);

	return 0;
}

void output(int (*ary)[3][4])
{
	int i,j,k;

	for(i=0; i<3; i++)
	{
		printf("[%d면]\n", i);
		for(j=0; j<3; j++)
		{
			printf(" %d행\t", j);
			for(k=0; k<4; k++)
			{
				printf("%-4d", ary[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	return;
}