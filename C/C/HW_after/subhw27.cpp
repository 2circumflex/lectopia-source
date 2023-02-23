#include <stdio.h>
#pragma warning (disable:4996)
int main() 
{ 
	int ssu, esu, tot;
	int i;
	char eo;

	while(1)
	{
		tot=0;
		printf("# 시작값을 입력하시오 : ");
		scanf("%d", &ssu);

		while(1)
		{
			printf("# 끝값을 입력하시오 : ");
			scanf("%d", &esu);

			if(esu>ssu)	break;
		}

		printf("* %d 부터 %d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", ssu, esu);
		fflush(stdin);
		scanf("%c", &eo);

		printf("%d 부터 %d 까지의 ", ssu, esu);

		if(eo == 'e')	printf("짝수(");
		else if(eo == 'o')	printf("홀수(");

		for(i=ssu; i<=esu; i++)
		{
			if(eo == 'e' && i%2 == 0)
			{
				printf("%d ", i);
				tot += i;
			}
			else if(eo == 'o' && i%2 == 1)
			{
				printf("%d ", i);
				tot += i;
			}
		}

		printf("\b)의 합은 %d 입니다.\n\n", tot);
	}

	return 0;
} 