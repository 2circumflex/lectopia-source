/* ��¥ : 2012�� 2�� 8��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �ΰ��� ������ �Է¹޾� �μ��� ���� ��� */
#include <stdio.h>
#pragma warning (disable : 4996)

int input(int *, int *);
void exchange(int *, int *);
void output(int *, int *, int *);
int main()
{
	int num1, num2, r_res, sum;
	
	while(1)
	{
		printf("# �ΰ��� ������ �Է��ϼ��� : ");
		r_res = input(&num1, &num2);

		if(r_res == 0 || r_res == 1)
		{
			break;
		}
		else if(num2>num1)
		{
			exchange(&num1, &num2);
		}

		sum = num1 - num2;
		output(&num1, &num2, &sum);		
	}
		
	return 0;
}

int input(int *a, int*b)
{	
	int n;
	fflush(stdin);
	n = scanf("%d %d", a, b);

	return n;
}
void exchange(int *x, int *y)
{
	int temp;
	temp = *x, *x = *y, *y = temp;
}
void output(int *p, int *q, int *pq)
{	
	printf("%d - %d = %d\n\n", *p, *q, *pq);
}
