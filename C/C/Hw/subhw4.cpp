/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ȭ���µ��� �Է� �ް� ���� �µ��� ����Ͽ� ����ϱ�, �����µ��� �Ҽ��� ���� ù°�ڸ����� ��� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	double hwac, subc;

	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf("%lf", &hwac);

	subc = 5.0 / 9.0 * (hwac - 32.0);

	printf("���� �µ��� %.1lf �� �Դϴ�.\n", subc);

	return 0;
}