/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : 1~100������ ���ڸ� ���, 3�� ����� *, 5�� ����� # 3�� 5�� ������� ������ڷ� ��� */
#include <stdio.h>

int main()
{
	int i, j, su=1;

	for(i=1; i<=10; i++)
	{
		for(j=1; j<=10; j++)
		{
			if(su%3 == 0 && su%5 == 0)
			{
				printf("%2d ", su);
			}
			else if(su%3 == 0)
			{
				printf(" * ");
			}
			else if(su%5 == 0)
			{
				printf(" # ");
			}
			else
			{
				printf("%2d ", su);
			}
			su++;
		}
		printf("\n");
	}

	return 0;
}
