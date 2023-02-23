/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 가위 바위 보 게임 */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함 
#include<stdio.h> 
int random(int);
#pragma warning (disable : 4996)
int main()
{	
	int rsu, su, vcnt=0, mcnt=0;
	char kbb[3][5] = {{"바위"}, {"가위"}, {"보"}};

	while(1)
	{
		rsu = random(3);

		printf("# [바위1], [가위2], [보3] 중에서 선택하세요 : ");
		scanf("%d", &su);

		if(su == rsu)
		{
			mcnt++;	
			printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 비겼습니다.\n\n", kbb[su-1], kbb[rsu-1]);
		}
		else if( (su == 1 && rsu == 2) || (su == 2 && rsu == 3) || (su == 3 && rsu == 1) )
		{
			vcnt++;
			printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 이겼습니다.\n\n", kbb[su-1], kbb[rsu-1]);
		}
		else if( (su == 1 && rsu == 3) || (su == 2 && rsu == 1) || (su == 3 && rsu == 2) )
		{
			printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 당신이 졌습니다.\n\n", kbb[su-1], kbb[rsu-1]);
			printf("게임결과 : %d 승 %d 무\n\n", vcnt, mcnt);
			break;
		}		
	}	

	return 0;
}

int random(int n)	//난수발생
{ 
	int res; 
	res = (rand() % n)+1; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
} 