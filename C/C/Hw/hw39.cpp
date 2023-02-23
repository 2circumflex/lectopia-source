/* 날짜 : 2012년 2월 21일   
   작성자 : 이로운   
   프로그램의 기능 : 야구게임 */
#include <stdio.h>
#include <conio.h>
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함
#pragma warning (disable : 4996)
#pragma warning (disable : 4244)
int random(int);
void rd_ary(int*);
void ary_check(int *, int *, int *, int *);
int main()
{
	int com[4], human[4];
	int i, cnt=1, ch_i, st=0, ba=0;
	char ch;

	srand( time (0) );

	rd_ary(com);	//난수4자리함수호출

	//for(i=0; i<4; i++)	//난수4자리확인용
	//{
	//	printf("%d\t", com[i]);
	//}
	//printf("\n");

	ch_i = 0;	

	while(1)
	{
		printf("# %d차 : ", cnt);
		
		for(i=0; i<4; i++) //4자리미만넣었을경우를대비해 0으로
		{
			human[i] = 0;
		}

		while((ch=getche())!='\r')
		{			
			if(ch-48>=0 && ch-48<=9)
			{
				human[ch_i] = ch-48;
				
				ch_i++;
			}
		}
		ch_i=0;

		printf("# %d차 : ", cnt);
		for(i=0; i<4; i++)
		{
			printf("%d ", human[i]);
		}
		
		ary_check(com, human, &st, &ba);
		if(st==4)
		{
			printf(" OK\n");
			break;
		}		
		else if(st==0 && ba==0)
		{
			printf(" No!\n");
		}
		else
		{
			printf(" %dS %dB\n", st, ba);
		}

		cnt++;
	}
	return 0;
}

void ary_check(int *c, int *h, int *s, int *b)	//난수랑 입력한값 비교
{
	int i, j;
	*s=0;
	*b=0;
	
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(i==j && c[i] == h[j])
			{
				(*s)++;
			}
			else if(i!=j && c[i] == h[j])
			{
				(*b)++;
			}			
		}
	}
	return;
}

void rd_ary(int *com)	//난수4자리 발생
{
	int i;		

	for(i=0; i<4; i++)
	{
		com[i] = random(10);
	}		
	while(com[1]==com[0])
	{
		com[1] = random(10);
	}
	while(com[2]==com[0] || com[2]==com[1])
	{
		com[2] = random(10);
	}
	while(com[3]==com[0] || com[3]==com[1] || com[3]==com[2])
	{
		com[3] = random(10);
	}	
	return;
}

int random(int n) // 난수발생함수
{ 
	int res; 
	res = rand() % n; // 0부터 n-1까지의 수중 난수 발생 
	return res; 
}