#include <stdio.h>
int main() 
{
	int i,j,k;

	for(i=2; i<7; i+=4)
	{
		for(j=1; j<=9; j++)
		{
			for(k=i; k<=i+3; k++)
			{
				printf("%d*%d=%2d\t\t", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}