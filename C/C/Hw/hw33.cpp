/* 날짜 : 2012년 2월 15일   
   작성자 : 이로운   
   프로그램의 기능 : 정수값 소트 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)
void input_num(int *);
void output(int *);
int main() 
{
	int num[10];

	while(1)
	{
		input_num(num);
		output(num);
	}
			
	return 0;
}

void input_num(int *num)	// 입력함수
{
	int i;

	fflush(stdin);
	for(i=0; i<10; i++)
	{
		printf("[%d]번방 : ", i);
		scanf("%d", &num[i]);
	}

	return;
}

void output(int *num)	// sort & 출력 함수
{
	int i, j, tmp;
	
	printf("\n내림차순!!\n");

	for(i=0; i<=9; i++)
	{
		for(j=i+1; j<10; j++)
		{
			if(num[i] < num[j])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}

		printf("%d ", num[i]);
	}
	printf("\n\n");	

	return;
}