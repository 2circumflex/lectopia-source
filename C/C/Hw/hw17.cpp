/* 날짜 : 2012년 2월 8일   
   작성자 : 이로운   
   프로그램의 기능 : 주메뉴 5개 출력, 각메뉴화면 실행 */
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#pragma warning (disable : 4996)
char menu();
void input();
void output();
void search();
void mydelete();
void mistake();
void end();
int main()
{
	char m_res;	

	do
	{
		m_res = menu();

		if(m_res == '5')
		{
			end();
			break;
		}		
		else if(m_res == '1')
		{
			input();
		}
		else if(m_res == '2')
		{
			output();
		}
		else if(m_res == '3')
		{
			search();
		}
		else if(m_res == '4')
		{
			mydelete();
		}
		else
		{
			mistake();			
		}
				
	}while(1);

	return 0;
}
char menu()
{
	char m_num;

	system("cls");
	printf("\n\n\n\t\t\t\t1. 입력하기\n\n");
	printf("\t\t\t\t2. 출력하기\n\n");
	printf("\t\t\t\t3. 검색하기\n\n");
	printf("\t\t\t\t4. 삭제하기\n\n");
	printf("\t\t\t\t5. 종    료\n\n");
	printf("\t\t\t\t#메뉴를 선택하세요 : ");
	fflush(stdin);
	m_num = getchar();
	
	return m_num;
}
void input()
{
	system("cls");
	printf("\n\n\n\t\t\t\t1번 입력하기 메뉴입니다.\n\n");
	printf("\n\n\n\t\t\t# 아무키나 누르면 주메뉴로 돌아갑니다.");
	getch();

	return;
}
void output()
{
	system("cls");
	printf("\n\n\n\t\t\t\t2번 출력하기 메뉴입니다.\n\n");
	printf("\n\n\n\t\t\t# 아무키나 누르면 주메뉴로 돌아갑니다.");
	getch();

	return;
}
void search()
{
	system("cls");
	printf("\n\n\n\t\t\t\t3번 검색하기 메뉴입니다.\n\n");
	printf("\n\n\n\t\t\t# 아무키나 누르면 주메뉴로 돌아갑니다.");
	getch();

	return;
}
void mydelete()
{
	system("cls");
	printf("\n\n\n\t\t\t\t4번 삭제하기 메뉴입니다.\n\n");
	printf("\n\n\n\t\t\t# 아무키나 누르면 주메뉴로 돌아갑니다.");
	getch();

	return;
}
void mistake()
{
	system("cls");
	printf("\n\n\n\t\t\t\t잘못 입력하셨습니다.\n\n");
	printf("\n\n\n\t\t\t# 아무키나 누르면 주메뉴로 돌아갑니다.");
	getch();

	return;
}
void end()
{
	system("cls");
	printf("\n\n\n\t\t\t\t종료합니다.\n\n");

	return;
}