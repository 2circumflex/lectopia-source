/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : Family ���α׷� - �ѹ��ڸ� �Է¹޾� f,F�̸� Father m,M�̸� Mother b,B�̸� Brother s,S�̸� Sister ��� �׿� ������ ���� Input Error ��� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char family;

	while(1)
	{
		printf("���� �Ѱ��� �Է��Ͻÿ� : ");
		scanf("%c", &family);

		if(family == 'f' || family == 'F')
		{
			printf("Father\n\n");
		}
		else if(family == 'm' || family == 'M')
		{
			printf("Mother\n\n");
		}
		else if(family == 'b' || family == 'B')
		{
			printf("Brother\n\n");
		}
		else if(family == 's' || family == 'S')
		{
			printf("Sister\n\n");
		}
		else
		{
			printf("Input Error!!!\n\n");
		}

		fflush(stdin);
	}

	return 0;
}