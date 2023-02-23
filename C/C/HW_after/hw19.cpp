#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
void input(int *, int *);
void output(char[], int, int);
int main() 
{ 
	int code, ton, fee;
	char str[10];

	input(&code, &ton);

	switch(code)
	{
		case 1 : fee = ton * 50 + (int)(ton * 50 * 0.05); strcpy(str, "1(가정용)"); break;
		case 2 : fee = ton * 45 + (int)(ton * 45 * 0.05); strcpy(str, "2(상업용)"); break;
		case 3 : fee = ton * 30 + (int)(ton * 30 * 0.05); strcpy(str, "3(공업용)"); break;
	}

	output(str, ton, fee);

	return 0;
}

void input(int *c, int*t)
{
	printf("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
	scanf("%d", c);

	printf("* 사용량을 입력하시오(ton단위) : ");
	scanf("%d", t);

	return;
}

void output(char c[10], int t, int f)
{
	printf("* 사용자코드 : %s\n", c);
	printf("* 사용량 : %dton\n", t);
	printf("* 총수도요금 : %d원\n", f);
}