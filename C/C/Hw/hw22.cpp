/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���ڹݺ� ��� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)
void char_print(char, int, int);
void input(char *, int*, int*);
int main()
{
	char ch;
	int su, line;
	
	input(&ch, &su, &line);

	char_print(ch, su, line);

	return 0;
}

void input(char * ch, int *su, int *line)
{	
	printf("* ����� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%c", ch);
	printf("* ���ٿ� �ݺ��� ȸ���� �Է��Ͻÿ� : ");
	scanf("%d", su);
	printf("* �ݺ������ ���μ��� �Է��Ͻÿ� : ");
	scanf("%d", line);
	printf("\n");
	return;
}

void char_print(char ch, int su, int line)
{
	int i,j;
	
	for(i=0; i<line; i++)
	{
		for(j=0; j<su; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}

	return;
}


