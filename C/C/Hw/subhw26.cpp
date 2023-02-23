/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 달걀 포장하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int egg, cnt=0;
	while(1)
	{
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
		scanf("%d", &egg);

		if(egg >=150 && egg <= 400)
		{
			cnt++;
		}
		else if(egg<150)
		{
			printf("*메추리알 가지고 장난하지 마시오~ ^^\n");
		}
		else if(egg>400)
		{
			printf("타조알 가지고 장난하지 마시오~ ^^\n");
		}

		printf("* 현재 달걀의 수 : %d\n", cnt);

		if(cnt == 10)
		{
			printf("\n*** 달걀 포장이 끝났습니다\n");
			break;
		}
	}

	return 0;
}