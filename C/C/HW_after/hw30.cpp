#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#pragma warning (disable:4996)
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15
void textcolor(int , int );
int y_ch(int);
void output(int, int, int, int);
int tot_day(int, int, int, int *);
void gotoxy(int x, int y);
int main() 
{
	int year=2012, month=2, day=1;
	int tot, yi, lday;
	int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	
	int ch;
	
	while(1)
	{		
		tot = tot_day(year, month, day, mon);
		yi = tot%7;
		lday = mon[month-1];
		if((y_ch(year)==1) && (month==2))	lday++;
	
		output(year, month, lday, yi);

		ch = getch();

		if(ch==224)
		{
			ch = getch();
			if(ch==72)
			{
				if(year>1)
				year--;
			}
			else if(ch==80)
			{
				year++;
			}
			else if(ch==75)
			{				
				if(year>1 && month==1)
				{					
					year--;
					month=12;
				}
				else if(month>1)
				{
					month--;
				}
			}
			else if(ch==77)
			{
				if(month==12)
				{
					year++;
					month=1;
				}
				else
				{
					month++;
				}
			}
		}
		else if(ch==27)
		{
			break;
		}
	}

	return 0;
}

void output(int y, int m, int ld, int yi)	//출력
{
	system("cls");
	int i, cnt=0, x=25, line=6;
	
	gotoxy(x+8, line++);
	textcolor(WHITE, BLACK);
	printf("[ %4d 년 %2d 월 ]", y, m);
	gotoxy(x, line++);
	textcolor(LIGHTRED, BLACK);
	printf("Sun  ");
	textcolor(LIGHTGRAY, BLACK);
	printf("Mon  Tue  Wed  Thu  Fri  ");
	textcolor(LIGHTBLUE, BLACK);
	printf("Sat");
	gotoxy(x, line++);
	textcolor(DARKGRAY, BLACK);
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

		if(cnt==0)
		{
			textcolor(LIGHTRED, BLACK);
		}
		else if(cnt==6)
		{
			textcolor(LIGHTBLUE, BLACK);
		}
		else
		{
			textcolor(LIGHTGRAY, BLACK);
		}

		printf("%-5d", i);
		cnt++;

		if(cnt==7)
		{
			cnt=0;
			gotoxy(x, line++);
		}
	}

	gotoxy(x, line++);
	gotoxy(x, line++);
	textcolor(LIGHTCYAN, BLACK);
	printf("ESC : 종료");
	gotoxy(x, line++);
	printf("↑:전년, ↓:다음년, ←:전월, →:다음월");
	printf("\n");
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

void textcolor(int foreground, int background)	//텍스트컬러
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}