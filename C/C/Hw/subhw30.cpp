/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 문자열안에 존재하는 숫자들이 총합을 계산하기 */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)
int main()
{	
	char str[20];
	int len, i, sum=0;

	while(1)
	{
		sum = 0;
		printf("입력하시오 : ");
		scanf("%s", str);

		len = strlen(str);

		for(i=0; i<len; i++)
		{
			if((str[i]-'0') >=0 && (str[i] - '0') <=9)
			{
				printf("%c+", str[i]);
				sum += str[i] - '0';
			}
		}
		printf("\b=%d\n\n", sum);
	}

	return 0;
}