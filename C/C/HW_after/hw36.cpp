#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
void input(char (*)[15], int);
void sort(char (*)[15], int);
void output(char (*)[15], int);
int main() 
{
	char str[5][15];	
	int row = sizeof(str) / sizeof(str[0]);	

	input(str, row);	
	sort(str, row);
	output(str, row);

	return 0;
}

void output(char (*s)[15], int row)
{
	int i;

	for(i=0; i<row; i++)
	{
		printf("str[%d] = %s  %c  %c\n", i, s[i], s[i][0], s[i][strlen(s[i])-1]);
	}
}

void sort(char (*s)[15], int row)
{
	int i, j, cnt=row-1;
	char tp[15];

	for(i=0; i<row-1; i++)
	{
		for(j=1; j<=cnt; j++)
		{			
			if(strcmp(s[i], s[i+j])>0)
			{
				strcpy(tp, s[i]);
				strcpy(s[i], s[i+j]);
				strcpy(s[i+j], tp);
			}
		}
		cnt--;
	}
}

void input(char (*s)[15], int row)
{
	int i;

	for(i=0; i<row; i++)
	{
		fflush(stdin);
		printf("# %d번 문자열을 입력하시오 : ", i+1);
		scanf("%s", s[i]);
	}
}

