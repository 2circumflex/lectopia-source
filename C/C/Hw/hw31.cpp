/* 날짜 : 2012년 2월 15일   
   작성자 : 이로운   
   프로그램의 기능 : 문자검색 프로그램 */
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
			printf("종료합니다\n");
			break;
		}

		while(1)
		{
			r_r = strcheck(str, ch, size);

			if(r_r!=-1)
			{
				printf("\"%s\" 문자열 안에 '%c' 문자는 %d번째 문자입니다.\n\n", str, ch, r_r);
			}
			else
			{
				printf("\"%s\" 문자열 안에 '%c' 문자는 존재하지 않습니다.\n\n", str, ch);
			}
			break;
		}
	}
			
	return 0;
}

int str_input(char *str, char *ch) //문자입력
{
	char end[4] = "end";	
	int s_r;

	printf("# 문자열을 입력하시오(종료:end입력) : ");
	scanf("%s", str);

	s_r = strcmp(end, str);

	if(s_r == 0)
	{
		return 0;
	}

	fflush(stdin);
	
	printf("# 문자를 입력하시오 : ");
	scanf("%c", ch);
	
	return 1;
}

int strcheck(char *str, char ch, int size) //문자체크
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