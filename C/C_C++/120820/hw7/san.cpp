#include "san.h"
#include <iostream>
#include <string.h>
using namespace std;

San::San()
{
	this->name = new char[1];
	strcpy(this->name, "");
	this->height = 0;
}

San::San(const char *name, int height)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->height = height;
}

San::San(const San &r)
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->height = r.height;
}

San::~San()
{
	delete[] this->name;
}

void San::setName(char *name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

char * San::getName()
{
	return this->name;
}

void San::setHeight(int height)
{
	this->height = height;
}

int San::getHeight()
{
	return this->height;
}

San& San::operator=(San &b)
{
	if(this==&b)	return *this;

	delete[] this->name;
	this->name = new char[strlen(b.name) + 1];
	strcpy(this->name, b.name);
	this->height = b.height;

	return *this;
}