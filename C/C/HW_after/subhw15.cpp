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

	printf("# �������� �Է��ϼ��� : ");
	scanf("%d", &su);

	return su;
}

void output(int su)
{
	int i;

	for(i=1; i<=su; i++)
	{
		printf("*");

		if(i%5 == 0)
		{
			printf("\n");
		}
	}
	printf("\n\n");
}