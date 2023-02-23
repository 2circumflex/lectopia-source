/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 년월 변경 가능한 color달력 출력하기 */
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#pragma warning (disable : 4996)
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
void gotoxy(int x, int y); 
int year_check(int);
int tot_day(int, int, int, int[]);
void output(int, int, int, int);
void ym_check(char, int*, int*);
int main()
{
	int year=2012, month=2, day=1, tot, yoil, lday;
	int m_ary[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char ch=0;

	while(ch!=27)
	{
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

		ch = getch();

		ym_check(ch, &year, &month);

		system("cls");
	}

	return 0;
}
void ym_check(char ch, int * y, int * m)	//키보드입력체크
{
	if(ch == '27')
	{
		return;
	}
	else if(ch == '8')
	{
		*y -= 1;
	}
	else if(ch == '2')
	{
		*y += 1;
	}
	else if(ch == '4')
	{
		if(*m == 1)
		{
			*y -= 1;
			*m = 12;
		}
		else
		{
			*m -= 1;
		}
	}
	else if(ch == '6')
	{
		if(*m == 12)
		{
			*y += 1;
			*m = 1;
		}
		else
		{
			*m += 1;
		}
	}
}

void output(int year, int month, int yoil, int lday)	//출력~~
{
	int i, line=5, tcolor=7;
	gotoxy(33, line++);
	textcolor(WHITE, BLACK);
	printf("[ %4d년 %2d월 ]", year, month);
	gotoxy(15, line++);
	textcolor(LIGHTRED, BLACK);
	printf("\tSun");
	textcolor(LIGHTGRAY, BLACK);
	printf("\tMon\tTue\tWed\tThu\tFri\t");
	textcolor(LIGHTBLUE, BLACK);
	printf("Sat\n");
	gotoxy(15, line++);
	textcolor(DARKGRAY, BLACK);
	printf("\t---------------------------------------------------\n");
	
	gotoxy(15, line++);
	textcolor(LIGHTGRAY, BLACK);
	for(i=0; i<yoil; i++)
	{
		printf("\t");
	}	

	for(i=1; i<=lday; i++)
	{
		if((i+yoil-1)%7 ==0)
		{
			tcolor = 12;
		}
		else if((i+yoil)%7 == 0)
		{
			tcolor = 9;
		}
		else
		{
			tcolor = 7;
		}		
		textcolor(tcolor, BLACK);
		printf("\t%d", i);		
		if((i+yoil)%7 == 0)
		{
			gotoxy(15, line++);			
		}
	}
	
	gotoxy(20, 16);
	textcolor(LIGHTMAGENTA, BLACK);
	printf("↑(8) 전년도 같은월  ↓(2) 다음년도 같은월");
	gotoxy(22, 17);
	printf("←(4) 전월  →(6) 다음월  (ESC) 종료");

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

void textcolor(int foreground, int background)	//텍스트컬러
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}