/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �� 10���� ������ �Է¹޾� Ȧ���� ¦���� �������� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int ary[10], i;
	
	while(1)
	{
		printf("# 10���� ���� �Է� : ");
		for(i=0; i<10; i++)
		{
			scanf("%d", &ary[i]);
		}

		printf("* Ȧ�� : ");
		for(i=0; i<10; i++)
		{
			if(ary[i]%2 !=0)
			{
				printf("%d ", ary[i]);
			}
		}
		printf("\n");

		printf("* ¦�� : ");
		for(i=0; i<10; i++)
		{
			if(ary[i]%2 ==0)
			{
				printf("%d ", ary[i]);
			}
		}
		printf("\n\n");
	}

	return 0;
}