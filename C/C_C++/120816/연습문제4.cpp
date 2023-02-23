/*
		2012년 8월 16일
		연습문제 4번
		작성자 : 이로운
										*/
#include <iostream>
using namespace std;

struct Savings{
	int w500;	//500원짜리 동전의 개수 저장
	int w100;	//100원짜리 동전의 개수 저장
	int w50;	//50원짜리 동전의 개수 저장
	int w10;	//10원짜리 동전의 개수 저장
};

void init(Savings &s);
void input(int &unit, int &cnt);
void save(Savings &s, int unit, int cnt);
int total(Savings &s);

int main()
{
	Savings money;
	int coin=0, coinCnt, tot;	//동전, 동전개수, 총저금액

	init(money);	//초기화

	while(1)
	{
		input(coin, coinCnt);
		if(coin < 0)	break;			//0보다 작은수를 입력했을때 그만입력
		save(money, coin, coinCnt);		
	}

	tot = total(money);
	cout << "총 저금액 : " << tot << endl;

	return 0;
}

//저금통의 초기화
//Savings 구조체내의 4개의 멤버를 모두 0으로 초기화 함
void init(Savings &s)
{
	s.w500 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w10 = 0;
}

//동전금액, 동전개수를 저장할변수
//키보드로부터 동전금액과 동전 개수를 입력받아 unit과 cnt에 저장함
void input(int &unit, int &cnt)
{	
	while(1)
	{
		cout << "동전의 금액 : ";
		cin >> unit;
	
		while(cin.fail())			//문자입력해서 실패했을때
		{
			cin.clear();
			while(cin.get()!='\n');
			cout << "동전의 금액 : ";
			cin >> unit;
		}
		if(unit== 500 || unit==100 || unit==50 || unit==10)	break;	//동전입력을 제대로 했을때  동전개수 입력을 위해 break
		else if(unit < 0)	return;		//0보다 작은수일때 종료종건
	}
	
	cout << "동전의 개수 : ";
	cin >> cnt;
}

//저금통, 단위, 개수를 전달
//저금통 구조체 변수의 멤버를 전달 받은 동전의 개수 만큼 누적함
void save(Savings &s, int unit, int cnt)
{
	if(unit == 500)	s.w500 += cnt;			//500원짜리 누적
	else if(unit == 100) s.w100 += cnt;		//100원짜리 누적
	else if(unit == 50) s.w50 += cnt;		//50원짜리 누적
	else if(unit == 10) s.w10 += cnt;		//10원짜리 누적
}

//저금통의 총 저축액을 계산하여 리턴하는 함수
int total(Savings &s)
{
	int tot = 0;	//총저축액을 저장할 변수

	tot = (500 * s.w500) + (100 * s.w100) + (50 * s.w50) + (10 * s.w10);	//총저금액 계산

	return tot;		//총저금액 리턴
}