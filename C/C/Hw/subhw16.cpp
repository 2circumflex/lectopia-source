/* 날짜 : 2012년 2월 8일   
   작성자 : 이로운   
   프로그램의 기능 : 두개의 정수를 입력받아 두수의 차를 출력 */
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
		printf("# 두개의 정수를 입력하세요 : ");
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
