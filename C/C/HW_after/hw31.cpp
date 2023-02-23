#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int strcheck(char *, char);
int input(char *, char *);
int main() 
{
	char str[20];
	char ch;
	int num;

	while(1)
	{		
		num = input(str, &ch);
		if(num==0)	break;
		num = strcheck(str, ch);

		printf("\"%s\" 문자열 안에 '%c' 문자는 ", str, ch);
		if(num == -1)
		{
			printf("존재하지 않습니다.\n\n");
		}
		else
		{
			printf("%d번째 문자입니다.\n\n", num+1);
		}
	}
	
	return 0;
}

int input(char *s, char *ch)
{
	fflush(stdin);
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", s);
	if(strcmp(s, "end") == 0)	return	0;
	printf("# 문자를 입력하시오 : ");
	scanf(" %c", ch);
	printf("\n");
	return 1;
}

int strcheck(char *s, char ch)
{
	int i=0;

	while(s[i] != '\0')
	{
		if(s[i] == ch)	return i;
		i++;
	}

	return -1;
}

