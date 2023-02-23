/* 날짜 : 2012년 2월 8일   
   작성자 : 이로운   
   프로그램의 기능 : 누승 함수 만들기 */
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
	printf("실수값을 넣으세요 : ");
	fflush(stdin);
	scanf("%lf", su);

	printf("n제곱 수 : ");
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
	printf("정수값을 넣으세요 : ");
	fflush(stdin);
	scanf("%d", su);

	printf("n제곱 수 : ");
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