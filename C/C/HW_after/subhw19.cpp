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
		printf("0���� ū���� �Է��Ͻÿ�(%d��°) : ", i);
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
	printf("�Էµ� ���� �� �� : %d\n", tot);
}