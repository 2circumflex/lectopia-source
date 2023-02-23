/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 역사, 문학, 예능 세 과목의 점수를 입력받아 총점과 평균을 구해 출력, 입력 점수는 모두 정수값, 평균은 실수값이 나올수 있도록 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int his, mun, ye;
	int hap;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &his, &mun, &ye);

	hap = his + mun + ye;

	printf("총점은 %d이고 평균은 %lf 입니다.\n", hap, (double)hap/3.0);

	return 0;
}