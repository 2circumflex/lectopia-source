// MoneyBox 멤버함수의정의(moneybox.cpp)
#include <iostream>
using namespace std;
#include <string.h>
#include "MoneyBox.h"
//-----------------------------------------------------------------------------
MoneyBox::MoneyBox(const char *name, int sum) : name(name) // 멤버명과전달인자명이같은데괜찮은가?
{
	this->sum=sum;
}
//-----------------------------------------------------------------------------
MoneyBox::MoneyBox(const MoneyBox &br) : name(br.name)
{
	this->sum=br.sum;
}
//-----------------------------------------------------------------------------
void MoneyBox::save(int money)
{
	if(money>=0)
	{
		this->sum += money;
	}
}
//-----------------------------------------------------------------------------
void MoneyBox::use(int money)
{
	if(money >= 0 && money <= this->sum)
	{
		this->sum -= money;
	}
}
//-----------------------------------------------------------------------------
void MoneyBox::setName(MyString name)
{
	this->name = name;
}
//-----------------------------------------------------------------------------
MyString MoneyBox::getName()
{
	return this->name;
}
//-----------------------------------------------------------------------------
void MoneyBox::setSum(int sum)
{
	this->sum = sum;
}
//-----------------------------------------------------------------------------
int MoneyBox::getSum()
{
	return this->sum;
}
//-----------------------------------------------------------------------------