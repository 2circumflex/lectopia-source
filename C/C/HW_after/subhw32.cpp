#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int ary[10], i;

	printf("10���� ���� �Է� : ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &ary[i]);
	}

	printf("Ȧ�� : ");
	for(i=0; i<10; i++)
	{
		if(ary[i]%2==1)
		{
			printf("%d ", ary[i]);
		}		
	}
	
	printf("\n¦�� : ");
		
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