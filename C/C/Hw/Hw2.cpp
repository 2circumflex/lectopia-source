/* ��¥ : 2012�� 2�� 1��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : 54321�ʸ� ��, ��, �� ������ ȯ���Ͽ� ����ϱ�	*/
#include <stdio.h>
int main()
{
	int second = 54321;	// 54321��
	int hour, min, sec;	// �ð�, ��, �ʴ��� ȯ���Ͽ� ����� ����

	hour = second / 360;
	second = second - 360 * hour;
	
	min = second / 60;
	sec = second - 60 * min;

	printf("54321�ʴ� %d�ð� %d�� %d�� �Դϴ�.\n", hour, min, sec);	//���

	return 0;
}