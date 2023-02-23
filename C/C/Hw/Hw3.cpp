/* 날짜 : 2012년 2월 2일   
   작성자 : 이로운   
   프로그램의 기능 : 1년은 365.2422일이다. 이는 몇일, 몇시간, 몇분, 몇초 인가를 출력하기	*/
#include <stdio.h>
int main()
{
	double day = 365.2422;
	double sec;
	int iday, hour, min;	
	
	iday = (int)day;
	hour = (int)((day - iday) * 24);	
	min = (int)(((day - iday) * 24 - hour) * 60);
	sec = (((day - iday) * 24 - hour) * 60 - min) * 60;

	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초입니다.\n", day, iday, hour, min, sec);

	return 0;
}