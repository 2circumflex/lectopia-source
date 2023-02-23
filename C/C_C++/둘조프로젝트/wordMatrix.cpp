#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define MAX 100
#define random(n) (rand() % (n))                        //0~n까지의 난수 발생

void gotoxy(int x, int y);
void textcolor(int foreground, int background);

struct Signal
{
	int ok;                // 신호의 존재 여부
	char ch;                 // 출력할 문자
	int x,y;                   // 현재 좌표
	int distance;           // 이동할 거리
	int nFrame;                 // 속도
	int nStay;               // 속도에 대한 카운트
};

void beginDisplay()
{
	int i;
	system("cls");
	struct Signal S[MAX];
	srand( time(0) );

	//ok 초기화
	for(i=0; i<MAX; i++)
	{
		S[i].ok = 0;
	}

	while(1)
	{
		if (random(5) == 0)
		{
			for (i=0;i<MAX;i++)
			{
				if (S[i].ok == 0)
				{  
					S[i].ok= 1;
					S[i].ch=random('Z'-'A'+1)+'A';
					S[i].x=random(80);
					S[i].y=0;
					S[i].distance=random(16)+9;
					S[i].nFrame=S[i].nStay=random(15)+5;
					break;
				}
			}
		}
	
		//
		for (i=0;i<MAX;i++)
		{
			if (S[i].ok == 0)
				continue;

			if (--S[i].nStay == 0)
			{
				S[i].nStay=S[i].nFrame;
				gotoxy(S[i].x,S[i].y);
				putch(' ');

				if (++S[i].y < S[i].distance)
				{
					gotoxy(S[i].x,S[i].y);
					textcolor(random(15), 0);
					putch(S[i].ch);
				}
				else
				{
					S[i].ok=0;
				}
			}
		}

		Sleep(5);

		textcolor(15, 0);
		gotoxy(10,8);
		printf("▩▩▩  ▩    ▩▩▩  ▩     ▩▩▩      ▩      ▩▩   ▩▩▩");
		gotoxy(10,9);
		printf("▩      ▩      ▩    ▩    ▩     ▩   ▩▩    ▩▩▩  ▩");
		gotoxy(10,10);
		printf("▩▩▩  ▩▩    ▩    ▩▩  ▩  ▩     ▩▩▩  ▩ ▩ ▩ ▩▩▩");
		gotoxy(10,11);
		printf("▩      ▩     ▩▩   ▩    ▩   ▩   ▩    ▩ ▩ ▩ ▩ ▩");
		gotoxy(10,12);
		printf("▩▩▩  ▩    ▩  ▩  ▩      ▩▩▩  ▩    ▩ ▩ ▩ ▩ ▩▩▩");

		gotoxy(28, 23);
		textcolor(15, 0);
		printf("Please~ press any key!");
	}
}

void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
