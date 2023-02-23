#include <stdio.h>
#pragma warning(disable:4996)
void input(int *, int);
void ary_sort(int *, int);
void output(int *, int);
int main() 
{
	int ary[10];
	int size = sizeof(ary) / sizeof(ary[0]);

	input(ary, size);
	ary_sort(ary, size);
	output(ary, size);
	
	return 0;
}

void output(int *ary, int size)
{
	int i;

	for(i=0; i<size; i++)
	{
		printf("[%d] ", ary[i]);
	}
	printf("\n");
}

void input(int *ary, int size)
{
	int i;

	for(i=0; i<size; i++)
	{
		printf("[%d]번방 정수입력 : ", i);
		scanf("%d", &ary[i]);
	}
}

void ary_sort(int *ary, int size)//내림차순
{
	int i, j, cnt=size-1, tp;

	for(i=0; i<size-1; i++)
	{
		for(j=1; j<=cnt; j++)
		{
			if(ary[i] < ary[i+j])
			{
				tp = ary[i];
				ary[i] = ary[i+j];
				ary[i+j] = tp;
			}
		}
		cnt--;
	}	
}