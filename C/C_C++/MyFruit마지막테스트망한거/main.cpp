#include <iostream>
using namespace std;
#include "MyFruit.h"

int main()
{
	// ㅠㅅㅠ 망했습니다......;;;;;;
	char fName[50];
	char oName[50];
	int quantity;
	int buyPrice;
	int num;
	int fNum;
	int su;

	cout << "첫번째 과일 한 상자를 사옵니다..." << endl;
	cout << "폼목입력 : ";
	cin >> fName;
	cout << "원산지 : ";
	cin >> oName;
	cout << "매입가격 : ";
	cin >> buyPrice;
	cout << "수량 : ";
	cin >> quantity;
	MyFruit a(fName, quantity, buyPrice, oName);
	
	cout << "두번째 과일 한 상자를 사옵니다..." << endl;
	cout << "폼목입력 : ";
	cin >> fName;
	cout << "원산지 : ";
	cin >> oName;
	cout << "매입가격 : ";
	cin >> buyPrice;
	cout << "수량 : ";
	cin >> quantity;
	MyFruit b(fName, quantity, buyPrice, oName);

	while(1)
	{
		cout << "장사를 시작합니다..." << endl;
		cout << "항목 선택 [판매-1, 반품-2, 종료-3] : ";
		cin >> num;
		if(num != 3)
		{
			cout << "과일 선택 "<< a.getItem() << "-1, " << b.getItem() << "-2 :";
			cin >> fNum;
			cout << "수량 : ";
			cin >> su;
			
			if(num == 1)
			{
				if(fNum == 1)
				{
					a.setQuantity(a.getQuantity() - su);
				}
				else
				{
					b.setQuantity(b.getQuantity() - su);			
				}				
			}
			else if(num == 2)
			{
				if(fNum == 1)
				{
					a.back(su);
				}
				else
				{
					b.back(su);
				}
			}
			cout << "** 영업 결과..." << endl;
			cout << "품목 : " << a.getItem() << " (" << a.getOrigin() << ")" << endl;
			cout << "남은 수량 : " << a.getQuantity() << endl;
			cout << "매입 가격 : " << a.getbuyPrice() << endl;
			cout << "매출 : " << a.getSelprice() << endl;
			cout << "순수익 : " << a.getSelprice() - a.getbuyPrice() << endl;
			cout << endl;
			cout << "품목 : " << b.getItem() << " (" << b.getOrigin() << ")" << endl;
			cout << "남은 수량 : " << b.getQuantity() << endl;
			cout << "매입 가격 : " << b.getbuyPrice() << endl;
			cout << "매출 : " << b.getSelprice() << endl;
			cout << "순수익 : " << b.getSelprice() - b.getbuyPrice() << endl;
			cout << endl;
		}
		else
		{
			break;
		}
		
	}
	
	cout << "** 순수익 금액이 많은 과일..." << endl;
	if(a>b)
	{
		cout << a.getItem() << endl;
	}
	else
	{
		cout << b.getItem() << endl;
	}

	return 0;
}