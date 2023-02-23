/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 메뉴프로그램 */
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#pragma warning (disable : 4996)
void gotoxy(int x, int y);
char menu();
void input(int*, char (*)[20], int);
void output(char (*)[20], int);
void search(char (*)[20], int);
void mydelete(char (*)[20], int*);
void end();
int main()
{
	char m_res;	
	char word_ary[20][20];
	int cnt=0, row=0;

	row = sizeof(word_ary) / sizeof(word_ary[4]);	//행수

	while(1)
	{
		m_res = menu();	

		switch(m_res)
		{
			case '1' : input(&cnt, word_ary, row ); break;
			case '2' : output(word_ary, cnt); break;
			case '3' : search(word_ary, cnt); break;
			case '4' : mydelete(word_ary, &cnt); break;
			case '5' : end(); break;
		}
		if(m_res == '5') { break; }
	}	

	return 0;
}

char menu()	//주메뉴화면
{
	int line=4;
	char m_num;

	system("cls");
	gotoxy(30, line+=2);
	printf("1. 입력하기");
	gotoxy(30, line+=2);
	printf("2. 출력하기");
	gotoxy(30, line+=2);
	printf("3. 검색하기");
	gotoxy(30, line+=2);
	printf("4. 삭제하기");
	gotoxy(30, line+=2);
	printf("5. 종    료");
	gotoxy(30, line+=2);
	printf("#메뉴를 선택하세요 : ");	
	m_num = getch();
	
	return m_num;
}

void input(int * cnt, char (*word)[20], int row)	//1번 입력하기
{
	int i;
	char tmp[20];
	system("cls");

	for(i=(*cnt); i<row; i++)
	{
		fflush(stdin);
		printf("# 영문 단어를 입력하세요 : ");
		scanf("%s", tmp);
		if(strcmp("end", tmp) == 0)
		{			
			break;
		}
		else
		{
			strcpy(word[i], tmp);
			(*cnt)++;			
		}		
	}
	
	if((*cnt) == 20)
	{
		printf("20개 꽉 찾습니다!\n");
	}
	
	printf("\n\n# 아무키나 누르면 주메뉴로 돌아갑니다.");
	getch();

	return;
}

void output(char (*word)[20], int cnt)	//2번 출력하기
{
	int i;
	system("cls");
	if(cnt == 0)
	{
		printf("출력할 단어가 없습니다\n");
		printf("\n\n# 아무키나 누르면 주메뉴로 돌아갑니다.");
		getch();
	}
	else
	{
		for(i=0; i<cnt; i++)
		{
			printf("단어 %2d : %s\n", i+1, word[i]);

			if(i%10 == 9) { getch(); }			
		}				
		printf("\n\n# 아무키나 누르면 주메뉴로 돌아갑니다.");
		getch();
	}

	return;
}

void search(char (*word)[20], int cnt)	//3번 검색하기
{
	char tmp[20];
	int i, res=0;
	system("cls");
	while(1)
	{
		printf("# 찾는 단어를 입력하세요 : ");
		scanf("%s", tmp);

		if(strcmp("end", tmp) == 0)	//end치면 종료
		{
			printf("\n\n# 아무키나 누르면 주메뉴로 돌아갑니다.");
			getch();
			break;
		}
		else
		{			
			for(i=0; i<cnt; i++)
			{
				res = strcmp(tmp, word[i]);
				if(res == 0)
				{
					printf("@ %s 문자열은 %2d번째 문자열입니다.\n\n", tmp, i+1);
					break;
				}
			}
			if(res != 0)
			{
				printf("@ %s 문자열은 존재하지 않습니다.\n\n", tmp);
			}
		}		
	}

	return;
}

void mydelete(char (*word)[20], int *cnt)	//4번 삭제하기
{
	char tmp[20], ch;
	int i, j;
	system("cls");
	while(1)
	{
		printf("# 삭제할 단어를 입력하세요 : ");
		scanf("%s", tmp);

		if(strcmp(tmp, "end") == 0)	//end치면 종료
		{
			break;
		}

		for(i=0; i<(*cnt); i++)
		{
			if(strcmp(tmp, word[i]) == 0)
			{				
				printf("# 정말로 삭제 하시겠습니까? (Y/N) : ");
				fflush(stdin);
				ch = getchar();
				
				if(ch == 'Y' || ch == 'y')
				{
					strcpy(word[i], "\0");
					printf("@삭제되었습니다.\n\n");
					for(j=i; j<(*cnt)-1; j++)
					{
						strcpy(word[j], word[j+1]);
					}

					(*cnt)--;					
					break;
				}
				else
				{
					printf("# 삭제가 취소되었습니다\n\n");
					break;
				}
			}
			else if(i==(*cnt)-1)
			{
				printf("@ %s 문자열은 존재하지 않습니다.\n\n", tmp);
			}			
		}
	}
	
	printf("\n\n# 아무키나 누르면 주메뉴로 돌아갑니다.");
	getch();

	return;
}

void end()	//종료
{
	system("cls");
	gotoxy(35, 13);
	printf("종료합니다...\n");

	return;
}

void gotoxy(int x, int y) //커서이동
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}