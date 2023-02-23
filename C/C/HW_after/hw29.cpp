#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#pragma warning (disable:4996)
int y_ch(int);
void output(int, int, int, int);
int tot_day(int, int, int, int *);
void gotoxy(int x, int y);
int main() 
{
	int year=1968, month=2, day=1;
	int tot, yi, lday;
	int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	
	
	tot = tot_day(year, month, day, mon);
	yi = tot%7;
	lday = mon[month-1];
	if((y_ch(year)==1) && (month==2))	lday++;
	

	output(year, month, lday, yi);
		
	return 0;
}

void output(int y, int m, int ld, int yi)	//출력
{
	int i, cnt=0, x=25, line=6;
	
	gotoxy(x+8, line++);
	printf("[ %d 년 %d 일 ]", y, m);
	gotoxy(x, line++);
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat");
	gotoxy(x, line++);
	printf("---------------------------------");
	gotoxy(x, line++);
	for(i=1; i<=ld; i++)
	{
		
		while(yi>0)
		{
			yi--;
			printf("     ");
			cnt++;
		}		

		printf("%-5d", i);
		cnt++;

		if(cnt==7)
		{
			cnt=0;
			gotoxy(x, line++);
		}
	}

	printf("\n");
	getch();
}

int tot_day(int year, int month, int day, int *mon)	//총일수
{
	int tot=0, i, ych;

	for(i=1; i<=year-1; i++)
	{			
		tot += 365;
		if((ych=y_ch(i)) == 1)
		{
			tot++;
		}
	}

	for(i=0; i<month-1; i++)
	{
		tot += mon[i];
	}

	tot += day;
	if((y_ch(year)==1) && (month>=3))	tot++;

	return tot;
}

int y_ch(int year)	//윤년체크
{
	if(year%4 != 0)
	{
		return 0;
	}
	else if(year%100 != 0)
	{
		return 1;
	}
	else if(year%400 != 0)
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