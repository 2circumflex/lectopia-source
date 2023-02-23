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
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		fflush(stdin);
		scanf("%c", &mn);

		if(mn=='i' || mn=='o' || mn=='q')
		{
			return mn;
		}
		else
		{
			printf("* 잘못 입력하셨습니다.\n\n");
			return 'e';
		}
	}
}

void in_money(int * m)
{
	int money, ch;

	printf("# 입금액을 입력하세요 : ");
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
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
		}
	}
}

void out_money(int *m)
{
	int money, ch;

	printf("# 출금액을 입력하세요 : ");
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
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
		}
		else if(money>*m)
		{
			printf("* 잔액이 부족합니다.\n");
			return;
		}
	}
}

void balance(int m)
{
	printf("* 현재 잔액은 %d원 입니다.\n\n", m);
}