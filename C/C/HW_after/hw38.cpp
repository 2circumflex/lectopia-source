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

//����
void m_end()
{
	system("cls");
	gotoxy(30, 12);
	printf("����...");
}

//�Է��ϱ�
void Str_input(char (*str)[20], int * cnt, int row)
{	
	int i;
	char tmp_str[20];

	system("cls");
	for(i=(*cnt); i<row; i++)
	{
		fflush(stdin);
		printf("# ���� �ܾ �Է��ϼ��� : ");		
		scanf("%s", tmp_str);

		if(strcmp(tmp_str, "end") == 0)
		{
			*cnt = i;
			printf("�Է�����");
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

//����ϱ�
void Str_output(char (*str)[20], int cnt)
{
	int i;

	system("cls");
	if(cnt == 0)
	{
		printf("�Էµ� �ܾ �����ϴ�\n");
		getch();
		return;
	}
	
	for(i=1; i<=cnt; i++)
	{
		printf("�ܾ� %d : %s\n", i, str[i-1]);
		if(i%10==0 && i!=cnt)	getch();		
	}
	
	printf("��¿Ϸ�");
	getch();
	
}

//�˻��ϱ�
void Str_search(char (*str)[20], int cnt)
{
	int i, res;
	char tmp_str[20];
	
	system("cls");
	while(1)
	{
		fflush(stdin);
		printf("# ã�� �ܾ �Է��ϼ��� : ");
		scanf("%s", tmp_str);

		if(strcmp(tmp_str, "end") == 0)
		{
			printf("@ �����մϴ�\n");
			getch();
			return;
		}
		else
		{
			printf("@ %s ���ڿ��� ", tmp_str);
		
			for(i=0; i<cnt; i++)
			{
				res = strcmp(str[i], tmp_str);
				if(res==0)
				{
					printf("%d��° ���ڿ��Դϴ�.\n\n", i+1);
					break;
				}				
			}

			if(res!=0)	printf("�������� �ʽ��ϴ�.\n\n");
		}
	}
}

//�����ϱ�
void Str_delete(char (*str)[20], int * cnt)
{
	int i, j, res;
	char tmp_str[20], yn;

	system("cls");
	while(1)
	{
		fflush(stdin);
		printf("# ������ �ܾ �Է��ϼ��� : ");
		scanf("%s", tmp_str);

		if(strcmp(tmp_str, "end")==0)
		{
			printf("@ �����մϴ�\n");
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
					printf("# ������ ���� �Ͻðڽ��ϱ�? (Y/N) : ");
					fflush(stdin);
					yn = getchar();

					if(yn=='y' || yn=='Y')
					{
						strcpy(str[i], "\0");
						for(j=i; j<(*cnt)-1; j++)
						{
							strcpy(str[j], str[j+1]);
						}
						printf("@ �����Ǿ����ϴ�.\n\n");
						(*cnt)--;
						break;
					}
					else
					{
						printf("@ ������ ��ҵǾ����ϴ�.\n\n");
						break;
					}
				}
			}

			if(res!=0)	printf("@ %s ���ڿ��� �������� �ʽ��ϴ�.\n\n", tmp_str);			
		}
	}
}

//Ŀ���̵�
void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

//�޴�
int menu(void)
{	
	int m_num;

	system("cls");
	gotoxy(25, 7);
	printf("1. �Է��ϱ�");
	gotoxy(25, 9);
	printf("2. ����ϱ�");
	gotoxy(25, 11);
	printf("3. �˻��ϱ�");
	gotoxy(25, 13);
	printf("4. �����ϱ�");
	gotoxy(25, 15);
	printf("5. ��    ��");
	gotoxy(18, 17);
	printf("#�޴��� �����ϼ��� : ");

	m_num = getch() - 48;

	return m_num;
}