/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 환풍기 관리 프로그램 */
#include <stdio.h>
#include <conio.h>
#pragma warning (disable : 4996)
int menu();
char fanOpen(char);
char fanOff(char);
char fanReverse(char);
char fanDisplay(char);
int main()
{
	char fan=0x00, res;
	int m_num;

	while(1)
	{
		m_num = menu();
		if(m_num == 1)
		{
			res = fanOpen(fan);
		}
		else if(m_num == 2)
		{
			res = fanOff(fan);
		}
		else if(m_num == 3)
		{
			res = fanReverse(fan);
		}
		else
		{			
			break;
		}
		fan = fanDisplay(res);
	}
	return 0;
}

char fanOpen(char fan)	//환풍구 열기
{	
	int num;	
	printf("--------------------------------------------------------------------\n");
	printf("\t\t\tFan 열기 작업 실행 화면\n");
	printf("--------------------------------------------------------------------\n");
	printf(" * OPEN할 FAN 번호를 입력하시오(1-8) : ");
	while(1)
	{
		fflush(stdin);
		scanf("%d", &num);
		if(num>=1 && num<=8) 
		{
			num--;
			break;
		}
		else
		{
			printf("잘못 입력했습니다. 다시입력하시오 : ");		
		}		
	}
	fan = fan|(0x01<<num);
	return fan;
}

char fanOff(char fan)	//환풍구 닫기
{
	int num;	
	printf("--------------------------------------------------------------------\n");
	printf("\t\t\tFan 닫기 작업 실행 화면\n");
	printf("--------------------------------------------------------------------\n");
	printf(" * OFF할 FAN 번호를 입력하시오(1-8) : ");
	while(1)
	{
		fflush(stdin);
		scanf("%d", &num);
		if(num>=1 && num<=8) 
		{
			num--;
			break;
		}
		else
		{
			printf("잘못 입력했습니다. 다시입력하시오 : ");		
		}		
	}

	if((fan&(0x01<<num)) != 0)
	{
		fan = fan^(0x01<<num);
	}	
	
	return fan;
}

char fanReverse(char fan)	//환풍구 on/off 역으로 바꾸기
{
	fan = ~fan;
	return fan;
}

char fanDisplay(char fan)	//환풍구 상태 출력
{	
	int i;
	printf("--------------------------------------------------------------------\n");

	for(i=8; i>=1; i--)
	{
		printf("%d번FAN\t",i);
	}
	printf("\n");

	for(i=7; i>=0; i--)
	{		
		if((fan&(0x01<<i))==0)
		{
			printf("  OFF\t");
		}
		else
		{
			printf("  ON\t");
		}
	}
	printf("\n");
	printf("--------------------------------------------------------------------\n");	
	return fan;
}

int menu(void)	//메뉴
{
	int num;

	printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
	while(1)
	{		
		fflush(stdin);
		scanf("%d", &num);	
		
		if(num>=1 && num<=4) { break; }
		else
		{
			printf("잘못 입력했습니다. 다시입력하시오 : ");
			getch();
			
		}
	}
	return num;
}