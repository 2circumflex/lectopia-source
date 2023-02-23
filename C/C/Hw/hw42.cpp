/* ��¥ : 2012�� 2�� 23��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� ���α׷�(struct �迭 �̿�) */
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
void myOutput(struct DIC *p, int cnt)	//����ϱ�
{		
	int i,j, num=1;
	struct DIC tmp;

	system("cls");
	if(cnt==0)
	{
		printf("����� �ܾ �����ϴ�. ���� �ܾ �Է��ϼ���\n");		
		printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
		getch();
	}
	else
	{
		for(i=0; i<cnt-1; i++)	//������������
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
			if(i==10)	{ getch(); }	//10���������ֱ�			
			if(strlen(p[i].mean)>50)
			{
				printf("%2d.%20s(%2d): %.50s~", num++, p[i].word, p[i].len, p[i].mean);				
			}
			else
			{
				printf("%2d.%20s(%2d): %s\n", num++, p[i].word, p[i].len, p[i].mean);
			}			
		}
		printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
		getch();
	}

		
}
void mySearch(struct DIC *p, int cnt)	//�˻��ϱ�
{
	char wtmp[20];
	int i;
	system("cls");

	if(cnt==0)	//�ܾ 0���϶�
	{
		printf("�Էµ� �ܾ �����ϴ�.\n");
		printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
		getch();
		return;
	}

	while(1)
	{		
		fflush(stdin);
		printf("# �˻��� �ܾ �Է��Ͻÿ� : ");
		scanf("%s", wtmp);

		if(strcmp(wtmp, "end")==0)
		{
			printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
			getch();
			return;
		}
		else
		{
			for(i=0; i<cnt; i++)
			{
				if(strcmp(p[i].word, wtmp)==0)
				{					
					printf("# �ܾ��� �� : %s\n", p[i].mean);
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
int myDelete(struct DIC *p, int cnt)	//�����ϱ�
{
	char wtmp[20];
	int i,j;
	system("cls");

	while(1)
	{
		if(cnt==0)	//�ܾ 0���϶�
		{
			printf("�Էµ� �ܾ �����ϴ�.\n");
			printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
			getch();
			return cnt;
		}

		fflush(stdin);
		printf("# ������ �ܾ �Է��Ͻÿ� : ");		
		scanf("%s", wtmp);		

		if(strcmp(wtmp, "end")==0)
		{
			printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
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
					printf("�����߽��ϴ�.\n");
					cnt--;
					break;
				}
				else if(i==(cnt-1))
				{					
					printf("���� �ܾ� �Դϴ�.\n");
					break;
				}
			}
			printf("\n");
		}
	}
}

int myInput(struct DIC *p, int cnt)	//�Է��ϱ�
{
	char wtmp[20] ,mtmp[80];	
	system("cls");

	if(cnt==20)
	{
		printf("�ܾ� ���尳���� �� ã���~\n");
		printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
		getch();
		return cnt;
	}
	
	while(1)
	{
		fflush(stdin);
		printf("#�ܾ �Է��Ͻÿ� : ");
		scanf("%19s", wtmp);

		if(strcmp(wtmp, "end")==0)
		{
			printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
			getch();
			return cnt;
		}
		else
		{		
			fflush(stdin);
			printf("#���� �Է��Ͻÿ� : ");
			gets(mtmp);			

			if(strcmp(mtmp, "end")==0)
			{
				printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
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
					printf("�ܾ� ���尳���� �� ã���~\n");
					printf("�ƹ�Ű�������� �޴��� ���ư��ϴ�.");
					getch();
					return cnt;
				}				
				printf("\n");
			}
		}		
	}
}

int menu()	//�޴�
{
	int num;
	system("cls");
	printf("���� ���α׷�\n");
	printf("1. �Է��ϱ�\n");
	printf("2. ����ϱ�\n");
	printf("3. �˻��ϱ�\n");
	printf("4. �����ϱ�\n");

	while(1)
	{
		printf("�޴��� ��ȣ�� �Է��Ͻÿ� : ");
		fflush(stdin);
		scanf("%d", &num);

		if(num>0 && num<5)
		{
			return num;
		}
		else
		{
			printf("�߸��Է��ϼ̽��ϴ�.\n");
		
		}
	}
}