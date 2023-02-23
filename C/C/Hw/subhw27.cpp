/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 시작과 끝 값 입력받고 두값사이에 홀수나 짝수를 출력하고 합 구하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int start, end, esum=0, osum=0, sum, i;
	char eo;

	while(1)
	{
		osum = 0;
		esum = 0;
		printf("# 시작값을 입력하시오 : ");
		scanf("%d", &start);
		while(1)
		{		
			printf("# 끝값을 입력하시오 : ");
			scanf("%d", &end);

			if(end>start)
			{
				break;
			}
		}
		fflush(stdin);
		printf("* %d 부터 %d 까지의 짝수의 합을 구할까요?\n  홀수의 합을 구할까요?(짝수:e/홀수:o) : ", start, end);
		scanf("%c", &eo);

		printf("* %d 부터 %d 까지의 ", start, end);
		if(eo=='e') printf("짝수(");
		else printf("홀수(");

		for(i=start; i<=end; i++)
		{
			if(eo == 'e' && i%2 == 0)
			{
				printf("%d ", i);
				esum += i;
			}
			else if(eo == 'o' && i%2 != 0)
			{
				printf("%d ", i);
				osum += i;
			}
		}
		(eo == 'e') ? (sum = esum) : (sum = osum);
		printf("\b)의 합은 %d 입니다.\n\n", sum);	
	}	
	
	return 0;
}