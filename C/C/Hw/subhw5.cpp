/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : cm������ �Է� �޾� M������ cm ������ ȯ���Ͽ� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int cm;

	printf("cm������ �Է��ϼ��� : ");
	scanf("%d", &cm);
	
	printf("%dcm => %dM %dcm\n", cm, cm/1000, cm%1000);

	return 0;
}