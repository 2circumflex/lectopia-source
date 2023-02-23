#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include<time.h> 

#pragma warning (disable:4996)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define PPP "▧"
#define SPECIAL_KEY 0
#define COMMON_KEY 1
#define UP_ARROW 72 
#define DOWN_ARROW 80 
#define LEFT_ARROW 75 
#define RIGHT_ARROW 77 
#define ENTER 13 
#define ESC 27 
#define SPACE_BAR 32

struct BOX{
	char MAP[25][40];//맵모양
	int object[2];//객체의좌표
	int stage[3];//게임탄수,행,열
	int goal[10][2];//골인지점 좌표
};

void clrscr(int startX, int startY, int endX, int endY); //부분 삭제함수
void gotoxy(int x, int y);// 커서이동함수
void removeCursor();//커서 없애는 함수
void displayCursor(); //커서 보이게하는 함수
char inKey(int *keyFlag);// 특수키 입력 받을수 있게끔 하는 함수
void textcolor(int foreground, int background); //컬러 바꾸는 함수
void loadMap(BOX *box);//맵로드
void blockDisplay(BOX *box);//벽출력
int goalCheck(BOX *box,int gCnt);//골인인지체크
void upKey(BOX *box);//up으로 이동가능한지 확인
void downKey(BOX *box);//down으로 이동가능한지 확인
void leftKey(BOX *box);//left으로 이동가능한지 확인
void rightKey(BOX *box);//right으로 이동가능한지 확인
void moveDisplay(BOX *box,int *gCnt);//객체 박스 골인지점 출력
void move(BOX *box,int direction,int caseNum);//객체와박스 이동

int main()
{
	BOX Box;
	int step=0;
	char ch;
	int keyFlag;
	int res=0,gCnt=0;//골인지점 갯수
	int i=0;
	printf("몇 탄부터 시작하시겠습니까?(1~10) : ");
	scanf("%d",&Box.stage[0]);//탄수입력받음

	while(1)
	{
		loadMap(&Box);
		blockDisplay(&Box);
		moveDisplay(&Box,&gCnt);
		goalCheck(&Box,gCnt);

		while(1)
		{

			ch=inKey(&keyFlag);
			switch(ch)
			{	
			case UP_ARROW: upKey(&Box);break;
			case DOWN_ARROW: downKey(&Box);break;
			case LEFT_ARROW:leftKey(&Box); break;
			case RIGHT_ARROW:rightKey(&Box);break;
			case SPACE_BAR:break;
			case ESC:break;
			}
			moveDisplay(&Box,&gCnt);
			step=goalCheck(&Box,gCnt);
			if(ch==SPACE_BAR||step==1)
			{
				gCnt=0;
				break;
			}
			if(ch==ESC)
			{
				res=1;
				break;
			}


		} //while

		if(res==1)
		{
			break;
		}


	}//while
	return 0;
}
void loadMap(BOX *box)
{
	int i,j;
	char str[100];
	FILE* ifp;
	sprintf(str,"C:\\data\\map%d.txt",box->stage[0]);
	ifp=fopen(str,"rt");
	fscanf(ifp,"%d %d",&box->stage[1], &box->stage[2]); 

	for(i=0; i<box->stage[1]; i++)
	{
		for(j=0; j<=box->stage[2]; j++)
		{
			fscanf(ifp,"%c",&box->MAP[i][j]);
			if(box->MAP[i][j]=='\n')
			{
				box->MAP[i][j]=NULL;
				break;
			}
		}
	}
	fclose(ifp);
}
void blockDisplay(BOX *box)
{
	int i,j;
	for(i=0; i<box->stage[1]; i++)
	{
		for(j=0; j<=box->stage[2]; j++)
		{
			if(box->MAP[i][j]=='B')
			{
				gotoxy(4+(j*2),i+2);
				printf("%s",PPP);
			}
		}	
	}
}
void moveDisplay(BOX *box,int* gCnt)
{
	int i,j;
	for(i=0; i<box->stage[1]; i++)
	{
		for(j=0; j<=box->stage[2]; j++)
		{
			if(box->MAP[i][j]=='C')
			{
				gotoxy(4+(j*2),2+i);
				printf("●");
				box->object[0]=j;
				box->object[1]=i;
				gotoxy(40+i,15);
			}
			else if(box->MAP[i][j]=='T')
			{
				gotoxy(4+(j*2),2+i);
				printf("■");
			}
			else if(box->MAP[i][j]=='G')
			{
				gotoxy(4+(j*2),2+i);
				printf("▒");
				box->goal[*gCnt][0]=i;
				box->goal[*gCnt][1]=j;
				(*gCnt)++;

			}
			else if(box->MAP[i][j]=='N')
			{
				gotoxy(4+(j*2),2+i);
				printf("  ");
			}
		}
	}
}

void upKey(BOX *box)
{
	int col,row;
	col=box->object[0];
	row=box->object[1];
	if(box->MAP[row-1][col]=='N'|| box->MAP[row-1][col]=='G')
	{
		move(box,UP,1);
	}
	else if(box->MAP[row-1][col]=='T'&&(box->MAP[row-2][col]=='N'||box->MAP[row-2][col]=='G'))
	{
		move(box,UP,2);
	}

}


void downKey(BOX *box)
{
	int row,col;
	col=box->object[0];
	row=box->object[1];

	if(box->MAP[row+1][col]=='N'||box->MAP[row+1][col]=='G')
	{
		move(box,DOWN,1);
	}
	else if(box->MAP[row+1][col]=='T'&&(box->MAP[row+2][col]=='N'||box->MAP[row+2][col]=='G'))
	{
		move(box,DOWN,2);
	}
}
void leftKey(BOX *box)
{
	int row,col;
	col=box->object[0];
	row=box->object[1];

	if(box->MAP[row][col-1]=='N'|| box->MAP[row][col-1]=='G')
	{
		move(box,LEFT,1);
	}
	else if(box->MAP[row][col-1]=='T'&&(box->MAP[row][col-2]=='N'||box->MAP[row][col-2]=='G'))
	{
		move(box,LEFT,2);
	}
}
void rightKey(BOX *box)
{
	int row,col;
	col=box->object[0];
	row=box->object[1];

	if(box->MAP[row][col+1]=='N'|| box->MAP[row][col+1]=='G')
	{
		move(box,RIGHT,1);
	}
	else if(box->MAP[row][col+1]=='T'&&(box->MAP[row][col+2]=='N'||box->MAP[row][col+2]=='G'))
	{
		move(box,RIGHT,2);
	}
}
void move(BOX *box,int direction,int caseNum)
{

	int row,col;
	col=box->object[0];
	row=box->object[1];
	int num;
	if(direction==UP||direction==LEFT)
	{
		num=-1;
	}
	else
	{
		num=+1;
	}
	if(direction==UP||direction==DOWN)
	{
		if(caseNum==1)
		{
			box->MAP[row+num][col]=box->MAP[row][col];
		}
		else
		{
			box->MAP[row+num*2][col]=box->MAP[row+num][col];
			box->MAP[row+num][col]=box->MAP[row][col];
		}
	}
	else
	{
		if(caseNum==1)
		{
			box->MAP[row][col+num]=box->MAP[row][col];
		}
		else
		{
			box->MAP[row][col+num*2]=box->MAP[row][col+num];
			box->MAP[row][col+num]=box->MAP[row][col];
		}
	}
	box->MAP[row][col]='N';
}
int goalCheck(BOX *box,int gCnt)
{
	int i,count=0;

	for(i=0;i<gCnt;i++)
	{
		if(box->MAP[box->goal[i][0]][box->goal[i][1]]=='T')
		{
			gotoxy(4+(box->goal[i][1]*2),box->goal[i][0]+2);
			printf("★");
			count++;
		}
		else if(box->MAP[box->goal[i][0]][box->goal[i][1]]!='C')
		{
			box->MAP[box->goal[i][0]][box->goal[i][1]]='G';
		}
	}

	if(gCnt==count)
	{
		box->stage[0]++;
		return 1;
	}
	return 0;
}
char inKey()
{
	return 'a';
}

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