#include <stdio.h>
#pragma warning (disable:4996)
int main() 
{
	int i,j;

	for(i=1; i<=9; i++)
	{
		for(j=2; j<=5; j++)
		{
			printf("%d*%d=%2d\t\t", j, i, j*i);
		}
		printf("\n");
	}

	printf("\n");

	for(i=1; i<=9; i++)
	{
		for(j=6; j<=9; j++)
		{
			printf("%d*%d=%2d\t\t", j, i, j*i);
		}
		printf("\n");
	}

	return 0;
}