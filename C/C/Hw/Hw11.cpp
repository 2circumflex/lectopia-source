/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���ڿ��� �Է� �޾� ���ڿ��� �ݸ�����ϱ�, ��½� ���ȣ�� ��� ����ϵ� ����¥�� ���ڿ� �ڿ��� ������ȣ */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main()
{
	char mj[20];

	printf("* ���ڸ� �Է��Ͻÿ� : ");
	scanf("%s", mj);

	 printf("[%*.*s. . .]\n", strlen(mj), strlen(mj)/2, mj);

	return 0;
}