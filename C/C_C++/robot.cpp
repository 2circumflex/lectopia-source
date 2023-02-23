robot.h
class Robot
{
	private:
		char name[20];
		int energy;
		void errRun();	//error �޽��� ���
	public:
		~Robot();	//�Ҹ���
		Robot();	//�������Լ�		
		Robot(char *, int);	//�������Լ�
		void init(char *, int e);
		void go();		//10 energy ����
		void back();	//20 energy ����
		void turn();	//30 energy ����
		void jump();	//40 energy ����
		void charge(int e);	//����
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
	//cout << this->name << "���� �������" << endl;
}

Robot::Robot(void)	//��ü����=
{
	
}

Robot::Robot(char *name, int energy=0)	//�ʱ�ȭ �� ��ü����
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
		cout<< getName() << " ����" <<endl;
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
		cout<< getName() <<" ����" <<endl;
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
		cout<< getName() <<" ��" <<endl;
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
		cout<< getName() <<" ����" <<endl;
	}
	else
	{
		errRun();
	}
}

void Robot::errRun()
{
	cout<< getName() <<" ����������" << endl;
}

void Robot::charge(int e)
{
	this->energy += e;
	cout<< getName() <<" ����������" <<endl;
}

char * Robot::getName()
{
	return this->name;
}

void Robot::setName(char *np)
{
	strcpy(this->name, np);
	cout<< "�̸�����!" <<endl;
}

int Robot::getEnergy()
{
	return this->energy;
}

void Robot::setEnergy(int e)
{
	this->energy = e;
	cout<< "����������" <<endl;
}

testmain.cpp
#include "robot.h"
#include <iostream>
using namespace std;
Robot t("¯��", 200);
Robot ex("��ʽ�", 100);
int main()
{
	//Robot r1;	//�޸� �� ����
	//Robot r2;	//�޸� �� ����

	Robot r1("������", 350);

	Robot r2("��Ű", 350);

	//Robot r3("��ʽ�");

	/*r1.setName("�±�v");
	r1.setEnergy(300);

	r1.init("�±�v", 300);
	r2.init("��¡��z", 250);*/
	
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