/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : 년도를 입력받아 평년, 윤년 구하는 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int year;

	while(1)
	{
		printf("년도를 입력하시오 : ");
		scanf("%d", &year);


		if (year%4 != 0)
		{
			printf("%d년은 평년(Common year)입니다.\n\n", year);
		}
		else if (year%100 != 0)
		{
			printf("%d년은 윤년(Leap year)입니다.\n\n", year);
		}
		else if (year%400 != 0)
		{
			printf("%d년은 평년(Common year)입니다.\n\n", year);
		}
		else
		{
			printf("%d년은 윤년(Leap year)입니다.\n\n", year);
		}
	}

	return 0;
}