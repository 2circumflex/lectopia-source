/* ��¥ : 2012�� 2�� 7��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �ݺ� ����� ���ڸ� �Է¹޾� �ݺ�ȸ�� ��ŭ ���ڸ� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int input1();
char input2();
void output(int, char);
int main()
{
	int cycle;
	char mj;

	while(1)
	{
		cycle = input1();
		mj = input2();
		output(cycle, mj);
	}
}

int input1()
{
	int num;
	printf("# �ݺ�ȸ���� �Է��Ͻÿ� : ");
	scanf("%d", &num);

	fflush(stdin);

	return num;
}

char input2()
{
	char ch;
	printf("# �ݺ����ڸ� �Է��Ͻÿ� : ");
	scanf("%c", &ch);

	return ch;
}

void output(int c, char m)
{
	int i=1;
	while(i<=c)
	{
		printf("%c", m);
		i++;
	}
	printf("\n\n");

	return;
}