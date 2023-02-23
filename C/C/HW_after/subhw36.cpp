#pragma warning (disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

void gotoxy(int, int);
int suInput();
void myMalloc(char ***, int ***, int);
void myFree(char **, int **, int);
int menu();

int main()
{
	int su, num, **subj;
	char **name;

	su = suInput();
	myMalloc(&name, &subj, su);	
	
	while(1)
	{
		num = menu();

		switch(num)
		{
			case 1:	break;
			case 2:	break;
			case 3:	break;
			case 4:	myFree(name, subj, su); break;
		}
		
		if(num==4)	break;
	}
	
	return 0;
}

//�޴�
int menu()
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
		fflush(stdin);
		gotoxy(30, yline++);
		printf("�޴���ȣ�� �Է��Ͻÿ� : ");
		scanf("%d", &num);

		if(num>=1 && num<=4)	return num;
		else
		{
			gotoxy(30, yline++);
			printf("�߸��Է��ϼ̽��ϴ�!!");
		}
	}
}

//�����޸� ����
void myFree(char **n, int **s, int su)
{
	int i;

	for(i=0; i<su; i++)
	{
		free(n[i]);
		free(s[i]);
	}
	free(n);	//�л��̸�
	free(s);	//����
}

//�����޸� �Ҵ�
void myMalloc(char ***n, int ***s, int su)
{
	int i;
	
	//�л��̸� �����޸�
	*n = (char**)malloc(su * sizeof(char*));
	//���� �����޸�
	*s = (int**)malloc(4 * sizeof(int *));

	for(i=0; i<su; i++){
		(*n)[i] = (char*)malloc(11 * sizeof(char));
		(*s)[i] = (int*)malloc(4 * sizeof(int));
	}
	strcpy((*n)[0], "empty");
}	

//Ŀ���̵�
void gotoxy(int x, int y)
{ 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

//�л��� �Է�
int suInput()
{
	int su, yLine = 7, chk;

	gotoxy(30, yLine++);
	printf("-------------------");
	gotoxy(30, yLine++);
	printf(" �������� ���α׷�");
	gotoxy(30, yLine++);
	printf("-------------------");
	gotoxy(30, yLine++);
	printf("�л��� �Է� : ");
	while(1)
	{			
		fflush(stdin);
		chk = scanf("%d", &su);

		if(chk == 1 && su > 0)
		{
			return su;
		}
		else
		{
			gotoxy(30, yLine++);
			printf("�ٽ� �Է��Ͻÿ� : ");
		}
	}	
}