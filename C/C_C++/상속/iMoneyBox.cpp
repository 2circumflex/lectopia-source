// iMoneyBox의선언, 멤버함수의정의, 메인함수(imomeybox.cpp)
#include <iostream>
using namespace std;
#include "imoneybox.h"

iMoneyBox::iMoneyBox(const char *np, int m, int l) : MoneyBox(np, m)
{
	this->limit=l;
}
//-----------------------------------------------------------------------------
int iMoneyBox::check()
{
	int temp;
	temp=int((double)this->getSum()/this->limit*100);
	return temp;
}
//-----------------------------------------------------------------------------
void iMoneyBox::setLimit(int limit)
{
	this->limit = limit;
}
//-----------------------------------------------------------------------------
int iMoneyBox::getLimit()
{
	return this->limit;
}

void iMoneyBox::save(int m)
{
	if(m > limit-this->getSum())
	{
		cout << "저금통의 공간이 부족합니다.." << endl;
		return;
	}
	MoneyBox::save(m);
}