/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �Է� ���� ������ 2���� ���� ������ ���� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int su;

	printf("(�Է�����)\n");
	printf("�� ���� ������ �Է��Ͻÿ� : ");
	scanf("%d", &su);

	printf("(��°��)\n");
	printf("%d�� 2��� => %d\n", su, su*2);
	printf("%d�� ����  => %d\n", su, su*su);

	return 0;
}