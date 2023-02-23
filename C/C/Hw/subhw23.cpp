/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 0부터 99까지의 정수를 한줄에 10개씩 수직으로 출력하기 */
#include <stdio.h>
int main()
{	
	int i, j;

	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			printf("  %2d", i+j*10);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}