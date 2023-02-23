/* 날짜 : 2012년 2월 23일   
   작성자 : 이로운   
   프로그램의 기능 : 사전 프로그램(struct 배열 이용) */
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable:4996)
struct DIC
{
	char word[20];
	char mean[80];
	int len;
};
int menu();
int myInput(struct DIC *p, int);
void myOutput(struct DIC *, int);
void mySearch(struct DIC *, int);
int myDelete(struct DIC *, int);
int main()
{
	struct DIC ary[20];	
	int res, cnt=0;	

	while(1)
	{
		res = menu();
		switch(res)
		{
			case 1: cnt=myInput(ary, cnt); break;
			case 2: myOutput(ary, cnt); break;
			case 3: mySearch(ary, cnt); break;
			case 4: cnt=myDelete(ary, cnt); break;
		}
	}

	return 0;
}
void myOutput(struct DIC *p, int cnt)	//출력하기
{		
	int i,j, num=1;
	struct DIC tmp;

	system("cls");
	if(cnt==0)
	{
		printf("출력할 단어가 없습니다. 먼저 단어를 입력하세요\n");		
		printf("아무키나누르면 메뉴로 돌아갑니다.");
		getch();
	}
	else
	{
		for(i=0; i<cnt-1; i++)	//오름차순정렬
		{
			for(j=i+1; j<cnt; j++)
			{
				if(strcmp(p[i].word, p[j].word)>0)
				{					
					tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
		}

		for(i=0; i<cnt; i++)
		{	
			if(i==10)	{ getch(); }	//10개씩보여주기			
			if(strlen(p[i].mean)>50)
			{
				printf("%2d.%20s(%2d): %.50s~", num++, p[i].word, p[i].len, p[i].mean);				
			}
			else
			{
				printf("%2d.%20s(%2d): %s\n", num++, p[i].word, p[i].len, p[i].mean);
			}			
		}
		printf("아무키나누르면 메뉴로 돌아갑니다.");
		getch();
	}

		
}
void mySearch(struct DIC *p, int cnt)	//검색하기
{
	char wtmp[20];
	int i;
	system("cls");

	if(cnt==0)	//단어가 0개일때
	{
		printf("입력된 단어가 없습니다.\n");
		printf("아무키나누르면 메뉴로 돌아갑니다.");
		getch();
		return;
	}

	while(1)
	{		
		fflush(stdin);
		printf("# 검색할 단어를 입력하시오 : ");
		scanf("%s", wtmp);

		if(strcmp(wtmp, "end")==0)
		{
			printf("아무키나누르면 메뉴로 돌아갑니다.");
			getch();
			return;
		}
		else
		{
			for(i=0; i<cnt; i++)
			{
				if(strcmp(p[i].word, wtmp)==0)
				{					
					printf("# 단어의 뜻 : %s\n", p[i].mean);
					break;
				}
				else if(i==(cnt-1))
				{
					printf("# Not Found!!!\n");
				}
			}
			printf("\n");
		}		
	}
}
int myDelete(struct DIC *p, int cnt)	//삭제하기
{
	char wtmp[20];
	int i,j;
	system("cls");

	while(1)
	{
		if(cnt==0)	//단어가 0개일때
		{
			printf("입력된 단어가 없습니다.\n");
			printf("아무키나누르면 메뉴로 돌아갑니다.");
			getch();
			return cnt;
		}

		fflush(stdin);
		printf("# 삭제할 단어를 입력하시오 : ");		
		scanf("%s", wtmp);		

		if(strcmp(wtmp, "end")==0)
		{
			printf("아무키나누르면 메뉴로 돌아갑니다.");
			getch();
			return cnt;
		}
		else
		{
			for(i=0; i<cnt; i++)
			{
				if(strcmp(p[i].word, wtmp)==0)
				{
					for(j=i; j<cnt-1; j++)
					{						
						p[j]=p[j+1];
					}
					printf("삭제했습니다.\n");
					cnt--;
					break;
				}
				else if(i==(cnt-1))
				{					
					printf("없는 단어 입니다.\n");
					break;
				}
			}
			printf("\n");
		}
	}
}

int myInput(struct DIC *p, int cnt)	//입력하기
{
	char wtmp[20] ,mtmp[80];	
	system("cls");

	if(cnt==20)
	{
		printf("단어 저장개수가 꽉 찾어요~\n");
		printf("아무키나누르면 메뉴로 돌아갑니다.");
		getch();
		return cnt;
	}
	
	while(1)
	{
		fflush(stdin);
		printf("#단어를 입력하시오 : ");
		scanf("%19s", wtmp);

		if(strcmp(wtmp, "end")==0)
		{
			printf("아무키나누르면 메뉴로 돌아갑니다.");
			getch();
			return cnt;
		}
		else
		{		
			fflush(stdin);
			printf("#뜻을 입력하시오 : ");
			gets(mtmp);			

			if(strcmp(mtmp, "end")==0)
			{
				printf("아무키나누르면 메뉴로 돌아갑니다.");
				getch();
				return cnt;
			}
			else
			{
				strcpy(p[cnt].word, wtmp);
				strcpy(p[cnt].mean, mtmp);
				p[cnt].len = strlen(wtmp);
				cnt++;
				if(cnt==20)
				{
					printf("단어 저장개수가 꽉 찾어요~\n");
					printf("아무키나누르면 메뉴로 돌아갑니다.");
					getch();
					return cnt;
				}				
				printf("\n");
			}
		}		
	}
}

int menu()	//메뉴
{
	int num;
	system("cls");
	printf("사전 프로그램\n");
	printf("1. 입력하기\n");
	printf("2. 출력하기\n");
	printf("3. 검색하기\n");
	printf("4. 삭제하기\n");

	while(1)
	{
		printf("메뉴를 번호를 입력하시오 : ");
		fflush(stdin);
		scanf("%d", &num);

		if(num>0 && num<5)
		{
			return num;
		}
		else
		{
			printf("잘못입력하셨습니다.\n");
		
		}
	}
}