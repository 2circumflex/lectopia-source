/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �̸��� �������� �Է� �޾� �پ��� ���·� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char ename[20];
	
	printf("�̸��� �Է��Ͻÿ� : ");
	scanf("%s", ename);

	printf("\"%s\"\n", ename);
	printf("\"%20s\"\n", ename);
	printf("\"%-20s\"\n", ename);

	return 0;
}