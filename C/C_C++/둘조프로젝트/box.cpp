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
#define PPP "��"
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
	char MAP[25][40];//�ʸ��
	int object[2];//��ü����ǥ
	int stage[3];//����ź��,��,��
	int goal[10][2];//�������� ��ǥ
};

void clrscr(int startX, int startY, int endX, int endY); //�κ� �����Լ�
void gotoxy(int x, int y);// Ŀ���̵��Լ�
void removeCursor();//Ŀ�� ���ִ� �Լ�
void displayCursor(); //Ŀ�� ���̰��ϴ� �Լ�
char inKey(int *keyFlag);// Ư��Ű �Է� ������ �ְԲ� �ϴ� �Լ�
void textcolor(int foreground, int background); //�÷� �ٲٴ� �Լ�
void loadMap(BOX *box);//�ʷε�
void blockDisplay(BOX *box);//�����
int goalCheck(BOX *box,int gCnt);//��������üũ
void upKey(BOX *box);//up���� �̵��������� Ȯ��
void downKey(BOX *box);//down���� �̵��������� Ȯ��
void leftKey(BOX *box);//left���� �̵��������� Ȯ��
void rightKey(BOX *box);//right���� �̵��������� Ȯ��
void moveDisplay(BOX *box,int *gCnt);//��ü �ڽ� �������� ���
void move(BOX *box,int direction,int caseNum);//��ü�͹ڽ� �̵�

int main()
{
	BOX Box;
	int step=0;
	char ch;
	int keyFlag;
	int res=0,gCnt=0;//�������� ����
	int i=0;
	printf("�� ź���� �����Ͻðڽ��ϱ�?(1~10) : ");
	scanf("%d",&Box.stage[0]);//ź���Է¹���

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
				printf("��");
				box->object[0]=j;
				box->object[1]=i;
				gotoxy(40+i,15);
			}
			else if(box->MAP[i][j]=='T')
			{
				gotoxy(4+(j*2),2+i);
				printf("��");
			}
			else if(box->MAP[i][j]=='G')
			{
				gotoxy(4+(j*2),2+i);
				printf("��");
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
			printf("��");
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