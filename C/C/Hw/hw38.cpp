/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �޴����α׷� */
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

	row = sizeof(word_ary) / sizeof(word_ary[4]);	//���

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

char menu()	//�ָ޴�ȭ��
{
	int line=4;
	char m_num;

	system("cls");
	gotoxy(30, line+=2);
	printf("1. �Է��ϱ�");
	gotoxy(30, line+=2);
	printf("2. ����ϱ�");
	gotoxy(30, line+=2);
	printf("3. �˻��ϱ�");
	gotoxy(30, line+=2);
	printf("4. �����ϱ�");
	gotoxy(30, line+=2);
	printf("5. ��    ��");
	gotoxy(30, line+=2);
	printf("#�޴��� �����ϼ��� : ");	
	m_num = getch();
	
	return m_num;
}

void input(int * cnt, char (*word)[20], int row)	//1�� �Է��ϱ�
{
	int i;
	char tmp[20];
	system("cls");

	for(i=(*cnt); i<row; i++)
	{
		fflush(stdin);
		printf("# ���� �ܾ �Է��ϼ��� : ");
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
		printf("20�� �� ã���ϴ�!\n");
	}
	
	printf("\n\n# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
	getch();

	return;
}

void output(char (*word)[20], int cnt)	//2�� ����ϱ�
{
	int i;
	system("cls");
	if(cnt == 0)
	{
		printf("����� �ܾ �����ϴ�\n");
		printf("\n\n# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
		getch();
	}
	else
	{
		for(i=0; i<cnt; i++)
		{
			printf("�ܾ� %2d : %s\n", i+1, word[i]);

			if(i%10 == 9) { getch(); }			
		}				
		printf("\n\n# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
		getch();
	}

	return;
}

void search(char (*word)[20], int cnt)	//3�� �˻��ϱ�
{
	char tmp[20];
	int i, res=0;
	system("cls");
	while(1)
	{
		printf("# ã�� �ܾ �Է��ϼ��� : ");
		scanf("%s", tmp);

		if(strcmp("end", tmp) == 0)	//endġ�� ����
		{
			printf("\n\n# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
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
					printf("@ %s ���ڿ��� %2d��° ���ڿ��Դϴ�.\n\n", tmp, i+1);
					break;
				}
			}
			if(res != 0)
			{
				printf("@ %s ���ڿ��� �������� �ʽ��ϴ�.\n\n", tmp);
			}
		}		
	}

	return;
}

void mydelete(char (*word)[20], int *cnt)	//4�� �����ϱ�
{
	char tmp[20], ch;
	int i, j;
	system("cls");
	while(1)
	{
		printf("# ������ �ܾ �Է��ϼ��� : ");
		scanf("%s", tmp);

		if(strcmp(tmp, "end") == 0)	//endġ�� ����
		{
			break;
		}

		for(i=0; i<(*cnt); i++)
		{
			if(strcmp(tmp, word[i]) == 0)
			{				
				printf("# ������ ���� �Ͻðڽ��ϱ�? (Y/N) : ");
				fflush(stdin);
				ch = getchar();
				
				if(ch == 'Y' || ch == 'y')
				{
					strcpy(word[i], "\0");
					printf("@�����Ǿ����ϴ�.\n\n");
					for(j=i; j<(*cnt)-1; j++)
					{
						strcpy(word[j], word[j+1]);
					}

					(*cnt)--;					
					break;
				}
				else
				{
					printf("# ������ ��ҵǾ����ϴ�\n\n");
					break;
				}
			}
			else if(i==(*cnt)-1)
			{
				printf("@ %s ���ڿ��� �������� �ʽ��ϴ�.\n\n", tmp);
			}			
		}
	}
	
	printf("\n\n# �ƹ�Ű�� ������ �ָ޴��� ���ư��ϴ�.");
	getch();

	return;
}

void end()	//����
{
	system("cls");
	gotoxy(35, 13);
	printf("�����մϴ�...\n");

	return;
}

void gotoxy(int x, int y) //Ŀ���̵�
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}