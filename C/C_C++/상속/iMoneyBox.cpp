// iMoneyBox�Ǽ���, ����Լ�������, �����Լ�(imomeybox.cpp)
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
		cout << "�������� ������ �����մϴ�.." << endl;
		return;
	}
	MoneyBox::save(m);
}