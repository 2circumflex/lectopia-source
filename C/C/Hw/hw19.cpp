/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 수도요금 계산 프로그램 */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)
void input(int *, int *);
void output(char[], int, double);
int main()
{
	int code, amount;
	double fee;
	char ch[10];
	
	input(&code, &amount);

	switch(code)
	{
		case 1 :fee = 50 * amount; 
				fee = fee + fee * 0.05;
				strcpy(ch, "1(가정용)");
				break;
		case 2 :fee = 45 * amount; 
				fee = fee + fee * 0.05;
				strcpy(ch, "2(상업용)");
				break;
		case 3 :fee = 30 * amount; 
				fee = fee + fee * 0.05;
				strcpy(ch, "3(공업용)");
				break;		
	}

	output(ch, amount, fee);

	return 0;
}

void input(int *cd, int *am)
{	
	printf("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
	scanf("%d", cd);
	printf("* 사용량을 입력하시오(ton단위) : ");
	scanf("%d", am);
	printf("\n");

	return;
}

void output(char ch[10], int am, double fee)
{
	printf("* 사용자코드 : %s\n", ch);
	printf("* 사용량 : %dton\n", am);
	printf("* 총수도요금 : %d원\n", (int)fee);
	return;
}
