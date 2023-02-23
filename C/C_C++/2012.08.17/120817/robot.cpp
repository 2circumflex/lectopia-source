#include "robot.h"
#include <iostream>
#include <string.h>
using namespace std;

Robot::~Robot()
{
	//cout << this->name << "께서 사라진다" << endl;
	delete[] this->name;
}

Robot::Robot(void)	//객체생성=
{
	this->name = new char[5];
	strcpy(this->name, "");
	this->energy = 0;
}

Robot::Robot(char *name, int energy)	//초기화 및 객체생성
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(Robot &n)	//copy생성자
{
	this->name = new char[strlen(n.name)+1];
	strcpy(this->name, n.name);
	this->energy = n.energy;
}

Robot& Robot::operator=(Robot &b)
{
	if(this==&b)	return *this;
	
	delete[] this->name;
	this->name = new char[strlen(b.name)+1];
	strcpy(this->name, b.name);
	this->energy = b.energy;
	return *this;	//자체가 리턴
}

bool Robot::operator==(Robot &b)
{
	if(strcmp(this->name, b.name) == 0 && this->energy == b.energy)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Robot::init(char *name, int e)
{
	strcpy(this->name, name);
	this->energy = e;
}

void Robot::go()
{
	if(this->energy >= 10)
	{
		this->energy -= 10;
		cout<< getName() << " 전진" <<endl;
	}
	else
	{
		errRun();
	}
}

void Robot::back()
{
	if(this->energy >= 20)
	{
		this->energy -= 20;
		cout<< getName() <<" 후진" <<endl;
	}
	else
	{
		errRun();
	}
}

void Robot::turn()
{
	if(this->energy >= 30)
	{
		this->energy -= 30;
		cout<< getName() <<" 턴" <<endl;
	}
	else
	{
		errRun();
	}
}

void Robot::jump()
{
	if(this->energy >= 40)
	{
		this->energy -= 40;
		cout<< getName() <<" 점프" <<endl;
	}
	else
	{
		errRun();
	}
}

void Robot::errRun()
{
	cout<< getName() <<" 에너지부족" << endl;
}

void Robot::charge(int e)
{
	this->energy += e;
	cout<< getName() <<" 에너지충전" <<endl;
}

char * Robot::getName()
{
	return this->name;
}

void Robot::setName(char *np)
{
	delete[] this->name;
	this->name = new char[strlen(np)+1];
	strcpy(this->name, np);
	//cout<< "이름설정! : " << this->name <<endl;
}

int Robot::getEnergy()
{
	return this->energy;
}

void Robot::setEnergy(int e)
{
	this->energy = e;
	//cout<< "에너지설정" <<endl;
}