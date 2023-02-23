#include <iostream>
#include "companyA.h"
using namespace std;

void my_flush();

int main()
{
	companyA comA;
	Car ca;
	int unum, cnum, km;

	//총10개까지만 입력
	while(comA.getlen() != 10)
	{
		//고객번호입력
		cout << "- 고객번호(4자리) : ";
		cin >> unum;
		while(cin.fail() || comA.searchUnique(unum)==1 || unum>9999 || unum<0)
		{
			my_flush();
			cout << "- 다시입력(4자리) : ";
			cin >> unum;
		}
		if(unum == 0)	//0입력시 입력종료
		{
			cout << endl;
			break;
		}

		//차종코드입력
		cout << "- 차종코드(1~5) : ";
		cin >> cnum;
		while(cin.fail() || cnum<1 || cnum>5)
		{
			my_flush();
			cout << "- 다시입력(1~5) : ";
			cin >> cnum;
		}

		//운행거리입력
		cout << "- 운행거리(KM단위) : ";
		cin >> km;
		while(cin.fail() || km>999 || km<0)
		{
			my_flush();
			cout << "- 다시입력(KM단위) : ";
			cin >> km;
		}

		cout << endl;

		ca.input(unum, cnum, km);	//고객번호, 차종코드, 운행거리 입력
		ca.cal();	//기본요금, 총요금계산
		comA.appendFromTail(ca);	//테일노드앞에 추가
	}
	comA.sortList();	//고객번호 오름차순으로 정렬
	comA.display();		//디스플레이
}

void my_flush()
{
	cin.clear();	//flag값을 0으로 변경

	while(cin.get() != '\n');
}
