/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 회문(Palindrome) 검사하기 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable : 4996)
int check(char*, int);
int main()
{	
	char ary[20];
	int ox, stl;

	while(1)
	{
		printf("입력 하시오 : ");
		scanf("%s", ary);

		stl = strlen(ary);

		ox = check(ary, stl);

		if(ox == 1)
		{
			printf("회문입니다.\n\n");
		}
		else
		{
			printf("회문이 아닙니다.\n\n");
		}
	}
	
	return 0;
}

int check(char *ary, int stl)	//회문검사
{	
	int i;
	for(i=0; i<stl/2; i++)
	{
		if(tolower(ary[i]) != tolower(ary[stl-1-i]))
		{				
			return 0;
		}		
	}
	return 1;
}