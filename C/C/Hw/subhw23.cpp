/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : 0���� 99������ ������ ���ٿ� 10���� �������� ����ϱ� */
#include <stdio.h>
int main()
{	
	int i, j;

	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			printf("  %2d", i+j*10);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}