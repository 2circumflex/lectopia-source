/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �⵵�� �Է¹޾� ���, ���� ���ϴ� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int year;

	while(1)
	{
		printf("�⵵�� �Է��Ͻÿ� : ");
		scanf("%d", &year);


		if (year%4 != 0)
		{
			printf("%d���� ���(Common year)�Դϴ�.\n\n", year);
		}
		else if (year%100 != 0)
		{
			printf("%d���� ����(Leap year)�Դϴ�.\n\n", year);
		}
		else if (year%400 != 0)
		{
			printf("%d���� ���(Common year)�Դϴ�.\n\n", year);
		}
		else
		{
			printf("%d���� ����(Leap year)�Դϴ�.\n\n", year);
		}
	}

	return 0;
}