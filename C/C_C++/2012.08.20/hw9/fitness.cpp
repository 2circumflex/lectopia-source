#include <iostream>
#include <string.h>
#include "fitness.h"
using namespace std;

Fitness::Fitness(void)
{
	this->num = 0;
	this->name = new char[1];
	strcpy(this->name, "");
	this->weight = 0;
	this->height = 0;
}

Fitness::Fitness(int num, char *name, double weight, double height)
{
	this->num = num;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->weight = weight;
	this->height = height;
}

Fitness::Fitness(Fitness &r)
{
	this->num = r.num;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->weight = r.weight;
	this->height = r.height;
}

Fitness::~Fitness()
{
	delete[] this->name;
}

Fitness& Fitness::operator=(Fitness &r)
{
	if(this == &r)	return *this;

	delete[] this->name;
	this->num = r.num;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->weight = r.weight;
	this->height = r.height;

	return *this;
}

bool Fitness::operator==(Fitness &r)
{
	if(this->num == r.num && strcmp(this->name, r.name)==0 && this->weight == r.weight && this->height == r.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Fitness::getNum()
{
	return this->num;
}

void Fitness::setName(char *name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

char * Fitness::getName()
{
	return this->name;
}

void Fitness::setWeight(double weight)
{
	this->weight = weight;
}

double Fitness::getWeight()
{
	return this->weight;
}

void Fitness::setHeight(double height)
{
	this->height = height;
}

double Fitness::getHeight()
{
	return this->height;
}

double Fitness::bmi()
{
	return (this->weight / ((this->height/100) * (this->height/100)));
}