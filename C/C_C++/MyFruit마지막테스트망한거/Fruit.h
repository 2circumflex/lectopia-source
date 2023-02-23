#pragma once

#include <iostream>
using namespace std;
#include "MyString.h"
#include "Fruit.h"

class Fruit
{
 private:
   char *item;		 // ���� �̸�
   int quantity;	 // ����
   int buyPrice;	 // ���� ����(�� �ڽ��� ����)
   int price;			 // �ܰ�(���� �Ѱ��� ����)
   int sellPrice;		 // �� ���� 
public:
	Fruit();	//����Ʈ������
	Fruit(char *itemp, int quantity, int buyPrice);  // �̸�, ����, ���԰������� �ʱ�ȭ
	Fruit(const Fruit &r);	//ī�ǻ�����
	~Fruit();	//�Ҹ���
	void sell(int n);  // �Ǹ� ����Լ�, �Ǹ� ���� ����
	Fruit &operator=(const Fruit &r);
	bool operator>(const Fruit &r);
	char* getItem();
	void setQuantity(int n);
	int getQuantity();
	void setBuyprice(int n);
	int getbuyPrice();
	void setPrice(int n);
	int getPrice();
	void setSelprice(int n);
	int getSelprice();
};