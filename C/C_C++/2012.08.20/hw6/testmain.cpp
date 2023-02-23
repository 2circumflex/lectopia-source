#include "time.h"
#include <iostream>
using namespace std;

Time::Time(void)
{
	this->hour = 0;
	this->min = 0;
}

Time::Time(int hour, int min)
{
	this->hour = hour;
	this->min = min;
}

Time::Time(double d)
{
	this->hour = d;
	this->min = 60 * (d - (double)this->hour);
}

Time::Time(const Time &tr)
{
	this->hour = tr.hour;
	this->min = tr.min;
}

Time Time::plus(const Time &tr)
{
	this->hour += tr.hour;
	this->min += tr.min;

	if(this->min >= 60)
	{
		this->hour += this->min / 60;
		this->min = this->min % 60;
	}
	
	return *this;
}

void Time::setHour(int hour)
{
	this->hour = hour;
}

int Time::getHour()
{
	return this->hour;
}

void Time::setMin(int min)
{
	this->min = min;
}

int Time::getMin()
{
	return this->min;
}