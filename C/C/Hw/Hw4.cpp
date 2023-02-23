/* 날짜 : 2012년 2월 2일   
   작성자 : 이로운   
   프로그램의 기능 : 주행거리와 시속을 입력 받아 주행시간을 계산하여 출력하기	*/
#include <stdio.h>
int main()
{
	double dist, speed;
	int hour, min;
	double sec;
	
	printf("주행거리 입력 : ");
	scanf("%lf", &dist);

	printf("시속을 입력 : ");
	scanf("%lf", &speed);

	hour = (int)(dist / speed);
	min = (dist / speed - hour) * 60;
	sec = ((dist / speed - hour) * 60 - min) * 60;
	
	printf("%.0lf km => %d시간 %d분 %.3lf초 소요됨\n", dist, hour, min, sec);

	return 0;
}