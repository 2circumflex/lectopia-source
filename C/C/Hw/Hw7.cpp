/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ASCII code�� �Է¹޾� ASCII code�� �ش��ϴ� ���ڸ� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int as;

	printf("(�Է�����)\n");
	printf("ASCII code���� �Է��Ͻÿ� : ");
	scanf("%d", &as);

	printf("(��°��)\n");
	printf("%d�� '%c'�� ASCII code �Դϴ�.\n", as, as);	

	return 0;
}