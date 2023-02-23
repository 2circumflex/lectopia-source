#include <stdio.h>
#pragma warning (disable:4996)
void in_money(int*);
void out_money(int*);
void balance(int);
char menu();
int main()
{	
	char mn;
	int money=0;

	while(1)
	{
		mn = menu();

		if(mn=='i')
		{
			in_money(&money);
			balance(money);
		}
		else if(mn=='o')
		{
			out_money(&money);
			balance(money);
		}
		else if(mn=='q')
		{
			printf("\n");
			break;
		}
	}

	return 0;
}

char menu()
{
	char mn;

	while(1)
	{
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		fflush(stdin);
		scanf("%c", &mn);

		if(mn=='i' || mn=='o' || mn=='q')
		{
			return mn;
		}
		else
		{
			printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
			return 'e';
		}
	}
}

void in_money(int * m)
{
	int money, ch;

	printf("# �Աݾ��� �Է��ϼ��� : ");
	while(1)
	{
		fflush(stdin);
		ch = scanf("%d", &money);

		if(money>0 && ch==1)
		{
			*m += money;
			return;
		}
		else
		{			
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
		}
	}
}

void out_money(int *m)
{
	int money, ch;

	printf("# ��ݾ��� �Է��ϼ��� : ");
	while(1)
	{
		fflush(stdin);
		ch = scanf("%d", &money);

		if(money>0 && money<=*m && ch==1)
		{
			*m -= money;
			return;
		}
		else if(money<0 || ch!=1)
		{
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
		}
		else if(money>*m)
		{
			printf("* �ܾ��� �����մϴ�.\n");
			return;
		}
	}
}

void balance(int m)
{
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", m);
}