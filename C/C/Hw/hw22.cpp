/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 문자반복 출력 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)
void char_print(char, int, int);
void input(char *, int*, int*);
int main()
{
	char ch;
	int su, line;
	
	input(&ch, &su, &line);

	char_print(ch, su, line);

	return 0;
}

void input(char * ch, int *su, int *line)
{	
	printf("* 출력할 문자를 입력하시오 : ");
	scanf("%c", ch);
	printf("* 한줄에 반복할 회수를 입력하시오 : ");
	scanf("%d", su);
	printf("* 반복출력할 라인수를 입력하시오 : ");
	scanf("%d", line);
	printf("\n");
	return;
}

void char_print(char ch, int su, int line)
{
	int i,j;
	
	for(i=0; i<line; i++)
	{
		for(j=0; j<su; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}

	return;
}


