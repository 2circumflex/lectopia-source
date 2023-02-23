#include <stdio.h>
#pragma warning (disable:4996)
int input();
void output(int);
int main()
{	
	int tot;

	tot = input();

	output(tot);
	
	return 0;
}

int input()
{
	int i, su, tot=0;
	
	for(i=1; i<=5; i++)
	{
		printf("0보다 큰수를 입력하시오(%d번째) : ", i);
		scanf("%d", &su);

		if(su>0)
		{
			tot+=su;
		}
		else
		{
			--i;
		}
	}
	return tot;
}

void output(int tot)
{
	printf("입력된 값의 총 합 : %d\n", tot);
}