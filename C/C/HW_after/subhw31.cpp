#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	double su_ary[5], su=0;
	int i;

	printf("다섯 개의 숫자를 입력하세요 : ");
	for(i=0; i<5; i++)
	{
		scanf("%lf", &su_ary[i]);
		if(su_ary[i]>su)	su = su_ary[i];
	}

	printf("가장 큰 값은 %.2lf 입니다.\n", su);
	
	return 0;
}