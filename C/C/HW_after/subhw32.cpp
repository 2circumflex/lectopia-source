#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int ary[10], i;

	printf("10개의 정수 입력 : ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &ary[i]);
	}

	printf("홀수 : ");
	for(i=0; i<10; i++)
	{
		if(ary[i]%2==1)
		{
			printf("%d ", ary[i]);
		}		
	}
	
	printf("\n짝수 : ");
		
	for(i=0; i<10; i++)
	{
		if(ary[i]%2==0)
		{
			printf("%d ", ary[i]);
		}		
	}
	
	printf("\n");
	
	return 0;
}