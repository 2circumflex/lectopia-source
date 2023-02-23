/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 길이가 10인 정수 배열을 선언하고 총 10개의 정수를 입력받고 홀수이면 배열의 앞에서부터 짝수이면 배열의 뒤에서부터 채워나가고 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int ary[10], tmp[10], i, jsu=0, hsu=0;

	while(1)
	{
		jsu=0;
		hsu=0;
		printf("정수 10개 입력 : ");
	
		for(i=0; i<10; i++)	//입력받기
		{
			scanf("%d", &tmp[i]);		
		}

		for(i=0; i<10; i++)	//입력받은 값 홀수는 앞부터 짝수는 뒤부터 정렬
		{
			if((tmp[i] % 2) == 0)
			{
				ary[9-jsu] = tmp[i];
				jsu++;
			
			}
			else
			{
				ary[0+hsu] = tmp[i];
				hsu++;			
			}
		}
		
		printf("[ ");
		for(i=0; i<10; i++)	//출력하기
		{
			printf("%d ", ary[i]);
		}
		printf("]\n\n");
	}


	return 0;
}