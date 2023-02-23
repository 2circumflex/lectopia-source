/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 1~100까지의 숫자를 출력, 3의 배수는 *, 5의 배수는 # 3과 5의 공배수는 정상숫자로 출력 */
#include <stdio.h>

int main()
{
	int i, j, su=1;

	for(i=1; i<=10; i++)
	{
		for(j=1; j<=10; j++)
		{
			if(su%3 == 0 && su%5 == 0)
			{
				printf("%2d ", su);
			}
			else if(su%3 == 0)
			{
				printf(" * ");
			}
			else if(su%5 == 0)
			{
				printf(" # ");
			}
			else
			{
				printf("%2d ", su);
			}
			su++;
		}
		printf("\n");
	}

	return 0;
}
