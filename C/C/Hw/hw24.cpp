/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �ﰢ ���ĺ� ����ϱ� */
#include <stdio.h>

int main()
{
	int i, j;
	char ch = 'F';

	for(i=1; i<=6; i++)
	{
		for(j=0; j<i; j++)
		{
			printf("%c", ch-j);
		}
		printf("\n");
	}
	

	return 0;
}