/* ��¥ : 2012�� 2�� 16��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� ���ĺ�������� sort�� ���ڿ� ù ���ڿ� �� ���� ����ϱ� */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)
void input(char (*)[20]);
void sort(char (*)[20]);
void output(char (*)[20]);
int main() 
{
	char str[5][20];
	while(1)
	{		
		input(str);
		sort(str);
		output(str);
	}
			
	return 0;
}

void input(char (*str)[20])
{
	int i;
	
	for(i=0; i<5; i++)
	{
		fflush(stdin);
		printf("# %d�� ���ڿ��� �Է��Ͻÿ� : ", i+1);
		scanf("%s", str[i]);
	}
	printf("\n");
	
	return;
}

void sort(char (*str)[20])
{
	char tmp[20];
	int i, j, n;

	for(i=0; i<5; i++)
	{
		for(j=i+1; j<5; j++)
		{
			n = strcmp(str[i], str[j]);
			if(n>0)
			{
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
	return;
}

void output(char (*str)[20])
{
	int i, n;

	

	for(i=0; i<5; i++)
	{
		n = strlen(str[i]);
		printf("str[%d] = %s  %c  %c\n", i, str[i], str[i][0], str[i][n-1]);
	}
	printf("\n");

	return;
}



