/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���ڿ��ȿ� �����ϴ� ���ڵ��� ������ ����ϱ� */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)
int main()
{	
	char str[20];
	int len, i, sum=0;

	while(1)
	{
		sum = 0;
		printf("�Է��Ͻÿ� : ");
		scanf("%s", str);

		len = strlen(str);

		for(i=0; i<len; i++)
		{
			if((str[i]-'0') >=0 && (str[i] - '0') <=9)
			{
				printf("%c+", str[i]);
				sum += str[i] - '0';
			}
		}
		printf("\b=%d\n\n", sum);
	}

	return 0;
}