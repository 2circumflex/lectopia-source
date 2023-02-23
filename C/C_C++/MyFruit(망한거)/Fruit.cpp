#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
#include "MyString.h"
#include "MyFruit.h"
#include "Fruit.h";
using namespace std;

Fruit::Fruit(char *itemp, int quantity, int buyPrice)
{
	this->item = new char[strlen(itemp) + 1];
	strcpy(this->item, itemp);
	this->quantity = quantity;
	this->buyPrice = buyPrice;
	this->price = (this->buyPrice + (this->buyPrice * 0.5)) / this->quantity;
	this->sellPrice = 0;
}

Fruit::Fruit(const Fruit &r)
{
	this->item = new char[strlen(r.item) + 1];
	strcpy(this->item, r.item);
	this->quantity = r.quantity;
	this->buyPrice = r.buyPrice;
	this->price = r.price;
	this->sellPrice = r.sellPrice;
}

Fruit::~Fruit()
{
	delete[] this->item;
}

void Fruit::sell(int n)
{
	this->quantity -= n;
	this->sellPrice += this->price * n;
}

Fruit& Fruit::operator=(const Fruit &r)
{
	delete[] this->item;
	this->item = new char[strlen(r.item) + 1];
	strcpy(this->item, r.item);
	this->quantity = r.quantity;
	this->buyPrice = r.buyPrice;
	this->price = r.price;
	this->sellPrice = r.sellPrice;

	return *this;
}

bool Fruit::operator>(const Fruit &r)
{
	if((this->buyPrice - this->sellPrice) > (r.buyPrice - this->sellPrice))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Fruit::setQuantity(int n)
{
	this->quantity = n;
}

int Fruit::getQuantity()
{
	return this->quantity;
}

void Fruit::setBuyprice(int n)
{
	this->buyPrice = n;
}

int Fruit::getbuyPrice()
{
	return this->buyPrice;
}

void Fruit::setPrice(int n)
{
	this->price = n;
}

int Fruit::getPrice()
{
	return this->price;
}

void Fruit::setSelprice(int n)
{
	this->sellPrice = n;
}

int Fruit::getSelprice()
{
	return this->sellPrice;
}

char* Fruit::getItem()
{
	return this->item;
}