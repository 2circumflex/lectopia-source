/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : Family 프로그램 - 한문자를 입력받아 f,F이면 Father m,M이면 Mother b,B이면 Brother s,S이면 Sister 출력 그외 문자일 경우는 Input Error 출력 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char family;

	while(1)
	{
		printf("문자 한개를 입력하시오 : ");
		scanf("%c", &family);

		if(family == 'f' || family == 'F')
		{
			printf("Father\n\n");
		}
		else if(family == 'm' || family == 'M')
		{
			printf("Mother\n\n");
		}
		else if(family == 'b' || family == 'B')
		{
			printf("Brother\n\n");
		}
		else if(family == 's' || family == 'S')
		{
			printf("Sister\n\n");
		}
		else
		{
			printf("Input Error!!!\n\n");
		}

		fflush(stdin);
	}

	return 0;
}