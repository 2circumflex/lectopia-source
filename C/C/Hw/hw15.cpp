/* 날짜 : 2012년 2월 7일   
   작성자 : 이로운   
   프로그램의 기능 : 달팽이 우물달출 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)

int input();
void output(int);
int main()
{
	int cm;
	
	while(1)
	{		
		cm = input();
		
		if(cm>=0)
		{
			output(cm);
		}
		else if(cm<0)
		{
			break;
		}

	}	

	return 0;
}

int input()
{
	int num;

	printf("* 우물의 깊이를 입력하시오(cm단위) : ");
	scanf("%d", &num);

	return num;
}

void output(int n)
{	
	int day, dd;	
	
	if(n == 0)
	{
		day = 0;
	}
	else
	{
		dd = n - 50;
		day = 1;
		while(dd>0)
		{
			day++;
			dd -= 30;
									
			if(dd<=0)
			{
				break;
			}		
		}
	}
	printf("%.2lf미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n\n", n * 0.01, day);
	
	return;
}