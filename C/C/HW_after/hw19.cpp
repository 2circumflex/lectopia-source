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
		case 1 : fee = ton * 50 + (int)(ton * 50 * 0.05); strcpy(str, "1(������)"); break;
		case 2 : fee = ton * 45 + (int)(ton * 45 * 0.05); strcpy(str, "2(�����)"); break;
		case 3 : fee = ton * 30 + (int)(ton * 30 * 0.05); strcpy(str, "3(������)"); break;
	}

	output(str, ton, fee);

	return 0;
}

void input(int *c, int*t)
{
	printf("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
	scanf("%d", c);

	printf("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
	scanf("%d", t);

	return;
}

void output(char c[10], int t, int f)
{
	printf("* ������ڵ� : %s\n", c);
	printf("* ��뷮 : %dton\n", t);
	printf("* �Ѽ������ : %d��\n", f);
}