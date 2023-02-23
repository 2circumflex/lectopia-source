/* 날짜 : 2012년 2월 13일   
   작성자 : 이로운   
   프로그램의 기능 : 요일 구하는 프로그램 */
#include <stdio.h> 
#include <string.h>
#pragma warning (disable : 4996)
void input(int*, int*, int*);
int year_check(int);
int main(void) 
{
	int year, month, day, tot, i, y_chk;
	char yoil[7];
	int m_ary[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	while(1)
	{
		tot = 0;
		input(&year, &month, &day);	//년월일 입력받기

		for(i=1; i<=year-1; i++)		//년도의 총날수
		{
			y_chk = year_check(i);

			if(y_chk == 1)
			{
				tot += 366;
			}
			else
			{
				tot += 365;
			}
		}

		for(i=0; i<month-1; i++)		//월의 총날수
		{
			tot += m_ary[i];
		}

		tot += day;	//일의 총날수
		
		if((year_check(year)) == 1 && month >= 3)	//날수보정
		{
			tot++;
		}

		switch(tot%7)
		{
			case 0 : strcpy(yoil, "일요일"); break;
			case 1 : strcpy(yoil, "월요일"); break;
			case 2 : strcpy(yoil, "화요일"); break;
			case 3 : strcpy(yoil, "수요일"); break;
			case 4 : strcpy(yoil, "목요일"); break;
			case 5 : strcpy(yoil, "금요일"); break;
			case 6 : strcpy(yoil, "토요일"); break;
		}

		printf("%d년 %d월 %d일은 %s입니다.\n\n", year, month, day, yoil);
	}

	return 0; 
}

void input(int *y, int *m, int *d)	//년월일 입력함수
{
	printf("* 년월일을 입력하시오 : ");
	scanf("%d %d %d", y, m, d);
}

int year_check(int y)	//윤년 계산함수
{
	if (y%4 != 0)
	{
		return 0;
	}
	else if (y%100 != 0)
	{
		return 1;
	}
	else if (y%400 != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}