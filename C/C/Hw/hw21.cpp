/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : y=ax제곱 + bx + c 계산 프로그램 */
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