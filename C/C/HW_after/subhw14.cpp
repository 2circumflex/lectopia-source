#include <stdio.h>
#pragma warning (disable:4996)

int input();
void output(int);
int main()
{	
	int su;

	while(1)
	{
		su = input();
		output(su);
	}

	return 0;
}

int input()
{
	int su;
	printf("# �������� �Է��Ͻÿ� : ");
	scanf("%d", &su);

	return su;
}

void output(int su)
{
	int hap=0, i;

	for(i=1; i<=su; i++)
	{
		hap += i;
	}

	printf("1���� %d������ ���� %d�Դϴ�\n\n", su, hap);
}