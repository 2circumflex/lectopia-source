/* 날짜 : 2012년 2월 16일   
   작성자 : 이로운   
   프로그램의 기능 : 한달치 달력 출력하기 */
#include <stdio.h>
#include <windows.h> 
void gotoxy(int x, int y); 
int year_check(int);
int tot_day(int, int, int, int[]);
void output(int, int, int, int);
int main()
{
	int year=1968, month=2, day=1, tot, yoil, lday;
	int m_ary[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
	tot = tot_day(year, month, day, m_ary);
	yoil = tot%7;
	
	if(year_check(year) == 1 && month == 2)
	{
		lday = 29;
	}
	else
	{
		lday = m_ary[month-1];
	}

	output(year, month, yoil, lday);	

	return 0;
}

void output(int year, int month, int yoil, int lday)	//출력~~
{
	int i, line=5;
	gotoxy(33, line++);
	printf("[ %d년 %d월 ]", year, month);
	gotoxy(15, line++);
	printf("\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	gotoxy(15, line++);
	printf("\t---------------------------------------------------\n");
	
	gotoxy(15, line++);
	for(i=0; i<yoil; i++)
	{
		printf("\t");
	}	

	for(i=1; i<=lday; i++)
	{
		printf("\t%d", i);
		if((i+yoil)%7 == 0)
		{
			gotoxy(15, line++);
		}
	}
	printf("\n\n\n");

	return;
}

int tot_day(int year, int month, int day, int m_ary[])	//년,월,일 총날수함수
{
	int i, y_chk, tot=0;

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
	
	return tot;
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

void gotoxy(int x, int y) //커서이동
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 
