/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������ ����ī �̿��, �Ž����� ��� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int km, tot, money, change;
	
	while(1)
	{
		printf("����ī�� ����� �Ÿ��� KM ������ �Է��ϼ��� : ");
		scanf("%d", &km);
				
		tot = km * 500 + (int)((km * 500) * 0.1);
		printf("�� �̿�� : %d��\n", tot);
		printf("�̿�� ������ ���� ������ �ݾ��� �������� �Է��ϼ��� : ");
		scanf("%d", &money);
		change = money - tot;
		printf("�Ž����� : %d��\n\n", change);
	}

	return 0;
}