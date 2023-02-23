#include <iostream>
#include "Car.h"
using namespace std;


//����ȣ, �����ڵ�, ����Ÿ�
void Car::input(int un, int cn, int km)
{
	this->userNum = un;
	this->carNum = cn;
	this->Km = km;
}

//�⺻���, �ѿ�� ���
void Car::cal()
{
	switch(this->carNum)
	{
		//����
	case 1:
		this->defPay = 10000;
		this->totPay = 10000 + (this->Km * 200);
		break;
		//������
	case 2:
		this->defPay = 15000;
		this->totPay = 15000 + (this->Km * 400);
		break;
		//������
	case 3:
		this->defPay = 20000;
		this->totPay = 20000 + (this->Km * 500);
		break;
		//������
	case 4:
		this->defPay = 25000;
		this->totPay = 25000 + (this->Km * 700);
		break;
		//������
	case 5:
		this->defPay = 30000;
		this->totPay = 30000 + (this->Km * 1000);
		break;
	}
}

//���Կ����� ����Լ�
Car &Car::operator=(const Car &cr)
{
	this->userNum = cr.userNum;
	this->carNum = cr.carNum;
	this->defPay = cr.defPay;
	this->Km = cr.Km;
	this->totPay = cr.totPay;

	return *this;
}

/* set, get �ø��� */

void Car::setuserNum(int un)
{
	this->userNum = un;
}

int Car::getuserNum()
{
	return this->userNum;
}

void Car::setcarNum(int cn)
{
	this->carNum = cn;
}

int Car::getcarNum()
{
	return this->carNum;
}

void Car::setdefPay(int dp)
{
	this->defPay = dp;
}

int Car::getdefPay()
{
	return this->defPay;
}

void Car::setKm(int km)
{
	this->Km = km;
}

int Car::getkm()
{
	return this->Km;
}

void Car::settotPay(int tp)
{
	this->totPay = tp;
}

int Car::gettotPay()
{
	return this->totPay;
}