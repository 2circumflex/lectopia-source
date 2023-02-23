/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 성적관리프로그램 */
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#pragma warning (disable : 4996)
int menu();
void input(int, char ***, int ***);
void modify(int, char ***, int ***);
void output(int, char ***, int ***);
void end(int, char **, int**);
void gotoxy(int x, int y); 
int main()
{
	int su, chk, i, res, len=11, sub=3, **subj, yline=7;
	char **name;

	gotoxy(30, yline++);
	printf("────────────");
	gotoxy(33, yline++);
	printf("*성적관리프로그램*\n\n");
	gotoxy(30, yline++);
	printf("────────────");
	gotoxy(30, yline++);
	printf("학생수를 입력하세요 : ");
	while(1)
	{
		fflush(stdin);
		chk = scanf("%d", &su);
		if(chk==1 && su >=1)
		{
			break;
		}
		else
		{
			gotoxy(30, yline++);
			printf("-_-^ 다시입력하시오 : ");
		}
		
	}
	//동적메모리할당
	name = (char**)malloc(su*sizeof(char*));
	subj = (int**)malloc(su*sizeof(int*));

	for(i=0; i<su; i++)
	{
		name[i] = (char*)malloc(len*sizeof(char));
		subj[i] = (int*)malloc(4*sizeof(int));
	}	
	
	strcpy(name[0], "empty");
	
	while(1)
	{
		res = menu();
		
		switch(res)
		{
		case 1 : input(su, &name, &subj); break;
		case 2 : modify(su, &name, &subj); break;
		case 3 : output(su, &name, &subj); break;
		case 4 : end(su, name, subj); break;
		}
		if(res==4) break;
	}
	return 0;
}

void end(int su, char **name, int **subj)	//종료. 동적메모리free
{
	int i;
	
	for(i=0; i<su; i++)
	{
		free(name[i]);
		free(subj[i]);
	}
	
	free(name);
	free(subj);
	
	return;
}

int menu()	//주메뉴
{
	int num, yline=5;
	system("cls");
	gotoxy(30, yline++);
	printf("────────────");
	gotoxy(34, yline++);
	printf("1. 개인성적입력\n");
	gotoxy(34, yline++);
	printf("2. 개인성적수정\n");
	gotoxy(34, yline++);
	printf("3. 전체성적출력\n");
	gotoxy(34, yline++);
	printf("4. 종        료\n");
	gotoxy(30, yline++);
	printf("────────────");
	
	while(1)
	{
		gotoxy(30, yline++);
		printf("메뉴번호를 입력하시오 : ");
		fflush(stdin);
		scanf("%d", &num);
		if(num==1||num==2||num==3||num==4)
		{
			break;			
		}
		gotoxy(30, yline++);
		printf("잘못입력했습니다~!!\n");
	}
	return num;
}

void input(int su, char ***name, int ***subj)	//성적입력
{
	int i, nn;
	
	system("cls");
	for(i=0; i<su; i++)
	{
		printf("%2d번 학생 이름 : ", i+1);
		scanf("%10s", (*name)[i]);			
		
		printf("국어 : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[i][0]);
			if(nn==1 && (*subj)[i][0]>=0 && (*subj)[i][0]<=100)
			{
				break;
			}
			printf("잘못입력했습니다. 다시입력(1~100) : ");			
		}
		printf("영어 : ");
		while(1)
		{
			fflush(stdin);			
			nn = scanf("%d", &(*subj)[i][1]);
			if(nn==1 && (*subj)[i][1]>=0 && (*subj)[i][1]<=100)
			{
				break;
			}
			printf("잘못입력했습니다. 다시입력(1~100) : ");			
		}
		printf("수학 : ");
		while(1)
		{
			fflush(stdin);			
			nn = scanf("%d", &(*subj)[i][2]);
			if(nn==1 && (*subj)[i][2]>=0 && (*subj)[i][2]<=100)
			{
				break;
			}
			printf("잘못입력했습니다. 다시입력(1~100) : ");			
		}
		(*subj)[i][3] = (*subj)[i][0] + (*subj)[i][1] + (*subj)[i][2];		
	}	
	printf("모두 입력하였습니다. 아무키나 누르면 메뉴로 돌아갑니다\n");
	getch();
	
	return;
}

void modify(int su, char ***name, int ***subj)	//수정하기
{	
	int i,j,k, n, nn, tmp;
	char sname[11];
	char *tn;

	system("cls");
	while(1)
	{
		if(strcmp((*name)[0], "empty")==0)
		{
			printf("입력된 데이터가 없습니다. 개인성적입력을 해주세요.\n");
			getch();
			break;
		}
		for(i=0; i<su; i++)	//sort
		{
			for(j=i+1; j<su; j++)
			{
				if(strcmp((*name)[i], (*name)[j]) >0)
				{
					for(k=0; k<4; k++)
					{
						tmp = (*subj)[i][k];
						(*subj)[i][k] = (*subj)[j][k];
						(*subj)[j][k] = tmp;
					}
					tn = (*name)[i];
					(*name)[i] = (*name)[j];
					(*name)[j] = tn;
				}
			}		
		}	

		for(i=1; i<=su; i++)	//성명 출력
		{	
			printf("[%10s]\t", (*name)[i-1]);
			if(i%5==0)
			{
				printf("\n");
			}			
		}

		printf("\n성적 수정할 학생 이름을 입력하시오(종료:end입력) : ");			
		scanf("%10s", sname);

		if(strcmp("end", sname) == 0)
		{
			break;
		}
		
		for(i=0; i<su; i++)
		{
			nn = strcmp(sname, (*name)[i]);
			if(nn==0)
			{
				printf("\n   이 름 \t국어\t영어\t수학\t총점\t평균\n");
				printf("%10s\t%3d\t%3d\t%3d\t%3d\t%5.2lf\n", (*name)[i], (*subj)[i][0], (*subj)[i][1], (*subj)[i][2], (*subj)[i][3], (double)(*subj)[i][3]/3);
				printf("------------------------------------------------------\n");
				n = i;	////////
				break;
			}			
		}

		printf("국어 : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[n][0]);
			if(nn==1 && (*subj)[n][0]>=0 && (*subj)[n][0]<=100)
			{
				break;
			}
			printf("잘못입력했습니다. 다시입력(1~100) : ");			
		}
		printf("영어 : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[n][1]);
			if(nn==1 && (*subj)[n][1]>=0 && (*subj)[n][1]<=100)
			{
				break;
			}
			printf("잘못입력했습니다. 다시입력(1~100) : ");			
		}
		printf("수학 : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[n][2]);
			if(nn==1 && (*subj)[n][2]>=0 && (*subj)[n][2]<=100)
			{
				break;
			}
			printf("잘못입력했습니다. 다시입력(1~100) : ");			
		}		

		(*subj)[n][3] = (*subj)[n][0] + (*subj)[n][1] + (*subj)[n][2];	//총점계산	

		printf("수정을 완료하였습니다\n\n");	
	}
	return;
}

void output(int su, char ***name, int ***subj)	//출력하기
{
	int i,j,k, tmp, cnt;
	char tname[11];
	char *tn;
	tn=tname;
	system("cls");

	if(strcmp((*name)[0], "empty")==0)
	{
		printf("입력된 데이터가 없습니다. 개인성적입력을 해주세요.\n");
		getch();
		return;
	}

	printf("석차\t    성명   \t국어\t영어\t수학\t총점\t평균\n");
	printf("-------------------------------------------------------------\n");

	for(i=0; i<su; i++)	//sort
	{
		for(j=i+1; j<su; j++)
		{
			if((*subj)[i][3]<(*subj)[j][3])
			{
				for(k=0; k<4; k++)
				{
					tmp = (*subj)[i][k];
					(*subj)[i][k] = (*subj)[j][k];
					(*subj)[j][k] = tmp;
				}
				tn = (*name)[i];
				(*name)[i] = (*name)[j];
				(*name)[j] = tn;
			}
		}		
	}
		
	for(i=1; i<=su; i++)	//석차
	{
		if(i>=2 && (*subj)[i-1][3]==(*subj)[i-2][3])
		{
			printf("%3d\t", i-cnt);
			cnt++;
		}
		else
		{
			printf("%3d\t", i);	
			cnt=1;
		}
		

		printf("%10s",(*name)[i-1]);	//성명
		
		for(j=0; j<4; j++)	//국 영 수 총점
		{
			printf("\t%3d", (*subj)[i-1][j]);	
		}

		printf("\t%5.2lf\n", (double)(*subj)[i-1][3]/3);	//평균

		if(i%15==0)
		{
			getch();
		}
	}	
	
	printf("\n아무키나 누르면 메뉴로 돌아갑니다.");
	getch();
	return;
}

void gotoxy(int x, int y) //커서이동
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 