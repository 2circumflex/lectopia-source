/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �����������α׷� */
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
	printf("������������������������");
	gotoxy(33, yline++);
	printf("*�����������α׷�*\n\n");
	gotoxy(30, yline++);
	printf("������������������������");
	gotoxy(30, yline++);
	printf("�л����� �Է��ϼ��� : ");
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
			printf("-_-^ �ٽ��Է��Ͻÿ� : ");
		}
		
	}
	//�����޸��Ҵ�
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

void end(int su, char **name, int **subj)	//����. �����޸�free
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

int menu()	//�ָ޴�
{
	int num, yline=5;
	system("cls");
	gotoxy(30, yline++);
	printf("������������������������");
	gotoxy(34, yline++);
	printf("1. ���μ����Է�\n");
	gotoxy(34, yline++);
	printf("2. ���μ�������\n");
	gotoxy(34, yline++);
	printf("3. ��ü�������\n");
	gotoxy(34, yline++);
	printf("4. ��        ��\n");
	gotoxy(30, yline++);
	printf("������������������������");
	
	while(1)
	{
		gotoxy(30, yline++);
		printf("�޴���ȣ�� �Է��Ͻÿ� : ");
		fflush(stdin);
		scanf("%d", &num);
		if(num==1||num==2||num==3||num==4)
		{
			break;			
		}
		gotoxy(30, yline++);
		printf("�߸��Է��߽��ϴ�~!!\n");
	}
	return num;
}

void input(int su, char ***name, int ***subj)	//�����Է�
{
	int i, nn;
	
	system("cls");
	for(i=0; i<su; i++)
	{
		printf("%2d�� �л� �̸� : ", i+1);
		scanf("%10s", (*name)[i]);			
		
		printf("���� : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[i][0]);
			if(nn==1 && (*subj)[i][0]>=0 && (*subj)[i][0]<=100)
			{
				break;
			}
			printf("�߸��Է��߽��ϴ�. �ٽ��Է�(1~100) : ");			
		}
		printf("���� : ");
		while(1)
		{
			fflush(stdin);			
			nn = scanf("%d", &(*subj)[i][1]);
			if(nn==1 && (*subj)[i][1]>=0 && (*subj)[i][1]<=100)
			{
				break;
			}
			printf("�߸��Է��߽��ϴ�. �ٽ��Է�(1~100) : ");			
		}
		printf("���� : ");
		while(1)
		{
			fflush(stdin);			
			nn = scanf("%d", &(*subj)[i][2]);
			if(nn==1 && (*subj)[i][2]>=0 && (*subj)[i][2]<=100)
			{
				break;
			}
			printf("�߸��Է��߽��ϴ�. �ٽ��Է�(1~100) : ");			
		}
		(*subj)[i][3] = (*subj)[i][0] + (*subj)[i][1] + (*subj)[i][2];		
	}	
	printf("��� �Է��Ͽ����ϴ�. �ƹ�Ű�� ������ �޴��� ���ư��ϴ�\n");
	getch();
	
	return;
}

void modify(int su, char ***name, int ***subj)	//�����ϱ�
{	
	int i,j,k, n, nn, tmp;
	char sname[11];
	char *tn;

	system("cls");
	while(1)
	{
		if(strcmp((*name)[0], "empty")==0)
		{
			printf("�Էµ� �����Ͱ� �����ϴ�. ���μ����Է��� ���ּ���.\n");
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

		for(i=1; i<=su; i++)	//���� ���
		{	
			printf("[%10s]\t", (*name)[i-1]);
			if(i%5==0)
			{
				printf("\n");
			}			
		}

		printf("\n���� ������ �л� �̸��� �Է��Ͻÿ�(����:end�Է�) : ");			
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
				printf("\n   �� �� \t����\t����\t����\t����\t���\n");
				printf("%10s\t%3d\t%3d\t%3d\t%3d\t%5.2lf\n", (*name)[i], (*subj)[i][0], (*subj)[i][1], (*subj)[i][2], (*subj)[i][3], (double)(*subj)[i][3]/3);
				printf("------------------------------------------------------\n");
				n = i;	////////
				break;
			}			
		}

		printf("���� : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[n][0]);
			if(nn==1 && (*subj)[n][0]>=0 && (*subj)[n][0]<=100)
			{
				break;
			}
			printf("�߸��Է��߽��ϴ�. �ٽ��Է�(1~100) : ");			
		}
		printf("���� : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[n][1]);
			if(nn==1 && (*subj)[n][1]>=0 && (*subj)[n][1]<=100)
			{
				break;
			}
			printf("�߸��Է��߽��ϴ�. �ٽ��Է�(1~100) : ");			
		}
		printf("���� : ");
		while(1)
		{
			fflush(stdin);
			nn = scanf("%d", &(*subj)[n][2]);
			if(nn==1 && (*subj)[n][2]>=0 && (*subj)[n][2]<=100)
			{
				break;
			}
			printf("�߸��Է��߽��ϴ�. �ٽ��Է�(1~100) : ");			
		}		

		(*subj)[n][3] = (*subj)[n][0] + (*subj)[n][1] + (*subj)[n][2];	//�������	

		printf("������ �Ϸ��Ͽ����ϴ�\n\n");	
	}
	return;
}

void output(int su, char ***name, int ***subj)	//����ϱ�
{
	int i,j,k, tmp, cnt;
	char tname[11];
	char *tn;
	tn=tname;
	system("cls");

	if(strcmp((*name)[0], "empty")==0)
	{
		printf("�Էµ� �����Ͱ� �����ϴ�. ���μ����Է��� ���ּ���.\n");
		getch();
		return;
	}

	printf("����\t    ����   \t����\t����\t����\t����\t���\n");
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
		
	for(i=1; i<=su; i++)	//����
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
		

		printf("%10s",(*name)[i-1]);	//����
		
		for(j=0; j<4; j++)	//�� �� �� ����
		{
			printf("\t%3d", (*subj)[i-1][j]);	
		}

		printf("\t%5.2lf\n", (double)(*subj)[i-1][3]/3);	//���

		if(i%15==0)
		{
			getch();
		}
	}	
	
	printf("\n�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.");
	getch();
	return;
}

void gotoxy(int x, int y) //Ŀ���̵�
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 