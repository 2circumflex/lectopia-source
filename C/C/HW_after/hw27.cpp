#include <stdio.h>
#pragma warning (disable:4996)

int main() 
{
	int eng=0, su=0, ste=0, etc=0;
	char ch;

	printf("아무거나 입력 : ");

	while((ch=getchar())!=EOF)
	{
		
		if((ch >= 'A' && ch<= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			eng++;
		}
		else if(ch >= '0' && ch <= '9')
		{
			su++;
		}
		else if(ch == ' ' || ch == '\t' || ch == '\n')
		{
			ste++;
		}
		else
		{
			etc++;
		}
	}

	printf("* 영문자대소문자 : %d 개\n", eng);
	printf("* 숫자문자 : %d 개\n", su);
	printf("* 여백문자(space,tab,enter) : %d 개\n", ste);
	printf("* 그외 기타문자 : %d 개\n", etc);

	return 0;
}

