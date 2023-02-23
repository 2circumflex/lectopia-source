#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#pragma warning(disable:4996)

void gotoxy(int x, int y);
int menu(void);
void Str_input(char (*)[20], int *, int);
void Str_output(char (*)[20], int);
void Str_search(char (*)[20], int);
void Str_delete(char (*)[20], int *);
void m_end();

int main() 
{	
	char str[20][20];
	int m_num, cnt=0, row;
	row = sizeof(str) / sizeof(str[0]);

	while(1)
	{
		m_num = menu();

		switch(m_num)
		{
			case 1 : Str_input(str, &cnt, row); break;
			case 2 : Str_output(str, cnt); break;
			case 3 : Str_search(str, cnt); break;
			case 4 : Str_delete(str, &cnt); break;
			case 5 : m_end(); break;
		}

		if(m_num == 5) break;
	}
	
	return 0;
}

//종료
void m_end()
{
	system("cls");
	gotoxy(30, 12);
	printf("종료...");
}

//입력하기
void Str_input(char (*str)[20], int * cnt, int row)
{	
	int i;
	char tmp_str[20];

	system("cls");
	for(i=(*cnt); i<row; i++)
	{
		fflush(stdin);
		printf("# 영문 단어를 입력하세요 : ");		
		scanf("%s", tmp_str);

		if(strcmp(tmp_str, "end") == 0)
		{
			*cnt = i;
			printf("입력종료");
			getch();
			return;
		}
		else
		{
			strcpy(str[i], tmp_str);			
		}		
	}

	*cnt = row;	
}

//출력하기
void Str_output(char (*str)[20], int cnt)
{
	int i;

	system("cls");
	if(cnt == 0)
	{
		printf("입력된 단어가 없습니다\n");
		getch();
		return;
	}
	
	for(i=1; i<=cnt; i++)
	{
		printf("단어 %d : %s\n", i, str[i-1]);
		if(i%10==0 && i!=cnt)	getch();		
	}
	
	printf("출력완료");
	getch();
	
}

//검색하기
void Str_search(char (*str)[20], int cnt)
{
	int i, res;
	char tmp_str[20];
	
	system("cls");
	while(1)
	{
		fflush(stdin);
		printf("# 찾는 단어를 입력하세요 : ");
		scanf("%s", tmp_str);

		if(strcmp(tmp_str, "end") == 0)
		{
			printf("@ 종료합니다\n");
			getch();
			return;
		}
		else
		{
			printf("@ %s 문자열은 ", tmp_str);
		
			for(i=0; i<cnt; i++)
			{
				res = strcmp(str[i], tmp_str);
				if(res==0)
				{
					printf("%d번째 문자열입니다.\n\n", i+1);
					break;
				}				
			}

			if(res!=0)	printf("존재하지 않습니다.\n\n");
		}
	}
}

//삭제하기
void Str_delete(char (*str)[20], int * cnt)
{
	int i, j, res;
	char tmp_str[20], yn;

	system("cls");
	while(1)
	{
		fflush(stdin);
		printf("# 삭제할 단어를 입력하세요 : ");
		scanf("%s", tmp_str);

		if(strcmp(tmp_str, "end")==0)
		{
			printf("@ 종료합니다\n");
			getch();
			return;
		}
		else
		{
			for(i=0; i<(*cnt); i++)
			{
				res = strcmp(str[i], tmp_str);
				
				if(res==0)
				{
					printf("# 정말로 삭제 하시겠습니까? (Y/N) : ");
					fflush(stdin);
					yn = getchar();

					if(yn=='y' || yn=='Y')
					{
						strcpy(str[i], "\0");
						for(j=i; j<(*cnt)-1; j++)
						{
							strcpy(str[j], str[j+1]);
						}
						printf("@ 삭제되었습니다.\n\n");
						(*cnt)--;
						break;
					}
					else
					{
						printf("@ 삭제가 취소되었습니다.\n\n");
						break;
					}
				}
			}

			if(res!=0)	printf("@ %s 문자열은 존재하지 않습니다.\n\n", tmp_str);			
		}
	}
}

//커서이동
void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

//메뉴
int menu(void)
{	
	int m_num;

	system("cls");
	gotoxy(25, 7);
	printf("1. 입력하기");
	gotoxy(25, 9);
	printf("2. 출력하기");
	gotoxy(25, 11);
	printf("3. 검색하기");
	gotoxy(25, 13);
	printf("4. 삭제하기");
	gotoxy(25, 15);
	printf("5. 종    료");
	gotoxy(18, 17);
	printf("#메뉴를 선택하세요 : ");

	m_num = getch() - 48;

	return m_num;
}