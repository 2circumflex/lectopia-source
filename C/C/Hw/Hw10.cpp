/* ��¥ : 2012�� 2�� 3��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� �̸��� �Է� �޾� �Էµ� �̸��� ����ϰ� ���� ���ο� ���� �̸��� ���� ���� ���� ���� �̸����ڸ��� ���߾� ����Ͻÿ� */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main()
{
	char sung[20], name[20];

	printf("#���� �Է��Ͻÿ� : ");
	scanf("%s", sung);
	printf("#�̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);

	printf("%s %s\n", sung, name);
	printf("%*d %*d\n", strlen(sung), strlen(sung), strlen(name), strlen(name));	

	return 0;
}