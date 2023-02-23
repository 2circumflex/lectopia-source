/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 배열에 임의의 숫자를 초기화한 후에 각 숫자들의 위치를 반대로 바꾸는 프로그램 */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함 
#pragma warning (disable : 4996)
int random(int);
int main()
{	
	int rsu, *p, i, tmp;
	srand( time (0) );
	
	rsu = random(20);
	p = (int *)malloc(rsu * sizeof(int));	//동적메모리 할당

	for(i=0; i<rsu; i++)	//배열에 랜덤값 입력
	{
		p[i] = random(100);
	}

	printf("처음 배열에 저장된 값 : ");		//처음값 출력하기
	for(i=0; i<rsu; i++)
	{
		printf("%2d ", p[i]);
	}
	printf("\n");
	
	for(i=0; i<rsu/2; i++)	//swap
	{		
		tmp = p[i];
		p[i] = p[rsu-1-i];
		p[rsu-1-i] = tmp;
	}

	printf("바뀐 배열에 저장된 값 : ");		//바뀐값 출력하기
	for(i=0; i<rsu; i++)
	{
		printf("%2d ", p[i]);
	}
	printf("\n\n");

	free(p);

	return 0;	
}

int random(int n)	//난수발생
{ 
	int res; 
	res = (rand() % n)+1; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
}