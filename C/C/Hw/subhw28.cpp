/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���̰� 10�� ���� �迭�� �����ϰ� �� 10���� ������ �Է¹ް� Ȧ���̸� �迭�� �տ������� ¦���̸� �迭�� �ڿ������� ä�������� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int ary[10], tmp[10], i, jsu=0, hsu=0;

	while(1)
	{
		jsu=0;
		hsu=0;
		printf("���� 10�� �Է� : ");
	
		for(i=0; i<10; i++)	//�Է¹ޱ�
		{
			scanf("%d", &tmp[i]);		
		}

		for(i=0; i<10; i++)	//�Է¹��� �� Ȧ���� �պ��� ¦���� �ں��� ����
		{
			if((tmp[i] % 2) == 0)
			{
				ary[9-jsu] = tmp[i];
				jsu++;
			
			}
			else
			{
				ary[0+hsu] = tmp[i];
				hsu++;			
			}
		}
		
		printf("[ ");
		for(i=0; i<10; i++)	//����ϱ�
		{
			printf("%d ", ary[i]);
		}
		printf("]\n\n");
	}


	return 0;
}