/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �� ������ �Է� �޾� ��, ��, ��, ���� ���� ����ϴ� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int a, b;

	printf("(�Է�����)\n");
	printf("�ΰ��� ������ �Է��Ͻÿ� : ");
	scanf("%d %d", &a, &b);

	printf("(��°��)\n");
	printf("%d+%d = %d\n", a, b, a+b);
	printf("%d-%d = %d\n", a, b, a-b);
	printf("%d*%d = %d\n", a, b, a*b);
	printf("%d/%d = %.2lf\n", a, b, (double)a/(double)b);	

	return 0;
}