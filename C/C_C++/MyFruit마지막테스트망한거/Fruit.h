#pragma once

#include <iostream>
using namespace std;
#include "MyString.h"
#include "Fruit.h"

class Fruit
{
 private:
   char *item;		 // 과일 이름
   int quantity;	 // 수량
   int buyPrice;	 // 구입 가격(한 박스의 가격)
   int price;			 // 단가(과일 한개의 가격)
   int sellPrice;		 // 총 매출 
public:
	Fruit();	//디폴트생성자
	Fruit(char *itemp, int quantity, int buyPrice);  // 이름, 수량, 구입가격으로 초기화
	Fruit(const Fruit &r);	//카피생성자
	~Fruit();	//소멸자
	void sell(int n);  // 판매 멤버함수, 판매 수량 전달
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