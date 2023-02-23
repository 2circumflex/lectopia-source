/* 날짜 : 2012년 2월 7일   
   작성자 : 이로운   
   프로그램의 기능 : 반복 출력할 문자를 입력받아 반복회수 만큼 문자를 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int input1();
char input2();
void output(int, char);
int main()
{
	int cycle;
	char mj;

	while(1)
	{
		cycle = input1();
		mj = input2();
		output(cycle, mj);
	}
}

int input1()
{
	int num;
	printf("# 반복회수를 입력하시오 : ");
	scanf("%d", &num);

	fflush(stdin);

	return num;
}

char input2()
{
	char ch;
	printf("# 반복문자를 입력하시오 : ");
	scanf("%c", &ch);

	return ch;
}

void output(int c, char m)
{
	int i=1;
	while(i<=c)
	{
		printf("%c", m);
		i++;
	}
	printf("\n\n");

	return;
}