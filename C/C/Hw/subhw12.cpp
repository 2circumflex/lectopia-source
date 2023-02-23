/* 날짜 : 2012년 2월 7일   
   작성자 : 이로운   
   프로그램의 기능 : 5명의 학생의 키를 입력받아 평균을 구해 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

double input();
void output(double);
int main()
{
	double totkey;

	while(1)
	{
		totkey = input();
		output(totkey);	
	}

	return 0;
}

double input()
{
	int i = 1;
	double key, tot=0;
	
	while(i<=5)
	{
		printf("- %d번 학생의 키는? ", i);
		scanf("%lf", &key);

		tot += key;
		i++;
	}	

	return tot;
}

void output(double avgkey)
{
	printf("다섯명의 평균 키는 %.1lf 입니다.\n\n", avgkey/5);

	return;
}