#include <stdio.h>
int main() 
{
	int i,j,k;

	for(i=1; i<=6; i++)
	{
		for(j=0; j<i; j++)
		{
			printf("*");
		}
		for(k=12; k>=i*2; k-=2)
		{
			printf("  ");
		}
		for(j=0; j<i; j++)
		{
			printf("*");
		}
		printf("\n");
	}	

	return 0;
}