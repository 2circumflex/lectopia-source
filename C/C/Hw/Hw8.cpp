/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �� ���� �Է� �޾� �� ���� �ֿ� ������ ��ȯ�ϴ� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int day;

	printf("*������ �Է��Ͻÿ� : ");
	scanf("%d", &day);

	printf("%d���� %d�� %d�� �Դϴ�\n", day, day/7, day%7);	

	return 0;
}