/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 삼각 알파벳 출력하기 */
#include <stdio.h>

int main()
{
	int i, j;
	char ch = 'F';

	for(i=1; i<=6; i++)
	{
		for(j=0; j<i; j++)
		{
			printf("%c", ch-j);
		}
		printf("\n");
	}
	

	return 0;
}