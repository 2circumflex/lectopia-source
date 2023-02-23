/* 날짜 : 2012년 2월 13일   
   작성자 : 이로운   
   프로그램의 기능 : 문자종류별 카운트 프로그램 */
#include <stdio.h> 
#pragma warning (disable : 4996)
void output(int, int, int, int);
int main(void) 
{ 
	char ch;
	int eng=0, su=0, ste=0, etc=0;

	printf("아무거나 입력하시오(종료는ctrl+z) : ");

	while((ch=getchar()) != EOF)
	{		
		if(ch == '\n')
		{
			ste++;
			output(eng, su, ste, etc);
			eng=0, su=0, ste=0, etc=0;
			printf("아무거나 입력하시오(종료는ctrl+z) : ");
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			eng++;
		}
		else if(ch >= 'a' && ch <= 'z')
		{
			eng++;
		}
		else if(ch >= '0' && ch <= '9')
		{
			su++;
		}
		else if(ch == ' ' || ch == '\t')
		{
			ste++;
		}
		else
		{
			etc++;
		}		
	}	

	return 0; 
}

void output(int a, int b, int c, int d)
{
	printf("* 영문자대소문자 : %2d 개\n", a);
	printf("* 숫자문자 : %2d 개\n", b);
	printf("* 여백문자(space, tab, enter) : %2d 개\n", c);
	printf("* 그외 기타문자 : %2d 개\n\n", d);
	return;
}
