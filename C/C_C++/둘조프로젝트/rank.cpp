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
	//�׽�Ʈ!!!!!!!!!!!!!
	ranking("gg", 1, "hangranking.txt", 5, 2);
	ranking("�Կ���", 33, "tajaranking.txt", 40, 2);
	ranking("�̷ο�",  55, "pushranking.txt", 5, 13);
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

	if(fp==NULL)  //������ ������ 
	{
		fp = fopen(str, "wt");   //���⸸
		fprintf(fp, "%s %d\n", user, score);     //�޾ƿ°� ����
		strcpy(rk[0].name, user);			//������ �����ϱ�. 0����
		rk[0].score = score;
		rCnt++;

		fclose(fp);
	}
	else
	{
		fscanf(fp, "%s %d", tmp.name, &(tmp.score));   //���Ͽ� ������ ������ 
		low_score = tmp.score;  
		
		rewind(fp);
		//����ü�迭�� �о����
		while(!feof(fp))
		{
			fscanf(fp, "%s %d\n", tmp.name, &(tmp.score));
			strcpy(rk[rCnt].name, tmp.name);
			rk[rCnt].score = tmp.score;
			if(low_score > tmp.score)
			{
				low_score = tmp.score;
				room = rCnt;  //���ȣ���
			}
			rCnt++;
		}
		fclose(fp);

		if(rCnt == 8)
		{
			//���������������� ũ�� 
			if(score > low_score)  //�Է¹��� ������ ���������� Ŭ��
			{
				strcpy(rk[room].name, user);  
				rk[room].score = score;	
			}			
		}
		else  //rCnt�� 8�� �ƴҶ�
		{
			rk[rCnt].score = score;
			strcpy(rk[rCnt].name, user);
			rCnt++;
		}

		fp = fopen(str, "wt");

		//��Ʈ
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
		
		//����ü �迭�� �̸�, ������ ���Ͽ� ����
		for(i=0; i<rCnt; i++)
		{
			fprintf(fp, "%s %d\n", rk[i].name, rk[i].score);
		}
		fclose(fp);
	}
	
	//��ŷ
	gotoxy(x, y++);	
	printf("������������������������������");
	gotoxy(x, y++);
	printf("������        �̸�     ���� ��");
	for(i=1; i<=rCnt; i++)
	{
		gotoxy(x, y++);			//Ŀ����ġ
		
		if(i>=2 && rk[i-2].score == rk[i-1].score)
		{
			printf("��%2d ", i-cnt);
		}
		else
		{
			printf("��%2d ", i);
			cnt=0;
		}
		printf("%18s %4d��", rk[i-1].name, rk[i-1].score);
		cnt++;
	}

	//8�� ��á���� ���� ����ֱ�
	for(i=rCnt; i<8; i++)
	{
		gotoxy(x, y++);
		printf("��                          ��");
	}

	//�ؿ�
	gotoxy(x, y);
	printf("������������������������������");
}

void gotoxy(int x, int y) 
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}