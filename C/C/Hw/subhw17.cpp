/* 날짜 : 2012년 2월 9일   
   작성자 : 이로운   
   프로그램의 기능 : 은행계좌 입출금 관리 프로그램 */
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
	printf("* 현재 잔액은 %d원 입니다.\n\n", money);
	return;
}

void withdraw (int *money)
{
	int out_m, res;

	while(1)
	{	
		printf("# 출금액을 입력하세요 : ");
		fflush(stdin);
		res = scanf("%d", &out_m);
		
		while(res == 0 || out_m<0)
		{
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
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
			printf("* 잔액이 부족합니다.\n");
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
		printf("# 입금액을 입력하세요 : ");
		fflush(stdin);
		res = scanf("%d", &in_m);
		
		while(res == 0 || in_m<0)
		{
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
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
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		fflush(stdin);
		scanf("%c", &ch);
		
		if(ch == 'i' || ch == 'o' || ch == 'q')
		{
			break;
		}
		
		printf("* 잘못 입력하셨습니다.\n\n");
		
	}
	
	return ch;
}