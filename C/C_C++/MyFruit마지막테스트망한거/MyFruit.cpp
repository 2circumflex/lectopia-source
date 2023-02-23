#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
#include "MyString.h"
#include "MyFruit.h"
#include "Fruit.h"
using namespace std;

MyFruit::MyFruit(const MyFruit &mr) : Fruit(mr)
{
	this->origin = mr.origin;
}

MyFruit::MyFruit(char *itemp, int quantity, int buyPrice, char * origin) : Fruit(itemp, quantity, buyPrice)
{
	this->origin = origin;
}

void MyFruit::back(int n)
{
	this->setQuantity(this->getQuantity() + n);
	this->setSelprice(this->getSelprice() - (this->getPrice() * n));
}

char * MyFruit::getOrigin()
{
	return this->origin.getStr();
}

void MyFruit::setQuantity(int n)
{
	if(n < 0)
	{
		cout << "재고부족" << endl;
	}
	else
	{
		Fruit::setQuantity(n);
		this->setSelprice(this->getSelprice() + this->getPrice() * n);
	}
}
