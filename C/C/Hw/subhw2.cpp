/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� ��뷮�� kw������ �Է��ϸ� ��� ����� ��� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int sayong;
	double yogm;

	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf("%d", &sayong);

	yogm = 660 + 88.5 * (double)sayong;
	yogm = yogm + yogm * 0.09;
	
	printf("���� ������� %lf �� �Դϴ�.\n", yogm);

	return 0;
}