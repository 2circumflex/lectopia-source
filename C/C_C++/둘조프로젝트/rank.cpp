#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct _rank
{
	char name[20];
	int score;
}rank;

void gotoxy(int x, int y); 
void ranking(char *user, int score, char *str, int x, int y);

int main()
{
	//테스트!!!!!!!!!!!!!
	ranking("gg", 1, "hangranking.txt", 5, 2);
	ranking("함영식", 33, "tajaranking.txt", 40, 2);
	ranking("이로운",  55, "pushranking.txt", 5, 13);
}

void ranking(char *user, int score, char *str, int x, int y)
{
	int i, j;
	int cnt;
	int rCnt = 0;
	int low_score, room;
	rank tmp;
	rank rk[8];
	FILE * fp;
	fp = fopen(str, "rt");

	if(fp==NULL)  //파일이 없을때 
	{
		fp = fopen(str, "wt");   //쓰기만
		fprintf(fp, "%s %d\n", user, score);     //받아온걸 쓰고
		strcpy(rk[0].name, user);			//파일이 없으니깐. 0번방
		rk[0].score = score;
		rCnt++;

		fclose(fp);
	}
	else
	{
		fscanf(fp, "%s %d", tmp.name, &(tmp.score));   //파일에 내용이 있을때 
		low_score = tmp.score;  
		
		rewind(fp);
		//구조체배열에 읽어오기
		while(!feof(fp))
		{
			fscanf(fp, "%s %d\n", tmp.name, &(tmp.score));
			strcpy(rk[rCnt].name, tmp.name);
			rk[rCnt].score = tmp.score;
			if(low_score > tmp.score)
			{
				low_score = tmp.score;
				room = rCnt;  //방번호기억
			}
			rCnt++;
		}
		fclose(fp);

		if(rCnt == 8)
		{
			//최저스테이지보다 크면 
			if(score > low_score)  //입력받은 점수가 최저값보다 클때
			{
				strcpy(rk[room].name, user);  
				rk[room].score = score;	
			}			
		}
		else  //rCnt가 8이 아닐때
		{
			rk[rCnt].score = score;
			strcpy(rk[rCnt].name, user);
			rCnt++;
		}

		fp = fopen(str, "wt");

		//소트
		for(i=0; i<rCnt-1; i++)
		{
			for(j=i+1; j<rCnt; j++)
			{
				if(rk[i].score <rk[j].score)
				{
					tmp.score = rk[i].score;
					rk[i].score = rk[j].score;
					rk[j].score = tmp.score;

					strcpy(tmp.name, rk[i].name);
					strcpy(rk[i].name, rk[j].name);
					strcpy(rk[j].name, tmp.name);
				}
			}
		}
		
		//구조체 배열에 이름, 점수를 파일에 저장
		for(i=0; i<rCnt; i++)
		{
			fprintf(fp, "%s %d\n", rk[i].name, rk[i].score);
		}
		fclose(fp);
	}
	
	//랭킹
	gotoxy(x, y++);	
	printf("┌─────────────┐");
	gotoxy(x, y++);
	printf("│순위        이름     점수 │");
	for(i=1; i<=rCnt; i++)
	{
		gotoxy(x, y++);			//커서위치
		
		if(i>=2 && rk[i-2].score == rk[i-1].score)
		{
			printf("│%2d ", i-cnt);
		}
		else
		{
			printf("│%2d ", i);
			cnt=0;
		}
		printf("%18s %4d│", rk[i-1].name, rk[i-1].score);
		cnt++;
	}

	//8명 안찼을때 옆에 찍어주기
	for(i=rCnt; i<8; i++)
	{
		gotoxy(x, y++);
		printf("│                          │");
	}

	//밑에
	gotoxy(x, y);
	printf("└─────────────┘");
}

void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}