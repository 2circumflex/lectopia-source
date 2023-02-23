#include <stdio.h>
int main() 
{
	int ary[3][3][4], i, j, k, su=0;

	for(i=0; i<2; i++)
	{
		printf("(%d면)\n", i);
		for(j=0; j<3; j++)
		{			
			su++;
			for(k=0; k<4; k++)
			{
				ary[i][j][k] = su + k;
				printf("%4d", ary[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("(2면의 저장 값)\n");
	for(i=0; i<3; i++)
	{		
		for(j=0; j<4; j++)
		{
			ary[2][i][j] = ary[0][i][j] + ary[1][i][j];
			printf("%4d", ary[2][i][j]);
		}
		printf("\n");
	}

	return 0;
}