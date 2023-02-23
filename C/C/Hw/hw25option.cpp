/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 구구단 출력하기(3중for문) */
#include <stdio.h>

int main()
{
	int i, j, k;
	
	for(i=1; i<=5; i+=4)
	{
		for(j=1; j<=9; j++)
		{
			for(k=i+1; k<=i+4; k++)
			{
				printf("%d*%d=%2d\t\t", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}	

	return 0;
}