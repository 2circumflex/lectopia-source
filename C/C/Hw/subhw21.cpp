/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 숫자 맞추기 게임 */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함 
#include<stdio.h> 
int random(int);
#pragma warning (disable : 4996)
#pragma warning (disable : 4244)
char su_check(int*, int, int*, int*);
int main()
{	
	int rsu, cnt=0, su, a=0, b=101;
	char ox;
	srand( time (0) );
	rsu = random(100);
		
	while(1)
	{
		printf("# 숫자를 입력하시오(1~100) : ");
		scanf("%d", &su);
		cnt++;
		ox = su_check(&rsu, su, &a, &b);
		if(ox=='o')
		{
			printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 맞추셨습니다.\n", cnt);
			a = 0;
			b = 101;
			cnt = 0;
		}
		else if(ox=='x')
		{
			printf("%d 보다는 크고 %d 보다는 작습니다.\n", a, b);
		}	
	}

	return 0;
}

char su_check(int *rsu, int su, int *a, int *b)	//체크
{
	if(su==(*rsu))
	{
		return 'o';
	}
	else if(su > *rsu && *b >= su)
	{
		*b = su;		
	}
	else if(su < *rsu && su >= *a)
	{
		*a = su;		
	}
	return 'x';
}

int random(int n)	//난수발생
{ 
	int res; 
	res = (rand() % n)+1; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
} 