/* ��¥ : 2012�� 2�� 15��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������ */
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#pragma warning (disable : 4996)
void gotoxy(int x, int y);
void left_ch(char *, int);
int main() 
{
	char str[30] = "Happy Birthday!!!!! ";
	int i, size;
	size = strlen(str);

	for(i=1; i<=40; i++)
	{	
		gotoxy(30, 12);
		printf("[%s]", str);		
		Sleep(100);
		system("cls");
		Sleep(100);			
		left_ch(str, size);	
	}

	Sleep(200);

	for(i=1; i<=3; i++)
	{		
		gotoxy(30, 12);
		printf("[%s]", str);
		system("cls");
		Sleep(500);		
	}
				
	return 0;
}

void gotoxy(int x, int y)	//gotoxy
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

void left_ch(char *str, int size) //�����̵�
{
	int i;
	char tmp;

	tmp = str[0];
	for(i=0; i<size-1; i++)
	{		
		str[i] = str[i+1];		
	}
	str[size-1] = tmp;

	return;
}