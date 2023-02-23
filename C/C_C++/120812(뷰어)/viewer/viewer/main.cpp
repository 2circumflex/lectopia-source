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

int m_num=1;		//�޴���ȣ
int x=9;			//��ǥ x��
int autosc = 0;		//���佺ũ��
int opentxt = 0;	//���Ͽ���Ȯ��
int txtcolor = 7;	//���ڻ�

/*----------------------------------------------------------------------------------------*/

//�����Լ�
int main()
{	
	int key, keys=0, res, ch;
	char loc[100];
	LinkedList List;
	TextInfo tInfo;
			
	h_menu(&tInfo);	//�ʱ�޴�

	while(1)
	{
		keys = keyInput(&key);
		if(key == SPECIAL_KEY)	//Ư��Ű�Է�
		{
			gotoxy(x, 2);
			printf(" ");

			if(keys == LEFT_ARROW && x!=9)	//�� ����Ű
			{
				x -= 9;
				m_num--;			
			}
			else if(keys == RIGHT_ARROW && x!=45)	//�� ����Ű
			{
				x += 9;
				m_num++;
			}
			else if(keys == UP_ARROW  && opentxt == 1 && tInfo.curLine != 1)	//�� ����Ű
			{
				tInfo.curLine--;
				text_print(&List, &tInfo, strPrint);
			}
			else if(keys == DOWN_ARROW && opentxt == 1 && tInfo.curLine <= List.len-16)	//�� ����Ű
			{
				if(tInfo.totLine > 16)	//16���� �̻��϶�
				{
					tInfo.curLine++;
					text_print(&List, &tInfo, strPrint);
				}
			}
			else if(keys == PAGEUP && opentxt == 1)	//��������
			{
				if(tInfo.curLine > 16) tInfo.curLine -= 16;
				else if(tInfo.curLine < 17)	tInfo.curLine = 1;
				text_print(&List, &tInfo, strPrint);
			}
			else if(keys == PAGEDOWN && opentxt == 1)	//�������ٿ�
			{
				if(tInfo.totLine > 16)	//16�����̻��϶�
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
		else if(key == COMMON_KEY)	//�Ϲ�Ű�Է�
		{
			if(keys == 13)	//�����Է�
			{
				switch(m_num)
				{
					//����
					case 1:
					if(opentxt == 0)	//������ �������� ������
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
					else if(opentxt == 1)	//������ ����������
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
					
					//ã��
					case 2:
					find(&List);
					break;
					
					//��
					case 3:
					text_color();
					if(opentxt == 1)	text_print(&List, &tInfo, strPrint);
					break;
				
					//����
					case 4:
					helpme();
					break;

					//����
					case 5:
					text_end(&List, &tInfo);
					return 0;
				}
			}
			else if(keys == 53 && opentxt == 1)	//���佺ũ��
			{
				autosc = 1;
				if(tInfo.totLine > 16)
				{
					while(autosc == 1)
					{
						if(tInfo.curLine == List.len-16)	autosc = 0;						
						Sleep(1000);	//1��
						tInfo.curLine++;
						text_print(&List, &tInfo, strPrint);
						
						if(kbhit())	//Ű�� �ԷµǸ� ESC���� Ȯ��
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

//����
void text_color(void)
{
	int color;
	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');
	gotoxy(5, 3);
	printf("���ϴ� ���ڻ� ��ȣ�� �Է��ϼ��� : ");
	gotoxy(5, 4);
	printf("BLUE(1) GREEN(2) CYAN(3) RED(4) LIGHTGRAY(7) YELLOW(14) WHITE(15)");
	gotoxy(39, 3);
	fflush(stdin);
	scanf("%d", &color);
	if(color==BLUE || color==GREEN || color==CYAN || color==RED || color==LIGHTGRAY || color==YELLOW || color==WHITE)
		txtcolor = color;
}

//����
void helpme(void)
{
	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');
	gotoxy(5, 3);
	printf("��� : �޴��̵�   ��� : �����̵�   PgUp/Dn : �������̵�\n");
	gotoxy(5, 4);
	printf("5 : ���佺ũ��   ���佺ũ������ : ESC");
}

//ã��޴�
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
		printf("ã�� �ܾ �Է��ϼ��� : ");
		fflush(stdin);
		gets(str);
		strCnt = text_find(list, str);
		gotoxy(5, 4);
		printf("�� %d�� ã�ҽ��ϴ�!", strCnt);
	}
	else
	{
		gotoxy(1, 3);
		ch_prn(' ');
		gotoxy(1, 4);
		ch_prn(' ');
		gotoxy(5, 3);
		printf("���� ���� ã��!");
	}
}

//������ �����ϴ��� üũ
int file_chk(char *sp)
{
	FILE * fp = fopen(sp, "rt");

	if(fp==NULL)
	{
		gotoxy(1, 4);
		ch_prn(' ');
		gotoxy(5, 4);
		printf("����!!");
		return 0;
	}
	else return 1;
}

//�˻�
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

//����
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
			//������ �������� �������
			if(res == EOF)
			{
				fclose(fp1);
				fp1 = fopen("list.txt", "at");
				fprintf(fp1, "%s %d\n", tp->t_name, tp->curLine);
				fclose(fp1);
				fclose(fp2);
				break;
			}

			//������ �����Ұ�� ����
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
	printf("�����մϴ�\n");
	if(opentxt == 1)	destroy(list, strFree);

	//���ϴ����� ǥ��
	opentxt = 0;
}

//ch���� �ݺ� ����Ʈ
void ch_prn(char ch)
{
	int i;
	for(i=0; i<79; i++)	putchar(ch);	printf("\r");
}

//�о��� �ؽ�Ʈ���� üũ
void open_Chk(TextInfo *tp)
{
	char tmp[100];
	char yn;
	int line, res;
	FILE *fp;
	if((fp = fopen("list.txt", "rt")) == NULL)
	{
		printf("����!!!");
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
			printf("�̾�� ok?(y,n) : ");
			fflush(stdin);
			scanf("%c", &yn);

			if(yn == 'y' || yn == 'Y')	tp->curLine = line;
		}
	}
	fclose(fp);
}

//���� ���� �޴�
void openMenu(char *cp)
{	
	gotoxy(1, 3);
	ch_prn(' ');
	gotoxy(1, 4);
	ch_prn(' ');
	gotoxy(5, 3);
	printf("������ �Է��ϼ��� : ");
	fflush(stdin);
	scanf("%s", cp);
}

//��� �ָ޴�
void h_menu(TextInfo *tp)
{
	system("cls");
	
	printf("\n   ����(v)  ã��( )  ����( )  ����( )  ����( )\n");	
	printf("    * �޴��� �����ϼ���!!\n\n");
	ch_prn('=');
	gotoxy(1, 23);
	ch_prn('=');
	gotoxy(1, 24);
	printf(" ���ڼ� : 0  ���μ� : 0");
}

//�ؽ�Ʈ���
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

		list->curp = list->curp->next;	//���������̵�
		if(k == tp->totLine-2)	break;
		k++;
	}

	//16�� �̸��϶�
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

//�ϴ� �ؽ�Ʈ����
void view_info(TextInfo *tp)
{	
	gotoxy(1, 23);
	ch_prn('=');
	printf("\n");
	ch_prn(' ');
	gotoxy(1,24);
	printf(" ���ϸ� : %s  ���ڼ� : %d  ���μ� : %d/%d",tp->t_name, tp->chCnt, tp->curLine, tp->totLine);
}

//�ؽ�Ʈ�ε�
int textLoad(LinkedList *list, TextInfo *tp, char *name)
{
	char tmp[80];

	FILE * fp;
	if((fp=fopen(name, "rt"))==NULL)
	{
		gotoxy(1, 4);
		ch_prn(' ');
		gotoxy(5, 4);
		printf("����!!");
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
	printf("���� ���� ����\n\n");
	
	//���Ͽ����� ǥ��
	opentxt = 1;

	return 1;
}

//�Ϲ�, Ư���� �ޱ�
char keyInput(int *keyFlag)
{ 
	char ascii, scan; 

	ascii=getch(); // �Էµ� ������ �ƽ�Ű�ڵ带 �Է¹޾ƿ� 
	if(ascii==-32 || ascii==0)
	{ // �Էµ� ������ �ƽ�Ű�ڵ尡 -32�̰ų� 0�̸� Ư��Ű�� �ԷµȰ��� 
		scan=getch(); // Ư��Ű�� �ԷµǾ��������� scan code���� �Է¹޾ƿ� 
		*keyFlag=SPECIAL_KEY; 
		return (scan); 
	} 
	else
	{ // �Ϲ�Ű�� �ԷµǾ����� 
		*keyFlag=COMMON_KEY; 
		return (ascii); 
	}
}

//Ŀ������
void gotoxy(int x, int y)
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

//�ؽ�Ʈ Į��
void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}