/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������ ����ϱ�(3��for��) */
#include <stdio.h>

int main()
{
	int i, j, k;
	
	for(i=1; i<=5; i+=4)
	{
		for(j=1; j<=9; j++)
		{
			for(k=i+1; k<=i+4; k++)
			{
				printf("%d*%d=%2d\t\t", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}	

	return 0;
}