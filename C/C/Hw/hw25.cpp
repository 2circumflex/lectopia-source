/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������ ����ϱ� */
#include <stdio.h>

int main()
{
	int i, j;
	
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