#include <stdio.h>
#pragma warning (disable:4996)

int input(int*,int*);
void output(int, int);
int main()
{	
	int su1, su2, ch;

	while(1)
	{
		ch = input(&su1, &su2);

		if(ch == 2)
		{
			output(su1, su2);
		}
		else
		{
			break;
		}
	}

	return 0;
}

int input(int * su1, int * su2)
{
	int ch;
	printf("# 두개의 정수를 입력하세요 : ");
	ch = scanf("%d %d", su1, su2);

	return ch;
}

void output(int su1, int su2)
{
	if(su1>su2)
	{
		printf("% d - % d = %d\n\n", su1, su2, su1-su2);
	}
	else
	{
		printf("% d - % d = %d\n\n", su2, su1, su2-su1);
	}
}




