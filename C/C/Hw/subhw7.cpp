/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ����ö��� ����ϴ� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int su, pay, cho;
	
	while(1)
	{
		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", &su);

		if(su!=0 && su<=5)
		{
			printf("��� : 600��\n\n");
		}
		else if(su<=10)
		{
			printf("��� : 800��\n\n");
		}
		else if(su>10)
		{
			cho = su - 10;
			
			if(cho%2 !=0)
			{
				pay = 800 + (cho/2) * 100 + 100;
			}
			else
			{
				pay = 800 + (cho/2) * 100;
			}
			printf("��� : %d��\n\n", pay);
		}
	}

	return 0;
}