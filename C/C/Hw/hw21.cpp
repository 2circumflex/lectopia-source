/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : y=ax���� + bx + c ��� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)
void input(double *, double *, double *);
void output(double, double, double);
int main()
{
	double a, b, c;

	input(&a, &b, &c);

	output(a, b, c);

	return 0;
}

void input(double *a, double *b, double *c)
{
	printf("a = ");
	scanf("%lf", a);
	printf("b = ");
	scanf("%lf", b);
	printf("c = ");
	scanf("%lf", c);	

	return;
}

void output(double a, double b, double c)
{
	double y;
	int i;

	for(i=1; i<=20; i++)
	{
		y = a * (i*i) + b * i + c;
		printf("x = %d   =>   y = %.2lf\n", i, y);
	}

	return;
}