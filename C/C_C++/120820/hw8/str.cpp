#include "str.h"
#include <iostream>
#include <string.h>
using namespace std;

MyString::MyString()
{
	this->str = new char[1];
	strcpy(this->str, "");
	this->len = 0;
}

MyString::MyString(const char *str)
{
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
	this->len = strlen(this->str);
}

MyString::MyString(const MyString &r)
{
	this->str = new char[strlen(r.str) + 1];
	strcpy(this->str, r.str);
	this->len = strlen(this->str);
}

MyString::~MyString()
{
	delete[] this->str;
}

MyString& MyString::operator=(MyString &r)
{
	if(this==&r)	return *this;
	
	delete[] this->str;
	this->str = new char[strlen(r.str) + 1];
	strcpy(this->str, r.str);
	this->len = strlen(this->str);

	return *this;
}

bool MyString::operator==(MyString &r)
{
	if(strcmp(this->str, r.str) == 0 && this->len == r.len)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MyString::setStr(char *str)
{
	delete[] this->str;
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
	this->len = strlen(this->str);
}

char * MyString::getStr()
{
	return this->str;
}

void MyString::setLen(int len)
{
	this->len = len;
}

int MyString::getLen()
{
	return this->len;
}