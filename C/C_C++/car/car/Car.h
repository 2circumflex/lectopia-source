#pragma once
#include <iostream>
using namespace std;

class Car
{
private:
	int userNum;	//����ȣ
	int carNum;		//�����ڵ�
	int defPay;		//�⺻���
	int Km;			//����Ÿ�
	int totPay;		//���Ӵ��
public:
	void input(int un, int cn, int km);	//����ȣ, �����ڵ�, ����Ÿ�
	void cal();							//�⺻���, �ѿ�� ���
	Car& operator=(const Car &cr);		//���Կ����� ����Լ�
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