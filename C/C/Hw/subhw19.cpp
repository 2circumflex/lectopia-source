/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 키보드로부터 양수를 입력 받고 그때까지 입력된 숫자의 합을 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
int input(int);
void output(int);
int main()
{
	int i, su, sum = 0;

	for(i=1; i<=5; i++)
	{
		su = input(i);

		if(su > 0)
		{
			sum += su;			
		}
		else
		{
			i--;
		}
	}
	output(sum);

	return 0;
}

int input(int i)
{
	int su;

	printf("0보다 큰수를 입력하시오(%d번째) : ", i);
	scanf("%d", &su);
	
	return su;
}

void output(int sum)
{
	printf("입력된 값의 총 합 : %d\n", sum);
	return;
}