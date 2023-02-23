/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : 몸무게와 키를 입력받아 신체질량지수(BMI)를 구하고 비만도를 출력해주는 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	double height, kg, bmi;
	
	while(1)
	{
		printf("몸무게를 입력하세요(kg) : ");
		scanf("%lf", &kg);
		printf("키를 입력하세요(m) : ");
		scanf("%lf", &height);

		bmi = kg / (height * height);

		if(bmi >= 40.0)
		{
			printf("당신의 BMI는 %.1lf으로 고도비만입니다\n\n", bmi);
		}
		else if(bmi>=30.0)
		{
			printf("당신의 BMI는 %.1lf으로 비만입니다\n\n", bmi);
		}
		else if(bmi>=25.0)
		{
			printf("당신의 BMI는 %.1lf으로 과체중입니다\n\n", bmi);
		}
		else if(bmi>=18.5)
		{
			printf("당신의 BMI는 %.1lf으로 정상체중입니다\n\n", bmi);
		}
		else
		{
			printf("당신의 BMI는 %.1lf으로 저체중입니다\n\n", bmi);
		}		
	}

	return 0;
}