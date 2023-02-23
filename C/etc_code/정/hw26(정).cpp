// 과제26 소수 출력 프로그램
// 프로그래머 : 렉토피아 정혜경 강사

#include<stdio.h>

int prime_number(int);
int main()
{
    int i, cnt=0, num;  // cnt : 소수의 개수를 count하는 변수
	
    printf("# 정수값을 하나 입력하시오 : ");
    scanf("%d", &num);
    for(i=2; i<=num; i++)
	{ 
		if(prime_number(i)==1) // 검사한 i의 값이 소수이면
		{ 
			printf("%6d", i);
			if(++cnt%5==0) printf("\n");  // 한줄에 5개의 소수를 출력하는 표현
		}
    }
    printf("\n1~%d 까지의 총 소수의 개수는 %d개이다\n", num, cnt);

	return 0;
}

int prime_number(int num) // 소수이면 1, 아니면 0을 리턴하는 함수
{
    int i;
    for(i=2; i<=sqrt(num); i++)  // num이 검사대상 숫자이고 2부터 num의 sqrt값에 해당하는 숫자까지의 수로 
	{  
		if(num%i==0)  // 나누어 떨어지는가를 검사한다.
		{  
			return 0;     // 더이상 검사할 필요가 없으므로 0을 return함 
		}
    }
    return 1; // for문 중간에서 return하지 않았으면 그 어느 수로도 나누어 떨어지지 않으므로 소수임
}