/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ����, ����, ���� �� ������ ������ �Է¹޾� ������ ����� ���� ���, �Է� ������ ��� ������, ����� �Ǽ����� ���ü� �ֵ��� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int his, mun, ye;
	int hap;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &his, &mun, &ye);

	hap = his + mun + ye;

	printf("������ %d�̰� ����� %lf �Դϴ�.\n", hap, (double)hap/3.0);

	return 0;
}