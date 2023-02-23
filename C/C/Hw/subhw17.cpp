/* ��¥ : 2012�� 2�� 9��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������� ����� ���� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)
void output(int);
void withdraw(int *);
void deposit(int *);
char menu();
int main()
{
	int money = 0;
	char choice;

	while(1)
	{
		output(money);
		choice = menu();

		if(choice == 'q')
		{
			break;
		}
		else if(choice == 'i')
		{
			deposit(&money);
		}
		else if(choice == 'o')
		{
			withdraw(&money);
		}		
	}

	return 0;
}

void output(int money)
{
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", money);
	return;
}

void withdraw (int *money)
{
	int out_m, res;

	while(1)
	{	
		printf("# ��ݾ��� �Է��ϼ��� : ");
		fflush(stdin);
		res = scanf("%d", &out_m);
		
		while(res == 0 || out_m<0)
		{
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
			fflush(stdin);
			res = scanf("%d", &out_m);
		}

		if(*money >= out_m)
		{
			*money -= out_m;
			break;
		}
		else
		{
			printf("* �ܾ��� �����մϴ�.\n");
			break;
		}
	}	

	return;
}

void deposit(int *money)
{	
	int in_m, res;

	while(1)
	{	
		printf("# �Աݾ��� �Է��ϼ��� : ");
		fflush(stdin);
		res = scanf("%d", &in_m);
		
		while(res == 0 || in_m<0)
		{
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
			fflush(stdin);
			res = scanf("%d", &in_m);
		}

		if(res == 1)
		{
			break;
		}
	}
	
	*money += in_m;

	return;
}

char menu()
{
	char ch;	
	
	while(1)
	{
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		fflush(stdin);
		scanf("%c", &ch);
		
		if(ch == 'i' || ch == 'o' || ch == 'q')
		{
			break;
		}
		
		printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
		
	}
	
	return ch;
}