/* 날짜 : 2012년 2월 15일   
   작성자 : 이로운   
   프로그램의 기능 : 대각선의 합구하기 */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함
int random(int);
void output(int (*)[5]);
#pragma warning (disable : 4996)
int main() 
{
	int num[5][5];

	srand( time (0) );

	output(num);
	
	return 0;
}

int random(int n) // 난수발생함수
{ 
	int res; 
	res = (rand() % n)+1; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
}

void output(int (*num)[5])	// 출력함수
{
	int i, j, res, sum1=0, sum2=0, sum3=0;

	for(i=0; i<5; i++)
	{
		printf("%d번 행 : ", i);
		for(j=0; j<5; j++)
		{
			res = random(20);
			num[i][j] = res;
			printf("%2d  ", num[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0; i<5; i++)	// sum1 누적
	{
		for(j=i; j<=i; j++)
		{
			sum1 += num[i][j];
		}
	}

	for(i=0; i<4; i++)	// sum2 누적
	{
		for(j=i+1; j<5; j++)
		{
			sum2 += num[i][j];
		}
	}

	for(i=1; i<5; i++)	// sum3 누적
	{
		for(j=0; j<i; j++)
		{
			sum3 += num[i][j];
		}
	}	

	printf("sum1 = %d\n", sum1);
	printf("sum2 = %d\n", sum2);
	printf("sum3 = %d\n", sum3);
	
	return;
}