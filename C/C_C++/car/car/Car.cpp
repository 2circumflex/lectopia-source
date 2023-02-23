#include <iostream>
#include "Car.h"
using namespace std;


//고객번호, 차종코드, 운행거리
void Car::input(int un, int cn, int km)
{
	this->userNum = un;
	this->carNum = cn;
	this->Km = km;
}

//기본요금, 총요금 계산
void Car::cal()
{
	switch(this->carNum)
	{
		//경차
	case 1:
		this->defPay = 10000;
		this->totPay = 10000 + (this->Km * 200);
		break;
		//소형차
	case 2:
		this->defPay = 15000;
		this->totPay = 15000 + (this->Km * 400);
		break;
		//중형차
	case 3:
		this->defPay = 20000;
		this->totPay = 20000 + (this->Km * 500);
		break;
		//대형차
	case 4:
		this->defPay = 25000;
		this->totPay = 25000 + (this->Km * 700);
		break;
		//리무진
	case 5:
		this->defPay = 30000;
		this->totPay = 30000 + (this->Km * 1000);
		break;
	}
}

//대입연산자 멤버함수
Car &Car::operator=(const Car &cr)
{
	this->userNum = cr.userNum;
	this->carNum = cr.carNum;
	this->defPay = cr.defPay;
	this->Km = cr.Km;
	this->totPay = cr.totPay;

	return *this;
}

/* set, get 시리즈 */

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