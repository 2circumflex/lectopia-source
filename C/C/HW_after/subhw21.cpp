#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)
int random(int);
int main() 
{ 
	int r_su, su, b_su=0, a_su=101, cnt=0;
	srand( time (0) );			
							
	r_su = random(100) + 1;		// 0~9사이의 난수를 발생시킴
	
	while(1)
	{
		cnt++;
		printf("# 숫자를 입력하시오 : ");
		scanf("%d", &su);

		if(su == r_su)
		{
			printf("우와~ 맞았당~~~ 추카추카~~ %d번째 만에 맞추셨습니다.\n", cnt);
			break;
		}
		else
		{
			if(r_su>su)
			{
				b_su = su;
			}
			else
			{
				a_su = su;
			}
			
			printf("%d보다는 크고 %d 보다는 작습니다.\n", b_su, a_su);
		}	
	}		

	return 0;
} 
	
int random(int n) // 난수발생 함수 - 과제 작성시 아래 함수를 복사하여 붙여놓고 사용하면됩니다. 
{ 
	int res; 
	res = rand() % n; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
} 