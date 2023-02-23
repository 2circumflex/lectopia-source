#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)
void gotoxy(int x, int y);
void change_str(char *, int);
int main() 
{
	char str[21] = "Happy Birthday!!!!! ";
	int size, cnt=0;

	size = sizeof(str) / sizeof(str[0]);

	while(cnt++!=40)
	{
		change_str(str, size);
		system("cls");		
		Sleep(200);
		gotoxy(30, 12);
		printf("[%s]", str);		
		Sleep(200);
	}
	cnt=0;
	while(cnt++!=3)
	{
		system("cls");
		Sleep(500);
		gotoxy(30, 12);
		printf("[%s]", str);
		Sleep(500);
	}
	printf("\n");
	
	return 0;
}

void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

void change_str(char *s, int size)
{
	char tp;
	int i;

	tp = s[0];

	for(i=0; i<size-2; i++)
	{
		s[i] = s[i+1];
	}

	s[size-2] = tp;
}