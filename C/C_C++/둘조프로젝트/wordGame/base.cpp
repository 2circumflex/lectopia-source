#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "base.h"
#define COMMON_KEY 1 
#define SPECIAL_KEY 0 
void removeCursor() 
{ 
	// 커서를 없애는 코드 부분 
	CONSOLE_CURSOR_INFO ConCurInf; 
	ConCurInf.dwSize = 50; 
	ConCurInf.bVisible = FALSE; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf); 
} 

void displayCursor() 
{ 
	// 커서를 살리는 코드 부분 
	CONSOLE_CURSOR_INFO ConCurInf; 
	ConCurInf.dwSize = 10; 
	ConCurInf.bVisible = TRUE; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf); 
}

char inKey(int *keyFlag) 
{ 
	char ascii, scan; 

	ascii=getch(); // 입력된 문자의 아스키코드를 입력받아옴 
	if(ascii==-32 || ascii==0){ // 입력된 문자의 아스키코드가 -32이거나 0이면 특수키가 입력된것임 
		scan=getch(); // 특수키가 입력되었을때에는 scan code값을 입력받아옴 
		*keyFlag=SPECIAL_KEY; 
		return (scan); 
	} 
	else { // 일반키가 입력되었으면 
		*keyFlag=COMMON_KEY; 
		return (ascii); 
	} 
}


void clrscr(int startX, int startY, int endX, int endY) 
{ 
	int i,j; 
	for(i=startY; i<=endY; i++){ 
		for(j=startX; j<=endX; j++){ 
			gotoxy(j,i); 
			putch(' '); 
		} 
	}
}

void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
} 
int random(int n) 
{ 
	int res; 
	res = rand() % n; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
} 

void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 



