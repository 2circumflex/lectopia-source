/* 날짜 : 2012년 2월 1일   
   작성자 : 이로운   
   프로그램의 기능 : 54321초를 시, 분, 초 단위로 환산하여 출력하기	*/
#include <stdio.h>
int main()
{
	int second = 54321;	// 54321초
	int hour, min, sec;	// 시간, 분, 초단위 환산하여 저장될 변수

	hour = second / 360;
	second = second - 360 * hour;
	
	min = second / 60;
	sec = second - 60 * min;

	printf("54321초는 %d시간 %d분 %d초 입니다.\n", hour, min, sec);	//출력

	return 0;
}