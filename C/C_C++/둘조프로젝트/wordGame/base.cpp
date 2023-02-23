#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "base.h"
#define COMMON_KEY 1 
#define SPECIAL_KEY 0 
void removeCursor() 
{ 
	// Ŀ���� ���ִ� �ڵ� �κ� 
	CONSOLE_CURSOR_INFO ConCurInf; 
	ConCurInf.dwSize = 50; 
	ConCurInf.bVisible = FALSE; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf); 
} 

void displayCursor() 
{ 
	// Ŀ���� �츮�� �ڵ� �κ� 
	CONSOLE_CURSOR_INFO ConCurInf; 
	ConCurInf.dwSize = 10; 
	ConCurInf.bVisible = TRUE; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf); 
}

char inKey(int *keyFlag) 
{ 
	char ascii, scan; 

	ascii=getch(); // �Էµ� ������ �ƽ�Ű�ڵ带 �Է¹޾ƿ� 
	if(ascii==-32 || ascii==0){ // �Էµ� ������ �ƽ�Ű�ڵ尡 -32�̰ų� 0�̸� Ư��Ű�� �ԷµȰ��� 
		scan=getch(); // Ư��Ű�� �ԷµǾ��������� scan code���� �Է¹޾ƿ� 
		*keyFlag=SPECIAL_KEY; 
		return (scan); 
	} 
	else { // �Ϲ�Ű�� �ԷµǾ����� 
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
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res; 
} 

void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 



