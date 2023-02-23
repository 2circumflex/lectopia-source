/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : 성명, 키, 성별을 입력받아 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char name[25];
	double height;
	char sex;
	
	while(1)
	{
		printf("# 성명 입력 : ");
		gets(name);

		printf("# 키 입력(cm단위) : ");
		scanf("%lf", &height);

		fflush(stdin);

		printf("# 성별 입력(M/F) : ");
		scanf("%c", &sex);

		fflush(stdin);

		if(sex == 'M' || sex == 'm')
		{
			printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n\n", name, height);
		}
		else if(sex == 'F' || sex == 'f')
		{
			printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n\n", name, height);
		}
	}

	return 0;
}