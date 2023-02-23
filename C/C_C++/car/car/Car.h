#pragma once
#include <iostream>
using namespace std;

class Car
{
private:
	int userNum;	//고객번호
	int carNum;		//차종코드
	int defPay;		//기본요금
	int Km;			//주행거리
	int totPay;		//총임대료
public:
	void input(int un, int cn, int km);	//고객번호, 차종코드, 운행거리
	void cal();							//기본요금, 총요금 계산
	Car& operator=(const Car &cr);		//대입연산자 멤버함수
	void setuserNum(int un);
	int getuserNum();
	void setcarNum(int cn);
	int getcarNum();
	void setdefPay(int dp);
	int getdefPay();
	void setKm(int km);
	int getkm();
	void settotPay(int tp);
	int gettotPay();	
};