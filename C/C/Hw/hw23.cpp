/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ��Ī�Ǵº���� */
#include <stdio.h>

int main()
{
	int i, j;
	for(i=1; i<=6; i++)
	{
		for(j=1; j<=i; j++)
		{
			printf("*");
		}
		for(j=15; j>=i*2; j--)
		{
			printf(" ");
		}
		for(j=1; j<=i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}