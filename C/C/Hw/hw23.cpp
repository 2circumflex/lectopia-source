/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 대칭되는별찍기 */
#include <stdio.h>

int main()
{
	int i, j;
	for(i=1; i<=6; i++)
	{
		for(j=1; j<=i; j++)
		{
			printf("*");
		}
		for(j=15; j>=i*2; j--)
		{
			printf(" ");
		}
		for(j=1; j<=i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}