/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������� ��� ���α׷� */
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
				strcpy(ch, "1(������)");
				break;
		case 2 :fee = 45 * amount; 
				fee = fee + fee * 0.05;
				strcpy(ch, "2(�����)");
				break;
		case 3 :fee = 30 * amount; 
				fee = fee + fee * 0.05;
				strcpy(ch, "3(������)");
				break;		
	}

	output(ch, amount, fee);

	return 0;
}

void input(int *cd, int *am)
{	
	printf("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
	scanf("%d", cd);
	printf("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
	scanf("%d", am);
	printf("\n");

	return;
}

void output(char ch[10], int am, double fee)
{
	printf("* ������ڵ� : %s\n", ch);
	printf("* ��뷮 : %dton\n", am);
	printf("* �Ѽ������ : %d��\n", (int)fee);
	return;
}
