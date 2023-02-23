/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 총 10개의 정수를 입력받아 홀수와 짝수를 구분지어 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int ary[10], i;
	
	while(1)
	{
		printf("# 10개의 정수 입력 : ");
		for(i=0; i<10; i++)
		{
			scanf("%d", &ary[i]);
		}

		printf("* 홀수 : ");
		for(i=0; i<10; i++)
		{
			if(ary[i]%2 !=0)
			{
				printf("%d ", ary[i]);
			}
		}
		printf("\n");

		printf("* 짝수 : ");
		for(i=0; i<10; i++)
		{
			if(ary[i]%2 ==0)
			{
				printf("%d ", ary[i]);
			}
		}
		printf("\n\n");
	}

	return 0;
}