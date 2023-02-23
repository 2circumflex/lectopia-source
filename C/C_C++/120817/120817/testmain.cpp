#include "robot.h"
#include <iostream>
using namespace std;
//Robot t("짱가", 200);
//Robot ex("비너스", 100);
int main()
{
	Robot ary[3];
	int i, num, ene;
	char temp[50];
	int energy;

	for(i=0; i<3; i++)
	{
		cout << i+1 << "번 Robot 이름 : ";
		cin >> temp;

		cout << temp << "의 energy 입력 : ";
		cin >> energy;
		
		ary[i].setName(temp);
		ary[i].setEnergy(energy);		
	}


	while(1)
	{
		cout << "일시킬 로봇 선택(로봇번호 1~3/4입력시 종료) : ";
		cin >> i;
		if(i == 4)	break;
		i-=1;
		cout << ary[i].getName() << "시킬 일은?(1전진/2후진/3턴/4점프/5충전) : ";
		cin >> num;
	
		switch(num)
		{
		case 1:
			ary[i].go();
			break;
		case 2:
			ary[i].back();
			break;
		case 3:
			ary[i].turn();
			break;
		case 4:
			ary[i].jump();
			break;
		case 5:
			cout << "에너지 입력 : ";
			cin >> ene;
			ary[i].charge(ene);
			break;
		}
	}

	for(i=0; i<3; i++)
	{
		cout << ary[i].getName() << " : " << ary[i].getEnergy() << endl;
	}

	//Robot r1;	//메모리 블럭 생성
	//Robot r2;	//메모리 블럭 생성

	//Robot r1;
	//
	//Robot r2("밍키", 350);

	//Robot r3(r2);

	//r1.setName("태권브이");

	//r1=r2;
	//r1=r1;

	//if(r1==r2)
	//{		
	//	cout << "같다" << endl;
	//}
	//else
	//{		
	//	cout << "다르다" << endl;
	//}

	//Robot r3("비너스");

	/*r1.setName("태권v");
	r1.setEnergy(300);

	r1.init("태권v", 300);
	r2.init("마징가z", 250);*/
	
	/*cout << r1.getName() << " " << r1.getEnergy() << endl;
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
	cout << r2.getName() << " " << r2.getEnergy() << endl;*/

	return 0;
}