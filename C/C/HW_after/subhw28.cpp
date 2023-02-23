#include <stdio.h>
#pragma warning(disable:4996)

int main() 
{	
	int ary[10], col, su, i, hsu, jsu;
	col = sizeof(ary) / sizeof(ary[0]);

	hsu = 0;
	jsu = 0;
	col--;
	for(i=0; i<=col; i++)
	{
		printf("정수입력(%d) : ", i+1);
		scanf("%d", &su);

		if(su%2==0)
		{
			ary[col-jsu++] = su;
		}
		else
		{
			ary[hsu++] = su;
		}
	}
	printf("\n");

	for(i=0; i<=col; i++)
	{
		printf("%4d", ary[i]);
	}

	printf("\n");

	
	
	return 0;
}