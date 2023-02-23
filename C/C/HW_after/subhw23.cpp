#include <stdio.h>
int main() 
{ 
	int i, j;

	for(i=0; i<10; i++)
	{
		for(j=i; j<100; j+=10)
		{
			printf("%2d  ", j);
		}
		printf("\n");
	}

	return 0;
} 