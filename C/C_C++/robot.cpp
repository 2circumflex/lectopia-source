robot.h
class Robot
{
	private:
		char name[20];
		int energy;
		void errRun();	//error 메시지 출력
	public:
		~Robot();	//소멸자
		Robot();	//생성자함수		
		Robot(char *, int);	//생성자함수
		void init(char *, int e);
		void go();		//10 energy 감소
		void back();	//20 energy 감소
		void turn();	//30 energy 감소
		void jump();	//40 energy 감소
		void charge(int e);	//충전
		char * getName();
		void setName(char *);
		int getEnergy();
		void setEnergy(int);
};

robot.cpp
#include "robot.h"
#include <iostream>
#include <string.h>
using namespace std;

Robot::~Robot()
{
	//cout << this->name << "께서 사라진다" << endl;
}

Robot::Robot(void)	//객체생성=
{
	
}

Robot::Robot(char *name, int energy=0)	//초기화 및 객체생성
{
	strcpy(this->name, name);
	this->energy = energy;
}

void Robot::init(char *np, int e)
{
	strcpy(this->name, np);
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
	strcpy(this->name, np);
	cout<< "이름설정!" <<endl;
}

int Robot::getEnergy()
{
	return this->energy;
}

void Robot::setEnergy(int e)
{
	this->energy = e;
	cout<< "에너지설정" <<endl;
}

testmain.cpp
#include "robot.h"
#include <iostream>
using namespace std;
Robot t("짱가", 200);
Robot ex("비너스", 100);
int main()
{
	//Robot r1;	//메모리 블럭 생성
	//Robot r2;	//메모리 블럭 생성

	Robot r1("ㅋㅋㅋ", 350);

	Robot r2("밍키", 350);

	//Robot r3("비너스");

	/*r1.setName("태권v");
	r1.setEnergy(300);

	r1.init("태권v", 300);
	r2.init("마징가z", 250);*/
	
	cout << r1.getName() << " " << r1.getEnergy() << endl;
	cout << r2.getName() << " " << r2.getEnergy() << endl;

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.charge(50);
	r2.charge(100);

	cout<<"-------------------------------"<<endl;

	cout << r1.getName() << " " << r1.getEnergy() << endl;
	cout << r2.getName() << " " << r2.getEnergy() << endl;

	return 0;
}