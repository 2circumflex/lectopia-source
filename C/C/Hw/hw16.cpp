/* ��¥ : 2012�� 2�� 8��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� �Լ� ����� */
#include <stdio.h>
#pragma warning (disable : 4996)

double fpow(double *, int *);
int ipow(int *, int *);
int main()
{
	double d_res, d_su;
	int i_res, i_su, i_n, d_n;

	while(1)
	{
		d_res = fpow(&d_su, &d_n);
		printf("%lf\n\n", d_res);

		i_res = ipow(&i_su, &i_n);
		printf("%d\n\n", i_res);
	}
			
	return 0;
}

double fpow(double *su, int *n)
{
	double num = 1;
	int i = 1;
	printf("�Ǽ����� �������� : ");
	fflush(stdin);
	scanf("%lf", su);

	printf("n���� �� : ");
	scanf("%d", n);

	if(*su == 0 && *n == 0)
	{
		return 0;
	}
	else
	{
		while(i <= *n)
		{		
			num *= *su;
			i++;
		}

		return num;
	}	
}

int ipow(int *su, int *n)
{	
	int num = 1;
	int i = 1;
	printf("�������� �������� : ");
	fflush(stdin);
	scanf("%d", su);

	printf("n���� �� : ");
	scanf("%d", n);

	if(*su == 0 && *n == 0)
	{
		return 0;
	}
	else
	{
		while(i<= *n)
		{		
			num *= *su;
			i++;
		}

		return num;
	}	
}