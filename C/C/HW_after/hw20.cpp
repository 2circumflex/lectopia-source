#include <stdio.h>
#pragma warning (disable:4996)
int input();
void output(int);
int main() 
{ 
	int jsu;

	while(1)
	{
		jsu = input();

		output(jsu);
	}

	return 0;
}

int input()
{
	int jsu;

	printf("* 정수를 입력하시오 : ");
	scanf("%d", &jsu);

	return jsu;
}

void output(int su)
{
	int i = su;

	for(i; i<=su+10; i++)
	{
		printf("[%d] ", i);
	}
	printf("\n\n");
}
