#pragma warning(disable:4996)
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "str.h"

/*----------------------------------------------------------------------------------------*/

void gotoxy(int x, int y);
void textcolor(int foreground, int background);
char keyInput(int *keyFlag);

void h_menu(TextInfo *tp);
void view_info(TextInfo *tp);
int textLoad(LinkedList *list, TextInfo *tp, char *name);
void text_print(LinkedList *list, TextInfo *tp, void (*dataPrint)(void*));
void open_Chk(TextInfo *tp);
void text_end(LinkedList *list, TextInfo * tp);
void ch_prn(char ch);
void openMenu(char *cp);
int file_chk(char *sp);
void find(LinkedList *list);
void helpme(void);
void text_color(void);
int text_find(LinkedList *list, char *sp);

/*----------------------------------------------------------------------------------------*/

int m_num=1;		//메뉴번호
int x=9;			//좌표 x축
int autosc = 0;		//오토스크롤
int opentxt = 0;	//파일오픈확인
int txtcolor = 7;	//글자색

/*----------------------------------------------------------------------------------------*/

//메인함수
int main()
{	
	int key, keys=0, res, ch;
	char loc[100];
	LinkedList List;
	TextInfo tInfo;
			
	h_menu(&tInfo);	//초기메뉴

	while(1)
	{
		keys = keyInput(&key);
		if(key == SPECIAL_KEY)	//특수키입력
		{
			gotoxy(x, 2);
			printf(" ");

			if(keys == LEFT_ARROW && x!=9)	//좌 방향키
			{
				x -= 9;
				m_num--;			
			}
			else if(keys == RIGHT_ARROW && x!=45)	//우 방향키
			{
				x += 9;
				m_num++;
			}
			else if(keys == UP_ARROW  && opentxt == 1 && tInfo.curLine != 1)	//상 방향키
			{
				tInfo.curLine--;
				text_print(&List, &tInfo, strPrint);
			}
			else if(keys == DOWN_ARROW && opentxt == 1 && tInfo.curLine <= List.len-16)	//하 방향키
			{
				if(tInfo.totLine > 16)	//16라인 이상일때
				{
					tInfo.curLine++;
					text_print(&List, &tInfo, strPrint);
				}
			}
			else if(keys == PAGEUP && opentxt == 1)	//페이지업
			{
				if(tInfo.curLine > 16) tInfo.curLine -= 16;
				else if(tInfo.curLine < 17)	tInfo.curLine = 1;
				text_print(&List, &tInfo, strPrint);
			}
			else if(keys == PAGEDOWN && opentxt == 1)	//페이지다운
			{
				if(tInfo.totLine > 16)	//16라인이상일때
				{
					if(tInfo.curLine <= tInfo.totLine-30)
					{
						tInfo.curLine += 16;
					}
					else if(tInfo.curLine > tInfo.totLine-30)
					{
						tInfo.curLine = tInfo.totLine - 15;
					}
				}
				text_print(&List, &tInfo, strPrint);
			}

			gotoxy(x, 2);
			printf("v");			
			gotoxy(4, 3);	
		}
		else if(key == COMMON_KEY)	//일반키입력
		{
			if(keys == 13)	//엔터입력
			{
				switch(m_num)
				{
					//열기
					case 1:
					if(opentxt == 0)	//파일이 열려있지 않을때
					{
						openMenu(loc);
						init(&List, &tInfo);
						res = textLoad(&List, &tInfo, loc);
						if(res == 1)
						{
							open_Chk(&tInfo);
							text_print(&List, &tInfo, strPrint);
						}
					}
					else if(opentxt == 1)	//파일이 열려있을때
					{
						openMenu(loc);
						res = file_chk(loc);
						if(res == 1)
						{
							destroy(&List, strFree);
							init(&List, &tInfo);
							res = textLoad(&List, &tInfo, loc);
							if(res == 1)
							{
								open_Chk(&tInfo);
								text_print(&List, &tInfo, strPrint);
							}
						}
					}
					break;
					
					//찾기
					case 2:
					find(&List);
					break;
					
					//색
					case 3:
					text_color();
					if(opentxt == 1)	text_print(&List, &tInfo, strPrint);
					break;
				
					//도움말
					case 4:
					helpme();
					break;

					//종료
					case 5:
					text_end(&List, &tInfo);
					return 0;
				}
			}
			else if(keys == 53 && opentxt == 1)	//오토스크롤
			{
				autosc = 1;
				if(tInfo.totLine > 16)
				{
					while(autosc == 1)
					{
						if(tInfo.curLine == List.len-16)	autosc = 0;						
						Sleep(1000);	//1초
						tInfo.curLine++;
						text_print(&List, &tInfo, strPrint);
						
						if(kbhit())	//키가 입력되면 ESC인지 확인
						{
							ch = getch();
							if(ch == ESC)	autosc = 0;
						}
					}
				}			
			}
		}		
	}

	return 0;
}

/*----------------------------------------------------------------------------------------*/

//색깔
void text_color(void)
{
	int color;
	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');
	gotoxy(5, 3);
	printf("원하는 글자색 번호를 입력하세요 : ");
	gotoxy(5, 4);
	printf("BLUE(1) GREEN(2) CYAN(3) RED(4) LIGHTGRAY(7) YELLOW(14) WHITE(15)");
	gotoxy(39, 3);
	fflush(stdin);
	scanf("%d", &color);
	if(color==BLUE || color==GREEN || color==CYAN || color==RED || color==LIGHTGRAY || color==YELLOW || color==WHITE)
		txtcolor = color;
}

//도움말
void helpme(void)
{
	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');
	gotoxy(5, 3);
	printf("←→ : 메뉴이동   ↑↓ : 라인이동   PgUp/Dn : 페이지이동\n");
	gotoxy(5, 4);
	printf("5 : 오토스크롤   오토스크롤해제 : ESC");
}

//찾기메뉴
void find(LinkedList *list)
{
	int strCnt;
	char str[100];
	if(opentxt == 1)
	{
		gotoxy(1, 3);
		ch_prn(' ');
		gotoxy(1, 4);
		ch_prn(' ');
		gotoxy(5, 3);
		printf("찾을 단어를 입력하세요 : ");
		fflush(stdin);
		gets(str);
		strCnt = text_find(list, str);
		gotoxy(5, 4);
		printf("총 %d개 찾았습니다!", strCnt);
	}
	else
	{
		gotoxy(1, 3);
		ch_prn(' ');
		gotoxy(1, 4);
		ch_prn(' ');
		gotoxy(5, 3);
		printf("파일 열고선 찾아!");
	}
}

//파일이 존재하는지 체크
int file_chk(char *sp)
{
	FILE * fp = fopen(sp, "rt");

	if(fp==NULL)
	{
		gotoxy(1, 4);
		ch_prn(' ');
		gotoxy(5, 4);
		printf("오류!!");
		return 0;
	}
	else return 1;
}

//검색
int text_find(LinkedList *list, char *sp)
{
	int cnt;
	char *strPtr;
	cnt = 0;
	list->curp = list->headp->next;
	while(list->curp != list->tailp)
	{
		strPtr = (char*)(list->curp+1);
		while(1)
		{
			strPtr = strstr(strPtr, sp);
			if(strPtr!=NULL)
			{
				cnt++;
				strPtr += strlen(sp);
			}
			else	break;			
		}
		list->curp = list->curp->next;
	}
	return cnt;
}

//종료
void text_end(LinkedList *list, TextInfo * tp)
{
	char tmp[100];
	int line, res;
	if(opentxt == 1)
	{
		FILE * fp1;
		FILE * fp2;
	
		fp1 = fopen("list.txt", "rt");
		fp2 = fopen("listcopy.txt", "wt");
	
		while(1)
		{
			res = fscanf(fp1, "%s %d", tmp, &line);
			//파일이 존재하지 않을경우
			if(res == EOF)
			{
				fclose(fp1);
				fp1 = fopen("list.txt", "at");
				fprintf(fp1, "%s %d\n", tp->t_name, tp->curLine);
				fclose(fp1);
				fclose(fp2);
				break;
			}

			//파일이 존재할경우 수정
			if(strcmp(tp->t_name, tmp) == 0)
			{
				rewind(fp1);

				while(1)
				{
					res = fscanf(fp1, "%s %d", tmp, &line);
					if(res == EOF)	break;

					if(strcmp(tp->t_name, tmp) == 0)
					{
						fprintf(fp2, "%s %d\n", tp->t_name, tp->curLine);
					}
					else
					{
						fprintf(fp2, "%s %d\n", tmp, line);
					}
				}
				fclose(fp1);
				fclose(fp2);
				system("del list.txt");
				system("ren listcopy.txt list.txt");
				break;
			}
		}
	}

	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');
	ch_prn(' ');
	
	system("cls");
	gotoxy(5, 3);
	printf("종료합니다\n");
	if(opentxt == 1)	destroy(list, strFree);

	//파일닫은거 표시
	opentxt = 0;
}

//ch문자 반복 프린트
void ch_prn(char ch)
{
	int i;
	for(i=0; i<79; i++)	putchar(ch);	printf("\r");
}

//읽었던 텍스트인지 체크
void open_Chk(TextInfo *tp)
{
	char tmp[100];
	char yn;
	int line, res;
	FILE *fp;
	if((fp = fopen("list.txt", "rt")) == NULL)
	{
		printf("에러!!!");
	}

	while(1)
	{
		res = fscanf(fp, "%s %d", tmp, &line);
		if(res == EOF)	break;
		else if(strcmp(tp->t_name, tmp) == 0)
		{
			/*gotoxy(1, 3);
			ch_prn(' ');
			gotoxy(1, 4);
			ch_prn(' ');*/
			gotoxy(5, 4);
			printf("이어보기 ok?(y,n) : ");
			fflush(stdin);
			scanf("%c", &yn);

			if(yn == 'y' || yn == 'Y')	tp->curLine = line;
		}
	}
	fclose(fp);
}

//열기 보조 메뉴
void openMenu(char *cp)
{	
	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');
	gotoxy(5, 3);
	printf("파일을 입력하세요 : ");
	fflush(stdin);
	scanf("%s", cp);
}

//상단 주메뉴
void h_menu(TextInfo *tp)
{
	system("cls");
	
	printf("\n   열기(v)  찾기( )  색깔( )  설명( )  종료( )\n");	
	printf("    * 메뉴를 선택하세요!!\n\n");
	ch_prn('=');
	gotoxy(1, 23);
	ch_prn('=');
	gotoxy(1, 24);
	printf(" 글자수 : 0  라인수 : 0");
}

//텍스트출력
void text_print(LinkedList *list, TextInfo *tp, void (*dataPrint)(void*))
{
	int i, k=0;

	gotoxy(1, 5);
	for(i=0; i<79; i++)	printf("=");
	printf("\n");
	
	list->curp = list->headp->next;

	for(i=0; i<tp->curLine-1; i++)
	{
		list->curp = list->curp->next;
	}

	for(i=0; i<16; i++)
	{		
		ch_prn(' ');
		printf("\r");
		textcolor(txtcolor, BLACK);
		dataPrint(list->curp+1);

		list->curp = list->curp->next;	//다음노드로이동
		if(k == tp->totLine-2)	break;
		k++;
	}

	//16줄 미만일때
	if(tp->totLine <17)
	{
		for(i=tp->totLine; i<17; i++)
		{
			ch_prn(' ');
		}
	}
	textcolor(LIGHTGRAY, BLACK);
	view_info(tp);
}

//하단 텍스트정보
void view_info(TextInfo *tp)
{	
	gotoxy(1, 23);
	ch_prn('=');
	printf("\n");
	ch_prn(' ');
	gotoxy(1,24);
	printf(" 파일명 : %s  글자수 : %d  라인수 : %d/%d",tp->t_name, tp->chCnt, tp->curLine, tp->totLine);
}

//텍스트로드
int textLoad(LinkedList *list, TextInfo *tp, char *name)
{
	char tmp[80];

	FILE * fp;
	if((fp=fopen(name, "rt"))==NULL)
	{
		gotoxy(1, 4);
		ch_prn(' ');
		gotoxy(5, 4);
		printf("오류!!");
		return 0;
	}

	strcpy(tp->t_name, name);

	while(!feof(fp))
	{
		fgets(tmp, 80, fp);
		appendFromTail(list, tmp, strlen(tmp)+1, strMemCopy);
		tp->chCnt += strlen(tmp);
	}
	fclose(fp);

	tp->curLine = 1;
	tp->totLine = list->len;
	
	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');	
	gotoxy(5, 3);
	printf("파일 열기 성공\n\n");
	
	//파일열은거 표시
	opentxt = 1;

	return 1;
}

//일반, 특수기 받기
char keyInput(int *keyFlag)
{ 
	char ascii, scan; 

	ascii=getch(); // 입력된 문자의 아스키코드를 입력받아옴 
	if(ascii==-32 || ascii==0)
	{ // 입력된 문자의 아스키코드가 -32이거나 0이면 특수키가 입력된것임 
		scan=getch(); // 특수키가 입력되었을때에는 scan code값을 입력받아옴 
		*keyFlag=SPECIAL_KEY; 
		return (scan); 
	} 
	else
	{ // 일반키가 입력되었으면 
		*keyFlag=COMMON_KEY; 
		return (ascii); 
	}
}

//커서제어
void gotoxy(int x, int y)
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

//텍스트 칼라
void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}