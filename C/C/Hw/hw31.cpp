/* ��¥ : 2012�� 2�� 15��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���ڰ˻� ���α׷� */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)
int str_input(char *, char *);
int strcheck(char *, char, int);
int main() 
{
	char str[20];
	char ch;
	int size, r_r, s_r;
	size = sizeof(str)/sizeof(str[0]);

	while(1)
	{
		s_r = str_input(str, &ch);
		if(s_r == 0)
		{
			printf("�����մϴ�\n");
			break;
		}

		while(1)
		{
			r_r = strcheck(str, ch, size);

			if(r_r!=-1)
			{
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� %d��° �����Դϴ�.\n\n", str, ch, r_r);
			}
			else
			{
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� �������� �ʽ��ϴ�.\n\n", str, ch);
			}
			break;
		}
	}
			
	return 0;
}

int str_input(char *str, char *ch) //�����Է�
{
	char end[4] = "end";	
	int s_r;

	printf("# ���ڿ��� �Է��Ͻÿ�(����:end�Է�) : ");
	scanf("%s", str);

	s_r = strcmp(end, str);

	if(s_r == 0)
	{
		return 0;
	}

	fflush(stdin);
	
	printf("# ���ڸ� �Է��Ͻÿ� : ");
	scanf("%c", ch);
	
	return 1;
}

int strcheck(char *str, char ch, int size) //����üũ
{
	int i, r_r = -1;
	for(i=0; i<size; i++)
	{
		if(ch == str[i])
		{
			r_r = i+1;
			return r_r;
		}		
	}
	return r_r;
}