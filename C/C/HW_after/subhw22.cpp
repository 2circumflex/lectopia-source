#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)
int random(int);
int main() 
{ 
	int r_su, win=0, same=0, u_su;
	char kbb[3][5] = {"바위", "가위", "보"};
	srand( time (0) );
	
	while(1)
	{
		r_su = random(3);		// 0~9사이의 난수를 발생시킴

		printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
		scanf("%d", &u_su);

		printf("당신은 %s 선택, 컴퓨터는 %s 선택 : ", kbb[u_su-1], kbb[r_su-1]);

		if(u_su == r_su)
		{
			printf("비겼습니다.\n\n");
			same++;
		}
		else if((u_su == 1 && r_su == 2) || (u_su == 2 && r_su == 3) || (u_su == 3 && r_su == 1))
		{
			printf("이겼습니다.\n\n");
			win++;
		}
		else
		{
			printf("당신이 졌습니다.\n");
			printf("게임결과 : %d 승 %d 무\n\n", win, same);
			break;
		}				
	}

	return 0;
} 
	
int random(int n) // 난수발생 함수 - 과제 작성시 아래 함수를 복사하여 붙여놓고 사용하면됩니다. 
{ 
	int res; 
	res = rand() % n + 1; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
} 